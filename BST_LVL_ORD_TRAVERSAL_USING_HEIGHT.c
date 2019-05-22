#include<stdio.h>


struct Node{
    int data;
    struct Node *left,*right;
};

struct Node* newnode(int k)
{
 struct Node *nn=(struct Node*)malloc(sizeof(struct Node));
 nn->data=k;
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

void printgivenlevel(struct Node* root,int lvl){
    if(root==NULL)
    {
        return;
    }
    if(lvl==1){
        printf("%d ",root->data);
    }
    else{
        printgivenlevel(root->left,lvl-1);
        printgivenlevel(root->right,lvl-1);
    }
}

int height(struct Node* root){
    if(root==NULL){
        return 0;
    }
    else{
        if(height(root->left)>height(root->right)){
            return height(root->left)+1;
        }
        else{
            return height(root->right)+1;
        }

    }
}



void lvlorder(struct Node* root){
    int h=height(root);
    int i=1;
    for(i=1;i<=h;i++){
        printgivenlevel(root,i);
    }
}



int main()
{
    int n,c=0;
    printf("\nEnter no of nodes to enter");
    scanf("%d",&n);
    struct Node *root=NULL;
    while(n>0)
    {
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

    lvlorder(root);
    return 0;
}
