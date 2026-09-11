class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        long long pref[n];
        pref[0] = piles[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + piles[i];
        }
        long long l = 1, r = 1e9, sum = 0, m, count = 0, res, k = 0;
        int y;

        while (l <= r) {
            m = (l + r) / 2;
            y = lower_bound(piles.begin(), piles.end(), m) - piles.begin();
            cout << m << " " << y << endl;
            k = 0;
            int j;
            if (y >= 0 && y < n) {
                count = y;
                y+1;
            }
            else{
                y=0;
                count =0;
            }
                for (j= y ; j < n; j++) {
                    k += (piles[j] + m - 1) / m;
                }
            if (count + k <= h) {
                res = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return res;
    }
};