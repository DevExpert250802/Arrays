void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &arr1, vector<long long> &arr2){
	int n=arr1.size();
	int m=arr2.size();
	vector<long long> arr3(n + m);
	int left=0,right=0,index=0;
	while(left<n && right<m){
		if(arr1[left]<=arr2[right]){
			arr3[index]=arr1[left];
			left++,index++;
		}
		else{
			arr3[index]=arr2[right];
			right++,index++;
		}
	}
    while(left<n){
		arr3[index]=arr1[left];
		left++,index++;
	}
	while(right<m){
		arr3[index]=arr2[right];
		right++,index++;
	}
	for(int i=0;i<n+m;i++){
		if(i<n)arr1[i]=arr3[i];
		else arr2[i-n]=arr3[i];
	}
}



Time Complexity:   O(n+m)+O(n+m)

Space Complexity:  O(n+m)



void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &arr1, vector<long long> &arr2){
	int n=arr1.size();
	int m=arr2.size();
	int left=n-1,right=0;
	while(left>=0 && right<m){
		if(arr1[left] > arr2[right]){
          swap(arr1[left] , arr2[right]);
		  left--,right++;
		}
		else{
			break;
		}
	}
	sort(arr1.begin(),arr1.end());
	sort(arr2.begin(),arr2.end());
}


Time Complexity:   O(min(n, m)) + O(n*logn) + O(m*logm)

Space Complexity:  O(1)
