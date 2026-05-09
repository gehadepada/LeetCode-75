class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 1, mx = 0;
        int n = nums.size();
        int count = 0;
        int kk = k;
        if (nums[0] == 1) {
            count++;
        }
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] && nums[i] == 1) {
                count++;
            } else {
                mx = max(mx, count);
                count = 0;
                if (nums[i] == 1) {
                    count = 1;
                }
            }
        }
        mx = max(mx, count);
        if (kk == 0) {
            return mx;
        }
        count=0;
        if (nums[l] == 0 && k > 0) {
            k--;
            count++;

        } else if (nums[l] == 1) {
            count++;
        }
          mx = max(count, mx);
        while (l <= r && r < n) {
            mx = max(count, mx);
            if (nums[r] == 0) {
                if (k > 0) {
                    k--;
                    count++;
                    r++;
                } else {
                    while (nums[l] == 1 && l < n) {
                        l++;
                        count--;
                    }
                    if (l < r && nums[l] == 0 && l < n) {
                        count--;
                        l++;
                        k++;
                    }
                }
            } else {
                count++;
                r++;
            }
            mx = max(count, mx);
        }
        return mx;
    }
};