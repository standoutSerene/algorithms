#include<iostream>
#include<queue>
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


node* buildTree(node *root){
	int d;
	cin>>d;

	if(d==-1)
		return NULL;
	root= new node(d);
	root->right=buildTree(root->right);
	root->left=	(root->left);
	return root;
}

int countNodes(node* root){
	if(root==NULL)
		return 0;
	return 1+countNodes(root->left)+countNodes(root->right);
}


int height(node* root){
	if(root==NULL)
        return 0;
	return 1+max(height(root->left),height(root->right));
}

void printLevelK(node* root,int k){
	if(root==NULL || k<1)
		return;
	if(k==1){
		cout<<root->data<<" ";
		return;
	}
	printLevelK(root->left,k-1);
	printLevelK(root->right,k-1);
}

void levelOrderBuild(node*&root){
	queue<node*> q;
	int d;


	cout<<"Enter root data : "<<endl;
	cin>>d;
	root=new node(d);
	q.push(root);

	while(!q.empty()){
		node* f=q.front();
		q.pop();

		cout<<"Enter the data of "<<f->data<<" : ";
		int c1,c2;
		cin>>c1>>c2;
		if(c1!=-1){
			f->left=new node(c1);
			q.push(f->left);
		}
		if(c2!=-1){
			f->right=new node(c2);
			q.push(f->right);
		}
	}
}



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

	if(root->data >= d)
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
	if(root==NULL)
		return NULL;
	if(root->data==key)
		return root;
	if(root->data>key)
		return search(root->left,key);
	else
		return search(root->right,key);

}


int main(){
	node* root =NULL;
	root=readBST();
	levelOrderPrint(root);
    cout<<endl;
    preOrder(root); cout<<endl;
    inOrder(root); cout<<endl;
    postOrder(root); cout<<endl;
}
