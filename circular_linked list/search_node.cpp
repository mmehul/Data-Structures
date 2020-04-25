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

bool search_node(node* start,int data){
	int x=0;
	node* ptr=start;
	while(ptr->next!=start){
		if(ptr->data !=data){
			x=1;
		}else{
			x=0;
			break;
		}
		ptr=ptr->next;
	}
	if(ptr->data==data){
		x=0;
	}
	if(x==0){
		return true;
	}else{
		return false;
	}
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
	while(response == "yes"){
		cout<<endl<<"Want to search any value:"<<endl;
		cin>>response;
		if(response =="yes"){
			int data;
			cout<<"Enter the data"<<endl;
			cin>>data;
			if(search_node(m,data)){
				cout<<"Found"<<endl;
			}else{
				cout<<"Not Found"<<endl;
			}
		}
	}
	display(m);
	return 0;
}
