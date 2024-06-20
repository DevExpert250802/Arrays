 // Sort Vowels in a String( 2785 )
/*
      Company Tags                : Microsoft
      Leetcode Link               : https://leetcode.com/problems/sort-vowels-in-a-string
*/

/*********************************************************** C++ **********************************************************************/
//Approach-1 (Separate string create and sort)

// T.C. = O(nlogn + 2n)



class Solution {
public:
    string sortVowels(string s) {
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i] =='i'||s[i] == 'o'|| s[i] == 'u'||s[i] == 'A'||s[i] =='E'||s[i]== 'I'||s[i] == 'O'||s[i] == 'U'){
                temp+=s[i];
            }
        }
        sort(temp.begin(),temp.end());
        int index=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i] =='i'||s[i] == 'o'|| s[i] == 'u'||s[i] == 'A'||s[i] =='E'||s[i]== 'I'||s[i] == 'O'||s[i] == 'U'){
                s[i]=temp[index];
                index++;
            }
        }
        return s;
    }
};







//Approach-2 (Without sorting. Counting the vowels - counting sort)
//T.C : O(n)



class Solution {
public:
bool isvowel( char c){
return(c=='a'||c=='e'||c=='i'||c == 'o'||c=='u'||c=='A'||c=='E'||c== 'I'||c == 'O'||c== 'U');
}

string sortVowels(string s) {
    unordered_map<char,int>mp;
        for(auto &c :s){
            if(isvowel(c)) mp[c]++;
        }

        string temp="AEIOUaeiou";

        int j=0;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
               while(mp[temp[j]] == 0 ){
                  j++;
                }
                s[i]= temp[j];
                mp[temp[j]]--;
            }
        }  
    return s;
    }
};
