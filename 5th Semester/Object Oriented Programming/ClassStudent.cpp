#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename S, typename I>

class Student {
public:
    S name, surname, patronymic, direction, sport, address, phone;
    I birth_year, age, course;

    Student(S surname, S name, S patronymic, I birth_year, S direction, I age, S sport, S address, S phone, I course) : name(name), surname(surname), patronymic(patronymic), birth_year(birth_year), direction(direction), age(age), sport(sport), address(address), phone(phone), course(course) {}
    Student() {}

    static void PrintAll(vector<Student>& Students)
    {
        ofstream file("ClassStudent.txt");
        for(int i = 0; i < Students.size(); i++)
        {
            cout << Students[i].surname << ' ' << Students[i].name << ' ' << Students[i].patronymic << ' ' << Students[i].birth_year << ' ' << Students[i].direction << ' ' << Students[i].age << ' ' << Students[i].sport << ' ' << Students[i].address << ' ' << Students[i].phone << ' ' << Students[i].course << '\n';
            file << Students[i].surname << ' ' << Students[i].name << ' ' << Students[i].patronymic << ' ' << Students[i].birth_year << ' ' << Students[i].direction << ' ' << Students[i].age << ' ' << Students[i].sport << ' ' << Students[i].address << ' ' << Students[i].phone << ' ' << Students[i].course << '\n';
        }
        file.close();
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
    }

    static void PrintSingle(vector<Student>& Students, int i)
    {
        cout << Students[i].surname << ' ' << Students[i].name << ' ' << Students[i].patronymic << ' ' << Students[i].birth_year << ' ' << Students[i].direction << ' ' << Students[i].age << ' ' << Students[i].sport << ' ' << Students[i].address << ' ' << Students[i].phone << ' ' << Students[i].course << '\n';
        ofstream file("ClassStudent.txt");
        file << Students[i].surname << ' ' << Students[i].name << ' ' << Students[i].patronymic << ' ' << Students[i].birth_year << ' ' << Students[i].direction << ' ' << Students[i].age << ' ' << Students[i].sport << ' ' << Students[i].address << ' ' << Students[i].phone << ' ' << Students[i].course << '\n';
        file.close();
    }

    static void PrintStudent(const Student& A)
    {
        cout << A.surname << ' ' << A.name << ' ' << A.patronymic << ' ' << A.birth_year << ' ' << A.direction << ' ' << A.age << ' ' << A.sport << ' ' << A.address << ' ' << A.phone << ' ' << A.course << '\n';
        ofstream file("ClassStudent.txt");
        file << A.surname << ' ' << A.name << ' ' << A.patronymic << ' ' << A.birth_year << ' ' << A.direction << ' ' << A.age << ' ' << A.sport << ' ' << A.address << ' ' << A.phone << ' ' << A.course << '\n';
        file.close();
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
    }

    static void AddStudent(vector<Student>& Students, Student student)
    {
        Students.push_back(student);
    }

    static void InputAndAddStudent(vector<Student>& Students)
    {
        Student<string,int> student;

        cout << "Surname: "; cin >> student.surname;
        cout << "Name: "; cin >> student.name;
        cout << "Patronymic: "; cin >> student.patronymic;
        cout << "Birth Year: "; cin >> student.birth_year;
        cout << "Direction: "; cin >> student.direction;
        cout << "Age: "; cin >> student.age;
        cout << "Sport: "; cin >> student.sport;
        cout << "Address: "; cin >> student.address;
        cout << "Phone Number: "; cin >> student.phone;
        cout << "Course: "; cin >> student.course;

        Students.push_back(student);
    }

    static void InputAndAddStudentViaFile(vector<Student>& Students)
    {
        Student<string,int> student;
        
        ifstream file("ClassStudentInputStudent.txt");
        if(file.is_open())
        {
            getline(file, student.surname, ',');
            getline(file, student.name, ',');
            getline(file, student.patronymic, ',');
            file >> student.birth_year; file.ignore();
            getline(file, student.direction, ',');
            file >> student.age; file.ignore();
            getline(file, student.sport, ',');
            getline(file, student.address, ',');
            getline(file, student.phone, ',');
            file >> student.course;

            Students.push_back(student);
        }
        else
        {
            cout << "Error opening the file!" << endl;
        }
    }

