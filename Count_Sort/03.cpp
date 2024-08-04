// 1051. Height Checker



class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>expected(heights);
        sort(expected.begin(),expected.end());
        int ans=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=expected[i])ans++;
        }
        return ans;
    }
};


T.C = O(NlogN+N)
S.C = O(logN+N)





  class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>count(101,0);
        for(auto it: heights)count[it]++;

        int cnt = 0, id=0;
        for(int i=0;i<heights.size();i++){
            while(count[id]==0) id++;

            if(heights[i]== id){
                count[id]--;
            }
            else{
                cnt++;
                count[id]--;
            }
        }
        return cnt;
    }
};


T.C = O(N+(N+k))
S.C = O(K)
