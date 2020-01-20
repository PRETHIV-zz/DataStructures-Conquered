/*
    Input:
          pret
          pubg
          hello
    Trie:
            :
           p  h
          r u  e
         e   b  l
        t     g  l
                  o
*/


#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct Node{
    char c;
    struct Node *child[258];
    Node(char letter){
        c=letter;
        for(int i=0;i<258;i++){
            child[i]=NULL;
        }
    }
};

void insertintoTrie(struct Node* root,string s){
    if(s.size()==0){
        return;
    }
    else{
        char temp=s[0];
        if(root->child[temp]==NULL){
        root->child[temp]=new Node(temp);
        insertintoTrie(root->child[temp],s.substr(1));
        }
        else{
            insertintoTrie(root->child[temp],s.substr(1));
        }
    }
}


void Lvl_Ord_Trie(struct Node* Trie){
    queue<struct Node*> q;
    q.push(Trie);
    while(!q.empty()){
        struct Node *temp=q.front();
        q.pop();
        cout<<temp->c<<" ";
        int i=0;
        while(i<258){
            if(temp->child[i]!=NULL){
                q.push(temp->child[i]);
            }
            i++;
        }
    }
}


int main()
{
    struct Node *Trie=new Node(':');
    int i=3;
    string s;
    while(i)
    {
        cin>>s;
        insertintoTrie(Trie,s);
        i--;
    }

    Lvl_Ord_Trie(Trie);

    return 0;
}
