
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> freq;

        string word, ans;
        int maxFreq = 0;

        for (int i = 0; i <= paragraph.size(); i++) {
            char c = (i < paragraph.size()) ? paragraph[i] : ' ';

            if (isalpha(c)) {
                word += tolower(c);
            } else {
                if (!word.empty()) {
                    if (!ban.count(word)) {
                        freq[word]++;

                        if (freq[word] > maxFreq) {
                            maxFreq = freq[word];
                            ans = word;
                        }
                    }

                    word.clear();
                }
            }
        }

        return ans;
    }
};
