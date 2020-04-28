#include<iostream>
using namespace std;

void swap(int *a,int *b){
	int t =*a;
	*a = *b;
	*b = t;
}
void selectionSort(int arr[],int start, int end){
	for(int i=start;i<end;i++){
		for(int j=i;j<end;j++){
			if(arr[i] > arr[j]){
				swap(&arr[i],&arr[j]);
			}
		}
	}
}
void display(int arr[], int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"   ";
	}
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	selectionSort(arr,0,n);
	display(arr,n);
	return 0;
}
