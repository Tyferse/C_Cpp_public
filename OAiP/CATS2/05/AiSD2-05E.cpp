#include <iostream> 
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> b;

bool compr(int fi, int si) {
    return b[fi] < b[si];
}

int main() {
    cin >> n;

    vector<int> a(n), indexes(n);
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        b.push_back(tmp);
        indexes[i] = i;
    }

    delete tmp;
    
    sort(a.begin(), a.end());
    sort(indexes.begin(), indexes.end(), compr);
    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << " ";
    // }

    // cout << endl;

    // for (int i = 0; i < n; i++) {
    //     cout << b[indexes[i]] << " ";
    // }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (a[i] <= b[indexes[i]]) 
            ans[indexes[i]] = a[i];
        else {
            cout << -1;
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
