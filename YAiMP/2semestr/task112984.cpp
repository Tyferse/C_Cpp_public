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

void push_back(int value) {
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

void push_middle(int value) {
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
    else if (len == 2) {
        Node *tmp = new Node;
        tmp->v = value;
        tmp->next = head->next;
        head->next = tmp;
        return;
    }

    Node *tmp = new Node;
    tmp->v = value;
    
    // Node *middle = head->next;
    // for (int i = 1; i < len / 2; i++)
    //     middle = middle->next;
    
    // tmp->next = middle->next;
    // middle->next = tmp;

    Node* slow = head;
    Node* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    tmp->next = slow->next;
    slow->next = tmp;
} 

void pop() {
    if (head == nullptr)
        return;

    if (len > 2) {
        // cout << "!!";
        head = head->next;
        // head->number--;
        // tail->number--;

        // return head;
    }
    else if (len == 2) {
        head->v = tail->v;
    }
    else {
        head = nullptr;
        tail = nullptr;
        // return nullptr;
    }
}

int main() {
    int n;
    cin >> n;

    char action;
    int number;
    for (int i = 0; i < n; i++) {
        cin >> action;
        if (action == '+') {
            cin >> number;
            push_back(number);
            len++;

            // cout << "head->v = " << head->v << endl;
        }
        else if (action == '*') {
            cin >> number;
            push_middle(number);
            len++;
        }
        else if (action == '-') {
            cout << head->v << endl;
            pop();
            len--;
        }
    }
    
    return 0;
}
