#include <iostream>
#include <windows.h>
#include <iomanip>
#include <limits>
#include <math.h>

using namespace std;

void print_row(double *A, double *X, int n, int i);
void print_the_equation(double *A, double *X, int n);
void print_the_matrix(double *A, int n);
int fill_the_matrix_with_keyboard(double *A, int n);
void fill_the_matrix_at_random(double *A, int n);
int fill_the_matrix_from_file(double *A, int n);
void fill_the_matrix_by_function(double *A, int n);
void main_element(double *A, int n);
int gauss_jordan(double *A, double *X, int n);
void matrix_multiplication(double *A, double *X, double *C, int n);
double accuracy_of_the_calculations(double *C, int n);

int main()
{
   // srand(time(0));
   SetConsoleOutputCP(CP_UTF8);

   int n, i, j, method_of_input, result_of_gauss_jordan_function;
   double *A, *X, *A_temp, *X_temp, *C, variable_for_time;
   bool running_switch_case_for_method_of_input = true;

   cout << "Введите размер матрицы (N x N): ";
   cin >> n;
   if (n <= 1)
   {
      cout << "Неверный размер матрицы! Размер должен быть больше единицы.\n";
      return -1;
   }

   if (!(A = (double *)malloc((n * n + n * n) * sizeof(double))))
   {
      cout << "Ошибка выделения памяти для матрицы A!\n";
      return -2;
   }

   if (!(A_temp = (double *)malloc((n * n + n * n) * sizeof(double))))
   {
      cout << "Ошибка выделения памяти для A_temp!";
      return -8;
   }

   X = A + n * n;

   X_temp = A_temp + n * n;

   if (!(C = (double *)malloc((n * n) * sizeof(double))))
   {
      cout << "Ошибка выделения памяти для матрицы C!\n";
      return -3;
   }

   for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
         if (i == j)
         {
            X[i * n + j] = 1.0;
         }
         else
            X[i * n + j] = 0.0;

   do
   {
      cout << "Выберите метод ввода.\nДоступные методы: (1 - Рандом), (2 - Через клавиатуру), (3 - По функции), (4 - Через файл)\nВаш выбор: ";
      cin >> method_of_input;
      switch (method_of_input)
      {
      case 1:
         fill_the_matrix_at_random(A, n);
         running_switch_case_for_method_of_input = false;
         break;
      case 2:
         if (fill_the_matrix_with_keyboard(A, n))
         {
            free(A);
            running_switch_case_for_method_of_input = false;
            return -5;
         }
      case 3:
         fill_the_matrix_by_function(A, n);
         running_switch_case_for_method_of_input = false;
         break;
      case 4:
         fill_the_matrix_from_file(A, n);
         running_switch_case_for_method_of_input = false;
         break;

      default:
         cout << "Неверный метод ввода! Попробуйте ещё раз.\n\n";
      }
   } while (running_switch_case_for_method_of_input);

   cout << "Матрица " << n << " на " << n << " успешно заполнена.\n";

   cout << "Матрица A и Матрица X: \n";
   print_the_equation(A, X, n);
   cout << "\n";

   for (i = 0; i < n * n; i++)
   {
      A_temp[i] = A[i];
      X_temp[i] = X[i];
   }

   variable_for_time = clock();
   gauss_jordan(A, X, n);
   variable_for_time = clock() - variable_for_time;

   cout << "Матрица A и Матрица X после функции Gauss-Jordan: \n";
   print_the_equation(A, X, n);
   cout << '\n';
   cout << "Результат умножения А(исходная) * X(после Gauss-Jordan): \n\n";
   main_element(A_temp, n);
   matrix_multiplication(A_temp, X, C, n);
   print_the_matrix(C, n);
   cout << "\nВремя работы программы: " << setw(6) << setprecision(5) << variable_for_time / CLOCKS_PER_SEC << '\n';
   cout << scientific << setprecision(6) << "Норма ||AX = E|| = " << accuracy_of_the_calculations(C, n) << '\n';
   cout << "\n";
}

