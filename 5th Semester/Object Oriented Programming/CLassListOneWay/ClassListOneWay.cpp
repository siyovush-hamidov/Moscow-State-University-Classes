#include <iostream>
#include <string>
#include <fstream>

template <typename T>
class ListOneWay
{
    struct List 
    {
        int Index; 
        T Value; 
        List *PointerToNext;
    };
private:
    List *PointerToFirst; int QuantityOfLists;
public:

    ListOneWay() : PointerToFirst(nullptr), QuantityOfLists(0) {}

    void AddList(T Value)
    {  
        List* NewRecord = new List;
        NewRecord->Value = Value;
        NewRecord->Index = 0;
        NewRecord->PointerToNext = nullptr;

        if(QuantityOfLists == 0)
        {
            PointerToFirst = NewRecord;
        }
        else
        {
            List* Current = new List; Current = PointerToFirst; Current->Index = 0;
            List* Previous = new List; Previous = nullptr;

            int index = 1;

            while(Current != nullptr)
            {
                Previous = Current;
                NewRecord->Index = index++;
                Current = Current->PointerToNext;
            }
            Previous->PointerToNext = NewRecord;
            
        }
        QuantityOfLists++;
    }

    void DeleteList(int index)
    {
        if (index >= QuantityOfLists) return;

        List* current = new List; current = PointerToFirst;
        List* previous = new List; previous = nullptr;

        for (int i = 0; i < index; i++) 
        {
            previous = current;
            current = current->PointerToNext;
        }

        if (previous != nullptr) 
        {
            previous->PointerToNext = current->PointerToNext;
        } 
        else 
        {
            PointerToFirst = current->PointerToNext;
        }

        delete current;
        QuantityOfLists--;
        Output();
    }

    void RefreshIndexes()
    {
        List* Current = new List;
        Current = PointerToFirst;

        int index = 0;

        while(Current != nullptr)
        {
            Current->Index = index++;
            Current = Current->PointerToNext;
        }
    }

