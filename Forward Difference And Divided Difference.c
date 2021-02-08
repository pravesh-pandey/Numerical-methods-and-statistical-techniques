#include<stdio.h>
#define n 6

void print_table(int a[n][n],int x[n],int y[n])
{
    int i=0,j=0;
    printf("--------------------------------------------\n");
    printf("x   y  diff1 diff2 diff3 diff4 diff5\n");
    printf("--------------------------------------------\n");
    for(i=0;i<n;i++)
     {
        printf("%d  ",x[i]);
        for(j=0;j<n-i;j++)
        printf("%d  ",a[i][j]);
        printf("\n");
    }
}
void forward_difference(int x[n],int y[n])
{
    
    int a[n][n];
    int i=0,j=0;
    for(i=0;i<n;i++)
    a[i][0]=y[i];
    for( i=1;i<n;i++)
    {
        for( j=0;j<n-i;j++)
        a[j][i]=(a[j+1][i-1]-a[j][i-1]);
    }
    print_table(a,x,y);
}
void divided_difference(int  x[n],int y[n])
{
    int a[n][n];
    int i=0,j=0;
    for(i=0;i<n;i++)
    a[i][0]=y[i];
    for( i=1;i<n;i++)
    {
        for( j=0;j<n-i;j++)
        a[j][i]=((a[j+1][i-1]-a[j][i-1])/(x[j+i]-x[j]));
    }
    print_table(a,x,y);
    
}
int main()
{
    int x[]={5,10,15,20,25,30},y[]={9962,9848,9659,9397,9063,8660};
    printf("Choose which table you want forward/backword/central difference (1,2,3)\n");
    int c=0;
    scanf("%d",&c);
    printf("First table is given as\n");
     forward_difference(x,y);
      printf("--------------------------------------------\n");
     printf("divided_difference Table is given as \n");
    int x1[]={4,5,7,10,11,13},y1[]={48,100,294,900,1210,2028};
    divided_difference(x1,y1);
    printf("-------------XXXX---------------------");
    return 0;
}
