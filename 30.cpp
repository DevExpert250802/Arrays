vector<int> rearrangeArray(vector<int>&arr) {
    int n = arr.size();
    vector<int>pos;
    vector<int>neg;
    for(int i=0;i<n;i++){
        if(arr[i]>0)pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
     }
     for(int i=0;i<n/2;i++){
         arr[2*i]=pos[i];
         arr[2*i+1]=neg[i];
      }
     return arr;
 }


T.C.=O(N) + O(N/2)
S.C.=O(1)



    vector<int> rearrangeArray(vector<int>&arr) {
        //The code snippet you provided is used in C++ to improve the input/output performance
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        
        int n = arr.size();
        vector<int>ans(n);
        int posindex=0, negindex=1;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
               ans[posindex]= arr[i];
               posindex += 2;
            }
            else{
                ans[negindex]= arr[i];
                negindex += 2;
            }
        }
        return ans;
    }

T.C.=O(N)
S.C.=O(1)
