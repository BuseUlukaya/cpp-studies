#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct {
    int *data;     
    int size;      
    int capacity;  
} Inventory;

int create(Inventory *inv, int initial_value );
void destroy(Inventory *inv);
int reserve(Inventory *inv, int new_capacity);
int append(Inventory *inv, int product_number );
int insert_at(Inventory *inv, int index, int product_number);
int delete_at(Inventory *inv, int index);
int find(Inventory *inv, int match_number);
void show_inventory(Inventory *inv);

int main(){
    int initial_value;
    int new_capacity;
    int product_number;
    int index;
    int choice;
    Inventory inv;
    do{
    	cout << endl;
        cout << "MENU" << endl;
        cout << "----------------------------------------" << endl;
        cout << " 1. Create new inventory" << endl;
        cout << " 2. Delete inventory" << endl;
        cout << " 3. Reserve inventory" << endl;
        cout << " 4. Append product" << endl;
        cout << " 5. Add product to spesific location" << endl;
        cout << " 6. Delete product to spesific location" << endl;
        cout << " 7. Find product" << endl;
        cout << " 8. Show inventory" << endl;
        cout << "----------------------------------------" << endl;
        cout << " 0. Exit" << endl << endl;

        cout << "Enter your choice : ";
        cin >> choice;
        cout << endl;

        switch(choice){
            case 1:
                cout << "Enter initial value : ";
                cin >> initial_value;
                cout << endl;
                create(&inv , initial_value);
                break;
            case 2:
                destroy(&inv);
                break;
            case 3:
                cout << "How much product input will you make? : ";
                cin >> new_capacity;
                cout << endl;
                reserve(&inv, new_capacity);
                break;
            case 4:
                cout << "How many product will you add? : ";
                cin >> product_number;
                cout << endl;
                append(&inv, product_number);
                break;
            case 5:
                cout << "Which index do you want to add a product to? : ";
                cin >> index;
                cout << endl;
                cout << "How many product will you add? : ";
                cin >> product_number;
                cout << endl;
                insert_at(&inv, index, product_number);
                break;
            case 6:
                cout << "Which index do you want to delete a product to? : ";
                cin >> index;
                cout << endl;
                delete_at(&inv, index);
                break;
            case 7:
                int number;
                cout << "How many products are you looking for your location? : ";
                cin >> number;
                find(&inv, number);
                break;
            case 8:
                show_inventory(&inv);
                break;
            case 0:
                cout << "Program was finished!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }while(choice != 0);
    
    return 0;

}

int create(Inventory *inv, int initial_value){
    inv->data =(int*)malloc(sizeof(int) *initial_value);
    if(inv ->data == NULL){
        cout << "Memory allocation failed!" << endl;
        return 1;
    }
    inv->size = 0;
    inv->capacity = initial_value;
    cout << "Inventory created successfully!" << endl;
    return 0;

}

void destroy(Inventory *inv){
    if(inv->data == NULL){
        cout << "Inventory is already empty!" << endl;
        return;
    }
    free(inv->data);
    inv->data = NULL;
    inv->size = 0;
    inv->capacity = 0;
    cout << "Inventory was deleted!" << endl;
}

int reserve(Inventory *inv, int new_capacity){
    if(new_capacity <= inv->capacity){
        cout << "Current capacity is enough!" << endl;
        return 0;

    } 
    int *tmp = (int*)realloc(inv->data, sizeof(int) * new_capacity);
    inv->data = tmp;
    inv->capacity = new_capacity;
    cout << "Capacity updated to!" << endl;
    return 1;
}

int append(Inventory *inv, int product_number){
    if(inv->size == inv->capacity){
        int new_capacity = (inv->capacity == 0) ? 1 : inv->capacity * 2;
        int *new_data = (int*)realloc(inv->data, sizeof(int) * new_capacity);
        if(new_data == NULL){
            return 0;
            cout << "Memory reallocation failed!" << endl;
        }
        inv->data = new_data;
        inv->capacity = new_capacity;
    }
        inv->data[inv->size] = product_number;
        inv->size++;
        cout << "Product appended!" << endl;
        
        return 1;
}

int insert_at(Inventory *inv, int index, int product_number) {
    
    if (index < 0 || index > inv->size){
        cout << "Invalid index!" << endl;
        return 0;
    }
    if (inv->size == inv->capacity) {
        int new_capacity = inv->capacity * 2;
        int *new_data = (int*)realloc(inv->data, sizeof(int) * new_capacity);
        if (new_data == NULL){
            cout << " Memory reallocation failed!" << endl;
            return 0;
        }
        inv->data = new_data;
        inv->capacity = new_capacity;
        cout << "Capacity doubled!" << endl;
    }
    for (int i = inv->size - 1; i >= index; i--) {
        inv->data[i + 1] = inv->data[i];
    }
    inv->data[index] = product_number;
    inv->size++;

    return 1; 
}

int delete_at(Inventory *inv, int index) {
    if (index < 0 || index >= inv->size){
        cout << "Invalid index!" << endl;
         return 0;
    }
    for (int i = index; i < inv->size - 1; i++) {
        inv->data[i] = inv->data[i + 1];
    }
    inv->size--;
    cout << "Product deleted at index!" << endl;
    return 1;
}

int find(Inventory *inv, int match_number){
    for(int i=0; i<inv->size; i++){
        if(inv->data[i] == match_number){
            cout << "Product found at index " << i << endl;
            return i;
        }
    }
    cout << "Product not found!" << endl;
        return -1;
}

void show_inventory(Inventory *inv){
    cout << "\nCurrent Inventory:\n";
    if (inv->data == NULL || inv->size == 0) {
        cout << "Inventory is empty.\n";
        cout << "Capacity: " << inv->capacity << endl;
        cout << "Total Products: " << inv->size << endl;
        return;
    }

    cout << "Total Products: " << inv->size << endl;
    cout << "Capacity: " << inv->capacity << endl;
    cout << "Products: ";
    for (int i = 0; i < inv->size; i++) {
        cout << inv->data[i];
        if (i < inv->size - 1) cout << ", ";
    }
    cout << endl;
}



