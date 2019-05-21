#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *link;
    Node(int fd)
    {
    data=fd;
    link=NULL;
    }
};

struct Node* enqueue(int d,struct Node* head)
{
    struct Node *nn=new Node(d);
    nn->link=head;
    return nn;
}

int length(struct Node* head)
{
    int c=0;
    while(head!=NULL){
        c++;
        head=head->link;
    }
    return c;
}


int dequeue(struct Node* head){
    struct Node *prev=head;
    struct Node *temp=head;
    try{
    temp=temp->link;
    }
    catch(exception e1){
        cout<<"\nEmpty Queue";
    }
    try{
        if(temp==NULL)
        {
            int n=prev->data;
            head=NULL;
            return n;
        }
        else{
        while(temp!=NULL)
        {
            if(temp->link==NULL)
            {
                break;
            }
            temp=temp->link;
            prev=prev->link;
        }
        prev->link=NULL;
        return temp->data;
        }
    }
    catch(exception e)
    {
        cout<<"No element in the queue";
    }

}


void printq(struct Node *head)
{
        if(length(head)==0){
            cout<<"\nThe Queue is Empty";
            return;
        }
        struct Node *temp=head;
        int c=0;
        int k=length(head)-2;
        while(temp!=NULL)
        {
            if(c==0)
            {
                cout<<"\nLAST\t\t";


                temp=temp->link;
                c++;
            }
            else if(temp->link==NULL)
            {
                cout<<"FRONT";
                temp=temp->link;
            }
            else{
                cout<<k<<"\t\t";
                k--;
                temp=temp->link;
            }


        }
        cout<<endl;

        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"\t\t";
            temp=temp->link;
        }
}


int main()
{
    int n=0;
    struct Node *head=NULL;
    while(n!=99)
    {
        cout<<"\n1.Enqueue\n2.Dequeue\n3.PrintQueue";
        cin>>n;
        if(n==1)
        {
            int k;
            cin>>k;
            head=enqueue(k,head);
//cout<<head;
        }
        else if(n==2){
                if(length(head)==1){
                    cout<<"\n\nThe dequed element is "<<head->data;
                    head=NULL;
                }
                else if(length(head)==0){
                    cout<<"\n\nThe queue is empty";
                }
                else{
            cout<<"\n\nThe dequeued element is "<<dequeue(head);
                }
        }
        else{
            printq(head);
        }
    }



    return 0;
}


