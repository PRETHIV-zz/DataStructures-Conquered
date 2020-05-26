/*
  for the problem statement check out the recursive solution for this one
*/

#include<iostream>
#include<vector>
using namespace std;

int DP[15][15];

void initialize(){
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            DP[i][j]=-1;
        }
    }
}

int solve(vector< vector<int> > v,int row,int col,int n){
    if(row==n-1&&col==n-1){
        return v[row][col];
    }
    else if(col>(n-1)){
        return solve(v,row+1,col-1,n);
    }
    else if(row>(n-1)){
        return solve(v,row-1,col+1,n);
    }
    else{
        //cout<<v[row][col]<<" "<<min(solve(v,row+1,col),solve(v,row,col+1))<<endl;
        if(DP[row][col]!=-1){
            return DP[row][col];
        }
        else{
            DP[row][col]=v[row][col]+min(solve(v,row+1,col,n),solve(v,row,col+1,n));
            return DP[row][col];
        }
        //return v[row][col]+min(solve(v,row+1,col,n),solve(v,row,col+1,n));
    }
}

int main(){
    int n,k;
    vector< vector<int> > v;
    cin>>n;
    initialize();
    for(int i=0;i<n;i++){
            vector<int> temp;
        for(int j=0;j<n;j++){
            cin>>k;
            temp.push_back(k);
        }
        v.push_back(temp);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"The minimum cost is "<<solve(v,0,0,n);
    return 0;
}
