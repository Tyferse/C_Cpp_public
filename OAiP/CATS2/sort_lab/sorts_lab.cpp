#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <iomanip>
using namespace std;


void bubble_sort_flag(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
		bool flag = false;
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
				flag = true;
            }
        }

        if(!flag) 
            break;
    }
}

void counting_sort(vector<int> &arr) {
    int minv = RAND_MAX;
    int maxv = 0;
    for (int i = 0; i < arr.size(); i++) {
        minv = min(arr[i], minv);
        maxv = max(arr[i], maxv);
    }

    int sublen = maxv - minv + 1;
    int subarr[sublen];
    fill(subarr, subarr + sublen, 0);

    for (int i = 0; i < arr.size(); ++i)
        subarr[arr[i] - minv]++;
    
    int j = 0;
    for (int n = 0; n < sublen; n++) {
        for (int i = 0; i < subarr[n]; i++) {
            arr[j] = n + minv;
            j++;
        }
    }
}

template <typename T>
void timetest(void func(vector<T> &), int size_limit=6) {
    int sz = 1;
    for (int i = 1; i <= size_limit; i++) {
        sz *= 10;
        sz += 3;
        vector<int> array(sz);
        cout << sz << endl;
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < sz; k++) {
                array[k] = rand();
                // cout << array[j] << endl;
            }

            // cout << endl << endl << endl;
            double startt = clock();
            func(array);
            double endt = clock();

            // cout << j + 1 << '. ';
            cout << (endt - startt) / 1000 << endl;
            // for (int j = 0; j < 10; j++) {
            //     cout << array[j] << " ";
            // }

            // cout << endl;
        }
    }
}

int main() {
    timetest(counting_sort, 9);

    return 0;
}