    static void RemoveStudent(vector<Student>& Students, int IndexOfStudent)
    {
        Students.erase(Students.begin() + IndexOfStudent);
    }

    static bool CompareStudentsBySurname(const Student& A, const Student& B)
    {
        return A.surname < B.surname;
    }

    static void SortStudentsBySurname(vector<Student>& Students)
    {
        sort(Students.begin(), Students.end(), CompareStudentsBySurname);
    }

    static void UpdateStudentSurname(vector<Student>& Students, int index, S CodeWord)
    {
        Students[index].surname = CodeWord;
        // Students[index].surname = CodeWord;
    }
    static void UpdateStudentName(vector<Student>& Students, int index, S CodeWord)
    {
        Students[index].name = CodeWord;
    }
    static void UpdateStudentPatronymic(vector<Student>& Students, int index, S CodeWord)
    {
        Students[index].patronymic = CodeWord;
    }
    static void UpdateStudentBirthYear(vector<Student>& Students, int index, I CodeWord)
    {
        Students[index].birth_year = CodeWord;
    }
    static void UpdateStudentDirection(vector<Student>& Students, int index, S CodeWord)
    {
        Students[index].direction = CodeWord;
    }
    static void UpdateStudentAge(vector<Student>& Students, int index, I CodeWord)
    {
        Students[index].age = CodeWord;
    }
    static void UpdateStudentSport(vector<Student>& Students, int index, S CodeWord)
    {
        Students[index].sport = CodeWord;
    }
    static void UpdateStudentAddress(vector<Student>& Students, int index, S CodeWord)
    {
        Students[index].address = CodeWord;
    }
    static void UpdateStudentPhone(vector<Student>& Students, int index, S CodeWord)
    {
        Students[index].phone = CodeWord;
    }
    static void UpdateStudentCourse(vector<Student>& Students, int index, I CodeWord)
    {
        Students[index].course = CodeWord;
    }
    static void UpdateStudent(vector<Student>& Students)
    {
        cout << "Choose the student's index: \n";
        for(int i = 0; i < Students.size(); i++)
        {
            cout << i + 1; cout << ' '; Student<string,int> :: PrintSingle(Students, i);
        }
        cout << "Enter the index: ";
        int IndexOfChosenStudentForUpdating; cin >> IndexOfChosenStudentForUpdating;

        cout << "Choose a field to change: \n 1 - Surname \n 2 - Name \n 3 - Patronymic \n 4 - Birth Year \n 5 - Direction \n 6 - Age \n 7 - Sport \n 8 - Address \n 9 - Phone Number \n 10 - Course \n Pick an operation: ";
        int Choice; cin >> Choice;
        
        S CodeString; I CodeInt;
        
        switch(Choice)
        {
        case 1:
            {
                cout << "Enter the surname: "; cin >> CodeString; Student<string,int> :: UpdateStudentSurname(Students, IndexOfChosenStudentForUpdating - 1, CodeString); break;
            }
        case 2:
           {
               cout << "Enter the name: "; cin >> CodeString; Student<string,int> :: UpdateStudentName(Students, IndexOfChosenStudentForUpdating - 1, CodeString); break;
           }
        case 3:
            {
               cout << "Enter the patronymic: "; cin >> CodeString; Student<string,int> :: UpdateStudentPatronymic(Students, IndexOfChosenStudentForUpdating - 1, CodeString); break;
            }
        case 4:
            {
               cout << "Enter the birth year: "; cin >> CodeInt; Student<string,int> :: UpdateStudentBirthYear(Students, IndexOfChosenStudentForUpdating - 1, CodeInt); break;
            }
        case 5:
            {
               cout << "Enter the direction: "; cin >> CodeString; Student<string,int> :: UpdateStudentDirection(Students, IndexOfChosenStudentForUpdating - 1, CodeString); break;
            }
        case 6:
            {
               cout << "Enter the age: "; cin >> CodeInt; Student<string,int> :: UpdateStudentAge(Students, IndexOfChosenStudentForUpdating - 1, CodeInt); break;
            }
        case 7:
            {
               cout << "Enter the sport: "; cin >> CodeString; Student<string,int> :: UpdateStudentSport(Students, IndexOfChosenStudentForUpdating - 1, CodeString); break;
            }
        case 8:
            {
               cout << "Enter the address: "; cin >> CodeString; Student<string,int> :: UpdateStudentAddress(Students, IndexOfChosenStudentForUpdating - 1, CodeString); break;
            }
        case 9:
            {
               cout << "Enter the phone number: "; cin >> CodeString; Student<string,int> :: UpdateStudentPhone(Students, IndexOfChosenStudentForUpdating - 1, CodeString); break;
            }
        case 10:
            {
               cout << "Enter the course: "; cin >> CodeInt; Student<string,int> :: UpdateStudentCourse(Students, IndexOfChosenStudentForUpdating - 1, CodeInt); break;
            }
        }
    }

