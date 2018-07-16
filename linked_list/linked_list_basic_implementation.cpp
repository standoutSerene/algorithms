#include<iostream>
using namespace std;

class node{

public:
	int data;
	node* next;
	node(int d){
		data = d;
		next = NULL;
	}
};

void insertAtHead(node* &head,int d){
	node* n = new node(d);
	n->next = head;
	head =n;
}

void readList(node* &head){
	int data;
	cin>>data;

	while(data!=-1){
		insertAtHead(head,data);
		cin>>data;
	}
}


void insertAtTail(node* &head,int d){
	if(head==NULL){
		head = new node(d);
		return;
	}

	node* temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = new node(d);
}

void print(node* head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}


int main(){
	node* head = NULL;
	readList(head);
	print(head);
}
