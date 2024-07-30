/*
    Company Tags                : Amazon, Microsoft, Paytm
    Leetcode Qn Link            : https://leetcode.com/problems/subarray-sums-divisible-by-k/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/sub-array-sum-divisible-by-k2617/1
*/



//Approach-1 (O(n^2))
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), count = 0;
        for(int i = 1; i<n; i++) {
            nums[i] += nums[i-1];
        }
        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                int sum = (i==0) ? nums[j] : nums[j] - nums[i-1];

                if(sum%k == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};




//Approach-2 (Time : O(n), Space : O(n))


/*
    Concept behind this method
    K
    
    a  b  c  d  e  fg  h   i    j
    |-----pa-------||----r------|
    
    |--------------pb-----------|
    
    Lets say, 
    pb-pa = r
    (pb-pa)%k = r%k
    if (r is divisible )
    pb % k = pa % k
    Which proves that the subarray is divisible by k
*/

|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|  /*
|                If we get -ve remainders  :
|  
|  Remember:     positive counterpart of -ve remainder 
|                
|               -r % k   =>     (-r+k) %k    
|                  2%6    =     (2+6)%6
|                    2     =      2
|     same way
|                   -2%6   =  (-2+6)% 6
|                     -2   =>  4            (both represent -2 %6 )
|
| but it will not work if  |-r|>k , 
|  eg : -7%3;
|                                  |-----------------------------------------|
|                                  |    -r % k   =>     ((-r%k) + k) %k      |
|                                  |     r % k   =>     ((r%k)  + k) %k      |
|                                  | ----------------------------------------|
| */
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


  
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int prefixSum=0;
        int count =0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];
            int remainder = prefixSum % k;
            if(remainder <0){
               remainder= remainder + k;
            }
            count+= mp[remainder];
            mp[remainder] +=1;
        } 
        return count;
    }
};



------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Alter :



class Solution {
public:
    int subarraysDivByK(vector<int>&arr, int k){
        int prefixSum=0, count=0, n=arr.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            prefixSum =(prefixSum + arr[i]% k +k) %k;
            count+= mp[prefixSum];
            mp[prefixSum]++;
        } 
        return count;
    }
};



------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Alter :



class Solution {
public:
    int subarraysDivByK(vector<int>&arr, int k) {
        unordered_map<int,int>mp;
        int prefixSum=0, count=0, n=arr.size();
        mp[0]=1;
        for(int i=0;i<n;i++){
            prefixSum+= arr[i]% k + k;
            int remainder = prefixSum %k;
            count+= mp[remainder];
            mp[remainder] +=1;
        } 
        return count;
    }
};
