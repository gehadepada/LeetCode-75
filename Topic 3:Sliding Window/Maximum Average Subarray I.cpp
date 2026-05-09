class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) { 
        double mx = -1e5 , sum = nums[0];
        int l = 0  ,r = 1;
        for( r =1 ; r< nums.size() ;r++)
        {
            if((r- l )< k )
            { 
                sum +=nums[r];
            }
            else{
                mx = max( mx , sum /(r- l ));
                sum -=nums[l];
                l++;
                sum+=nums[r];

            }

        }
          mx = max( mx , sum /(r- l ));
        return mx;
        
    }
};