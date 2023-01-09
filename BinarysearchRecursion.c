 //Binary search using recursion
 
 #include<stdio.h>
 int search(int se,int si,int n)
 {
	 if(si>n)return -1;
	 int x[]={1,10,12,30,42,55,56,60};
	 int mid,i;

		 mid=(si+n)/2;
		 if(se==x[mid])
		 {
			 return mid;
		 }
		 else if(se>x[mid])
		 {
			 si=mid+1;
			 search(se,mid+1,n);
		 }
		 else if(se<x[mid])
		 {
			 n=mid-1;
			 search(se,si,mid-1);
		 }
  }
 void main()
 {
	 printf("%d\n",search(1,0,7));
 	 //printf("%d\n",search(10,0,7));
	 //printf("%d\n",search(-42,0,7));
	 //printf("%d\n",search(90,0,7));

 }