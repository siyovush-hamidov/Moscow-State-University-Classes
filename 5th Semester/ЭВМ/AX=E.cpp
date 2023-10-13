#include <iostream>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include <math.h>
#include <limits>

using namespace std;

void print_the_equation(double *A, double *B, int n);
void fill_the_matrix_at_random(double *A, int n);
int fill_the_matrix_with_keyboard(double *A, int n);

int main()
{

    SetConsoleOutputCP(CP_UTF8);

    int n, result_of_the_equation, method_of_input, i, j;
    double *A, *B, variable_for_time, *A_temp, *B_temp;
    bool running_switch_case_for_method_of_input = true;

    cout << "Введите размер матрицы (N x N): ";
    cin >> n;

    if (n <= 0 || n == 1)
    {
        cout << "Неверный размер матрицы! Размер должен быть больше единицы.\n";
        return -1;
    }

    if (!(A = (double *)malloc((n * n + n * n) * sizeof(double))))
   {
      cout << "Ошибка выделения памяти для матрицы!\n";
      return -2;
   }
    
    B = A + n * n;
    
    do
   {
      cout << "Выберите метод ввода.\nДоступные методы: (1 - Рандом), (2 - Через клавиатуру)\nВаш выбор: ";
      cin >> method_of_input;
      switch (method_of_input)
      {
      case 1:
         fill_the_matrix_at_random(A, n);
         cout << "Матрица " << n << " на " << n << " успешно заполнены случайными числами.\n";
         running_switch_case_for_method_of_input = false;
         break;
      case 2:
         if (fill_the_matrix_with_keyboard(A, n))
        {
            free(A);
            return -5;
        }
        cout << "Матрица " << n << " на " << n << " успешно заполнены.\n";
        running_switch_case_for_method_of_input = false;
        break;
      default:
         cout << "Неверный метод ввода! Попробуйте ещё раз.\n\n";
      }
   } while (running_switch_case_for_method_of_input);

   for (i = 0; i < n; i++)
      for (B[i] = 0., j = 0; j < n; j++)
         B[i] += (j % 2 ? -1. : 1.) * A[i * n + j];

   cout << "Матрица A и вектор b: \n";
   print_the_equation(A, B, n);

   if(!(A_temp = (double *)malloc((n + n * n) * sizeof(double))))
   {
      cout << "Ошибка выделения памяти для A_temp!";
      return -8;
   }

}

void print_the_system(double *A, double *B, int n)
{

}