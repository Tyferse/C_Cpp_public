#include <iostream>
using namespace std;


int main() {
    int n, max_el;
    cin >> n;

    int c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (i > 0) {
            max_el = c > max_el ? c : max_el;
        }
        else 
            max_el = c;
    }

    cout << max_el << endl;

    return 0;
}