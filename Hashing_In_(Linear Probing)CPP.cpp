#include<iostream>

#Hi i am prethiv "THE SO CALLED c Programmer"

/*This is just a simple hashing .I used linear probing to avoid collision .so it is not so much efficient

But i am damm sure it is better than normal array storage and retrival


If u need more efficient implementation of hashing go with Quadratic probing or Double hashing .


So thats it ....


*/



using namespace std;

//This is the structure of our hash table .it stores values based on  key
struct hash_table{

        string key;
        string value;
};

struct hash_table t1[20];
//Global hash_table array so that it can be called anywhere

static int cnt=0;
//Count indicates total no of search operation performed while accessing key value

/*
  The initialize function is used to initialize our hash table key values
*/
void initialize(){
    for(int i=0;i<20;i++){
        t1[i].key="0";
        t1[i].value="";
    }
}
/*
  The job of newhashkey function is to find a index value for a given key.
  
  
  I used linear probing to collision avoidance .
  
  
  My algorithm Behind key Finding is explained as below
  
    1.First i am finding the length of the given key
    
    2.And i am finding the index as modulo of key length by table size
    
    3.If found indexes value is empty which indicates ,it is not used previously before, then thats the index for our new value
    
    4.Return that index 
    
    5.suppose if any collision occurs which means same index value for another key then just search for the next empty row in the table
    
    
    
   Eg:
   
   
    Consider the key value entry:
      1. Prethiv  900
      2. Ajay     901
      3. Ajit     902
      
      1.
         sizeof "Prethiv" is 7 
         7 % 20 is 7
         Initally row 7 is empty 
         Hence t1[7].key is Prethiv
         and t1[7].value is 900
         
      2.
        sizeof "Ajay" is 4
        4 % 20 is 4
        Row 4 is empty 
        hence t1[4].key is Ajay
        t1[4].value is 901
       
      3.
        sizeof "Ajit" is 4
        4 % 20 is 4
        Row 4 is already used before (collision occurs) hence lookup 5 (next address)
        row 5 is empty 
        hence t1[5].key is Ajit
        t1[5].value is 902

*/
int newhashkey(string key)
{

    int n;
    for(int i=0;i<20;i++){
        n=key.size()%20+i;
        if(t1[n].value=="" && n<20){
            return n;
            break;
        }
    }
}


/*
  Once hashtable entries are inserted we need to access the value of the key .
  
  Search hash key function will return the index of the key we given
  
  
  It search for the key using algorithm we described above except it doesn't look for Empty value but if it matces with the given key
  
  if matches then it will return the index
  
*/

int searchhashkey(string key){

    int n,hops=0;
    for(int i=0;i<20;i++)
    {
        n=key.size()%20+i;
        cnt++;
        hops++;
        if(t1[n].key==key && n<20){
                cout<<"\nItem found in "<<hops<<"hops";
            return n;
        }
    }

}

/*The display function take hash_table array as argument and print the key and value of the array

*/

void display(struct hash_table t[])
{
    cout<<"\n\nHASH_TABLE ";
    cout<<"\n\tIndex\tKey\tValue";
    for(int i=0;i<20;i++){
        cout<<"\n\t"<<i<<"\t"<<t[i].key<<"\t"<<t[i].value;
    }
}


int main()
{
    int n;
    cout<<"\nEnter the size of the hashing table(size should be less than 20)";
    cin>>n;
    string k,v;
    int ind;
    initialize();
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter key of item "<<i+1;
        cin>>k;
        cout<<"\nEnter value of item "<<i+1;
        cin>>v;
        ind=newhashkey(k);

        t1[ind].key=k;
        t1[ind].value=v;

    }

    display(t1);

    cout<<"\nEnter a  key to find its value";
    cin>>k;

    cout<<"\nThe value of key "<<k<<" is "<<t1[searchhashkey(k)].value;

    cout<<"\nTotall cost spend is "<<cnt;

    return 0;
}
