#include <iostream>

template <typename I, typename V>

class Ring
{
private:
    struct List
    {
        I Index;
        V Value;
        List *PointerToPrevious;
        List *PointerToNext;
    };
    List *PointerToLast;
    int N;

public:
    Ring() : PointerToLast(nullptr), N(0) {}

    bool if_index_already_is_present(int index)
    {
        bool aha = false;
        if (PointerToLast == nullptr)
            aha = false;
        else
        {
            List *node = new List;
            node = PointerToLast;
            for (int i = 0; i < N; i++)
            {
                if (node->Index == index)
                    aha = true;
                node = node->PointerToPrevious;
            }
        }
        if (aha)
            std ::cout << "Index: " << index << " is already in use.\n";
        return aha;
    }

    void add_ring(I index, V value)
    {
        while (if_index_already_is_present(index))
        {
            std ::cout << "Please, enter the index once more: ";
            std ::cin >> index;
        }
        List *NewRecord = new List;
        NewRecord->Index = index;
        NewRecord->Value = value;
        if (PointerToLast == nullptr)
        {
            NewRecord->PointerToPrevious = NewRecord;
            NewRecord->PointerToNext = NewRecord;
            PointerToLast = NewRecord;
        }
        List *temp = PointerToLast;
        for(int i = 0; i < N - 1; i++)
        {
            temp = temp->PointerToPrevious;
        }
        NewRecord->PointerToNext = temp;
        temp->PointerToPrevious = NewRecord;
        NewRecord->PointerToPrevious = PointerToLast;
        if(PointerToLast != nullptr)
        {
            NewRecord->PointerToPrevious = PointerToLast;
            PointerToLast->PointerToNext = NewRecord;
            PointerToLast = NewRecord;
        }
        N++;
    }

    void delete_list(int index)
    {
        if(PointerToLast == nullptr)
        {
            std :: cout << "The list is empty.\n";
            return;
        }
        List *temp = PointerToLast;
        for(int i = 0; i < N; i++)
        {
            if(temp->Index == index)
            {
                temp->PointerToPrevious->PointerToNext = temp->PointerToNext;
                temp->PointerToNext->PointerToPrevious = temp->PointerToPrevious;    
                if(temp == PointerToLast)
                {
                    PointerToLast = temp->PointerToPrevious;
                }
                delete temp; N -= 1;
                return;
            }
            temp = temp->PointerToPrevious;
        } 
        std :: cout << "The element under the given index was deleted successfully.\n";
    }

    void alter_index(I index, I new_index)
    {
        List *temp = PointerToLast;
        for(int i = 0; i < N; i++)
        {
            if(temp->Index == index)
                temp->Index = new_index;
            temp = temp->PointerToPrevious;
        }
        std :: cout << "Index provided was altered successfully.\n";
    }

    void erase_ring()
    {
        PointerToLast = nullptr; N = 0;
        std :: cout << "The list was erased successfully.\n";
    }

    int count()
    {
        std :: cout << "Quantity of the records is " << N << '\n';
        return N;
    }

    void set_item(I index, V value)
    {
        List *temp = PointerToLast;
        for(int i = 0; i < N; i++)
        {
            if(temp->Index == index)
            {
                temp->Value = value;
            }
            temp = temp->PointerToPrevious;
        }
        std :: cout << "The provided value was set successfully.\n";
    }

    V get_item(I index)
    {
        List *temp = PointerToLast;
        for(int i = 0; i < N; i++)
        {
            if(temp->Index == index)
            {
                return temp->Value;
            }
            temp = temp->PointerToPrevious;
        }
        std :: cout << "No index was found.\n";
    }

    V& operator[](I index)
    {
        List *temp = PointerToLast;
        for(int i = 0; i < N; i++)
        {
            if(temp->Index == index)
            {
                return temp->Value;
            }
            temp = temp->PointerToPrevious;
        }
        std :: cout << "No index was found.\n";
    }

