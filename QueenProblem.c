//Queen problem 

#include<stdio.h>
#include<stdbool.h>
#define s 5
bool isvalid(int x[s][s],int r,int c)
{
	int i,j;
	for(i=c;i>=0;i--)if(x[r][i])return false;
	for(i=r,j=c;i>=0&&j>=0;i--,j--)if(x[i][j])return false;
	for(i=r,j=c;i<s&&j>=0;i++,j--)if(x[i][j])return false;
     return true;
}
bool show(int x[s][s],int c)
{
	if(c==s)return  true;
	int i;
	for(i=0;i<s;i++)
	{
		if(isvalid(x,i,c))
		{
			x[i][c]=1;
			if(show(x,c+1))return true;
			x[i][c]=0;
		}
	}
	return false;
}
void main()
{
	int x[5][5]={0};
	int i ,j;
	show(x,0);
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			printf("%d ",x[i][j]);
		}
		printf("\n");
	}
}