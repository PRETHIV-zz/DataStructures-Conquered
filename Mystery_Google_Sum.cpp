/*
  In this problem u will be given a array of numbers your task is to find out if the can be
  maken as sorted array by reversing any subarray within it.
  Ind 0 1 2 3 4 
  Arr 1 2 5 4 3
  
  Here the answer is YES and by reversing the range 2-4 the array can acquire sorted form 
  
  I know my solution is not optimized one,,,but somewhat solution 
  Time Complexity O(n2)
  But this solution will work for array range 1-n power 4
  
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool A_EQ_SORT(vector<int> a){
    for(int i=0;i<a.size()-1;i++){
        if(a[i]>a[i+1]){
            return false;
        }
    }
    return true;
}

vector<int> getARR(vector<int> a,int l,int h){
    vector<int> Y;
    for(int i=l;i<=h;i++){
        Y.push_back(a[i]);
    }
    return Y;
}

bool Check_Possible1(vector<int> a){
    if(A_EQ_SORT(a)){
        return true;
    }
    else{
        return false;
    }
}

bool Check_Possible(vector<int> arr,int l,int n,int END){
    if(l>=n){
        return false;
    }
    if(A_EQ_SORT(arr)){
        cout<<"THE RANGE "<<l<<" "<<n<<endl;
        return true;
    }
    else{
        vector<int> temp;
        temp=getARR(arr,l,n);
        vector<int> check;
        for(int i=0;i<=END;i++){
            if(i>=l&&i<=n){
                check.push_back(temp[temp.size()-1]);
                temp.pop_back();
            }
            else{
                check.push_back(arr[i]);
            }
        }
        if(Check_Possible1(check)){
            cout<<"THE RANGE "<<l<<" "<<n<<endl;
            return true;
        }
        else{
            return Check_Possible(arr,l+1,n,END)||Check_Possible(arr,l,n-1,END);
        }
    }
}

int main()
{
    vector<int> arr;
    int n,k;
    cin>>n;
    while(n){
        cin>>k;
        arr.push_back(k);
        n--;
    }
    if(Check_Possible(arr,0,arr.size()-1,arr.size()-1)){
        cout<<"POSSIBLE";
    }
    else{
        cout<<"IMPOSSIBLE";
    }
    return 0;
}
