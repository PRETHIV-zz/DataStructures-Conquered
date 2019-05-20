#include<stdio.h>
//Back2Form
int a[30]; //size of the stack
int top=0;
void push(int d)
{
    a[top++]=d;
}

int pop()
{
    return a[--top];
}

void printstack(){
    int n=top-1;
    while(n!=-1)
    {
        printf("\n\t__________");
        printf("\n\t|   %d",a[n]);
        printf("\n\t__________\n");

        n--;
    }

}


int main()
{
int n,c=0;
while(n!=99){

    if(c==top){
        printf("\nMax elements in the stack");
    }
    printf("\n1.Push \n2.Pop \n3.Printstack");
    scanf("%d",&n);
    if(n==1){
        int k;
        scanf("%d",&k);
        c++;
        push(k);
    }
    else if(n==2){
        printf("\nThe poped element is %d",pop());
    }
    else{
        printstack();
    }
}
}
