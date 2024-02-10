#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    sort(arr.begin(),arr.end());
    return arr[n-1];
}

T.C.=O(NlogN)
S.C.=O(1)




  #include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    int maxi=INT_MIN;
   for(int i=0; i<n;i++){
       maxi=max(maxi,arr[i]);
   }
   return maxi;
}


T.C.=O(N)
S.C.=O(1)
