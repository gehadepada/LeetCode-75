class Solution {
public:
    string reverseVowels(string s) {
        string t="";
        for(auto cc : s)
        {
           char c=tolower(cc);
            if(c =='a' || c=='i' || c=='e' || c =='u' || c == 'o')
            {
                t.push_back(cc);
            }
        }
        reverse(t.begin() , t.end());
        int i = 0 ;
        for(auto&x : s)
        {
             char c=tolower(x);
            if(c =='a' || c=='i' || c=='e' || c =='u' || c == 'o')
            {
                x=t[i];
                i++;
            }

        }
        return s;
        
        
    }
};