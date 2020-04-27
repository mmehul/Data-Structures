#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* left;
		node* right;
		node(int data){
			this->data = data;
			left = NULL;
			right = NULL;
		}
};

node* create_node(node* root, int data){
	if(root == NULL){
		node* n = new node(data);
		root = n;
	}else if(root->data > data){
		root->left = create_node(root->left,data);
	}else if(root->data < data){
		root->right = create_node(root->right,data);
	}
	return root;
}
node* build_bst(){
	node* k = NULL;
	int data;
	cin>>data;
	while(data!=-1){
		k = create_node(k,data);
		cin>>data;
	}
	return k;
}

bool search_node(node* root,int data){
	if(root == NULL){
		return false;
	}else if(root->data == data){
		return true;
	}else if(root->data > data){
		return search_node(root->left,data);
	}else if(root->data < data){
		return search_node(root->right,data);
	}
	return false;
}

node* findmax(node* root){
	while(root->right != NULL){
		root = root->right;
	}
	return root;
}

node* deletion_node(node* root,int data){
	if(root == NULL){
		return root;
	}else if(root->data > data){
		root->left = deletion_node(root->left,data);
	}else if( root->data < data){
		root->right = deletion_node(root->right,data);
	}else{
		if(root->left == NULL && root->right == NULL){
			root = NULL;
			return root;
		}else if(root->left == NULL){
			node* root1 = root;
			root = root->right;
			delete root1;
			return root;
		}else if(root->right == NULL){
			node* root1 = root;
			root = root->left;
			delete root1;
			return root;
		}else{
			node* root1 = findmax(root->left);
			root->data = root1->data;
			root->left = deletion_node(root->left,root1->data);
		}
	}
}

void preorder(node* root){
	if(root!=NULL){
		preorder(root->left);
		preorder(root->right);
		cout<<root->data<<"   ";
	}
}

void postorder(node* root){
	if(root!=NULL){
		cout<<root->data<<"   ";
		postorder(root->left);
		postorder(root->right);
	}
}
void inorder(node* root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<"  ";
		inorder(root->right);
	}
}

int main(){
	node* k = NULL;
	k = build_bst();
	cout<<endl<<"preorder:   ";
	preorder(k);
	cout<<endl<<"inorder:   ";
	inorder(k);
	cout<<endl<<"postorder:  ";
	postorder(k);
	cout<<endl;
	string response = "yes";
	while(response == "yes"){
		cout<<endl<<"Want to search any node:  ";
		cin>>response;
		if(response == "yes"){
			int data;
			cout<<endl<<"Enter the data:  ";
			cin>>data;
			if(search_node(k,data)){
				cout<<endl<<"Want to delete this node:  ";
				cin>>response;
				if(response == "yes"){
					k = deletion_node(k,data);
					cout<<endl;
					inorder(k);
				}else{
					response = "yes";
				}
			}else{
				cout<<endl<<"Not Found";
			}
		}
	}
	return 0;
}
