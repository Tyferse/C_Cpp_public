#include <iostream>
#include <cmath>
#include <fstream>
#include <cmath>
using namespace std;


int main() {
    float x1, x2, y1, y2, xp, yp;
    bool prov = false;
    int flag = true;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> x1 >> y1 >> x2 >> y2;
    if ((x1 > 0) && (x1 < 9) && (x2 > 0) && (x2 < 9) && (y1 > 0) && (y1 < 9) && (y2 > 0) && (y2 < 9)) {
        prov = (abs(x1 - x2) == abs(y1 - y2));

        if (prov && ((abs(x1 - x2) > 1) && (abs(y1 - y2) > 1))) {
            if (((x1 < x2) && (y1 > y2)) || ((x1 > x2) && (y1 < y2))) {
                fout << ceil((x1 + x2) / 2) << " " << floor((y1 + y2) / 2);
            }
            else {
                fout << ceil((x1 + x2) / 2) << " " << ceil((y1 + y2) / 2);
            }
        }
        else if (prov && (abs(x1 - x2) <= 1) && (abs(y1 - y2) <= 1)) {
            fout << 0;
        }
        else if(!prov){
            for (int i = 1; i <= 8; i++) {
                for (int j = 1; j <= 8; j++) {
                    xp = i;
                    yp = j;
                    prov = ((abs(xp - x1)) == (abs(yp - y1))) && ((abs(xp - x2)) == (abs(yp - y2)));
                    if (prov) {
                        fout << xp << " " << yp;
                        flag = false;
                        break;
                    }
                }

                if (!flag)
                    break;
            }

            if (flag) 
                fout << 0;   
        }
    } 
    else
        fout << 0;
    
    return 0;
}
