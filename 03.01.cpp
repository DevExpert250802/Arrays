// https://bit.ly/3DXfsDZ 


//  Add arrays


#include <bits/stdc++.h> 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int i=n-1,j=m-1;
	int carry = 0;
	vector<int>ans;
	while(i>=0 && j>=0){
		int val1 =a[i];
		int val2 =b[j];

		int sum=val1+val2+carry;

		carry = sum/10;
		sum=sum%10;
		ans.push_back(sum);
		i--;j--;
	}
	// 1st case
	while(i>=0){
		int sum = a[i]+ carry;
		carry = sum/10;
		sum=sum%10;
		ans.push_back(sum);
		i--;
	}
	// 2nd case
	while(j>=0){
		int sum = b[j]+ carry;
		carry = sum/10;
		sum=sum%10;
		ans.push_back(sum);
		j--;
	}
	// 3rd case
	while(carry!=0){
		int sum =carry;
		carry = sum/10;
		sum=sum%10;
		ans.push_back(sum);
	}
	reverse(ans.begin(),ans.end());
	return ans;
}


T.C. = O(max(n,m))
S.C. = O(max(n,m))
