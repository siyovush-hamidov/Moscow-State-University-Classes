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

        if(aha) std :: cout << "Index: " << index <<" is already in use.\n";

        return aha;
    }

    T& operator[](int index)
    {
        List* Current = new List;
        Current = PointerToLast;
        
        for(int i = 0; i < count(); i++)
        {
            if(Current->Index == index) return Current->Value;
            Current = Current->PointerToPrevious;
        }
        std :: cout << "No index was found..."; return Current->Value;
    }

    void add_end(int index, T value)
    {
        while(if_index_already_is_present(index))
        {
            std :: cout << "Please, enter the index once more: ";
            std :: cin >> index;
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
        while(PointerToLast->PointerToNext != nullptr)
        {
            PointerToLast = PointerToLast->PointerToNext;
        }
        std :: cout << "The element was added to the end successfully.\n"; 
    }
    
    void add_begin(int index, T value)
    {
        while(if_index_already_is_present(index))
        {
            std :: cout << "Please, enter the index once more: ";
            std :: cin >> index;
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
        while(PointerToLast->PointerToNext != nullptr)
        {
            PointerToLast = PointerToLast->PointerToNext;
        }
        std :: cout << "The element was added to the beginning successfully.\n";        
    }

    void insert_list(int index, T value)
    {
        while(if_index_already_is_present(index))
        {
            std :: cout << "Please, enter the index once more: ";
            std :: cin >> index;
        }
        List* NewRecord = new List;
        NewRecord->Index = index;
        NewRecord->Value = value;
        NewRecord->PointerToNext = nullptr;
        NewRecord->PointerToPrevious = nullptr;

        if (PointerToLast == nullptr)
        {
            PointerToLast = NewRecord;
        }
        else
        {
            List* temp = PointerToLast;
            List* closest = nullptr;
            int minDiff = INT_MAX;

            while (temp != nullptr)
            {
                int diff = abs(temp->Index - index);
                if (diff < minDiff)
                {
                    minDiff = diff;
                    closest = temp;
                }
                temp = temp->PointerToPrevious;
            }

            if (closest->Index < index)
            {
                NewRecord->PointerToNext = closest->PointerToNext;
                NewRecord->PointerToPrevious = closest;
                if (closest->PointerToNext != nullptr)
                {
                    closest->PointerToNext->PointerToPrevious = NewRecord;
                }
                closest->PointerToNext = NewRecord;
            }
            else
            {
                NewRecord->PointerToNext = closest;
                NewRecord->PointerToPrevious = closest->PointerToPrevious;
                if (closest->PointerToPrevious != nullptr)
                {
                    closest->PointerToPrevious->PointerToNext = NewRecord;
                }
                closest->PointerToPrevious = NewRecord;
            }
        }
        while(PointerToLast->PointerToNext != nullptr)
        {
            PointerToLast = PointerToLast->PointerToNext;
        }
        std :: cout << "The element was inserted successfully.\n";
    }

    void delete_list(int index)
    {
        if (PointerToLast == nullptr)
        {
            std :: cout << "The list is empty.\n";
            return; // List is empty
        }

        List* temp = PointerToLast;

        while (temp != nullptr)
        {
            if (temp->Index == index)
            {
                if (temp->PointerToPrevious != nullptr)
                {
                    temp->PointerToPrevious->PointerToNext = temp->PointerToNext;
                }
                if (temp->PointerToNext != nullptr)
                {
                    temp->PointerToNext->PointerToPrevious = temp->PointerToPrevious;
                }
                if (temp == PointerToLast)
                {
                    PointerToLast = temp->PointerToPrevious;
                }
                delete temp;
                return;
            }
            temp = temp->PointerToPrevious;
        }
        std :: cout << "The element was deleted successfully.\n";
    }

    void Forward()
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
        std :: cout << "Elements were displayed sequentially.\n";
    }

    void Backward()
    {
        if (PointerToLast == nullptr)
        {
            std ::cout << "\nThe list is empty\n";
            return;
        }
        List *temp = new List;
        temp = PointerToLast;
        std ::cout << "\nIndex   Value\n";
        while(temp != nullptr)
        {
            std ::cout << temp->Index << "       " << temp->Value << '\n';
            temp = temp->PointerToPrevious;
        }
        std :: cout << "Elements were displayed backwardly.\n";
    }

    void refresh_indexes(int index, int pace)
    {
        List *temp = PointerToLast;
        while(temp->PointerToPrevious != nullptr)
        {
            temp = temp->PointerToPrevious;
        }
        while(temp->PointerToNext != nullptr)
        {
            temp->Index = index;
            index += pace;
            temp = temp->PointerToNext;
        }
        PointerToLast->Index = index;

        std :: cout << "Indexes were refreshed succesfully.\n";
    }
    
    void erase_all()
    {
        PointerToLast = nullptr;
        std :: cout << "The list was erased succesfully.\n";
    }

    void sort_list()
    {
        std :: cout << "ASC - 1 | DESC - 2\nChoose order: "; int choice; std :: cin >> choice;
        switch (choice)
        {
        case 1:
            for(int i = 0; i < count() - 1; i++)
            {
                List *temp = PointerToLast;
                while(temp->PointerToPrevious != nullptr)
                {
                    if(temp->Value < temp->PointerToPrevious->Value)
                    {
                        int temp_index = temp->Index, temp_previous_index = temp->PointerToPrevious->Index;
                        T temp_value = temp->Value, temp_previous_value = temp->PointerToPrevious->Value;
                        
                        temp->Index = temp_previous_index;
                        temp->Value = temp_previous_value;
                        temp->PointerToPrevious->Index = temp_index;
                        temp->PointerToPrevious->Value = temp_value;
                    }
                    temp = temp->PointerToPrevious;
                }
            }
            break;
        case 2:
            for(int i = 0; i < count() - 1; i++)
            {
                List *temp = PointerToLast;
                while(temp->PointerToPrevious != nullptr)
                {
                    if(temp->Value > temp->PointerToPrevious->Value)
                    {
                        int temp_index = temp->Index, temp_previous_index = temp->PointerToPrevious->Index;
                        T temp_value = temp->Value, temp_previous_value = temp->PointerToPrevious->Value;
                        
                        temp->Index = temp_previous_index;
                        temp->Value = temp_previous_value;
                        temp->PointerToPrevious->Index = temp_index;
                        temp->PointerToPrevious->Value = temp_value;
                    }
                    temp = temp->PointerToPrevious;
                }
            }
            break;
        default: std :: cout << "Invalid order. Please, try again." << std::endl;
        }
        
        Forward();
    }
};

