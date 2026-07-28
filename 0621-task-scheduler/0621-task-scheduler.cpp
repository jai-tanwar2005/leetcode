class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> mp(26, 0);

        for (char ch : tasks)
            mp[ch - 'A']++;

        priority_queue<int> pq;

        for (int x : mp)
            if (x > 0)
                pq.push(x);

        int time = 0;

        while (!pq.empty()) {

            vector<int> temp;
            int cnt = 0;

            for (int i = 0; i <= n; i++) {

                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();

                    freq--;
                    cnt++;

                    if (freq > 0)
                        temp.push_back(freq);
                }
            }

            for (int x : temp)
                pq.push(x);

            if (pq.empty())
                time += cnt;
            else
                time += n + 1;
        }

        return time;
    }
};