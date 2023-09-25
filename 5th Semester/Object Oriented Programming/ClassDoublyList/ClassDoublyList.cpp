#include <iostream>

template <typename T>
class DoublyList
{
private:
    struct List
    {
        int Index;
        T Value;
        List *PointerToNext;
        List *PointerToPrevious;
    };
    List *PointerToLast;

public:
    DoublyList() : PointerToLast(nullptr) {}

    int count()
    {
        int ans = 0;
        List *current = new List;
        current = PointerToLast;
        while (current != nullptr)
        {
            ans++;
            current = current->PointerToPrevious;
        }
        return ans;
    }
    bool if_index_already_is_present(int index)
    {
        bool aha = false;
        if (PointerToLast == nullptr)
            aha = false;
        else
        {
            List *node = new List;
            node = PointerToLast;
            while (node != nullptr)
            {
                if (node->Index == index) aha = true;
                node = node->PointerToPrevious;
            }
        }
        return aha;
    }
    void add_end(int index, T value)
    {
        if (if_index_already_is_present(index))
        {
            std :: cout << "Index: " << index <<" is already in use."; return;
        }
        List *NewRecord = new List;

        NewRecord->Index = index;
        NewRecord->Value = value;
        NewRecord->PointerToNext = nullptr;

        if (PointerToLast == nullptr)
        {
            NewRecord->PointerToPrevious = nullptr;
            PointerToLast = NewRecord;
        }
        else
        {
            NewRecord->PointerToPrevious = PointerToLast;
            PointerToLast->PointerToNext = NewRecord;
            PointerToLast = NewRecord;
        }
    }
    void add_begin(int index, T value)
    {
        if (if_index_already_is_present(index))
        {
            std :: cout << "Index: " << index <<" is already in use."; return;
        }
        List *NewRecord = new List;
        NewRecord->Index = index;
        NewRecord->PointerToPrevious = nullptr;
        NewRecord->Value = value;

        if (PointerToLast == nullptr)
        {
            NewRecord->PointerToNext = nullptr;
            PointerToLast = NewRecord;
        }
        else
        {
            List *temp = new List;
            temp = PointerToLast;
            while (temp->PointerToPrevious != nullptr)
            {
                temp = temp->PointerToPrevious;
            }
            NewRecord->PointerToNext = temp;
            temp->PointerToPrevious = NewRecord;
        }
    }
    void insert_list(int index, T value)
    {
        if(if_index_already_is_present(index))
        {
            std :: cout << "Index: " << index <<" is already in use."; return;
        }
        List *NewRecord = new List;
        NewRecord->Index = index;
        NewRecord->PointerToPrevious = nullptr;
        NewRecord->Value = value;

        if (PointerToLast == nullptr)
        {
            NewRecord->PointerToNext = nullptr;
            PointerToLast = NewRecord;
        }
        else
        {
            List *temp = new List;
            temp = PointerToLast;
            while (temp-> != nullptr)
            {
                int a = temp->Index;
                temp = temp->PointerToPrevious;
                if (a >= temp->Index)
                {
                    int b = temp->Index;
                }
            }
            NewRecord->PointerToNext = temp;
            temp->PointerToPrevious = NewRecord;
        }
    }
    void Output()
    {
        if (PointerToLast == nullptr)
        {
            std ::cout << "\nThe list is empty\n";
            return;
        }
        List *temp = new List;
        temp = PointerToLast;

        while (temp->PointerToPrevious != nullptr)
        {
            temp = temp->PointerToPrevious;
        }
        std ::cout << "\nIndex   Value\n";
        while (temp != nullptr)
        {

            std ::cout << temp->Index << "       " << temp->Value << '\n';
            temp = temp->PointerToNext;
        }
    }
};

int main()
{
    DoublyList<int> A;
    A.Output();
    A.add_end(5, 7);
    A.add_end(1, 4);
    A.add_begin(6, 5);
    A.insert_list(4,2);
    A.add_end(2, 7);
    A.Output();
}