/*
283. Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]

*/


vector<int> moveZeros(int n, vector<int> a) {
    vector<int>temp;
    for(int i=0;i<n;i++){
        if(a[i]!=0)
        temp.push_back(a[i]);
    }
    for(int i=0;i<temp.size();i++){
        a[i]=temp[i];
    }
    for(int i=temp.size();i<n;i++){
        a[i]=0;
    }
    return a;
}

// T.C.=O(2N)
// S.C.=O(N)


vector<int> moveZeros(int n, vector<int> a) {
    int j=-1;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            j=i;
            break;
        } 
    }
    if(j==-1) return a;
    for(int i=j+1;i<n;i++){
            if(a[i]!=0){
            swap(a[j],a[i]);
            j++;
        } 
    }  
    return a;
}
T.C.=O(N)
S.C.=O(1)  
