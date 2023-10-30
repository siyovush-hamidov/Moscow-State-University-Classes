#include <iostream>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include <math.h>
#include <limits>

using namespace std;

void print_row(double *A, double *X, int n, int i);
void print_the_equation(double *A, double *X, int n);
void print_the_matrix(double *A, int n);
void print_vector(double *v, int n);
int fill_the_matrix_with_keyboard(double *A, int n);
void fill_the_matrix_at_random(double *A, int n);
int fill_the_matrix_from_file(double *A, int n);
void fill_the_matrix_by_function(double *A, int n);
double magnitude_calculator(double *u, int n);
double *unit_vector_calculator(double *u, int n);
double dot_product_calculator(double *u, double *v, int n);
double *vector_scalar_multiplication(double scalar, double *v, int n);
double *vector_projection_calculator(double *v, double *u, int n);
double *vector_subtraction_calculator(double *v, double *u, int n);
double *gram_schmidt_process(double *A, int n);
double *matrix_transpose_calculator(double *A, int n);
void matrix_multiplication(double *A, double *X, double *B, int n);
void qr_factorization(double *A, double *Q, double *R, int n);
double L2_accuracy_of_factorization(double *A, double *Q, double *R, int n);

int main()
{
    // srand(time(0));
    SetConsoleOutputCP(CP_UTF8);

    int n, result_of_invocation_function, method_of_input, i, j;
    double *A, variable_for_time, *Q, *R;
    bool running_switch_case_for_method_of_input = true;

    cout << "Введите размер матрицы (N x N): ";
    cin >> n;

    if (n <= 0 || n == 1)
    {
        cout << "Неверный размер матрицы! Размер должен быть больше единицы.\n";
        return -1;
    }

    if (!(A = (double *)malloc((n * n) * sizeof(double))))
    {
        cout << "Ошибка выделения памяти для матрицы!\n";
        return -2;
    }
    if (!(Q = (double *)malloc((n * n) * sizeof(double))))
    {
        cout << "Ошибка выделения памяти для матрицы!\n";
        return -3;
    }
    if (!(R = (double *)malloc((n * n) * sizeof(double))))
    {
        cout << "Ошибка выделения памяти для матрицы!\n";
        return -4;
    }

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
                return -5;
            }
            running_switch_case_for_method_of_input = false;
            break;
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

    variable_for_time = clock();

    qr_factorization(A, Q, R, n);

    variable_for_time = clock() - variable_for_time;

    cout << "Время работы программы: " << setw(6) << setprecision(3) << variable_for_time / CLOCKS_PER_SEC << '\n';
    cout << scientific << setprecision(6) << "Норма ||A - QR|| = " << L2_accuracy_of_factorization(A, Q, R, n) << '\n';

    free(A);
    free(Q);
    free(R);

    return 0;
}

void print_row(double *A, double *b, int n, int i)
{
    if (n >= 15)
    {
        cout << fixed;
        for (int j = 0; j < 5; j++)
            cout << setw(8) << setprecision(3) << A[i * n + j];
        cout << setw(8) << "..." << setw(8) << setprecision(3) << A[i * n + n - 1] << " | " << setprecision(3) << b[i] << '\n';
    }
    else
    {
        for (int j = 0; j < n; j++)
            cout << setw(8) << setprecision(3) << A[i * n + j];
        cout << " | " << setprecision(3) << b[i] << '\n';
    }
}

void print_vector(double *v, int n)
{
    if (n >= 15)
    {
        cout << fixed;
        for (int j = 0; j < 5; j++)
            cout << setw(8) << setprecision(3) << v[j] << '\n';
        cout << '\n'
             << setw(8) << "..."
             << "\n\n"
             << setw(8) << setprecision(3) << v[n - 1] << '\n';
    }
    else
    {
        for (int j = 0; j < n; j++)
            cout << setw(8) << setprecision(3) << v[j] << '\n';
        cout << '\n';
    }
}

