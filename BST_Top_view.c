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

void inord(struct Node* root)
{
	if(root==NULL)
	{
		return;}
		else{
			inord(root->left);
			printf("%d ",root->data);
			inord(root->right);
		}
}

struct Node* insert(struct Node* root,int data)
{
	if(root==NULL)
	{
		return newnode(data);
	}
	else{
		if(data<=root->data)
		{
			root->left=insert(root->left,data);
		}
		else{
			root->right=insert(root->right,data);
		}
		return root;
	}
}
int a[20];
int i=0;
void root_till_left(struct Node* root)
{
	struct Node *temp=root;
	while(temp!=NULL)
	{
	//	printf("%d ",temp->data);
	   a[i]=temp->data;
	   i++;
		temp=temp->left;
	}
   i--;
   while(i>=0)
   {
   	printf("%d ",a[i]);
   	i--;
   }
	
}


void root_till_right(struct Node* root)
{
	printf(" ");
	struct Node *temp=root->right;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->right;
	}
	
}
		
		


int main()
{
	struct Node *root=NULL;
	int n;
	scanf("%d",&n);
	int i=1,k;
	while(i<=n)
	{
		if(i==1)
		{
			scanf("%d",&k);
			root=insert(root,k);
		}
		else{
			scanf("%d",&k);
			insert(root,k);
		}
		i++;
	}
	printf("\nINORDER ");
	inord(root);
	printf("\n");
	printf("\nTop view");
	root_till_left(root);
    root_till_right(root);

	
	return 0;
}
			
