
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1);

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {

            // If character was already seen
            if (lastSeen[s[right]] >= left) {
                left = lastSeen[s[right]] + 1;
            }

            // Update last seen position
            lastSeen[s[right]] = right;

            // Calculate maximum window length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
