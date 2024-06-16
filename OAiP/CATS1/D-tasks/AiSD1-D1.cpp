#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <math.h>
using namespace std;


int main() {
    double xa, ya, xb, yb, x0, y0, b;
    FILE *f1 = fopen("input.txt", "r");
    fscanf(f1, "%lf %lf", &xa, &ya);
    fscanf(f1, "%lf %lf", &xb, &yb);
    fscanf(f1, "%lf %lf", &x0, &y0);
    fscanf(f1, "%lf", &b);
    fclose(f1);

    // перемещение точек так, чтобы они поворачивались относительно точки (0, 0)
    xa -= x0;
    ya -= y0;
    xb -= x0;
    yb -= y0;

    // float r = sqrt((xb - xa)*(xb - xa) + (yb - ya)*(yb - ya));
    double nxa = cos(M_PI * b / 180) * xa - sin(M_PI * b / 180) * ya;
    double nya = sin(M_PI * b / 180) * xa + cos(M_PI * b / 180) * ya;
    double nxb = cos(M_PI * b / 180) * xb - sin(M_PI * b / 180) * yb;
    double nyb = sin(M_PI * b / 180) * xb + cos(M_PI * b / 180) * yb;
    // cout << nxa << " " << round(cos(M_PI * b / 180)) << " " << sin(M_PI * b / 180);


    FILE *f2 = fopen("output.txt", "w");
    fprintf(f2, "%.9f %.9f %.9f %.9f", nxa + x0, nya + y0, nxb + x0, nyb + y0);
    fclose(f2); 

    return 0;
}
