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
		start = n;
		n->next=start;
	} 
	else{
		node* ptr=start;
		while(ptr->next!=start){
			ptr=ptr->next;
		}
		ptr->next=n;
		n->next=start;
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

node* delete_node(node* start){
	node* ptr=start;
	node* k = start;
	while(k->next!=start){
		k=k->next;
	}
	start=start->next;
	k->next=start;
	delete ptr;
	return start;
}

int counts(node* start){
	node* ptr=start;
	int count=0;
	while(ptr->next!=start){
		ptr=ptr->next;
		count++;
	}
	return count;
}

node* delete_node(node* start,int index){
	node* ptr=start;
	int count = counts(start);
	if(index==0){
		node* k=start;
		while(k->next!=start){
			k=k->next;
		}
		k->next=start->next;
		start=start->next;
		delete ptr;
	}else if(index==count){
		node* k=start;
		while(ptr->next!=start){
			ptr=ptr->next;
		}
		while(k->next!=ptr){
			k=k->next;
		}
		k->next=ptr->next;
		delete ptr;
	}else{
		while(index>0){
			ptr=ptr->next;
			index--;
		}
		node* k=start;
		while(k->next!=ptr){
			k=k->next;
		}
		k->next=ptr->next;
		delete ptr;
	}
	return start;
}

void display(node* start){
	node* ptr=start;
	while(ptr->next!=start){
		cout<<ptr->data<<"-->";
		ptr = ptr->next;
	}
	cout<<ptr->data;
}

int main(){
	node* m = NULL;
	m = create_node();
	display(m);
	string response = "yes";
	while(response!="no"){
		cout<<endl<<"want to delete a node?";
		cin>>response;
		if(response != "no"){
			int index;
			cout<<endl<<"Enter the index number";
			cin>>index;
			if(index>0){
				m = delete_node(m,index-1);
			}else{
				m = delete_node(m,0);
			}
		}
	}
	cout<<endl;
	display(m);
	return 0;
}
