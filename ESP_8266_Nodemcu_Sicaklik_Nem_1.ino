#include <ESP8266WiFi.h> // ESP8266 çekirdek kütüphanesi
#include <Wire.h>
//#include <string.h>

// Kablosuz ağ bilgilerinizi buraya girin
const char* ssid     = "Ankara Teknik Bili\xC5\x9Fim";
const char* password = "1881Atb?";

// TCP Sunucusu nesnesi (Port 8080 üzerinden dinleme yapacak)
WiFiServer tcpSunucu(8080);

// SHT3x I2C Adresi (ADR pini GND'de ise 0x44, VCC'de ise 0x45'tir)
#define SHT3X_I2C_ADDR 0x44 



// ESP8266 I2C Pin Tanımlamaları
const int SDA_PIN = 4; // NodeMCU üzerindeki D2 pini (GPIO4)
const int SCL_PIN = 5; // NodeMCU üzerindeki D1 pini (GPIO5)

 float celsius = 0.00;
 float humidity = 0.00;

void setup() {
  // ESP8266 için kararlı seri haberleşme hızı (115200 Baud)
  Serial.begin(115200); 
  
  // Wi-Fi modülünü şimdilik kapatıyoruz (Güç tasarrufu ve paraziti önlemek için)
  //WiFi.mode(WIFI_OFF);

  // Wi-Fi ağına bağlanma süreci
  //Serial.println();
  //Serial.print(ssid);
  //Serial.print(" agina baglaniliyor");
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
   // Serial.print(".");
  }
  
  //Serial.println("");
  //Serial.println("Wi-Fi baglantisi basarili!");

  // NodeMCU'nun aldığı IP adresini seri porttan oku (TCP bağlantısı için bu IP gerekli)
  //Serial.print("NodeMCU IP Adresi: ");
  //Serial.println(WiFi.localIP());

  //Serial.print("ESP8266 MAC Adresi: ");
  //Serial.println(WiFi.macAddress());

    // TCP sunucusunu başlat
  tcpSunucu.begin();
  //Serial.println("TCP Sunucusu baslatildi. Port: 8080");
  
  // ESP8266 için I2C hattını belirtilen pinlerle başlatıyoruz
  Wire.begin(SDA_PIN, SCL_PIN); 
  
  //Serial.println("\n[ESP8266] SHT3x-DIS Sensör Testi Başlatılıyor...");
  delay(1000);
}

void loop() {

// Yeni bir istemci (client) baglantisi var mı kontrol et
  WiFiClient istemci = tcpSunucu.available();

  if (istemci) {
    //Serial.println("\nYeni bir istemci baglandi.");
    String gelenVeri = "";

 

  // 2. Sensörden 6 byte veri talep et 
  Wire.requestFrom(SHT3X_I2C_ADDR, 6); 
  
  if (Wire.available() == 6) {
    // Ham sıcaklık verisini al
    uint16_t rawTemperature = (Wire.read() << 8) | Wire.read();
    Wire.read(); // Sıcaklık CRC byte'ını atla
    
    // Ham nem verisini al
    uint16_t rawHumidity = (Wire.read() << 8) | Wire.read();
    Wire.read(); // Nem CRC byte'ını atla
    
    // 3. Sensirion Dönüşüm Formülleri
    celsius = -45.0 + (175.0 * ((float)rawTemperature / 65535.0));
    humidity = 100.0 * ((float)rawHumidity / 65535.0);
    
    // Değerleri sınırla
    if (humidity > 100.0) humidity = 100.0;
    if (humidity < 0.0)   humidity = 0.0;

    // 4. Seri Port Ekranına Yazdır
    //Serial.print("Sıcaklık: ");
    //Serial.print(celsius, 2);
    //Serial.print(" °C\t | \t");
    
    //Serial.print("Bağıl Nem: % ");
    //Serial.println(humidity, 2);
    
  } else {
    //Serial.println("Hata: Sensörden 6 byte veri paketi alınamadı!");
  }


  
  // ESP8266'nın kilitlenmesini (Watchdog Reset) önlemek ve stabil çalışmasını sağlamak için delay kullanımı uygundur
  //delay(1000); 

    
    // İstemci bağlıyken ve veri gönderiyorken oku
    while (istemci.connected()) {
      if (istemci.available()) {
        char c = istemci.read();
        
        // Satır sonu veya yeni satır karakterine kadar veriyi biriktir
        if (c == '\n' || c == '\r') {
          if (gelenVeri.length() > 0) {
            gelenVeri.trim(); // Boşlukları temizle
            Serial.print("Gelen TCP Verisi: ");
            Serial.println(gelenVeri);

            // Gelen veriye göre dijital çıkışı kontrol et
            if (gelenVeri == "SICAKLIK") {
              //digitalWrite(cikisPini, HIGH);
              //istemci.println("CIKIS AKTIF (HIGH) 1");
              //Serial.println("--> Cikis HIGH yapildi.");

              String str_sicaklik = "";

              //String floatString = String(myFloat, 2); 
              //Serial.println("Price: " + floatString);

             str_sicaklik = String(celsius);
            istemci.printf("SICAKLIK = ");
            istemci.println(str_sicaklik);

           

            } 
            else if (gelenVeri == "NEM") {
              //digitalWrite(cikisPini, LOW);
              //istemci.println("CIKIS PASIF (LOW) 1");
              //Serial.println("--> Cikis LOW yapildi.");
            } 
            else {
              istemci.println("Gecersiz komut! Kullanin: SICAKLIK veya NEM");
            }
            
            gelenVeri = ""; // Bir sonraki komut için temizle
          }
        } else {
          gelenVeri += c; // Karakterleri string'e ekle
        }
      }
    }
  }

  // 1. Ölçüm Komutunu Gönder (Yüksek Hassasiyet Modu: 0x2400)
  Wire.beginTransmission(SHT3X_I2C_ADDR);
  Wire.write(0x24); // Üst Byte
  Wire.write(0x00); // Alt Byte
  
  if (Wire.endTransmission() != 0) {
   // Serial.println("Hata: Sensör bulunamadı! D1(SCL) ve D2(SDA) bağlantılarını kontrol edin.");
    //delay(2000);
    return;
  }
  
  // ESP8266 arka plan görevlerini (Wi-Fi vb.) aksatmamak için kısa bekleme
  delay(1000); 

 
}

