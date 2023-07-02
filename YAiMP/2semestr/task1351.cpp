#include <iostream>
using namespace std;


int main() {
    float xa, ya, xb, yb, xc, yc, k;
    cin >> xa >> ya >> xb >> yb >> xc >> yc >> k;

    float ab[2] = {xb - xa, yb - ya}, ac[2] = {xc- xa, yc - ya};

    float xb_new = k * ab[0] + xa;
    float yb_new = k * ab[1] + ya;
    float xc_new = k * ac[0] + xa;
    float yc_new = k * ac[1] + ya;

    cout << xb_new << " " << yb_new << endl;
    cout << xc_new << " " << yc_new;
}
