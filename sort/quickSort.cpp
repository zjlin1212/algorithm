class Solution {
public:
    void quicksort(vector<int>& v){
        quicksort(v,0,v.size()-1);
    }
    void quicksort(vector<int>& nums, int low, int high) {
        if(low >= high)
            return ;
        int left = low, right = high;
        int pivot = low;
        low++;
        /*
        //both are right
        while(low < high) {
            while(low <= high && nums[low] < nums[pivot])
                low++;
            while(low <= high && nums[high] > nums[pivot])
                high--;
            if(low < high)
                swap(nums[low++], nums[high--]);
        }
        */
        while(low < high) {
            while(low <= high && nums[low] <= nums[pivot])
                low++;
            while(low <= high && nums[high] >= nums[pivot])
                high--;
            if(low < high)
                swap(nums[low], nums[high]);
        }
        
        while(high > pivot && nums[high] >= nums[pivot])
            high--;
        if(high > pivot)
            swap(nums[high], nums[pivot]);
        quicksort(nums, left, high - 1);
        quicksort(nums, high + 1, right);
        
    }
};
