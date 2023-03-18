#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    int R, N;
    cin >> R >> N;

    vector<string> dict;
    string key, value;
    for (int i = 0; i <= R; i++) {
        getline(cin, key);
        getline(cin, value);
        dict.push_back(key);
        dict.push_back(value);
        cout << key << " | " << value << endl;
    }

    


    return 0;
}
