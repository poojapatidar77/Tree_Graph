#include<stdio.h>
#include<stdbool.h>
#define size 5
#define max 2147483647
void algo(int x[size][size],int src);
void showall(int output[]);
int min_dis(int output[],bool b[]);
void main()
{
	int x[size][size]={{0,6,0,0,1},{6,0,5,2,2},{0,5,0,5,0},{0,2,5,0,1},
	{1,2,0,1,0}};
    algo(x,0);
}
void algo(int x[size][size],int src)
{
	int output[size];
	bool b[size];
	int i,j,m;
	for(i=0;i<size;i++)
	{
		output[i]=max;
		b[i]=false;
	}
	 output[src]=0;
	 for(i=0;i<size;i++)
	 {
		 m=min_dis(output,b);
 	   b[m]=true;
	 for(j=0;j<size;j++)
	 {
		 if(x[m][j]!=0 && b[j]==false && output[j]>output[m]+x[m][j])
			 output[j]=output[m]+x[m][j];
	 }
	 }
     showall(output);
}
void showall(int output[])
{
	int i;
	printf("vertex\toutput\n");
	for(i=0;i<size;i++)
	{
		printf("%d\t%d\n",i,output[i]);
	}
}
int min_dis(int output[],bool b[])
{
	int i,m,min=max;
	for(i=0;i<size;i++)
	{
		if(min>output[i] && b[i]==false)
		{
			min=output[i];
			m=i;
		}
	}
	return m;
}