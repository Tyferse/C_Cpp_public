#include <iostream>
#include <string>
using namespace std;


struct Node {
    int v;
    Node *next = nullptr;
    // int number;
};

Node *Queue(int value) {
    Node *queue = new Node;
    queue->v = value;
    // queue->number = 1;
    return queue;
}

Node *head = nullptr;
Node *tail = nullptr;
int len = 0;

void push(int value) {
    if (!tail) {
        head = Queue(value);
        tail = Queue(value);
        head->next = tail;
        return;
    }
    else if (len == 1) {
        tail->v = value;
        return;
    }

    Node *tmp = new Node;
    tmp->v = value;
    // tmp->number = tail->number + 1;
    tail->next = tmp;
    tail = tail->next;
    // return tmp;
} 

void pop() {
    if (head == nullptr)
        return;

    if (len > 1) {
        // cout << "!!";
        head = head->next;
        // head->number--;
        // tail->number--;

        // return head;
    }
    else {
        head = nullptr;
        tail = nullptr;
        // return nullptr;
    }
}

int main() {
    string command;
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
                push(n);
                len++;

                cout << "ok" << endl;
            }
            else if (command == "pop") {
                if (head != nullptr) {
                    int deleted = head->v;
                    pop();

                    cout << deleted << endl;
                    len--; 
                }
                else
                    cout << "error" << endl;
            }
            else if (command == "front") {
                if (head != nullptr)
                    cout << head->v << endl;
                else
                    cout << "error" << endl;
            }
            else if (command == "size") {
                cout << len << endl;
            }
            else if (command == "clear") {
                while (head != nullptr)
                    pop();
                
                len = 0;
                cout << "ok" << endl;
            }

            cin >> command;
        }

        cout << "bye";
    }
    
    return 0;
}
