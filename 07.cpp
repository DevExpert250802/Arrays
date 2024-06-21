// Rotate Array to Right

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int  n = nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        
    }
};


T.C.=O(2N)
S.C.=O(1)
