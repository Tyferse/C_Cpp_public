#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
using namespace std;


int main() {
    set <int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int type, x;
        cin >> type >> x;
        if (type == 1) { // добавление
            s.insert(x);
        } 
        else if (type == 2) { // проверка
            if (s.find(x) == s.end()) {
                  cout << "NO\n";
            } 
            else {
                cout << "YES\n";
            }
        } 
        else { // удаление
              s.erase(x);
        }
    }


    for (auto now = s.begin(); now != s.end(); now++) {
        cout << *now << ' ';
    }

    cout << endl;

    for (auto now : s) {    
        cout << now << ' ';
    }

    multiset <int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    int cnt = 0;
    for (auto now = s.lower_bound(1); now != s.upper_bound(1); now++) {
        cnt++;
    }

    cout << cnt;


    map <int, string> m;
    m[112] = "sos";
    if (m.find(112) != m.end()) {
        cout << "YES\n";
    }

    m[102] = "emergency";
    for (auto now : m) {
        cout << now.first << " " << now.second << "\n";
    }


    map <string, vector <string>> mv;
    mv["Vasya"] = { "112133", "12341" };
    for (auto now :mv["Vasya"]) {
        cout << now << " ";
    }

    return 0;
} 
