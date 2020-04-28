#include<iostream>
using namespace std;

void insertionSort(int arr[],int start, int end){
	for(int i=start;i<end;i++){
		int j = i-1;
		int val = arr[i];
		while(j>=0 && arr[j]>val){
			arr[j+1] = arr[j];
			j = j - 1;
		}
		arr[j+1] = val;
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
	insertionSort(arr,0,n);
	display(arr,n);
	return 0;
}
