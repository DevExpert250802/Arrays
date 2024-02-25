#include<bits/stdc++.h>
vector<vector<int>> fourSum(vector<int>& nums, int target){
    set<vector<int>>st;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum== target){
                      vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                      sort(temp.begin(), temp.end());
                      st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}


Time Complexity: O(N^4), where N = size of the array.
Reason: Here, we are mainly using 4 nested loops. But we not considering the time complexity of sorting as we are just sorting 4 elements every time.

Space Complexity: O(2 * no. of the quadruplets) as we are using a set data structure and a list to store the quads





#include<bits/stdc++.h>
vector<vector<int>> fourSum(vector<int>& nums, int target){
    set<vector<int>>st;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<long long>hashset;
            for(int k=j+1;k<n;k++){
               long long sum=nums[i]+nums[j];
               sum+=nums[k];
               long long fourth=target-sum;
               if(hashset.find(fourth)!=hashset.end()){
                  vector<int> temp = {nums[i],nums[j],nums[k],(int)fourth};
                  sort(temp.begin(),temp.end());
                  st.insert(temp); 
                }
            hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}




Time Complexity: O(N^3*log(M)), where N = size of the array, M = no. of elements in the set.
Space Complexity: O(2 * no. of the quadruplets)+O(N)



#include<bits/stdc++.h>
vector<vector<int>> fourSum(vector<int>& nums, int target){
    vector<vector<int>>ans;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j!= i+1 && nums[j]==nums[j-1]) continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum=nums[i]+nums[j];
                sum+=nums[k];
                sum+=nums[l];
                if(sum==target){
                  vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                  ans.push_back(temp);
                  k++;
                  l--;
                  while (k < l && nums[k] == nums[k - 1])
                    k++;
                  while (k < l && nums[l] == nums[l + 1])
                    l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }

    return ans;
}



Time Complexity: O(N^3), where N = size of the array.

Space Complexity: O(no. of quadruplets), This space is only used to store the answer. We are not using any extra

