#Linklist without using class in python

#Hi this Prethiv "SO CALLED THE C PROGRAMMER"


#Dear git visitor first of all i would like to explain u all whats the main difference between others link list implementation and mine version
#Normally in c++ or c when i pass a node reference it is passed as a pointer as it is a reference so any changes done within the function 
#will be reflected in the reference variable itself
#But in python i tried similar approach end up getting wrong or unexpected answer
#As i am a newbie to python i don't know how to implement in python later i found there is no pointers in python
#hence the reference is a passed just as value
#so whatever the updates done within the function is not reflected back
#Hence i decided to compute the head value once the neccessary list action is performed within the function
#and return the head value to the main function ence the new head value is updated if any



#CODER_ROCKY

#Specifying the Object Node
class Node:
    def __init__(self,data):    #constructor for object
        self.data=data          #data attribute for the node
        self.link=None          #i used link instead of next coz i am using the name link since childhood

        
#Print the complete list


def printlist(head):
    print("*******************************************") #just for beautification purpose nothing big
    print()                                              #as said above
    while head!=None:                                    #loop to iterate through the list until it reaches end
        print(head.data,end="=>")                        #At the same time i am printing node's data value and ataching link symbol at the end
        head=head.link                                   #I am shifting the head position as next node
    print("None")                                        #Printing None at the end so that it will be look as
    print("*******************************************") # 6=>7=>8=>None

def insertbydata(ld,data,head):                         #This function takes 3 arg one is list data after u want to enter second one is new data to be inserted and the last one is head of the list
    cur=head                                            #Setting some temporary variable to head
    while cur.data!=ld:                                 #moving the pointer until its current node's data matches with the desired data (ld)
        cur=cur.link
    ne=cur.link                                         #once found its next node also referenced as ne
    nn=Node(data)                                       #Creating a new node for data
    cur.link=nn                                         #giving connectiions to the new node so that it is inserted into the list
    nn.link=ne
    return head                                         #Once inserted the head pointer value is returned

#The drawback in insertion using data insertion u can start inserting element after head only

def lengthlist(head):   #This function will return the length of the list
    c=0                 #counter variable to count the no. of nodes in the list
    while head!=None:   #Loop until head becomes null
        head=head.link  #Moving the head pointer each time and increementing the counter for each iteration when the loop ends
        c+=1            #It will give the length of the List
    return c            #Return the length of the list found

def deletebypos(pos,head):  #This function deletes the node based on index position
    cur=head                #Indices        0     1       2       3       4
    if pos==0:              #Data           89   78      67      56      45
        cur=cur.link        # if pos is zero it means we have to delete the first node 
        head.link=None      #making head node's next as null and returning head nodes next as head value
        return cur
    else:
        try:
            while pos!=1:  #loop until position becomes 1
                pos-=1
                cur=cur.link
            ne=cur.link    #Find next node of positioned node
            ne.link=None   #make next node's adress as null
            ne=ne.link     #current node's address as ne nodes of address
            cur.link=ne
            return head
        except:
            print("\n\nIndex Out of Range\n\n")  #If any error occurs while deletion at specified position it clearly indicates Out of Range
            return head

def searchlist(head,data):  #search list function will return the index of the data in the list
    find=0                  #The find varible will keep track of whether the node is found or not
    c=0                     #Counter variable to count the index position
    while head!=None:       #Loop until head reaches None and increement the c value on each iteration
        if head.data==data: #If head's data matches with given data just return the c value 
            return c
        c+=1
        head=head.link
    if find==0:             #If the loop runs successfully then  the find value remains 0 
        print("\n\nELEMENT NOT FOUND\n\n")#if the find value is 0 it indicates The element not even in the list
        return 0
    

def insert(ind,data,head):      #Insert function takes three arg index position data to be inserted and the list's head 
    if ind==0 or ind=='first' or ind=="First" or ind=="FIRST": #If the index is 0 or first or bla-bla-bla 
        nn=Node(data)               #creating a new node
        nn.link=head                #make new node's next node as head 
        return nn                   #return new node's address as head node
    elif ind=="last" or ind=="Last" or ind=="LAST":  #If ind='last' new node is inserted at last
        cur=head                
        if lengthlist(head)==0: #If list is empty then new node can't be inserted
            print("List is empty so cant insert at the end at the moment please try inserting at the beginning")
            return head
        else:
            while cur.link!=None:  #loop until pointer reaches last node
                cur=cur.link
            cur.link=Node(data) #last node of next is assigned as new node
            return head
    else:   #insertion using index position
        c=1 #counter to keep track of index
        cur=head    #make cur as head
        while c<ind: #loop until index is reached
            c+=1    
            cur=cur.link
        ne=cur.link   #next node as current node's next  node
        nn=Node(data) #Creating a new node
        cur.link=nn   #Current node's next node as newnode
        nn.link=ne    #newnode of next is next node
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
        

