class Solution {
public:
    int minFlips(int a, int b, int c) {
        bitset<32>bta(a);
        bitset<32>btb(b);
        bitset<32>btc(c);
    
        int res = 0 ;
        for(int i= 0 ; i < 32 ; i ++ )
        {
            if(btc[i] == 1 && (bta[i] == 0 && btb[i] == 0))
            {
                res++;
            }
            else if(btc[i] == 0  && (bta[i] == 1 || btb[i] == 1))
            {
                if((bta[i] == 1 && btb[i] == 1)){
            
                res+=2;
                }
                else{
                    res++;
                }
            }
        }
        return res;
        
    }
};