#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int data;
    struct Node *left,*right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

struct Node* insertT(struct Node* root,int key){
    if(root==NULL){
        return new Node(key);
    }
    else{
        if(key<=root->data){
            root->left=insertT(root->left,key);
        }
        else{
            root->right=insertT(root->right,key);
        }
        return root;
    }
}

void Lvl_Ord_LbyL(struct Node* root){
    queue<struct Node*> q;
    q.push(root);
    struct Node *n=NULL;
    q.push(n);
    cout<<"\n";
    while(!q.empty()){
        if(q.size()==1&&q.front()==n){
                //cout<<"Base\n";
            break;
           // q.pop();
        }
        struct Node *temp=q.front();
        //cout<<"Struct temp "<<temp->data<<endl;
        q.pop();
        //cout<<"Popped\n";
        if(temp==NULL){

            //q.pop();
            //cout<<"Temp is NULL\n";
            temp=q.front();
            q.pop();
           // cout<<"New Temp"<<temp->data<<endl;
            q.push(n);
           // cout<<"Null pushed"<<endl;
            cout<<"\n";
        }
        cout<<temp->data<<" ";
        if(temp->left!=NULL){
                //cout<<"Left Pushed";
            q.push(temp->left);
        }
        if(temp->right!=NULL){
           // cout<<"Right pushed";
            q.push(temp->right);
        }
       // cout<<"Q size "<<q.size()<<endl;
    }
}

int main()
{
    struct Node *root=NULL;
    int n,key;
    cin>>n;

    while(n){
        cin>>key;
        root=insertT(root,key);
        n--;
    }

    Lvl_Ord_LbyL(root);

    return 0;
}
