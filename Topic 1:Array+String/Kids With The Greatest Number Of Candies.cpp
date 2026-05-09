class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(candies.begin() , candies.end());
        vector<bool>res;
        for(auto x : candies)
        {
            if(extraCandies + x >= mx)
            {
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
        }
        return res;
        
    }
};