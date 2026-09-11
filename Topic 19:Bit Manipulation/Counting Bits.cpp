class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ress;
        for(int i = 0 ;i <=n ;i ++)
        {
            ress.push_back(__builtin_popcount(i));
        }
        return ress;
        
    }
};