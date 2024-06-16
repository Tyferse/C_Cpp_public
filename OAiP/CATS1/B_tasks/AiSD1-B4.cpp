#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


string add_edge(int n_edge) {
    if (n_edge % 3 == 0) {
        return "/|";
    }
    else if (n_edge % 3 == 1) {
        return " +";
    }
    else if (n_edge % 3 == 2) {
        return " |";
    }

    return "";
}


void write_edges1(int start, int n_edge, bool is_upper, ofstream &fout) {
    // ofstream f("output.txt", ios_base::app);
    if (is_upper) {
        // int j = 0;
        // do {
        //     cout << add_edge(n_edge + 2 * (j / 2));
        //     fout << add_edge(n_edge + 2 * (j / 2));
        //     j += 2;
        // } while (j < start - n_edge);
        for (int j = 0; j < start - n_edge; j += 2) {
            cout << add_edge(n_edge + 2 * (j / 2));
            fout << add_edge(n_edge + 2 * (j / 2));
        }
    }
    else {
        // int j = start - n_edge;
        // do {
        //     cout << add_edge(n_edge + 2 * (j / 2));
        //     fout << add_edge(n_edge + 2 * (j / 2));
        //     j -= 2;
        // } while (j >= 0);
        for (int j = start - n_edge; j >= 0; j -= 2) {
            cout << add_edge(n_edge + 2 * (j / 2));
            fout << add_edge(n_edge + 2 * (j / 2));
        }
    }
}


void write_edges2(int start, int n_edge, bool is_upper, ofstream &fout) {
    if (is_upper) {
        for (int j = 0; j <= start - 1; j++) {
            // cout << n_edge + j;
            cout << add_edge(n_edge + j);
            fout << add_edge(n_edge + j);
        }
    }
    else {
        for (int j = start - 1; j >= 0; j--) {
            // cout << n_edge + j;
            cout << add_edge(n_edge + j);
            fout << add_edge(n_edge + j);
        }
    }
}


void write_edges3(int n_edge, bool is_upper, ofstream &fout) {
    if (is_upper) {
        for (int i = 0; i < n_edge; i++) {
            cout << add_edge(n_edge + i);
            fout << add_edge(n_edge + i);
        }
    }
    else {
        for (int i = n_edge - 1; i >= 0; i--) {
            cout << add_edge(n_edge + i);
            fout << add_edge(n_edge + i);
        }
    }
}


