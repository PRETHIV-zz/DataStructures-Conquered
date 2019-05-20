//Queue using c by arrays
#include<stdio.h>
#include<string.h>
int a[30];
int front=0;
int last=0;

void enqueue(int d){
    a[last++]=d;
    if(last==30)
    {
        printf("\nQueue is filled");
    }
}

int length(){
    int f=front;
    int l=last;
    return l-f;
}

int dequeue()
{
     if(front>=last){
        printf("\nQueue is empty");
        return 0;
    }
    else{
    int d=a[front++];

    return d;
    }
}

void printq()
{
    int f=front;
    int l=last;
    //char aa[f-l+100];
    //strcat(aa,"ENTER = ");
    printf("\n\nQUEUE CONTENT\n\n");
    printf("ENTER  =  ");
    while(l>f)
    {
        //strcat(aa,a[--l]-48);
        //strcat(aa," = ");
        printf("%d  =  ",a[--l]);
    }
    //strcat(a,"EXIT");
    //printf("\n\n%s",aa);
    printf(" EXIT");
}



int main()
{
    int n=0;
    while(n!=99){
        printf("\n1.Enqueue \n2.Dequeue \n3.Printstack \nPress 99 to exit");
        scanf("%d",&n);
        if(n==1)
        {
            int k;
            scanf("%d",&k);
            enqueue(k);
            //printf("\n\nFront %d , Last %d",front,last);
        }
        else if(n==2){
                if(length()==0){
                    printf("\nQueue is Empty");
                }
                else{
            printf("\n\nThe dequeued element is %d",dequeue());
                }
                //printf("\n\nFront %d , Last %d",front,last);
        }
        else if(n==3){
            printq();
        }
        else{
            printf("\nThe length of the queue is %d",length());
        }
    }
    return 0;
}
