class Solution {
public:
    int binry(vector<int>& spells, vector<int>& potions, long long success , long long num)
    {
        int l = 0 , r = potions.size()-1;
        int res = -1;
        while(l <= r)
        {
            int m = (l+r)/2;
            if(potions[m] * num >=success)
            {
                res = m ; 
                r=m-1;
            }
            else {
                l=m+1;
            }

        }
        if(res == -1)
        {
            return (int)potions.size();
        }
        else{
        
            return res;
        }
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin() , potions.end());
        int n = potions.size();
        vector<int>res;
        for(int i = 0 ; i < spells.size() ; i ++)
        {
            res.push_back(n - binry(spells , potions , success , spells[i] ));
        }
        return res;
        
    }
};