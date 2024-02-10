int slargest(vector<int> a,int n){
  int largest  = a[0];
  int slargest = INT_MIN;
  for(int i=1;i<n;i++){
    if(a[i]>largest){
        slargest=largest;
        largest=a[i];
    }
    else if(a[i]<largest && a[i]>slargest){
        slargest=a[i];
    }
   }
   return slargest;
}

int smallest(vector<int> a,int n){
  int smallest  = a[0];
  int ssmallest = INT_MAX;
  for(int i=1;i<n;i++){
    if(a[i]<smallest){
        ssmallest=smallest;
        smallest=a[i];
    }
    else if(a[i]>smallest && a[i]<ssmallest){
        ssmallest=a[i];
    }
   }
   return ssmallest;
}


vector<int> getSecondOrderElements(int n, vector<int> a) {
    int secondlargest= slargest(a,n);
    int secondsmallest= smallest(a,n);
    return {secondlargest, secondsmallest};
}


T.C.=O(2N)
S.C.=O(1)
