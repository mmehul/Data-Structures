#include<iostream>
using namespace std;

void swap(int *a,int *b){
	int t =*a;
	*a = *b;
	*b = t;
}
void bubbleSort(int arr[],int start, int n){
	for(int i = start;i<n-1;i++){
		for(int j=start;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(&arr[j],&arr[j+1]);
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
	bubbleSort(arr,0,n);
	display(arr,n);
	return 0;
}