void print_row(double *A, double *X, int n, int i)
{
   double epsilon = 1e-10;

   if (n >= 10)
   {
      cout << fixed;
      for (int j = 0; j < 5; j++)
         cout << setw(8) << setprecision(3) << (fabs(A[i * n + j]) < epsilon ? 0 : A[i * n + j]);
      cout << setw(8) << "..." << setw(8) << setprecision(3) << (fabs(A[i * n + n - 1]) < epsilon ? 0 : A[i * n + n - 1]) << " | ";
      for (int j = 0; j < 5; j++)
         cout << setw(8) << setprecision(3) << (fabs(X[i * n + j]) < epsilon ? 0 : X[i * n + j]);
      cout << setw(8) << "..." << setw(8) << setprecision(3) << (fabs(X[i * n + n - 1]) < epsilon ? 0 : X[i * n + n - 1]) << "\n";
   }
   else
   {
      for (int j = 0; j < n; j++)
         cout << setw(8) << setprecision(3) << (fabs(A[i * n + j]) < epsilon ? 0 : A[i * n + j]);
      cout << " | ";
      for (int j = 0; j < n; j++)
         cout << setw(8) << setprecision(3) << (fabs(X[i * n + j]) < epsilon ? 0 : X[i * n + j]);
      cout << '\n';
   }
}

void print_the_matrix(double *A, int n)
{
   double epsilon = 1e-10;
   if (n >= 10)
   {
      cout << fixed;
      for (int i = 0; i < 5; i++)
      {
         for (int j = 0; j < 5; j++)
            cout << setw(8) << setprecision(3) << (fabs(A[i * n + j]) < epsilon ? 0 : A[i * n + j]);
         cout << setw(8) << "..." << setw(8) << setprecision(3) << (fabs(A[i * n + n - 1]) < epsilon ? 0 : A[i * n + n - 1]) << '\n';
      }
   }
   else
   {
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
            cout << setw(8) << setprecision(2) << (fabs(A[i * n + j]) < epsilon ? 0 : A[i * n + j]) << ' ';
         cout << '\n';
      }
   }
}

