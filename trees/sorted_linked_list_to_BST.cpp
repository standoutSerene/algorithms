    #include<iostream>
    #include<queue>
    #include<cmath>
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

    class treeNode{
    public:
        int data;
        treeNode* left;
        treeNode* right;

        treeNode(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
    };

    void levelOrderPrint(treeNode* root){
        queue<treeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            treeNode* f = q.front();
            if(f==NULL){
                cout<<endl;;
                q.pop();
                if(!q.empty())
                    q.push(NULL);
            }else{
                cout<<f->data<<" ";
                q.pop();
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }
        }
        cout<<endl;
    }

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

    node* moveNsteps(node* head,int N){
        for(int i=1;i<=N-1;i++)
            head = head->next;
        return head;
    }



    treeNode* sortedLLToBST(node* head,int N){
        if(N<=0)
            return NULL;
        if(N==1)
            return new treeNode(head->data);
        node* mid = moveNsteps(head,N/2+1);
        treeNode* root = new treeNode(mid->data);
        root->left = sortedLLToBST(head,N/2);
        int index = 0;
        if(N%2 == 0)
            index = N/2 - 1;
        else
            index = N/2;
        root->right = sortedLLToBST(mid->next,index);
        return root;
    }

    void preOrder(treeNode* root){
        if(root == NULL)
            return;
        cout<<root->data<<"->";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(treeNode* root){
        if(root == NULL)
            return;
        inOrder(root->left);
        cout<<root->data<<"->";
        inOrder(root->right);
    }


    void postOrder(treeNode* root){
        if(root == NULL)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<"->";
    }

    int main(){
        node* head = NULL;
        readList(head);
        print(head);
        int len = 8;
        treeNode* root = sortedLLToBST(head,len);
        levelOrderPrint(root); cout<<endl;
        preOrder(root); cout<<endl;
        inOrder(root); cout<<endl;
        postOrder(root); cout<<endl;

    }