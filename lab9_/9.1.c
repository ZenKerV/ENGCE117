#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Student {
    string name;
    int age;
    char sex;
    float gpa;
    Student* next;

    Student(string n, int a, char s, float g) 
        : name(n), age(a), sex(s), gpa(g), next(nullptr) {}
};

class StudentList {
private:
    Student* head;

public:
    StudentList() : head(nullptr) {}

    void add(string name, int age, char sex, float gpa) {
        Student* newNode = new Student(name, age, sex, gpa);
        if (!head) {
            head = newNode;
        } else {
            Student* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    Student* find(string name) {
        Student* temp = head;
        while (temp) {
            if (temp->name == name) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    bool remove(string name) {
        if (!head) return false;
        
        if (head->name == name) {
            Student* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Student* curr = head;
        while (curr->next && curr->next->name != name) curr = curr->next;

        if (curr->next) {
            Student* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            return true;
        }
        return false;
    }

    void display() {
        Student* temp = head;
        cout << "\n--- Student List ---\n";
        while (temp) {
            cout << temp->name << " (" << temp->age << "y, " << temp->sex << ") GPA: " << temp->gpa << endl;
            temp = temp->next;
        }
    }

    ~StudentList() {
        while (head) {
            Student* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    StudentList list;
    int menu;

    do {
        cout << "\n1.Add 2.Delete 3.Find 4.Show 0.Exit: ";
        cin >> menu;

        if (menu == 1) {
            string n; int a; char s; float g;
            cout << "Name Age Sex GPA: ";
            cin >> n >> a >> s >> g;
            list.add(n, a, s, g);
        } else if (menu == 2) {
            string n; cout << "Name to delete: "; cin >> n;
            if (list.remove(n)) cout << "Deleted.\n";
            else cout << "Not found.\n";
        } else if (menu == 3) {
            string n; cout << "Name to find: "; cin >> n;
            Student* s = list.find(n);
            if (s) cout << "Found: " << s->name << " GPA: " << s->gpa << endl;
            else cout << "Not found.\n";
        } else if (menu == 4) {
            list.display();
        }
    } while (menu != 0);

    return 0;
}
