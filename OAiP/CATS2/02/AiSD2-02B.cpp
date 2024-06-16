#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


struct rectangle {
    int x, y;
};

bool maxcompr(rectangle a, rectangle b) {
    return a.y > b.y || (a.y == b.y && a.x > b.x);
}

int main() {
    ifstream fin("power.in");
    ofstream fout("power.out");

    int n, k;
    fin >> n >> k;
    vector<rectangle> rects(n);
    for (int i = 0; i < n; i++) {
        fin >> rects[i].x >> rects[i].y;
    }

    sort(rects.begin(), rects.end(), maxcompr);
    // make_heap(rects.begin(), rects.end(), maxcompr);
    // sort_heap(rects.begin(), rects.end(), maxcompr);

    // for (int i = 0; i < n; i++) {
    //     cout << rects[i].x << " " << rects[i].y << endl;
    // }

    long long smax = 0;
    std::priority_queue<int, std::vector<int>, std::greater<>> pqx;
    for (int i = 0; i < rects.size(); i++) {
        pqx.push(rects[i].x);
        if (pqx.size() > k) {
            pqx.pop();
        }

        if (pqx.size() == k) {
            smax = max(smax, 1LL * rects[i].y * pqx.top());
        }
    }

    fout << smax;
    // cout << smax;

    fin.close();
    fout.close();
    
    return 0;
}
