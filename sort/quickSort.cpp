class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return 0;
    }
    void quickSort(vector<int>&nums,int left,int right){
        if(left<right){
            int pivot=partition(nums,left,right);
            quickSort(nums, left, pivot-1);
            quickSort(nums, pivot+1, right);
        }
    }
    int partition(vector<int>& nums,int start,int end){
        int left=start+1,right=end;
        int tmp;
        while(left<right){
            while(left<=right&&nums[left]<=nums[start])
                left++;
            while(left<=right&&nums[right]>=nums[start])
                right--;
            if(left<right){
                tmp=nums[left];
                nums[left]=nums[right];
                nums[right]=tmp;
            }
        }
        while(right>start&&nums[right]>=nums[start])
            right--;
        if(right>start){
            tmp=nums[right];
            nums[right]=nums[start];
            nums[start]=tmp;
            return right;
        }else
            return start;
        
    }
};
