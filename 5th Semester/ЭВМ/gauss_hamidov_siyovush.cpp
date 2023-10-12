///////////////////////////////////////////////////////

// Сообщение для преподавателя.

// Здравствуйте! При написании кода, я обычно делаю подробные инструкции того, что написано. Это делается для глубокого понимания происходящего. Для этого я использовал чат-бот Microsoft Bing. Очень надеюсь, что это вам не помешает читать код.

// Код алгоритма писал сам, но попросил Bing описать словами алгоритм. Делал по его описанию.
///////////////////////////////////////////////////////

#include <iostream>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include <math.h>
#include <limits>

///////////////////////////////////////////////////////
// Зачем нужна библиотека limits?

// Библиотека `<limits>` в C++ предоставляет класс `std::numeric_limits`, который используется для получения информации о свойствах арифметических типов (целочисленных или с плавающей точкой) на конкретной платформе, для которой компилируется библиотека¹. 

// Это включает в себя такие свойства, как максимальное и минимальное значение, которое может принимать данный тип, а также другие характеристики, такие как количество битов, используемых для представления типа. 

// Например, `std::numeric_limits<int>::max()` вернет наибольшее возможное значение для типа `int`¹. Это полезно, когда вам нужно узнать ограничения типов данных в вашей программе. 

// Важно отметить, что эти значения могут отличаться в зависимости от системы и компилятора².

// Source: Conversation with Bing, 10/12/2023
// (1) std::numeric_limits - cppreference.com. https://en.cppreference.com/w/cpp/types/numeric_limits.
// (2) (limits.h) in C/C++ - GeeksforGeeks. https://www.geeksforgeeks.org/climits-limits-h-cc/.
// (3) numeric_limits - C++ Users. https://cplusplus.com/reference/limits/numeric_limits/.
///////////////////////////////////////////////////////

using namespace std;

void print_row(double *A, double *b, int number_of_elements, int i);
void print_vector(double *b, int number_of_elements);
void print_the_equation(double *A, double *b, int number_of_elements);
int fill_the_matrix_with_keyboard(double *A, int number_of_elements);
void fill_the_matrix_at_random(double *A, int number_of_elements);
double accuracy_of_the_calculations(double *A, double *b, double *x, int number_of_elements);
int gaussian_elimination(double *A, double *b, int number_of_elements);
int gauss_jordan_column(double *A, double *b, int number_of_elements);
int gauss_jordan_row(double *A, double *b, int number_of_elements);

