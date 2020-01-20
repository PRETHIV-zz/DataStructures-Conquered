/*
Input:
Enter the number of sentences to be added into our Trie:3
dog_is_a_animal
dolphins_are_cute
shalini

Type something and press Enter to reviel suggestion:d
dog_is_a_animal
dolphins_are_cute

Type something and press Enter to reveil suggestion:dol
dolphins_are_cute

Type something and press Enter to reveil suggestion:s
shalini



****This is how google suggests you when u type something***Also this trie type is used to avoid storing values again

for the above example our trie might look like this

                  :
                 / \
                d   s
               /     \ 
              o       h
             /\        \
            g  l        a
           /    \        \
          _      p        l
         /        \         \
        i          h          i
       /            \           \
      s              i            n
     /                \            \
    _                  n            i
    \                   \
     a                   s
     /                    \
    _                      a
    \                       \
    a                        r
    \                         \
     n                         e
     /                          \
     i                           c
     /                            \
     m                             u 
     /                              \
     a                               t 
     /                                \
    l                                  e         
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Node{
    char ch;
    struct Node *child[300];
    Node(char d){
        ch=d;
        for(int i=0;i<300;i++){
            child[i]=NULL;
        }
    }
};

void insertchar(struct Node* root,string s){
    if(s.size()==0){
        return;
    }
    else{
        char ch=s[0];
        if(root->child[ch]==NULL){
            root->child[ch]=new Node(ch);
            insertchar(root->child[ch],s.substr(1));
        }
        else{
            insertchar(root->child[ch],s.substr(1));
        }
    }
}

struct Node* findnode(struct Node* root,string s){
    if(s.size()==0){
        return root;
    }
    else{
        char ch=s[0];
        if(root->child[ch]!=NULL){
            return findnode(root->child[ch],s.substr(1));
        }
        else{
            cout<<"\n\nNot enough suggestions in the trie\n\n";
        }
    }
}

vector<string> sugg;
static char ans[100];
void givemeanode(struct Node* root,int pos){
    //static char ans[100];
    static int cnt=0;
    cnt++;
    int k=0;
    bool en=true;
    while(k<300){
        if(root->child[k]!=NULL){
            en=false;
            ans[pos]=root->child[k]->ch;
            givemeanode(root->child[k],pos+1);
        }
        k++;
    }
    if(en){
        for(int i=pos;i<cnt;i++){
            ans[i]=32;
        }
        sugg.push_back(ans);
        return;
    }
}


void clearcontent(){
    for(int i=0;i<100;i++){
        ans[i]=32;
    }
}

int main()
{
    int n;
    cout<<"Enter the no of sentences to be added into our trie: ";
    cin>>n;
    string s,pretext="";
    struct Node *root=new Node(':');
    while(n>=1){
        cin>>s;
        insertchar(root,s);
        n--;
    }
    n=3;
    while(n>=1)
    {
        cout<<"Type something and then press enter to reveil suggestions ";
        cin>>s;
        struct Node *temp=findnode(root,s);
       // cout<<temp->ch;
        //cout<<"1";
        givemeanode(temp,0);
        //cout<<"2";
        cout<<endl;
        for(int i=0;i<sugg.size();i++){
            cout<<s<<sugg[i]<<endl;
        }
        //cout<<"3";
        sugg.clear();
        clearcontent();
        n--;
    }



    return 0;
}
