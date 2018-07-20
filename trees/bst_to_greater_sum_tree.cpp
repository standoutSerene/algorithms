    #include<iostream>
    #include<queue>
    using namespace std;

    class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
    };

    void levelOrderBuild(node* &root){
        queue<node*> q;
        int d;
        cin>>d;
        root = new node(d);
        q.push(root);

        while(!q.empty()){
            node* f = q.front();
            q.pop();

            int c1,c2;
            cin>>c1>>c2;

            if(c1!=-1){
                f->left = new node(c1);
                q.push(f->left);
            }
            if(c2!=-1){
                f->right = new node(c2);
                q.push(f->right);
            }
        }
    }


    void levelOrderPrint(node* root){
        queue<node*> q;
        q.push(root);
        q.push(NULL);


        while(!q.empty()){
            node* f=q.front();

            if(f==NULL){
                cout<<endl;
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



    void preOrder(node* root){
        if(root==NULL)
            return;
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);

    }

    void inOrder(node* root){
        if(root==NULL)
            return;
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);

    }

    void postOrder(node* root){
        if(root==NULL)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";

    }


    void convert2GreaterSumTree(node* &root,int* sum){
        if(root==NULL)
            return;
        convert2GreaterSumTree(root->right,sum);
        *sum = *sum + root->data;
        root->data = *sum - root->data;
        convert2GreaterSumTree(root->left,sum);
    }

    int main(){
        node* root = NULL;
        levelOrderBuild(root);
        levelOrderPrint(root);
        preOrder(root); cout<<endl;
        inOrder(root); cout<<endl;
        postOrder(root); cout<<endl;
        int sum = 0;
        convert2GreaterSumTree(root,&sum);
         levelOrderPrint(root);
        preOrder(root); cout<<endl;
        inOrder(root); cout<<endl;
        postOrder(root); cout<<endl;
    }