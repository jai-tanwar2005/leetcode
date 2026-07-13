class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Bucket where index = frequency
        vector<vector<char>> bucket(s.size() + 1);

        for (auto &[ch, f] : freq) {
            bucket[f].push_back(ch);
        }

        string result = "";

        // Traverse buckets from highest frequency to lowest
        for (int i = s.size(); i >= 1; i--) {
            for (char ch : bucket[i]) {
                result += string(i, ch);
            }
        }

        return result;
    }
};