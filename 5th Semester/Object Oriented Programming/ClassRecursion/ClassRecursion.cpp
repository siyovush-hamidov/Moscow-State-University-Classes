#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

class Recursion
{
    public:

    int factorial(int n)
    {
        if(n == 0) return 1;
        return n * factorial(n - 1);
    }

    string o_triangle(int n, string temp)
    {
        if(n == 0)
        {
            std :: reverse(temp.begin(), temp.end());
            return temp;
        }
        while(n > 0)
        {
            temp+='\n';
            for(int i = 0; i < n; i++) temp+='o';
            return o_triangle(n - 1, temp);
        }
    }

    int fibonacci(int n)
    {
        if(n == 1) return 0;
        if(n == 2) return 1;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    int euclid(int a, int b)
    {
        if(b==0)
            return a;
        else
            return euclid(b,a%b);
    }

    int sum_of_digits(int n)
    {
        if(n % 10 == n) return n;
        return n % 10 + sum_of_digits(n / 10);
    }

    int quantity_of_digits(int n)
    {
        if(n % 10 == n) return 1;
        while(n % 10 != n) return quantity_of_digits(n / 10) + 1;    
    }

    string numeralise(int n, int k)
    {
        if(n / k == 0) return to_string(n);
        while(n / k != 0)
        {    
            return to_string(n % k) + numeralise(n / k, k);
        }
    }

    int reverse(int n)
    {
        if(n % 10 == n) return n;
        return ((n % 10) * pow(10,quantity_of_digits(n) - 1)) + reverse(n / 10);
    }

    int max_element(int *a, int n)
    {
        if(n == 1)
            return a[0];
        while(n > 0)
            return (a[n - 1] > max_element(a, n - 1)) ? a[n - 1] : max_element(a, n - 1);
    }

    double k_root(double x, int k, int n)
    {
        if(n == 0) 
            return 1;
        return k_root(x, k, n - 1) - (k_root(x, k, n - 1) - x/pow(k_root(x, k, n - 1), k - 1)) / k;
    }

    void tower_of_hanoi(int n, char A, char B, char C)
    {
        if (n == 1)
        {
            cout << A << " -> " << C << endl;
        }
        else
        {  
            tower_of_hanoi(n - 1, A, C, B);
            cout << A << " -> " << C << endl;
            tower_of_hanoi(n - 1, B, A, C);
        }
    }
};

int main()
{
    Recursion obj;
    int n; string temp, num;
    bool running = true;
    while(running)
    {
        cout << "\n=============================\nHello, User! Please choose a function to execute:\n";
        cout << "1. Factorial\n";
        cout << "2. O_Triangle\n";
        cout << "3. Fibonacci\n";
        cout << "4. Euclid\n";
        cout << "5. Sum_of_Digits\n";
        cout << "6. Quantity_of_Digits\n";
        cout << "7. Numeralise\n";
        cout << "8. Reverse\n";
        cout << "9. Max_Element\n";
        cout << "10. K_Root\n";
        cout << "11. Tower_of_Hanoi\n";
        cout << "Enter 12 to exit.\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Enter a number for factorial: ";
                cin >> n;
                cout << obj.factorial(n) << endl;
                break;
            case 2:
                cout << "Enter a number for o_triangle: ";
                cin >> n;
                cout << obj.o_triangle(n, temp);
                break;
            case 3:
                cout << "Enter a number for fibonacci: ";
                cin >> n;
                for(int i = 1; i <= n; i++) 
                    cout << obj.fibonacci(i) << ' ';
                cout << endl;
                break;
            case 4:
                int a, b;
                cout << "Enter two numbers for euclid: ";
                cin >> a >> b;
                cout << obj.euclid(a, b) << endl;
                break;
            case 5:
                cout << "Enter a number for sum_of_digits: ";
                cin >> n;
                cout << obj.sum_of_digits(n) << endl;
                break;
            case 6:
                cout << "Enter a number for quantity_of_digits: ";
                cin >> n;
                cout << obj.quantity_of_digits(n) << endl;
                break;
            case 7:
                int k;
                cout << "Enter two numbers for numeralise: ";
                cin >> n >> k;
                num = obj.numeralise(n,k); 
                reverse(num.begin(), num.end()); 
                cout << num << endl;
                break;
            case 8:
                cout << "Enter a number for reverse: ";
                cin >> n;
                cout << obj.reverse(n) << endl;
                break;
            case 9:
               
                cout << "Enter quantity of numbers and numbers themself for max_element: ";
                int n; cin >> n;
                int arr[n];
                for(int i=0; i<n; i++)
                    cin >> arr[i];
                cout << obj.max_element(arr,n) << endl;
                break;
            case 10:
                 double x;
                 cout<<"Enter three numbers X, K, N for k_root:";
                 cin>>x>>k>>n; 
                 cout<<obj.k_root(x,k,n)<<endl; 
                 break; 
            case 11:
                 char from, to, aux; 
                 cout<<"Enter the number of disks for tower_of_hanoi:";
                 cin>>n; 
                 obj.tower_of_hanoi(n, 'A', 'B', 'C');
                 break;
            case 12:
                running = false;
                exit(0);
            default:
                 cout << "Invalid option, please try again";
                 break; 
        }
    }
}
