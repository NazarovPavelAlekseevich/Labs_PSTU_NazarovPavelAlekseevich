#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int v){data = v; next = nullptr; prev = nullptr;}
};

struct List{
    Node* head; Node* tail; int size = 0;
    List(){head = nullptr; tail = nullptr;}

    void pushfront(int n){
        Node* temp = new Node(n);
        if(head == nullptr){
            head = temp; tail = temp;
        }
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        ++size;
    }

    void pushback(int n){
        Node* temp = new Node(n);
        if(tail == nullptr){
            head = temp; tail = temp;
        }
        else{
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        ++size;
    }

    void popback(){
        if(tail == nullptr) return;
        Node* temp = tail;
        tail = tail->prev;
        if(tail == nullptr) head = nullptr;
        else tail->next = nullptr;
        delete temp;
        --size;
    }

    void popfront(){
        if(head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if(head == nullptr) tail = nullptr;
        else head->prev = nullptr;
        delete temp;
        --size;
    }

    Node* getAt(int k){
        if(k < 0 || k >= size) return nullptr;
        Node* temp = head;
        for(int i = 0; i < k; ++i) temp = temp->next;
        return temp;
    }

    // вставка на позицию k
    void incert(int k, int n){
        if(k < 0 || k > size){ cout << "Incorrect index" << endl; return; }
        if(k == 0){ pushfront(n); return; }
        Node* element = getAt(k-1);
        Node* temp = new Node(n);
        temp->prev = element;
        temp->next = element->next;
        if(element->next == nullptr) tail = temp;
        else element->next->prev = temp;
        element->next = temp;
        ++size;
    }

    // вставка после элемента с индексом k
    void postincert(int k, int n){
        if(k < 0 || k >= size){ cout << "Incorrect index" << endl; return; }
        Node* element = getAt(k);
        Node* temp = new Node(n);
        temp->prev = element;
        temp->next = element->next;
        if(element->next == nullptr) tail = temp;
        else element->next->prev = temp;
        element->next = temp;
        ++size;
    }

    // вставка перед элементом с индексом k — теперь через prev, без поиска k-2
    void previncert(int k, int n){
        if(k < 0 || k >= size){ cout << "Incorrect index" << endl; return; }
        if(k == 0){ pushfront(n); return; }
        Node* element = getAt(k);
        Node* temp = new Node(n);
        temp->prev = element->prev;
        temp->next = element;
        element->prev->next = temp;
        element->prev = temp;
        ++size;
    }

    void couter(){
        for(Node* i = head; i != nullptr; i = i->next){
            cout << i->data << " ";
        }
        cout << endl;
    }

    // при желании можно добавить вывод с конца — двусвязный список это умеет
    void couterRevers(){
        for(Node* i = tail; i != nullptr; i = i->prev){
            cout << i->data << " ";
        }
        cout << endl;
    }

    void newelements(int k, int ind){
        for(int i = 0; i < k; ++i){
            int n; cin >> n;
            incert(ind, n); ++ind;
        }
    }

    void sorter(){
        if(head == nullptr || head->next == nullptr) return;
        int* m = new int[size];
        int j = 0, s = size;
        for(Node* i = head; i != nullptr; i = i->next, ++j) m[j] = i->data;

        for(int i = 0; i < s; ++i){
            int min = m[i], k = i;
            for(int j = i; j < s; ++j){if(m[j] <= min){min = m[j]; k = j;}}
            m[k] = m[i];
            m[i] = min;
        }

        for(int i = 0; i < s; ++i){pushback(m[i]); popfront(); cout << m[i] << " ";}
        delete[] m;
    }

    void del(){
        while(head != nullptr) popfront();
    }

    // удаление col элементов, начиная с индекса ind
    void deleter(int col, int ind){
        Node* start = getAt(ind);
        if(start == nullptr){
            cout << "Incorrect index" << endl;
            return;
        }
        for(int i = 0; i < col && start != nullptr; ++i){
            Node* todel = start;
            start = start->next;
            if(todel->prev == nullptr) head = start;
            else todel->prev->next = start;
            if(start == nullptr) tail = todel->prev;
            else start->prev = todel->prev;
            delete todel;
            --size;
        }
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
    list.couter();
    list.del();
    return 0;
}