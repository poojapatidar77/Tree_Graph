 //Binary search
 
 #include<stdio.h>
 int search(int se)
 {
	 int x[]={1,10,12,30,42,55,56,60};
	 int n=8;
	 int mid,i;
	 int si=0;
	 for(i=si;si<=n;i++)
	 {
		 mid=(si+n)/2;
		 if(se==x[mid])
		 {
			 return mid;
		 }
		 else if(se>x[mid])
		 {
			 si=mid+1;
		 }
		 else if(se<x[mid])
		 {
			 n=mid-1;
		 }
	 }
	 return -1;
 }
 void main()
 {
	 printf("%d\n",search(1));
 	 printf("%d\n",search(10));
	 printf("%d\n",search(42));
	 printf("%d\n",search(60));

 }