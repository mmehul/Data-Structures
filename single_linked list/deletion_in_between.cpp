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

bool search(node* start,int data){
	int x=0;
	while(start!=NULL){
		if(start->data==data){
			x=1;
			break;
		}
		start=start->next;
	}
	if(x==1){
		return true;
	}
	else{
		return false;
	}
}

node* deletion_node(node* start,int data){
	node* t=start;
	while(t->data!=data){
		t=t->next;
	}
	node* prev=start;
	while(prev->next!=t){
		prev=prev->next;
	}
	prev->next=t->next;
	delete(t);
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
	int data;
	string response="yes";
	while(response=="yes"){
		cout<<"Enter the data to be deleted";
		cin>>data;
		if(search(k,data)){
			deletion_node(k,data);
		}
		else{
			cout<<endl<<"data not found";
		}
		cout<<endl<<"Want to try again?";
		cin>>response;
	}
	
	display(k);
	return 0;
}
