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

void oddBeforeEven(node* &head){
    node* odd_start = NULL;
    node* even_start = NULL;
	node* odd_ptr = NULL;
	node* even_ptr = NULL;
	node* temp = head;
	while(temp!=NULL){
		if(temp->data%2 == 1){
			if(odd_ptr == NULL){
				odd_ptr = temp;
                odd_start = temp;
            }
			else{
				odd_ptr->next = temp;
				odd_ptr = temp;
			}
		}else{
			if(even_ptr == NULL){
				even_ptr = temp;
                even_start = temp;
            }
			else{
				even_ptr->next = temp;
				even_ptr = temp;
			}
		}
		temp = temp->next;
	}
	odd_ptr->next = even_start;
	even_ptr->next = NULL;
	head = odd_start;
}


int main(){
	node* head = NULL;
	readList(head);
	print(head);
	oddBeforeEven(head);
	print(head);
}