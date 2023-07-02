#include <iostream>
#include <string>
using namespace std;


struct Node {
    int v;
    Node *prev = nullptr;
    int number;
};

Node *Stack(int value) {
    Node *stk = new Node;
    stk->v = value;
    stk->number = 1;
    return stk;
}

Node *push(Node *stack, int value) {
    if (!stack)
        return Stack(value);

    Node *tmp = new Node;
    tmp->v = value;
    tmp->number = stack->number + 1;
    tmp->prev = stack;
    return tmp;
} 

Node *pop(Node *stack) {
    if (stack == nullptr)
        return stack;

    if (stack->number > 1) {
        stack = stack->prev;
        return stack;
    }
    else if (stack->number < 2) {
        free(stack);
        return nullptr;
    }
}

int main() {
    int value;
    Node *st = nullptr;

    string command = "1";
    cin >> command;
    if (command == "exit") {
        cout << "bye";
    }
    else {
        int n;
        while (command != "exit") {
            // cout << '"' << command << '"' << endl;
            if (command == "push") {
                cin >> n;
                st = push(st, n);
                cout << "ok" << endl;
            }
            else if (command == "pop") {
                if (st != nullptr) {
                    int deleted = st->v;
                
                    st = pop(st);
                    cout << deleted << endl; 
                }
                else
                    cout << "error" << endl;
            }
            else if (command == "back") {
                if (st != nullptr)
                    cout << st->v << endl;
                else
                    cout << "error" << endl;
            }
            else if (command == "size") {
                if (st != nullptr)
                    cout << st->number << endl;
                else
                    cout << 0 << endl;
            }
            else if (command == "clear") {
                while (st != nullptr)
                    st = pop(st);
                
                cout << "ok" << endl;
            }

            cin >> command;
        }

        cout << "bye";
    }
    
    return 0;
}
