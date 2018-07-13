#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};

void levelOrderPrint(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);


	while(!q.empty()){
		node* f=q.front();

		if(f==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty())
				q.push(NULL);
		}else{
			cout<<f->data<<" ";
			q.pop();

			if(f->left)
				q.push(f->left);
			if(f->right)
				q.push(f->right);
		}
	}
	cout<<endl;
}

void preOrder(node* root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(node* root){
	if(root==NULL)
		return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

void postOrder(node* root){
	if(root==NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}


node* insertInBST(node* root,int d){
	if(root==NULL)
		return new node(d);
	if(root->data>=d)
		root->left=insertInBST(root->left,d);
	else
		root->right=insertInBST(root->right,d);
	return root;
}


node* readBST(){
		int d;
		node* root=NULL;
		cin>>d;
		while(d!=-1){
			root=insertInBST(root,d);
			cin>>d;
		}
		return root;
}


node* search(node* root,int key){
	if(root == NULL)
		return NULL;
	if(root->data == key)
		return root;
	if(root->data > key)
		return search(root->left,key);
	return search(root->right,key);
}

node* findLargest(node* root){
	node* temp=root;
	while(temp->right!=NULL)
		temp=temp->right;
	return temp;
}


node* removeNode(node* root,int key){
	if(root==NULL)
		return NULL;
	if(root->data==key){
		if((root->left==NULL) && (root->right==NULL)){
			delete root;
			return NULL;
		}else if((root->left!=NULL) && (root->right==NULL)){
			node* temp=root->left;
			delete root;
			return temp;			
		}else if((root->left==NULL) && (root->right!=NULL)){
			node* temp=root->right;
			delete root;
			return temp;
		}else{
			node* biggest=findLargest(root->left);
			root->data=biggest->data;
			root->left=removeNode(root->left,biggest->data);
		}
	}else if(root->data > key){
		 root->left=removeNode(root->left,key);
	}else
		root->right=removeNode(root->right,key);
	return root;
}

bool isBST(node* root,int minV=INT_MIN,int maxV=INT_MAX){
	if(root==NULL)
		return true;
	if((root->data>=minV) && (root->data<maxV) && isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV))
		return true;
	return false;
}


int main(){
	node* root=NULL;
	root=readBST();
	levelOrderPrint(root); cout<<endl;
	//preOrder(root); cout<<endl;
	//inOrder(root); cout<<endl;
	//postOrder(root); cout<<endl;
    cout<<isBST(root)<<endl;
    removeNode(root,8);
    cout<<isBST(root)<<endl;
    levelOrderPrint(root); cout<<endl;
}