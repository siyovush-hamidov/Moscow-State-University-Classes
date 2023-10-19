#include <iostream>
#include <limits>
#include <iomanip>
#include <windows.h>
#include <algorithm>
#include <queue>

using namespace std;

constexpr double MAX_DOUBLE = std::numeric_limits<double>::max();

class Dushanbe
{
public:
    void print_matrix(double *A, int vertices)
    {
        int i, j;
        string districts[] = {"Somoni", "Sino", "Shoh", "Firdavsi", "Varzob"};

        cout << setw(12) << ' ';
        for (i = 0; i < vertices; i++)
            cout << setw(13) << left << districts[i];
        cout << endl;
        for (i = 0; i < vertices; i++)
        {
            cout << setw(12) << left << districts[i];
            for (j = 0; j < vertices; j++)
            {
                cout << setw(12) << left << setprecision(2) << A[i * vertices + j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    double Dijkstra(double *A, int vertices, int from, int to)
    {
        // // Инициализируем массив `distances` нулями, а массив `visited` - значениями `false`.
        // double distances[vertices], distance, new_distance;
        // bool visited[vertices];
        // int vertex, neighbor, i;
        // for (i = 0; i < vertices; i++)
        // {
        //     distances[i] = numeric_limits<double>::max();
        //     visited[i] = false;
        // }

        // // Добавляем стартовую вершину в очередь приоритетов.
        // priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> queue;
        // queue.push({0, from});

        // // Пока очередь не пуста:
        // while (!queue.empty())
        // {
        //     // Извлекаем вершину из очереди с приоритетом.
        //     distance = queue.top().first;
        //     vertex = queue.top().second;
        //     queue.pop();

        //     // Если вершина уже посещена, пропускаем ее.
        //     if (visited[vertex])
        //     {
        //         continue;
        //     }

        //     // Для каждой вершины, смежной с текущей вершиной:

        //     for (neighbor = 0; neighbor < vertices; neighbor++)
        //     {
        //         // Если вершина не посещена:
        //         if (!visited[neighbor])
        //         {
        //             // Обновляем значение расстояния до вершины, используя формулу Дейкстры.
        //             new_distance = distance + A[vertex * vertices + neighbor];

        //             // Если новое расстояние меньше, чем ранее найденное расстояние:
        //             if (new_distance < distances[neighbor])
        //             {
        //                 distances[neighbor] = new_distance;
        //                 queue.push({new_distance, neighbor});
        //             }
        //         }
        //     }

        //     // Отмечаем вершину как посещенную.
        //     visited[vertex] = true;
        // }

        // // Возвращаем кратчайшее расстояние от `from` до `to`.
        // return distances[to];

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
};

int main()
{
    Dushanbe obj;
    double *A, vector_of_weights[] = {2.5, 3.5, 5.5, 1.5, 7.5, 3.5, 7.5, 4.5}, result;
    int vertices = 5, edges = 8, i, j, indices[] = {0, 1, 0, 3, 1, 3, 1, 4, 2, 3, 3, 0, 3, 1, 4, 1};

    if (!(A = (double *)calloc(vertices * vertices, sizeof(double))))
    {
        cout << "Memory allocation failed!\n";
        return -1;
    }

    for (i = 0; i < sizeof(indices) / sizeof(indices[0]); i += 2)
    {
        A[indices[i] * vertices + indices[i + 1]] = 1;
    }

    for (i = 0, j = 0; i < vertices * vertices; i++)
    {
        if (A[i] == 1)
            A[i] = vector_of_weights[j++];
        else
            A[i] = MAX_DOUBLE;
    }

    obj.print_matrix(A, vertices);

    result = obj.Dijkstra(A, vertices, 2, 4);

    cout << result;
}