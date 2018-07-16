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

void printMiddles(node* head){
	node* slow = head;
	node* slow_prev = NULL;
	node* fast = head;
	while(fast!=NULL && fast->next!=NULL){
		slow_prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	if(fast==NULL){
		cout<<"There are two middles"<<slow_prev->data<<" and "<<slow->data<<endl;
	}else{
		cout<<"There is only one middle"<<slow->data<<endl;
	}

}

int main(){
	node* head = NULL;
	readList(head);
	print(head);
    printMiddles(head);
}