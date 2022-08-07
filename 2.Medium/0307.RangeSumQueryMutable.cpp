// 8/7/22
class NumArray {
    inline static int n;
    int* segTree;
public:
    NumArray(vector<int>& nums) {
        n = size(nums);
        segTree = (int*)malloc(4 * n * sizeof(int));
        build(nums, 1, 0, n - 1);
    }
    
    void build(vector<int>& nums, int segIdx, int l, int r) {
        if(l == r) segTree[segIdx] = nums[l]; // can't split further - assign corresponding index of segTree as nums[l]
        else {
            int mid = (l + r) / 2; // divide array into two halves (left and right child of current node of segment tree)
            build(nums, 2 * segIdx, l, mid); // calculate result for left child
            build(nums, 2 * segIdx + 1, mid + 1, r); // calculate result for right child
            segTree[segIdx] = segTree[2*segIdx] + segTree[2*segIdx + 1]; // merge result into parent - parent val = sum of left & right child
        }
    }
    
    void update(int index, int val, int segIdx = 1, int l = 0, int r = n - 1) {
        if(l == r) segTree[segIdx] = val; // update segment tree index corresponding to the array index to be updated
        else {
            int mid = (l + r) / 2;
            if (index <= mid) update(index, val, 2*segIdx, l, mid); // if node holding [nums[index]] segment lies in left child, recurse for it
            else update(index, val, 2*segIdx + 1, mid + 1, r); // otherwise recurse the right child
            
            segTree[segIdx] = segTree[2*segIdx] + segTree[2*segIdx + 1]; // child nodes got updated - so parent need to be updated again as sum of left + right child nodes
        }
    }
    
    int sumRange(int left, int right, int segIdx = 1, int l = 0, int r = n - 1) {
        if(left > right) return 0;   
        if(l == left && r == right) return segTree[segIdx]; // case - 1
        int mid = (l + r) / 2;
		// case - 2 and 3
		// Here, we are picking min(right, mid) & max(left, mid+1) to ensure that [left, right] is always subrange of [l, r] for recursive call 
		// otherwise base condition would never be reached in some cases
        return sumRange(left, min(right, mid), 2*segIdx, l, mid) + sumRange(max(left, mid + 1), right, 2*segIdx + 1, mid + 1, r);
    }
};