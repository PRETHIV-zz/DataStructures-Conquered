#include<iostream>
using namespace std;


/*
  our structure for our node

*/
struct Node{
    int data;
    struct Node *left,*right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }

};


/*Refer BST_Height*/
int height(struct Node* root){
    if(root==NULL){
        return 0;
    }

    else{
        int l,r;

        l=height(root->left);
        r=height(root->right);
        if(l>r){
            return l+1;
        }
        else{
            return r+1;
        }

    }

}

/*Refer BST_LVL_ORDER_BY_HEIGHT*/
void printgivenlevel(struct Node* root,int lvl){
    if(root==NULL){
        return;
    }
    if(lvl==1){
        cout<<root->data<<" ";
    }
    else{
        printgivenlevel(root->left,lvl-1);
        printgivenlevel(root->right,lvl-1);
    }
}



void lvlorder(struct Node* root){
    int h=height(root);
    cout<<endl;
    for(int i=1;i<=h;i++)
{
    printgivenlevel(root,i);

}

}



struct Node* insert(struct Node* root,int key){

    if(root==NULL){
        return new Node(key);
    }

    else{
        if(key<=root->data){
            root->left=insert(root->left,key);
        }
        else{
            root->right=insert(root->right,key);
        }

    }
    return root;

}


/*
  in this scenario we have two base cases
  
  if root is null then return null as there is no node in the tree
  
  if root's data is equals to our desired key
  
    then return reference of the root
  
  else:
    check if the key is lesser than or equal to our root's data
      if so then repeat the above two steps for the lfet sub tree since it must present there as it is lesser than the root
      
    else:
      repeat step 1 and step2 for right sub tree as it is greater than the root.
  
  
*/
struct Node* returnnode(struct Node* root,int key){
    if(root==NULL){
        return NULL;
    }

    if(root->data==key){
        return root;
    }

    else{
        if(key<=root->data){
            return returnnode(root->left,key);
        }
        else{
            return returnnode(root->right,key);
        }
    }
}



int main(){


int n;
cout<<"\nEnter no of nodes u want to enter";
cin>>n;

struct Node *root=NULL;
int c=0;
while(n>0){

    if(c==0){
        cin>>c;
        root=insert(root,c);
        c++;
    }
    else{
        cin>>c;
        insert(root,c);

    }

    n--;
}

lvlorder(root);

    cout<<"\nEnter the key so that we will return u the corresonding node";
    cin>>c;
    struct Node *finded=returnnode(root,c);
    if(finded==NULL){
        cout<<"\nThe node is null or no node with given key value";
    }
    else{
        cout<<"\nThe finded->data is "<<finded->data;
    }
    return 0;
}
