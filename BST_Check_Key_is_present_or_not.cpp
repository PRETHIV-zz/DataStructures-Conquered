#include<iostream>
#include<queue>
using namespace std;

//Structure of our Node


//Default constructor for our Node 
struct Node{
    int data;
    struct Node *left,*right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};


/*Insert function will insert a new node into our tree it is many times described in our previous problems check out bst_traversal to find about the functionn implementationn in details*/
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

/*Refer BST_LVL_Order traversal to find the full implementation discussion of the function*/

void lvlorder(struct Node* root){
    queue<struct Node*> q;
    q.push(root);
    struct Node *temp;
    cout<<endl;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }

    }


}


/*THe key check function will take two arguments 
1.Root of the tree 2. Key we r going to check 

There are only two base cases for our scenario

if our root node is a null and we r checking if our key is present or not

 In this situation it is False absolutely as we all know
 
 another situation is if our root node itself contains the desired key
 
 In this situation it is true because we know that the root contains our desired search key
 
 
 Another case is if our root is not  null and it doesn't contain our key as well
 
  In this situation we have to check both left sub tree as well as right sub tree
  
  And return true if any on esubtree contains our desired key
  
  so we r writing a code "return keycheck(root->left,key)||keycheck(root->right)"


*/

bool keycheck(struct Node* root,int k){
    if(root==NULL){
        return false;
    }

    if(root->data==k){
        return true;
    }

    else{
        return keycheck(root->left,k)||keycheck(root->right,k);
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

cout<<"\nEnter node u want to check whether it is present in this tree or not";
cin>>c;

keycheck(root,c)?cout<<"\nNode is present ":cout<<"\nNode not present in this tree";


return 0;
}
