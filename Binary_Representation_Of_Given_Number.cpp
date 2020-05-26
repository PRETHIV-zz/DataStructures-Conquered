#include<iostream>


using namespace std;

void printbits(int no){
    if(no<0){
        cout<<"ERROR Negative Can't be Handled";
    }
    else if(no==0){
        cout<<"0";
    }
    else{
        printbits(no/2);
        cout<<no%2;
    }
}

int main()
{
    int no;

    cin>>no;

    printbits(no);

    return 0;
}
