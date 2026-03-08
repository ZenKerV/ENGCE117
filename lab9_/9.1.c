#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct Student {
    string name;
    int age;
    char sex;
    float gpa;
    Student* next;

    Student(string n, int a, char s, float g) : name(n), age(a), sex(s), gpa(g), next(NULL) {}
};

class LinkedList {
private:
    Student* head;

public:
    LinkedList() : head(NULL) {}

    void addNode(string n, int a, char s, float g) {
        Student* newNode = new Student(n, a, s, g);
        if (!head) {
            head = newNode;
        } else {
            Student* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }


    void showAll() {
        Student* temp = head;
        while (temp) {
            cout << temp->name << " | " << temp->age << " | " 
                 << temp->sex << " | " << temp->gpa << endl;
            temp = temp->next;
        }
    }

    
    Student* findNode(string n) {
        Student* temp = head;
        while (temp) {
            if (temp->name == n) return temp;
            temp = temp->next;
        }
        return NULL;
    }

    
    bool deleteNode(string n) {
        if (!head) return false;
        if (head->name == n) {
            Student* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        Student* curr = head;
        while (curr->next && curr->next->name != n) curr = curr->next;
        
        if (curr->next) {
            Student* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            return true;
        }
        return false;
    }

    ~LinkedList() {
        while (head) {
            Student* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
