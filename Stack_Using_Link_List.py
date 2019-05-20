class Node:
    def __init__(self,data):
        self.data=data
        self.link=None

def push(head,data):
    nn=Node(data)
    nn.link=head
    return nn


def pop(head):
    cur=head.link
    head.link=None
    return cur,head.data

def printstack(head):
    print("****************************************************************\n\n")
    c=0
    while head!=None:
        if c==0:
            c+=1
            print("                                        --------------")
            print(" ____  __   ____                        |             ")
            print("  |   |  |  |  |                        |   ",head.data)
            print("  |   |  |  |__|                        |             ")
            print("  |   |__|  |                           --------------")
            head=head.link
        elif head.link==None:
            print("  ___  ___  ____  ___    ___   _    _   --------------")
            print(" |  | |   |  |     |    |   | | \  / |  |             ")
            print(" |__| |   |  |     |    |   | |  \/  |  |   ",head.data)
            print(" |  | |   |  |     |    |   | |      |  |             ")
            print(" |__| |___|  |     |    |___| |      |  --------------")
            head=head.link
            
        else:
            print("                                        --------------")
            print("                                        |             ")
            print("                                        |   ",head.data)
            print("                                        |             ")
            print("                                        --------------")
            head=head.link
    print("\n\n****************************************************************")

n=0
head=None
while n!=99:
    n=int(input("1 for push \n2 for pop \n3 for printstack"))
    if n==1:
        ip=input("\nenter data to be pushhed")
        head=push(head,ip)
    elif n==2:
        try:
            head,data=pop(head)
            print("The poped element is ",data)
        except:
            print("Stack is Empty")
    elif n==3:
        printstack(head)