int main()
{
   srand(time(0));
   SetConsoleOutputCP(CP_UTF8);

   int n, result_of_gauss_function, method_of_input, i, j, choice_of_gauss;
   double *A, *b, variable_for_time, *A_temp, *b_temp;
   bool running_switch_case_for_method_of_input = true;

   cout << "Введите размер матрицы (N x N): ";
   cin >> n;

   if (n <= 0 || n == 1)
   {
      cout << "Неверный размер матрицы! Размер должен быть больше единицы.\n";
      return -1;
   }
   ///////////////////////////////////////////////////////
    // Зачем использовать различные return?

    // Автор использует разные return в коде для обозначения различных ошибок. Каждое уникальное значение return соответствует определенной ошибке. Это позволяет программе или другому коду, который вызывает эту функцию, определить, какая именно ошибка произошла, основываясь на возвращаемом значении.
    ///////////////////////////////////////////////////////

   if (!(A = (double *)malloc((n + n * n) * sizeof(double))))
   {
      cout << "Ошибка выделения памяти для матрицы!\n";
      return -2;
   }
    ///////////////////////////////////////////////////////
    // Как работает функция malloc?

    //     Функция `malloc()` в C++ используется для динамического выделения памяти¹. Она принимает один аргумент - количество байтов, которые нужно выделить¹. Функция возвращает указатель на первый байт выделенной памяти¹. Если память не может быть выделена (например, если запрашиваемое количество памяти превышает доступное количество), `malloc()` возвращает нулевой указатель¹.
    // В вашем коде `malloc()` используется для выделения памяти под массив `A` размером `(n + n * n) * sizeof(double)`. Это означает, что выделяется память под `n` элементов типа `double`, а также под квадратную матрицу размером `n * n` элементов типа `double`.
    // Оператор `!` перед вызовом `malloc()` проверяет, была ли память успешно выделена. Если `malloc()` возвращает нулевой указатель (то есть память не может быть выделена), условие `if(!(A=(double *)malloc((n + n * n) * sizeof(double))))` становится истинным, и программа выводит сообщение об ошибке и возвращает `-3`.

    // Source: Conversation with Bing, 10/2/2023
    // (1) C++ malloc() - GeeksforGeeks. https://www.geeksforgeeks.org/cpp-malloc/.
    // (2) c++ - How do malloc() and free() work? - Stack Overflow. https://stackoverflow.com/questions/1119134/how-do-malloc-and-free-work.
    // (3) malloc() in C++ | How malloc() method work in C++ with Sample Code - EDUCBA. https://www.educba.com/malloc-in-c-plus-plus/.
    // (4) Malloc in C++ - Scaler Topics. https://www.scaler.com/topics/malloc-in-cpp/.
    ///////////////////////////////////////////////////////
   if (!(b = (double *)malloc(n * sizeof(double))))
   {
      cout << "Ошибка выделения памяти для вектора!\n";
      return -3;
   }
    ///////////////////////////////////////////////////////
    // В чём отличие между cin, cout и scanf, printf?

    // `cin` и `cout` являются частью стандартной библиотеки C++ и разработаны для бесшовной работы с языком C++, включая такие функции, как объектно-ориентированное программирование и обработка исключений³. В отличие от этого, `printf` и `scanf` являются частью стандартной библиотеки C и не предназначены для естественной работы с языком C++³.
    // Вот некоторые ключевые различия:
    // 1. **Типизация**: `cin` и `cout` используют перегруженные операторы для работы с различными типами данных, в то время как `scanf` и `printf` требуют явного указания типа входных данных¹².
    // 2. **Безопасность**: `cin` и `cout` обеспечивают большую безопасность по сравнению с `scanf` и `printf`, поскольку они предотвращают некоторые типы ошибок, такие как переполнение буфера¹².
    // 3. **Производительность**: По умолчанию, `scanf` может быть быстрее, чем `cin`, потому что `cin` тратит время на синхронизацию с буфером stdio в базовой библиотеке C¹². Однако, можно увеличить скорость `cin`, отключив эту синхронизацию¹².
    // 4. **Совместимость**: `printf` и `scanf` могут быть использованы в коде на C++, но они не полностью интегрированы с функциями C++, такими как классы и объекты³.
    // Важно отметить, что выбор между этими двумя подходами зависит от конкретной задачи и предпочтений программиста.
    
    // Source: Conversation with Bing, 10/11/2023
    // (1) Difference between printf/scanf and cout/cin in C++? - codedamn. https://codedamn.com/news/c/difference-between-printf-scanf-and-cout-cin-in-c.
    // (2) Cin-Cout vs Scanf-Printf - GeeksforGeeks. https://www.geeksforgeeks.org/cincout-vs-scanfprintf/.
    // (3) printf/scanf usage and difference from <iostream> and cout/cin .... https://stackoverflow.com/questions/61716649/printf-scanf-usage-and-difference-from-iostream-and-cout-cin-diffferences-whe.
    // (4) cin/cout-printf/scanf - C++ Forum - C++ Users. https://cplusplus.com/forum/beginner/34165/.
    ///////////////////////////////////////////////////////

   b = A + n * n;

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
    ///////////////////////////////////////////////////////
    // Зачем использовать функцию free()?
    // Функция `free(A)` используется для освобождения памяти, которая была ранее выделена с помощью функции `malloc`, `calloc` или `realloc`. В данном контексте, `A` скорее всего указывает на блок памяти, который был выделен ранее. Если ввод пользователя не является числом (`scanf("%d", &i) == 1` возвращает `false`), то программа выводит сообщение об ошибке, освобождает память и завершает выполнение с кодом ошибки `-4`.

    // Освобождение памяти важно для предотвращения утечек памяти, что может привести к исчерпанию доступной памяти и снижению производительности.
    ///////////////////////////////////////////////////////
        cout << "Матрица " << n << " на " << n << " успешно заполнена.\n";
        running_switch_case_for_method_of_input = false;
        break;
      default:
         cout << "Неверный метод ввода! Попробуйте ещё раз.\n\n";
      }
   } while (running_switch_case_for_method_of_input);

   for (i = 0; i < n; i++)
      for (b[i] = 0., j = 0; j < n; j++)
         b[i] += (j % 2 ? -1. : 1.) * A[i * n + j];

   cout << "Матрица A и вектор b: \n";
   print_the_equation(A, b, n);

   if(!(A_temp = (double *)malloc((n + n * n) * sizeof(double))))
   {
      cout << "Ошибка выделения памяти для A_temp!";
      return -8;
   }

   b_temp = A_temp + n * n;

   for(i = 0; i < n * n; i++)
      A_temp[i] = A[i];
   for(i = 0; i < n; i++)
      b_temp[i] = b[i];

    ///////////////////////////////////////////////////////
    //Что делает функция clock()?

    // Функция `clock()` в C++ возвращает приближенное значение процессорного времени, которое было потрачено на выполнение программы¹²³. Значение, возвращаемое функцией `clock()`, выражается в тактах часов, которые являются единицами времени постоянной, но системно-зависимой длины³. 

    // В данном случае, `t = clock();` сохраняет текущее значение процессорного времени в переменную `t`¹²³. Это может быть полезно для измерения времени выполнения определенного участка кода. Например, вы можете вызвать `clock()` в начале выполнения участка кода, а затем снова вызвать `clock()` после его выполнения и вычесть первое значение из второго, чтобы получить количество тактов часов, потраченных на выполнение этого участка кода¹²³.

    // Чтобы преобразовать значение в секунды, его нужно разделить на макрос `CLOCKS_PER_SEC`¹²³.

    // Source: Conversation with Bing, 10/11/2023
    // (1) C++ clock() - C++ Standard Library - Programiz. https://www.programiz.com/cpp-programming/library-function/ctime/clock.
    // (2) clock() function in C/C++ - GeeksforGeeks. https://www.geeksforgeeks.org/clock-function-in-c-c/.
    // (3) clock - C++ Users. https://cplusplus.com/reference/ctime/clock/.
    ///////////////////////////////////////////////////////

   variable_for_time = clock();

   result_of_gauss_function = gaussian_elimination(A, b, n);
   // result_of_gauss_function = gauss_jordan_column(A, b, n); 
   // result_of_gauss_function = gauss_jordan_row(A, b, n);

   variable_for_time = clock() - variable_for_time;

   if(result_of_gauss_function < 0)
   {
      cout << "Ошибка! Матрица несовместна.";
      free(A);
      return -7;
   }

   cout << "Вектор х:\n";
   print_vector(b, n);

   cout << "Время работы программы: " << setw(6) << setprecision(5) << variable_for_time / CLOCKS_PER_SEC << '\n';
   cout << scientific << setprecision(6) << "Норма ||Ax - b|| = " << accuracy_of_the_calculations(A_temp, b_temp, b, n) << '\n';
   
   free(A);
   return 0;
}

