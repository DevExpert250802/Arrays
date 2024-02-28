#include<bits/stdc++.h> 
vector<int> majorityElement(vector<int> v) {
    set<int> st;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (v[i] == v[j]) 
                cnt++;
        }
        if (cnt > n / 3) 
            st.insert(v[i]);
    }
    vector<int> ans(st.begin(), st.end());
    return ans;
}






#include<bits/stdc++.h> 
vector<int> majorityElement(vector<int> v) {
    vector<int>list;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        if(list.size()==0 || list[0]!=v[i]){
        int cnt = 0;
        for (int j = 0; j < n; j++) {
          if (v[i] == v[j])
            cnt++;
        }
        if (cnt > n / 3)
          list.push_back(v[i]);
        }
        if(list.size()==2) break;
    }
    return list;
}



Time Complexity: O(N^2), where N = size of the given array.

Space Complexity: O(1)






#include<bits/stdc++.h> 
vector<int> majorityElement(vector<int> v) {
    vector<int>ans;
    map<int,int>mp;
    int n = v.size();
    for (int i=0;i<n;i++){
        mp[v[i]]++;
    }
    for(auto it:mp){
       if(it.second>n/3)ans.push_back(it.first);
    }
    return ans;
}




#include<bits/stdc++.h> 
vector<int> majorityElement(vector<int> v) {
    vector<int>list;
    unordered_map<int,int>mp;
    int n = v.size();
    for (int i=0;i<n;i++){
        mp[v[i]]++;
    }
    for(auto it:mp){
       if(it.second>n/3)list.push_back(it.first);
    }
    sort(list.begin(), list.end());
    return list;
}



#include<bits/stdc++.h> 
vector<int> majorityElement(vector<int> v){
    vector<int>list;
    unordered_map<int,int>mp;
    int n = v.size();
    int mm= floor(n/3)+1;

    for (int i=0;i<n;i++){
        mp[v[i]]++;
        if(mp[v[i]] == mm) list.push_back(v[i]);
        if(list.size()==2) break;
    }
    sort(list.begin(),list.end());
    return list;
}





Time Complexity: O(N*logN), where N = size of the given array.
If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N^2)
Space Complexity: O(N)




#include<bits/stdc++.h>
vector<int> majorityElement(vector<int> v) {
    int n = v.size();
    int cnt1 = 0 , cnt2=0;
    int el1 = INT_MIN,el2=INT_MIN;

    for(int i=0; i<n; i++){
        if(cnt1==0 && v[i]!=el2){
          el1 =v[i];
          cnt1++;
        }
        else if(cnt2==0 && v[i]!=el1){
            el2 = v[i];
            cnt2++;
        }
        else if(v[i]==el1)cnt1++;
        else if(v[i]==el2)cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }
    vector<int> ls;
// just do a manual check at the last
    cnt1 = 0 ; cnt2 = 0;

    for(int i= 0 ; i<n;i++ ){
        if(v[i]==el1)cnt1++;
        if(v[i]==el2)cnt2++;
    }
    int mini = int(n/3)+1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);
return ls;
}


Time Complexity: O(N) + O(N), where N = size of the given array.
Space Complexity: O(1) as we are only using a list that stores a maximum of 2 elements. The space used is so small that it can be considered constant.

