class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Count the frequency of each element in arr1
        map<int, int> mp;
        for (int it1 : arr1) mp[it1]++;

        // Use an index to modify arr1 directly
        int index = 0;
        // Place elements according to the order in arr2
        for (int it2 : arr2) {
            while (mp[it2] > 0) {
                arr1[index++] = it2;
                mp[it2]--;
            }
        }
        // Collect and place remaining elements

        for (auto it : mp) {
            while (it.second > 0) {
                arr1[index++] = it.first;
                it.second--;
            }
        }
        return arr1;
    }
};
//size of arr1 =n
// T.C. = O(nlogn +n)
// S.C. = O(n)








// if     0 <= arr1[i], arr2[i] <= 1000   
// counting sort

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int max = *max_element(arr1.begin(),arr1.end());
        vector<int>mp(max+1,0);
        for (int it1 : arr1) mp[it1]++;

        // Use an index to modify arr1 directly
        int index = 0;
        // Place elements according to the order in arr2
        for (int it2 : arr2) {
            while (mp[it2] > 0) {
                arr1[index++] = it2;
                mp[it2]--;
            }
        }
        // Collect and place remaining elements

        for (int i = 0; i <= max; ++i) {
            while (mp[i] > 0) {
                arr1[index++] = i;
                mp[i]--;
            }
        }
        return arr1;
    }
};
//size of arr1 =n
//size of arr1 =m
//max element =k
// T.C. = O(n + m +k )
// S.C. = O(k)
