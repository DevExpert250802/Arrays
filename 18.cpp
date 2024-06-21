Problem statement :
You are given an array 'arr' of length 'n', consisting of integers.
A subarray is a contiguous segment of an array. In other words, a subarray can be formed by removing 0 or more integers from the beginning and 0 or more integers from the end of an array.
Find the sum of the subarray (including empty subarray) having maximum sum among all subarrays.The sum of an empty subarray is 0.
  
Example :
Input: 'arr' = [1, 2, 7, -4, 3, 2, -10, 9, 1]
Output: 11
Explanation: The subarray yielding the maximum sum is [1, 2, 7, -4, 3, 2].






long long maxSubarraySum(vector<int> arr, int n){
   long long maxsum=0;
   for(int i=0;i<n;i++){
      long long sum=0;
      for(int j=i;j<n;j++){
         sum+=arr[j];
         maxsum = max(maxsum,sum);
      }
   }
   return maxsum;
}



T.C. = O(n*n)
S.C. = O(1)

  

  

long long maxSubarraySum(vector<int> arr, int n){
   long long maxsum=LONG_MIN,sum=0;
   for(int i=0;i<n;i++){
      sum+=arr[i];

      if(sum>maxsum) maxsum= sum;
     
      if(sum<0) sum=0;
   }
   return maxsum;
}


T.C. = O(n)
S.C. = O(1)
