#include<stdio.h>


struct Node{
    int data;
    struct Node *left,*right;
};


struct Node* newnode(int data)
{
    struct Node *nn=(struct Node*)malloc(sizeof(struct Node));
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}

struct Node* insert(struct Node* root,int key){
    if(root==NULL){
        return newnode(key);
    }
    else{
        if(root->data>=key){
            root->left=insert(root->left,key);
        }
        else{
            root->right=insert(root->right,key);
        }

    }
    return root;
}

void postorder(struct Node* root){
    if(root==NULL){
        return;
    }
    else{
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}


/*
  sizeof the tree function takes only one argument that is the root of the tree
  
  if root is null then it indicates the tree is empty therefore it returns zero
  
  else:
      its size that is (1) + sizeof left side subtree +sizeof right side subtree
  
  
*/


int sizeoftree(struct Node* root){
    if(root==NULL){
        return 0;
    }
    else{
        return sizeoftree(root->left)+sizeoftree(root->right)+1;
    }
}


int main(){

int n;
printf("\nEnter no. of nodes to be entered");
scanf("%d",&n);
int c=0;
struct Node *root=NULL;
while(n>0){
    if(c==0){
            scanf("%d",&c);
        root=insert(root,c);
        c++;
    }
    else{
        scanf("%d",&c);
        insert(root,c);
    }




    n--;
}


/*
            90
            /  \
            7   99
            /\    \
            6 null 109

            preorder:6 7 109 99 90
            size of the tree is no.of nodes in the tree :5
 */

postorder(root);

printf("\nThe size of the tree is  %d",sizeoftree(root));

return 0;
}
