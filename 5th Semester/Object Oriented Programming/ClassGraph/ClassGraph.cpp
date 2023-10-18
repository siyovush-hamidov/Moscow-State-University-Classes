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

    double Dijkstra(double *A, int vertices, int start)
    {
        // Инициализируем массив `distances` нулями, а массив `visited` - значениями `false`.
        double distances[vertices];
        bool visited[vertices];
        for (int i = 0; i < vertices; i++)
        {
            distances[i] = numeric_limits<double>::max();
            visited[i] = false;
        }

        // Добавляем стартовую вершину в очередь приоритетов.
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> queue;
        queue.push({0, start});

        // Пока очередь не пуста:
        while (!queue.empty())
        {
            // Извлекаем вершину из очереди с приоритетом.
            double distance = queue.top().first;
            int vertex = queue.top().second;
            queue.pop();

            // Если вершина уже посещена, пропускаем ее.
            if (visited[vertex])
            {
                continue;
            }

            // Для каждой вершины, смежной с текущей вершиной:
            for (int neighbor = 0; neighbor < vertices; neighbor++)
            {
                // Если вершина не посещена:
                if (!visited[neighbor])
                {
                    // Обновляем значение расстояния до вершины, используя формулу Дейкстры.
                    double new_distance = distance + A[vertex * vertices + neighbor];

                    // Если новое расстояние меньше, чем ранее найденное расстояние:
                    if (new_distance < distances[neighbor])
                    {
                        distances[neighbor] = new_distance;
                        queue.push({new_distance, neighbor});
                    }
                }
            }

            // Отмечаем вершину как посещенную.
            visited[vertex] = true;
        }

        // Возвращаем массив `distances`.
        return distances[start];
    }

    Пример использования:

0 2 3.2 7.2 4
Дополнительные пояснения:

В строке double distances[vertices]; мы объявляем массив distances, в котором будем хранить расстояния до каждой вершины.
В строке bool visited[vertices]; мы объявляем массив visited, в котором будем хранить флаги посещения вершин.
В строке queue.push({0, start}); мы добавляем стартовую вершину в очередь приоритетов с расстоянием 0.
В строке distance = queue.top().first; мы извлекаем из очереди вершину с наименьшим расстоянием.
В строке distances[neighbor] = new_distance; мы обновляем значение расстояния до вершины neighbor на новое значение.
В строке queue.push({new_distance, neighbor}); мы добавляем вершину neighbor в очередь приоритетов с новым расстоянием.
};

int main()
{
    Dushanbe obj;
    double *A, *matrix_for_dijkstra, vector_of_weights[] = {2, 3, 5, 1, 7, 3.2, 7, 4}, result;
    int vertices = 5, edges = 8, i, j, indices[] = {0, 1, 0, 3, 1, 3, 1, 4, 2, 3, 3, 0, 3, 1, 4, 1};

    if (!(A = (double *)calloc(vertices * vertices, sizeof(double))))
    {
        cout << "Memory allocation failed!\n";
        return -1;
    }

    if (!(matrix_for_dijkstra = (double *)calloc(vertices * vertices, sizeof(double))))
    {
        cout << "Memory allocation failed!\n";
        return -1;
    }

    for (i = 0; i < vertices * vertices; i++)
        matrix_for_dijkstra[i] = MAX_DOUBLE;

    for (i = 0; i < sizeof(indices) / sizeof(indices[0]); i += 2)
    {
        A[indices[i] * vertices + indices[i + 1]] = 1;
    }

    for (i = 0, j = 0; i < vertices * vertices; i++)
    {
        if (A[i] == 1)
            A[i] = vector_of_weights[j++];
    }
    result = obj.Dijkstra(A, matrix_for_dijkstra, vertices);
}

#include <queue>