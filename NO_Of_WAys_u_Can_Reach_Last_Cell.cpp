/*
 In this problem you will be given weighted matrix that denotes the path cost ,at any given moment you can either move down or move right
 Given a cost C ,Your task is to find out in how many ways the end of the cell can be reached with given cost
 
 3 22
 4 7 8
 6 7 3
 3 8 1
 
 The possible ways with their costs are:
    
    4+7+8+3+1=23
    4+7+7+8+1=27
    4+7+7+3+1=22
    4+6+3+8+1=22
    4+6+7+3+1=21
    4+6+7+8+1=26
 
*/
#include<iostream>
using namespace std;

int DP[102][102];

void initialize(){
    for(int i=0;i<102;i++){
        for(int j=0;j<102;j++){
            DP[i][j]=-1;
        }
    }
}

int no_of_ways(int row,int col,int n){
    if(row==n-1&&col==n-1){
        return 1;
    }
    else if(row>=n){
            return 0;
        //return no_of_ways(row-1,col+1,n);
    }
    else if(col>=n){
            return 0;
        //return no_of_ways(row+1,col-1,n);
    }
    else{
            if(DP[row][col]==-1){
                DP[row][col]=no_of_ways(row+1,col,n)+no_of_ways(row,col+1,n);
                return DP[row][col];
            }
            else{
                return DP[row][col];
            }
    }
}

int main(){
    int n;
    cin>>n;
    initialize();
    cout<<"No of ways can be reached is "<<no_of_ways(0,0,n);
    return 0;
}
