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

node* insert_node(node* start, int data){
	node* n=new node(data);
	if(start==NULL){
		start=n;
	}
	else{
		node* ptr=start;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=n;
	}
	
	return start;
}

node* create_node(){
	node* m=NULL;
	int data;
	cin>>data;
	while(data!=-1){
		m=insert_node(m,data);
		cin>>data;
	}
	return m;
}

void display(node* start){
	while(start!=NULL){
		cout<<start->data<<"-->";
		start=start->next;
	}
}

int main(){
	node* k=NULL;
	k=create_node();
	display(k);
	return 0;
}
