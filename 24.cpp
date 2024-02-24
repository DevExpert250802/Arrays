#include <bits/stdc++.h> 
void sortArray(vector<int>& arr, int n){
   sort(arr.begin(),arr.end());
}

T.C.=O(N*logN)
S.C.=O(1)




#include <bits/stdc++.h>

void sortArray(vector<int> &arr, int n) {
   int cnt0 = 0, cnt1 = 0, cnt2 = 0;
   for (int i = 0; i < n; i++) {
      if (arr[i] == 0)
         cnt0++;
      else if (arr[i] == 1)
         cnt1++;
      else
         cnt2++;
   }
   for (int i = 0; i < n; i++) {
      if (cnt0) {
         arr[i] = 0;
         cnt0--;
      } else if (cnt1) {
         arr[i] = 1;
         cnt1--;
      } else {
         arr[i] = 2;
         cnt2--;
      }
   }
}

T.C.=O(2N)
S.C.=O(1)
   


   
#include <bits/stdc++.h> 
void sortArray(vector<int>&arr, int n){
    int low=0,mid=0,high=n-1;
    while(mid<=high){
       if(arr[mid]==0){
          swap(arr[low],arr[mid]);
          low++;
          mid++;
         }
         else if(arr[mid]==1){
            mid++;
         }
         else{
            swap(arr[mid],arr[high]);
            high--;
         }
      }
}

T.C.=O(N)
S.C.=O(1)

 
