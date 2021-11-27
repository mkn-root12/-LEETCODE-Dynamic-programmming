/*Intuition: Sort and only keep unique elements. The problem is the same as "get the length of the longest subarray whose difference between min and max elements is N - 1".

Algorithm:

The brute force way is to pick each A[i] as the start of the subarray and count the number of elements that are <= A[i] + N - 1, which takes O(N^2) time.

Since the array is already sorted, we can use sliding window so that we only traverse the entire array once.*/
class Solution {
public:
    int minOperations(vector<int>& A) {
        int N = A.size(), ans = N, j = 0;
        sort(begin(A), end(A));
        A.erase(unique(begin(A), end(A)), end(A)); // only keep unique elements
        int M = A.size();
        for (int i = 0; i < M; ++i) {
            while (j < M && A[j] < A[i] + N) ++j; // let `j` point to the first element that is out of range -- `>= A[i] + N`.
            ans = min(ans, N - j + i); // The length of this subarray is `j - i`. We need to replace `N - j + i` elements to make it continuous.
        }
        return ans;
    }
};
