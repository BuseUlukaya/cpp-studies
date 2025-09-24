#include <iostream>
using namespace std;

void sortArrayDescending(int array[], int size);
void sortArrayAscending(int array[], int size);

int main(){
	int n;
	int i;
	int getlength;
	cout<<"How many numbers will you enter?\n";
	cin>>n;
	int array[n];
	
	for(i=0; i<n; i++){
		cout<<"array["<<i<<"]";   // 7 3 8 5 11 
		cin>>array[i];
	}
	
	getlength = sizeof(array) / sizeof(array[0]);
	
	cout<<"The array sorted from smallest to largest"<<endl;
	sortArrayAscending(array, getlength);
	cout<<"The array sorted from smallest to largest"<<endl;
	sortArrayDescending(array, getlength);
	
	return 0;
}

void sortArrayDescending(int array[], int size){
	int i, j;
	int temp;
	for(i=0; i<size-1; i++){
		for(j=0; j<size-i-1; j++){
			if(array[j] < array[j+1]){
				temp=array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	
	for(i=0; i<size; i++){
		cout<<array[i]<<"  ";
	}
}

void sortArrayAscending(int array[], int size){
	int i, j;
	int temp;
	for(i=0; i<size-1; i++){
		for(j=0; j<size-i-1; j++){
			if(array[j] > array[j+1]){
				temp=array[j+1];
				array[j+1] = array[j];
				array[j] = temp;
			}
		}
	}
	
	for(i=0; i<size; i++){
		cout<<array[i]<<"  ";
	}
}
