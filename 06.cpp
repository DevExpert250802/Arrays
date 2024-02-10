#include<bits/stdc++.h>
vector<int> rotateArray(vector<int>arr, int k) {
    int n = arr.size();
    k = k%n;
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());
    reverse(arr.begin(),arr.end());
    return arr;
}

T.C.=O(2N)
S.C.=O(1)
