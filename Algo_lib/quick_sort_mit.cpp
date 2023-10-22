#include<iostream>
using namespace std;
int Partition(int* A,int p,int q);
void Qsort(int* A,int p,int q);
int main()
{
    int A[] = {100,4,1,3,2,16,9,10,14,8,7};
    int len =sizeof(A)/ sizeof(A[0])-1 ;
    cout<<len<<endl;
    Qsort(A,0,len+1);
for (int i = 0; i <= len; i++) {cout<<A[i]<<" ";}
    return 0;
}
int Partition(int* A,int p,int q)
{

    int i=p;//0
    //1 2 3 4 
    for(int j=p+1;j<q;j++)//+1 
    {
        if(A[j]<=A[p])
        {
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[p]);
    return 1+i;
}
void Qsort(int* A,int p,int q)
{
    if(p<q)
    {
        int r=Partition(A,p,q);
        Partition(A,p,r-1);
        Partition(A,r+1,q);
    }
}