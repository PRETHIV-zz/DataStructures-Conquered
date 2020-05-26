/*
  Find Maximum sum such that no two elements are adjacent in O(N) time.
  
  Input:  arr[]={5,5,10,100,10,5}
  
  Output: 110
  
*/

#include<iostream>
#include<vector>

using namespace std;

int solve(int l,int h,vector<int> v){
    if(l>=v.size()||h<0){return 0;}
    if(l>h){ return 0; }
    else if(l+1==h){ return 0; }
    else if(l==h){ return v[l]; }
    else{
        return max(max(v[l]+solve(l+2,h,v),v[h]+solve(l,h-2,v)),max(v[l+1]+solve(l+3,h,v),v[h-1]+solve(l,h-3,v)));
    }
}

int main()
{
    vector<int> v;
    int n,t;
    cin>>n;
    while(n)
    {
        cin>>t;
        v.push_back(t);
        n--;
    }
    cout<<"The maximum sum without adjacent element is "<<solve(0,v.size()-1,v);
    return 0;
}
