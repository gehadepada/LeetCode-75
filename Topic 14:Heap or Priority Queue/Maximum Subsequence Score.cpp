class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int , int>>p;
        for(int i =0 ;i < nums2.size() ; i++)
        {
            p.push({nums2[i] , nums1[i] });
        }
        priority_queue<int , vector<int> , greater<int>>summ;
        long long sum =0;
        long long maxi = 0;
        while(!p.empty())
        {
            summ.push(p.top().second);
            sum+=p.top().second;
            k--;
            if(k < 0 )
            {
                
                sum-=summ.top();
                summ.pop();
                k++;
            }
            if(k == 0 )
            {
                maxi = max(maxi , p.top().first * sum);
            }
            p.pop();
           
        }
        return maxi;
        
    }
};