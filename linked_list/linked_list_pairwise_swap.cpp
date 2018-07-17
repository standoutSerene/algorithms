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

void pairwiseSwap(node* &head){
	node* one = head;
	node* two = NULL;

	if(head!=NULL)
		two = head->next;

	while(one!=NULL && two!=NULL){
		int temp = two->data;
		two->data = one->data;
		one->data = temp;

		one = one->next->next;
		if(two->next!=NULL)
			two = two->next->next;
	}
}

int main(){
	node* head = NULL;
	readList(head);
	print(head);
	pairwiseSwap(head);
	print(head);
}