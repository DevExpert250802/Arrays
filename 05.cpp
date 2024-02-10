#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& arr, int n) {
    int temp = arr[0];
    for(int i=0;i<n;i++){
        arr[i] = arr[i+1];
    }
    arr[n-1]=temp;
    return arr;
}

T.C.=O(N)
S.C.=O(1)
