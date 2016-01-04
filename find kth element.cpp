    int findmkth(vector<int> a,int aL,int aR,vector<int> b,int bL,int bR,int k){
        if(aL>aR) return b[bL+k-1];
        if(bL>bR) return a[aL+k-1];
        int aMid=(aL+aR)/2;
        int bMid=(bL+bR)/2;
        if(a[aMid]<=b[bMid]){
            if(k<=(aMid-aL+1)+(bMid-bL))
                return findmkth(a, aL, aR, b, bL, bMid-1, k);
            else
                return findmkth(a,aMid+1,aR, b, bL, bR,k-(aMid-aL+1));
            
        }
        else{
            if(k<=(aMid-aL+1)+(bMid-bL))
                return findmkth(b, bL, bR, a, aL, aMid-1, k);
            else
                return findmkth(b,bMid+1,bR, a, aL, aR,k-(bMid-bL+1));

        }
    }
    */
     int findmkth(vector<int> a,int aL,int aR,vector<int> b,int bL,int bR,int k){
        if(aR-aL>bR-bL)
            return findmkth(b,bL,bR,a,aL,aR,k);
        if(aL>=aR) return b[bL+k-1];
        if(k==1)
            return min(a[aL],b[bL]);
        int i=min(aL+k/2,aR);
        int j=min(bL+k/2,bR);
        if(a[i-1]<b[j-1])
            return findmkth(a, i, aR, b, bL, bR, k-(i-aL));
        else
            return findmkth(a, aL, aR, b, j, bR, k-(j-bL));
        
    }
    
