class Solution {
public:
    int maximumGap(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        if (n == 1) {
            return 0;
        }
        int maxi = arr[1] - arr[0];
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, arr[i] - arr[i - 1]);
        }
        return maxi;
    }
};