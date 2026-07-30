    int lengthOfLongestSubstring(char *s) {
    int left = 0, right = 0;
    int maxLen = 0;
    int freq[128] = {0};
    while (s[right] != '\0') {

        while (freq[s[right]] > 0) {
            freq[s[left]]--;
            left++;
        }
        freq[s[right]]++;

        if (right - left + 1 > maxLen)
            maxLen = right - left + 1;

        right++;
    }
    return maxLen;
}