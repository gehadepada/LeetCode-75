class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> m;
        for (auto x : nums) {
            m[x]++;
        }
        int c = 0;
        for (auto x : nums) {
            if (m[k - x] != 0 && m[x] != 0) {
                if (k - x == x) {
                    if (m[x] > 1) {
                        c++;
                        m[k - x]--;
                        m[x]--;
                    }

                } else {
                    c++;
                    m[k - x]--;
                    m[x]--;
                }
            }
        }
        return c;
    }
};