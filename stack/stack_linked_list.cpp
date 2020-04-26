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
node* top = NULL;

void push(int data){
	node* n =new node(data);
	if(top==NULL){
		top = n;
	}else{
		n->next = top;
		top = n;
	}
}
void pop(){
	if(top==NULL){
		cout<<"Underflow";
	}else{
		node* ptr = top;
		top = top->next;
		ptr->next=NULL;
		delete ptr; 
	}
}
void display(){
	if(top == NULL){
		cout<<"Underflow";
	}else{	
		node* ptr = top;
		while(ptr!= NULL){
			cout<<ptr->data<<"  ";
			ptr = ptr->next;
		}
	}
}
int main(){
	string response = "yes";
	while(response!="no"){
		cout<<"Want To add:";
		cin>>response;
		if(response == "yes"){
			int data;
			cout<<endl<<"Enter the data:   ";
			cin>>data;
			push(data);
		}
	} 
	cout<<endl;
	display();
	cout<<endl;
	response = "yes";
	while(response == "yes"){
		cout<<"Want to delete:";
		cin>>response;
		if(response == "yes"){
			pop();
		}
	}
	cout<<endl;
	display();
	return 0;
}
