// 6/29/23

class Solution {
private:
    vector<int> nextelement(vector<int>& heights, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for (int i = n-1; i >= 0; i--) {
            int curr = heights[i];

            while (st.top() != -1 && heights[st.top()] >= curr) {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> prevelement(vector<int>& heights, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int curr = heights[i];

            while (st.top() != -1 && heights[st.top()] >= curr) {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();
       int area = INT_MIN;

       vector<int> next(n);
       vector<int> prev(n);

       next = nextelement(heights, n);
       prev = prevelement(heights, n);

       for (int i = 0; i < n; i++) {
           int l = heights[i];

           if (next[i] == -1) {
               next[i] = n;
           }

           int b = next[i] - prev[i] - 1;
           int newarea = l * b;
           area = max(area, newarea);
        }

        return area;
    }
};
