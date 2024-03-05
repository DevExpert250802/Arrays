
vector<int> findMissingRepeatingNumbers(vector<int>a){
    int n= a.size();
    int missing=-1,repeat=-1;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(a[j]==i)cnt++;
        }
        if(cnt==2)repeat=i;
        if(cnt==0)missing=i;
        if(repeat !=-1 && missing !=-1 ) break;
    }
    return {repeat,missing};
}


Time Complexity:   O(N*N)

Space Complexity:  O(1)



vector<int> findMissingRepeatingNumbers(vector<int>a){
    int n= a.size();
    int missing=-1,repeat=-1;
    int hash[n+1] = {0};
    for (int i=0;i<n;i++){
      hash[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(hash[i]==2)repeat=i;
        else if(hash[i]==0)missing=i;
        if(repeat !=-1 && missing !=-1 ) break;
    }
    return {repeat,missing};
} 



Time Complexity:   O(2N)

Space Complexity:  O(N)


vector<int> findMissingRepeatingNumbers(vector<int>a){
    long long n= a.size();
    long long S =0,S2=0;
    long long Sn = n*(n+1)/2;
    long long Sn2=n*(n+1)*(2*n+1)/6;
    for(int i=0;i<n;i++){
        S+=a[i];
        S2+= (long long)a[i] * (long long)a[i];
    }
    long long val1=Sn-S; // y-x
    long long val2=Sn2-S2; // y^2-x^2
    val2 = val2/val1;// y+x
    long long y=(val1+val2)/2;
    long long x= y-val1;
    return {(int)x,(int)y};
}


Time Complexity:   O(N)

Space Complexity:  O(1)





#include <bits/stdc++.h>
vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); // size of the array

    int xr = 0;

    //Step 1: Find XOR of all elements:
    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

    //Step 2: Find the differentiating bit number:
        int bit_no = 0;
    while (1){
        if ((xr & (1<<bit_no)) != 0)
            break;

        bit_no++;
    }

    //Step 3: Group the numbers:
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
        //part of 1 group:
        if ((a[i] & (1<<bit_no)) != 0) {
            one = one ^ a[i];
        }
        //part of 0 group:
        else {
            zero = zero ^ a[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        //part of 1 group:
        if ((i & (1<<bit_no)) != 0) {
            one = one ^ i;
        }
        //part of 0 group:
        else {
            zero = zero ^ i;
        }
    }

    // Last step: Identify the numbers:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == zero) cnt++;
    }

    if (cnt == 2) return {zero, one};
    return {one, zero};
}



Time Complexity:   O(3N)

Space Complexity:  O(1)
