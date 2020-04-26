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

node* insert_node(node* start,int data){
	node* n = new node(data);
	if(start==NULL){
		start=n;
	}else{
		n->next=start;
		start=n;
	}
	return start;
}

node* create_node(){
	node* k = NULL;
	int data;
	cin>>data;
	while(data!=-1){
		k = insert_node(k,data);
		cin>>data;
	}	
	return k;
}

node* reverse_list(node* start){
	node* next1 = NULL;
	node* prev = NULL;
	node* current = start;
	while(current != NULL){
		next1=current->next;
		current->next=prev;
		prev=current;
		current = next1;
	}
	return prev;
}
void display(node* start){
	while(start!=NULL){
		cout<<start->data<<"  ";
		start=start->next;
	}
}
int main(){
	node* k = NULL;
	k=create_node();
	cout<<endl;
	display(k);
	cout<<endl;
	k = reverse_list(k);
	display(k);
	return 0;
}

