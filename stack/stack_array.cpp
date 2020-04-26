#include<iostream>
using namespace std;
int main(){
	
	int stack[100],front=0,rear=0;
	int data;
	cin>>data;
//	int i=0
	while(data!=-1){
		stack[rear]=data;
		rear++;
		cin>>data;
	}
	for(int i=front;i<rear;i++){
		cout<<stack[i]<<"-->";
	}
	cout<<endl;
	string response="yes";
	while(response!="no"){
		cout<<"Want to delete:"<<endl;
		cin>>response;	
		if(response!="no"){
			rear--;
		}
	}
	for(int i=front;i<rear;i++){
		cout<<stack[i]<<"-->";
	}
	
	
	return 0;
}
