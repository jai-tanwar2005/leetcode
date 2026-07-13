class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int open = 0;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
                maxi = max(maxi, open);
            }
            else if (s[i] == ')') {
                open--;
            }
        }

        return maxi;
    }
};
