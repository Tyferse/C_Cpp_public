#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Node {
    float v;
    Node *prev = nullptr;
    int number;
};

Node *Stack(float value) {
    Node *stk = new Node;
    stk->v = value;
    stk->number = 1;
    return stk;
}

Node *push(Node *stack, float value) {
    if (!stack)
        return Stack(value);

    Node *tmp = new Node;
    tmp->v = value;
    tmp->number = stack->number + 1;
    tmp->prev = stack;
    return tmp;
} 

Node *pop(Node *stack) {
    if (stack == nullptr)
        return stack;

    if (stack->number > 1) {
        stack = stack->prev;
        return stack;
    }
    else if (stack->number < 2)
        free(stack);

    return nullptr;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    float value;
    Node *st = nullptr;

    string command;
    bool err = false;
    if (!(fin >> command)) {
        err = true;
        fout << "ERROR";
    }

    while (!fin.eof()) {
        // cout << '"' << command << '"' << endl;
        if (command[0] == '+') {
            value = stof(command);
            if (!value) {
                err = true;
                fout << "ERROR";
                break;
            }

            // cout << value << " " << command << endl;
            st = push(st, value);
        }
        else if (command == "-") {
            // cout << "MM" << endl;
            if (st != nullptr)
                st = pop(st);
            else {
                fout << "ERROR";
                err = true;
                break;
            }
        }
        else {
            fout << "ERROR";
            err = true;
            break;
        }
        
        fin >> command;
    }

    if (!err && st == nullptr)
        fout << "EMPTY";
    else if (!err) {
        int n = st->number + 1;
        // cout << n << endl;
        float out_st[n] = {0};
        for (int i = n - 1; i > 0; i--) {
            out_st[i] = st->v;
            st = pop(st);
            // cout << out_st[i] << " ";
        }

        fout << out_st[1];
        for (int i = 2; i < n; i++) {
            fout << " " << out_st[i];
            // cout << out_st[i] << " ";
        }
    }

    fin.close();
    fout.close();
    
    return 0;
}


// #include<fstream> 
// #include <iostream> 
// #include<vector> 
// #include <stack>
//  #include<string> 
// #include<algorithm>
//  using namespace std; 
//  stack<int>st; 
//  int error = 0; 
//  void operation(string command) {     
//     if (command == "DROP")     
//     {         
//         if (st.size() > 0)         
//         {             
//             st.pop(); 
//             return;         
//             }         
//             else         
//             {             
//                 error = 1; 
//                 return;         
//                 }     }     
//                 if (command == "SWAP")     
//                 {         
//                     if (st.size() >= 2)         
//                     {             
//                         int a = st.top();             
//                         st.pop();             
//                         int b = st.top();             
//                         st.pop();             
//                         st.push(a);             
//                         st.push(b);             
//                         return;         
//                         }         
//                     else         
//                     {             
//                         error = 1;
//                         return;         
//                         }     
//                     }     
//                 if (command == "DUP")     
//                 {         
//                     if (st.size() > 0)         
//                     {             
//                         int a = st.top();             
//                         st.push(a);             
//                         return;         
//                         }         
//                     else         
//                     {             
//                         error = 1;             
//                         return;         
//                         }     
//                     }     
//                 if (command == "OVER")     
//                 {         
//                     if (st.size() >= 2)         
//                     {             
//                         int a = st.top();             
//                         st.pop();             
//                         int b = st.top();             
//                         st.pop();             
//                         st.push(b);             
//                         st.push(a);             
//                         st.push(b);             
//                         return;         
//                         }         
//                     else         
//                     {             
//                         error = 1; 
//                         return;         
//                         }    
//                     }     
//                 if (command == "+")     
//                 {         
//                     if (st.size() >= 2)         
//                     {             
//                         int a = st.top();             
//                         st.pop();             
//                         int b = st.top();             
//                         st.pop();             
//                         st.push(a + b);         
//                         }         
//                     else         
//                     {             
//                         error = 1;             
//                         return;         
//                         }     
//                     }     
//                 if (command == "-")     
//                 {         
//                     if (st.size() >= 2)         
//                     {             
//                         int a = st.top();             
//                         st.pop();             
//                         int b = st.top();             
//                         st.pop();             
//                         st.push(b - a); 
//                         return;         
//                         }         
//                     else         
//                     {             
//                         error = 1;             
//                         return;         
//                         }     
//                     }     
//                 if (command == "*")     
//                 {         
//                     if (st.size() >= 2)         
//                     {             
//                         int a = st.top();             
//                         st.pop();             
//                         int b = st.top();             
//                         st.pop();             
//                         st.push(b*a); 
//                         return;         
//                         }         
//                     else         
//                     {             
//                         error = 1;             
//                         return;         
//                         }       
//                     }     
//                 if (command == "/")     
//                     {         
//                     if (st.size() >= 2)         
//                     {             
//                         int a = st.top();             
//                         st.pop();             
//                         int b = st.top();             
//                         st.pop();             
//                         st.push(b/a); 
//                         return;         
//                         }         
//                     else         
//                     {            
//                         error = 1;             
//                         return;         
//                         }     
//                     } 
// } 

// bool isnumber(string x) {     
//     for (int i = 0; i < x.length(); i++)     
//     {         
//         if (x[i] > '9' || x[i] < '0')         
//         {             
//             return false;         
//             }     
//         }     
//     return true; 
// } 

// int main() {     vector<int>v;     ifstream in;     ofstream out;     in.open("input.txt");     out.open("output.txt");         string command;     while (in >> command&&error != 1)     {         if (isnumber(command) == true)         {             st.push(atoi(command.c_str())); continue;         }         operation(command);     }     if (error == 1)     {         out << "ERROR"; return 0;     }     if (st.size() == 0)     {         out << "EMPTY"; return 0;     }     while (st.size() != 0)     {         v.push_back(st.top());         st.pop();     }     reverse(v.begin(), v.end());     for (int i = 0; i < v.size(); i++)     {         out << v[i] << " ";     }     in.close();     out.close(); }