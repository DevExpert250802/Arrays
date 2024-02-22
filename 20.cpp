Problem statement
Given an array ‘A’ consisting of ‘N’ integers and an integer ‘B’, find the number of subarrays of array ‘A’ whose bitwise XOR(^) of all elements is equal to ‘B’.
A subarray of an array is obtained by removing some(zero or more) elements from the front and back of the array.

Example:
Input: ‘N’ = 4 ‘B’ = 2  ‘A’ = [1, 2, 3, 2]

Output: 3
Explanation: Subarrays have bitwise xor equal to ‘2’ are: [1, 2, 3, 2], [2], [2].



  int subarraysWithSumK(vector<int>a,int b){
   int n=a.size();
   int count=0;
   for(int i=0;i<n;i++){
       int XOR=0;
       for(int j=i;j<n;j++){
           XOR^=a[j];
           if(XOR==b) count++;
       }
    }
    return count;
}


T.C. = O(n^2)
S.C. = O(1)


  

  #include<bits/stdc++.h>
int subarraysWithSumK(vector<int>a,int b){
    map<int,int>mp;
    mp[0]=1;
    int count=0;
    int frontXOR=0;
    for(int i=0;i<a.size();i++){
    frontXOR ^= a[i];
    int x= frontXOR^b;
    count+=mp[x];
    mp[frontXOR]+=1;
    }
    return count;
}


T.C. = O(N*logN)  map
T.C. = O(N)      unordered_map(best and avg => 1 and worst => N)

S.C. = O(N)
