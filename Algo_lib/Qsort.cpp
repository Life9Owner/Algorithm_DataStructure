#include<iostream>
using namespace std;
// {6,10,13,5,8,3,2,11};
int partition(int A[], int p, int r)
{
    int i = p;
    printf("pivot:%dpivot\n",A[r]);
    for (int j = p+1; j <=r; ++j) {
        if (A[j] <A[p]){
            swap(A[++i],A[j]);
        }
    }
    swap(A[p],A[i]);
    return i;
}

void quickSort(int A[], int p, int r){
    
    //  for (int i = 0; i <= r; i++) {cout<<A[i]<<" ";}
    //  cout<<endl;
    if(p<r){
        int q = partition(A,p,r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}
int main(){
    
    int A[] = {0,6,10,13,5,8,3,2,11};
    int len =sizeof(A)/ sizeof(A[0])-1;
    quickSort(A,1,len);
    for (int i = 1; i <= len; i++) {cout<<A[i]<<" ";}
}