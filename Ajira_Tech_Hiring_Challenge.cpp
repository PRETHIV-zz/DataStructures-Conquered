/*
 AJIRATECH CONQUERED
 This problem has been asked in AjiraTech Interview.During the month of July-20-2019.It is a very beautiful Problem.
 
 Problem Name     : SPACEKINGS
 Problem Statement:
 
    Spacekings Asha and Amar are playing SpaceKings a video game.It is a two player game where the second player is the helper.Asha needs
    your help maximizing her gold while playing her favorite game.Both are facing N aliens.Asha and Amar are both at a single location and the
    aliens are in lined up in front of them.Asha and Amar take turns shooting the aliens, and she goes first.During his turn,Amar always shoots
    the alien closest to him to help Asha maximize her gold.Asha and Amar cannot shot dead alien.If Asha shoots at an alien,its hitpoint are
    reduced by P,If Amar shoots at an alien ,its hitpoint are reduced by Q,If an alien's hitpoint goes below 1,it is killed.The ith alien starts
    Hi hit points.Asha is awarded Gi gold if her shots kills the ith alien,but none if Amar's shot kills it.What is the maximum amount of gold
    Asha can obtain?Input Each Case begins with one line containing three space seperated integers representing P,Q and N.N lines the follow,with
    the ith line containing two space seperated integers representing Hi and Gi .The aliens are given in the order of their distance from Asha and Amar.
    In other words,Amar will shoot at the ith alien only if all aliens<i are dead.Output the Maximum amount of gold that Asha can obtain.
    
    Input :
    
    20 60 3
    
    80 100
    80 200
    120 300
    
    Output:
    
    500
    
    Explaining Asha should give up the first alien,During her first two turns she should soften up the third alien bringing it down to 80Hitpoint
    allowing her to easily get the last shot on the second and third aliens.
    
    Input:
    
    50 60 2
    
    40 100
    40 90
    
    Output:
    
    100
    
    Input:
    
    50 60 2
    40 100
    40 200
    
    Output:
    
    200
    
    
    Input:
    
    50 100 2
    60 100
    60 200
    
    Output:
    
    200
    
    Input:
    
    50 400 2
    
    60 100
    190 200
    
    Output:
    
    0

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Function to check that whether all aliens are dead are not
bool AED(vector<int> alien_strength){
    for(int i=0;i<alien_strength.size();i++){
        if(alien_strength[i]>=1){
            return false;
        }
    }
    return true;
}

vector<int> ans;

void max_gold(int P,int Q,vector<int> H,vector<int> G,int pts,int turn){
    if(AED(H)){
            cout<<"Called";
        ans.push_back(pts);
    }
    else{
        if(turn==0){
                cout<<"T1 ";
            //U might shoot at any alive alien or skip shoot
             //skips shoot
            for(int i=0;i<H.size();i++){
                if(H[i]>=1){
                    H[i]-=P;
                    if(H[i]<1){
                    max_gold(P,Q,H,G,pts+G[i],turn+1);
                    }
                    else{
                    max_gold(P,Q,H,G,pts,turn+1);
                    }
                    H[i]+=P;
                }
            }
            max_gold(P,Q,H,G,pts,turn+1);
        }
        else if(turn==1){
            cout<<"T2 ";
            //definiteky u must shoot using Q the first alive alien
            int alien=0;
            for(int i=0;i<H.size();i++){
                if(H[i]>=1){
                    alien=i;
                    break;
                }
            }
            H[alien]-=Q;
            max_gold(P,Q,H,G,pts,turn-1);
            H[alien]+=Q;
        }
    }
}


int main(){


    int n,p,q,k,l;
    cin>>n>>p>>q;
    vector<int> hit,gold;
    while(n)
    {
     cin>>k>>l;
     hit.push_back(k);
     gold.push_back(l);
     n--;
    }
    max_gold(p,q,hit,gold,0,0);
    cout<<"Printing answer vector\n";
    int m=ans[0];
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]>m){
            m=ans[i];
        }
        cout<<ans[i]<<" ";
    }

    cout<<endl;
    cout<<"The maximum gold possibility is ";
    cout<<m;
    return 0;
}

