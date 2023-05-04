#include <iostream>
using namespace std;

template <class T>

class Vector
{
    public:
        Vector()
        {
            arr_ = new T[1];
            capacity_ = 1;
        }

        size_t size()
        {
            return size_;
        }      

        size_t capacity()
        {
            return capacity_;
        }
        
        void PushBack(T& value)
        {
            if (size_ >= capacity_) addMemory();
            arr_[size_++] = value;
        }

        void remove(size_t index)
        {
            for(size_t i = index + 1; i < size_; ++i) arr_[i - 1] = arr_[i];
            --size_;
        }

        T& operator[](size_t index)
        {
            return arr_[index];
        }

        T max_element()
        {
            T MaxElement = arr_[0];
            for(size_t i = 1; i < size_; i++) if(MaxElement < arr_[i]) MaxElement = arr_[i];
            return MaxElement;
        }

            T min_element()
        {
            T MinElement = arr_[0];
            for(size_t i = 1; i < size_; i++) if(MinElement > arr_[i]) MinElement = arr_[i];
            return MinElement;
        }

        void print()
        {
            for(int i = 0; i < size_; i++) cout << arr_[i] << ' ';
        }
        // void& operator<<(size_t index)
        // {
        //     cout << arr_[index];
        // }

    private:
        T* arr_;
        size_t size_{};
        size_t capacity_{};

        void addMemory()
        {
            capacity_ *= 2;
            T* temp = arr_;
            arr_ = new T[capacity_];
            for(size_t i = 0; i < size_; ++i) arr_[i] = temp[i];
            delete[] temp;
        }
};

// template<class T>
// inline ostream& operator<<(ostream& os, const Vector<T>& vec)
//     {
//         for(size_t i = 0; i < vec.size(); ++i) os << vec[i] << ' ';
//         return os;
//     }

int main()
{
    Vector<int> A;
    int n, x; cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        A.PushBack(x);
    }

    int MaxAns = A.max_element();
    int MinAns = A.min_element();
    cout << MaxAns << ' ' << MinAns << endl;
    A.print();
}