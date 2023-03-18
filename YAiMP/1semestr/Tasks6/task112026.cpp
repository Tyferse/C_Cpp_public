#include <iostream>
#include <string>
#include <vector>
using namespace std;


int hamingDist(vector<char> v1, vector<char> v2) {
    if (v1.size() != v2.size()) {
        return -1;
    }
 
    int k = 0;
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {
            k++;
        }
    }
 
    return k;
}


int main() {
    // // string s1, s2;
    // int max_length = 300000;
    // char s1[max_length], s2[max_length];
    // cin.getline(s1, max_length, '\n');
    // cin.getline(s2, max_length, '\n');
    // int i = 0, k = 0;
    // // ((65 <= (int)s1[i] && (int)s1[i] <= 90) || (97 <= (int)s2[i] && (int)s2[i] <= 122))
    // while (i < max_length && s1[i] != 0 && s2[i] != 0) {
    //     if (s1[i] != s2[i]) {
    //         k++;
    //         // cout << s1[i] << " " << s2[i] << endl;
    //     }

    //     // cout << (int)s1[i] << " " << (int)s2[i] << endl;
    //     i++;
    //     // cout << (int)s1[i] << " " << (int)s2[i] << endl;
    // }

    // cout << k;
    vector<char> s1, s2;
    char c = getchar();
    while (c != '\n') {
        s1.push_back(c);
        c = getchar();
    }

    c = getchar();
    while (c != '\n') {
        s2.push_back(c);
        c = getchar();
    }
    

    cout << hamingDist(s1, s2);

    return 0;
}
