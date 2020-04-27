#include<iostream>
using namespace std;

bool binary_search(int ar[],int start,int end,int data){
	if(start<=end){
		int mid = (start + end) / 2;
		if(ar[mid] == data){
			return true;
		}else if(ar[mid] < data){
			return binary_search(ar, mid + 1, end, data);
		}else{
			return binary_search(ar, start, mid - 1, data);
		}
	}
	return false;
}
int main(){
	int size;
	cin>>size;
	int arr[size];
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	for(int i=0;i<size;i++){
		for(int j=i;j<size;j++){
			if(arr[i] > arr[j]){
				int t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
	cout<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<"  ";
	}
	cout<<endl;
	string response = "yes";
	while(response == "yes"){
		cout<<"Want to search any data: ";
		cin>>response;
		if(response == "yes"){
			int data;
			cout<<endl<<"Enter the data: ";
			cin>>data;
			if(binary_search(arr,0,size,data)){
				cout<<endl<<"Found"<<endl;
			}else{
				cout<<"Not Found"<<endl;
			}
		}
	}
	return 0;
}

