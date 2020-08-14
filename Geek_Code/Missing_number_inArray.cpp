
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define MAX 255

int main() 
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;

       ll A[n+1],a;
       memset(A,0,(n+1)*sizeof(int));
       for(int i=1;i<n;i++)
       {
         cin>>a;
         A[a]=a;
       }

       for(int i=1;i<=n;i++)
       {       
           if(A[i]!=i)
            {
                cout<<i<<endl;
                break;
            }
       }
   }
       
    return 0;
}

