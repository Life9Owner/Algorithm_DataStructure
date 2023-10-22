#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct container
{
	int id;
	int weight;
};
bool Compare(container a,container b)
{
	return a.weight<b.weight;
}
void containerLoading(container* c,int capacity,int numberOfContainers, int*x)
{
	int n=numberOfContainers;//simplify
	sort(c,c+n,Compare);//sort
	for(int i=0;i<n&&c[i].weight<=capacity;i++)//judge whether to save or weed out
	{
		x[c[i].id-1]=1;
		capacity-=c[i].weight;
	}
	
}
int main()
{
	container  c[8];
	for(int i=0;i<8;i++)
	{
		c[i].id=i+1;
	}
	
	c[0].weight=100;
	c[1].weight=200;
	c[2].weight=50;
	c[3].weight=90;
	c[4].weight=150;
	c[5].weight=50;
	c[6].weight=20;
	c[7].weight=80;
	for(const container watch:c)
	{
		cout<<watch.id<<"    ";
		cout<<watch.weight<<endl;
	}
	sort(c,c+8,Compare);
	cout<<endl<<"after"<<endl;
	for(const container watch:c)
	{
		cout<<watch.id<<"    ";
		cout<<watch.weight<<endl;
	}
	int x[8]={0};
	containerLoading(c,400,8,x);
	for(int watch:x)
	{
		cout<<"x:"<<watch<<endl;
	}
	cout<<"The answer:"<<endl;
	for(int i=0;i<8;i++)
	{
		if(x[i]==1)
		{
			cout<<"id= "<<i+1<<endl;
		}
	}
	
	return 0;

}