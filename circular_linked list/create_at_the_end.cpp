#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		node(int data){
			this->data = data;
			next = 	NULL;
		}
};

node* insert_node(node* start,int data){
	node* n = new node(data);
	if(start == NULL){
		start = n;
		n->next=start;
	} 
	else{
		node* ptr=start;
		while(ptr->next!=start){
			ptr=ptr->next;
		}
		ptr->next=n;
		n->next = start;
	}
	return start;
}

node* create_node(){
	node* k = NULL;
	int data;
	cin>>data;
	while(data!=-1){
		k=insert_node(k,data);
		cin>>data;
	}
	return k;
}

void display(node* start){
	node* ptr = start;
	while(ptr->next!=start){
		cout<<ptr->data<<"-->";
		ptr = ptr->next;
	}
	cout<<ptr->data;
}

int main(){
	node* m = NULL;
	m = create_node();
	display(m);
	return 0;
}
