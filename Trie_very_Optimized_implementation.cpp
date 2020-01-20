#include<iostream>
#include<map>
#include<string>
#include<queue>

using namespace std;

struct Node{
    char c;
    map<char,struct Node*> child;
    Node(char letter){
        c=letter;
    }
};

void insertintoTrie(struct Node* root,string s,int len_of_str){
    if(len_of_str==0){
        return;
    }
    else{
        char c=s[0];
        if(root->child[c]==0){
            root->child[c]=new Node(c);
            insertintoTrie(root->child[c],s.substr(1),len_of_str-1);
        }
        else{
            insertintoTrie(root->child[c],s.substr(1),len_of_str-1);
        }
    }
}

void Lvl_Ord(struct Node* root){
    queue<struct Node*> q;
    q.push(root);
    while(!q.empty()){
        struct Node *temp=q.front();
        cout<<temp->c<<" ";
        q.pop();
        for(map<char,struct Node*>::iterator i=temp->child.begin();i!=temp->child.end();i++){
            q.push(temp->child[i->first]);
        }
    }
}

int main(){
    string s;
    int n=3;
    struct Node *Trie=new Node(':');
    while(n){
        cin>>s;
        insertintoTrie(Trie,s,s.size());
        n--;
    }
    Lvl_Ord(Trie);
    return 0;
}
