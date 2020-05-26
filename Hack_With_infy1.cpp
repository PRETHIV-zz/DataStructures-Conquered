/*
    Problem Statement:
        You are given a string of length N.In the string some positions may be blank,marked by '?' and others contain lowercase
        English Letters.You can place any lowercase English letter replacing '?' subject to the following conditions:

            1.No two adjacent letters in the string are the same.
            2.The first and last letters of the string must be the same.
        You are required to find the total number of ways such that the string contains only lowercase English letters and
        follows the stated conditions.
        Input format:
            =>The first line contains the number of tests T,next T strings follows.
            =>Each string contains lowercase English letters and/or '?'.
        Output format:
        For each test case ,print the total number of ways mod 1000000007.
        The answer to each test case must come in a new line.

        Constraints:
            1<=T<=100
            2<=N<=1000
        Sample Input:
        4
        abcd
        abc?
        a?za
        abca

        Output:
        0
        1
        24
        1
*/

#include<iostream>
#include<string>

using namespace std;

int solveIt(string s,string asmp,int i,int l){
    if(i==0){
        if(s[i]=='?'){
            int n=0;
            for(char loop='a';loop<='z';loop++){
                if(s[i+1]!=loop){
                    n+=solveIt(s,asmp+loop,i+1,l);
                }
            }
            return n;
        }
        else{
            if(s[0]==s[1]&&s[0]!='?'){
                return 0;
            }
            return solveIt(s,asmp+s[i],i+1,l);
        }
    }
    else if(i==l){
        if(s[i]=='?'){
            int n=0;
            for(char loop='a';loop<='z';loop++){
                if(asmp[i-1]!=loop&&loop==asmp[0]){
                    n++;
                    string dum=asmp;
                    dum+=loop;
                    cout<<dum<<endl;
                }
            }
            return n;
        }
        else{
            string dum=asmp;
            dum+=s[i];
            cout<<dum<<endl;
            if(s[0]!=s[i]||s[i-1]==s[l]&&s[l]!='?'){
                return 0;
            }
            else{
            return 1;
            }
        }
    }
    else{
        if(s[i]=='?'){
            int n=0;
            for(char loop='a';loop<='z';loop++){
                if(asmp[i-1]!=loop&&s[i+1]!=loop){
                    n+=solveIt(s,asmp+loop,i+1,l);
                }
            }
            return n;
        }
        else{
            if(s[i-1]==s[i]||s[i+1]==s[i]&&s[i]!='?'){
                return 0;
            }
            return solveIt(s,asmp+s[i],i+1,l);
        }
    }
}

int main()
{
    string s;
    cin>>s;

    cout<<"The answer is "<<solveIt(s,"",0,s.size()-1);
    return 0;
}
