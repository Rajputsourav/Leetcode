
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
            "....", "..", ".---", "-.-", ".-..", "--", "-.",
            "---", ".--.", "--.-", ".-.", "...", "-", "..-",
            "...-", ".--", "-..-", "-.--", "--.."
        };

        unordered_set<string> unique;

        for (string word : words) {
            string code = "";

            for (char ch : word) {
                code += morse[ch - 'a'];
            }

            unique.insert(code);
        }

        return unique.size();
    }
};