void print_the_matrix(double *A, int n)
{
    cout << '\n';
    double epsilon = 1e-10;
    if (n >= 15)
    {
        cout << fixed;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
                cout << setw(8) << setprecision(3) << (fabs(A[i * n + j]) < epsilon ? 0 : A[i * n + j]);
            cout << setw(8) << "..." << setw(8) << setprecision(3) << (fabs(A[i * n + n - 1]) < epsilon ? 0 : A[i * n + n - 1]) << '\n';
        }

        cout << '\n';
        for (int i = 0; i < 6; i++)
            cout << setw(8) << "...";
        cout << setw(8) << "...";
        cout << "\n\n";

        for (int j = 0; j < 5; j++)
            cout << setw(8) << setprecision(3) << (fabs(A[(n - 1) * n + j]) < epsilon ? 0 : A[(n - 1) * n + j]);
        cout << setw(8) << "..." << setw(8) << setprecision(3) << (fabs(A[(n - 1) * n + n - 1]) < epsilon ? 0 : A[(n - 1) * n + n - 1]) << '\n';
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << setw(8) << setprecision(3) << (fabs(A[i * n + j]) < epsilon ? 0 : A[i * n + j]) << ' ';
            cout << '\n';
        }
    }
    cout << '\n';
}

void print_the_equation(double *A, double *b, int n)
{
    if (n >= 15)
    {
        for (int i = 0; i < 5; i++)
            print_row(A, b, n, i);
        cout << '\n';
        for (int i = 0; i < 7; i++)
            cout << setw(8) << "...";
        cout << setw(6) << "...";
        cout << '\n'
             << '\n';
        print_row(A, b, n, n - 1);
        cout << '\n';
    }
    else
        for (int i = 0; i < n; i++)
            print_row(A, b, n, i);
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

void fill_the_matrix_by_function(double *A, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            A[i * n + j] = 1. / (i + j + 1);
    }
}

int fill_the_matrix_from_file(double *A, int n)
{
    int i;
    FILE *fr = fopen("data.txt", "r");
    if (!fr)
        return -1;

    for (i = 0; i < n * n; i++)
        if (!(fscanf(fr, "%lf", A + i) == 1))
        {
            cout << "Wrong data in file!" << endl;
            fclose(fr);
            return -1;
        }
    fclose(fr);
    return 0;
}

double magnitude_calculator(double *u, int n)
{
    int i;
    double magnitude = 0.0;

    for (i = 0; i < n; i++)
        magnitude += pow(fabs(u[i]), 2);

    return sqrt(magnitude);
}

double *unit_vector_calculator(double *u, int n)
{
    double magnitude = magnitude_calculator(u, n), *unit_vector;
    int i;

    if (magnitude == 0)
    {
        cout << "Ошибка: магнитуда равна нулю!";
        return u;
    }

    if (!(unit_vector = (double *)malloc((n) * sizeof(double))))
    {
        cout << "Ошибка выделения памяти для unit_vector!";
        return u;
    }

    for (i = 0; i < n; i++)
        unit_vector[i] = u[i] / magnitude;
    return unit_vector;
}

double dot_product_calculator(double *u, double *v, int n)
{
    double dot_product = 0.0;
    int i;

    for (i = 0; i < n; i++)
        dot_product += u[i] * v[i];

    return dot_product;
}

double *vector_scalar_multiplication(double scalar, double *v, int n)
{
    int i;
    double *v_s_multiplication;

    if (!(v_s_multiplication = (double *)malloc((n) * sizeof(double))))
    {
        cout << "Ошибка выделения памяти для v_s_multiplication!";
        return v;
    }

    for (i = 0; i < n; i++)
        v_s_multiplication[i] = v[i] * scalar;

    return v_s_multiplication;
}

double *vector_projection_calculator(double *v, double *u, int n)
{
    int i;
    double dot_product = dot_product_calculator(v, u, n), magnitude_u = magnitude_calculator(u, n), *projection_of_v_onto_u;

    if (magnitude_u == 0)
    {
        cout << "Ошибка: магнитуда равна нулю!";
        return v;
    }

    if (!(projection_of_v_onto_u = (double *)malloc((n) * sizeof(double))))
    {
        cout << "Ошибка выделения памяти для projection_of_v_onto_u!";
        return v;
    }

    projection_of_v_onto_u = vector_scalar_multiplication(dot_product / pow(magnitude_u, 2), u, n);

    return projection_of_v_onto_u;
}

