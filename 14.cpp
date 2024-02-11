Approach 1 : XOR

int getSingleElement(vector<int> &arr){
	int n = arr.size();
	
	// Initializing the XOR to 0.
	int XOR = 0;
	for(int i = 0; i < n; ++i){
		
		// XOR of the current element with the XOR of previous elements.
		XOR ^= arr[i];
	}
	return XOR;
}

Time Complexity: O(N)
Space Complexity: O(1)



Approach 2 : 
  
int getSingleElement(vector<int> &arr){
    int x;
    for(int i=0;i<arr.size();i=i+2){
        if(arr[i]!=arr[i+1]){
            x=arr[i];
		    break;
        }
    }
    return x;
}

Time Complexity: O(N/2)
Space Complexity: O(1)


  Approach 3 : Binary search


#include<vector>
int getSingleElement(vector<int> &arr){
	int n =  arr.size();

	//Edgecases, mid at 0 or last.
	if(n==1) return arr[0];
	if(arr[0]!=arr[1]) return arr[0];
	if(arr[n-1]!=arr[n-2]) return arr[n-1];

	//Apply binary search
	int l = 1, r =n - 2;
	int mid;
	//Intuition for moving left right is, notice the indexes, notice how they are even and odd.
	while(l<=r){
		mid = l + (r-l)/2;
		if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]) return arr[mid];

	    if((mid%2 ==1 && arr[mid-1] == arr[mid]) || (mid%2 ==0 && arr[mid] == arr[mid+1])){
            l = mid+1;
		} 
		else{
				r = mid-1;
			}
		}
	return -1;	
}


Time Complexity: O(logN)
Space Complexity: O(1)
