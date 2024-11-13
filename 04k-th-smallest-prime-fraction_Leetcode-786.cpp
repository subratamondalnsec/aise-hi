#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {//m1
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {//t.c=o(n^2logk)
        priority_queue<pair<double,pair<int,int>>> pq;
        for(int i = 0; i < arr.size() - 1; i++) {
            for(int j = i + 1; j < arr.size(); j++) {
                double fraction = (double) arr[i] / arr[j];
                pq.push({fraction, {arr[i], arr[j]}});
                if(pq.size() > k) pq.pop();
            }
        }
        return {pq.top().second.first, pq.top().second.second};
    }
};


int main() {
    Solution sol;

    // Test case 1: Small array of primes
    vector<int> arr1 = {1, 2, 3, 5};
    int k1 = 3;
    vector<int> result1 = sol.kthSmallestPrimeFraction(arr1, k1);
    cout << "The " << k1 << "-th smallest fraction is: " 
         << result1[0] << "/" << result1[1] << endl;

    // Test case 2: Larger array of primes
    vector<int> arr2 = {1, 7, 23, 29, 47};
    int k2 = 5;
    vector<int> result2 = sol.kthSmallestPrimeFraction(arr2, k2);
    cout << "The " << k2 << "-th smallest fraction is: " 
         << result2[0] << "/" << result2[1] << endl;

    return 0;
}
