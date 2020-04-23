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

node* insert_node(node* start,int data){
	node* n=new node(data);
	if(start==NULL){
		start=n;
	}
	else{
		n->next=start;
		start=n;
	}
	return start;
}

node* create_node(){
	node* m=NULL;
	int data;
	while(data!=-1){
		m=insert_node(m,data);
		cin>>data;
	}
	return m;
}

node* deletion_node_at_the_end(node* start){
	node* ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	node* k=start;
	while(k->next!=ptr){
		k=k->next;
	}
	k->next=NULL;
	delete(ptr);
	return start;
}

void display(node* start){
	while(start->next!=NULL){
		cout<<start->data<<"-->";
		start=start->next;
	}
}

int main(){
	node* k=NULL;
	k=create_node();
	display(k);
	cout<<endl;
	k=deletion_node_at_the_end(k);
	display(k);
	return 0;
}
