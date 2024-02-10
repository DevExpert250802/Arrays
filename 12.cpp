int findMaxConsecutiveOnes(vector<int>& nums) {
     int cnt=0;
     int maxcnt=0;
      for(int i=0;i<nums.size();i++){
          if(nums[i]==1){
            cnt++;
            maxcnt=max(cnt,maxcnt);
          }
          else cnt=0;
        }
      return maxcnt;
    }



T.C.=O(N)
S.C.=O(1)
