#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m){
   vector<int>intersect;
	int i=0;
	int j=0;
	while(i<n && j<m){
		if(arr1[i]==arr2[j]){
			intersect.push_back(arr1[i]);
			i++;
			j++;
		}
		else if(arr1[i]<arr2[j]){
			i++;
		}
		else{
			j++;
		}
	}
	return intersect;
}



T.C.=O(N1+N2)
S.C.=O(N1+N2)
