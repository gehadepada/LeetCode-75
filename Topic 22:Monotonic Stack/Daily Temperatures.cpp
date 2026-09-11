class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        map<int, priority_queue<int, vector<int>, greater<int>>> m;
        vector<int> res;
        for (int i = 0; i < n; i++) {

            m[temperatures[i]].push(i);
        }
        for (int i = 0; i < n; i++) {
            int mini = 1e8;
            for (int j = temperatures[i] + 1; j <= 100; j++) {
                if (m[j].size() > 0) {
                    while (m[j].size() > 0) {
                        if (m[j].top() > i) {
                            mini = min(mini, m[j].top());
                            break;

                        } else {
                            m[j].pop();
                        }
                    }
                }
            }
            if (mini == 1e8) {
                res.push_back(0);

            } else {
                res.push_back(mini - i);
            }
        }
        return res;
    }
};