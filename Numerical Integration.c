#include <stdio.h>
#include <math.h>
float f(float);
float f(float x)
{
    return 1 / (1 + x * x);
}
void main()
{
    int i, j, n, m = 0, z, t, e, o = 0;
    float a, b, h, sum;
    printf("enter the lower limit = ");
    scanf("%f", &a);
    printf("enter the upper limit = ");
    scanf("%f", &b);
    printf("enter no of sub-intervals = ");
    scanf("%d", &n);
    if (n % 2 == 0)
    {
        m = 1;
        if (n % 4 == 0)
        {
            printf("best method are trapezoidal,simpson 1/3,boole\n");
            printf("for trapezoidal press 1,for simspson 1/3 press 2,for boole press 3,for all press 0 = ");
            scanf("%d", &e);
        }
        if (n % 6 == 0)
        {
            printf("best method are trapezoidal,simpson 1/3,weddle\n");
            printf("for trapezoidal press 4,for simspson 1/3 press 5,for weddle press 6,for all press 7 = ");
            scanf("%d", &z);
        }
    }
    if (n % 3 == 0)
    {
        o = 1;
        printf("best method are trapezoidal and simpson 3/8\n");
        printf("for trapezoidal press 8,for simspson 3/8 press 9,for both press 10 = ");
        scanf("%d", &t);
    }
    if (m == 1)
    {
        if (e == 1 || e == 0 || z == 4 || z == 7)
        {
            h = (b - a) / n;
            sum = 0;
            for (i = 1; i <= n - 1; i++)
            {
                int l = a + (h * i);
                sum += 2 * f(l);
            }
            sum = sum + (f(a) + f(b));
            sum = (sum * h) / 2;
            printf("I by trapezoidal = %f\n", sum);
        }
        if (e == 2 || e == 0 || z == 5 || z == 7)
        {
            sum = 0;
            h = (b - a) / n;
            for (i = 1; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    int l = a + (h * i);
                    sum += 2 * f(l);
                }
                else
                {
                    int l = a + (h * i);
                    sum += 4 * f(l);
                }
            }
            sum += f(a) + f(b);
            sum = (sum * h) / 3;
            printf("I by simpson 1/3 = %f\n", sum);
        }
        if (e == 3 || e == 0)
        {
            h = (b - a) / 8;
            sum = 0;
            sum = 7 * f(a) + 32 * f(a + h) + 12 * f(a + h * 2) + 32 * f(a + 3 * h) + 14 * f(a + h * 4) + 32 * f(a + 5 * h) + 12 * f(a + 6 * h) + 32 * f(a + h * 7) + 14 * f(a + 8 * h);
            sum = (sum * 2 * h) / 45;
            printf("I by boole = %f\n", sum);
        }
        if (z == 7 || z == 6)
        {
            h = (b - a) / 12;
            sum = 0;
            sum = f(a) + 5 * f(a + h) + f(a + h * 2) + 6 * f(a + 3 * h) + f(a + h * 4) + 5 * f(a + 5 * h) + 2 * f(a + 6 * h) + 5 * f(a + h * 7) + f(a + 8 * h) + 6 * f(a + 9 * h) + f(a + 10 * h) + 5 * f(a + 11 * h) + 2 * f(a + 12 * h);
            sum = (sum * 3 * h) / 10;
            printf("I by weddle = %f\n", sum);
        }
    }
    if (o == 1)
    {
        if (t == 10 || t == 8)
        {
            h = (b - a) / n;
            sum = 0;
            for (i = 1; i <= n - 1; i++)
            {
                int l = a + (h * i);
                sum += f(l);
            }
            sum = sum + (f(a) + f(b)) / 2;
            sum = sum * h;
            printf("I by trapezoidal = %f\n", sum);
        }
        if (t == 9 || t == 10)
        {
            sum = 0;
            h = (b - a) / n;
            for (i = 1; i < n; i++)
            {
                if (i % 3 == 0)
                {
                    int l = a + (h * i);
                    sum += 2 * f(l);
                }
                else
                {
                    int l = a + (h * i);
                    sum += 3 * f(l);
                }
            }
            sum += f(a) + f(b);
            sum = (sum * h * 3) / 8;
            printf("I by simpson 3/8 =%f ", sum);
        }
    }
}