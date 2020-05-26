#include<iostream>
#include<string>

using namespace std;

int check_palin(string hulk,int start,int endi){
    if(start==endi){
        //If there is only one letter in the string then that string is a palindrome
        return 1;
    }
    else if(endi<start){
        //If no of letters in the string is even then start position will cross ,if it crosses then it indicates
        //the string is palindrome
        return 1;
    }
    else if(hulk[start]==hulk[endi]){
        return check_palin(hulk,start+1,endi-1);
    }
    else{
        return 0;
    }
}

int main()
{
    string s;
    cin>>s;
    if(check_palin(s,0,s.size()-1)){
        cout<<"PALINDROME";
    }
    else{
        cout<<"NOT PALINDROME";
    }
    return 0;
}
