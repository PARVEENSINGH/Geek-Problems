#include <iostream>
using namespace std;
typedef long long ll;
// Time Complexity O(d*(n+b))
ll getMax(ll a[],ll n)
{
    ll max=a[0];
    for(ll i=0;i<n;i++)
    {
        if(max<a[i])
        max=a[i];
    }
    cout<<max<<endl;
    return max;
}
void countSort(ll a[],ll n,int ex)
{
    ll op[n];
    int count[10]={0};
    
    for(ll i=0;i<n;i++)
        count[(a[i]/ex)%10]++;
        
    for(int i=1;i<10;i++)
        count[i]+=count[i-1];
        
    for(ll i=n-1;i>=0;i--)
    {
        op[count[(a[i]/ex)%10]-1]=a[i];
        count[(a[i]/ex)%10]--;
    }
    
    for(ll i=0;i<n;i++)
    a[i]=op[i];
}
void printSortedArray(ll a[],ll n)
{
    for(ll i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
void radixsort(ll a[],ll n)
{
    ll max=getMax(a,n);
    for(int ex=1;max/ex>0;ex*=10)
    countSort(a,n,ex);
    
    printSortedArray(a,n);
}
int main() 
{
 int t;
 cin>>t;
 while(t--)
 {
     ll n;
     cin>>n;
     
     ll a[n];
     for(ll i=0;i<n;i++)
     cin>>a[i];
     
     radixsort(a,n);
 }
}

