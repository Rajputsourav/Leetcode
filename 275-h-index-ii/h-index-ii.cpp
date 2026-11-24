
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (citations[mid] >= n - mid) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return n - low;
    }
};
