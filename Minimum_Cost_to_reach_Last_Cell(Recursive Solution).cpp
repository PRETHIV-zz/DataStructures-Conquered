/*
  You are given a cost matrix of size N*N
  your task is to find the minimum traversal cost to reach the last Cell
  At any cell in that matrix you can either move down or move right
  
  Example:
     2
     4 7
     6 3
     
     The number of ways you can reach Last cell is
     
     4+7+3=14
     4+6+3=13
     
     Hence the answer is 13
     
     5
     4 7 8 6 4
     6 7 3 9 2
     3 8 1 2 4
     7 1 7 3 7
     2 9 8 9 3
     
     The answer for this is 36
     and that is 4+6+7+3+1+2+3+7+3
*/

#include<iostream>
#include<vector>
using namespace std;

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
            return v[row][col]+min(solve(v,row+1,col,n),solve(v,row,col+1,n));
    }
}


int main(){
    int n,k;
    vector< vector<int> > v;
    cin>>n;

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
