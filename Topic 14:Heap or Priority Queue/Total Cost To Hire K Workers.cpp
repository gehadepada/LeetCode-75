class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> left, right;
        int n = costs.size();
        map<int, int> m;
        int i, j;
        for (i = 0; i < candidates; i++) {
            left.push(costs[i]);
            m[i]++;
        }
        long long res = 0;
        i--;
        for (j = n - 1; j >= n - candidates; j--) {
            if (m[j] == 0) {
                right.push(costs[j]);

                m[j]++;

            } else {
                break;
            }
        }

        j++;
        
      

        while (k--) {
            if ((left.size() != 0) && (right.size() != 0) ){

                if (left.top() <= right.top()) {
                   cout<<left.top()<<endl;
                    res += left.top();

                    left.pop();
                    if (i + 1 < n && (m.count(i+1) == 0)) {
                        left.push(costs[++i]);
                        m[i ]++;
                    }
                } else {
                    res += right.top();
                     cout<<right.top()<<endl;
                    right.pop();
                 
                    if (j - 1 >= 0 && (m.count(j-1) == 0)) {
                        

                        right.push(costs[--j]);
                        m[j]++;
                    }
                }
            } else {

                if (left.empty()) {
                  
                    res += right.top();
                    
                    right.pop();
                    if (j - 1 >= 0 && (m.count(j-1) == 0)) {

                        right.push(costs[--j]);
                        m[j ]++;
                    }
                } else {

                    res += left.top();
               
                    left.pop();
                    if (i + 1 < n && (m.count(i+1)== 0)) {
                        left.push(costs[++i]);
                        m[i ]++;
                    }
                }
            }
        }

        return res;
    }
};