int main() {
    int w, h, d, w1, h1, d1;
    // FILE *f1 = fopen("input.txt", "r");
    // fscanf(f1, "%d %d %d %d %d %d", &w, &h, &d, &w1, &h1, &d1);
    // fclose(f1);
    ifstream fin("input.txt", ios_base::in);
    fin >> w >> h >> d >> w1 >> h1 >> d1;
    fin.close();

    // FILE *f2 = fopen("output.txt", "w");
    ofstream fout;
    fout.open("output.txt", ios_base::out | ios_base::trunc);

    // Поверхность параллелепипеда
    int dots = 2 * h;
    int edge = 3 * d;
    for (int i = (h - h1) * 2 + 1; i > 0; i--) {
        for (int j = dots; j > 0; j--) {
            cout << ".";
            fout << ".";
        }

        dots--;

        if (i % 2 == 0) {
            for (int j = 0; j < w; j++) {
                fout << "/   ";
                cout << "/   ";
            }
            
            // for (int j = 3 * d - edge; j >= 0; j -= 2) {
            //     cout << add_edge(edge + 2 * (j / 2));
            //     fout << add_edge(edge + 2 * (j / 2));
            // }

            write_edges1(3 * d, edge, false, fout);
            edge--;

            cout << endl;
            fout << "\n";
        }
        else if (i % 2 == 1) {
            for (int j = 0; j < w; j++) {
                cout << "+---";
                fout << "+---";
            }

            fout << "+";
            cout << "+";
            
            if (i != (h - h1) * 2 + 1) {
                // for (int j = 3 * d - edge; j >= 0; j -= 2) {
                //     cout << add_edge(edge + 2 * (j / 2));
                //     fout << add_edge(edge + 2 * (j / 2));
                // }

                write_edges1(3 * d, edge, false, fout);
                edge--;
            }

            cout << endl;
            fout << "\n";
        }
    }

    // Поверхность вырезанной части параллелепипеда

    if (d1 != 0) {
        // Боковая поверхность вырезанной части
        // int idepth = d1 * 3;
        int ihight = h * 3;
        int idots = dots;
        int iedge = idots;
        int imod2 = (3 * h - edge) % 2;
        int imod3 = (3 * h - edge) % 3;
        for (int i = d1 * 3 + h1 * 2 + 1; i > 0; i--) {
            for (int j = dots; j > 0; j--) {
                fout << ".";
                cout << ".";
            }
            dots--;

            if (i % 2 == imod2 && dots >= 0) {
                for (int j = (w - w1); j > 0; j--) {
                    fout << "/   ";
                    cout << "/   ";
                }
                
                // iedge
                // for (int j = ((h - h1) * 2 + 1) - iedge; j >= 0; j -= 2) {
                //     cout << add_edge(iedge + 2 * (j / 2));
                //     fout << add_edge(iedge + 2 * (j / 2));
                // }

                write_edges1(idots, iedge, false, fout);
                iedge--;
            }
            else if (i % 2 != imod2 && dots >= 0) {
                for (int j = (w - w1); j > 0; j--) {
                    fout << "+---";
                    cout << "+---";
                }

                fout << "+";
                cout << "+";

                // iedge
                // for (int j = ((h - h1) * 2 + 1) - iedge; j >= 0; j -= 2) {
                //     cout << add_edge(iedge + 2 * (j / 2));
                //     fout << add_edge(iedge + 2 * (j / 2));
                // }

                write_edges1(idots, iedge, false, fout);
                iedge--;
            }


            if (dots < 0) {
                if (ihight % 3 == 0) {
                    for (int j = (w - w1); j > 0; j--) {
                        fout << "+---";
                        cout << "+---";
                    }

                    fout << "+";
                    cout << "+";
                }
                else {
                    for (int j = (w - w1); j > 0; j--) {
                        fout << "|   ";
                        cout << "|   ";
                    }

                    fout << "|";
                    cout << "|";
                }

                ihight--;
                write_edges2(h1, i, false, fout);
            }


            if ((i + 1) % 3 == imod3) {
                for (int j = w1; j > 0; j--) {
                    fout << "---+";
                    cout << "---+";
                }
            }
            else {
                for (int j = w1; j > 0; j--) {
                    fout << "   |";
                    cout << "   |";
                }
            }


            // for (int j = 3 * d - edge; j >= 0; j -= 2) {
            //     cout << add_edge(edge + 2 * (j / 2));
            //     fout << add_edge(edge + 2 * (j / 2));
            // }

            if (edge > 0) {
                write_edges1(h - h1, edge, true, fout);
                edge--;
            }
            else {
                // Realise this shit too
                
            }
            
            cout << endl;
            fout << "\n";
        }


        // "Нижняя" (верхняя) поверхность вырезанной части
    }
    // else {
    //     // int ihight = h * 3;
    //     int idots = dots;
    //     // int iedge = idots;
    //     int imod2 = (3 * h - edge) % 2;
    //     // int imod3 = (3 * h - edge) % 3;
    //     for (int i = d1 * 3 + h1 * 2 + 1; i > 0; i--) {
    //         for (int j = dots; j > 0; j--) {
    //             fout << ".";
    //             cout << ".";
    //         }
    //         dots--;

    //         if (i % 2 == imod2 && dots >= 0) {
    //             for (int j = (w - w1); j > 0; j--) {
    //                 fout << "/   ";
    //                 cout << "/   ";
    //             }
                
    //             // iedge
    //             // for (int j = ((h - h1) * 2 + 1) - iedge; j >= 0; j -= 2) {
    //             //     cout << add_edge(iedge + 2 * (j / 2));
    //             //     fout << add_edge(iedge + 2 * (j / 2));
    //             // }

    //             // write_edges1(idots, iedge, false, fout);
    //             // iedge--;
    //         }
    //         else if (i % 2 != imod2 && dots >= 0) {
    //             for (int j = (w - w1); j > 0; j--) {
    //                 fout << "+---";
    //                 cout << "+---";
    //             }

    //             fout << "+";
    //             cout << "+";

    //             // iedge
    //             // for (int j = ((h - h1) * 2 + 1) - iedge; j >= 0; j -= 2) {
    //             //     cout << add_edge(iedge + 2 * (j / 2));
    //             //     fout << add_edge(iedge + 2 * (j / 2));
    //             // }

    //             // write_edges1(idots, iedge, false, fout);
    //             // iedge--;
    //         }

    //         // for (int j = 3 * d - edge; j >= 0; j -= 2) {
    //         //     cout << add_edge(edge + 2 * (j / 2));
    //         //     fout << add_edge(edge + 2 * (j / 2));
    //         // }

    //         if (edge > 0) {
    //             write_edges2(h, edge, true, fout);
    //             edge--;
    //             cout << "!!";
    //         }
    //         else {
    //             // Realise this shit too
                
    //         }
            
    //         cout << endl;
    //         fout << "\n";
    //     }
    // }

    int jhight = h * 2 - 2;
    for (int i = (d - d1) * 3; i > 0; i--) {
        if (i % 3 == 1) {
            for (int j = w; j > 0; j--) {
                cout << "+---";
            }

            cout << "+";
        }
        else {
            for (int j = w; j > 0; j--) {
                cout << "|   ";
            }

            cout << "|";
        }

        if (h % 2 == 1) {
            if (i == (d - d1) * 3) {
                edge += 2;
            }

            if (edge > 2) {
                write_edges2(h - h1, edge, true, fout);
                edge--;
            }
            else {
                write_edges3((int)round((jhight - 1 * (jhight % 2 == 0)) / 2.), true, fout);
                jhight--;

                if (abs(jhight % 2) == 1) { 
                    cout << "/";
                    fout << "/";
                }

                cout << "__" << (int)round((jhight - 1 * (jhight % 2 == 0)) / 2.);
            }
        }
        else {
            
        } 
        

        cout << endl;
        fout << "\n";
    }


    fout.close();

    return 0;
}
