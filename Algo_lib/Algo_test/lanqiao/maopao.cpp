#include<iostream>
using namespace std;
void swap_(int& a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
int main()
{
    int arr[10]={3,2,5,4,1,0,8,9,6,7};
    int n=10;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
            {
                swap(arr[j],arr[i]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"   ";
    }
}