#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
		node(int data){
			this->data = data;
			next = NULL;
		}
};
node* front = NULL;
node* rear = NULL;
void push(int data){
	node* n = new node(data);
	if(front == NULL){
		front = n;
		rear = n;
	}else{
		node* ptr= front;
		while(ptr!=rear){
			ptr=ptr->next;
		}
		ptr->next = n;
		rear =n;
	}
}
void pop(){
	if(front == rear && front == NULL){
		cout<<"Underflow";
	}else if(front == rear){
		front = NULL; 
		rear = NULL;
	}else{
		node* ptr=front;
		front =front->next;
		ptr->next=NULL;
		delete(ptr);
	}
}
void display(){
	node* ptr = front;
	while(ptr!=rear){
		cout<<ptr->data<<"  ";
		ptr=ptr->next;
	}
	cout<<ptr->data;
}
int main(){
	string response = "yes";
	while(response == "yes"){
		int data;
		cout<<"Want to add a data:  ";
		cin>>response;
		if(response == "yes"){
			cout<<endl<<"Enter the data:";
			cin>>data;
			push(data);
		}
	}
	cout<<endl;
	display();
	response = "yes";
	while(response == "yes"){
		cout<<endl<<"Want to pop:";
		cin>>response;
		if(response == "yes"){
			pop();
		}
	} 
	display();
	return 0;
}
