Least Number of Unique Integers after K Removals   1481

//T.C : O(nlogn)
//S.C : O(n)

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (auto it : arr)  mp[it]++;
        vector<int> freq;
        for (auto i : mp) freq.push_back(i.second);
        sort(freq.begin(), freq.end());

        int elementRemoved = 0;
        for (int i=0;i<freq.size();i++) {
            elementRemoved+=freq[i];
            if(elementRemoved>k) return freq.size()-i;
        }
        return 0;
    }
};





//Approach-2 (Using min-heap)
//T.C : O(nlogn)
//S.C : O(n)

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int>freq;
        for (auto it : arr)freq[it]++;
        priority_queue<int,vector<int>,greater<int>>q;
        for (auto it : freq) q.push(it.second);

        int elementRemoved = 0;
        while(!q.empty()){
            elementRemoved+=q.top();
            if(elementRemoved>k)return q.size();
            q.pop();
        }
        return 0;
    }
};





//Approach-3 (Using Counting Sort)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int>freq;
        for(int &x : arr)freq[x]++;
        vector<int> freqCount(n+1,0);
        for(auto &it : freq) freqCount[it.second]++;

        int remaingUniqueElements = freq.size();
        for(int freq = 1; freq <= n; freq++) {
            int numElementsToRemove = min(k/freq, freqCount[freq]);
            
            k -= (numElementsToRemove * freq);
            remaingUniqueElements -= numElementsToRemove;
            if(k <= freq)  return remaingUniqueElements;
        }
        return 0;
    }
};

