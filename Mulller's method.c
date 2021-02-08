#include <stdio.h>
#include <math.h>
#define f(x) x *x *x - x *x - x - 1
#define error 0.0000001
float max(float a, float b)
{
    if (a > b)
        return b;
    else
        return a;
}

int main(void)
{

    float
        x1 = 1,
        x2 = 2,
        x3 = 3, x4;
    int i = 3;
    printf("iteration = %d x%d =%f  f(x) = %f\n", 1, 1, x1, f(x1));
    printf("iteration = %d x%d =%f  f(x) = %f\n", 2, 2, x2, f(x2));
    printf("iteration = %d x%d =%f  f(x) = %f\n", 3, 3, x3, f(x3));
    while (fabs(x3 - x2) > error)
    {

        i++;
        float
            a,
            b, c, q;

        q = (x3 - x2) / (x2 - x1);
        c = (1 + q) * f(x3);
        b = (2 * q + 1) * f(x3) - (1 + q) * (1 + q) * f(x2) + q * q * f(x1);
        a = q * f(x3) - q * (1 + q) * f(x2) + q * q * f(x1);
        if ((b * b - 4 * a * c) > 0)
        {

            x4 = x3 - (x3 - x2) * ((2 * c) / (max(b + pow(b * b - 4 * a * c, 0.5), b - pow(b * b - 4 * a * c, 0.5))));
            printf("iteration = %d x%d =%f  f(x) = %f\n", i, i, x4, f(x4));
            x1 = x2;
            x2 = x3;
            x3 = x4;
        }
        else
        {
            printf("complex");
            break;
        }
    }
    return 0;
}
