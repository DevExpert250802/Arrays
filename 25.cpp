vector<int> twoSum(vector<int>& nums, int target) {
   int n= nums.size();
   for(int i=0; i<n; i++){
       for(int j=i+1; j<n; j++){
           if(nums[i]+nums[j]== target)
           return{i,j};
        }
    }
   return{};
}

T.C.=O(N*N)
S.C.=O(1)



  
  
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
     for (int i = 0; i < nums.size(); i++){
       int a = nums[i];
        int ans = target - nums[i];
           if (mp.find(ans) != mp.end()){
              return {mp[ans], i};
           }
           mp[a]=i;
       }
       return {};
    } 

T.C.=O(N*logN)
S.C.=O(1)


  
                                                              <!--  2-pointer only for true or false -->

    String twoSum(vector<int>& nums, int target){
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == target){
                return "YES";
            }
            else if(sum < target) left++;
            else right--;
        }
        return "NO";
    }


# Complexity
- Time complexity:O(N) + O(N*logN)[for sorting], where N = size of the array.
- Space complexity:O(1)



  
