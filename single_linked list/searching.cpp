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

int main(){
	node* k=NULL;
	k=create_node();
	display(k);
	int val;
	string response="yes";
	while(response=="yes"){
		cout<<endl<<"Enter the number to be searched for";
		cin>>val;
		if(search(k,val)){
			cout<<"Found";
		}
		else{
			cout<<"Not Found";
		}
		cout<<endl<<"Want to try again?";
		cin>>response;
	}
	return 0;
}
