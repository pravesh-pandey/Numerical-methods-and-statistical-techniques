#include<stdio.h>
#include<math.h>
int main()
{
 float x[20], y[20][20],s1,S=0,g,g1;
 int i,j,n,X;
 printf("Enter number of data:");
 scanf("%d", &n);
 printf("Enter data:\n");
 for(i = 0; i < n ; i++)
 {
  printf("x[%d]=", i);
  scanf("%f", &x[i]);
  printf("y[%d]=", i);
  scanf("%f", &y[0][i]);
 }
 printf("\nEnter value of x at which you want to find f(x):");
 scanf("%d",&X);
 for(j=0;j<n;j++)
 {
     s1=1;
     for(i=0;i<n;i++)
     {
         if(i!=j)
         {
             s1=s1*((X-x[i])/(x[j]-x[i]));
         }
     }
     S=S+s1*y[0][j];
 }
 printf("f(%d) using Lagrange Interpolation Formula:%f\n",X,S);
 for(i = 1; i < n; i++)
 {
  for(j = 0; j < n-i; j++)
  {
   y[i][j] = (y[i-1][j+1]-y[i-1][j])/(x[j+i]-x[j]);
  }
 }
 g=y[0][0];
 for(j=0;j<n-1;j++)
 {
     g1=1;
     for(i=0;i<=j;i++)
     {
         g1=g1*(X-x[i]);
     }
     g=g+g1*y[j+1][0];
 }
   printf("f(%d) using Newton General Interpolation Formula:%f\n",X,g);
   printf("Difference between values obtained from both the methods:%f",fabs(S-g));
}
