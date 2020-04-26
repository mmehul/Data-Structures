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
	n->next=start;
	if(start != NULL){
		start->prev = n;
	}
	start = n;
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

bool search_node(node* start,int data){
	int x=0;
	while(start!=NULL){
		if(start->data == data){
			x=0;
			break;
		}else{
			x=1;
		}
		start = start->next;
	}
	if(x==0){
		return true;
	}else{
		return false;
	}
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
	string response = "yes";
	while(response == "yes"){
		cout<<endl<<"Want to search any element:  ";
		cin>>response;
		if(response == "yes"){
			int data;
			cout<<endl<<"Enter the data:";
			cin>>data;
			if(search_node(k,data)){
				cout<<endl<<"Found";
			}else{
				cout<<endl<<"Not Found";
			}
		}
	}
	return 0;
}