    void SortList()
    {
        for(int i = 1; i < QuantityOfLists; i++)
        {
            T key = (*this)[i];
            int left = 0;
            int right = i;
            
            while(left < right)
            {
                int mid = left + (right - left) / 2;
                if(key < (*this)[mid])
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            for(int j = i; j > left; j--)
            {
                (*this)[j] = (*this)[j - 1];
            }
            (*this)[left] = key;
        }
        Output();
    }

    void SortListDesc()
    {
        for(int i = 1; i < QuantityOfLists; i++)
        {
            T key = (*this)[i];
            int left = 0;
            int right = i;
            
            while(left < right)
            {
                int mid = left + (right - left) / 2;
                if(key > (*this)[mid])
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            for(int j = i; j > left; j--)
            {
                (*this)[j] = (*this)[j - 1];
            }
            (*this)[left] = key;
        }
        Output();
    }

    void EraseList()
    {
        PointerToFirst = nullptr; 
        QuantityOfLists = 0; 
        std :: cout << "The list was erased successfully.\n";
        Output();
    }

    int CountOfLists()
    {
        return QuantityOfLists;
    }

    void Round()
    {
        for(int i = 0; i < QuantityOfLists; i++)
        {
            if((*this)[i] - 0.5 > int((*this)[i]))
            {
                (*this)[i] = int((*this)[i] + 0.5);
            }
            else
            {
                (*this)[i] = int((*this)[i]); 
            }
        }
    }

    void MakeListWhole()
    {
        for(int i = 0; i < QuantityOfLists; i++)
        {
            (*this)[i] = int((*this)[i]);
        }
    }

    void MakeListFractional()
    {
        for(int i = 0; i < QuantityOfLists; i++)
        {
            (*this)[i] = (*this)[i] - int((*this)[i]);
        }    
    }

    std :: string ListToString()
    {
        std :: string result = "";

        List* current = new List;
        current = PointerToFirst;
        while(current != nullptr)
        {
            result += std::to_string(current->Value) + " ";
            current = current->PointerToNext;
        }
        std :: cout << result << '\n';
        return result; 
    }

    void SaveToFile(std :: string FileName)
    {
        std :: ofstream file(FileName);
        
        for(int i = 0; i < QuantityOfLists; i++)
        {
            file << (*this)[i] << ' ';
        }
        this->Output();
        std :: cout << "The file was saved successfully to '"+FileName+"'" << std :: endl;
    }

    void LoadFromFile(std :: string FileName)
    {
        this->EraseList();
        std :: ifstream file(FileName);
        T temp; int i = 0;
        while(file >> temp)
        {
            this->AddList(temp);
        }
        
        this->Output();
        std :: cout << "The list was loaded from File '"+FileName+"' successfully" << std :: endl;
    }

    T& operator[](int Index)
    {
        if(Index >= QuantityOfLists) std :: cout << "Index out of range\n";

        List* Current = new List;
        Current = PointerToFirst;
        
        for(int i = 0; i < Index; i++)
        {
            Current = Current->PointerToNext;
        }

        return Current->Value;
    }
    
    void OutputByIndex(int index)
    {
        std :: cout << "ID|Value\n";
        List* current = new List;
        current = PointerToFirst;

        for(int i = 0; i < index; i++)
        {
            current = current->PointerToNext;
        } 
        std :: cout << current->Index + 1 << ". " << current->Value << '\n';
    }
    
    void Output()
    {
        std :: cout << "=================================\n";
        std :: cout << "ID|Value\n";

        List* current = new List;
        current = PointerToFirst;

        for(int i = 0; i < QuantityOfLists; i++)
        {
            std :: cout << current->Index + 1 << ". " << current->Value << '\n';
            current = current->PointerToNext;
        }

        std :: cout << std :: endl;
    }
};

using namespace std;

int main()
{
    ListOneWay<double> List;
    for(int i = 1; i < 6; i++) List.AddList(i);
    bool running = true;
    int operation = 0; 
    while(running)
    {
        cout << "=================================\nWelcome! Available functions are:\n=================================\n1. Add a value to a list\n2. Delete a value by index\n3. Erase the whole list\n4. Sort the list (Insertion Sort)\n5. Get the quantity of records in the list\n6. Invert the list to String type\n7. Save the list to file\n8. Load from file\n9. Print the list\n10. Print by index\n11. Refresh indexes\n12. Round all the numbers\n13. Make all the numbers whole\n14. Make all the numbers fractional\n15. Exit the program\n=================================\nChoose an operation: "; 
        cin >> operation;

        switch (operation)
        {
            case 1:
            {
                cout << "Enter a value to add: "; double Value; cin >> Value;
                List.AddList(Value);
                List.Output(); 
                break;
            }
            case 2:
            {
                List.Output();
                cout << "Enter an index to delete: "; int index; cin >> index;
                List.DeleteList(index - 1);
                break;
            }
            case 3:
            {
                List.EraseList(); 
                break;
            }
            case 4:
            {
                cout << "Choose method to sort: 1 - ASC | 2 - DESC: "; int choose; cin >> choose;
                switch (choose)
                {
                case 1:
                {
                    List.SortList();
                    break;
                }
                case 2:
                {
                    List.SortListDesc();
                    break;
                }
                default: break;
                }
                break;
            }
            case 5:
            {
                cout << "=================================\n";
                cout << "Quntity of records is: "<< List.CountOfLists() << '\n';   
                break;
            }
            case 6:
            {
                cout << "Name a string to assign: "; string result; cin >> result;
                result = List.ListToString();
                break;
            }
            case 7:
            {
                cout << "Name a file to save to: "; string FileName; cin >> FileName;
                FileName += ".txt";
                List.SaveToFile(FileName);
                break;
            }
            case 8: 
            {
                cout << "Name a file to load from: "; string FileName; cin >> FileName;
                List.LoadFromFile(FileName);
                break;
            }
            case 9:
            {
                List.Output();    
                break;
            }
            case 10:
            {
                cout << "Enter the index: ";
                int IndexToOutput; cin >> IndexToOutput;
                List.OutputByIndex(IndexToOutput - 1);
                break;
            }
            case 11:
            {
                List.RefreshIndexes();
                List.Output();
                break;
            }
            case 12:
            {
                List.Round(); List.Output();
                break;
            }
            case 13:
            {
                List.MakeListWhole();
                List.Output();
                break;
            } 
            case 14:
            {
                List.MakeListFractional();
                List.Output();
                break;
            } 
            case 15:
            {
                cout << "Terminating the program..."; running = false;
                exit(0);
            } 
            default: cout << "Invalid option. Please, try again." << endl;
        }
    }
    return 0;
}