#include<iostream>
using namespace std;
int main(){
	int queue[100],front=0,rear=0;
	int data;
	cin>>data;
	while(data!=-1){
		queue[rear]=data;
		rear++;
		cin>>data;
	}
	for(int i=front;i<rear;i++){
		cout<<queue[i]<<"-->";
	}
	cout<<endl;
	string response = "yes";
	while(response!="no"){
		cout<<"Want to delete ?"<<endl;
		cin>>response;
		if(response=="yes"){
			if(front!=rear){
				front++;
			}
			else{
				cout<<"Underflow";
			}
		}
	}
	cout<<endl;
	for(int i=front;i<rear;i++){
		cout<<queue[i]<<"-->";
	}
	
	return 0;
}
