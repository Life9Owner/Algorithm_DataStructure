// Java:https://blog.csdn.net/weixin_42240763/article/details/111436165
// C语言:
#include<stdio.h>
int main(){
	int n,m,i,j,max=0,t;
	scanf("%d%d",&n,&m);
	// int a[n];
	int* a=new int[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){//共计算n-1次 
		t=0;
		for(j=i;j<m+i;j++){//锁定求和范围为[i,i+m-1]
			if(j>n-1){//j超出数组长度是需要回头所以j-n 
				t+=a[j-n];
			}
			else{
				t+=a[j];
			}
		}
		if(t>max){//每次一比较保留较大值 
			max=t;
		}
	}
	printf("%d",max);
	return 0;
}
