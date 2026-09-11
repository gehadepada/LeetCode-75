class StockSpanner {
public:
    priority_queue<pair<int ,int> , vector<pair<int , int>> , greater<pair<int , int>>>q;
    StockSpanner() {
        q =   priority_queue<pair<int ,int> , vector<pair<int , int>> , greater<pair<int , int>>>();
        
    }
    
    int next(int price) {
         int count = 1;
        if(q.empty())
        {
            q.push({price , 1});
            return 1;
        }
        else{
           
            if(q.top().first<= price)
            {
                while(!q.empty() && q.top().first <= price){
                count+=q.top().second;
                 q.pop();
                }

            }
            q.push({price , count});
            
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */