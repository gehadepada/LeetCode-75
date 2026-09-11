class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        stack<int>s2;
        string chars="";
        int num =0 ; 
        for(auto x : s)
        {
            if( isdigit(x))
            {
                num = num*10 + x-'0';
            }
            else{
                if(x == '[')
                {
                    s2.push(num);
                    st.push(chars);
                    chars="";
                    num= 0 ;
                    
                }
                else if(x== ']'){
                    string u = chars;
                    int r= s2.top();
                    chars = st.top();
                    s2.pop();
                    st.pop();
                    while(r--)
                    {
                        chars+=u ;
                    }
                }
                else{
                    chars+=x;
                    
                }
            }

        }
        
       return chars;
        
    }
};