#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int numBuckets = 128;

vector<string> bucketSort(vector<string> array, int pos=0) { 
    if (array.size() < 2 || pos == 3)
        return array;

    vector<vector<string>> buckets(numBuckets);
    for (int i = 0; i < array.size(); i++) {
        int index = int(array[i][pos]);
        buckets[index].push_back(array[i]);
	}

    for (int i = 0; i < numBuckets; i++) 
        buckets[i] = bucketSort(buckets[i], pos + 1);
    
    vector<string> answer;
    for (int i = 0; i < numBuckets; i++)
        for (int j = 0; j < buckets[i].size(); j++)
            answer.push_back(buckets[i][j]);
    
    return answer;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    vector<string> array(n);
    for (int i = 0; i < n; i++) {
        fin >> array[i];
    }
    
    array = bucketSort(array);

    for (int i = 0; i < n; i++) {
        fout << array[i] << endl;
        // cout << array[i] << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
