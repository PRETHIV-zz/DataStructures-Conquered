#include<iostream>
#include<vector>

using namespace std;

int solve(int cost,int r,int c,int expected,int n,vector< vector<int> > v){
    if(r==n-1&&c==n-1){
        cost+=v[r][c];
        if(cost==expected){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(cost>expected){
        return 0;
    }
    else if(r>=n){
        return 0;
    }
    else if(c>=n){
        return 0;
    }
    else{
        return solve(cost+v[r][c],r+1,c,expected,n,v)+solve(cost+v[r][c],r,c+1,expected,n,v);
    }
}

int main(){
    int n,k,cost;
    cin>>n>>cost;
    vector< vector<int> > v;
    for(int i=0;i<n;i++)
    {
        vector<int> temp;
        for(int j=0;j<n;j++){
            cin>>k;
            temp.push_back(k);
        }
        v.push_back(temp);
    }

    cout<<"The number of ways with given cost "<<cost<<" Can be reached in"<<solve(0,0,0,cost,n,v);
    return 0;
}
