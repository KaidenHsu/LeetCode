// 6/24/23

class Solution {
private:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> map;

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for (string s: strs) {
            string orig = s;
            sort(s.begin(), s.end());
            map[s].push_back(orig);
        }

        for (pair<string, vector<string>> p: map)
            ans.push_back(p.second);

        return ans;
    }
};
