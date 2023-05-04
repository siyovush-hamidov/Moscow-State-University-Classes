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
        [[nodiscard]] size_t size() const
        {
            return size_;
        }        
        [[nodiscard]] size_t capacity() const
        {
            return capacity_;
        }
        
        void PushBack(const T& value)
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

        bool SawLike()
        {
            bool ans = true;
            for(int i = 1; i < size_ - 1; i++) if((arr_[i-1] < arr_[i] && arr_[i] < arr_[i+1]) || (arr_[i+1] < arr_[i] && arr_[i] < arr_[i-1])){ans = false; break;}
            return ans;
        }


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

template<class T>
inline ostream& operator<<(ostream& os, const Vector<T>& vec)
    {
        for(size_t i = 0; i < vec.size(); ++i) os << vec[i] << ' ';
        return os;
    }

int main()
{
    Vector<int> A;
    int n, x; cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        A.PushBack(x);
    }

    bool ans = A.SawLike();
    
    cout << ans << endl;
}