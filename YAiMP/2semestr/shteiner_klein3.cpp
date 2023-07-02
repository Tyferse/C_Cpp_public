#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <graphics.h>
using namespace std;


class Point {
    public:
        float x;
        float y;
        Point(float xi = 0.0, float yi = 0.0) {
            this->x = xi;
            this->y = yi;
        }

        float len() {
            return sqrt(this->x * this->x + this->y * this->y);
        }

        Point operator+(Point p2) {
            return Point(this->x + p2.x, this->y + p2.y);
        }

        Point operator-(Point p2) {
            return Point(this->x - p2.x, this->y - p2.y);
        }

        Point operator*(float v) {
            return Point(this->x * v, this->y * v);
        }

        float operator*(Point p2) {
            return (this->x * p2.x + this->y * p2.y) / (this->len() * p2.len());
        }
};

int X0 = 400, Y0 = 300;
float scale = 40;
float lims[4];

int xcoord(float x) {
    return int(X0 + scale * x);
}

int ycoord(float y) {
    return int(Y0 - scale * y);
}

void axes(float dv) {
    line(0, Y0, X0 * 2 - 1, Y0);
    line(X0, 0, X0, 799);

    line(X0, 0, xcoord(dv / 2), scale * dv);
    line(X0, 0, xcoord(-dv / 2), scale * dv);
    line(X0 * 2 - 1, Y0, X0 * 2 - scale * dv, ycoord(dv / 2));
    line(X0 * 2 - 1, Y0, X0 * 2 - scale *  dv, ycoord(-dv / 2));
    
    char s[10];
    int least_intx = floor(lims[0]);
    int least_inty = floor(lims[2]);
    for (int i = least_intx; i <= lims[1]; i++) {
        line(xcoord(i), ycoord(-dv / 2), xcoord(i), ycoord(dv / 2));

        if (i != 0){
            sprintf(s, "%d", i);
            outtextxy(xcoord(i) - 4, ycoord(-dv) + 3, s);
        }

        for (float j = i + dv; j < i + 1 && j < lims[1]; j += dv) {
            line(xcoord(j), ycoord(-dv / 4), xcoord(j), ycoord(dv / 4));
        }
    }

    for (int i = least_inty; i <= lims[3]; i++) {
        line(xcoord(-dv / 2), ycoord(i), xcoord(dv / 2), ycoord(i));

        if (i != 0){
            sprintf(s, "%d", i);
            outtextxy(xcoord(dv) + 4, ycoord(i) - 5, s);
        }

        for (float j = i + dv; j < i + 1 && j < lims[3]; j += dv) {
            line(xcoord(-dv / 4), ycoord(j), xcoord(dv / 4), ycoord(j));
        }
    }
}

void print_point(float x, float y, int dx, int dy) {
    char text[20];
    sprintf(text, "x=%.3f", x);
    outtextxy(xcoord(x) + dx, ycoord(y) + dy - 15, text);
    sprintf(text, "y=%.3f", y);
    outtextxy(xcoord(x) + dx, ycoord(y) + dy, text);
}

