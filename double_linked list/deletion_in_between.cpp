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

int counts(node* start){
	int count = 0;
	while(start!=NULL){
		start = start->next;
		count++;
	}
	return count;
}

node* delete_node(node* start,int index){
	if(index == 0 ){
		start = start->next;
		start->prev = NULL;
	}else if(index == counts(start)){
		node* ptr= start;
		node* k =start;
		while(ptr->next!=NULL){
			if(ptr->next->next = NULL){
				k=ptr;
			}
			ptr=ptr->next;
		}
		k->next = NULL;
		ptr->prev=NULL;
		delete ptr;
	}else{
		node* ptr=start;
		while(index--){
			ptr=ptr->next;
		}
		node* k=start;
		while(k->next!=ptr){
			k=k->next;
		}
		k->next=ptr->next;
		ptr->next->prev = k;
		delete ptr;
	}
	return start;
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
		cout<<endl<<"Want to delete:  ";
		cin>>response;
		if(response == "yes"){
			int index;
			cout<<endl<<"Enter the index:";
			cin>>index;
			k =delete_node(k,index-1);
		}
	}
	cout<<endl;
	display(k);
	cout<<endl;
	display_reverse(k);
	return 0;
}
