#include <iostream>
#include<vector>
#include <stdlib.h> 
#include <time.h>
#include<string>
using namespace std;

string printTime(){
  time_t my_time = time(NULL); 
  printf("%s", ctime(&my_time)); 
  return ctime(&my_time);
}

long long int comp=0;

void linearSearch(vector<long long int> v,long long int n){
  long long int l=v.size();
  for(long long int i=0;i<l;i++){
    //cout<<i<<endl;
    cout<<"COMPARISION"<<endl;
    comp++;
    if(v[i]==n){
      cout<<"\nItem Found at index"<<i<<endl;
      break;
    }
  }
}

void jumpSearch(vector<long long int> v,long long int n){
  long long int l=v.size(),i=0;
  for(i=0;i<l;i+=100000){
    //cout<<i<<v[i]<<endl;
    cout<<"COMPARISION"<<endl;
    comp++;
    if(i>=l){
      i-=100000;
      //cout<<"\nGTLIMIT";
      break;
    }
     else if(v[i]>n){
        //cout<<"\nBREAKING";
        i-=100000;
        break;
       }
  }
  i-=100000;
  if(i<0){
    i=0;
  }
  //cout<<"Reached here";
  while(true){
    cout<<"COMPARISION"<<endl;
    comp++;
    if(v[i]==n){
      cout<<"\nItem found by JS"<<i<<endl;
      break;
    }
    i++;
  }
}

void binarySearch(vector<long long int> v,long long int n,long long int l,long long int h){
 
  if(l>h){
    return;
  }
  long long int mid=(l+h)/2;
  if(v[mid]==n){
    cout<<"\nItem found"<<mid<<"BS";
  }
  else if(n<mid){
    cout<<"COMPARISION"<<endl;
    comp++;
    binarySearch(v,n,l,mid-1);
  }
  else{
    cout<<"COMPARISION"<<endl;
    comp++;
    binarySearch(v,n,mid+1,h);
    return;
  }
}

void ternarySearch(vector<long long int> v,long long int n,long long int l,long long int h){
  if(l>h){
    return;
  }
  long long int m1=l+(h-l)/3;
  long long int m2=h-(h-l)/3;
  if(v[m1]==n){
    cout<<"Item found at"<<m1<<endl;
    return;
  }
  if(v[m2]==n){
    cout<<"Item found at"<<m2<<endl;
    return;
  }
  if(n<v[m1]){
    cout<<"COMPARISION"<<endl;
    comp++;
    ternarySearch(v,n,l,m1-1);
  }
  else if(n>v[m2]){
    cout<<"COMPARISION"<<endl;
    comp++;
    ternarySearch(v,n,m2+1,h);
  }
  else{
    cout<<"COMPARISION"<<endl;
    comp++;
    ternarySearch(v,n,m1+1,m2-1);
  }
}

int main(){


  vector<long long int> v;
  cout<<"\nMISSIONSTARTED\n";
  long long int j=1;
  for(long long int i=1;i<10000000;i++){
   // cout<<"pushing";
    v.push_back(i);
    if(i%10000==0){
      cout<<j++<<" "<<i<<endl;
      //cout<<"I"<<endl;
    }
    //cout<<i<<endl;
  }

  cout<<"Dummy large array created successfully\n";
  
  cout<<"Total Size of the array"<<v.size();

  long long int n;
  cout<<"Enter a number to search from the array <1000000\n";

  cin>>n;
  
 // binarySearch(v,n,0,v.size()-1);
 
  string lst,lend,jst,jend,bst,bend;
  string tst,tend;
  
  long long int lC,jC,bC,tC;

  cout<<"\nLinear search started ";
  lst=printTime();
  linearSearch(v,n);
  lend=printTime();
  cout<<"\nLinear search completed";
  lC=comp;
  comp=0;
  cout<<"\nJump search started ";
  jst=printTime();
  jumpSearch(v,n);
  jend=printTime();
  cout<<"\nJump search completed";
  jC=comp;
  comp=0;
  cout<<"\nBinary Search Started";
  bst=printTime();
  binarySearch(v,n,0,v.size()-1);
  bend=printTime();
  cout<<"\nBinary Search completed";
  bC=comp;
  comp=0;
  cout<<"\nTernary Search Started";
  tst=printTime();
  ternarySearch(v,n,0,v.size()-1);
  tend=printTime();
  cout<<"\nTernary Search Completed";
  tC=comp;

  cout<<"SUMMARY"<<endl;
  cout<<"LINEAR SEARCH\n";
  cout<<"Start "<<lst<<endl;
  cout<<"End "<<lend<<endl;
  cout<<"Comparision"<<lC<<endl;
  
  cout<<"Jump Search\n";
  cout<<"Start "<<jst<<endl;
  cout<<"End "<<jend<<endl;
  cout<<"Comparision"<<jC<<endl;
  
  cout<<"Binary Search\n";
  cout<<"Start "<<bst<<endl;
  cout<<"End "<<bend<<endl;
  cout<<"Comparision"<<bC<<endl;
  
  cout<<"Ternary Search\n";
  cout<<"Start "<<tst<<endl;
  cout<<"End "<<tend<<endl;
  cout<<"Comparision"<<tC<<endl;
  

  return 0;
}