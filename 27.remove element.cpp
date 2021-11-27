class Solution {
public:
    int removeElement(vector<int>& A, int val) {
        int j = 0, N = A.size();
        for (int i = 0; i < N; ++i) {
            if (A[i] != val) A[j++] = A[i];
        }
        return j;
    }
};
