#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            // If target could be in this row
            if (matrix[i][0] <= target && matrix[i][n - 1] >= target) {
                int l = 0, r = n - 1;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    if (matrix[i][mid] == target) return true;
                    else if (matrix[i][mid] > target) r = mid - 1;
                    else l = mid + 1;
                }
                // target not in this row; no need to check further in this row
                return false; // optional: if rows are guaranteed to be strictly increasing by row,
                               // you could return false here. If rows are independent, continue.
            }
            // else: target not in this row range → check next row
        }
        return false;
    }
};