class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int ,int>m , c;
        for(auto x : arr)
        {
            m[x]++;

        }
        for(auto x : m )
        {
            if(c.count(x.second)!=0)
            {
                return false;
            }
            c[x.second]++;
        }
        return true;
        
    }
};