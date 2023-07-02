#include <iostream>
using namespace std;


struct Node {
    float v;
    Node *prev = nullptr;
    Node *next = nullptr;
};

Node *List(float value) {
    Node *lst = new Node;
    lst->v = value;
    return lst;
}

Node *append(Node *begin, float value) {
    if (!begin)
        return List(value);

    if (begin->v > value) { 
        Node* new_node = List(value);        
        Node *p = begin->next; // сохранение указателя на следующий узел
        begin->next = new_node; // предыдущий узел указывает на создаваемый
        new_node->v = value; // сохранение поля данных добавляемого узла
        new_node->next = p; // созданный узел указывает на следующий узел
        new_node->prev = begin; // созданный узел указывает на предыдущий узел
        if (p != NULL)
            p->prev = new_node;

        return new_node;
    }

    begin->next = append(begin->next, value);
    return begin;
}

void print_list(Node *list, int len) {
    while (list != nullptr && len > 0) {
        cout << list->v << " ";
        list = list->prev;
        len--;
    }

    if (list == nullptr)
        cout << "end";
}

int main() {
    int n;
    cin >> n;

    float value;
    cin >> value;
    Node *list = List(value);
    for (int i = 0; i < n - 1; i++) {
        cin >> value;
        list = append(list, value);
        // cout << list->v << " ";
    }

    if (n > 1) {
        Node *last = new Node;
        last->next = list->next;
        while (last->next) {
            last = last->next;
        }

        list->prev = last;
        last->next = list;
    }

    print_list(list, n);

    return 0;
}
