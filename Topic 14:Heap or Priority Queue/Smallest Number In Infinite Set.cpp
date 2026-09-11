class SmallestInfiniteSet {
public:
      set<int>st;
       int cur = 1;
    SmallestInfiniteSet() {
        cur=1;
          st.clear();
    }

    int popSmallest() {
        if(!st.empty()){
        auto ans = *st.begin();
        st.erase(st.begin());
        return ans;
        }
        return cur++;
    }

    void addBack(int num) { 
        if(num<cur)
          st.insert(num);
         }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */