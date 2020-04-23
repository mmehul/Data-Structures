#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		node(int data){
			this->data=data;
			next=NULL;
		}
};

node* insert_node(node* head,int data){
	node* start=new node(data);
	if(head==NULL){
		head=start;
	}
	else{
		start->next=head;
		head=start;
	}
	return head;
}

node* create(){
	node* k=NULL;
	int data;
	cin>>data;
	while(data!=-1){
		k=insert_node(k,data);
		cin>>data;
	}
	return k;
}

void display(node* start){
	while(start!=NULL){
		cout<<start->data<<"-->";
		start= start->next;
	}
}

int main(){
	node* n=NULL;
	n=create();
	display(n);
	return 0;
}