double *vector_subtraction_calculator(double *v, double *u, int n)
{
    double *vector_subtraction;
    int i;
    if (!(vector_subtraction = (double *)malloc((n) * sizeof(double))))
    {
        cout << "Ошибка выделения памяти для vector_subtraction!";
        return v;
    }

    for (i = 0; i < n; i++)
        vector_subtraction[i] = v[i] - u[i];

    return vector_subtraction;
}

double *gram_schmidt_process(double *A, int n)
{
    double *v_i, *u_i, *u_temp, *U, *e_i, *Q;
    int i, j, k;

    if (!(v_i = (double *)malloc((n) * sizeof(double))))
    {
        cout << "Ошибка выделения памяти для v_i!";
        return A;
    }

    if (!(u_i = (double *)malloc((n) * sizeof(double))))
    {
        cout << "Ошибка выделения памяти для u_i!";
        return A;
    }

    if (!(u_temp = (double *)malloc((n) * sizeof(double))))
    {
        cout << "Ошибка выделения памяти для u_temp!";
        return A;
    }

    if (!(U = (double *)malloc((n * n) * sizeof(double))))
    {
        cout << "Ошибка выделения памяти для U!";
        return A;
    }

    if (!(e_i = (double *)malloc((n) * sizeof(double))))
    {
        cout << "Ошибка выделения памяти для e_i!";
        return A;
    }

    if (!(Q = (double *)malloc((n * n) * sizeof(double))))
    {
        cout << "Ошибка выделения памяти для E!";
        return A;
    }

    cout << "Матрица А:\n";
    print_the_matrix(A, n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            v_i[j] = A[j * n + i];
        u_i = v_i;
        if (i == 0)
            for (j = 0; j < n; j++)
                U[i * n + j] = u_i[j];
        else
        {
            for (j = 0; j < i; j++)
            {
                for (k = 0; k < n; k++)
                {
                    u_temp[k] = U[(i - 1 - j) * n + k];
                }
                u_i = vector_subtraction_calculator(u_i, vector_projection_calculator(v_i, u_temp, n), n);
            }
        }
        e_i = unit_vector_calculator(u_i, n);
        for (k = 0; k < n; k++)
            Q[k * n + i] = e_i[k];
        for (k = 0; k < n; k++)
            U[i * n + k] = u_i[k];
    }
    cout << "Матрица Q: \n";
    print_the_matrix(Q, n);

    free(v_i);
    free(u_i);
    free(u_temp);
    free(U);
    free(e_i);

    return Q;
}

double *matrix_transpose_calculator(double *A, int n)
{
    int i, j;
    double temp = 0.;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
        {
            temp = A[j * n + i];
            A[j * n + i] = A[i * n + j];
            A[i * n + j] = temp;
        }
    return A;
}

void matrix_multiplication(double *A, double *X, double *B, int n)
{
    int i, j, k;
    for (i = 0; i < n * n; i++)
        B[i] = 0.0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                B[i * n + j] += A[i * n + k] * X[k * n + j];
}

void qr_factorization(double *A, double *Q, double *R, int n)
{
    int i, j, k;
    Q = gram_schmidt_process(A, n);
    double *Q_t = Q, *Q_a;
    matrix_transpose_calculator(Q_t, n);
    matrix_multiplication(Q_t, A, R, n);
    cout << "\nМатрица R:\n";
    print_the_matrix(R, n);
    // R = A;
    if (!(Q_a = (double *)malloc((n * n) * sizeof(double))))
    {
        cout << "Ошибка выделения памяти для Q_a!";
    }

    matrix_multiplication(Q, R, Q_a, n);
    cout << "Произведение Q * R (в идеале должно быть копией А):\n";
    print_the_matrix(Q_a, n);
}

double L2_accuracy_of_factorization(double *A, double *Q, double *R, int n)
{
    double norma = 0., *A_from_QR;

    if (!(A_from_QR = (double *)malloc((n * n) * sizeof(double))))
    {
        cout << "Ошибка выделения памяти для A_from_QR!";
        return 0;
    }

    matrix_multiplication( Q, R, A_from_QR, n);
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            A[i * n + j] -= A_from_QR[i * n + j];

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            norma += A[i * n + j] * A[i * n + j];

    free(A_from_QR);

    return sqrt(norma);
}