    static vector<Student*> FindStudentBySurname(vector<Student>& Students, S CodeWord)
    {
        vector<Student*> foundStudents;
        ofstream file("ClassStudent.txt");
        cout << "Search for '" << CodeWord << "' returned: " << '\n';
        for(typename vector<Student> :: iterator it = Students.begin(); it != Students.end(); ++it)
        {
            if(it->surname == CodeWord)
            {
                file << it->surname << ' ' << it->name << ' ' << it->patronymic << ' ' << it->birth_year << ' ' << it->direction << ' ' << it->age << ' ' << it->sport << ' ' << it->address << ' ' << it->phone << ' ' << it->course << '\n';
                cout << it->surname << ' ' << it->name << ' ' << it->patronymic << ' ' << it->birth_year << ' ' << it->direction << ' ' << it->age << ' ' << it->sport << ' ' << it->address << ' ' << it->phone << ' ' << it->course << '\n';
                foundStudents.push_back(&(*it));
            }
        }
        file.close();
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
        return foundStudents;
    }
    static vector<Student*> FindStudentByName(vector<Student>& Students, S CodeWord)
    {
        vector<Student*> foundStudents;
        cout << "Search for '" << CodeWord <<"' returned: " << '\n';
        ofstream file("ClassStudent.txt");
        for(typename vector<Student> :: iterator it = Students.begin(); it != Students.end(); ++it)
        {
            if(it->name == CodeWord)
            {
                file << it->surname << ' ' << it->name << ' ' << it->patronymic << ' ' << it->birth_year << ' ' << it->direction << ' ' << it->age << ' ' << it->sport << ' ' << it->address << ' ' << it->phone << ' ' << it->course << '\n';
                cout << it->surname << ' ' << it->name << ' ' << it->patronymic << ' ' << it->birth_year << ' ' << it->direction << ' ' << it->age << ' ' << it->sport << ' ' << it->address << ' ' << it->phone << ' ' << it->course << '\n';
                foundStudents.push_back(&(*it));
            }
        }
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
        file.close();
        return foundStudents;
    }
    static vector<Student*> FindStudentByPatronymic(vector<Student>& Students, S CodeWord)
    {
        vector<Student*> foundStudents;
        cout << "Search for '" << CodeWord <<"' returned: " << '\n';
        ofstream file("ClassStudent.txt");
        for(typename vector<Student> :: iterator it = Students.begin(); it != Students.end(); ++it)
        {
            if(it->patronymic == CodeWord)
            {
                file << it->surname << ' ' << it->name << ' ' << it->patronymic << ' ' << it->birth_year << ' ' << it->direction << ' ' << it->age << ' ' << it->sport << ' ' << it->address << ' ' << it->phone << ' ' << it->course << '\n';
                cout << it->surname << ' ' << it->name << ' ' << it->patronymic << ' ' << it->birth_year << ' ' << it->direction << ' ' << it->age << ' ' << it->sport << ' ' << it->address << ' ' << it->phone << ' ' << it->course << '\n';
                foundStudents.push_back(&(*it));
            }
        }
        file.close();
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
        return foundStudents;
    }
    static vector<Student*> FindStudentByBirthYear(vector<Student>& Students, I CodeWord)
    {
        cout << "Search for '" << CodeWord <<"' returned: " << '\n';
        vector<Student*> foundStudents;
        ofstream file("ClassStudent.txt");
        for(typename vector<Student> :: iterator it = Students.begin(); it != Students.end(); ++it)
        {
            if(it->birth_year == CodeWord)
            {
                file << it->surname << ' ' << it->name << ' ' << it->patronymic << ' ' << it->birth_year << ' ' << it->direction << ' ' << it->age << ' ' << it->sport << ' ' << it->address << ' ' << it->phone << ' ' << it->course << '\n';
                cout << '\n' << it->surname << ' ' << it->name << ' ' << it->patronymic << ' ' << it->birth_year << ' ' << it->direction << ' ' << it->age << ' ' << it->sport << ' ' << it->address << ' ' << it->phone << ' ' << it->course << '\n';
                foundStudents.push_back(&(*it));
            }
        }
        file.close();
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
        return foundStudents;
    }
    static vector<Student*> FindStudentByDirection(vector<Student>& Students, S CodeWord)
    {
        cout << "Search for '" << CodeWord <<"' returned: " << '\n';
        vector<Student*> foundStudents;
        ofstream file("ClassStudent.txt");
        for(typename vector<Student> :: iterator it = Students.begin(); it != Students.end(); ++it)
        {
            if(it->direction == CodeWord)
            {
                file << it->surname << ' ' << it->name << ' ' << it->patronymic << ' ' << it->birth_year << ' ' << it->direction << ' ' << it->age << ' ' << it->sport << ' ' << it->address << ' ' << it->phone << ' ' << it->course << '\n';
                cout << '\n' << it->surname << ' ' << it->name << ' ' << it->patronymic << ' ' << it->birth_year << ' ' << it->direction << ' ' << it->age << ' ' << it->sport << ' ' << it->address << ' ' << it->phone << ' ' << it->course << '\n';
                foundStudents.push_back(&(*it));
            }
        }
        file.close();
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
        return foundStudents;
    }
    static vector<Student*> FindStudentByAge(vector<Student>& Students, I CodeWord)
    {
        cout << "Search for '" << CodeWord <<"' returned: " << '\n';
        vector<Student*> foundStudents;
        ofstream file("ClassStudent.txt");
        for(typename vector<Student> :: iterator it = Students.begin(); it != Students.end(); ++it)
        {
            if(it->age == CodeWord)
            {
                file << it->surname << ' ' << it->name << ' ' << it->patronymic << ' ' << it->birth_year << ' ' << it->direction << ' ' << it->age << ' ' << it->sport << ' ' << it->address << ' ' << it->phone << ' ' << it->course << '\n';
                cout << it->surname << ' ' << it->name << ' ' << it->patronymic << ' ' << it->birth_year << ' ' << it->direction << ' ' << it->age << ' ' << it->sport << ' ' << it->address << ' ' << it->phone << ' ' << it->course << '\n';
                foundStudents.push_back(&(*it));
            }
        }
        file.close();
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
        return foundStudents;
    }
    static vector<Student*> FindStudentBySport(vector<Student>& Students, S CodeWord)
    {
        vector<Student*> foundStudents;
        cout << "Search for '" << CodeWord <<"' returned: " << '\n';
        ofstream file("ClassStudent.txt");
        for(typename vector<Student> :: iterator it = Students.begin(); it != Students.end(); ++it)
        {
            if(it->sport == CodeWord)
            {
                file << it->surname << ' ' << it->name << ' ' << it->patronymic << ' ' << it->birth_year << ' ' << it->direction << ' ' << it->age << ' ' << it->sport << ' ' << it->address << ' ' << it->phone << ' ' << it->course << '\n';
                cout << it->surname << ' ' << it->name << ' ' << it->patronymic << ' ' << it->birth_year << ' ' << it->direction << ' ' << it->age << ' ' << it->sport << ' ' << it->address << ' ' << it->phone << ' ' << it->course << '\n';
                foundStudents.push_back(&(*it));
            }
        }
        file.close();
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
        return foundStudents;
    }
    static vector<Student*> FindStudentByAddress(vector<Student>& Students, S CodeWord)
    {
        vector<Student*> foundStudents;
        cout << "Search for '" << CodeWord <<"' returned: " << '\n';
        ofstream file("ClassStudent.txt");
        for(typename vector<Student> :: iterator it = Students.begin(); it != Students.end(); ++it)
        {
            if(it->address == CodeWord)
            {
                file << it->surname << ' ' << it->name << ' ' << it->patronymic << ' ' << it->birth_year << ' ' << it->direction << ' ' << it->age << ' ' << it->sport << ' ' << it->address << ' ' << it->phone << ' ' << it->course << '\n';
                cout << it->surname << ' ' << it->name << ' ' << it->patronymic << ' ' << it->birth_year << ' ' << it->direction << ' ' << it->age << ' ' << it->sport << ' ' << it->address << ' ' << it->phone << ' ' << it->course << '\n';
                foundStudents.push_back(&(*it));
            }
        }
        file.close();
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
        return foundStudents;
    }
    static vector<Student*> FindStudentByPhone(vector<Student>& Students, S CodeWord)
    {
        vector<Student*> foundStudents;
        cout << "Search for '" << CodeWord <<"' returned: " << '\n';
        ofstream file("ClassStudent.txt");
        for(typename vector<Student> :: iterator it = Students.begin(); it != Students.end(); ++it)
        {
            if(it->phone == CodeWord)
            {
                file << it->surname << ' ' << it->name << ' ' << it->patronymic << ' ' << it->birth_year << ' ' << it->direction << ' ' << it->age << ' ' << it->sport << ' ' << it->address << ' ' << it->phone << ' ' << it->course << '\n';
                cout << it->surname << ' ' << it->name << ' ' << it->patronymic << ' ' << it->birth_year << ' ' << it->direction << ' ' << it->age << ' ' << it->sport << ' ' << it->address << ' ' << it->phone << ' ' << it->course << '\n';
                foundStudents.push_back(&(*it));
            }
        }
        file.close();
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
        return foundStudents;
    }
    static vector<Student*> FindStudentByCourse(vector<Student>& Students, I CodeWord)
    {
        vector<Student*> foundStudents; 
        cout << "Search for '" << CodeWord <<"' returned: " << '\n';
        ofstream file("ClassStudent.txt");
        for(typename vector<Student> :: iterator it = Students.begin(); it != Students.end(); ++it)
        {
            if(it->course == CodeWord)
            {
                file << it->surname << ' ' << it->name << ' ' << it->patronymic << ' ' << it->birth_year << ' ' << it->direction << ' ' << it->age << ' ' << it->sport << ' ' << it->address << ' ' << it->phone << ' ' << it->course << '\n';
                cout << it->surname << ' ' << it->name << ' ' << it->patronymic << ' ' << it->birth_year << ' ' << it->direction << ' ' << it->age << ' ' << it->sport << ' ' << it->address << ' ' << it->phone << ' ' << it->course << '\n';
                foundStudents.push_back(&(*it));
            }
        }
        file.close();
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
        return foundStudents;
    }  
    static Student* FindStudent(vector<Student>& Students)
    {
        cout << "Choose a field to search for: \n 1 - Surname \n 2 - Name \n 3 - Patronymic \n 4 - Birth Year \n 5 - Direction \n 6 - Age \n 7 - Sport \n 8 - Address \n 9 - Phone Number \n 10 - Course \n Pick an operation: ";
        int Choice; cin >> Choice;
        S CodeString;
        I CodeInt;
        switch(Choice)
        {
        case 1:
            {
                cout << "Enter the surname: "; cin >> CodeString; Student<string,int> :: FindStudentBySurname(Students, CodeString); break;
            }
        case 2:
           {
               cout << "Enter the name: "; cin >> CodeString; Student<string,int> :: FindStudentByName(Students, CodeString); break;
           }
        case 3:
            {
               cout << "Enter the patronymic: "; cin >> CodeString; Student<string,int> :: FindStudentByPatronymic(Students, CodeString); break;
            }
        case 4:
            {
               cout << "Enter the birth year: "; cin >> CodeInt; Student<string,int> :: FindStudentByBirthYear(Students, CodeInt); break;
            }
        case 5:
            {
               cout << "Enter the direction: "; cin >> CodeString; Student<string,int> :: FindStudentByDirection(Students, CodeString); break;
            }
        case 6:
            {
               cout << "Enter the age: "; cin >> CodeInt; Student<string,int> :: FindStudentByAge(Students, CodeInt); break;
            }
        case 7:
            {
               cout << "Enter the sport: "; cin >> CodeString; Student<string,int> :: FindStudentBySport(Students, CodeString); break;
            }
        case 8:
            {
               cout << "Enter the address: "; cin >> CodeString; Student<string,int> :: FindStudentByAddress(Students, CodeString); break;
            }
        case 9:
            {
               cout << "Enter the phone number: "; cin >> CodeString; Student<string,int> :: FindStudentByPhone(Students, CodeString); break;
            }
        case 10:
            {
               cout << "Enter the course: "; cin >> CodeInt; Student<string,int> :: FindStudentByCourse(Students, CodeInt); break;
            }
        }
        return NULL;
    }
};

