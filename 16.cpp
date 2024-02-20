Longest Subarray with sum K [positives + negatives]

Problem statement:

Ninja and his friend are playing a game of subarrays. They have an array ‘NUMS’ of length ‘N’. 
Ninja’s friend gives him an arbitrary integer ‘K’ and asks him to find the length of the longest subarray in which the sum of elements is equal to ‘K’.
Ninjas asks for your help to win this game. Find the length of the longest subarray in which the sum of elements is equal to ‘K’.
If there is no subarray whose sum is ‘K’ then you should return 0.

Example:
Input: ‘N’ = 5,  ‘K’ = 4, ‘NUMS’ = [ 1, 2, 1, 0, 1 ]

Output: 4
There are two subarrays with sum = 4, [1, 2, 1] and [2, 1, 0, 1]. Hence the length of the longest subarray with sum = 4 is 4.







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
