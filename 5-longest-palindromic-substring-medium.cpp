class Solution {
public:
    string longestPalindrome(string s) {
        std::string longest = "";

        for (int center = 0; center < s.length(); ++center) {
            for (int width = 0; true; ++width) {
                int endpos = center + width;
                int startpos = center - width;

                if (endpos >= s.length() || startpos < 0 || s[startpos] != s[endpos])
                    break;

                std::string candidate = s.substr(startpos, (width * 2) + 1);

                if (candidate.length() > longest.length()) {
                    longest = candidate;
                }
            }
        }

        for (int leftcenter = 0, rightcenter = 1; rightcenter < s.length(); ++rightcenter, ++leftcenter) {
            for (int width = 0; true; ++width) {
                int endpos = rightcenter + width;
                int startpos = leftcenter - width;

                if (endpos >= s.length() || startpos < 0 || s[startpos] != s[endpos])
                    break;

                std::string candidate = s.substr(startpos, (width * 2) + 2);

                if (candidate.length() > longest.length()) {
                    longest = candidate;
                }
            }
        }

        return longest;
    }
};