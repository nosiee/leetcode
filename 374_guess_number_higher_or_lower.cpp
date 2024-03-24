class Solution {
  public:
    int guessNumber(int n) {
        int l = 0;
        int r = n;

        while (l <= r) {
            // to avoid overflow (r + l) / 2, calculate middle in the more usual way
            const int m = ((r - l) / 2) + l;
            int g = guess(m);

            if (g == -1) {
                r = m - 1;
            } else if (g == 1) {
                l = m + 1;
            } else {
                return m;
            }
        }

        return -1;
    }
};
