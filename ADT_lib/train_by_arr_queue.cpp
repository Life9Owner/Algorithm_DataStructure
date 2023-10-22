#include<stdio.h>
#include<stdlib.h>
#define Max 20
// k is the train number
static int cnt=0;
int compare(const void* a,const void* b);
typedef struct
{
	int data[Max];
	int front,rear;
}squeue;
void initqueue(squeue *&q)
{
	q=(squeue*)malloc(sizeof(squeue));
	q->front=q->rear=0;
}
void enqueue(squeue* &q,int e)
{
	q->rear=(q->rear+1)%Max;
	q->data[q->rear]=e;
	
}
void dequeue(squeue *&q)
{
	q->front=(q->front+1)%Max;
}
int gettop(squeue *&q)
{
	return q->data[q->front+1];
}
int getrear(squeue *&q)
{
	{
		return q->data[q->rear];
	}
}
void reset(squeue *&q,squeue * &w1,squeue* &w2,int k)
//in ==q,w1 ==wait_trace1 ==w2==wait_trace2
{
	int nowout=1;
	int n1=0,n2=0;
	squeue* out;
	initqueue(out);
	for(int i=0;i<50;i++)//the train in the waiting queue and go out  of the waiting queue,
	//I can't know the times it really before a specific example is given
	//Let me use the magic method to get it stop!
	{
		cnt++;
		if(q->data[q->front+1]==nowout)
		{
			printf("%dth train out!\t",q->data[q->front+1]);
			enqueue(out,nowout);
			nowout++;
			dequeue(q);
		}
		else if(gettop(w1)==nowout)
		{
			printf("%dth train out! \t",gettop(w1));
			enqueue(out,nowout);
			nowout++;
			dequeue(w1);
			
		}
		else if(gettop(w2)==nowout)
		{
			printf("%dth train out!\t",gettop(w2));
			enqueue(out,nowout);
			nowout++;
			dequeue(w2);
		
		}else{
			int c=gettop(q);
			n1=getrear(w1);
			n2=getrear(w2);
			if(n1>n2)
			{
				if(c>n1)
				{
					enqueue(w1,c);
					dequeue(q);
				}
				else
				{
					enqueue(w2,c);
					dequeue(q);
				}
			}
			else
			{
				if(c>n2)
				{
					enqueue(w2,c);
					dequeue(q);
				}
				else
				{
					enqueue(w1,c);
					dequeue(q);
				}
			}
		}
		//if the last train is is out ,stop
		if(getrear(out)==k)
		{
			break;
		}
	}
}
int examenter(int a[],int k)
{
	#if 1
	int temp[k];
	for(int i=0;i<k;i++)
	{
		temp[i]=a[i];
	}
	qsort(temp,k,sizeof(int),compare);
	for(int i=0;i<k;i++)
	{
		printf("temp[i]:%d\n",temp[i]);
		
	}
	for(int i=0;i<k;i++)
	{
		if(temp[i]!=i+1)
		{
		return 0;
		}
		
	}
	return 1;
	#endif
	
}
int main()
{
	squeue* q,*w1,*w2;
	initqueue(q);
	initqueue(w1);
	initqueue(w2);
	int a[10],k;
	label:
		printf("how much train do you want to add\n");
		scanf("%d",&k);
		if(k<=0)
		{
			printf("input the right train num\n");
			printf("**********************************************");
			printf("\n");
			goto label;
		}
		label2: 
			printf("input the before sorted sequeue\n");
			
			for(int i=0;i<k;i++)
			{
				scanf("%d",&a[i]);
				enqueue(q,a[i]);
			}
			int r=examenter(a,k);
			if(r==0)
			{
				printf("the train num input is wrong\n");
				goto label2;
			}
			else{
				printf(" before sorted:\n");
				for(int i=0;i<k;i++)
				{
					printf("%d\t",a[i]);
				}
				printf("\n");
				printf("sorted\n");
				reset(q,w1,w2,k);
			}
			printf("cnt=%d",cnt);
}

int compare(const void* a,const void* b)
{
	
	if(*(int*)a>*(int*)b)
	{
		return 1;
	}
	else if(*(int*)a==*(int*)b)
	{
		return 0;
	}
	else 
	{
		return -1;
	}
	
}