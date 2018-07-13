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
	if(root==NULL)
		return NULL;
	if(root->data==key)
		return root;
	if(root->data > key)
		return search(root->left,key);
	return search(root->right,key);
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

class LinkedList{
public:
	node* head;
	node* tail;
};

LinkedList convertTree2LL(node* root){
	LinkedList l;
	if(root==NULL){
		l.head=l.tail=NULL;
		return l;
	}else if((root->left==NULL) && (root->right==NULL)){
		l.head=l.tail=root;
		return l;
	}else if((root->left!=NULL) && (root->right==NULL)){
		LinkedList leftLL= convertTree2LL(root->left);
		leftLL.tail->right=root;
		l.head=leftLL.head;
		l.tail=root;
	}else if((root->left==NULL) && (root->right!=NULL)){
		LinkedList rightLL=convertTree2LL(root->right);
		root->right=rightLL.head;
		l.head=root;
		l.tail= rightLL.tail;
	}else{
		LinkedList leftLL=convertTree2LL(root->left);
		LinkedList rightLL=convertTree2LL(root->right);
		leftLL.tail->right=root;
		root->right=rightLL.head;

		l.head=leftLL.head;
		l.tail=rightLL.tail;
	}
	return l;
}

int childSum(node* root){
	if(root==NULL)
		return 0;
	int leftSum=childSum(root->left);
	int rightSum=childSum(root->right);

	int temp=root->data;
	root->data = leftSum+rightSum;
	return temp+root->data;
}

int leafSum(node* root){
	if(root==NULL)
		return 0;
	if((root->left==NULL) && (root->right==NULL))
		return root->data;
	return leafSum(root->left)+leafSum(root->right);
}

int leftLeafSum(node* root,int dir=1){
	if(root==NULL)
		return 0;
	if((root->left==NULL) && (root->right==NULL))
		return (root->data * dir);
	return leftLeafSum(root->left,1)+leftLeafSum(root->right,0);
}


void leftView(node* root,int currentLevel,int &maxLevel){
	if(root==NULL)
		return;
	if(currentLevel>maxLevel){
		cout<<root->data<<",";
		maxLevel=currentLevel;
	}
	leftView(root->left,currentLevel+1,maxLevel);
	leftView(root->right,currentLevel+1,maxLevel);
}

node* lca(node* root,node* a,node* b){
	if(root==NULL)
		return NULL;
	if(root==a || root==b)
		return root;
	node* left=lca(root->left,a,b);
	node* right=lca(root->right,a,b);

	if((left!=NULL) && (right!=NULL))
		return root;
	if(left==NULL && right!=NULL)
		return right;
	if(left!=NULL && right==NULL)
		return left;
	return NULL;
}

node* buildBSTArray(int* arr,int s,int e){
	if(s>e)
		return NULL;
	int mid=(s+e)/2;
	node* root=new node(arr[mid]);
	root->left=buildBSTArray(arr,s,mid-1);
	root->right=buildBSTArray(arr,mid+1,e);
	return root;
}

int main(){
	node* root=NULL;
	//root=readBST();
    int arr[]={1,3,4,6,7,8,10,13,14};
    root=buildBSTArray(arr,0,8);
	levelOrderPrint(root); cout<<endl;
	preOrder(root); cout<<endl;
	inOrder(root); cout<<endl;
	postOrder(root); cout<<endl;
    //LinkedList l=convertTree2LL(root);
    //node* temp=l.head;
    //while(temp!=NULL){
    //    cout<<temp->data<<" -> ";
    //    temp=temp->right;
    //}
    //cout<<endl;
    //cout<<leafSum(root)<<endl;
    //cout<<leftLeafSum(root)<<endl;
    //int min=INT_MIN;
    //leftView(root,0,min); cout<<endl;
    cout<<(lca(root,search(root,13),search(root,10)))->data<<endl;
}