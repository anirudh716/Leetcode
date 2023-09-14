class Solution {
public:
    int reverse(int x) {
        long long reversed = 0;
        while(x != 0){
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        if(reversed < INT_MIN || reversed > INT_MAX)
            return 0;
        return reversed;
    }
};