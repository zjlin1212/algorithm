class maxHeap{
// http://www.cs.umd.edu/~meesh/351/mount/lectures/lect13-heapsort.pdf
public:
    vector<int> nums;
    
    void bubbleDown(int index){
        int l=index*2+1,r=index*2+2;
        int max_i=index;
        if(l<nums.size()&&nums[l]>nums[max_i])
            max_i=l;
        if(r<nums.size()&&nums[r]>nums[max_i])
            max_i=r;
        if(max_i!=index){
            swap(nums[max_i],nums[index]);
            bubbleDown(max_i );
        }
    }
    void bubbleUp(int index){
        if(index==0)
            return ;
        int parent=(index-1)/2;
        
        if(nums[parent]<nums[index]){
            swap(nums[parent],nums[index]);
            bubbleUp(parent);
        }
        
    }
    
    void makeHeap(vector<int>& nums){
        vector<bool> visited(false,nums.size());
        for(int i=nums.size()/2;i>=0;i--){
            bubbleDown(i);
        }
    }
    int pop(){
        int ret=nums[0];
        swap(nums[0],nums.back());
        nums.pop_back();
        bubbleDown(0);
        return ret;
    }
    
    void push(int num){
        nums.push_back(num);
        bubbleUp(nums.size()-1);
    }
    
    maxHeap(vector<int> v){
        this->nums=v;
        makeHeap(nums);
    }
    
};
