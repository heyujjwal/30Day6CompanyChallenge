typedef long long int long_int;
class Solution {
    long_int findLCM(long_int x, long_int y) {
        return (x * y) / __gcd(x, y);
    }

    bool isPoss(long_int maxValue, const int div1, const int div2, const int count1, const int count2) {
        long_int valid = maxValue;

        long_int bothInvalid = maxValue / findLCM(div1, div2);
        long_int arr1Invalid = maxValue / div1 - bothInvalid;
        long_int arr2Invalid = maxValue / div2 - bothInvalid;

        long_int canBeInAny = maxValue - arr2Invalid - arr1Invalid - bothInvalid;

        if (arr2Invalid < count1) canBeInAny -= (count1 - arr2Invalid);
        if (arr1Invalid < count2) canBeInAny -= (count2 - arr1Invalid);

        return (canBeInAny >= 0);
    }

public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCount1, int uniqueCount2) {
        long_int left = 1;
        long_int right = 2e9;

        while (left < right) {
            long_int mid = (left + right) / 2;
            if (isPoss(mid, divisor1, divisor2, uniqueCount1, uniqueCount2))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};
