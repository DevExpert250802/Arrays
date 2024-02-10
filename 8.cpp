vector<int> moveZeros(int n, vector<int> a) {
    vector<int>temp;
    for(int i=0;i<n;i++){
        if(a[i]!=0)
        temp.push_back(a[i]);
    }
    int nonzero = temp.size();
    for(int i=0;i<temp.size();i++){
        a[i]=temp[i];
    }
    for(int i=nonzero;i<n;i++){
        a[i]=0;
    }
    return a;
}

T.C.=O(2N)
S.C.=O(N)


vector<int> moveZeros(int n, vector<int> a) {
    int j=-1;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            j=i;
            break;
        } 
    }
    if(j==-1) return a;
    for(int i=j+1;i<n;i++){
            if(a[i]!=0){
            swap(a[j],a[i]);
            j++;
        } 
    }  
    return a;
}
T.C.=O(N)
S.C.=O(1)  
