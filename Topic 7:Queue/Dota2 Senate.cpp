class Solution {
public:
    string predictPartyVictory(string senate) {
        deque<int>r,d;
        for(int i =0; i < senate.size() ; i++)
        {
            if(senate[i] == 'R')
            {
                r.push_back(i);
            }
            else{
                d.push_back(i);
            }
        }
        while(!d.empty() && !r.empty())
        {
            if(d.front() < r.front())
            {
                r.pop_front();
                d.push_back(d.front() + senate.size());
               
                 d.pop_front();

            }
            else{
                d.pop_front();
                r.push_back(r.front() + senate.size());
                 r.pop_front();
            }
        }
        if(r.empty())
        {
            return "Dire";
        }
       
            return "Radiant";
        
       
    }
};