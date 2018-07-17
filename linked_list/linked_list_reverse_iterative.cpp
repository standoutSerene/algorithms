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


void reverse(node* &head){
	node* prev = NULL;
	node* curr = head;
	while(curr!=NULL ){
		node* n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;
	}
    head = prev;
}

int main(){
	node* head = NULL;
	readList(head);
	print(head);
	reverse(head);
	print(head);
}