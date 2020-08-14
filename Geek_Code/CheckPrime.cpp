
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define MAX 255

string  checkPrime(int n)
{
    if(n<=1)
    return "No";

    if(n<=3)
    return "Yes";

    if(!(n%2) || !(n%3))
    return  "No";

//Every prime number can be written in the form (6k ± 1) exceptionally 2 and 3.

    for(int i=5;i*i<=n;i=i+6)
        if(n%i==0 || n%(i+2)==0)
            return "No";

    return "Yes";        
}
int main() 
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;

        cout<<checkPrime(n)<<endl;
   }
       
    return 0;
}

