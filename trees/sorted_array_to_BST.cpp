#include<iostream>
#include<queue>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};


void levelOrderPrint(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* f = q.front();
		if(f==NULL){
			cout<<endl;;
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

node* sortedArrayToBST(int *arr,int s,int e){
	if(s>e)
		return NULL;
	int mid = (s+e)/2;
	node* root = new node(arr[mid]);
	root->left = sortedArrayToBST(arr,s,mid-1);
	root->right = sortedArrayToBST(arr,mid+1,e);
    return root;
}

void preOrder(node* root){
	if(root == NULL)
		return;
	cout<<root->data<<"->";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(node* root){
	if(root == NULL)
		return;
	inOrder(root->left);
	cout<<root->data<<"->";
	inOrder(root->right);
}

void postOrder(node* root){
	if(root == NULL)
		return;

	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<"->";
}

int main(){
	int arr[]={1,2,3,4,5,6};
    int len = sizeof(arr)/sizeof(int);
	node* root = sortedArrayToBST(arr,0,len-1);
	levelOrderPrint(root);
	preOrder(root); cout<<endl;
	inOrder(root); cout<<endl;
	postOrder(root); cout<<endl;
}
