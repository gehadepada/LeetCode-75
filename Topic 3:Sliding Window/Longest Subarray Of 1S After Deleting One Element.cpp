class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0 , r = 0 ; 
        int flag =  1;
        int n= nums.size();
        int cnt = 0; 
        int mx = 0 ;
        int x=0;
        while(l<=r && r< n && l < n  )
        {
            if(nums[r] == 0 )
            {
                x=1;
            }
            mx = max(cnt , mx);
            if(nums[r] == 1)
            {
            
                cnt++;
            }
            else{
              
                if(flag == 1)
                {
                    flag =0;
                }
                else{
                
                    if(nums[l] == 0)
                    {
                        flag =1;

                    }
                    else{
                        cnt--;
                    }
                    l++;
                    r--;
                }
            }
            r++;

        }
        mx=max(mx , cnt);
        if(x==0)
        {
            mx--;
        }
        return mx;
        
    }
};