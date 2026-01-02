#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

// problem link - https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

// it is basically counting sort

class Solution {
  public:
  
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n < 0) return;

        int aux[3] = {0, 0, 0};
        for(int i=0; i<n ; i++){
            aux[ arr[i] ] += 1;
        }

        int j=0;
        for(int i=0; i<3; i++){
            int temp = aux[i];
            while(temp--) arr[j++] = i;
        }

    }
};