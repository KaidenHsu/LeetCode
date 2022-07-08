class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	    int n = nums.size();
        unordered_map<int,int> mpp;
		vector<int> v;
		
		for(int i=0;i<n;i++){ 
		      if(mpp.find(target - nums[i]) != mpp.end()){
			      v.push_back(i);
				  v.push_back(mpp[target-nums[i]]);
				  return v;
			  }
		 mpp[nums[i]] = i;
		 }
		 
		 return v;  
    }
};