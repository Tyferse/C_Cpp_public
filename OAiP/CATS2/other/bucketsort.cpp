#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


int numBuckets = 6;

double minb(vector<double> three_hundred_bucks, double elem) {
    double min_bucks = elem;
    for (int i = 0; i < three_hundred_bucks.size(); i++) {
        if (three_hundred_bucks[i] < min_bucks)
            min_bucks = three_hundred_bucks[i];
    }

    return min_bucks;
}

double maxb(vector<double> three_hundred_bucks, double elem) {
    double max_bucks = elem;
    for (int i = 0; i < three_hundred_bucks.size(); i++) {
        if (three_hundred_bucks[i] > max_bucks)
            max_bucks = three_hundred_bucks[i];
    }

    return max_bucks;
}

vector<double> bucketSort(vector<double> array, double minElement, double maxElement) { 
    if (array.size() < 2 || minElement == maxElement)
        return array;

    double range = maxElement - minElement;

    vector<vector<double>> buckets(numBuckets);
    vector<double> minBuckets(numBuckets), maxBuckets(numBuckets);
    for (int i = 0; i < array.size(); i++) {
        int index = int((array[i] - minElement) * (numBuckets - 1) / range);
        buckets[index].push_back(array[i]);
        minBuckets[index] = minb(buckets[index], array[i]);
        maxBuckets[index] = maxb(buckets[index], array[i]);
	}

    for (int i = 0; i < numBuckets; i++) 
        buckets[i] = bucketSort(buckets[i], minBuckets[i], maxBuckets[i]);
    
    vector<double> answer;
    for (int i = 0; i < numBuckets; i++)
        for (int j = 0; j < buckets[i].size(); j++)
            answer.push_back(buckets[i][j]);
    
    return answer;
}

vector<double> insertsort(vector<double> array) {
    for (int i = 1; i < array.size(); i++) {
        int j = i - 1;
        while (j >= 0 && array[j] > array[j + 1]) {
            swap(array[j], array[j + 1]);
            j--;
        }
    }

    return array;
}

vector<double> bucketSort(vector<double> array) {
    double minElement = __DBL_MAX__;
    double maxElement = -1 * __DBL_MAX__;
    for (int i = 0; i < array.size(); i++) {
        minElement = min(minElement, array[i]);
        maxElement = max(maxElement, array[i]);
    } 

    double range = maxElement - minElement;
    vector<vector<double>> buckets(numBuckets);
    for (int i = 0; i < array.size(); i++) {  
        int index = int((array[i] - minElement) * (numBuckets - 1) / range);
        buckets[index].push_back(array[i]);
    }

    for (int i = 0; i < numBuckets; i++)
        buckets[i] = insertsort(buckets[i]);

    vector<double> answer;
    for (int i = 0; i < numBuckets; i++)
        for (int j = 0; j < buckets[i].size(); j++)
            answer.push_back(buckets[i][j]);

    return answer;
}

int main() {
    // ifstream fin("input.txt");
    // ofstream fout("output.txt");
    vector<double> arr = {426, 134, 891, 243, 620, 578, 655, 902, 319};

    double arrmin = arr[0], arrmax = arr[0];
    for (int i = 0; i < arr.size(); i++) {
        arrmin = arrmin > arr[i] ? arr[i] : arrmin;
        arrmax = arrmax < arr[i] ? arr[i] : arrmax;
    }
    
    // vector<double> arrn = bucketSort(arr, arrmin, arrmax);
    vector<double> arrn = bucketSort(arr);
    for (int i = 0; i < arrn.size(); i++) {
        cout << arrn[i] << " ";
    }

    // fin.close();
    // fout.close();
    
    return 0;
}
