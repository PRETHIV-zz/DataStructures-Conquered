#Linklist without using class in python
class Node:
    def __init__(self,data):
        self.data=data
        self.link=None

def printlist(head):
    print("*******************************************")
    print()
    while head!=None:
        print(head.data,end="=>")
        head=head.link
    print("None")
    print("*******************************************")

def insertbydata(ld,data,head):
    cur=head
    while cur.data!=ld:
        cur=cur.link
    ne=cur.link
    nn=Node(data)
    cur.link=nn
    nn.link=ne
    return head

def lengthlist(head):
    c=0
    while head!=None:
        head=head.link
        c+=1
    return c

def deletebypos(pos,head):
    cur=head
    if pos==0:
        cur=cur.link
        head.link=None
        return cur
    else:
        try:
            while pos!=1:
                pos-=1
                cur=cur.link
            ne=cur.link
            ne.link=None
            ne=ne.link
            cur.link=ne
            return head
        except:
            print("\n\nIndex Out of Range\n\n")
            return head

def searchlist(head,data):
    find=0
    c=0
    while head!=None:
        if head.data==data:
            return c
        c+=1
        head=head.link
    if find==0:
        print("\n\nELEMENT NOT FOUND\n\n")
        return 0
    

def insert(ind,data,head):
    if ind==0 or ind=='first' or ind=="First" or ind=="FIRST":
        nn=Node(data)
        nn.link=head
        return nn
    elif ind=="last" or ind=="Last" or ind=="LAST":
        cur=head
        if lengthlist(head)==0:
            print("List is empty so cant insert at the end at the moment please try inserting at the beginning")
            return head
        else:
            while cur.link!=None:
                cur=cur.link
            cur.link=Node(data)
            return head
    else:
        c=1
        cur=head
        while c<ind:
            c+=1
            cur=cur.link
        ne=cur.link
        nn=Node(data)
        cur.link=nn
        nn.link=ne
        return head

n=1
head=None
while n!=99:
    n=int(input("1.Insert\n2.Delete\n3.Search\n4.Length\n5.Printlist\n99.exit"))
    if n==99:
        break
    elif n==1:
        print("\n\nFunction Specification \n\n insert(index,data,head) \n\n first or First or 0 in index to insert element at first \n Last or last to insert at the last")
        ch=input("\n\n1.Insert by Index \n\n2.Insert by Data")
        if ch=='1':
            ind=input("\n\nEnter the index position   ")
            data=input("\n\nEnter the data to be inserted   ")
            try:
                ind=int(ind)
                head=insert(ind,data,head)
            except:
                head=insert(ind,data,head)
        elif ch=='2':
            ld=input("\n\nEnter the list data after u want to insert")
            data=input("\n\nEnter the new data to be inserted in the list")
            head=insertbydata(ld,data,head)
        else:
            print("\n\nInvalid Option\n\n")
    elif n==5:
        printlist(head)
    elif n==4:
        print("\n\nLength of the list =",lengthlist(head),end="\n\n")
    elif n==3:
        s=input("\n\nEnter the element to be searched   ")
        print("\n\nThe element is found at position ",searchlist(head,s),end="\n\n")
    elif n==2:
        ch=int(input("\n\n1.Delete by Index\n\n2.Delete by element"))
        if ch==2:
            s=input("\n\nEnter the element to be deleted   ")
            head=deletebypos(searchlist(head,s),head)
        elif ch==1:
            s=input("\n\nEnter the index to be deleted   ")
            head=deletebypos(int(s),head)
        

