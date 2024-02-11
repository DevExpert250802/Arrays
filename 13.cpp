 Approach 1 : check each element

int missingNumber(vector<int>&a, int N) {
   for(int i=1;i<=N;i++){
       bool flag=0;
       for(int j=0;j<N-1;j++){
         if (a[j] == i) {
           flag = 1;
           break;
         }
       }
       if(flag==0) return i;
   }
}

T.C. = O(N^2)
S.C. = O(1)


  
  Approach 2 : using hashing



 int missingNumber(vector<int>&a, int N) {
    vector<int>hash(N+1,0);
    for(int i=0; i<N-1; i++){
        hash[a[i]]++;
    }
    for(int i=1; i<=N; i++){
        if(hash[i]==0) return i;
    }
} 

T.C. = O(2N)
S.C. = O(1)



Approach 3 : Sum of ‘N’ Natural Numbers
  
int missingNumber(vector<int>&a, int N) {
    int totalsum=N*(N+1)/2;
    int sum = 0;
    for(int i=0; i<N-1; i++){
        sum += a[i];
    }
    return totalsum - sum;
}




Integer Overflow Handling:


int missingNumber(vector<int>&a, int N) {
    long long totalsum = ((long long)N* (long long)(N+1))/2LL;
    long long sum = 0;
    for(int i=0; i<N-1; i++){
        sum += a[i];
    }
    return totalsum - sum;
}


T.C. = O(N)
S.C. = O(1)


  
Approach 4 : XOR

int missingNumber(vector<int>&a, int N) {
    int XOR1 = 0;
    for (int i = 1; i <= N; i++) {
        XOR1 ^= i;
    }
    // Find the XOR of the array.
    int XOR2 = 0;
    for (int i = 0; i < N - 1; i++) {
        XOR2 ^= a[i];
    }
    // Return the XOR of 'XOR1' and 'arrayXor'.
    return XOR1 ^ XOR2;
}


int missingNumber(vector<int>&a, int N) {
// Find the XOR of the array and of first 'N' natural number.
    int XOR1 = 0,XOR2 = 0;
    for (int i = 0; i <N-1; i++) {
        XOR2 ^= a[i];
        XOR1 ^= i+1;
    }
     XOR1=XOR1^N;
// Return the XOR of 'XOR1' and 'arrayXor'.
    return XOR1^XOR2;
}


T.C. = O(N)
S.C. = O(1)
