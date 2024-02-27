    int majorityElement(vector<int>v) {
	int n=v.size();
	for(int i=0;i<n;i++){
	    int cnt=0;
	    for(int j=0;j<n;j++){
		if(v[i]==v[j]) cnt++;
	     }
	if(cnt>n/2) return v[i];
	}
       return -1;
    }


T.C.=O(N*N)
S.C.=O(1)


int majorityElement(vector<int>v) {
    int n=v.size();
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[v[i]]++;
    }
    for (auto it : mp) {
        if (it.second > n/2)return it.first;
    }
	return -1; 
}

T.C.=O(N* logN) + O(N)
S.C.=O(N)



/////////////////////////////////////////////////////  Boyer Moore’s Voting Algorithm  ////////////////////////////////////////////


int majorityElement(vector<int> v) {
    int cnt=0;
    int el;
    int n=v.size();
    for(int i=0;i<n;i++){
        if(cnt==0){  
           cnt=1;
           el=v[i];
        } 
	else if(v[i] == el) cnt++;
        else cnt--;
    }
// if array may or maynot have majority element
    int cnt1=0; 
    for(int i=0;i<n;i++){
        if(v[i]==el)cnt1++;
        if(cnt1 > n/2)return el;
    }
    return -1;
}


T.C.=O(N) + O(N)
S.C.=O(1)