int main() {
    Point stnpt, p[3];
    for (int i = 0; i < 3; i++) {
        cin >> p[i].x >> p[i].y;
    }

    // Проверка углов между вершинами
    float angle[3];
    Point v[3] = {p[1] - p[2], p[2] - p[0], p[0] - p[1]};
    angle[0] = acos(((v[1].x * v[1].x + v[1].y * v[1].y) + (v[2].x * v[2].x + v[2].y * v[2].y)
                 - (v[0].x * v[0].x + v[0].y * v[0].y)) / (2 * v[1].len() * v[2].len()));
    angle[2] = acos(((v[1].x * v[1].x + v[1].y * v[1].y) + (v[0].x * v[0].x + v[0].y * v[0].y)
                 - (v[2].x * v[2].x + v[2].y * v[2].y)) / (2 * v[0].len() * v[1].len()));
    angle[1] = M_PI - angle[0] - angle[2];

    bool found = false;
    for (int i = 0; i < 3; i++) {
        if (angle[i] > 2 * M_PI / 3) {
            cout << p[i].x << " " << p[i].y;
            stnpt.x = p[i].x, stnpt.y = p[i].y;
            found = true;

            // Вывод всего этого на координатные оси
            float xmax = p[0].x > p[1].x ? p[0].x : p[1].x;
            xmax = p[2].x > xmax ? p[2].x : xmax;
            float xmin = p[0].x < p[1].x ? p[0].x : p[1].x;
            xmin = p[2].x < xmin ? p[2].x : xmin;
            float ymax = p[0].y > p[1].y ? p[0].y : p[1].y;
            ymax = p[2].y > ymax ? p[2].y : ymax;
            float ymin = p[0].y < p[1].y ? p[0].y : p[1].y;
            ymin = p[2].y < ymin ? p[2].y : ymin;
            lims[0] = xmin - 5, lims[1] = xmax + 5,
            lims[2] = ymin - 5, lims[3] = ymax + 5;

            scale = max((lims[1] - lims[0]), (lims[3] - lims[2])) / 1.25;
            cout << "\nScale = " << scale;

            // -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
            initwindow(X0 * 2, Y0 * 2);
            axes(1/3.);
            
            setcolor(LIGHTBLUE);
            line(xcoord(p[i].x), ycoord(p[i].y), xcoord(p[(i + 1) % 3].x), ycoord(p[(i + 1) % 3].y));
            line(xcoord(p[i].x), ycoord(p[i].y), xcoord(p[(i + 2) % 3].x), ycoord(p[(i + 2) % 3].y));

            setcolor(GREEN);
            fillellipse(xcoord(stnpt.x), ycoord(stnpt.y), 7, 7);
            setcolor(WHITE);
            print_point(stnpt.x, stnpt.y, 15, -10);
            
            fillellipse(xcoord(p[(i + 1) % 3].x), ycoord(p[(i + 1) % 3].y), 4, 4);
            fillellipse(xcoord(p[(i + 2) % 3].x), ycoord(p[(i + 2) % 3].y), 4, 4);

            getch();
            closegraph();

            break;
        }
    }

    if (not found) {
        // Выбираем вершины ребра напротив наибольшего угла
        int ai = angle[0] > angle[1] ? 0 : 1;
        ai = angle[ai] > angle[2] ? ai : 2;
        int bi = (ai + 1) % 3, ci = (bi + 1) % 3;

        // Определяем, с какой стороны строить правильный треугольник
        int tr_side = (v[ai].x * v[ci].y - v[ai].y * v[ci].x > 0) ? 1 : -1,
            k = 60 * tr_side;
        
        // Поворячиваем большую сторону на 60 градусов
        // и находим точку для построения правильного треугольника
        Point d(v[ai].x * cos(k * M_PI / 180) - v[ai].y * sin(k * M_PI / 180), 
                v[ai].x * sin(k * M_PI / 180) + v[ai].y * cos(k * M_PI / 180));
        Point dpt = p[bi] - d, cd = p[ci] - dpt;

        // Находим координаты центра тяжести треугольника, как точку пересечения двух его медиан
        Point bc_center = p[ci] + v[ai] * 0.5;
        Point cd_center = p[ci] - cd * 0.5;
        
        Point median1 = dpt - bc_center, median2 = p[bi] - cd_center;
        float xc = (bc_center.x * median2.x - cd_center.x * median1.x) / (median2.x - median1.x),
              yc = median1.y * (xc - bc_center.x) / median1.x + bc_center.y;
        
        // Через уравнение окружности находим её точку пересечения с вектором,
        // проведённым к внешней вершине, что и является точкой Ферма
        float r = sqrt((dpt.x - xc) * (dpt.x - xc) + (dpt.y - yc) * (dpt.y - yc));
        Point con_line = dpt - p[ai];
        float a = (dpt.x - p[ai].x) * (dpt.x - p[ai].x) + (dpt.y - p[ai].y) * (dpt.y - p[ai].y),
              b = 2 * con_line.x * (p[ai].x - xc) + 2 * con_line.y * (p[ai].y - yc), 
              c = (p[ai].x - xc) * (p[ai].x - xc) + (p[ai].y - yc) * (p[ai].y - yc) - r * r;
        float t1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a), 
              t2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        
        // cout << dpt.x << " " << dpt.y << endl;
        // cout << cd.x << " " << cd.y << endl;
        // cout << bc_center.x << " " << bc_center.y << endl;
        // cout << cd_center.x << " " << cd_center.y << endl;
        // cout << a << " " <<  b << " " << c << endl;
        // cout << t1 << " " << t2 << endl;
        if ((t1 > 1 - 1e-6 && t1 < 1 + 1e-6) || (t1 > -1e-6 && t1 < 1e-6)) {
            stnpt.x = con_line.x * t2 + p[ai].x;
            stnpt.y = con_line.y * t2 + p[ai].y;
        }
        else if ((t2 > 1 - 1e-6 && t2 < 1 + 1e-6) || (t2 > -1e-6 && t2 < 1e-6)) {
            stnpt.x = con_line.x * t1 + p[ai].x;
            stnpt.y = con_line.y * t1 + p[ai].y;
        }

        cout << stnpt.x << " " << stnpt.y;

        float xmax = p[0].x > p[1].x ? p[0].x : p[1].x;
        xmax = p[2].x > xmax ? p[2].x : xmax;
        float xmin = p[0].x < p[1].x ? p[0].x : p[1].x;
        xmin = p[2].x < xmin ? p[2].x : xmin;
        float ymax = p[0].y > p[1].y ? p[0].y : p[1].y;
        ymax = p[2].y > ymax ? p[2].y : ymax;
        float ymin = p[0].y < p[1].y ? p[0].y : p[1].y;
        ymin = p[2].y < ymin ? p[2].y : ymin;
        lims[0] = xmin - 5, lims[1] = xmax + 5,
        lims[2] = ymin - 5, lims[3] = ymax + 5;

        scale =  max((lims[1] - lims[0]), (lims[3] - lims[2])) / 1.25;
        cout << "\nScale = " << scale;

        // -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

        /*
        Тесты:
        -15 5
        -9 -1
         7 -1

        -8 -5
        10 1
        -9 8

        0 4
        3 14
        2 2

        9 -6
        -7 8
        5 10
        */

        initwindow(X0 * 2, Y0 * 2);
        axes(1/3.);
        
        // вывод точек и соединение их рёбрами
        setcolor(LIGHTBLUE);
        line(xcoord(p[0].x), ycoord(p[0].y), xcoord(p[1].x), ycoord(p[1].y));
        line(xcoord(p[1].x), ycoord(p[1].y), xcoord(p[2].x), ycoord(p[2].y));
        line(xcoord(p[2].x), ycoord(p[2].y), xcoord(p[0].x), ycoord(p[0].y));

        setcolor(LIGHTRED);
        line(xcoord(p[0].x), ycoord(p[0].y), xcoord(stnpt.x), ycoord(stnpt.y));
        line(xcoord(p[1].x), ycoord(p[1].y), xcoord(stnpt.x), ycoord(stnpt.y));
        line(xcoord(p[2].x), ycoord(p[2].y), xcoord(stnpt.x), ycoord(stnpt.y));

        setcolor(GREEN);
        fillellipse(xcoord(stnpt.x), ycoord(stnpt.y), 7, 7);
        setcolor(WHITE);
        print_point(stnpt.x, stnpt.y, 15, -10);
         
        fillellipse(xcoord(p[0].x), ycoord(p[0].y), 4, 4);
        fillellipse(xcoord(p[1].x), ycoord(p[1].y), 4, 4);
        fillellipse(xcoord(p[2].x), ycoord(p[2].y), 4, 4);

        getch();
        closegraph();
    }

    return 0;
}
