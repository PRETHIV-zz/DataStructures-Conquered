#include<stdio.h>

struct Node{
    int data;
    struct Node *left,*right;
};

struct Node* newnode(int k){
    struct Node *nn=(struct Node*)malloc(sizeof(struct Node));
    nn->data=k;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}

struct Node* insert(struct Node* root,int key){
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


int height(struct Node* root){
    if(root==NULL){
        return 0;
    }
    else{
        int l=height(root->left);
        int r=height(root->right);
        if(l>r){
            return l+1;
        }
        else{
            return r+1;
        }
    }
}



void printgivenlevel(struct Node* root,int n){
    if(root==NULL){
        return;
    }
    if(n==1){
        printf("%d ",root->data);
    }
    else{
        printgivenlevel(root->left,n-1);
        printgivenlevel(root->right,n-1);
    }

}


int main(){
int n;
printf("\nEnter no of nodes u want to enter ");
scanf("%d",&n);
int c=0;
struct Node *root=NULL;
while(n>0){
    if(c==0){
        c++;
        scanf("%d",&c);
        root=insert(root,c);
    }
    else{
        scanf("%d",&c);
        insert(root,c);
    }
    n--;
}



/*
        eg:
                90
                /  \
               7    99
              /       \
             6        109

             height of the tree is 3


*/
printf("\nThe height of the given tree is %d",height(root));

printf("\nenter level to print");
scanf("%d",&n);
if(n<=height(root)){
printgivenlevel(root,n);
}
else{
    printf("\nLevel Exceeds Tree Height");
}
return 0;
}
