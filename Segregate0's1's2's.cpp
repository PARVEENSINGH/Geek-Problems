using namespace std;

void printArray(int A[],int n)
{
    for(int i=0;i<n;i++)
    cout<<A[i]<<" ";
}
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void partitionLikeQuickSort(int A[],int l,int r)
{
    int mid=0;
    int end=r-1;
    
    while(mid<=end)
    {
        switch(A[mid])
        {
            case 0:
                swap(&A[mid++],&A[l++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(&A[mid],&A[end--]);
                break;
                
        }
    }
    printArray(A,r);
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int A[n];
	    int pi=0;
	    
	    for(int i=0;i<n;i++)
        {
            cin>>A[i];
            
            if(A[i]==1)
            pi=i;
        }
       partitionLikeQuickSort(A,0,n);
        cout<<endl;
	}
	return 0;
}