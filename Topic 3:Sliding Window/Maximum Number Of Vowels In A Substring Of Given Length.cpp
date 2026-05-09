class Solution {
public:
    int maxVowels(string s, int k) {
        int v = 0;
        int mx = 0;
        int l = 0;
        if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'u' ||
            s[l] == 'o') {
            v++;
        }
        for (int r = 1; r < s.size(); r++) {
            if ((r - l)  == k) {
                mx = max(v, mx);
                if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'u' ||
                    s[l] == 'o') {
                    v--;
                    l++;
                } else {
                    l++;
                }
            }
            if (s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'u' ||
                s[r] == 'o') {
                v++;
            }

        }
        return mx = max( mx , v);
    }
};