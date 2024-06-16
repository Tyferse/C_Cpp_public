#include <fstream>
#include <vector>
#include <iostream>
using namespace std;


int sortr(vector<long long> & v, long long start, long long end) {
    long long m = start, p;
    if(end-start < 1) 
        return 0;
    
    long long x = v[start];
    
    for(int i = start+1; i<=end; i++) {
        if(v[i] < x) m++;
    }
    
    p = v[m];
    v[m] = x;
    v[start] = p;
    long long s1 = start, s2 = m+1;
    while(s1<m && s2 <=end) {
        if (v[s1]>=x) {
            while (v[s2] >=x && s2 < end) s2++;
            p = v[s1];
            v[s1] = v[s2];
            v[s2] = p;
        }
        s1++;
    }
    sortr(v, start, m-1);
    sortr(v, m+1, end);
    return 0;
}

int main()
{
    long long  L, S, N, D, res = 0, p = 0, zap;
    vector<long long> DV = {0};
    
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    
    fin >> L >> S >> N;
    
    zap = S;
    
    for(long long i = 0; i < N; i++) {
        fin >> D;
        if(D < L){
            DV.push_back(D);
        }
    }
    
    DV.push_back(L);
    N = DV.size();
    
    sortr(DV, 0, N-1);
    
    for (long long i = N-1; i>0; i--) {
        DV[i] -= DV[i-1];
    }
    
    for(long long i = 1; i < N; i++) {
        if(DV[i] > S){
            fout << -1;
            return 0;
        }
    }
    
    for (long long i = 1; i < N; i++) {
        if(DV[i] <= zap) { 
            zap -= DV[i];
        }
        else {
            zap = S;
            i--;
            res++;
        }
    }
    fout << res;

    return 0;
}
