#include <iostream>
#include <limits>
#include <typeinfo>
#include <iomanip>
using namespace std;


template<class T>
void f(T t) { 
    cout << typeid(t).name(); 
}


int main() {
    /*
    long long x[13] = {bool; char; unsigned char; short; unsigned short; 
                 int; unsigned int; long long; unsigned long long; 
                 float; double; long double};
    */

    int length = 18;


    //bool i = 0;
    cout << setw(length) << "bool";
    cout << setw(length) << " " << sizeof(std::numeric_limits<bool>::max()) << " ";
    cout << setw(length) << std::numeric_limits<bool>::lowest() << setw(length) << " " << std::numeric_limits<bool>::max();
    cout << endl;

    //char j = 0;
    cout << setw(length) << "char";
    cout << setw(length) << "" << sizeof(std::numeric_limits<char>::max()) << " ";
    cout << setw(length) << std::numeric_limits<char>::lowest() << setw(length) << " " << std::numeric_limits<char>::max();
    cout << endl;

    //unsigned char k = 0;
    cout << setw(length) << "unsigned char";
    cout << setw(length) << " " << sizeof(std::numeric_limits<unsigned char>::max()) << " ";
    cout << setw(length) << std::numeric_limits<unsigned char>::lowest() << setw(length) << " " << std::numeric_limits<unsigned char>::max();
    cout << endl;

    //short l = 0;
    cout << setw(length) << "short";
    cout << setw(length) << " " << sizeof(std::numeric_limits<short>::max()) << " ";
    cout << setw(length) << std::numeric_limits<short>::lowest() << setw(length) << " " << std::numeric_limits<short>::max();
    cout << endl;

    //unsigned short m = 0;
    cout << setw(length) << "unsigned short";
    cout << setw(length) << " " << sizeof(std::numeric_limits<unsigned short>::max()) << " ";
    cout << setw(length) << std::numeric_limits<unsigned short>::lowest() << setw(length) << " " << std::numeric_limits<unsigned short>::max();
    cout << endl;

    //int o = 0;
    cout << setw(length) << "int";
    cout << setw(length) << " " << sizeof(std::numeric_limits<int>::max()) << " ";
    cout << setw(length) << std::numeric_limits<int>::lowest() << setw(length) << " " << std::numeric_limits<int>::max();
    cout << endl;

    //unsigned int p = 0;
    cout << setw(length) << "unsigned int";
    cout << setw(length) << " " << sizeof(std::numeric_limits<unsigned int>::max()) << " ";
    cout << setw(length) << std::numeric_limits<unsigned int>::lowest() << setw(length) << " " << std::numeric_limits<unsigned int>::max();
    cout << endl;

    //long long q = 0;
    cout << setw(length) << "long long";
    cout << setw(length) << " " << sizeof(std::numeric_limits<long long>::max()) << " ";
    cout << setw(length) << std::numeric_limits<long long>::lowest() << setw(length) << " " << std::numeric_limits<long long>::max();
    cout << endl;

    //unsigned long long r = 0;
    cout << setw(length) << "unsigned long long";
    cout << setw(length) << " " << sizeof(std::numeric_limits<unsigned long long>::max()) << " ";
    cout << setw(length) << std::numeric_limits<unsigned long long>::lowest() << setw(length) << " " << std::numeric_limits<unsigned long long>::max();
    cout << endl;

    //float t = 0;
    cout << setw(length) << "float";
    cout << setw(length) << " " << sizeof(std::numeric_limits<float>::max()) << " ";
    cout << setw(length) << std::numeric_limits<float>::lowest() << setw(length) << " " << std::numeric_limits<float>::max();
    cout << endl;

    //double u = 0;
    cout << setw(length) << "double";
    cout << setw(length) << " " << sizeof(std::numeric_limits<double>::max()) << " ";
    cout << setw(length) << std::numeric_limits<double>::lowest();
    cout << setw(length) << " " << std::numeric_limits<double>::max();
    cout << endl;

    //long double w = 0;
    cout << setw(length) << "long double";
    cout << setw(length) << " " << sizeof(std::numeric_limits<long double>::max()) << " ";
    cout << setw(length) << std::numeric_limits<long double>::lowest() << setw(length) << " " << std::numeric_limits<long double>::max();
    cout << endl;


    return 0;
}
