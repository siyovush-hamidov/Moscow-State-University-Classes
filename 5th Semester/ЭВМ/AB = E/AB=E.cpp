#include <iostream>
#include <windows.h>
#include <iomanip>
#include <limits>
#include <math.h>

using namespace std;

void print_the_equation(double *A, double *B, int n);
void fill_the_matrix_at_random(double *A, int n);
int fill_the_matrix_with_keyboard(double *A, int n);
void inversion(double *A, double *B, int n);
void matrix_multiplication(double *A, double *B, double *C, int n);

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int n, i, j, method_of_input, result_of_gauss_jordan_function;
    double *A, *B, *A_temp, *B_temp, *C;
    bool running_switch_case_for_method_of_input = true;

    cout << "Введите размер матрицы (N x N): ";
    cin >> n;
    if (n <= 1)
    {
        cout << "Неверный размер матрицы! Размер должен быть больше единицы.\n";
        return -1;
    }

    if (!(A = (double *)malloc((n * n) * sizeof(double))))
    {
        cout << "Ошибка выделения памяти для матрицы A!\n";
        return -2;
    }

    if(!(A_temp = (double *)malloc((n * n) * sizeof(double))))
   {
      cout << "Ошибка выделения памяти для A_temp!";
      return -8;
   }

    if (!(B = (double *)malloc((n * n) * sizeof(double))))
    {
        cout << "Ошибка выделения памяти для матрицы B!\n";
        return -3;
    }

    if (!(B_temp = (double *)malloc((n * n) * sizeof(double))))
    {
        cout << "Ошибка выделения памяти для матрицы B_temp!\n";
        return -3;
    }

    if (!(C = (double *)malloc((n * n) * sizeof(double))))
    {
        cout << "Ошибка выделения памяти для матрицы C!\n";
        return -3;
    }

    
    for (i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            if (i == j)
            {
                B[i * n + j] = 1.0;
            }
            else
                B[i * n + j] = 0.0;

    do
    {
        cout << "Выберите метод ввода.\nДоступные методы: (1 - Рандом), (2 - Через клавиатуру)\nВаш выбор: ";
        cin >> method_of_input;
        switch (method_of_input)
        {
        case 1:
            fill_the_matrix_at_random(A, n);
            cout << "Матрица " << n << " на " << n << " успешно заполнена случайными числами.\n";
            running_switch_case_for_method_of_input = false;
            break;
        case 2:
            if (fill_the_matrix_with_keyboard(A, n))
            {
                free(A);
                return -5;
            }
            cout << "Матрица " << n << " на " << n << " успешно заполнена.\n";
            running_switch_case_for_method_of_input = false;
            break;
        default:
            cout << "Неверный метод ввода! Попробуйте ещё раз.\n\n";
        }
    } while (running_switch_case_for_method_of_input);

    cout << "Матрица A и Матрица B: \n";
    print_the_equation(A, B, n);
    cout << "\n";

    for(i = 0; i < n * n; i++)
    {
        A_temp[i] = A[i];
        B_temp[i] = B[i];
    }

    inversion(A, B, n);
    cout << "Матрица A и Матрица B после функции Gauss-Jordan: \n";
    print_the_equation(A, B, n);
    cout << '\n';
    cout << "Результат умножения A(после функции) и А(исходной) и исходная матрица А: \n";
    matrix_multiplication(A, A_temp, C, n);
    print_the_equation(C, A_temp, n);
    cout << "\n";
}

void print_row(double *A, double *B, int n, int i)
{
    if (n >= 10)
    {
        cout << fixed;
        for (int j = 0; j < 5; j++)
            cout << setw(8) << setprecision(3) << A[i * n + j];
        cout << setw(8) << "..." << setw(8) << setprecision(3) << A[i * n + n - 1] << " | ";
        for (int j = 0; j < 5; j++)
            cout << setw(8) << setprecision(3) << B[i * n + j];
        cout << setw(8) << "..." << setw(8) << setprecision(3) << B[i * n + n - 1] << "\n";
    }
    else
    {
        for (int j = 0; j < n; j++)
            cout << setw(8) << setprecision(3) << A[i * n + j];
        cout << " | ";
        for (int j = 0; j < n; j++)
            cout << setw(8) << setprecision(3) << B[i * n + j];
        cout << '\n';
    }
}

void print_the_equation(double *A, double *B, int n)
{
    if (n >= 10)
    {
        for (int i = 0; i < 5; i++)
            print_row(A, B, n, i);
        cout << '\n';
        for (int i = 0; i < 7; i++)
            cout << setw(8) << "...";
            cout << " | "; 
        for (int i = 0; i < 7; i++)
            cout << setw(8) << "...";
        cout << '\n'
             << '\n';
        print_row(A, B, n, n - 1);
        cout << '\n';
    }
    else
        for (int i = 0; i < n; i++)
            print_row(A, B, n, i);
    cout << '\n';
}


void fill_the_matrix_at_random(double *A, int n)
{
    int i;
    for (i = 0; i < n * n; i++)
    {
        A[i] = double(rand() % 10000) / double(1000);
    }
}

int fill_the_matrix_with_keyboard(double *A, int n)
{
    int i;
    cout << "Необходимое количество элементов: " << n * n << '\n';
    for (i = 0; i < n * n; i++)
    {
        cin >> A[i];
        if (cin.fail())
        {
            cout << "Неверный ввод!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return -1;
        }
    }
    return 0;
}

void inversion(double *A, double *B, int n)
{
    int i, j, k;
    double temp;

    for(k = 0; k < n; k++)
    {
        temp = A[k * n + k];

        for(j = 0; j < n; j++)
        {
            A[k * n + j] /= temp;
            B[k * n + j] /= temp;
        }
        
        print_the_equation(A, B, n);

        for(i = k + 1; i < n; i++)
        {
            temp = A[i * n + k];

            for(j = 0; j < n; j++)
            {
                A[i * n + j] -= A[k * n + j] * temp;
                B[i * n + j] -= B[k * n + j] * temp;
            }
        }
    }

    for(k = n - 1; k >= 0; k--)
    {
        for(i = k; i < n; i++)
        {
            temp = A[i * n + k];

            for(j = 0; j < n; j++)
            {
                A[i * n + j] -= A[k * n + j] * temp;
                B[i * n + j] -= B[k * n + j] * temp;
            }
        }
        print_the_equation(A, B, n);
    }


    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            A[i * n + j] = B[i * n + j];
}

void matrix_multiplication(double *A, double *B, double *C, int n)
{
    int i, j, k;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            C[i * n + j] = 0;
            for(k = 0; k < n; k++)
            {
                C[i * n + j] += A[i * n + k] * B[k * n + j];
            }
        }
    }
}
