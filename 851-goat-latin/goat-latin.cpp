
class Solution {
public:
    string toGoatLatin(string sentence) {
        string ans = "";
        string word = "";
        int count = 0;

        for (int i = 0; i <= sentence.size(); i++) {

            if (i < sentence.size() && sentence[i] != ' ') {
                word += sentence[i];
            }
            else {
                count++;

                char ch = tolower(word[0]);

                if (ch != 'a' && ch != 'e' &&
                    ch != 'i' && ch != 'o' &&
                    ch != 'u') {

                    word = word.substr(1) + word[0];
                }

                word += "ma";

                word += string(count, 'a');

                if (!ans.empty()) {
                    ans += " ";
                }

                ans += word;

                word = "";
            }
        }

        return ans;
    }
};
