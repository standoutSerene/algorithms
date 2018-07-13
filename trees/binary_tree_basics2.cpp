#include<iostream>
#include<queue>
using namespace std;

class node{
public:
	int data;
	node *left;
	node *right;

	node(int d){
		data=d;
		right=NULL;
		left=NULL;

	}
};


node* buildTree(node* root){
	int d;
	cin>>d;

	if(d==-1){
		return NULL;
	}

	root=new node(d);
	root->left=buildTree(root->left);
	root->right=buildTree(root->right);
	return root;
}

int height(node* root){
	if(root==NULL)
		return 0;
	return 1+max(height(root->left),height(root->right));
}

void levelOrderPrint(node *root){
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
}

void mirror(node* root){
	if(root==NULL)
		return;
	swap(root->left,root->right);
	mirror(root->left);
	mirror(root->right);
}

bool areIdentical(node* root1,node* root2){
    if(root1==NULL && root2==NULL)
        return true;
    if( (root1==NULL && root2!=NULL)||(root1!=NULL && root2==NULL) )
        return false;
    if((root1->data==root2->data) && (areIdentical(root1->left,root2->left)) && (areIdentical(root1->right,root2->right)))
        return true;
    return false;
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

void preOrder(node* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}



int main(){
	node* root=NULL;
	root=buildTree(root);
	levelOrderPrint(root);
    //mirror(root);
    //cout<<endl;
    //levelOrderPrint(root);
    preOrder(root); cout<<endl;
    inOrder(root); cout<<endl;
    postOrder(root); cout<<endl;
}


