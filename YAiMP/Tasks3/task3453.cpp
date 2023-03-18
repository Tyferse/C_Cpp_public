#include <iostream>
#include <string>
#include <set>
using namespace std;


int main () {
    int n_requests, a;
    string command;
    cin >> n_requests;
    set<int> array[n_requests];
    for (int i = 0; i < n_requests; i++) {
        cin >> command;
        if (command == "ADD") {
            cin >> a;
            array->insert(a);
        }
        else if (command == "PRESENT") {
            cin >> a;
            if (array->count(a)) 
                cout << "YES" << endl;
            else 
                cout << "NO" << endl;
        }
        else if (command == "COUNT") {
            cout << array->size() << endl;
        }
    }
    
    return 0;
}