void print_the_equation(double *A, double *X, int n)
{
   if (n >= 10)
   {
      for (int i = 0; i < 5; i++)
         print_row(A, X, n, i);
      cout << '\n';
      for (int i = 0; i < 7; i++)
         cout << setw(8) << "...";
      cout << " | ";
      for (int i = 0; i < 7; i++)
         cout << setw(8) << "...";
      cout << '\n'
           << '\n';
      print_row(A, X, n, n - 1);
      cout << '\n';
   }
   else
      for (int i = 0; i < n; i++)
         print_row(A, X, n, i);
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

void fill_the_matrix_by_function(double *A, int number_of_elements)
{
    int i, j;
        for (i=0; i<number_of_elements; i++) {
                for (j=0; j<number_of_elements; j++)
                    A[i*number_of_elements+j]=1./(i+j+1);
        }

}
int fill_the_matrix_from_file(double *A, int number_of_elements)
{
    int i;
    FILE *fr=fopen("data.txt", "r");
    if (!fr)
        return -1;

    for (i=0; i<number_of_elements*number_of_elements; i++)
        if (!(fscanf(fr, "%lf", A+i)==1)) {
            cout<<"Неверные данные в файле!"<<endl;
            fclose(fr);
            return -1;
        }
    fclose(fr);
    return 0;
}

void main_element(double *A, int n)
{
   int i, j, k, max_row;
   double temp, max_element;

   for (i = 0; i < n; i++)
   {
      max_element = A[i * n + i];
      max_row = i;
      for (j = i + 1; j < n; j++)
      {
         if (fabs(max_element) < fabs(A[j * n + i]))
         {
            max_element = fabs(A[j * n + i]);
            max_row = j;
         }
      }

      if (fabs(max_element) < 1.e-20)
      {
         cout << "Матрица необратима!\n";
         return;
      }

      for (j = i; j < n; j++)
      {
         temp = A[i * n + j];
         A[i * n + j] = A[max_row * n + j];
         A[max_row * n + j] = temp;
      }
   }
}

int gauss_jordan(double *A, double *X, int n)
{
   // 1. Создайте единичную матрицу того же размера, что и ваша исходная матрица `A`. Это будет вашей матрицей `X`.
   // 2. Примените метод Гаусса-Жордана к матрице `A`, выполняя те же операции над матрицей `X`. Вот подробные шаги:
   //    - Пройдите по каждой строке `i` от `0` до `n-1` (где `n` - это размер матрицы).
   //    - Найдите строку с наибольшим абсолютным значением элемента в столбце `i` (это называется выбором главного элемента по столбцу). Поменяйте местами эту строку с текущей строкой `i`.
   //    - Для каждой строки ниже строки `i`, вычтите из нее строку `i`, умноженную на коэффициент, равный `A[j][i] / A[i][i]`, где `j` - это номер строки. Выполните те же операции для матрицы `X`.
   int i, j, k, max_row;
   double temp, max_element;

   main_element(A, n);

   // print_the_equation(A,X,n);

   for (i = 0; i < n; i++)
   {
      // cout << "Выбрали главный элемент\n";
      // print_the_equation(A,X,n);

      temp = 1. / A[i * n + i];

      for (j = i; j < n; j++)
         A[i * n + j] *= temp;

      for (j = 0; j < n; j++)
         X[i * n + j] *= temp;
      // cout << "Поделили на первый элемент всю строку\n";
      // print_the_equation(A, X, n);

      for (j = i + 1; j < n; j++)
      {
         temp = A[j * n + i];
         for (k = i; k < n; k++)
            A[j * n + k] -= temp * A[i * n + k];

         for (k = 0; k < n; k++)
            X[j * n + k] -= temp * X[i * n + k];

         // cout << "Сделали так чтобы на следующей строке был 0\n";
         // print_the_equation(A, X, n);
      }
   }
   // 3. Теперь у вас должна быть матрица в виде ступенчатого ряда. Продолжите преобразования, чтобы получить единичную матрицу:
   //    - Пройдите по каждой строке `i` от `n-1` до `0`.
   //    - Для каждой строки выше строки `i`, вычтите из нее строку `i`, умноженную на коэффициент, равный `A[j][i] / A[i][i]`, где `j` - это номер строки. Выполните те же операции для матрицы `X`.
   for (i = n - 1; i >= 0; i--)
   {
      for (j = i - 1; j >= 0; j--)
      {
         temp = A[j * n + i];
         for (k = 0; k < n; k++)
         {
            A[j * n + k] -= temp * A[i * n + k];
            X[j * n + k] -= temp * X[i * n + k];
         }
         // cout << "Поделили на последний элемент всю строку\n";
         // print_the_equation(A, X, n);
      }
   }

   // 4. В конце у вас должна получиться единичная матрица из исходной матрицы `A` и обратная матрица из единичной матрицы `X`.
   // 5. Проверьте свои вычисления, умножив исходную матрицу на найденную обратную. Если все сделано правильно, результатом должна быть единичная матрица.
   // Удачи в написании кода! Если у вас возникнут вопросы, не стесняйтесь задавать их.
   return 0;
}

void matrix_multiplication(double *A, double *X, double *C, int n)
{
   int i, j, k;
   for (i = 0; i < n * n; i++)
      C[i] = 0.0;
   for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
         for (k = 0; k < n; k++)
            C[i * n + j] += A[i * n + k] * X[k * n + j];
}

double accuracy_of_the_calculations(double *C, int n)
{
   double norma = 0.;
   int i, j, k;

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         norma += C[i * n + j] * C[i * n + j];
      }
   }

   norma = sqrt(norma);

   free(C);

   return fabs(sqrt(n) - norma);
}

// double accuracy_of_the_calculations(double *A, double *X, double *X_temp, int n)
// {
//    double sum = 0., norma = 0.;
//    int i, j, k;
//    for (i = 0; i < n; i++)
//    {
//       for (j = 0; j < n; j++)
//       {
//          for (sum = 0., k = 0; k < n; k++)
//             sum += A[i * n + k] * X_temp[k * n + j];
//          sum -= X[i * n + j];
//          norma += sum * sum;
//       }
//    }
//    return sqrt(norma);
// }

// 0.041    8.47    6.33     6.5    9.17    5.72    1.48    9.36    6.96 |
//  4.46    5.71    8.14    3.28    6.83    9.96   0.491       3    1.94 |
//  4.83    5.44    2.39     4.6     3.9   0.153   0.292    2.38    7.42 |
//  8.72    9.72    9.89    5.45    1.73    4.77    1.54    1.87    9.91 |
//  5.67     6.3    7.04    9.89     8.7    3.81    1.32   0.333    7.67 |
//  4.66    5.14    7.71    8.25    6.87    5.55    7.64    2.66    2.76 |
// 0.037    2.86    8.72    9.74    7.53   0.778    2.32    3.04    2.19 |
//  1.84   0.288   0.106    9.04    8.94    9.26    2.65    7.45    3.81 |
//  5.89    6.73    4.37    5.35    5.01     1.1    4.39    3.55    9.63 |