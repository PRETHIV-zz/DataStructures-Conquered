#include<stdio.h>
#include<stdlib.h>

//Hi i am Prethiv "THE SO CALLED C PROGRAMMER"

struct Node{       /*Specifying node as a structure*/
    int data;
    struct Node *left,*right;

};

struct Node* newnode(int data)   /*A handwritten function to create a new node.The function takes one argument ,the data value of node to be created*/
{
    struct Node *nn=(struct Node*)malloc(sizeof(struct Node));  /*Creating a newnode using malloc*/
    nn->data=data;//Newnode's data equals to passed argument
    nn->left=NULL;//Nenode's left is nULL
    nn->right=NULL;//Newnode's right is null
    return nn;//return the created newnode
}

/*The insert function is used to insert  new node in the tree
    if the root is null then create a newnode for the data given and assign it the root
    else:
        if the key given is less than the root then call the function again by assigning root->left and passing root->left instead of root
      
        if the key is greater than the root then call the same function again by asigning root->right and passing root->right instead of root

*/


struct Node* insert(struct Node* root,int key)  
{
 if(root==NULL){
    return newnode(key);
 }
 else{
    if(key<=root->data)
    {
        root->left=insert(root->left,key);
    }
    else{
        root->right=insert(root->right,key);
    }
    return root;
 }
}



/*The inorder traversal of a given tree 
    As it is straight forward logic i think no need to explain this for more info about inorder traversal visit geeksforgeeks
    
    
            90
           /  \
          86   91
         / \   /  \ 
        85 88 null 93
        
        The inorder traversal of the given tree is : 85 86 88 90 91 93
        The level order traversal of the given tree is :90 86 91 85 88 93
 */

 void inorder(struct Node* root)
 {
     if(root==NULL){
        return;
     }
     else{
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
     }
 }


 int main()
 {
     int n;
     printf("\n\nEnter no of nodes u want to enter");
     scanf("%d",&n);
     struct Node *root=NULL;
     int c=0;
     while(n>0)
     {
         int key;
         scanf("%d",&key);
         if(c==0){
            c++;
            root=insert(root,key);
         }
         else{
            insert(root,key);
         }

         n--;
     }

     inorder(root);
     return 0;
 }


