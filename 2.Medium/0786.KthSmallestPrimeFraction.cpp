// 8/4/22
typedef pair<int, int> pr;

class Solution {
public:
    class Compare {
        public:
        bool operator() (const pr &p1, const pr &p2) {
            // cross multiplication method
            if(p1.first * p2.second < p1.second * p2.first) return 1;
            return 0;
        }
    };
   
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pr, vector<pr>, Compare> pq;

        for(int i = 0; i < arr.size(); ++i)
            for(int j = i + 1; j < arr.size(); ++j){
                pq.push({arr[i], arr[j]});
                if(pq.size() > k) pq.pop();
            }
       
        return vector<int>{pq.top().first, pq.top().second};
    }
};