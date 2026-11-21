class Solution {
public:
    string r1 = "qwertyuiop";
    string r2 = "asdfghjkl";
    string r3 = "zxcvbnm";

    // Helper to return which row (1, 2, or 3) a character belongs to
    int getRow(char c) {
        c = tolower(c); // Handle uppercase letters
        if (r1.find(c) != string::npos) return 1;
        if (r2.find(c) != string::npos) return 2;
        return 3;
    }

    vector<string> findWords(vector<string>& words) {
        vector<string> ans;

        for (string word : words) {
            int targetRow = getRow(word[0]);
            bool isValid = true;

            for (char c : word) {
                if (getRow(c) != targetRow) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
