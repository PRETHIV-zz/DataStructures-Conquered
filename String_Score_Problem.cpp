/*
  Beleive me this question been asked in interviews like google,Microsoft,Facebook.
  See my own solution and thank me Later  ..>Enjoy:-)
  
  This is just a modified version of Balanced Parenthesis problem.
  
  You will be given a string that is balanced parenthesis expression.
  
  your task is to find the score of that expression.
  
  ()  = has a score 1
  
  (A) = has a score 2*A where A is a balanced parenthesis A can be (),(()),(()()) any balanced parenthesis expression
  
  (AB)= has a score A+B where A,B is a balanced parenthesis.
  
  Input :
  
    ()
    (())
    (()())
    (()(()))
    
  Output:
    1
    2
    4
    6
  
  Explanation:
     () straight away u all know it is one
     
     (())  consider (A) i use A to denote that balanced expression() score of A is 1 therefore score of (A)=2*1 =2
     
     (()()) consider this as (AB) A=1 B=1 A+B=2  (2) =2*2(inner value)=4
     
     (()(())) it is complex i will do in step by step
     
     (1 (1) )
     
     (1 2)
     
     (3)
     
     6

*/

#include<iostream>
#include<string>
#include<stack>


using namespace std;

int ending[100];

struct Node{
    int pos;
    char c;
    Node(int p,char ch){
        pos=p;
        c=ch;
    }
};

int solve(int l,int h){
    if(l+1==h){
        return 1;
    }
    else{
        int m=ending[l];
        if(m==h){
            return 2*solve(l+1,h-1);
        }
        else{
            return solve(l,m)+solve(m+1,h);
        }
    }
}

int main(){
    string s;
    cin>>s;
    stack<struct Node> stk;
    //int ending[s.size()];
    for(int i=0;i<s.size();i++){
        if(s[i]==')'){
            struct Node temp=stk.top();
            ending[temp.pos]=i;
            stk.pop();
        }
        else{
            stk.push(Node(i,s[i]));
        }
    }
   
    cout<<"The Answer is "<<solve(0,s.size()-1);
    return 0;
}
