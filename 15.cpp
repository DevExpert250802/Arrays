Longest Subarray With Sum K


#include <bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
   map<long long,int>mp;
   int maxlength=0;
   long long sum=0;
   for(int i=0;i<a.size();i++){
   sum+=a[i];
   if(sum==k)
   maxlength=max(maxlength,i+1);
   long long rem = sum-k;
   if (mp.find(rem) != mp.end()) {    
      int length = i-mp[rem];              //mp[rem] would give the index of the element where the prefix sum
      maxlength=max(maxlength,length);
   }
   if (mp.find(rem) == mp.end())
   mp[sum]=i;
   }
   return maxlength;
}

Time Complexity: O(n * log n) or O(n)
Space Complexity: O(n)




  
#include <bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
int left=0 ;
int right=0;
long long sum =a[0];
int maxlength=0;
int n= a.size();
while(right<n){
   while(left<=right && sum>k){
      sum-=a[left];
      left++;
   }
   if(sum==k){
      maxlength=max(maxlength,right-left+1);
   }
   right++;
   sum+=a[right];
}
   return maxlength;
}

Time Complexity : O(n)
Space Complexity: O(1)
