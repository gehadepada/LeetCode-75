class RecentCounter {
public:
    int count ;
    vector<int>q;
    RecentCounter() {
        count = 0 ;
    }
    
    int ping(int t) {
        q.push_back(t);
        int index = lower_bound(q.begin() , q.end() , t-3000)-q.begin();
        if(index >=0 && index<q.size())
        {
            return q.size() - index;
        }
        return 0;
        
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */