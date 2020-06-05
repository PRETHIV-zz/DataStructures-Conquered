#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{

  string s;

  cout<<"Enter a string to build its sufix array ";

  cin>>s;

  vector<string> suffxarr;

  for(int i=0;i<s.size();i++){
    string temp=s.substr(i);
    //cout<<temp<<" ";
    suffxarr.push_back(temp);
  }


  sort(suffxarr.begin(),suffxarr.end());



  cout<<"After sorting suffix array ";


  for(int i=0;i<suffxarr.size();i++){
    cout<<suffxarr[i]<<endl;
  }


  return 0;
}
