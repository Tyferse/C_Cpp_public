#include <iostream>
#include <vector>
#include <string>
using namespace std;


int p = 29;
int np = 'a' + 1;

long long hashstr(string str, int l, int r) {
    long long sum = 0;
    for (int i = l; i <= r; i++) {
        sum *= p;
        sum += str[i] - np;
    }

    return sum;
}

int main() {
    string s;
    cin >> s;

    long long hash_list[s.size()] = {s[0] - np};
    for (int i = 1; i < s.size(); i++) {
        hash_list[i] = hash_list[i - 1] * p + s[i] - np;
        // cout << hash_list[i] << " ";
    }

    long long p_pows[s.size()] = {1};
    for (int i = 1; i < s.size(); i++)
        p_pows[i] = p_pows[i - 1] * p;
    
    int n, a, b, c, d;
    cin >> n;
    for (int k = 0; k < n; k++) {
        cin >> a >> b >> c >> d;

        if (a == c && b == d)
            cout << "Yes" << endl;
        else if (b - a == 0 && d - c == 0)
            if (s[a - 1] == s[c - 1])
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        else if (c - a != d - b)
            cout << "No" << endl;
        else {
            long long hash1 = hash_list[b - 1], hash2 = hash_list[d - 1];
            // long long hash12, hash22;
            if (a > 1) 
                hash1 -= hash_list[a - 2] * p_pows[b - a + 1];
            
            // cout << "1: " << hash1 << endl;
            // for (int i = 0; i < a - 1; i++) 
            //     hash1 /= p;
            
            if (c > 1)
                hash2 -= hash_list[c - 2] * p_pows[d - c + 1];
            
            // cout << "2: " << hash2 << endl;
            // for (int i = 0; i < c - 1; i++) 
            //     hash2 /= p;

            if ((long long)hash1 == (long long)hash2) 
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}
