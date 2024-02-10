#include<bits/stdc++.h>
vector < int > sortedArray(vector < int > a, vector < int > b) {
    set<int>st;
    for(int i=0;i<a.size();i++){
        st.insert(a[i]);
    }
    for(int i=0;i<b.size();i++){

        st.insert(b[i]);
    }
    vector<int>temp;
    for(auto it:st){
        temp.push_back(it);
    }
    return temp;
}

T.C.=O(N1 logn) + O(N2 logn) + O(N1+N2)
S.C.=O(N1+N2) + O(N1+N2)



  #include<bits/stdc++.h>
vector<int>sortedArray(vector<int>a,vector<int>b){
    vector<int>unionArr;
    int i=0;
    int j=0;
    int n1=a.size();
    int n2=b.size();
    while(i<n1 && j<n2){
      if(a[i] <= b[j]){
        if (unionArr.size() == 0 || unionArr.back() != a[i]) {
          unionArr.push_back(a[i]);
        }
        i++;
      }
      else{
        if (unionArr.size() == 0 || unionArr.back() != b[j]) {
          unionArr.push_back(b[j]);
        }
        j++;
      }
    }
    // if 1st array get exausted
    while(j<n2){
        if (unionArr.size() == 0 || unionArr.back() != b[j]) {
          unionArr.push_back(b[j]);
        }
        j++;
      }
        // if 2nd array get exausted
    while(i<n1){
        if (unionArr.size() == 0 || unionArr.back() != a[i]) {
          unionArr.push_back(a[i]);
        }
        i++;
      }
    return unionArr;
}


T.C.=O(N1+N2)
S.C.=O(N1+N2)
