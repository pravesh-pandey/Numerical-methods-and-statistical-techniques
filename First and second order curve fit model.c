#include<stdio.h>
main()
{
printf("\tFor 1st order------\n");
int n,i;
printf("\nPlease enter the degree of polynomial n=");
scanf("%d",&n);
float a[n+1],x,p[n+1],r[0];
for(i=n;i>=0;i--)
{
printf("Please enter the coeff of pow(x,%d)=",i);
scanf("%f",&a[i]);
}
printf("Please enter the variable x =");
scanf("%f",&x);
p[n]=a[n];
for(i=n;i>0;i--)
{
p[i-1]=p[i]*x+a[i-1];
}
printf("Value of polynomial is %f\n",p[0]);


printf("\t\nfor 2nd order-------\n");
int d,j;
printf("\nPlease enter the degree of polynomial d=");
scanf("%d",&d);
float b[d+1],X,f[d+1];
for(j=d;j>=0;j--)
{
printf("Please enter the coeff of pow(x,%d)=",j);
scanf("%f",&b[j]);
}
printf("Please enter the variable X =");
scanf("%f",&X);
f[d]=b[d];
for(j=d;j>0;j--)
{
f[j-1]=f[j]*X+b[j-1];
}
printf("Value of polynomial is %f\n",f[0]);
printf("\t\ncomparing the results----\n");
r[0]=p[0]-f[0];
printf("result is %f",r[0]);
}
