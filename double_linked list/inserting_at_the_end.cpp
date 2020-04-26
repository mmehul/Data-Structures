#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
		node* prev;
		node(int data){
			this->data = data;
			next = NULL;
			prev = NULL;
		}
};

node* insert_node(node* start,int data){
	node* n = new node(data);
	if(start != NULL){
		node* ptr=start;
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}
		ptr->next=n;
		n->prev=ptr;
	}else{
		start=n;
	}
	return start;
}

node* create_node(){
	int data;
	node* k = NULL;
	cin>>data;
	while(data!=-1){
		k = insert_node(k,data);
		cin>>data;
	}
	return k;
}

void display(node* start){
	while(start->next!=NULL){
		cout<<start->data<<"<==>";
		start = start->next;
	}
	cout<<start->data;
}

void display_reverse(node* start){
	node* ptr=start;
	while(start->next!=NULL){
		start = start->next;
	}
	while(start!=ptr){
		cout<<start->data<<"<==>";
		start = start->prev;
	}
	cout<<start->data;
	
}

int main(){
	node* k = NULL;
	k=create_node();
	display(k);
	cout<<endl;
	display_reverse(k);
	return 0;
}
