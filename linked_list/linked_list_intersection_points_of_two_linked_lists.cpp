#include<iostream>
#include<unordered_set>
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

node* findCycle(node* head){
	node* temp = head;
	unordered_set<node* > s;
	while(temp!=NULL){
		if(s.find(temp)==s.end())
			s.insert(temp);
		else
			return temp; 
    temp = temp->next;
	}
	return NULL;
}

void findIntersection(node* &headOne,node* &headTwo){
	node* endTwo = headTwo;
	while(endTwo->next!=NULL)
		endTwo = endTwo->next;
	endTwo->next = headTwo;
	node* intersect = findCycle(headOne);
	cout<<"The intersection node value is "<<intersect->data<<endl;
	endTwo->next = NULL;
}

node* find(node* head,int val){
    while(head!=NULL){
        if(head->data == val)
            return head;
        head = head->next;
    }
    return NULL;
}

int main(){
    node* headOne = NULL;
    readList(headOne);
    node* headTwo = NULL;
    headTwo = new node(10);
    headTwo->next = find(headOne,15);
    print(headOne);
    print(headTwo);
    findIntersection(headOne,headTwo);
    print(headOne);
    print(headTwo);
}