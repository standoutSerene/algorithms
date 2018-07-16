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

int detectLoop(node* head){
	node* slow = head;
	node* fast = head;
	int cycle_len=0;
    int found=0;
	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
            found = 1;
			while(slow->next!=fast){
				cycle_len++;
                slow = slow->next;
            }
			break;
		}
	}
	return cycle_len+found;
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
    cout<<"cycle length is "<<detectLoop(head)<<endl;


}