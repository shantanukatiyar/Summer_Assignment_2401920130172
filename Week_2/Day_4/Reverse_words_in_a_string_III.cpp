class Solution {
public:
    string reverseWords(string s) {
        string word, ans;

        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverse(word.begin(), word.end());
                ans += word;

                if (i != s.size())
                    ans += ' ';

                word = "";
            } else {
                word += s[i];
            }
        }

        return ans;
    }
};
