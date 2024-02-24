#include<bits/stdc++.h>
vector<vector<int>> triplet(int n, vector<int> &nums){
    vector<vector<int>>ans;
    set<vector<int>>st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
           for(int k=j+1;k<n;k++){
              if(nums[i]+nums[j]+nums[k]==0){
                  vector<int>temp = {nums[i],nums[j],nums[k]};
                  sort(temp.begin(),temp.end());
                   st.insert(temp);
               }
            }
        }
    }
    // vector<vector<int>>ans(st.begin(),st.end());
    ans.insert(ans.end(), st.begin(), st.end());
    return ans;
}

Time Complexity: O(N^3 * log(no. of unique triplets)), where N = size of the array.
Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity.
But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.
  
Space Complexity: O(2 * no. of the unique triplets) as we are using a set data structure and a list to store the triplets.




  #include<bits/stdc++.h>
vector<vector<int>> triplet(int n, vector<int> &nums){
    set<vector<int>>st;
    for(int i=0;i<n;i++){
        set<int>hashset;
        for(int j=i+1;j<n;j++){
          int third=-(nums[i]+nums[j]);
          if(hashset.find(third)!=hashset.end()){
              vector<int>temp={nums[i],nums[j],third};
              sort(temp.begin(),temp.end());
              st.insert(temp);
            }
          hashset.insert(nums[j]);
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}



Time Complexity: O(N^2 * log(no. of unique triplets)), where N = size of the array.
Reason: Here, we are mainly using 2 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity.
But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.
  
Space Complexity: o(N) for hashset +  O(2 * no. of the unique triplets) as we are using a set data structure and a list(vector) to store the triplets.
