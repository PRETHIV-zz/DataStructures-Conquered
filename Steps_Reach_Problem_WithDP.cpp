/*
  The same stepd reach problem but this time it is powered with DP....FEEL THE POWER OF DP.
  Just run the Recursive solution of this problem by giving inputs: 40 10
  It will take atleast one minute for computation sometimes it might crash.
  But give the same input to this one.It will compute instatnly
  
  By the way the Steps with staircase 40 with series of stpes 1-10 can be reached in 295819520 ways...:-) Enjoy I hope u like this one.
*/

#include<iostream>
#include<vector>


using namespace std;

int DP[50][30];

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
            if(DP[steps][v[i]]==-1){
                 DP[steps][v[i]]=no_of_ways(steps-v[i],v);
                 n+=DP[steps][v[i]];
            }
            else{
                n+=DP[steps][v[i]];
            }
        }
        return n;
    }
}

void initialize(){
    for(int i=0;i<50;i++){
        for(int j=0;j<30;j++){
            DP[i][j]=-1;
        }
    }
}

int main(){
    int n,c;
    cin>>n>>c;
    vector<int> v;
    initialize();
    while(c){
        v.push_back(c);
        c--;
    }
    cout<<"No of ways top of the steps can be reached is "<<no_of_ways(n,v);
    return 0;
}
