#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_PRINT 5

using namespace std;

int fill_from_keyboard(double *a, int n);
int fill_from_file(double *a, int n);
void fill_at_random(double *a, int n);
void fill_by_func(double *a, int n);
void fill_b(double *a, double *b, int n);
void print(double *a, double *b, int n);
void print_large(double *a, double *b, int n);
void print_vector(double *, int n);

int main()
{
    int n, init_type, res;

    printf("Gaussian Method\n");
    printf("Enter the order n: ");
    
    if(!(scanf("%d", &n) == 1))
    {
        printf("Wrong n!\n");
        return -1;
    } 

    double *a, *b, *a_saved, *b_saved. err;
    a = (double*)malloc(n * (n + 1) * sizeof(double));

    // 1. What is going on in 89? Benefits. (double*) - для определения типа возвращения. 
    // 2. More information on malloc - возвращает тип void
    // 3. Why different returns? чтобы было понятно какая именно ошибка
    // 4. free() ? Why do we do that? для высвобождения памяти

    if(!a)
    {
        printf("Insufficient memory!\n");
        return -2;
    }

    b = a + n * n;

    printf("Choose a type\n");
    printf("1 - keyboard\n");
    printf("2 - from file \'data.txt\'\n");
    printf("3 - at random\n");
    printf("4 - by function\n");
    
    if(!(scanf("%d", &init_type) == 1))
    {
        printf("Wromg init type!\n");
        free(a);
        return -3;
    }

    // fill the matrix
    
    switch (init_type)
    {
        case 1:
            res = fill_from_keyboard(a,n);
            if(res)
            {
                printf("Fill from keyboard error!\n");
                free(a);
                return -4;
            }
            break;
        case 2:
            res = fill_from_file(a,n);
            if(res)
            {
                printf("Fill from file error!\n");
                free(a);
                return -5;
            }
            break;
        case 3:
            fill_at_random(a,n);
            break;
        case 4:
            fill_by_func(a,n);
            break;
    
        default:
            printf("Wrong init_type!\n");
            free(a);
            return -6;
    }
    fill_b(a,b,n);
    // print A, b
    printf("A and b:\n");
    if(n > MAX_PRINT + 1)
        print_large(a, b, n);
    else
        print(a, b, n);
    // algo
    // print X
    printf("Answer X");
    // check
    err = calc_err(a_saved,b_saved,b,n, err);
    printf("||Ax - b|| =%e\n");

    free(a);
    a = 0;
    return 0;
}

int fill_from_keyboard(double *a, int n)
{
    int i;
    printf("Input n * n = %d real numbers to fill A: ");
    for(int i = 0; i < n * n; i++)
    {
        if(!(scanf("%lf", a + i) == 1))
            return -1;
    }
    return 0;
}

int fill_from_file(double *a, int n)
{
    int i;
    FILE *fr;
    fr = fopen("data.txt", "r");
    if(!fr)
    {
        printf("\'data.txt\' open error!\n");
        return -1;
    }
    for(int i = 0; i < n * n; i++)
    {
        if(!(scanf("%lf", a + i) == 1))
        {
            printf("Incorrect data in \'data.txt\'\n");
            fclose(fr);
            return -2;
        }
    }
    fclose(fr);
    return 0;
}

void fill_at_random(double *a, int n)
{
    int i;
    srand(n);
    for(int i = 0; i < n * n; i++)
    { 
        // (rand()%2?1.:-1.) * () / ((rand() % 100) + 1)
        a[i] = rand() % 100 ;
        return;
    }
}

void fill_by_func(double *a, int n)
{
    int i, j;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a[i * n + j] = 1./ (1 + i + j);
    return;
}

void fill_b(double *a, double *b, int n)
{
    int i, j;
    double sum;
    for(i = 0; i < n; i++)
    {
        for(j = 0, sum = 0.; j < n; j++)      
            sum += (j + 1) * (j%2 ? -1. : 1.) * a[i * n + j];
        b[i] = sum;
    }
    return;
}

void print(double *a, double *b, int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%7.2lf ", a[i * n + j]);
        printf("    %7.2lf\n", b[i]);
    }
    return;
}

void print_large(double *a, double *b, int n)
{
    int i, j;
    for(i = 0; i < MAX_PRINT; i++)
    {
        for(int j = 0; j < MAX_PRINT; j++)
            printf("%7.2lf ", a[i * n + j]);
        printf(" ...%7.2lf    %7.2lf\n", a[i * n + n - 1], b[i]);
    }
    for(j = 0; j < MAX_PRINT + 1; j++)
        printf("........");
    printf("  ...      ........\n");

    for(int i = n - 1, j = 0; j < MAX_PRINT; j++)
            printf("%7.2lf ", a[i * n + j]);
        printf(" ...%7.2lf    %7.2lf\n", a[i * n + n - 1], b[i]);

    return;
}

void print_vector(double *x, int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%.2lf ", x[i]);
    printf("\n");
    return;
}