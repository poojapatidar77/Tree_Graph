
import java.util.*;

class Demo1
{
	static int n=7;
       int x[]=new int[n];
        int dis[][]=new int[n][n];
            Demo1()
			{
				
			for(int i=0;i<n;i++)
               x[i]=Integer.MAX_VALUE; 			
                  
                 x[0]=0;				  
		}
			
			void insert(int u,int v,int w)
			{
				dis[u-1][v-1]=w;
			}

            void relexation()
			{
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<n;j++)
					{
						if(dis[i][j]!=0 && dis[i][j]+x[i]<x[j])
						{
						   x[j]=dis[i][j]+x[i];	
						}
					}
				}
			}
			


	public static  void main(String ar[])
	{
			Demo1 d=new Demo1();
		d.insert(1,2,6);	
		d.insert(1,3,5);	
		d.insert(1,4,5);
		d.insert(2,5,-1);
		d.insert(3,5,1);
		d.insert(3,2,-2);
		d.insert(4,3,-2);
		d.insert(4,6,-1);
		d.insert(6,7,3);
		d.insert(5,7,3);
		

			
			
			for(int i=1;i<n;i++)
			{
				d.relexation();
			}
	       for(int i=0;i<n;i++)
			   System.out.println(d.x[i]);
		  
		  

		
		



	}
}
