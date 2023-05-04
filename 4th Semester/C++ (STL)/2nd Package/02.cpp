#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <class T>

class List
{
    public:
        List()
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

        char StrTok(char Delimiter)
        {
            string StringBuff;
            for(int i = 0; i < n; i++) StringBuff += arr_[i];

            char CharBuff[255];
            strcpy(CharBuff, StringBuff.c_str());

            char tmp_char;
            for(int i = 0; i < sizeof(CharBuff); i++)
            {
                if(CharBuff[i] != Delimiter)
                {
                    tmp_char += CharBuff[i];
                }
                else break;
            }
            return tmp_char;
        }

        T MaxDistanceElement()
        {
            T MaxDistance = 0, temp = 0, MaxDistanceElement = arr_[0];
            for(int i = 1; i < size_; i++) MaxDistance += abs(arr_[0] - arr_[i]); 

            for(int i = 1; i < size_; i++)
            {
                temp = 0;
                for(int j = 0; j < size_; j++)
                {
                    temp += abs(arr_[i] - arr_[j]);
                }
                if(temp > MaxDistance){MaxDistance = temp; MaxDistanceElement = arr_[i];}
            }
            
            return MaxDistanceElement;
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
inline ostream& operator<<(ostream& os, const List<T>& lis)
    {
        for(size_t i = 0; i < lis.size(); ++i) os << lis[i] << ' ';
        return os;
    }

int main()
{
    List<string> A;
    int n; cin >> n;
    string x;

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        A.PushBack(x);
        cout << A[i] << endl;
    }
    cout << endl;
    char *tmp_char;
    char H = 'K';
    tmp_char = A.StrTok(H);
    cout << tmp_char;

    // int ans = A.MaxDistanceElement();
    
    // cout << ans << endl;
}