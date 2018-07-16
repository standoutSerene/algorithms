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

void NthFromLast(node* head,int N){
	node* slow = head;
	node* fast = head;
	for(int i=1;i<=N-1;i++){
			fast = fast->next;
    }
	while(fast->next!=NULL){
		slow = slow->next;
		fast = fast->next;
	}
    cout<<slow->data<<endl;
}

int main(){
	node* head = NULL;
	readList(head);
	print(head);
    NthFromLast(head,1);
    NthFromLast(head,2);
    NthFromLast(head,3);
    NthFromLast(head,4);
}