void print_row(double *A, double *b, int number_of_elements, int i)
{
   if (number_of_elements >= 15)
   {
      cout << fixed;
      for (int j = 0; j < 5; j++)
         cout << setw(8) << setprecision(3) << A[i * number_of_elements + j];
      cout << setw(8) << "..." << setw(8) << setprecision(3) << A[i * number_of_elements + number_of_elements] << " | " << setprecision(2) << b[i] << '\n';
   }
   else
   {
      for (int j = 0; j < number_of_elements; j++)
         cout << setw(8) << setprecision(3) << A[i * number_of_elements + j];
      cout << " | " << setprecision(3) << b[i] << '\n';
   }
}

void print_vector(double *b, int number_of_elements)
{
   if (number_of_elements >= 15)
   {
      cout << fixed;
      for (int j = 0; j < 5; j++)
         cout << setw(8) << setprecision(3) << b[j] << '\n';
      cout << '\n'
           << setw(8) << "..."
           << "\n\n"
           << setw(8) << setprecision(3) << b[number_of_elements - 1] << '\n';
   }
   else
   {
      for (int j = 0; j < number_of_elements; j++)
         cout << setw(8) << setprecision(3) << b[j] << '\n';
      cout << '\n';
   }
}

void print_the_equation(double *A, double *b, int number_of_elements)
{
   if (number_of_elements >= 15)
   {
      for (int i = 0; i < 5; i++)
         print_row(A, b, number_of_elements, i);
      cout << '\n';
      for (int i = 0; i < 7; i++)
         cout << setw(8) << "...";
      cout << setw(6) << "...";
      cout << '\n'
           << '\n';
      print_row(A, b, number_of_elements, number_of_elements - 1);
      cout << '\n';
   }
   else
      for (int i = 0; i < number_of_elements; i++)
         print_row(A, b, number_of_elements, i);
   cout << '\n';
}

void fill_the_matrix_at_random(double *A, int number_of_elements)
{
   int i;
   for (i = 0; i < number_of_elements * number_of_elements; i++)
   {
      A[i] = double(rand() % 10000) / double(1000);
   }
}

