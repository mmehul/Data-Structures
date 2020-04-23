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

int count_nodes(node* start){
	int count=0;
	while(start!=NULL){
		count++;
		start=start->next;
	}
	return count;
}

node* insert_node1(node* start,int data,int count){
	node* m=start;
	node* n=new node(data);
	if(count==0){
		n->next=start;
		start=n;
	}
	else if(count==count_nodes(start)){
		while(start->next!=NULL){
			start=start->next;
		}
		start->next=n;
	}
	else{
		while(count!=0){
			start=start->next;
			count--;
		}
		node* ptr=start->next;
		start->next=n;
		n->next=ptr;
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
	string response="yes";
	while(response!="no"){
		int count=count_nodes(k);
		int n;
		cout<<endl<<"Enter the index from where you want to insert:";
		cin>>n;
		if(n<=count){
			int data;
			cout<<endl<<"Enter the data:";
			cin>>data;
			k=insert_node1(k,data,n);
		}
		else{
			cout<<endl<<"Wrong index number added";
		}
		cout<<endl<<"Want to add again?";
		cin>>response;
	}
	display(k);
	return 0;
}
