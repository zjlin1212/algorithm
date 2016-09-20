class Solution {
public:
    void quicksort(vector<int>& v){
        quicksort(v,0,v.size()-1);
    }
    void quicksort(vector<int>&v,int start,int end){
        if(end<=start)
            return;
        int pivot=v[start];
        int left=start+1,right=end;
        while(left<right){
            while(left<end&&v[left]<=pivot)
                left++;
            while(right>start&&v[right]>=pivot) //只要有一个>=即可
                right--;
            if(left<right){
                int tmp=v[left];
                v[left]=v[right];
                v[right]=tmp;
            }
        }
        while(right>start&&v[right]>=pivot)
            right--;
        swap(v[start],v[right]);
            
        quicksort(v,start,right-1);
        quicksort(v,right+1,end);
    }
};