int main()
{
    vector<Student<string,int> > Students;

    Student<string,int> Siyovush("Hamidov", "Siyovush", "Khalifaboboevich", 2002, "AMI", 21, "Gymnastics", "Rudaki Ave.", "+992901643003", 3); Student<string,int> :: AddStudent(Students, Siyovush);
    Student<string,int> Misha("Kuzmin", "Michael", "Dmitrievich", 2003, "AMI", 20, "Pylates", "7th KM", "+992901000000", 3); Student<string,int> :: AddStudent(Students, Misha);
    
    int MainMenu;
    do
    {
        cout << "\nWelcome! Choose an operation: \n 1 - Print all students \n 2 - Print a student by index \n 3 - Remove a student by index \n 4 - Enter an information about a student and add the student \n 5 - Sort by surname \n 6 - Update an information about a student \n 7 - Find a student \n 8 - Enter an information about a student and add the student via file \n 9 - Exit \n Enter the number: ";
        cin >> MainMenu; cout << "\n|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
    
        switch (MainMenu)
        {
        case 1:
        {
            Student<string,int> :: PrintAll(Students); break;
        }
        case 2:
        {
            cout << "Choose the student's index: \n";
            for(int i = 0; i < Students.size(); i++)
            {
                cout << i + 1; cout << ' '; Student<string,int> :: PrintSingle(Students, i);
            }
            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
            cout << "Enter the index: "; int IndexToShow; cin >> IndexToShow;
            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
            Student<string,int> :: PrintSingle(Students, IndexToShow - 1); cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
            break;
        }
        case 3:
        {   
            cout << "Choose the student's index: \n";
            for(int i = 0; i < Students.size(); i++)
            {
                cout << i + 1; cout << ' '; Student<string,int> :: PrintSingle(Students, i);
            }

            cout << "Enter the index: "; int IndexToRemove; cin >> IndexToRemove;
            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
            Student<string,int> :: RemoveStudent(Students, IndexToRemove - 1); 
            Student<string,int> :: PrintAll(Students);
            break;
        }
        case 4:
        {
            Student<string,int> :: InputAndAddStudent(Students); 
            Student<string,int> :: PrintAll(Students);
            break; 
        }
        case 5:
        {
            Student<string,int> :: SortStudentsBySurname(Students); 
            Student<string,int> :: PrintAll(Students); 
            break;
        }
        case 6:
        {
            Student<string,int> :: UpdateStudent(Students); 
            Student<string,int> :: PrintAll(Students);
            break;
        }
        case 7:
        {
            Student<string,int> :: FindStudent(Students);
            break;
        }
        case 8:
        {
            cout << "Please, check the file 'ClassStudentInputStudent.txt' for misspells. \nPress 'Y' if it is ready to use, and 'N' if not. [Y / N] \n";
            char Answer; cin >> Answer; 
            if(Answer == 'Y' || Answer == 'y')
            {
                Student<string,int> :: InputAndAddStudentViaFile(Students);
                Student<string,int> :: PrintAll(Students);
            }
            else
            {
                cout << "Operation was terminated.";
            }
            break;
        }
        case 9:
        {
            return 0;
        }

        default:
            return 0;
            break;
        } 
    } while (MainMenu != 9);
}
