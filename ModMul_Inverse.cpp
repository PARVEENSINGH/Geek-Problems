
#include <iostream>
using namespace std;

int EuclidianGcd(int a,int m,int *t1,int *t2)
{
    if(a==0)
    {
        *t1=0;
        *t2=1;
        return m;
    }
    int x,y;
    int gcd=EuclidianGcd(m%a,a,&x,&y);
    *t2=x;
    *t1=y-(m/a)*x;
    return gcd;
}

int GetMulInverse(int a,int m)
{
    int x,y;
    int gcd=EuclidianGcd(a,m,&x,&y);
    if(gcd!=1)
    cout<<-1<<endl;
    else
    {
        int res=(x%m+m)%m;
        cout<<res<<endl;
    }
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int a,m;
        cin>>a>>m;
        
        GetMulInverse(a,m);
    }
	return 0;
}
