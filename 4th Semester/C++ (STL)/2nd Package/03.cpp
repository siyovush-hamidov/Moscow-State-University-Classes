#include <bits/stdc++.h>
using namespace std;

template <class T>
class Matrix
{
    private:
        T** arr_;
        size_t rows_{}; size_t cols_{};
    public:
        Matrix()
        {
            rows_ = cols_ = 0;
        }
        Matrix(int rows, int cols)
        {
            rows_ = rows;
            cols_ = cols;

            arr_ = (T**) new T*[rows_];

            for (int i = 0; i < rows_; i++)arr_[i] = (T*)new T[cols_];
            for (int i = 0; i < rows_; i++) for (int j = 0; j < cols_; j++) arr_[i][j] = 0;
        }
        size_t rows()
        {
            return rows_;
        }
        size_t cols()
        {
            return cols_;
        }
        void Input()
        {
            T value = 0;
            for(size_t i = 0; i < rows_; i++)
            {
                for(size_t j = 0; j < cols_; j++)
                {
                    cin >> value;
                    arr_[i][j] = value;
                }
            }
        }
        void Print()
        {
            for(size_t i = 0; i < rows_; i++)
            {
                for(size_t j = 0; j < cols_; j++)
                {
                    cout << arr_[i][j] << ' ';
                }
                cout << endl;
            }
        }
        int DifferentRows()
        {
            int ans = rows_; bool bans = false;
            for(size_t i = 0; i < rows_; i++)
            {
                bans = false;
                for(size_t j = 0; j < cols_; j++)
                {
                    for(size_t k = j + 1; k < cols_; k++)
                    {
                        if(arr_[i][j] == arr_[i][k])
                        {
                            bans = true;
                            ans--;
                            break;
                        }
                    }
                    if(bans) break;
                }
            }
            return ans;
        }
};

int main()
{
    int Cols, Rows;
    cin >> Rows >> Cols;
    Matrix<int> A(Rows,Cols);
    A.Input();
    int ans = A.DifferentRows();
    cout << ans;
}