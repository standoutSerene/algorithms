#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int d){
		data = d;
		next =  NULL;
	}
};

void insertAtHead(node* &head,int data){
	node* n = new node(data);
	n->next = head;
	head = n;
}

void readList(node* &head){
	int data;
	cin>>data;

	while(data!=-1){
		insertAtHead(head,data);
		cin>>data;
	}
}

void print(node* head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}


pair<node*,node*> findNode(node*head,int val){
	pair<node*,node*> ret; ret.first = NULL; ret.second = NULL;
	node* prev = NULL;
    while(head!=NULL){
        if(head->data==val){
        	ret.first = prev;
        	ret.second = head;
            return ret;
        }
        prev = head;
        head = head->next;
    }
    return ret;
}

void swap(node* &head,int a,int b){
	pair<node*,node*> one = findNode(head,a);
	pair<node*,node*> two = findNode(head,b);
	if(one.first!=NULL)
		one.first->next = two.second;
	else
		head = two.second;

	if(two.first!=NULL)
		two.first->next = one.second;
	else
		head = one.second;


	node* next = one.second->next;
	one.second->next = two.second->next;
	two.second->next = next;
}

int main(){
	node* head = NULL;
	readList(head);
	print(head);
	swap(head,1,9);
	print(head);
}