using namespace std;

int main()
{
    DoublyList<int> List;
    List.add_end(7, 7);
    List.add_end(2, 4);
    List.add_end(9, 7);
    List.add_begin(8, 5);
    List.insert_list(1,2);
    List.insert_list(10,10);
    // List.insert_list(20,20);
    List.Forward();
    bool running = true;
    int operation = 0; 
    while(running)
    {
        cout << "=================================\n"
        << "Welcome! Available functions are:\n"
        << "=================================\n"
        << "1. Add a value to the end\n"
        << "2. Add a value to the beginning\n"
        << "3. Insert a value into the list \n"
        << "4. Delete an element by index\n"
        << "5. Display sequentially\n"
        << "6. Display backwardly\n"
        << "7. Refresh indexes\n"
        << "8. Display the quantity of records\n"
        << "9. Erase the whole list\n"
        << "10. Sort the list\n"
        << "11. Terminate the programm\n"
        << "=================================\n"
        << "Choose an operation: ";
        cin >> operation;
        switch (operation)
        {
            case 1:
            {
                cout << "Enter an index and a value to add: "; 
                int index, Value; cin >> index >> Value;
                List.add_end(index, Value);
                List.Forward(); 
                break;
            }
            case 2:
            {
                cout << "Enter an index and a value to add: "; 
                int index, Value; cin >> index >> Value;
                List.add_begin(index, Value);
                List.Forward(); 
                break;
            }
            case 3:
            {
                cout << "Enter an index and a value to add: "; 
                int index, Value; cin >> index >> Value;
                List.insert_list(index, Value);
                List.Forward(); 
                break;
            }
            case 4:
            {
                cout << "Enter an index to delete: ";
                int index; cin >> index;
                List.delete_list(index); 
                List.Forward();
                break;
            }
            case 5:
            {
                List.Forward();  
                break;
            }
            case 6:
            {
                List.Backward();  
                break;
            }
            case 7:
            {
                cout << "Enter the index and the pace: ";
                int index, pace; cin >> index >> pace;
                List.refresh_indexes(index, pace);
                break;
            }
            case 8: 
            {
                int ans = List.count();
                cout << "The quantity of records is " << ans << '\n';
                break;
            }
            case 9:
            {
                List.erase_all();  
                break;
            }
            case 10:
            {
                List.sort_list();  
                break;
            }
            case 11:
            {
                cout << "Terminating the program...";
                running = false;
                exit(0);
            }
            default: cout << "Invalid option. Please, try again." << std::endl;
        }
    }
    return 0;
}