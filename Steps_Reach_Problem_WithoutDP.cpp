/*
  These questions been asked most of the times in interview like Google,Microsoft,Amazon,Paypal,Facebook etc...
  In these u will be given no of staircase present in steps and a series of no of steps u can take at any given steps will be given 
  You have to find in how many times in which the top of the steps can be reached using given steps
  
  Input:
        2 2
        no of steps is 2
        series of steps : 1 2
        here you can reach top step in two ways 1+1 or 2
        
        
 consider this one: 
        3 3
        no of steps is 3
        series of steps :1 2 3
        here you can reach top step in 4 ways 
        1+1+1
        1+2
        2+1
        3
*/
#include<iostream>
#include<vector>

using namespace std;

int no_of_ways(int steps,vector<int> v){
    if(steps<0){
        return 0;
    }
    else if(steps==0){
        return 1;
    }
    else{
        int n=0;
        for(int i=0;i<v.size();i++){
            n+=no_of_ways(steps-v[i],v);
        }
        return n;
    }
}

int main(){
    int n,c;
    cin>>n>>c;
    vector<int> v;
    while(c){
        v.push_back(c);
        c--;
    }
    cout<<"No of ways can be reached is "<<no_of_ways(n,v);
    return 0;
}
