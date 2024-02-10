#include<bits/stdc++.h>

  int removeDuplicates(vector<int>& nums) {
        set<int>st;
        for(int i=0;i<nums.size();++i) {
            st.insert(nums[i]);//inserting elements
        }
        int index = 0;
        for(auto it:st){
            nums[index]=it ;
            index++;
        }
        return index;
    }

T.C.=O(N)
S.C.=O(N)


int removeDuplicates(vector<int> &arr, int n) {
	int i=0;
	for(int j=1;j<n;j++){
          if (arr[j] != arr[i]) {
			  arr[i+1]=arr[j];
              i++;
          }
        }
	return i+1;
}

T.C.=O(N)
S.C.=O(1)
