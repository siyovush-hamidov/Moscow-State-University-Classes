#include <iostream>
#include <limits>
#include <iomanip>
#include <windows.h>
#include <algorithm>
#include <queue>

using namespace std;

constexpr double MAX_DOUBLE = std::numeric_limits<double>::max();

class Graph
{
public:
    void print_matrix_dushanbe(double *A, int vertices, string *districts)
    {
        int i, j;

        cout << setw(12) << ' ';
        for (i = 0; i < vertices; i++)
            cout << setw(13) << left << districts[i];
        cout << endl;
        for (i = 0; i < vertices; i++)
        {
            cout << setw(12) << left << districts[i];
            for (j = 0; j < vertices; j++)
            {
                if (A[i * vertices + j] == MAX_DOUBLE)
                    cout << setw(12) << left << setprecision(3) << 'X' << ' ';
                else
                    cout << setw(12) << left << setprecision(3) << A[i * vertices + j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    void print_matrix_tajikistan(double *A, int vertices, string *cities)
    {
        int i, j;

        cout << setw(12) << ' ';
        for (i = 0; i < vertices; i++)
            cout << setw(13) << left << cities[i];
        cout << endl;
        for (i = 0; i < vertices; i++)
        {
            cout << setw(12) << left << cities[i];
            for (j = 0; j < vertices; j++)
            {
                if(A[i * vertices + j] == MAX_DOUBLE)
                    cout << setw(12) << left << setprecision(3) << 'X' << " ";
                else
                    cout << setw(12) << left << setprecision(3) << A[i * vertices + j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    double Dijkstra(double *A, int vertices, int from, int to)
    {
        double distances[vertices], distance, new_distance;
        bool visited[vertices];
        int i, vertex, neighbor;

        for (i = 0; i < vertices; i++)
        {
            distances[i] = MAX_DOUBLE;
            visited[i] = false;
        }

        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> queue;
        queue.push({0, from});

        while (!queue.empty())
        {
            distance = queue.top().first;
            vertex = queue.top().second;
            queue.pop();

            if (visited[vertex])
                continue;

            for (neighbor = 0; neighbor < vertices; neighbor++)
            {
                if (!visited[neighbor])
                {
                    new_distance = distance + A[vertex * vertices + neighbor];

                    if (new_distance < distances[neighbor])
                    {
                        distances[neighbor] = new_distance;
                        queue.push({new_distance, neighbor});
                    }
                }
            }
            visited[vertex] = 1;
        }
        return distances[to];
    }

    double simplex_method(double *A, int vertices, int from, int to)
    {
        double distances[vertices];
        int i, j;
        bool visited[vertices];

        for(i = 0; i < vertices; i++)
        {
            distances[i] = MAX_DOUBLE;
            visited[i] = false;
        }
    }
};

int main()
{
    SetConsoleOutputCP(65001);
    srand(time(0));
    Graph obj;
    double *A, *B, result;
    bool running = true;
    int vertices = 5, edges = 8, i, j, indices[] = {0, 1, 0, 3, 1, 3, 1, 4, 2, 3, 3, 0, 3, 1, 4, 1}, choice_of_task, choice_from, choice_to, choice_of_algorithm;
    string cities[] = {"Dushanbe", "Khorog", "Khujand", "Kulob", "Bokhtar", "Istaravshan", "Murgob", "Nurek", "Panjakent", "Buston", "Vakhdat", "Hissor", "Guliston", "Istiqlol", "Isfara", "Konibodom", "Levakand", "Rogun", "Tursunzoda"}, districts[] = {"I.Somoni", "Sino", "Shohmansur", "Firdavsi", "Varzob"};

    do
    {
        cout << "Привет! Какую задачу вы хотите решить?\n1. Задача про город Душанбе (ориентированный неполный граф)\n2. Задача коммивояжера в Таджикистане (неориентированный полный граф)\n3. Завершить программу\nВведите номер задачи: ";
        cin >> choice_of_task;
        switch (choice_of_task)
        {
        case 1:
            cout << "\nВ условии задачи существует 5 районов города (вершин графа) и 8 связей (рёбер) между ними.\nВеса графа будут заполнены в случайном порядке в пределах от 1 до 20\n\n";
            vertices = 5, edges = 8;
            if (!(A = (double *)malloc(vertices * vertices * sizeof(double))))
            {
                cout << "Ошибка выделения памяти!\n";
                return -1;
            }
            for (i = 0; i < vertices * vertices; i++)
                A[i] = MAX_DOUBLE;
            for (i = 0; i < sizeof(indices) / sizeof(indices[0]); i += 2)
                A[indices[i] * vertices + indices[i + 1]] = 1 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / 19));
            obj.print_matrix_dushanbe(A, vertices, districts);
            cout << "\nГде вы находитесь?";
            for (i = 0; i < vertices; i++)
                cout << '\n'
                     << i + 1 << ". " << districts[i];
            cout << "\nВведите номер района: ";
            cin >> choice_from;
            cout << "Введите конечный район (куда вам надо): ";
            cin >> choice_to;
            break;
        case 2:
            cout << "Введите размер матрицы (до 19 так как в базе есть только 19 городов нашей страны (это сделано для того, чтобы придать задаче интересный смысл), веса графа будут заполнены случайными числами в пределах от 1 до 20): ";
            cin >> vertices;
            while (vertices < 2 || vertices > 19)
            {
                cout << "Вы ввели недопустимое число! Пожалуйста, введите ещё раз: ";
                cin >> vertices;
            }
            edges = vertices * (vertices + 1) / 2;
            if (!(A = (double *)malloc(vertices * vertices * sizeof(double))))
            {
                cout << "Ошибка выделения памяти!\n";
                return -1;
            }
            for (i = 0; i < vertices; i++)
                for (j = 0; j <= i; j++)
                {
                    if (j == i)
                        A[i * vertices + j] = MAX_DOUBLE;
                    else
                        A[i * vertices + j] = 1 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / 19));
                    A[j * vertices + i] = A[i * vertices + j];
                }
            obj.print_matrix_tajikistan(A, vertices, cities);
            cout << "\nВ каком вы городе?";
            for (i = 0; i < vertices; i++)
                cout << '\n'
                     << i + 1 << ". " << cities[i];
            cout << "\nВведите номер города: ";
            cin >> choice_from;
            cout << "Введите конечный город (куда вам надо): ";
            cin >> choice_to;
            break;
        case 3:
            cout << "Программа будет завершена...";
            exit(0);
        default:
            cout << "Некорректный ввод. Поробуйте ещё раз, пожалуйста.\n";
        }

        cout << "\nКаким алгоритмом нужно решить вашу задачу?\n1. Алгоритм Дейкстры (не всегда проходит через все вершины)\n2. Симплекс-Метод\nВведите номер алгоритма: ";
        cin >> choice_of_algorithm;

        switch (choice_of_algorithm)
        {
        case 1:
            result = obj.Dijkstra(A, vertices, choice_from - 1, choice_to - 1);
            if (result == MAX_DOUBLE)
                cout << "\nВ текущее время, на дороге ведутся работы. Дороги закрыты (туда попасть невозможно).\n\n";
            else
                cout << "\nКратчайший путь будет: " << result << "\n\n";
            free(A);
            break;
        }
    } while (running);

    for (i = 0; i < sizeof(indices) / sizeof(indices[0]); i += 2)
    {
        A[indices[i] * vertices + indices[i + 1]] = 1;
    }

    for (i = 0; i < vertices * vertices; i++)
    {
        if (A[i] == 1)
            A[i] = rand() % 10;
        else
            A[i] = MAX_DOUBLE;
    }

    if (!(B = (double *)calloc(vertices * vertices, sizeof(double))))
    {
        cout << "Ошибка выделения памяти";
        return -7;
    }

    for (i = 0; i < vertices * vertices; i++)
    {
        cin >> B[i];
    }

    obj.print_matrix_dushanbe(A, vertices, districts);

    result = obj.Dijkstra(A, vertices, 2, 4);
    cout << result;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// КАК РАБОТАЕТ static_cast<dest_type>(source)?
// `static_cast` - это оператор приведения типов в C++, который используется для преобразования одного типа данных в другой. Он может выполнять такие вещи, как неявные преобразования между типами (например, из `int` в `float`, или из указателя на `void*`), и он также может вызывать явные функции преобразования¹.

// Синтаксис `static_cast` выглядит следующим образом:
// ```cpp
// static_cast<dest_type>(source);
// ```
// Здесь `dest_type` - это тип, в который вы хотите преобразовать, а `source` - это исходное значение, которое вы хотите преобразовать¹.

// Вот пример использования `static_cast`:
// ```cpp
// float f = 3.5;
// int a = f; // a будет равно 3
// int b = static_cast<int>(f); // b будет равно 3
// ```
// В этом примере `static_cast` используется для преобразования числа с плавающей точкой `f` в целое число¹.

// Однако стоит отметить, что `static_cast` не выполняет проверку типов во время выполнения. Это означает, что если вы пытаетесь выполнить некорректное приведение типов (например, привести указатель на `char` к указателю на `int`), компилятор выдаст ошибку¹.

// Также `static_cast` может использоваться для преобразования объектов с помощью определенного пользователем оператора преобразования, если он определен¹. Кроме того, он может обеспечивать как восходящее, так и нисходящее приведение в случае наследования¹.

// Source: Conversation with Bing, 20.10.2023
// (1) static_cast in C++ - GeeksforGeeks. https://www.geeksforgeeks.org/static_cast-in-cpp/.
// (2) static_cast conversion - cppreference.com. https://en.cppreference.com/w/cpp/language/static_cast.
// (3) c++ - Regular cast vs. static_cast vs. dynamic_cast - Stack Overflow. https://stackoverflow.com/questions/28002/regular-cast-vs-static-cast-vs-dynamic-cast.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Как я могу реализовать метод ветвей и границ для задачи коммивояжера, опиши шаги словами, я хочу сам написать алгоритм.

// Метод ветвей и границ (Branch and Bound, B&B) - это общий алгоритм для решения задач дискретной и комбинаторной оптимизации, таких как задача коммивояжера. Вот основные шаги алгоритма:
// 1. **Инициализация:** Начните с создания корневого узла, который представляет собой частичное решение (например, путь, который проходит только через начальную вершину).
// 2. **Создание дочерних узлов:** Для каждого узла создайте дочерние узлы, которые представляют собой все возможные расширения текущего частичного решения (например, все вершины, которые можно посетить следующими).
// 3. **Оценка узлов:** Для каждого узла вычислите нижнюю границу стоимости любого возможного решения, которое может быть получено путем расширения этого узла. Это можно сделать, например, с помощью оценки минимального остовного дерева или метода ближайшего соседа.
// 4. **Выбор узла:** Выберите узел с наименьшей нижней границей для дальнейшего расширения. Если есть несколько таких узлов, выберите тот, который был создан первым (это обеспечивает стратегию поиска в ширину).
// 5. **Проверка на завершение:** Если выбранный узел представляет собой полное решение (то есть путь, который проходит через все вершины), и его стоимость меньше текущего лучшего решения, обновите текущее лучшее решение. Если нет других узлов для расширения (то есть все пути были исследованы), алгоритм завершается.
// 6. **Отсечение ветвей:** Если нижняя граница узла больше стоимости текущего лучшего решения, этот узел и все его дочерние узлы могут быть отсечены (то есть исключены из дальнейшего рассмотрения), поскольку они не могут привести к лучшему решению.
// 7. **Повторение:** Повторите шаги 2-6 до тех пор, пока не будет найдено оптимальное решение или не будут исследованы все возможные пути.

// Обратите внимание, что эффективность метода ветвей и границ во многом зависит от выбора стратегии создания дочерних узлов и оценки нижних границ. Более точные оценки могут привести к более быстрому отсечению неподходящих ветвей, но также могут потребовать больше времени для вычисления.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////