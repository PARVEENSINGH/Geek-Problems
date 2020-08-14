
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define MAX 255

//https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes/0

void  PrintPrime(ll A[],ll n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(A[i])
        {
            for(int p=i*i;p<=n;p+=i)
                A[p]=0;
        }
    }    

    for(int i=2;i<=n;i++)
        if(A[i]!=0)
            cout<<A[i]<<" ";
}
int main() 
{
   int t;
   cin>>t;
   while(t--)
   {
       ll n;
       cin>>n;

        ll A[n+2];
        for(int i=2;i<=n;i++)
            A[i]=i;

     PrintPrime(A,n);
     cout<<endl;
   }
       
    return 0;
}

