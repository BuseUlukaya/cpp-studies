#include <iostream>
using namespace std;

int findmin(int array[], int size);
int findmax(int array[], int size);

int main(){
	int number;
	int i;
	int getlength;
	int min_number, max_number;
	cout<<"How many numbers will you enter?: ";
	cin>>number;
	int array[number];
	getlength = sizeof(array) / sizeof(array[0]);
	
	for(i=0; i<number; i++){
		cout<<"array["<<i<<"]: ";
		cin>>array[i];
	}
	
	min_number = findmin(array, getlength);
	max_number = findmax(array, getlength);
	cout<<"The smallest number in array: "<<min_number<<endl;
	cout<<"The largest number in array: "<<max_number<<endl;
	
	return 0;
	
}

int findmin(int array[], int size){
	int i;
	int min = array[0];
	for(i=0; i<size ;i++){
		if(array[i] < min){
			min = array[i];
		}
	}
	
	return min;
}

int findmax(int array[], int size){
	int i;
	int max=array[0];
	for(i=0; i<size;i++){
		if(array[i] > max){
			max = array[i];
		}
	}
	
	return max;
}
