'''

Rather than Going with complex DFS or Auxilary visit array my simple recursive logic solution for the famous amazon island sum

1 1 0 0 0
0 1 0 0 1
1 0 0 1 1
0 0 0 0 0
1 0 1 0 1

1 1 0 0 0 
0 1 0 0 1 
1 0 0 1 1 
0 0 0 0 0 
1 0 1 0 1 

Incrementing count  0 0
Called for  0 0
Making  0 0 -1
Called for  -1 -1
Corner reached
Called for  -1 0
Corner reached
Called for  -1 1
Corner reached
Called for  0 -1
Corner reached
Called for  0 1
Making  0 1 -1
Called for  -1 0
Corner reached
Called for  -1 1
Corner reached
Called for  -1 2
Corner reached
Called for  0 0
Zero or minus one
Called for  0 2
Zero or minus one
Called for  1 0
Zero or minus one
Called for  1 1
Making  1 1 -1
Called for  0 0
Zero or minus one
Called for  0 1
Zero or minus one
Called for  0 2
Zero or minus one
Called for  1 0
Zero or minus one
Called for  1 2
Zero or minus one
Called for  2 0
Making  2 0 -1
Called for  1 -1
Corner reached
Called for  1 0
Zero or minus one
Called for  1 1
Zero or minus one
Called for  2 -1
Corner reached
Called for  2 1
Zero or minus one
Called for  3 -1
Corner reached
Called for  3 0
Zero or minus one
Called for  3 1
Zero or minus one
Called for  2 1
Zero or minus one
Called for  2 2
Zero or minus one
Called for  1 2
Zero or minus one
Called for  1 -1
Corner reached
Called for  1 0
Zero or minus one
Called for  1 1
Zero or minus one
Incrementing count  1 4
Called for  1 4
Making  1 4 -1
Called for  0 3
Zero or minus one
Called for  0 4
Zero or minus one
Called for  0 5
Corner reached
Called for  1 3
Zero or minus one
Called for  1 5
Corner reached
Called for  2 3
Making  2 3 -1
Called for  1 2
Zero or minus one
Called for  1 3
Zero or minus one
Called for  1 4
Zero or minus one
Called for  2 2
Zero or minus one
Called for  2 4
Making  2 4 -1
Called for  1 3
Zero or minus one
Called for  1 4
Zero or minus one
Called for  1 5
Corner reached
Called for  2 3
Zero or minus one
Called for  2 5
Corner reached
Called for  3 3
Zero or minus one
Called for  3 4
Zero or minus one
Called for  3 5
Corner reached
Called for  3 2
Zero or minus one
Called for  3 3
Zero or minus one
Called for  3 4
Zero or minus one
Called for  2 4
Zero or minus one
Called for  2 5
Corner reached
Incrementing count  4 0
Called for  4 0
Making  4 0 -1
Called for  3 -1
Corner reached
Called for  3 0
Zero or minus one
Called for  3 1
Zero or minus one
Called for  4 -1
Corner reached
Called for  4 1
Zero or minus one
Called for  5 -1
Corner reached
Called for  5 0
Corner reached
Called for  5 1
Corner reached
Incrementing count  4 2
Called for  4 2
Making  4 2 -1
Called for  3 1
Zero or minus one
Called for  3 2
Zero or minus one
Called for  3 3
Zero or minus one
Called for  4 1
Zero or minus one
Called for  4 3
Zero or minus one
Called for  5 1
Corner reached
Called for  5 2
Corner reached
Called for  5 3
Corner reached
Incrementing count  4 4
Called for  4 4
Making  4 4 -1
Called for  3 3
Zero or minus one
Called for  3 4
Zero or minus one
Called for  3 5
Corner reached
Called for  4 3
Zero or minus one
Called for  4 5
Corner reached
Called for  5 3
Corner reached
Called for  5 4
Corner reached
Called for  5 5
Corner reached
Final Island

-1 -1 0 0 0 
0 -1 0 0 -1 
-1 0 0 -1 -1 
0 0 0 0 0 
-1 0 -1 0 -1 

The no of islands present is  5
'''

data=[]
cnt=0

#MyOwn Solution based on recursion
#Time Comp O(ROW*COL)

def printIsland():
    global data
    print()
    for i in range(5):
        for j in range(5):
            print(data[i][j],end=" ")
        print()
    print()

def makeadjMinus(i,j):
    print("Called for ",i,j)
    global data
    if i<0 or j>4 or i>4 or j<0:
        print("Corner reached")
        return
    if data[i][j]==0 or data[i][j]==-1:
        print("Zero or minus one")
        return
    else:
        print("Making ",i,j,"-1")
        data[i][j]=-1
        makeadjMinus(i-1,j-1)
        makeadjMinus(i-1,j)
        makeadjMinus(i-1,j+1)
        makeadjMinus(i,j-1)
        makeadjMinus(i,j+1)
        makeadjMinus(i+1,j-1)
        makeadjMinus(i+1,j)
        makeadjMinus(i+1,j+1)

for i in range(5):
    row=list(map(int,input().split()))
    data.append(row)
printIsland()
for i in range(5):
    for j in range(5):
        if data[i][j]==1:
            print("Incrementing count ",i,j)
            cnt+=1
            makeadjMinus(i,j)
print("Final Island")

printIsland()

print("The no of islands present is ",cnt)
