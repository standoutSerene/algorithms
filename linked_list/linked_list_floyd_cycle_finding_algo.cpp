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

void detectLoop(node* head){
	node* slow = head;
	node* fast = head;
	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			cout<<"Voila! Cycle Found"<<endl;
			return;
		}
	}
	cout<<"No Cycle Found";
}

node* findNode(node*head,int val){
    while(head!=NULL){
        if(head->data==val){
            return head;
        }
        head = head->next;
    }
}

int main(){
	node* head = NULL;
	readList(head);
	print(head);

    node* three = findNode(head,3); cout<<three->data<<endl;
    node* ten = findNode(head,10);   cout<<ten->data<<endl;
    //ten->next = three;
    detectLoop(head);


}