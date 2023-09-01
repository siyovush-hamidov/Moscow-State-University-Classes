#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename NameType, typename SurnameType, typename PatronymicType, typename BirthYearType, typename SpecializationType, typename AgeType, typename SportType, typename AddressType, typename PhoneType, typename CourseType>
class Student {
public:
    NameType name;
    SurnameType surname;
    PatronymicType patronymic;
    BirthYearType birth_year;
    SpecializationType specialization;
    AgeType age;
    SportType sport;
    AddressType address;
    PhoneType phone;
    CourseType course;

    Student(NameType name, SurnameType surname, PatronymicType patronymic, BirthYearType birth_year, SpecializationType specialization, AgeType age, SportType sport, AddressType address, PhoneType phone, CourseType course) : name(name), surname(surname), patronymic(patronymic), birth_year(birth_year), specialization(specialization), age(age), sport(sport), address(address), phone(phone), course(course) {}

    static void add_student(vector<Student>& students, Student student) {
        students.push_back(student);
    }

    static void remove_student(vector<Student>& students, int index) {
        students.erase(students.begin() + index);
    }

    static void update_student(vector<Student>& students, int index, Student student) {
        students[index] = student;
    }

    static Student* find_student(vector<Student>& students, NameType name) {
        for (typename vector<Student>::iterator it = students.begin(); it != students.end(); ++it) {
            if (it->name == name) {
                return &(*it);
            }
        }
        return NULL;
    }

    static bool compare_students_by_name(const Student& a, const Student& b) {
        return a.name < b.name;
    }

    static void sort_students_by_name(vector<Student>& students) {
        sort(students.begin(), students.end(), compare_students_by_name);
    }
};

int main()
{
    SetConsoleOutputCP(1251);
    vector<Student<string,string,string,int,string,int,string,string,string,int> > students;
    Student<string,string,string,int,string,int,string,string,string,int> student1("Иван", "Иванов", "Иванович", 2000, "Математика", 23, "Футбол", "ул. Ленина, д. 1", "+79999999999", 4);
    Student<string,string,string,int,string,int,string,string,string,int>::add_student(students, student1); // добавляем student1 в students
    Student<string,string,string,int,string,int,string,string,string,int> student2("Петр", "Петров", "Петрович", 2001, "Физика", 22, "Баскетбол", "ул. Сталина, д. 2", "+78888888888", 3);
    Student<string,string,string,int,string,int,string,string,string,int>::add_student(students, student2); // добавляем student2 в students
    Student<string,string,string,int,string,int,string,string,string,int>::remove_student(students, 0); // удаляем первого студента из students
    Student<string,string,string,int,string,int,string,string,string,int> student3("Сергей", "Сергеев", "Сергеевич", 1999, "Химия", 24, "Волейбол", "ул. Кирова, д. 3", "+77777777777", 5);
    Student<string,string,string,int,string,int,string,string,string,int>::update_student(students, 0, student3); // обновляем информацию о первом студенте в students
    Student<string,string,string,int,string,int,string,string,string,int>* found_student = Student<string,string,string,int,string,int,string,string,string,int>::find_student(students, "Сергей"); // находим студента с именем Сергей

if (found_student != NULL)
    {
        cout << found_student->name << endl; // выводим имя найденного студента
    }
    Student<string,string,string,int,string,int,string,string,string,int>::sort_students_by_name(students); // сортируем students по имени
}
