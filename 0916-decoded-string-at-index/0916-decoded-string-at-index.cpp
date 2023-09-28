class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long decodedLength = 0;
        int n = s.size();

        for(int i=0; i<n; i++){
            if(isdigit(s[i]))
                decodedLength *= s[i] -'0';
            else
                decodedLength++;
        }

        for(int i=n-1; i>=0; i--){
            k %= decodedLength;
            if(k == 0 && isalpha(s[i]))
                return string(1,s[i]);
            if(isdigit(s[i]))
                decodedLength /= s[i] - '0';
            else
                decodedLength--;
        }

        return "";
    }
};
