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

node* create_bst(node* root,int data){
	if(root == NULL){
		node* n = new node(data);
		root = n;
		return root;
	}else if(root->data > data){
		root->left = create_bst(root->left,data);
	}else if(root->data < data){
		root->right = create_bst(root->right,data);
	}
}

node* build_bst(){
	node* n = NULL;
	int data;
	cin>>data;
	while(data != -1){
		n = create_bst(n,data);
		cin>>data;
	}
	return n;
}

void inorder(node* root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<"  ";
		inorder(root->right);
	}
}

int main(){
	node* k =NULL;
	k = build_bst();
	cout<<endl;
	inorder(k);
	return 0;
}
