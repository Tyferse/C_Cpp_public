#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int arr_size = 100000;

struct ListNode {
    ListNode *next = nullptr;
    int v;
    
    ListNode(int val) {
        v = val;
    }
};

class UnorderedSet {
    private:
        int hash(int v) {
            return v % arr.size();
        }
    public:
        vector<ListNode*> arr;


        UnorderedSet(int size=arr_size) {
            arr = vector<ListNode*>(size, nullptr); 
        }

        ListNode *search(int value) {
            int idx = hash(value);
            ListNode* node = arr[idx];
            if (node == nullptr) 
                return node;

            while (node != nullptr && node->v != value) {
                node = node->next;
            }

            return node;
        }
    
        void add(int value) {
            ListNode *node = search(value);
            ListNode *new_node = new ListNode(value);
            if (node != nullptr && node->v == value)
                return;

            int idx = hash(value);
            ListNode *insnode = arr[idx];
            if (insnode == nullptr) {
                arr[idx] = new ListNode(value);
            }
            else {
                if (insnode->v == value) 
                    return;

                while (insnode->next != nullptr && insnode->v <= value) {
                    if (insnode->v == value) 
                        return;
                    
                    insnode = insnode->next;
                }

                insnode->next = new_node;
            }
        }
    
        void del(int value) {
            int h = hash(value);
            ListNode *node = arr[h];
            ListNode *prev = nullptr;
            if (node == nullptr) 
                return;
            
            while (node->next != nullptr && node->v != value) {
                prev = node;
                node = node->next;
            }

            if (prev == nullptr && arr[h]->v == value) {
                arr[h] = nullptr;
            }
            else if (node->v == value) {
                prev->next = node->next;
                free(node);
            }
        }

        // void print() {
        //     ofstream fout("output.txt");

        //     bool empty_slot[arr.size()] = {false};
        //     int empty_count = 0;
        //     for (int i = 0; i < arr.size(); i++) {
        //         if (arr[i] == nullptr) {
        //             empty_slot[i] = true;
        //             empty_count++;
        //             continue;
        //         }

        //         fout << arr[i]->v << " ";
        //         // cout << arr[i]->v << " ";
        //         remove(arr[i]->v);
        //     }

        //     if (empty_count == arr.size())
        //         return;

        //     while (empty_count < arr.size()) {
        //         for (int i = 0; i < arr.size(); i++) {
        //             if (!empty_slot[i]) {
        //                 fout << arr[i]->v << " ";
        //                 // cout << arr[i]->v << " ";
        //                 remove(arr[i]->v);
        //                 if (arr[i] == nullptr) {
        //                     empty_slot[i] = true;
        //                     empty_count++;
        //                 }
        //             }
        //         }
        //     }

        //     fout.close();
        // }
};

int main() {
    /*
    unordered_set
    массив линейных списков
    хэш-функция (остаток от деления (простое число) 
                 или поиск неиспользованного индекса)
    если одинаковый хэш, то добавляем в список под этим индексом

    vector<ListNode> * unordered_set
    */

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    signed int ai = -1;
    UnorderedSet uset = UnorderedSet();

    while (ai != 0) {
        fin >> ai;
        if (ai > 0)
            uset.add(ai);
        else if (ai < 0) {
            uset.del(-ai);
        }
    }

    vector<int> output_arr;
    for (int i = 0; i < arr_size; i++) {
        while (uset.arr[i] != nullptr) {
            output_arr.push_back(uset.arr[i]->v);
            uset.del(uset.arr[i]->v);
        }
    }

    sort(output_arr.begin(), output_arr.end());
    for (int i = 0; i < output_arr.size(); i++) {
        fout << output_arr[i] << " ";
    }

    fin.close();
    fout.close();
    
    return 0;
}
