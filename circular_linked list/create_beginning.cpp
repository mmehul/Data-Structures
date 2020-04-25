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
		n->next=start;
		start = n;
	} 
	else{
		n->next = start;
		start = n;
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
	while(start->next!=start){
		cout<<start->data<<"-->";
		start = start->next;
	}
	cout<<start->data;
}

int main(){
	node* m = NULL;
	m = create_node();
	display(m);
	return 0;
}
