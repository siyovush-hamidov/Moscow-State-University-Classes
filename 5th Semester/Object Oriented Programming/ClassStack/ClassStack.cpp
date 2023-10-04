#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

template <typename T>

class Stack
{
    struct Element{T value; Element* pointer_to_previous;};
    private:
    Element *pointer_to_last;
    public:
    
    Stack() : pointer_to_last(nullptr) {}

    void push(T value_to_push)
    {
        Element *new_record = new Element;
        new_record->value = value_to_push;      
        if(pointer_to_last == nullptr)
        {
            new_record->pointer_to_previous = nullptr;
            pointer_to_last = new_record;
        }
        else
        {
            new_record->pointer_to_previous = pointer_to_last;
            pointer_to_last = new_record;            
        }
    }
    void show()
    {
        std :: string ans = "";
        Element *current = pointer_to_last;
        std :: ostringstream any_stream;
        while(current != nullptr)
        {
            any_stream << current->value << ' ' <<current->pointer_to_previous << ' ' << current << '\n';
            current = current->pointer_to_previous;
        }
        std :: cout << any_stream.str();
    }
    void pop()
    {
        Element *deletion = pointer_to_last;
        pointer_to_last = deletion->pointer_to_previous;
        delete deletion;
    }
    T top()
    {
        std :: cout << pointer_to_last->value << ' ' << pointer_to_last << ' ' << pointer_to_last->pointer_to_previous<< '\n'   ;
        return pointer_to_last->value;
    }
    
};

using namespace std;

int main()
{
    Stack<double> Container;
    Container.push(5);
    Container.push(7);
    Container.push(1);
    Container.push(2);
    // Container.show();
    bool running = true;
    int operation = 0; 
    while(running)
    {
        cout << "=================================\n"
        << "Welcome! Available functions are:\n"
        << "=================================\n"
        << "1. Push\n"
        << "2. Top\n"
        << "3. Pop\n"
        << "4. Show\n"
        << "5. Terminate the programm\n"
        << "=================================\n"
        << "Choose an operation: ";
        cin >> operation;
        switch (operation)
        {
            case 1:
                cout << "Enter an index and a value to add: "; 
                double Value; cin >> Value;
                Container.push(Value);
                Container.show(); 
                break;
            case 2:
                Container.top();
                break;
            case 3:
                Container.pop();
                Container.show();
                break;
            case 4:
                Container.show();
                break;
            case 5:
                cout << "Terminating the program...";
                running = false;
                exit(0);
            default: cout << "Invalid option. Please, try again." << '\n';
        }
    }
}