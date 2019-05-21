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

void preorder(struct Node* root){
    if(root==NULL){
        return;
    }
    else{
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
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

            preorder:90 7 6 99 109
 */

preorder(root);

return 0;
}
