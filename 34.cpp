Approach :

Step 1: Find all possible permutations of elements present and store them.

Step 2: Search input from all possible permutations.

Step 3: Print the next permutation present right after it.


Time Complexity:   O(N!xN)

Space Complexity:  O(1) 






vector<int> nextPermutation(vector<int> &arr, int n){

    next_permutation(arr.begin(),arr.end());
    return arr;
}

Time Complexity:   O(N)

Space Complexity:  O(1) 




#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &arr, int n){
    int ind = -1; // break point
    for (int i =n-2;i>=0; i--) {
        if (arr[i]<arr[i+1]) {
            ind = i;
            break;
        }
    }
// If break point does not exist:
// reverse the whole array:
    if (ind == -1) {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    // Step 2: Find the next greater element and swap it with arr[ind]:
    for (int i=n-1;i>ind;i--) {
        if (arr[i] > arr[ind]) {
            swap(arr[i], arr[ind]);
            break;
        }
    }
 // Step 3: reverse the right half:
    reverse(arr.begin()+ind+1, arr.end());

    return arr;
}


Time Complexity:   O(3N)

Space Complexity:  O(1) 
