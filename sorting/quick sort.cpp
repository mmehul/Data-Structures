#include<iostream>
using namespace std;

void swap(int *a,int *b){
	int t =*a;
	*a = *b;
	*b = t;
}

int partition(int arr[],int start,int end){
	int i=start-1;
	int pivot = arr[end];
	for(int j=start;j<end;j++){
		if(arr[j]<pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[end]);
	return (i+1);
}

void quickSort(int arr[],int start, int end){
	if(start < end){
		int p = partition(arr,start,end);
		
		quickSort(arr,start,p-1);
		quickSort(arr,p+1,end);
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
	quickSort(arr,0,n-1);
	display(arr,n);
	return 0;
}
