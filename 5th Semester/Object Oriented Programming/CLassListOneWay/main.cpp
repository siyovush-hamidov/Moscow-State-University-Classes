#include <bits/stdc++.h>

template <typename X>
class ListOneWay {
    struct LST {
        int Index;
        X ValueOfTheRecord;
        LST *PointerToTheNextRecord;
    };

private:
    LST *PointerToTheFirstRecord;
    int QuantityOfRecordsInListOneWay;
//
public:
    ListOneWay() : PointerToTheFirstRecord(nullptr), QuantityOfRecordsInListOneWay(0) {}

    void AddList(X value) {
        LST* newRecord = new LST;
        newRecord->ValueOfTheRecord = value;
        newRecord->PointerToTheNextRecord = PointerToTheFirstRecord;
        PointerToTheFirstRecord = newRecord;
        QuantityOfRecordsInListOneWay++;
        RefreshIndexes();
    }

    std::string ListToString() {
        std::string result = "";
        LST* current = PointerToTheFirstRecord;
        while (current != nullptr) {
            result += std::to_string(current->ValueOfTheRecord) + " ";
            current = current->PointerToTheNextRecord;
        }
        return result;
    }

    void DeleteList(int index) {
        if (index >= QuantityOfRecordsInListOneWay) return;

        LST* current = PointerToTheFirstRecord;
        LST* previous = nullptr;

        for (int i = 0; i < index; i++) {
            previous = current;
            current = current->PointerToTheNextRecord;
        }

        if (previous != nullptr) {
            previous->PointerToTheNextRecord = current->PointerToTheNextRecord;
        } else {
            PointerToTheFirstRecord = current->PointerToTheNextRecord;
        }

        delete current;
        QuantityOfRecordsInListOneWay--;
        RefreshIndexes();
    }

    void RefreshIndexes() {
        LST* current = PointerToTheFirstRecord;
        int index = 0;

        while (current != nullptr) {
            current->Index = index++;
            current = current->PointerToTheNextRecord;
        }
    }

    X& operator[](int index) {
        if (index >= QuantityOfRecordsInListOneWay) throw std::out_of_range("Index out of range");

        LST* current = PointerToTheFirstRecord;

        for (int i = 0; i < index; i++) {
            current = current->PointerToTheNextRecord;
        }

        return current->ValueOfTheRecord;
    }
};

using namespace std;

int main() {
    ListOneWay<int> list;

    // Добавляем элементы в список
    list.AddList(1);
    list.AddList(2);
    list.AddList(3);

    // Выводим список
    cout << "Список: " << list.ListToString() << endl;

    // Удаляем элемент из списка
    list.DeleteList(1);

    // Выводим список после удаления
    cout << "Список после удаления: " << list.ListToString() << endl;

    // Доступ к элементу списка по индексу
    cout << "Элемент с индексом 1: " << list[1] << endl;

    return 0;
}

