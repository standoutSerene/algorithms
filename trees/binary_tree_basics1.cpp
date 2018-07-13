#include<iostream>
#include<queue>
#include<algorithm>
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

node* buildTree(node* root){
	int d;
	cin>>d;

	if(d==-1){
		return NULL;
	}

	root = new node(d);
	root->left=buildTree(root->left);
	root->right=buildTree(root->right);
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


void printLevelK(node *root,int k){
	if(root==NULL||k<1)
		return;
	if(k==1){
		cout<<root->data<<" ";
		return;
	}
	printLevelK(root->left,k-1);
	printLevelK(root->right,k-1);
}


void levelOrderBuild(node* &root){
	queue<node*> q;
	int d;

	cout<<"Enter root data"<<endl;
	cin>>d;

	root = new node(d);
	q.push(root);


	while(!q.empty()){
		node* f=q.front();
		q.pop();


		cout<<"Enter the children of "<<f->data<<" : ";
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

void levelOrderPrint(node *root){

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f=q.front();

        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
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


int diameter(node* root){
    if(root==NULL)
        return 0;
    return max(height(root->left)+height(root->right),max(diameter(root->left),diameter(root->right)));
}


pair<int,int> fastDiameter(node* root){
    pair<int,int> p;

    if(root==NULL){
            p.first=0;
            p.second=0;
            return p;
    }

    pair<int,int> leftTree=fastDiameter(root->left);
    pair<int,int> rightTree=fastDiameter(root->right);

    p.first=1+max(leftTree.first,rightTree.first);
    p.second=max(max(leftTree.second,rightTree.second),leftTree.first+rightTree.first);
    return p;
}


int main(){
	node* root=NULL;
    root =buildTree(root);
    //levelOrderBuild(root);
    levelOrderPrint(root);
    cout<<diameter(root)<<endl;
    cout<<fastDiameter(root).second<<endl;
}







