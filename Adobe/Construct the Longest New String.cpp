class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans = 0;
    int minComb = min(x, y);
    if (z == 0)
    {
        return 4 * minComb;
    }

    if (x == y)
    {
        ans = (x + y) * 2;
        ans += z * 2;
        return ans;
    }
    ans += 4 * minComb;
    ans += 2;
    ans += z * 2;

    return ans;
    }
};
