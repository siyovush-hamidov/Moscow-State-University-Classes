#include <iostream>
#include <fstream>

template <typename K, typename V>

class Map
{
private:
    struct Element
    {
        K key;
        V value;
        int index;
    };
    Element *elements, *current_element;
    int size, capacity;
    V default_value;
    K default_key;

public:
    Map() : size(0), capacity(10) { elements = new Element[capacity]; }
    ~Map() { delete[] elements; }
    Map(K key, V value)
    {
        elements = new Element[1];
        elements[0] = {key, value};
        size = 1;
        capacity = 1;
        default_value = value;
        default_key = key;
    }
    bool if_key_is_present(K key_if_present)
    {
        for(int i = 0; i < size; i++)
        {
            if(elements[i].key == key_if_present)
            {
                return true;
            }
        }
        return false;
    }
    int count()
    {
        return size;
    }
    V find(K key_to_search_for)
    {
        for(int i = 0; i < size; i++)
        {
            if(elements[i].key == key_to_search_for)
            {
                return elements[i].value;
            }
        }
        std :: cout << "The key was not found. The default value will be returned. Please, enter the key once more.\n";
        return default_value;
    }
    K find(V value_to_search_for)
    {
        for(int i = 0; i < size; i++)
        {
            if(elements[i].value == value_to_search_for)
            {
                return elements[i].key;
            }
        }
        std :: cout << "The key was not found. The default key will be returned. Please, enter the value once more.\n";
        return default_key;
    }
    void refresh_indexes()
    {
        for(int i = 0; i < size; i++)
        {
            elements[i].index = i;
        }
        std :: cout << "Indexes were refreshed seuccessfully.\n";
    }
    void insert(K key_to_insert, V value_to_insert)
    {
        for(int i = 0; i < size; i++)
        {
            if(elements[i].key == key_to_insert)
            {
                elements[i].value = value_to_insert;
                return;
            }
        }
        if(size == capacity)
        {
            capacity *= 2;
            Element *new_elements = new Element[capacity];
            for(int i = 0; i < size; i++)
            {
                new_elements[i] = elements[i];
            }
            delete[] elements;
            elements = new_elements;
        }
        int temp = elements[size - 1].index;
        elements[size++] = {key_to_insert, value_to_insert, temp + 1};
    }
    void delete_element(int index_to_delete)
    {
        bool aha = false;
        if(size >= 0)
        {
            for(int i = 0; i < size; i++)
            {
                if(elements[i].index == index_to_delete && aha == false)
                {
                    index_to_delete = i;
                    aha = true;
                }
            }
            if(aha == false) 
                {
                    std :: cout <<"No index was found.\n";
                    return;
                }
            for(int i = index_to_delete; i < size - 1; i++)
            {
                elements[i] = elements[i + 1];
            }
            size--;
        }
        std :: cout << "The element was deleted successfully.\n";
    }
    void begin()
    {
        if(size > 0)
        {
            current_element = &elements[0];
        }
    }
    void end()
    {
        if(size > 0)
        {
            current_element = &elements[size - 1];
        } 
    }            
    void sort_map()
    {
        int choice;
        std :: cout << "Choose an order:\nAscending - 1 | Descending - 2: ";
        std :: cin >> choice;
        switch (choice)
        {
        case 1:
            for(int i = 0; i < size - 1; i++)
            {
                for(int j = i + 1; j < size; j++)
                {
                    if(elements[i].value > elements[j].value)
                    {
                        Element temp = elements[i];
                        elements[i] = elements[j];
                        elements[j] = temp; 
                    }
                }
            }
            break;
        case 2:
            for(int i = 0; i < size - 1; i++)
            {
                for(int j = i + 1; j < size; j++)
                {
                    if(elements[i].value < elements[j].value)
                    {
                        Element temp = elements[i];
                        elements[i] = elements[j];
                        elements[j] = temp; 
                    }
                }
            }
            break;
        default:
            break;
        } 
    }   
    V& operator[](K key_to_search)
    {
        for(int i = 0; i < size; i++)
        {
            if(elements[i].key == key_to_search)
            {
                return elements[i].value;
            }
        }
        std :: cout << "No such a key was found.\n";
        return default_value;
    }
    void show()
    {
        begin();
        for(int i = 0; i < size; i++)
        {
            std::cout << "Index: " << current_element->index << " Key: " << current_element->key << " Value: " << current_element->value << std::endl;
            ++current_element;
        }
        begin();
    }
    void save_to_file()
    {
        std :: ofstream file("Result.txt");
        for(int i = 0; i < size; i++)
        {
            file << elements[i].index << ' ' << elements[i].key << ' ' << elements[i].value << '\n';
        }   
        std :: cout << "The file was saved successfully to Result.txt" << std :: endl;
    }
};

using namespace std;

int main()
{
    Map<int,string> map(0, "Default value");
    map.insert(1, "First");
    map.insert(2, "Fiars");
    map.insert(3, "Third");

    bool running = true;
    int operation = 0; 
    while(running)
    {
        cout << "=================================\nWelcome!\n=================================\n1. Get the quantity of elements\n2. Find an element by key\n3. Find an element by value\n4. Refresh indexes\n5. Insert an element\n6. Delete an element by index\n7. Sort the map\n8. Save to file\n9. Print the map\n10. Exit the program\n=================================\nChoose an operation: "; 
        cin >> operation;

        switch (operation)
        {
            case 1:
            {
                int quan = map.count();
                cout <<"The quantity is: " << quan << '\n';
                break;
            }
            case 2:
            {
                int key;
                string value;
                cout << "Enter the key to search for: ";
                cin >> key;
                value = map.find(key);
                cout << value << " was found."<< '\n';
                break;
            }
            case 3:
            {
                cin.ignore();
                int key;
                string value;
                cout << "Enter the value to search for: ";
                getline(cin, value);
                key = map.find(value);
                cout << key << " was found." << '\n';
                break;
            }
            case 4:
            {
                map.refresh_indexes();
                map.show();
                break;
            }
            case 5:
            {
                int k; string v;
                cout << "Enter the key to insert: ";
                cin >> k;
                cout << "Enter the value to insert: ";
                cin.ignore();
                getline(cin, v);
                if(map.if_key_is_present(k))
                {
                    cout << "The key is already in use, so the element's value will be altered.\n";
                }
                map.insert(k, v);
                std :: cout << "The element was inserted successfully.\n";
                map.show();
                break;
            }
            case 6:
            {
                int index_to_delete;
                cout << "Enter the index to delete: ";
                cin >> index_to_delete;
                map.delete_element(index_to_delete);
                map.show();
                break;
            }
            case 7:
            {
                map.sort_map();
                map.show();
                break;
            }
            case 8: 
            {
                map.save_to_file();
                break;
            }
            case 9:
            {
                map.show();
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