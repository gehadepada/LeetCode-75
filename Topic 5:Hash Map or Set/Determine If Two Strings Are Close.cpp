class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char ,int>m , mm,cont , cont2;
        for(auto x : word1)
        {
            m[x]++;

        }
        for(auto x : word2)
        {
            if(m.count(x) == 0 )
            {
                return false;
            }
            mm[x]++;
        }
        for(auto x : m)
        {
            cont[x.second]++;
        }
        for(auto x : mm)
        {
            if(cont.count(x.second) == 0)
            {
                return false;
            }
            cont2[x.second]++;
        }
        for(auto x:cont)
        {
            if(x.second != cont2[x.first])
            {
                return false;
            }
        }
        return true;
        
    }
};