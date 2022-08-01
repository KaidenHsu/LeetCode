// 8/1/22
class Solution {
public:
    double mediann(vector<int>& a, vector<int>& b){
        int m = a.size(), n = b.size(), l = 0, r = m;
        if(m > n) return mediann(b, a);

        while(l <= r){
            int partx = l + (r - l) / 2;
            int party = (m + n + 1) / 2 - partx;
            int maxlx = (partx == 0)? INT_MIN : a[partx - 1];
            int minrx = (partx == m)? INT_MAX : a[partx];
            int maxly = (party == 0)? INT_MIN : b[party - 1];
            int minry = (party == n)? INT_MAX : b[party];

            if (maxlx <= minry && maxly <= minrx){
                // even elements cases
                if ((m + n) % 2 == 0) return (double)(max(maxlx, maxly) + min(minrx, minry)) / 2;
                // odd elements cases
                else return (double)(max(maxlx, maxly));
            } else if (maxlx > minry) r = partx - 1;
            else l = partx + 1;
        }

        return -1.0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans = mediann(nums1, nums2);
        return ans;   
    }
};