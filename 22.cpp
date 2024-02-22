#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> findLongestIncreasingSubarray(vector<int>& arr) {
    int n = arr.size();
    int max_start = 0;
    int max_length = 1;
    int current_start = 0;
    int current_length = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1]) {
            current_length++;
        } else {
            current_start = i;
            current_length = 1;
        }

        if (current_length > max_length) {
            max_start = current_start;
            max_length = current_length;
        }
    }

    return make_pair(max_start, max_length);
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 2, 3, 4, 5};
    
    pair<int, int> result = findLongestIncreasingSubarray(arr);

    cout << "Longest Increasing Subarray: ";
    for (int i = result.first; i < result.first + result.second; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

return 0;
}
