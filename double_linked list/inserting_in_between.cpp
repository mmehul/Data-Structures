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

int counts(node* start){
	int count=0;
	while(start!=NULL){
		count++;
		start=start->next;
	}
	return count;
}

node* insert_between(node* start,int data,int index){
	node* n = new node(data);
	if(index == 0){
		n->next=start;
		start=n;
	}else if(index == counts(start)){
		node* ptr=start;
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}
		ptr->next=n;
		n->prev=ptr;
	}else{
		node* ptr=start;
		while(index!=0){
			ptr=ptr->next;
			index--;
		}
		
		n->next=ptr->next;
		ptr->next=n;
		ptr->next->next->prev=n;
		n->prev=ptr;
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
		cout<<endl<<"Want to enter any node in between:";
		cin>>response;
		if(response!="no"){
			int data,index;
			cout<<endl<<"enter the data and index number:";
			cin>>data>>index;		
			k = insert_between(k,data,index-1);
		}
			
	}	
	display(k);
	cout<<endl;
	display_reverse(k);
	return 0;
}
