class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        vector<int> rank(26);

        for (int i = 0; i < 26; i++) {
            rank[order[i] - 'a'] = i;
        }

        for (int i = 0; i < words.size() - 1; i++) {

            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());

            bool different = false;

            for (int j = 0; j < len; j++) {

                if (s1[j] != s2[j]) {

                    if (rank[s1[j] - 'a'] > rank[s2[j] - 'a']) {
                        return false;
                    }

                    different = true;
                    break;
                }
            }

            // Prefix case: "apple" comes before "app" -> invalid
            if (!different && s1.size() > s2.size()) {
                return false;
            }
        }

        return true;
    }
};