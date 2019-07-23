#include<iostream>
#include<vector>
#include<queue>

using namespace std;



struct Node{
    int data;
    vector<struct Node*> child;

    Node(int d){
        data=d;
    }

};


struct Node* findparent(struct Node* root,int data){
    queue<struct Node*> q;
    q.push(root);

    while(!q.empty()){
        struct Node *temp=q.front();
        q.pop();
        if(temp->data==data){
            return temp;
        }
        int k=0;

        while(k<temp->child.size()){
                q.push(temp->child[k]);
                k++;
        }

    }
}


void insertnode(struct Node* parent,int d){
    struct Node *nn=new Node(d);
    parent->child.push_back(nn);
}


void printtree(struct Node* root){
    queue<struct Node*> q;
    q.push(root);
    cout<<endl;
    while(!q.empty()){
        struct Node *temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        int k=0;
        while(k<temp->child.size()){
            if(temp->child[k]!=NULL)
            {
                q.push(temp->child[k]);
            }
            k++;
        }

    }
    cout<<endl;
}

void lcafinder(struct Node* root,int d1,int d2){
    queue<struct Node*> q;
    q.push(root);
    bool f1=false,f2=false;

    while(!q.empty()){
        struct Node *temp=q.front();
        q.pop();
        int k=0;
        while(k<temp->child.size()){
            if(temp->child[k]->data==d1){
                f1=true;
            }
            if(temp->child[k]->data==d2){
                f2=true;
            }
            q.push(temp->child[k]);
            k++;
        }

        if(f1&&f2){
            cout<<"\nThe LCA is "<<temp->data;
            break;
        }
        else{
            f1=false;
            f2=false;
        }

    }

}


int main(){
    int n;
    cin>>n;
    struct Node *root=new Node(-1);

    for(int i=0;i<n;i++){
            int parent,data;
        cin>>parent>>data;
        struct Node *parent1=findparent(root,parent);
        insertnode(parent1,data);

    }

    cout<<"\nEnter 2 nos to find its lca ";
    int d1,d2;
    cin>>d1>>d2;


    lcafinder(root,d1,d2);

    printtree(root);

    return 0;
}
