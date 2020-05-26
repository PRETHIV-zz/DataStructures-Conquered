/*
  N=9
    *
   ***
  *****
 *******
*********
*********
 *******
  *****
   ***
    *
 
 N=4
 **
****
****
 **
 
*/
#include<iostream>

using namespace std;

void top_half(int no,int spc){
    if(no<1){
        return;
    }
    else{
        top_half(no-2,spc+1);
        for(int i=0;i<spc;i++){
            cout<<" ";
        }
        for(int i=0;i<no;i++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void bottom_half(int no,int spc){
    if(no<1){
        return;
    }
    else{
        for(int i=0;i<spc;i++){
            cout<<" ";
        }
        for(int i=0;i<no;i++){
            cout<<"*";
        }
        cout<<endl;
        bottom_half(no-2,spc+1);
    }
}

void diamond(int no){
        top_half(no,0);
        bottom_half(no,0);
}

int main()
{
    int n;

    cin>>n;

    diamond(n);

    return 0;
}
