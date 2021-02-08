
#include <stdio.h>
#include <math.h>
#define error 0.000001

int main()
{

      

      printf("The four eqations for which the root is calculated are given as : \n");
      printf("\t x1 = 0.3 + 0.2*x2 + 0.1*x3 + 0.1*x4\n");
      printf("\t x2 = 1.5 + 0.2*x1 + 0.1*x3 + 0.1*x4\n");
      printf("\t x3 = 2.7 + 0.1*x1 + 0.1*x2 + 0.2*x4\n");
      printf("\t x4 = -0.9 + 0.1*x1 + 0.1*x2 + 0.2*x3\n");

      float x1 = 0, x2, x3, x4, a, b, c, d, k;
      int i = 1;

      printf("Enter the initial guess values of x2 , x3 , x4 :   ");
      scanf("%f%f%f", &x2, &x3, &x4);

      printf("\n sweep\tx1\tx2\tx3\tx4\n");

      do
      {
            a = x1;
            b = x2;
            c = x3;
            d = x4;

            x1 = 0.3 + 0.2 * x2 + 0.1 * x3 + 0.1 * x4;
            x2 = 1.5 + 0.2 * x1 + 0.1 * x3 + 0.1 * x4;
            x3 = 2.7 + 0.1 * x1 + 0.1 * x2 + 0.2 * x4;
            x4 = -0.9 + 0.1 * x1 + 0.1 * x2 + 0.2 * x3;

            if (fabs(x1 - a) < 0.000001 && fabs(x2 - b) < 0.000001 && fabs(x3 - c) < 0.000001 && fabs(x4 - d) < 0.000001)
            {
                  k = 0;
            }
            else
            {
                  k = 1;
            }

            printf("%d   \t%f\t%f\t%f\t%f\n", ++i, x1, x2, x3, x4);
      } while (k);

      printf("     \t\tx1\t\tx2\t\tx3\t\tx4\n");
      printf("ans   \t   %f\t   %f\t   %f\t   %f\n", x1, x2, x3, x4);
      return 0;
}
