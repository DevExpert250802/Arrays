Problem statement :

You are given an integer array 'arr' of size 'N' and an integer 'K'.
Your task is to find the total number of subarrays of the given array whose sum of elements is equal to k.
A subarray is defined as a contiguous block of elements in the array.

Example:
Input: ‘N’ = 4, ‘arr’ = [3, 1, 2, 4], 'K' = 6
Output: 2
Explanation: The subarrays that sum up to '6' are: [3, 1, 2], and [2, 4].



int findAllSubarraysWithGivenSum(vector<int>&a,int k){
    int n =a.size();
    int count=0;
    for(int i=0;i<n;i++){
        int sum=0;
       for(int j=i;j<n;j++){
           sum+=a[j];
           if(sum==k) count++;
        }
    }
    return count;
}

T.C. = O(N^2)
S.C. = O(1)




  int findAllSubarraysWithGivenSum(vector<int>&a,int k){
    umordered_map<int,int>mp;
    int count=0,prefixsum=0;
    mp[0]=1;
    //O(N)
    for (int i=0; i<a.size(); i++) {
      prefixsum += a[i];
      int remaining = prefixsum-k;
      count+=mp[remaining];
      mp[prefixsum]+=1;
    }
    return count;
}



T.C. = O(N*logN)  map
T.C. = O(N)      unordered_map(best and avg => 1 and worst => N)

S.C. = O(N)
