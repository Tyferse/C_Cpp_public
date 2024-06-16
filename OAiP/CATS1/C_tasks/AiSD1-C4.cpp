#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;



int main() {
    float x1, x2, y1, y2, xs, ys;
    bool test = false;
    int found = false;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> x1 >> y1 >> x2 >> y2;
    if ((x1 > 0) && (x1 < 9) && (x2 > 0) && (x2 < 9) && (y1 > 0) && (y1 < 9) && (y2 > 0) && (y2 < 9)) {
        test = (abs(x1 - x2) == abs(y1 - y2)); // проверка на принадлежность пешек одной прямой

        if (test && (abs(x1 - x2) <= 1) && (abs(y1 - y2) <= 1)) { // если пешка расположены радом
            fout << 0;
        }
        else if (test && ((abs(x1 - x2) > 1) && (abs(y1 - y2) > 1))) {
            if (((x1 < x2) && (y1 > y2)) || ((x1 > x2) && (y1 < y2))) { 
                fout << ceil((x1 + x2) / 2) << " " << floor((y1 + y2) / 2);
            }
            else {
                fout << ceil((x1 + x2) / 2) << " " << ceil((y1 + y2) / 2);
            }
        }
        else if(!test) {
            for (int i = 1; i <= 8; i++) {
                for (int j = 1; j <= 8; j++) {
                    xs = i;
                    ys = j;
                    test = ((abs(xs - x1)) == (abs(ys - y1))) && ((abs(xs - x2)) == (abs(ys - y2)));
                    if (test) {
                        fout << xs << " " << ys;
                        found = true;
                        break;
                    }
                }

                if (found)
                    break;
            }

            if (not found) 
                fout << 0;   
        }
    } 
    else
        fout << 0;
    
    return 0;
}

