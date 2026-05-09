class Solution {
public:
    string reverseWords(string s) {
       vector< string> st;
        string t ="";
        int flag=0;
        for(int i =0 ; i < s.size() ;i++)
        {
            if(s[i]!=' ')
            {
                t.push_back(s[i]);
                flag=1;

            }
            else{
                if(t!=""){
                st.push_back(t);
                t="";
                }
            }
        }
        if(t!=""){
        st.push_back(t);
        }
        string res="";
        for(int i = st.size()-1 ;i >=0 ;i--)
        {
            res+=st[i];
            if((i== 0))
            {
                continue;
            }
            else{
                res+=" ";
            }
        }
       
        return res;
        
    }
};