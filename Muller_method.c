#include <stdio.h>
#include <math.h>
const int MAX = 10000;
//this function to find f(n)
float f(float x) {
   // f(x) = x ^ 3 + 2x ^ 2 + 10x - 20
   return 1*pow(x, 3) + 2*x*x + 10*x - 20;
}
int muller(float a, float b, float c) {
   int i;
   float result;
   for (i = 0;;++i) {
      // Calculating various constants required
      // to calculate x3
      float f1 = f(a);
      float f2 = f(b);
      float f3 = f(c);
      float d1 = f1 - f3;
      float d2 = f2 - f3;
      float h1 = a - c;
      float h2 = b - c;
      float a0 = f3;
      float a1 = (((d2*pow(h1, 2)) - (d1*pow(h2, 2))) / ((h1*h2) * (h1-h2)));
      float a2 = (((d1*h2) - (d2*h1))/((h1*h2) * (h1-h2)));
      float x = ((-2*a0) / (a1 + abs(sqrt(a1*a1-4*a0*a2))));
      float y = ((-2*a0) / (a1-abs(sqrt(a1*a1-4*a0*a2))));
      // Taking the root which is closer to x2
      if (x >= y)
         result = x + c;
      else
         result = y + c;
         // checking for resemblance of x3 with x2 till
         // two decimal places
         float m = result*100;
         float n = c*100;
         m = floor(m);
         n = floor(n);
         if (m == n)
         break;
         a = b;
         b = c;
         c = result;
         if (i > MAX) {
            printf("Root can't be found using Muller method\n");
            break;
         }
   }
   if (i <= MAX)
   printf("The root is %f", result);
   return 0;
}
// main function
int main() {
   float a = 1, b = 3, c = 2;
   muller(a, b, c);
   return 0;
}