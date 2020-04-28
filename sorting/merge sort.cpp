#include<iostream>
using namespace std;

void merge(int arr[],int start,int mid,int end){
	int n1 = mid-start+1;
	int n2 = end-mid;
	int i,j,k=start;
	int left[n1],right[n2];
	for(i=0;i<n1;i++){
		left[i] = arr[start+i];
	}
	for(j=0;j<n2;j++){
		right[j] = arr[j+mid+1];
	}
	i=0;
	j=0;
	while(i<n1 && j<n2){
		if(left[i]<=right[j]){
			arr[k++] = left[i++];
		}else{
			arr[k++] = right[j++];
		}
	}
	while(i<n1){
		arr[k++] = left[i++];
	}
	while(j<n2){
		arr[k++] = right[j++];
	}
}
void mergeSort(int arr[],int start, int end){
	if(start < end){
		int mid = start + (end - start)/2;
		
		mergeSort(arr,start,mid);
		mergeSort(arr,mid+1,end);
		
		merge(arr,start,mid,end);
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
	mergeSort(arr,0,n-1);
	display(arr,n);
	return 0;
}
