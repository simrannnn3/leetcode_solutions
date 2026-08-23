class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                leftSum += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                rightSum += num[i] - '0';
        }

        int diff = leftSum - rightSum;
        int qDiff = leftQ - rightQ;

        // If the number of '?' is odd, Alice gets the extra move
        if ((leftQ + rightQ) % 2 == 1)
            return true;

        // Bob can balance the game only in this exact situation
        if (diff * 2 == -9 * qDiff)
            return false;

        return true;
    }
};