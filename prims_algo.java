
import java.util.*;

class Demo1
{
	int size=5;
	int  key[]=new int[size];
	int  parent[]=new int[size];
	boolean mst[]=new boolean[size];
	
	Demo1()
	{
		Arrays.fill(key,Integer.MAX_VALUE);
		Arrays.fill(parent,-1);
		key[0]=0;
	}
	int min_val()
    {
	   int min=Integer.MAX_VALUE;
        int m=0;
        for(int i=0;i<size;i++)
		{
		 if(min>key[i] && mst[i]==false)
		 {
			 min=key[i];
			 m=i;
		 }			 
			 
		}	
     return m;		
	}
	void prims(int x[][])
	{
     
     for(int i=0;i<size;i++)
	 {
		 int u=min_val();
		 mst[u]=true;
		 for(int j=0;j<size;j++)
		 {
			if(x[u][j]!=0 && key[j]>x[u][j])
			{
			 	key[j]=x[u][j];
				parent[j]=u;
			}				
		 }
         display();		 
	 
	 }		 
	
	}
	void display()
	{
		System.out.print("Key =>  ");
		for(int i:key)
		System.out.print(i+"  ");
		System.out.println();
		System.out.print("mst -> ");
		for(boolean i:mst)
		System.out.print(i+"  ");
		System.out.println();

System.out.print("parent =>  ");
		for(int i:parent)
		System.out.print(i+"  ");
		System.out.println();
		


		System.out.println();
	}
	
	public static  void main(String ar[])
	{
		int a=Integer.MAX_VALUE;
		int x[][]={
			{0,2,0,6,0},
			{2,0,3,8,5},
			{0,3,0,0,7},
			{6,8,0,0,0},
			{0,5,7,0,0}
		
		};
		Demo1 d=new Demo1();
		d.prims(x);
	}
}
