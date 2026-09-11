class Solution {
public:
 vector<vector<int>>r;
     
     void tryy(int k , int n , int sum , int take ,vector<int>&res)
     {
        if(sum == n && ((int)res.size() == k) )
        {
            r.push_back(res);
            return ;
        }
         
        for(int i = take +1 ; i <= 9 ; i ++)
        { 
            if(sum  + i <= n  && ((int)res.size() < k ))
            {
                res.push_back(i);
                tryy( k , n , sum + i ,  i,res);
                if((int)res.size() > 0){
                res.pop_back();
               
                }
            }
           

        }
     }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>res;
        tryy( k , n , 0 , 0 , res);
        return r;
        
    }
};