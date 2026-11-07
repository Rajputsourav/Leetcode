
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        if (s == goal) {
            set<char> st(s.begin(), s.end());
            return st.size() < s.size();
        }

        vector<int> diff;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i]) {
                diff.push_back(i);
            }
        }

        if (diff.size() != 2) {
            return false;
        }

        int i = diff[0];
        int j = diff[1];

        return s[i] == goal[j] && s[j] == goal[i];
    }
};
