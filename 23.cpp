Problem statement
There is an integer array ‘A’ of size ‘N’ . A sequence is successive when the adjacent elements of the sequence have a difference of 1.
You must return the length of the longest successive sequence.

Note:You can reorder the array to form a sequence.
  
For example,
Input : A = [5, 8, 3, 2, 1, 4], N = 6
Output:5
  
Explanation: 
The resultant sequence can be 1, 2, 3, 4, 5.    
The length of the sequence is 5.





bool ls(vector<int>&a,int key){
    for(int i=0;i<a.size();i++){
        if(a[i]==key) return true;
    }
    return false;
}

int longestSuccessiveElements(vector<int>&arr){
    int curr_count=0;
    int max_count=1;

    for(int i=0;i<arr.size();i++){
        int x=arr[i];
        curr_count=1;
        while (ls(arr,x+1) == true) {
          x=x+1;
          curr_count+=1;
        }
        max_count=max(max_count,curr_count);
    }
    return max_count;
}


T.C.=O(N*N)
S.C.=O(1)


int longestSuccessiveElements(vector<int>&arr){
    int curr_count=0;
    int max_count=1;
    int prev_smaller=INT_MIN;
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<arr.size();i++){

        if(arr[i]-1 == prev_smaller){
           curr_count+=1; 
           prev_smaller=arr[i];
        }
        else if(arr[i] != prev_smaller){
            curr_count=1;
            prev_smaller=arr[i];
        }
        max_count=max(max_count,curr_count);
    }
    return max_count;
}

T.C.=O(N*logN)
S.C.=O(1)


  
int longestSuccessiveElements(vector<int>&arr){
    int curr_count=0;
    int max_count=1;
    unordered_set<int>st;

    for (int i = 0; i<arr.size(); i++) {
        st.insert(arr[i]);
    }
    for(auto it:st){
        if(st.find(it-1) == st.end()){
            curr_count=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                x=x+1;
                curr_count+=1;
            }
            max_count=max(max_count,curr_count);
        }
    }
    return max_count;
}

T.C.=O(3N)
S.C.=O(N)
