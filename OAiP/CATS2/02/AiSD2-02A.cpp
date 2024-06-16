#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void sift_up_max(vector<int> & heap, int idx) {
    while (idx > 0 && heap[idx] > heap[(idx - 1) / 2]) {  
        swap(heap[idx], heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

void sift_up_min(vector<int> & heap, int idx) {
    while (idx > 0 && heap[idx] < heap[(idx - 1) / 2]) {  
        swap(heap[idx], heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

void sift_down_max(vector<int> & heap, int idx, int depth) {
    while (2 * idx + 1 < depth) {
        int leftidx = 2 * idx + 1;
        int rightidx = 2 * idx + 2;

        int next = leftidx;
        if (rightidx < depth && heap[rightidx] > heap[leftidx]) {
            next = rightidx;
        }

        if (heap[idx] >= heap[next]) {
            break;
        }

        // cout << heap[idx] << " | " << heap[next] << endl;
        swap(heap[idx], heap[next]);
        idx = next;
    }
}

void sift_down_min(vector<int> & heap, int idx, int depth) {
    while (2 * idx + 1 < depth) {
        int leftidx = 2 * idx + 1;
        int rightidx = 2 * idx + 2;

        int next = leftidx;
        if (rightidx < depth && heap[rightidx] < heap[leftidx]) {
            next = rightidx;
        }

        if (heap[idx] <= heap[next]) {
            break;
        }

        // cout << heap[idx] << " | " << heap[next] << endl;
        swap(heap[idx], heap[next]);
        idx = next;
    }
}

// void build_max_heap(vector<int> &arr) {
//     for (int i = arr.size() / 2; i >= 0; i--) {
//         sift_down_max(arr, i, arr.size());
//     } 
// }

// void build_min_heap(vector<int> &arr) {
//     for (int i = arr.size() / 2; i >= 0; i--) {
//         sift_down_min(arr, i, arr.size());
//     } 
// }

// void pyromid_sort(vector<int> & arr) {
//     // build_heap(arr);

//     for (int i = arr.size() - 1; i >= 0; i--) {
//         swap(arr[0], arr[i]);
//         sift_down(arr, 0, i);
//     }
// }

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, ai;
    fin >> n;

    vector<int> right_heap, left_heap;
    fin >> ai;
    right_heap.push_back(ai);

    // cout << ai << " ";
    fout << ai << " ";
    for (int i = 1; i < n; i++) {
        fin >> ai;
        
        if (right_heap.size() > left_heap.size()) {
            if (ai > right_heap[0]) {
                // cout << endl << "first" << endl;
                left_heap.push_back(right_heap[0]);
                sift_up_max(left_heap, left_heap.size() - 1);

                right_heap[0] = right_heap[right_heap.size() - 1];
                right_heap.pop_back();
                sift_down_min(right_heap, 0, right_heap.size());

                right_heap.push_back(ai);
                sift_up_min(right_heap, right_heap.size() - 1);
            }
            else {
                // cout << endl << "second" << endl;
                left_heap.push_back(ai);
                sift_up_max(left_heap, left_heap.size() - 1);
            }
            
            // cout << left_heap[0] << " ";
            fout << left_heap[0] << " ";
        }
        else {
            if(ai < left_heap[0]) {
                // cout << endl << "third" << endl;
                right_heap.push_back(left_heap[0]);
                sift_up_min(right_heap, right_heap.size() - 1);

                left_heap[0] = left_heap[left_heap.size() - 1];
                left_heap.pop_back();
                sift_down_max(left_heap, 0, left_heap.size());

                left_heap.push_back(ai);
                sift_up_max(left_heap, left_heap.size() - 1);
            }
            else {
                // cout << endl << "fourth" << endl;
                right_heap.push_back(ai);
                sift_up_min(right_heap, right_heap.size() - 1);
            }

            // cout << right_heap[0] << " ";
            fout << right_heap[0] << " ";
        }
    }

    fin.close();
    fout.close();
    
    return 0;
}
