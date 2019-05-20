#include<stdio.h>

struct Node{
    int data;
    struct Node *left,*right;
};


struct Node* newnode(int d)
{
   struct Node *nn=(struct Node*)malloc(sizeof(struct Node));
   nn->data=d;
   nn->left=NULL;
   nn->right=NULL;
   return nn;
}

struct Node* insert(struct Node* root,int key)
{
 if(root==NULL){
    return newnode(key);
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
     return 0;
}
