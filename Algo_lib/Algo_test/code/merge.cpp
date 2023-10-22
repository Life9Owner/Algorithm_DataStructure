#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int* merge(int A[],int tempArr[],int lhead,int rhead,int rend);
void Merge_Sort(int *arr,int* temp,int L,int RightEnd);
void sort_something()
{
    vector<int> vec{43,2,3,4,5,1,566,23,13,3,};
    sort(&vec[0],&vec[10]);
    sort(vec.begin(),vec.end(),greater<int>());
    for(int a:vec)
    {
        cout<<a<<" ";
    }

}
int main()
{
    sort_something();

    return 0;
}
int* merge(int A[],int tempArr[],int lhead,int rhead,int rend)
{
    
    int lend=rhead-1;
    int Tmp=lhead;//I think it may be '0'
    
    while(lhead<lend&&rhead<rend)
    {
        if(A[lhead]<=A[rhead])
        tempArr[Tmp++]=A[lhead++];
        else{
            tempArr[Tmp++]=A[rhead++];
        }
    }
    while(lhead<lend)
    {
        tempArr[Tmp++]=A[lhead++];
    }
     while(rhead<rend)//whether is it equal?
     //It's a topic about whether 'lhead','lend','rhead','rend',is the index or pointer.
    {
        tempArr[Tmp++]=A[rhead++];
    }
    for(int i=rend-1;i>=0;i--)
    {
        A[i]=tempArr[i];
    }
    return A;
    
}