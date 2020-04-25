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
int counts(node* start){
	int count = 0;
	node* ptr = start;
	while(ptr->next!=start){
		ptr=ptr->next;
		count++;
	}
	return count;
}
node* insertion_node(node* start,int data,int index, int size){
	node* n = new node(data);
	if(index==0){
		n->next=start->next;
		start=n;
	}else if(index==size){
		node* ptr=start;
		while(ptr->next!=start){
			ptr = ptr->next;
		}
		ptr->next=n;
		n->next=start;
	}else{
		node* ptr =start;
		while(index!=0){
			index--;
			ptr=ptr->next;
		}
		node* k= start;
		while(k->next!=ptr){
			k=k->next;
		}
		k->next=n;
		n->next=ptr;
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
	int count = counts(m);
	string response = "yes";
	while(response == "yes"){
		cout<<endl<<"Want to add any node in between:"<<endl;
		cin>>response;
		if(response =="yes"){
			int data1,data2;
			cout<<"Enter the data";
			cin>>data1;
			cout<<endl<<"Enter where you want to add:";
			cin>>data2;
			m=insertion_node(m,data1,data2,count);
		}
	}
	display(m);
	return 0;
}
