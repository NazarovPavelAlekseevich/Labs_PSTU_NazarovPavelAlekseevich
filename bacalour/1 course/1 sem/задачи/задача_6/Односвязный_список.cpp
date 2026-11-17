#include <iostream>
#include <list>
#include <windows.h>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

struct List{
    Node* head;
    List() {head = nullptr;}

    Node* getAt(int k){
        if(k < 0) return nullptr;
        Node* current = head;
        int index = 0;
        while(current != nullptr && index != k){
            current = current->next;
            ++index;
        }
        return (index == k) ? current : nullptr;
    }

    void List::pushBack(int value){ //Ввод в конец
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) current = current->next;
        current->next = newNode;
    };

    void List::pushFront(int value){ //Добавление в начало
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void List::popFront(int value){ //Удаление из начала списка
        if(head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void List::popBack(int value){ //удаление с конца
        if(head == nullptr) return;
        Node* current = head; Node* temp;
        while(current->next != nullptr){temp = current; current = current->next;}
        temp->next = nullptr;
        delete current;
    }

    void List::insert(int k, int data){//вставка по индексу
        Node* left = getAt(k);
        if(left == nullptr) return;
        Node* temp = new Node(data);
        temp->next = left->next;
        left->next = temp;
    }

    void List::erase(int k){ //удаление элемента
        Node* left = getAt(k-1);
        Node* right = getAt(k+1);
        Node* temp = getAt(k);
        if(temp == nullptr) return;
        if(left != nullptr && right != nullptr) left->next = right;
        else if(left == nullptr && right != nullptr) head = right;
        else if(left != nullptr && right == nullptr) left->next = nullptr;
        else if(left == nullptr && right == nullptr) head = nullptr;
        delete temp;
    }
};

int main(){
    setlocale(LC_ALL, ".65001");
    List list;
    char temp;
    for(int i = 0; i < 5; ++i){
        cout << "Введите " << i+1 << " Элемент: ";
        cin >> temp;
        list.pushBack(temp);
    }
    cout << endl;
    for(Node* node = list.head; node->next != nullptr; node = node->next){
        char c = node->data;
        cout << c << ' ';
    }
    cout << endl << endl;
    list.insert(2,'u');

    for(Node* node = list.head; node->next != nullptr; node = node->next){
        char c = node->data;
        cout << c << ' ';
    }
    list.erase(4);
    cout << endl << endl;

    for(Node* node = list.head; node->next != nullptr; node = node->next){
        char c = node->data;
        cout << c << ' ';
    }
    return 0;
}