/* sorting  + two pointer */
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& A) {
        sort(begin(A), end(A));
        int N = A.size(), mx = A[N - 1] - A[0] - N - min(A[N - 1] - A[N - 2], A[1] - A[0]) + 2, mn = mx;
        for (int i = 0, j = 0; i < N; ++i) {
            while (j < N && A[j] <= A[i] + N - 1) ++j;
            int cnt = N - j + i;
            if (cnt == 1 && A[j - 1] != A[i] + N - 1) continue; // If the opening is at the end of the window, skip
            mn = min(mn, cnt);
        }
        return { mn, mx };
    }
};
