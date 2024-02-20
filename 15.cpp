Longest Subarray With Sum K (Positive)


You are given an array 'a' of size 'n' and an integer 'k'.Find the length of the longest subarray of 'a' whose sum is equal to 'k'.
Example :
Input: ‘n’ = 7 ‘k’ = 3
‘a’ = [1, 2, 3, 1, 1, 1, 1]



   
  int longestSubarrayWithSumK(vector<int> a, long long k) {
   int n = a.size();
   int length=0;
    for(int i=0;i<n;i++){
       int sum =0;
      for(int j=i;j<n;j++){
         sum+=a[j];
         if(sum==k)
         length=max(length,j-i+1);
       }
    }
    return length;
} 

Time Complexity : O(n*n)
Space Complexity: O(1)



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
   if (mp.find(sum) == mp.end())
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