int fill_the_matrix_with_keyboard(double *A, int number_of_elements)
{
   int i;
   cout << "Необходимое количество элементов: " << number_of_elements * number_of_elements << '\n';
   for(i = 0; i < number_of_elements * number_of_elements; i++)
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

double accuracy_of_the_calculations(double *A, double *b, double *x, int number_of_elements)
{
   double sum = 0., norma = 0.;
   int i, j;
   for(i = 0; i < number_of_elements; i++)
   {
      for(sum = 0., j = 0; j < number_of_elements; j++)
         sum += A[i * number_of_elements + j] * x[j];
      sum -= b[i];
      norma += sum * sum;
   }
   return sqrt(norma);
}

int gaussian_elimination(double *A, double *b, int number_of_elements)
{
   // Шаги алгоритма Гаусса:

   // - Прямой ход: привести матрицу системы к ступенчатому или треугольному виду с помощью элементарных преобразований над строками. Выбирать в качестве главного элемента ненулевой элемент в первом столбце и обнулять все элементы под ним. Повторять этот процесс для всех столбцов, пока не останется матрица нулевого размера или не будет обнаружена несовместность системы.

   int i, j, k;
   double temp;
   for(int i = 0; i < number_of_elements; i++)
   {
      if(fabs(A[i * number_of_elements + i]) < 1.e-20)
         return -(i + 1);

      temp = 1. / A[i * number_of_elements + i];
      for(j = i; j < number_of_elements; j++)
      {
         A[i * number_of_elements + j] *= temp;
      }
      b[i] *= temp;

      // print_the_equation(A,b, number_of_elements);

      for(j = i + 1; j < number_of_elements; j++)
      {
         temp = A[j * number_of_elements + i];
         for(k = i; k < number_of_elements; k++)
         {
            A[j * number_of_elements + k] -= A[i * number_of_elements + k] * temp;
         }
         b[j] -= b[i] * temp;
      }
   }
   // - Обратный ход: выразить все главные переменные через свободные переменные и построить фундаментальную систему решений. Начать с последнего уравнения и вычислить соответствующую главную переменную. Подставить её в предыдущие уравнения и повторить этот процесс для всех главных переменных, поднимаясь по "ступенькам" наверх.
   // cout << A[(number_of_elements - 1) * number_of_elements] << endl;
   // cout << A[(number_of_elements - 1) * number_of_elements - 1] << endl;

   for(i = number_of_elements - 1; i >= 0; i--)
   {
      for(j = i - 1; j >= 0; j--)
      {
         temp = A[j * number_of_elements + i];
         A[j * number_of_elements + i] = 0;
         b[j] -= b[i] * temp;
         // print_the_equation(A,b,number_of_elements);
      }
   }
   return 0;
}

int gauss_jordan_column(double *A, double *b, int number_of_elements)
{
   // Шаги алгоритма Гаусса с выбором главного элемента:
   //    Метод Гаусса с выбором главного элемента, также известный как метод Гаусса-Жордана, включает в себя дополнительные шаги по сравнению с обычным методом Гаусса. Вот шаги алгоритма:
   // 1. **Прямой ход**:
   //    - Начните с первого столбца матрицы.
   //    - Найдите максимальный по модулю элемент в текущем столбце. Это будет ваш главный элемент.
   //    - Поменяйте местами текущую строку и строку, содержащую главный элемент. Это называется частичным выбором.
   //    - Выполните элементарные преобразования над строками, чтобы обнулить все элементы под главным элементом в текущем столбце.
   //    - Повторите этот процесс для всех столбцов, пока не останется матрица нулевого размера или не будет обнаружена несовместность системы.

   int i, j, k, max_row;
   double temp, max_element;
   for(i = 0; i < number_of_elements; i++)
   {
      max_element = A[i * number_of_elements + i];
      max_row = i;
      for(j = i + 1; j < number_of_elements; j++)
      {
         if(fabs(max_element) < fabs(A[j * number_of_elements + i]))
         {
            max_element = A[j * number_of_elements + i];
            max_row = j;
         }
      }

      if(fabs(max_element) < 1.e-20)
         return -(i + 1);

      for(j = i; j < number_of_elements; j++)
      {
         temp = A[i * number_of_elements + j];
         A[i * number_of_elements + j] = A[max_row * number_of_elements + j];
         A[max_row * number_of_elements + j] = temp;
      }

      temp = b[i];
      b[i] = b[max_row];
      b[max_row] = temp;
      
      temp = 1./A[i * number_of_elements + i];

      for(j = i; j < number_of_elements; j++)
      {
         A[i * number_of_elements + j] *= temp;
      }
      b[i] *= temp;

      for(j = i + 1; j < number_of_elements; j++)
      {
         temp = A[j * number_of_elements + i];
         for(k = i; k < number_of_elements; k++)
         {
            A[j * number_of_elements + k] -= temp * A[i * number_of_elements + k]; 
         }
         b[j] -= b[i] * temp;
      }
   }

   // 2. **Обратный ход**:
   //    - Начните с последнего уравнения и вычислите соответствующую главную переменную.
   //    - Подставьте её в предыдущие уравнения и повторите этот процесс для всех главных переменных, поднимаясь по "ступенькам" наверх.

   for(i = number_of_elements - 1; i >= 0; i--)
   {
      for(j = i - 1; j >= 0; j--)
      {
         temp = A[j * number_of_elements + i];
         A[j * number_of_elements + i] = 0;
         b[j] -= b[i] * temp;
      }
   }
   // print_the_equation(A,b,number_of_elements);

   // Этот метод обеспечивает более высокую численную устойчивость по сравнению с обычным методом Гаусса, особенно для больших систем уравнений или систем с плохо обусловленными матрицами. Однако он требует больше вычислительных ресурсов из-за дополнительного шага выбора главного элемента.
   return 0;   
}

int gauss_jordan_row(double *A, double *b, int number_of_elements)
{
   // Шаги алгоритма Гаусса с выбором главного элемента:
   //    Метод Гаусса с выбором главного элемента, также известный как метод Гаусса-Жордана, включает в себя дополнительные шаги по сравнению с обычным методом Гаусса. Вот шаги алгоритма:

   // 1. **Прямой ход**:
   //    - Начните с первой СТРОКИ матрицы.
   //    - Найдите максимальный по модулю элемент в текущей СТРОКЕ. Это будет ваш главный элемент.
   //    - Поменяйте местами текущий столбец и столбец, содержащую главный элемент. Это называется частичным выбором.
   //    - Выполните элементарные преобразования над столбцами, чтобы обнулить все элементы под главным элементом в текущем столбце.
   //    - Повторите этот процесс для всех строк, пока не останется матрица нулевого размера или не будет обнаружена несовместность системы.

   int i, j, k, max_column;
   double temp, max_element;
   for(i = 0; i < number_of_elements; i++)
   {
      max_element = A[i * number_of_elements + i];
      max_column = i;
      for(j = i + 1; j < number_of_elements; j++)
      {
         if(fabs(max_element) < fabs(A[i * number_of_elements + j]))
         {
            max_element = A[i * number_of_elements + j];
            max_column = j;
         }
      }

      if(fabs(max_element) < 1.e-20)
         return -(i + 1);

      for(j = i; j < number_of_elements; j++)
      {
         temp = A[j * number_of_elements + i];
         A[j * number_of_elements + i] = A[j * number_of_elements + max_column];
         A[j * number_of_elements + max_column] = temp;
      }
      print_the_equation(A,b,number_of_elements);

      // temp = b[i];
      // b[i] = b[max_column];
      // b[max_column] = temp;
      
      temp = 1./A[i * number_of_elements + i];

      for(j = i; j < number_of_elements; j++)
      {
         A[i * number_of_elements + j] *= temp;
      }
      b[i] *= temp;

      print_the_equation(A,b,number_of_elements);

      for(j = i + 1; j < number_of_elements; j++)
      {
         temp = A[j * number_of_elements + i];
         for(k = i; k < number_of_elements; k++)
         {
            A[j * number_of_elements + k] -= temp * A[i * number_of_elements + k]; 
         }
         b[j] -= b[i] * temp;
      }
      print_the_equation(A,b,number_of_elements);
   }
   // // 2. **Обратный ход**:
   // //    - Начните с последнего уравнения и вычислите соответствующую главную переменную.
   // //    - Подставьте её в предыдущие уравнения и повторите этот процесс для всех главных переменных, поднимаясь по "ступенькам" наверх.

   for(i = number_of_elements - 1; i >= 0; i--)
   {
      for(j = i - 1; j >= 0; j--)
      {
         temp = A[j * number_of_elements + i];
         A[j * number_of_elements + i] = 0;
         b[j] -= b[i] * temp;
      }
      print_the_equation(A,b,number_of_elements);
   }
   // print_the_equation(A,b,number_of_elements);

   // Этот метод обеспечивает более высокую численную устойчивость по сравнению с обычным методом Гаусса, особенно для больших систем уравнений или систем с плохо обусловленными матрицами. Однако он требует больше вычислительных ресурсов из-за дополнительного шага выбора главного элемента.
   return 0;     
}