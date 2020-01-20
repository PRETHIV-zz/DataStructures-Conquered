#include<iostream>
#include<string>
#include<queue>

using namespace std;


struct Node{
    char c;
    struct Node *child[258];
    //since ascii ranges from 0-256
    Node(char letter){
        c=letter;
        for(int i=0;i<258;i++){
            child[i]=NULL;
        }
    }
};

void insertintoTrie(struct Node *root,string s){
    if(s.size()==0){
        return;
    }
    else{
        char c=s[0];
        if(root->child[c]==NULL){
            root->child[c]=new Node(c);
            insertintoTrie(root->child[c],s.substr(1));
        }
        else{
            insertintoTrie(root->child[c],s.substr(1));
        }
    }
}

void Lvl_Ord(struct Node* root){
    queue<struct Node*> q;
    q.push(root);
    while(!q.empty()){
        struct Node *temp=q.front();
        q.pop();
        cout<<temp->c<<" ";
        for(int i=0;i<258;i++){
            if(temp->child[i]!=NULL){
                q.push(temp->child[i]);
            }
        }
    }
}

int main(){
    string s;
    struct Node *Trie=new Node(':');
    cout<<"Enter a word or sentence to create its suffix tree";
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
        insertintoTrie(Trie,s.substr(i));
        //Suffix tree is similar to trie...except this main logic part
    }
    Lvl_Ord(Trie);
    return 0;
}
