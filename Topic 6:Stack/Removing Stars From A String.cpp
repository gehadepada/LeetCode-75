class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(auto x : s)
        {
            if(x == '*' && !st.empty())
            {
                st.pop();

            }
            else{
                st.push(x);
            }
        }
        s="";
      while(!st.empty())
        {
            s.push_back(st.top());
            st.pop();

        }
        reverse(s.begin() , s.end());
        return s;
    }
};