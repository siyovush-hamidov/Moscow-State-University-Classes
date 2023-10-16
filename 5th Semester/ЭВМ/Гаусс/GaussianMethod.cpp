///////////////////////////////////////////////////////
// Сообщение для преподавателя.
// Здравствуйте! При написании кода, я обычно делаю подробные инструкции того, что написано. Это делается для глубокого понимания происходящего.
// Обычно я действую по методу Сократа, чтобы полноценно представлять картину.
///////////////////////////////////////////////////////

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
// #define MAX_PRINT 6
// #define MAX_PRINT_VECTOR 700

///////////////////////////////////////////////////////
// Что такое #define и что такое макросы в C++?

// `#define` - это директива препроцессора в C++, которая используется для создания макросов. Макросы - это специальные конструкции, которые заменяют указанный текст на другой текст перед компиляцией.
// Вот пример использования `#define`: #define PI 3.14159 | В этом примере, `PI` является макросом, и каждый раз, когда компилятор встречает `PI` в коде, он заменяет его на `3.14159`. `#define` часто используется для определения констант, которые используются во всем коде. Однако, важно отметить, что `#define` не является типизированным, что может привести к ошибкам. Вместо этого, в C++ рекомендуется использовать `const` или `constexpr` для определения констант.
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
// Почему define менее предпочтителен чем constexpr или const?

// `#define`, `const` и `constexpr` в C++ используются для разных целей и имеют разные свойства:
// 1. `#define`¹³: Это директива препроцессора, которая используется для создания макросов. Макросы - это просто текстовые подстановки, которые происходят во время фазы препроцессора, до фактической компиляции. Они не типизированы, что может привести к ошибкам. Они могут быть использованы для определения констант или функций, которые вы хотите использовать в своем коде.
// 2. `const`²: Это ключевое слово, которое используется для объявления объекта как константы. Это означает, что после инициализации значение этого объекта не изменится. Это помогает компилятору оптимизировать код и предотвращает написание кода, который изменяет объекты, которые не должны быть изменены после инициализации.
// 3. `constexpr`¹²: Это ключевое слово, которое используется для объявления объекта или функции, пригодной для использования в константных выражениях. `constexpr` происходит во время фактического разбора и он типизирован. Это означает, что компилятор проверяет типы во время компиляции, что делает его безопаснее, чем `#define`.
// Важно отметить, что `constexpr` в C++11 подразумевает `const`, в то время как в C++14 и C++17 это уже не так².
// В общем, использование `const` и `constexpr` предпочтительнее, поскольку они обеспечивают проверку типов и большую безопасность по сравнению с `#define`. Однако `#define` все еще может быть полезен в некоторых случаях, например, для условной компиляции¹.
// Source: Conversation with Bing, 10/2/2023
// (1) c++ - Difference between `constexpr` and `#define` - Stack Overflow. https://stackoverflow.com/questions/66176642/difference-between-constexpr-and-define.
// (2) Difference between #define and const in C? - GeeksforGeeks. https://www.geeksforgeeks.org/diffference-define-const-c/.
// (3) What is the difference between constexpr and const?. https://stackoverflow.com/questions/14116003/whats-the-difference-between-constexpr-and-const.
///////////////////////////////////////////////////////

constexpr int MAX_PRINT = 6;
constexpr int MAX_PRINT_VECTOR = 700;

using namespace std;

void print_matrix (double *A, int n);
void print_system(double *A, double *b, int n );
int gauss (double *A, double *b, int n );
void print_vector(double *b, int n);
int fill_matr_keyboard(double *A, int n);
int fill_matr_file(double *A, int n);
void fill_matr_func(double *A, int n);
void fill_matr_rand(double *A, int n);
double calc_acc(double *A_saved, double *b_saved, double *b, int n);
void inversed_matrix(double *A, int n, double *A_inv);

