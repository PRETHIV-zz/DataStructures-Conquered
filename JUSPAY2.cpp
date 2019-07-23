#include<iostream>
#include<queue>


using namespace std;



vector< pair<int,int> > v;


struct Node{
    int data;
    vector<struct Node*> child;

    Node(int d){
        data=d;
    }

};


struct Node* findnode(struct Node* root,int p){
    queue<struct Node*> q;
    q.push(root);

    while(!q.empty()){
        struct Node *temp=q.front();
        q.pop();
        if(temp->data==p){
            return temp;
        }
        int k=0,n=temp->child.size();
        while(k<n){
            q.push(temp->child[k]);
            k++;
        }

    }

}


void insertnode(struct Node* parent,int c){
        parent->child.push_back(new Node(c));
}


void treebuild(struct Node* root){
        int p,c;
        for(int i=0;i<v.size();i++){
            p=v[i].first;
            c=v[i].second;
            struct Node *parent=findnode(root,p);
            insertnode(parent,c);
        }

}

void lvlorder(struct Node* root){
    queue<struct Node*> q;
    q.push(root);
    cout<<endl;
    while(!q.empty()){
        struct Node *temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        int k=0,n=temp->child.size();
        while(k<n){
            q.push(temp->child[k]);
            k++;
        }
    }
    cout<<endl;


}


void vectorbuild(int root,vector<int> v1){
    //pair<int,int> p=make_pair(0,0);

    //int newfind;

    for(int i=0;i<v1.size();i++){
        if(v1[i]==root){
            v.push_back(make_pair(v1[i],i));
            vectorbuild(i,v1);
        }
    }

}

void printpairvector(vector< pair<int,int> > r){
    cout<<endl;
    for(int i=0;i<r.size();i++){
        cout<<r[i].first<<" "<<r[i].second<<endl;
    }
    cout<<endl;

}


int heigh1t(struct Node* root){
    if(root->child.size()==0){
        return 1;
    }
    else{
    vector<int> depth;
    int k1=0,n1=root->child.size();
    while(k1<n1){
            int height=heigh1t(root->child[k1]);
        depth.push_back(height);
        k1++;
    }
    int m=depth[0];
    for(int i=0;i<depth.size();i++){
        if(depth[i]>m){
            m=depth[i];
        }
    }
    return m+1;
    }


}

void printgivenlevel(struct Node* root,int lvl){
    if(lvl==1){
        cout<<root->data<<" ";
    }
    else{
        int k=0,n=root->child.size();
        while(k<n){
            printgivenlevel(root->child[k],lvl-1);
            k++;
        }
    }
}


void lvlorder1(struct Node* root){
    int h=heigh1t(root);
    for(int i=2;i<=h;i++)
    {
        printgivenlevel(root,i);
        cout<<endl;
    }

}


int main()
{


     vector<int> vq;

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        vq.push_back(k);

    }

    vectorbuild(-1,vq);

    struct Node *root=new Node(-1);

    treebuild(root);

    lvlorder1(root);

    return 0;
}
