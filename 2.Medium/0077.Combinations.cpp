// 7/19/22
class Solution {
public:
    void backtrack(int n, int k, vector<vector<int>>& res, vector<int>&r){
        if (r.size() == k){
            res.push_back(r); 
            return; 
        }
        
        if (n - 1 < 0) return; 
        
        r.push_back(n);
        backtrack(n - 1, k, res, r); 
        r.pop_back(); 
        backtrack(n - 1, k, res, r); 
    }
    
    vector<vector<int>> combine(int n, int k){
        vector<vector<int>> res; 
        vector<int> r; 
        backtrack(n, k, res, r); 
        return res;
    }
};