#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Employee {
public:
    Employee(int newIdNumber, string newName = "", double newRate = 0): idNumber(newIdNumber), name(newName),
        hourlyPayRate(newRate), numberOfHoursWorked(0) {};
    void addHours(int newHoursWorked) { numberOfHoursWorked += newHoursWorked; };
    string getName() { return name; };
    double getTotalPay() const { return (hourlyPayRate * numberOfHoursWorked); };
    bool operator==(const Employee& rhs) const { return (idNumber == rhs.idNumber); };
    bool operator!=(const Employee& rhs) const { return !(operator==(rhs)); };
    bool operator<(const Employee& rhs) const { return (getTotalPay() < rhs.getTotalPay()); };
private:
    int idNumber;
    string name;
    double hourlyPayRate;
    int numberOfHoursWorked;
};


template <class T>
class LList;

template <class T>
class LListNode {
public:
    LListNode(const T& newData = T(), LListNode<T>* newNext = nullptr): data(newData), next(newNext) {};
    T& getData() { return data; };
    LListNode<T>* getNext() { return next; };
    friend class LList<T>;
private:
    T data;
    LListNode<T>* next;
};

template <class T>
class LList {
public:
    LList(): head(nullptr) {};
    void headInsert(T newData);
    void sortDescending();
    LListNode<T>* search(T target);
    LListNode<T>* getHead() { return head; };
private:
    void swap(LListNode<T>* first, LListNode<T>* second);
    LListNode<T>* head;
};

template <class T>
void LList<T>::headInsert(T newData) {
    LListNode<T>* newNode = new LListNode<T>(newData, head);
    head = newNode;
}

template <class T>
void LList<T>::sortDescending() {
    bool unsorted = true;

    while (unsorted) {
        unsorted = false;
        LListNode<T>* curr = head;

        while (curr != nullptr) {
            LListNode<T>* next = curr->next;

            if (next != nullptr && curr->data < next->data) {
                swap(curr, next);
                unsorted = true;
            }
            curr = next;
        }
    }
}

template <class T>
void LList<T>::swap(LListNode<T>* first, LListNode<T>* second) {
    T tempData = first->data;
    first->data = second->data;
    second->data = tempData;
}

template <class T>
LListNode<T>* LList<T>::search(T target) {
    LListNode<T>* here = head;
    while (here != nullptr && here->data != target) {
        here = here->next;
    }
    return here;
}


void readInFirstFile(LList<Employee>& list);
void readInSecondFile(LList<Employee>& list);
void printPayrollInfo(LList<Employee>& list);

int main() {
    LList<Employee> list;

    readInFirstFile(list);
    readInSecondFile(list);
    list.sortDescending();
    printPayrollInfo(list);

    return 0;
}

void readInFirstFile(LList<Employee>& list) {
    ifstream fin("emps.txt");

    if (fin.fail()) {
        cout << "Failed to open the first file.";
        exit(1);
    }

    int idNumber;
    double rate;
    string name;

    while (fin >> idNumber) {
        fin >> rate;
        fin.ignore(9999, ' ');
        getline(fin, name);
//        getline(fin, name, '\r'); //in case '\r' is used instead of '\n'

        Employee newEmployee(idNumber, name, rate);

        list.headInsert(newEmployee);
    }
    fin.close();
}

void readInSecondFile(LList<Employee>& list) {
    ifstream fin("hours.txt");

    if (fin.fail()) {
        cout << "Failed to open the second file.";
        exit(1);
    }

    int idNumber;
    int hours;

    while (fin >> idNumber) {
        fin >> hours;

        LListNode<Employee>* empListNodePtr = list.search(Employee(idNumber));

        if (empListNodePtr != nullptr) {
            empListNodePtr->getData().addHours(hours);
        } else {
            cout << "Unknown employee referenced in the second file.";
            exit(1);
        }
    }
    fin.close();
}

void printPayrollInfo(LList<Employee>& list) {
    cout << "*********Payroll Information********\n";
    for (LListNode<Employee>* iter = list.getHead(); iter != nullptr; iter = iter->getNext()) {
        cout << iter->getData().getName() << ", $" << iter->getData().getTotalPay() << endl;
    }
    cout << "*********End payroll**************\n";
}