class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> a, b;
        vector<vector<int>> res;
        vector<int> aa;
        for (auto x : nums1) {
            a[x]++;
        }
        for (auto x : nums2) {
            b[x]++;
        }
        for (auto x : a) {
            if (b.count(x.first) == 0) {
                aa.push_back(x.first);
            }
        }
        res.push_back(aa);
        aa.clear();
        for (auto x : b) {
            if (a.count(x.first) == 0) {
                aa.push_back(x.first);
            }
        }
        res.push_back(aa);
        return res;
    }
};