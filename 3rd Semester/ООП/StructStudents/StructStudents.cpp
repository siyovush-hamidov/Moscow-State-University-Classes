#include <iostream>
#include <string>

using namespace std;

struct Student {
 string name, byear, address, phone;
};

Student Write(Student s)
{

    cin >> s.name >> s.byear >> s.address >> s.phone;
    return s;
}

Student Print(Student s)
{

    cout<<s.name<<" "<<s.byear<<" "<<s.address<<" "<<s.phone;
    return s;
}

void Searhing(string s, Student *b, int n)
{
    for(int i=0; i<n; i++){
        if(s == b[i].name){
            Print(b[i]);
            cout << "\n";
        }
    }

}


void Sorting(Student *b, int n)
{
    for(int i=0; i < n; i++){
        for(int j =0; j<n-1; j++){
            if(b[j].name > b[j+1].name){
                swap(b[j],b[j+1]);
            }
        }
    }
}



int main()
{
    Student s[100], x;
    int n = 0;
    while(n < 5){
        x = Write(x);
        s[n] = x;
        n++;
    }
    n = 0;
    string c;
    cin>>c;
    Searhing(c,s,5);
    Sorting(s,5);

    while(n < 5){
        Print(s[n]);
        cout<<"\n";
        n++;
    }
    //s = Write(s);
    //Print(s);
}
