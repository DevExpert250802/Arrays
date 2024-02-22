Problem statement
Given an array ‘Arr’ that has ‘N’ elements. You have to find the subarray of ‘Arr’ that has the largest product. You must return the product of the subarray with the maximum product.

For example:
When ‘N’ = 5, and ‘Arr’ = {-2, 3, -4, 0}

The subarrays of ‘Arr’ are:
{-2}, {-2, 3}, {-2, 3, -4}, {-2, 3, -4, 0}, {3}, {3, -4}, {3, -4, 0}, {-4}, {-4, 0}, {0}.
Among these, {-2, 3, -4} is the subarray having the maximum product equal to 24.
Hence, the answer is 24.





#include<bits/stdc++.h>

int subarrayWithMaxProduct(vector<int> &arr) {
  int n = arr.size();
  int maxi=INT_MIN;
  for (int i=0; i<n; i++){
	int product=1;
    for(int j=i;j<n;j++){
		product*=arr[j];
		maxi=max(maxi,product);
	}
  }
  return maxi;
}

T.C. = O(n*n)
S.C. = O(1)



  
Optimal : 1
  
  
           Observations:

If the given array only contains positive numbers: If this is the case, we can confidently say that the maximum product subarray will be the entire array itself.
  
If the given also array contains an even number of negative numbers: As we know, an even number of negative numbers always results in a positive number. 
So, also, in this case, the answer will be the entire array itself.
  
If the given array also contains an odd number of negative numbers: Now, an odd number of negative numbers when multiplied result in a negative number. 
Removal of 1 negative number out of the odd number of negative numbers will leave us with an even number of negatives. 
Hence the idea is to remove 1 negative number from the result. Now we need to decide which 1 negative number to remove such that the remaining subarray yields the maximum product.

If the array contains 0’s as well: We should never consider 0’s in our answer(as considering 0 will always result in 0) and we want to obtain the maximum possible product.
So, we will divide the given array based on the location of the 0’s and apply the logic of case 3 for each subarray.








#include<bits/stdc++.h>
int subarrayWithMaxProduct(vector<int> &arr){
  int n = arr.size();
  int maxi=INT_MIN;
  int prefix=1,suffix=1;
  for (int i=0; i<n; i++){
    if(prefix==0) prefix=1;
    if(suffix==0) suffix=1;
    
    prefix*=arr[i];
    suffix*=arr[n-i-1];
    maxi=max(maxi,max(prefix,suffix));
  }
  return maxi;
}


T.C. = O(n)
S.C. = O(1)




  
