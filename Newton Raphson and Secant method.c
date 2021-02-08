#include <stdio.h>
#include <math.h>
// #define f(x) 2*x*x*x+5*x*x+3*x+7
// #define derivative_of_f(x) 6*x*x+10*x+3
#define f(x) x *x *x
#define derivative_of_f(x) 3 * x *x

#define error 0.0001
void netwon_method(float x1)
{
    printf("\n");
    int i = 0;
    float x2 = x1 - (f(x1) / derivative_of_f(x1));

    while (fabs(x1 - x2) >= error && i < 100)
    {
        i++;
        printf("%d iteration x is %f and error is %f\n", i, x2, x2 - x1);
        x1 = x2;
        x2 = x1 - (f(x1) / derivative_of_f(x1));
    }
}
void secant_method(float x1, float x2)
{
    printf("\n");
    int i = 0;
    float x3, xm, c;
    if (f(x1) * f(x2) < 0)
    {
        do
        {
            i++;
            x3 = (x2 - ((f(x2) * (x2 - x1)) / (f(x2) - f(x1))));

            c = f(x1) * f(x3);

            x1 = x2;
            x2 = x3;
            if (c == 0)
                break;

            xm = (x2 - ((f(x2) * (x2 - x1)) / (f(x2) - f(x1))));
            printf("%d iteration x is %f ,f(x) is %f and error is %f \n", i, x3, f(x3), fabs(xm - x3));
        } while (fabs(xm - x3) >= error && i < 100);
    }
    else
    {
        printf("Roots does not exist in given interval choose another");
    }
}
int main()
{
    int choice = 0;
    printf("Enter 1 for netwon's method \nEnter 2 for secant method\n");
    printf("enter your choice: \n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        float guess;
        printf("Enter Sample guess :");
        scanf("%f", &guess);
        netwon_method(guess);
    }
    else if (choice == 2)
    {
        float guess1, guess2;
        printf("Enter two guess no :");
        scanf("%f %f \n", &guess1, &guess2);
        secant_method(guess1, guess2);
    }
    else
    {
        printf("You have entered wrong choice");
    }
    return 0;
}