    void sort_ring()
    {
        std :: cout << "ASC - 1 | DESC - 2\n";
        int choice; std :: cin >> choice;
        switch (choice)
        {
        case 1:
            for(int i = 0; i < N; i++)
            {
                List *temp = PointerToLast;
                for(int j = 0; j < N - 1; j++)
                {
                    if(temp->Value < temp->PointerToPrevious->Value)
                    {
                    I temp_index = temp->Index;
                    V temp_value = temp->Value;

                    temp->Index = temp->PointerToPrevious->Index;
                    temp->Value = temp->PointerToPrevious->Value;
                    
                    temp->PointerToPrevious->Index = temp_index;
                    temp->PointerToPrevious->Value = temp_value;
                    }
                    temp = temp->PointerToPrevious;
                }
            }
            break;
        case 2:
            for(int i = 0; i < N; i++)
            {
                List *temp = PointerToLast;
                for(int j = 0; j < N - 1; j++)
                {
                    if(temp->Value > temp->PointerToPrevious->Value)
                    {
                    I temp_index = temp->Index;
                    V temp_value = temp->Value;

                    temp->Index = temp->PointerToPrevious->Index;
                    temp->Value = temp->PointerToPrevious->Value;
                    
                    temp->PointerToPrevious->Index = temp_index;
                    temp->PointerToPrevious->Value = temp_value;
                    }
                    
                    temp = temp->PointerToPrevious;
                }
            }
            break;
        default: std :: cout << "Invalid order. Please, try again." << std::endl;
        }
        std :: cout << "The ring was sorted successfully\n";
        Output();
    }

    void Output()
    {
        List *temp = PointerToLast->PointerToNext;
        std ::cout << "Index Value\n";
        for (int i = 0; i < N; i++)
        {
            std ::cout << temp->Index << "     " << temp->Value << ' ' << temp->PointerToPrevious << ' ' << temp  << ' ' << temp->PointerToNext << '\n';
            temp = temp->PointerToNext;
        }
    }
};

using namespace std;

int main()
{
    Ring<int, double> Ring;
    Ring.add_ring(1, 2.4);
    Ring.add_ring(2, 3.01);
    Ring.add_ring(5, 2.8);
    Ring.Output();
    bool running = true;
    int operation = 0; 
    while(running)
    {
        cout << "=================================\n"
        << "Welcome! Available functions are:\n"
        << "=================================\n"
        << "1. Add a value\n"
        << "2. Display the ring\n"
        << "3. Delete an element by index\n"
        << "4. Alter an index\n"
        << "5. Erase the ring\n"
        << "6. Get the quantity of the records\n"
        << "7. Set item\n"
        << "8. Get item\n"
        << "9. Sort the ring\n"
        << "10. Terminate the programm\n"
        << "=================================\n"
        << "Choose an operation: ";
        cin >> operation;
        switch (operation)
        {
            case 1:
            {
                cout << "Enter an index and a value to add: "; 
                int index; cin >> index;
                double Value; cin >> Value;
                Ring.add_ring(index, Value);
                cout << "The element was added successfully.\n";
                Ring.Output(); 
                break;
            }
            case 2:
            {
                Ring.Output(); 
                break;
            }
            case 3:
            {
                cout << "Enter an index to delete: ";
                int index; cin >> index;
                Ring.delete_list(index); 
                Ring.Output();
                break;
            }
            case 4:
            {
                cout << "Enter an index to alter: ";
                int index, new_index; cin >> index >> new_index;
                Ring.alter_index(index, new_index);
                Ring.Output();
                break;
            }
            case 5:
            {
                Ring.erase_ring();
                break;
            }
            case 6:
            {
                Ring.count();
                break;
            }
            case 7:
            {
                cout << "Enter the index and the value to set: ";
                int index; cin >> index; 
                double value; cin >> value;
                Ring.set_item(index, value);
                break;
            }
            case 8: 
            {
                cout << "Enter an index to get the value: ";
                int index; cin >> index;
                double ans = Ring.get_item(index);
                cout << ans << '\n';
                break;    
            }
            case 9:
            {
                Ring.sort_ring();  
                break;
            }
            case 10:
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