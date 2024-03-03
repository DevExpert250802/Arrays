vector<int>superiorElements(vector<int>&arr) {
    int n=arr.size();
    vector<int>ans;
    for(int i=0;i<n;i++){
        bool leader=true;
        for(int j=i+1;j<n;j++){
            if (arr[j] >=arr[i]) {
               leader = false;
               break;
            }
        }
        if(leader==true)ans.push_back(arr[i]);
    }
    sort(ans.begin(),ans.end());
    return ans;
}


Time Complexity:   O(N*N)

Space Complexity:  O(1) 


vector<int>superiorElements(vector<int>&arr) {
    int n=arr.size();
    vector<int>ans;
    int maxi=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if (arr[i]>maxi) {
            ans.push_back(arr[i]);
            maxi=max(arr[i],maxi);
        }
        
    }
    sort(ans.begin(),ans.end());
    return ans;
}

Time Complexity:   O(N)

Space Complexity:  O(1) 
