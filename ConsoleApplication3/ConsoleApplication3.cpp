// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
void sort();
void remove_duplicates();
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {

public:
    Node* head, * tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    };

    void push_front(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        }
        if (tail == nullptr)
        {
            tail = newNode;
        }

        head = newNode;
  
    }

    void push_back(int data) {
        Node* newNode = new Node(data);
        newNode->prev = tail;

        if (tail != nullptr) {
            tail->next = newNode;
        }
        if (head == nullptr) {
            head = newNode;
        }

        tail = newNode;

    }

    void pop_front() {
        if (head == nullptr) {
            return;
        }
        Node* newNode = head;
        head = head->next;
        if (head == nullptr) {
            tail == nullptr;
        }
        else
        {
            head->prev = nullptr;
        }

    }

    void pop_back() {
        if (tail == nullptr) return;
        Node* newNode = tail;
        tail = tail->prev;
        if (tail == nullptr) {
            head = nullptr;
        }
        else {
            tail->next = nullptr;
        }
        delete newNode;
    }

    void display() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    void sort()
    {

        if (head == nullptr) return;
        bool swapped;
        do {
            swapped = false;
            Node* current = head;
            while (current->next != nullptr) {
                if (current->data > current->next->data) {
                    swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);

    }
    void remove_duplicates()
    {
        if (head == nullptr) return;
        Node* cur = head;
        while (cur != nullptr) {
            Node* curnode = cur;
            while (curnode->next != nullptr) {
                if (cur->data == curnode->next->data) {
                    Node* temp = curnode->next;
                    curnode->next = curnode->next->next;
                    if (curnode->next != nullptr) {
                        curnode->next->prev = curnode;
                    }
                    else {
                        tail = curnode;
                    }
                    delete temp;
                }
                else {
                    curnode = curnode->next;
                }
            }
            cur = cur->next;
        }

    };

 };



    void main() {
        DoublyLinkedList list;
        int number;
        while (true) {
            cout << "Выберите действие:\n1-Добавить элемент в начало списка \n2-Добавить элемент в конец списка\n3-Убрать элемент из начала списка\n4-Убрать элемент с конца списка\n5-Отобразить список\n6-Отсортировать список\n7-Удалить дубликаты\n8-Выход";    cin >> number;
            switch (number) {
            case 1:
                cout << "Введите значение: ";
                cin >> number;
                list.push_front(number);
                break;
            case 2:
                cout << "Введите значение: ";
                cin >> number;
                list.push_back(number);
                break;
            case 3:
                list.pop_front();
                break;
            case 4:
                list.pop_back();
                break;
            case 5:
                list.display();
                break;
            case 6:
                list.sort();
                break;
            case 7:
                list.remove_duplicates();
                break;
            case 8:
                return;
            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
            }
        }
    }





    // Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
    // Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

    // Советы по началу работы 
    //   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
    //   2. В окне Team Explorer можно подключиться к системе управления версиями.
    //   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
    //   4. В окне "Список ошибок" можно просматривать ошибки.
    //   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
    //   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

