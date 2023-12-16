class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int result = 0, i = 0, j = 0;
        int count_F = 0;
        while(j < n){
            if(answerKey[j] == 'F')
                count_F++;
            while(count_F > k){
                if(answerKey[i] == 'F')
                    count_F--;
                i++;
            }
            result = max(result, j-i+1);
            j++;
        }
        int count_T = 0;
        i = 0, j = 0;
        while(j < n){
            if(answerKey[j] == 'T')
                count_T++;
            while(count_T > k){
                if(answerKey[i] == 'T')
                    count_T--;
                i++;
            }
            result = max(result, j-i+1);
            j++;
        }
        return result;
    }
};