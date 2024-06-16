#include <iostream>
#include <fstream>
using namespace std;


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N, u, v;
    fin >> N >> u >> v;

    int x, y, d;
    if (N == 1) {
        fin >> x >> y >> d;
        if (u != x || v != y)
            fout << 0 << " " << 0;
        else
            fout << d;
    }
    else if (N == 2) {
        bool ans = false;
        if (u != x || v != y) {
            ans = true;
            fout << 0 << " " << 0;
        }
        else {
            fout << d;
            ans = true;
        }
        if (!ans) {
        fin >> x >> y >> d;
        if (u != x || v != y)
            fout << 0 << " " << 0;
        else
            fout << d;
        }
    }
    else {
        float a1, a2, b1, b2, d1, d2;
        bool ans = false;
        for (int i = 0; i < 3; i++) {
            if (i == 0) {
                fin >> x >> y >> d;
            }
            else if (i == 1) {
                fin >> a1 >> b1 >> d1;
            }
            else if (i == 2) {
                fin >> a2 >> b2 >> d2;

                a1 = float(x) - a1;
                a2 = float(x) - a2;
                b1 = float(y) - b1;
                b2 = float(y) - b2;
                d1 = float(d) - d1;
                d2 = float(d) - d2;

                if (a1 != 0) {
                    float incr = -a2 / a1;
                    b2 = incr * b1 + b2;
                    d2 = incr * d1 + d2;
                }
                else
                    break;

                if (b2 == 0 && a1 == 0) {
                    break;
                }
                else if (b2 == 0) {
                    break;
                }
                else if (a1 == 0 && a2 != 0) {
                    float b = d2 / b2;
                    // bkkvkivkivkigkigvkjgb

                }
                else {
                    float b = d2 / b2;
                    float a = (d1 - b1 * b) / a1;
                    float c = d - (a * x + b * y);

                    fout << int(a * u + b * v + c);
                    ans = true;
                }
            }
        }

        if (!ans)
            fout << 0 << " " << 0;
    }


    return 0;
}
