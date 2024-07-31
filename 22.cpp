#include <bits/stdc++.h>
using namespace std;

vector<int> findLongestIncreasingSubarray(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return {};

    int max_start = 0;
    int max_length = 1;
    int current_start = 0;
    int current_length = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i-1]) {
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

    vector<int> longest_subarray(arr.begin() + max_start, arr.begin() + max_start + max_length);
    return longest_subarray;
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = findLongestIncreasingSubarray(arr);

    cout << "Longest Increasing Subarray: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
