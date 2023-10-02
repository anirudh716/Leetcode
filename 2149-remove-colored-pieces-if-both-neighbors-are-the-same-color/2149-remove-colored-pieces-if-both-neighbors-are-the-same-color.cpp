class Solution {
public:
    bool winnerOfGame(string colors) {
        int aliceCount = 0, bobCount = 0;
        for (int i = 1; i < colors.size() - 1; ++i) {
            if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1]) {
                if (colors[i] == 'A') {
                    aliceCount++;
                } else {
                    bobCount++;
                }
            }
        }
        return aliceCount > bobCount;
    }
};
