class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        st.push(asteroids[0]);
        for (int i = 1; i < asteroids.size(); i++) {
            if (!st.empty() && ((st.top() > 0 && asteroids[i] < 0))) {

                while (!st.empty() && abs(asteroids[i]) > abs(st.top()) &&
                       (st.top() > 0 && asteroids[i] < 0)) {
                    st.pop();
                }
                if (!st.empty() && (abs(asteroids[i]) == abs(st.top())) &&
                    (st.top() > 0 && asteroids[i] < 0)) {
                  
                        st.pop();
                    
                 
                } else {
                      if(st.empty()||(st.top()<0 &&asteroids[i]<0)||(st.top()>0 &&asteroids[i]>0)){
                       st.push(asteroids[i]);
                      }
                }

            } else {
                st.push(asteroids[i]);
            }
        }
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};