int main()
{
    int n, i, j, res;
    cout << "Enter the size of the matrix: ";
    cin >> n;
    double *A, *b, *A_saved, *b_saved, t, *A_inv;

    if(n == 1)
    {
        cout << "Inappropriate n!" << endl;
        return -1;
    }
    if(n <= 0)
    {
        cout << "The size must be greater than 1." << endl;
        return -2;
    }
    ///////////////////////////////////////////////////////
    // Зачем использовать различные return?

    // Автор использует разные return в коде для обозначения различных ошибок. Каждое уникальное значение return соответствует определенной ошибке. Это позволяет программе или другому коду, который вызывает эту функцию, определить, какая именно ошибка произошла, основываясь на возвращаемом значении.
    ///////////////////////////////////////////////////////

    if(!(A=(double *)malloc((n + n * n) * sizeof(double))))
    {
        cout << "Trying to allocate too much space!" << endl;
        return -3;
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

    b = A + n * n;

    printf("Enter an input type: (1 - from keyboard, 2 - via file, 3 - by function, 4 - at random): ");
    if(!(scanf("%d", &i) == 1))
    {
        printf("Wrong input type!\n");
        free(A);
        return -4;
    }
    ///////////////////////////////////////////////////////
    // Что за конструкция "%d"?

    // В языке программирования C++ конструкция "%d" называется **спецификатором формата**. Спецификаторы формата используются в функциях ввода-вывода, таких как `printf` и `scanf`, для определения типа данных, который будет выводиться или считываться. Вот некоторые основные спецификаторы формата:

    // - `%d` или `%i`: Десятичное целое число¹.
    // - `%u`: Беззнаковое десятичное целое число¹.
    // - `%f`, `%F`: Десятичное число с плавающей точкой¹.
    // - `%e`, `%E`: Число с плавающей точкой в научной нотации¹.
    // - `%c`: Символ¹.
    // - `%s`: Строка символов¹.
    // - `%p`: Адрес указателя¹.
    // - `%%`: Символ процента¹.

    // Каждый спецификатор формата может быть дополнен различными флагами и параметрами для управления шириной поля, точностью и другими аспектами форматирования¹.

    // Источник: беседа с Bing, 03.10.2023
    // (1) printf - C++ Users. https://cplusplus.com/reference/cstdio/printf/.
    // (2) std::printf, std::fprintf, std::sprintf, std::snprintf - Reference. https://en.cppreference.com/w/cpp/io/c/fprintf.
    // (3) scanf - C++ Users. https://cplusplus.com/reference/cstdio/scanf/.
    // (4) Format Specifiers in C/C++ - RAD Studio. https://docwiki.embarcadero.com/RADStudio/Sydney/en/Format_Specifiers_in_C/C++.
    ///////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // Почему в if(!(scanf("%d", &i) == 1)) стоит адрес &i, а не просто i?

    // В языке программирования C и C++ символ `&` перед переменной используется для получения адреса этой переменной в памяти. Это называется **адресной операцией**.
    // В контексте функции `scanf`, `&i` используется, чтобы `scanf` мог записать введенное пользователем значение непосредственно в переменную `i`. Это возможно, потому что `scanf` теперь знает адрес переменной `i` в памяти и может изменить значение, хранящееся по этому адресу.
    // Если бы мы передали просто `i` (без `&`), `scanf` получил бы значение `i`, а не его адрес. Это означает, что `scanf` не смог бы изменить исходное значение `i`.
    ///////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////
    // `scanf` и `printf` являются функциями стандартной библиотеки C, в то время как `cin` и `cout` являются частью стандартной библиотеки C++. Вот некоторые ключевые различия:

    // - **Производительность**: `scanf` и `printf` обычно работают быстрее, чем `cin` и `cout`. Однако, можно увеличить скорость `cin` и `cout`, отключив синхронизацию с библиотекой C с помощью команды `std::ios_base::sync_with_stdio(false)`.

    // - **Безопасность типов**: `cin` и `cout` обеспечивают безопасность типов, что означает, что компилятор проверяет соответствие типов во время компиляции. С другой стороны, `scanf` и `printf` не обеспечивают безопасность типов, и ошибки типов могут быть обнаружены только во время выполнения.

    // - **Удобство использования**: `cin` и `cout` обычно считаются более удобными для использования, поскольку они поддерживают перегрузку операторов и могут легко работать с пользовательскими типами данных.

    // В целом, выбор между `scanf`/`printf` и `cin`/`cout` зависит от ваших потребностей. Если вам нужна высокая производительность и вы готовы тщательно проверять типы, `scanf` и `printf` могут быть хорошим выбором. Если вы предпочитаете безопасность типов и удобство использования, `cin` и `cout` могут быть лучшим выбором.
    ///////////////////////////////////////////////////////
    
    ///////////////////////////////////////////////////////
    // Зачем использовать free()?

    // Строка `free(A)` в коде на языке C или C++ используется для освобождения памяти, которую ранее занимал массив `A`. Когда вы создаете динамический массив с помощью функций, таких как `malloc`, `calloc` или `new`, операционная система выделяет блок памяти для этого массива. Эта память остается занятой, пока вы явно не освободите ее.

    // Если вы не освободите эту память, когда она вам больше не нужна, это может привести к утечке памяти - состоянию, когда ваша программа занимает все больше и больше памяти, но не возвращает ее обратно в систему. Утечки памяти могут замедлить вашу программу и в конечном итоге привести к ее аварийному завершению.

    // Таким образом, `free(A)` служит для предотвращения утечек памяти, корректно освобождая память, которую больше не использует ваша программа. Однако следует быть осторожным при использовании `free`: если вы попытаетесь освободить память, которая уже была освобождена, или память, которая не была выделена с помощью `malloc`, `calloc` или `new`, это может привести к ошибкам выполнения.
    ///////////////////////////////////////////////////////

    printf("Your choise is: %d\n", i);
    switch (i)
    {
    case 1:
        if(fill_matr_keyboard(A,n))
        {
            free(A);
            return -5;
        }
        break;
    case 2:
        if(fill_matr_file(A,n))
        {
            free(A);
            return -7;
        }
        break;
    case 3:
        fill_matr_func(A,n);
        break;
    case 4:
        fill_matr_rand(A,n);
        break;
    default:
        break;
    }

    for(i = 0; i < n; i++)
        for(b[i] = 0., j = 0; j < n; j++)
            b[i] += (j%2 ? -1. : 1.) * A[i * n + j];
    cout << "Matrix A:" << endl;
    print_system(A,b,n);

    if(!(A_saved=(double *)malloc((n+n*n)*sizeof(double)))) { 
        cout<<"Not enough space!"<<endl;
        return -99;
    }
    b_saved=A_saved+n*n;
    for (i=0; i<n*n; i++)
        A_saved[i]=A[i];
    for (j=0; j<n; j++)
        b_saved[j] = b[j];

    t=clock();
    res=gauss(A,b,n);
    t=clock()-t;
    if(res<0) {
        printf("Error! Result %d, can't divide by 0\n");
        free(A);
        return -4;
    }
    cout<<"Answer x:"<<endl;
    print_vector(b,n);

    cout<<endl;
    printf("Gauss time: %.2lf\n",t/CLOCKS_PER_SEC);
    printf("||Ax-b||= %e\n",calc_acc(A_saved, b_saved, b, n));
    free(A);

    A_inv = (double*) malloc(n * n * sizeof(double));

    inversed_matrix(A, n, A_inv);

    return 0;
}
    ///////////////////////////////////////////////////////
void print_matrix (double *A, int n) {
    int i, j;
    for (i=0; i<(n<MAX_PRINT?n:MAX_PRINT); i++) {
        for (j=0; j<(n<MAX_PRINT?n:MAX_PRINT); j++)
            printf("%8.2f", A[i*n+j]);
        cout<<endl;
    }
}

void print_vector(double *b, int n) {
    int i;
    for (i=0; i<(n<MAX_PRINT_VECTOR?n:MAX_PRINT_VECTOR); i++) {
        printf("%8.2f", b[i]);
        cout<<endl;
    }
}

void print_system (double *A, double *b, int n) {
    int i, j;
    for (i=0; i<(n<MAX_PRINT?n:MAX_PRINT); i++) {
        for (j=0; j<n; j++)
            printf("%8.2f", A[i*n+j]);
        printf(       "%8.2f", b[i]);
        cout<<endl;
    }
}

int gauss (double *A, double *b, int n) {
    int i, j, k, maxx, num_max;
    double tmp, *p, *q;

    for (i=0; i<n; i++){

        if (fabs(A[i*n+i]) < 1.e-18)
        return -(i+1);
        tmp = 1./A[i*n+i];
        for (j=i+1;j<n;j++)
            A[i*n+j]*=tmp;
        b[i]*=tmp;

    for (j=i+1; j<n; j++) {
        for (k=i+1, tmp=A[j*n+i], p=A+j*n+i+1, q=A+i*n+i+1; k<n;k++)
            *(p++)-=*(q++)*tmp;
        b[j]-=b[i]*A[j*n+i];
    }
    }

    for (i=n-1; i>0; i--) {
        for (j=i-1; j>=0; j--)
            b[j]-=b[i]*A[j*n+i];
    }
    return 0;
}

double calc_acc(double *A, double *b, double *x, int n)
{
    double sum=0., norma=0.;
    int i, j;
    for (i=0; i<n; i++)
    {
        for (sum=0., j=0; j<n; j++)
            sum+=A[i*n+j]*x[j];
        sum-=b[i];
        norma+=sum*sum;
    }

    return sqrt(norma);
}

int fill_matr_keyboard(double *A, int n)
{
    int i;
    printf("Input n*n numbers:\n");
    for (i=0; i<n*n; i++)
        if (!(scanf("%lf", A+i)==1)) {
            cout<<"Wrong input!"<<endl;
            return -1;
        }
    return 0;
}

int fill_matr_file(double *A, int n)
{
    int i;
    FILE *fr=fopen("data.txt", "r");
    if (!fr)
        return -1;

    for (i=0; i<n*n; i++)
        if (!(fscanf(fr, "%lf", A+i)==1)) {
            cout<<"Wrong data in file!"<<endl;
            fclose(fr);
            return -1;
        }
    fclose(fr);
    return 0;
}
void fill_matr_func(double *A, int n)
{
    int i, j;
        for (i=0; i<n; i++) {
                for (j=0; j<n; j++)
                    A[i*n+j]=1./(i+j+1);
        }

}
void fill_matr_rand(double *A, int n)
{
    int i;
    srand(n);
    for (i=0; i<n*n; i++) {
        A[i]=(rand()%2?1.:-1.)*(double)(rand()%1000) / ((rand()%1000)+1);
    }
    return;
}
void inversed_matrix(double *A, int n, double *A_inv)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            A_inv[i * n + j] = (i == j) ? 1.0 : 0.0;
        }
    }
    for(int i = 0; i < n; i++)
    {
        double max_element = abs(A[i * n + i]);
        int max_row = i;
        for(int k = i + 1; k < n; k++)
        {
            if(abs(A[k * n + i]) > max_element)
            {
                max_element = abs(A[k * n + i]);
                max_row = k;
            }
        }
        for(int k = i; k < n; k++)
        {
            double temp = A[max_row * n + k];
            A[max_row * n + k] = A[i * n + k];
            A[i * n + k] = temp;

            temp = A_inv[max_row * n + k];
            A_inv[max_row * n + k] = A_inv[i * n + k];
            A_inv[i * n + k] = temp;
        }
        double pivot = A[i * n + i];
        if(pivot == 0)
        {
            printf("Матрица не обращается в обратную\n");
            return;
        }
        for(int k = 0; k < n; k++)
        {
            A[i * n + k] /= pivot;
            A_inv[i * n + k] /= pivot;
        }
        for(int k = 0; k < n; k++)
        {
            if(k != i)
            {
                double scale = A[k * n + i];
                for(int j = 0; j < n; j++)
                {
                    A[k * n + j] -= scale * A[i * n + j];
                    A_inv[k * n + j] -= scale * A_inv[i * n + j];
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << A_inv[i * n + j] << ' ';
        }
        cout << '\n';
    }
}
