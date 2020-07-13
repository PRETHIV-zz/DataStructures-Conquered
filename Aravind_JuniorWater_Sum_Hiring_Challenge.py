'''
Sample Output:

Enter no of days u want to survive3
Enter no of clusters4
Enter cluster 1
C1 100 300
Enter cluster 2
C2 100 300
Enter cluster 3
C3 100 200
Enter cluster 4
C4 100 400
Enter no of links4
F_C1
0 1
F_C2
0 2
C2_C3
2 3
C3_C4
3 4
[0, 1, 1, 0, 0]
[0, 0, 0, 0, 0]
[0, 0, 0, 1, 0]
[0, 0, 0, 0, 1]
[0, 0, 0, 0, 0]
0 0 0
300 100 300
300 100 300
200 100 200
400 100 400
1200
0 0 0
200 100 300
200 100 300
100 100 200
300 100 400
start of day 2
Cluster has water
Cluster has water
Cluster has water
Cluster has water
End of day 2
start of day 2
Cluster has water
Cluster has water
Cluster  3 has no water
0
1
Mid clusterno  2
i am d
Path is  3*2*D
Cluster has water
End of day 2
1700
>>> 

'''

class cluster:
    def __init__(self,p,u,c):
        self.present=p
        self.usage=u
        self.capacity=c


def getPath(clusterno,CM,t1):
    if CM[0][clusterno]==1:
        print('i am d');
        return "D"
    else:
        for i in range(1,t1+1):
            print(CM[i][clusterno])
            if CM[i][clusterno]==1:
                print('Mid clusterno ',i)
                return str(i)+"*"+getPath(i,CM,t1+1)
        print('gonna return i')
        return "I"
    
days=int(input("Enter no of days u want to survive"))
noofclusters=int(input("Enter no of clusters"))


clusterinfo=[]

totalans=0

clusterinfo.append(cluster(0,0,0))

i=0

while i<noofclusters:
    print("Enter cluster",i+1)
    clusterno,usage,capacity=map(str,input().split())
    clusterinfo.append(cluster(capacity,usage,capacity))
    totalans+=int(capacity)
    i+=1


nooflinks=int(input("Enter no of links"))

CM=[]

for j in range(noofclusters+1):
    temp=[]
    temp.append(0)
    for k in range(noofclusters):
        temp.append(0)
    CM.append(temp)

i=0

while i<nooflinks:
    link=input()
    fr,to=link.split('_')
    if fr=='F':
        fr=0
    else:
        fr=fr[1:]
        fr=int(fr)
    to=to[1:]
    to=int(to)
    print(fr,to)
    CM[fr][to]=1
    i+=1


for inp in CM:
    print(inp)

for inp in clusterinfo:
    print(inp.present,inp.usage,inp.capacity)

for inp in clusterinfo:
    inp.present=int(inp.present)-int(inp.usage)


days-=1
day=2
print(totalans)
for inp in clusterinfo:
    print(inp.present,inp.usage,inp.capacity)
while days>0:
    print('start of day',day)
    for ind in range(1,len(clusterinfo)):
        if clusterinfo[ind].present<=0:
            print("Cluster ",ind,"has no water")
            clusterno=ind
            path=str(clusterno)+"*"+getPath(clusterno,CM,noofclusters)
            print('Path is ',path)
            if len(path)==1:
                if path=="D":
                    clusterinfo[ind].present=clusterinfo[ind].capacity
                    totalans+=int(clusterinfo[ind].capacity)
                elif path=="I":
                    totalans=-1
                    break
            else:
                temp=path.split('*')
                for i1 in temp:
                    if i1=="D" or i1=="D":
                        continue
                    else:
                        
                        clusterinfo[int(i1)].present=clusterinfo[int(i1)].capacity
                        totalans+=int(clusterinfo[int(i1)].capacity)
        else:
            print('Cluster has water')
    print('End of day',day)
    for inp in clusterinfo:
        inp.present=int(inp.present)-int(inp.usage)
    days-=1

print(totalans)
