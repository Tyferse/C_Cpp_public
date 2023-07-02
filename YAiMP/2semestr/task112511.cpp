#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// struct Node {
//     string word;
//     int count = 1;
//     Node *prev = nullptr;
//     Node *next = nullptr;
// };

// Node *List(string w) {
//     Node *lst = new Node;
//     lst->word = w;
//     return lst;
// }

// Node *search(Node *begin, string s) {
//     if (begin->word == s)
//         return begin;
    
//     while (begin != nullptr && begin->word != s) {
//         begin = begin->next;
//     }

//     return begin;
// }

// Node *append(Node *begin, string w) {
//     if (!begin)
//         return List(w);

//     Node *insptr = search(begin, w);
//     cout << "  search = " << insptr << endl;
//     if (insptr == nullptr) {
//         Node *tmp = List(w);
//         if (w < begin->word && begin->count == 1) {
//             cout << "    add to beginning " << endl;
//             tmp->next = begin;
//             return tmp;
//         }

//         while ((w > begin->word || begin->count > 1) && begin->next != nullptr)
//             begin = begin->next;
        
//         if (begin->next == nullptr) {
//             cout << "    add to the end" << endl;
//             begin->next = tmp;
//             tmp->prev = begin;
//             while (begin->prev != nullptr)
//                 begin = begin->prev;
            
//             return begin;
//         }

//         cout << "    add to the middle" << endl;
//         tmp->prev = begin->prev;
//         tmp->next = begin;
//         begin->prev = tmp;
//         while (begin->prev != nullptr)
//             begin = begin->prev;

//         return begin;
//     }

//     insptr->count++;
//     if (insptr->prev != nullptr) {
//         cout << "  move to higher position" << endl;
        
//         while ((insptr->prev->count < insptr->count 
//                 || (insptr->prev->count == insptr->count && insptr->word < insptr->prev->word)) 
//                 && insptr->prev != nullptr) {
//             cout << "    " << insptr->prev->count << " <= " << insptr->count << " || ";
//             cout << insptr->word << " < " << insptr->prev->word << endl;
            
//             int tmpcount = insptr->count;
//             string tmpw = insptr->word;

//             insptr->word = insptr->prev->word;
//             insptr->count = insptr->prev->count;
//             insptr->prev->word = tmpw;
//             insptr->prev->count = tmpcount;
//             insptr = insptr->prev;
//             cout << "    insptr->prev = " << insptr->word << ", " << insptr->count << endl;
//         }

//         cout << " " << insptr->word << endl;

//         while (insptr->prev != nullptr)
//             insptr = insptr->prev;
//     }
    
//     return insptr;
// }

// int main() {
//     ifstream fin("input.txt");
//     ofstream fout("output.txt");


//     Node *lst = nullptr;
//     string w;
//     while (!fin.eof()) {
//         fin >> w;
//         cout << "append(" << w << ")" << endl;
//         lst = append(lst, w);
//         cout << (lst == nullptr) << endl;
//         // cout << "current head = " << lst->word << " " << lst->count << endl << endl;
//     }

//     while (lst->next != nullptr) {
//         fout << lst->word << " " << lst->count << endl;
//         cout << lst->word << " " << lst->count << endl;
//         lst = lst->next;
//     }

//     fin.close();
//     fout.close();
    
//     return 0;
// }

struct Node {
    string word;
    int count = 1;
    Node* prev;
    Node* next;
    Node(string w) {
        word = w; 
        prev = nullptr;
        next = nullptr; 
    }
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
    public:
        DoublyLinkedList() { 
            head = nullptr;
            tail = nullptr;
        }

        Node *get_head() {
            return head;
        }

        Node *search(string w) {
            Node* curr = head;
            while (curr != nullptr && curr->word != w) {
                curr = curr->next;
            }

            return curr;
        }

        void insert(string w) {
            Node *inspt = search(w);

            if (inspt == nullptr) {
                Node* newNode = new Node(w);
                if (head == nullptr) {
                    head = tail = newNode;
                } 
                else if (w < head->word && head->count == 1) {
                    newNode->next = head;
                    head->prev = newNode;
                    head = newNode;
                } 
                else if (w > tail->word || tail->count > 1) {
                    newNode->prev = tail;
                    tail->next = newNode;
                    tail = newNode;
                }
                else {
                    Node* curr = head->next;
                    while (curr != nullptr && (curr->word < w || curr->count > 1)) 
                        curr = curr->next;

                    Node* prevNode = curr->prev;
                    prevNode->next = newNode;
                    newNode->prev = prevNode;
                    newNode->next = curr;
                    curr->prev = newNode;
                }
            }
            else {
                inspt->count++;
                // while (inspt->prev != nullptr && (inspt->prev->count < inspt->count 
                //         || (inspt->prev->count == inspt->count && inspt->word < inspt->prev->word))) {
                //     cout << (inspt->prev->count < inspt->count 
                //         || (inspt->prev->count == inspt->count && inspt->word < inspt->prev->word)) << endl;
                //     Node *tmp = inspt->prev;
                //     inspt->prev = tmp->prev;
                //     tmp->prev = inspt;
                //     tmp->next = inspt->next;
                //     inspt->next = tmp;
                // }
                while (inspt != head && (inspt->count > inspt->prev->count 
                                         || (inspt->count == inspt->prev->count 
                                             && inspt->word < inspt->prev->word))) {
                    Node* prevNode = inspt->prev;
                    Node* nextNode = inspt->next;
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                    inspt->prev = prevNode->prev;
                    inspt->next = prevNode;
                    prevNode->prev = inspt;
                    if (inspt->prev == nullptr)
                        head = inspt;
                    else 
                        inspt->prev->next = inspt;
                }
            }
        }
};


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    DoublyLinkedList lst = DoublyLinkedList();
    string w;
    while (!fin.eof()) {
        fin >> w;
        cout << "append(" << w << ")" << endl;
        lst.insert(w);
        // cout << (lst == nullptr) << endl;
        // cout << "current head = " << lst->word << " " << lst->count << endl << endl;
    }

    Node *curr = lst.get_head();
    fout << curr->word << " " << curr->count << endl;
    cout << curr->word << " " << curr->count << endl;
    while (curr->next != nullptr) {
        curr = curr->next;
        fout << curr->word << " " << curr->count << endl;
        cout << curr->word << " " << curr->count << endl;
    }

    fin.close();
    fout.close();
    
    return 0;
}
