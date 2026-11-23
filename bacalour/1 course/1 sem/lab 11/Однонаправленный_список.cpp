#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int v){data = v; next = nullptr;}
};

struct List{
    Node* head; Node* tail; int size = 0;
    List(){head = nullptr; tail = nullptr;}

    void pushfront(int n){
        Node* temp = new Node(n);
        if(head == nullptr){
            head = temp; tail = head;
            temp->next = nullptr;
            return;
        }
        temp->next = head;
        head = temp;
        ++size;
    }

    void pushback(int n){
        Node* temp = new Node(n);
        if(head == nullptr){
            head = temp;
            tail = head;
            return;
        }
        tail->next = temp;
        tail = temp;
        ++size;
    }

    void popback(){
        if(head == nullptr) return;
        else if(head->next == nullptr){
            delete head; head = nullptr; size = 0;
        }
        else{
            Node* temp = head;
            while(temp->next != tail) temp = temp->next;
            delete temp->next;
            tail = temp; tail->next = nullptr;
            --size;
        }
    }

    void popfront(){
        if(head == nullptr) return;
        else if(head->next == nullptr){
            delete head; head = nullptr; size = 0;
        }
        else{
            Node* temp = head;
            head = temp->next;
            delete temp;
            --size;
        }
    }

    Node* getAt(int k){
        if(k < 0 || k >= size) return nullptr;
        Node* temp = head;
        int i = 0;
        while(i < k){
            temp = temp->next;
            ++i;
        }
        if(i == k) return temp;
        else return nullptr;
    }

    void incert(int k, int n){
        Node* temp = new Node(n);
        Node* element = getAt(k-1);
        if(element == nullptr){
            cout << "Incorrect index" << endl;
            return;
        }
        else if (element->next == nullptr){pushback(temp->data); return;}
        temp->next = element->next;
        element->next = temp;
    }

    void postincert(int k, int n){
        Node* temp = new Node(n);
        Node* element = getAt(k);
        if(element == nullptr){
            cout << "Incorrect index" << endl;
            return;
        }
        else if (element->next == nullptr){pushback(temp->data); return;}
        temp->next = element->next;
        element->next = temp;
    }

    void previncert(int k, int n){
        Node* temp = new Node(n);
        Node* element = getAt(k-2);
        if(element == nullptr){
            cout << "Incorrect index" << endl;
            return;
        }
        else if (element->next == nullptr){pushback(temp->data); return;}
        temp->next = element->next;
        element->next = temp;
    }

    void couter(){
        for(Node* i = head; i != nullptr; i = i->next){
            cout << i->data << " ";
        }
        cout << endl;
    }

    void newelements(int k, int ind){
        for(int i = 0; i < k; ++i){
            int n; cin >> n;
            incert(ind, n); ++ind;
        }
        size += k;
    }

    void sorter(){
        if(head == nullptr || head->next == nullptr) return;
        int* m = new int[size+1];
        int j = 0, s = size+1;
        for(Node* i = head; i != nullptr; i = i->next, ++j) m[j] = i->data;

        for(int i = 0; i < s; ++i){
            int min = m[i], k;
            for(int j = i; j < s; ++j){if(m[j] <= min){min = m[j]; k = j;}}
            m[k] = m[i];
            m[i] = min;
        }

        for(int i = 0; i < s; ++i){pushback(m[i]); popfront(); cout << m[i] << " ";}
        delete[] m;
    }

    void del(){
        while(head != nullptr)popback();
        head = nullptr;
        size = 0;
    }

    void deleter(int col, int ind){
        Node* start = getAt(ind-1); Node* end = start;
        if(start == nullptr){
            for(int i = 0; i < col; ++i) popfront();
            return;
        }
        for(int i = 0; i <= col && end != nullptr; ++i) end = end->next;
        if(end == nullptr) for(int i = 0; i < col; ++i) popback();
        Node* temp = start->next;
        for(int i = 0; i < col; ++i){
            Node* todel = temp;
            temp = temp->next;
            delete todel;
        }
        start->next = end;
    }
};

int main(){
    setlocale(LC_ALL,".65001");
    int k, ind, col; cin >> k;
    List list;
    cout << "Ввод: ";
    for(int i = 0; i < k; ++i){
        int n; cin >> n;
        list.pushback(n);
    }
    list.couter();
    cout << endl << "Добавление элемента в начало: "; cin >> k;
    list.pushfront(k);
    list.couter();
    cout << endl << "Добавление элемента в конец: "; cin >> k;
    list.pushback(k);
    list.couter();
    cout << endl << "Добавление элемента по индексу: "; cin >> ind >> k;
    list.incert(ind, k);
    list.couter();
    cout << endl << "Добавление элемента перед элементом с индексом: "; cin >> ind >> k;
    list.previncert(ind, k);
    list.couter();
    cout << endl << "Добавление элемента после элемента с индексом: "; cin >> ind >> k;
    list.postincert(ind, k);
    list.couter();
    cout << endl << "Удаление k элементов: "; cin >> col >> ind;
    list.deleter(col, ind);
    list.couter();
    cout << endl << "Добавление k элементов: "; cin >> col >> ind;
    list.newelements(col, ind);
    list.couter();
    cout << endl << "Отсортированный список по возрастанию: ";
    list.sorter();
    list.del();
    return 0;
}