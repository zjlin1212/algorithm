    void helper(vector<int>&nums,int begin,int end){
        if(begin>=end)
            return ;
        if(begin==end-1){
            if(nums[end]<nums[begin])
                swap(nums[begin],nums[end]);
            return ;
        }
        int mid=(begin+end)/2;
        helper(nums,begin,mid-1);
        helper(nums,mid,end);
        vector<int> tmp(end-begin+1,0);
        int i=0;
        int i1=begin,i2=mid;
        while(i1<=mid-1||i2<=end){
            if(i2>end||(i1<=mid-1&&nums[i1]<nums[i2]))
                tmp[i++]=nums[i1++];
            else
                tmp[i++]=nums[i2++];
        }
        for(int i=0;i<tmp.size();i++)
            nums[begin+i]=tmp[i];
        
    }
    void mergeSort(vector<int>&nums ){
        helper(nums,0,nums.size()-1);
    }
