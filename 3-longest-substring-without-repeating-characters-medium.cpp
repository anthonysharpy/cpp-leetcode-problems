class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) {
            return s.length();
        }

        int start = 0;
        int end = 0;
        std::string longest = "";

        while (start < s.length())
        {
            std::map<char, bool> charmap{};

            while (end < s.length()) 
            {
                char letter = s[end];
                bool exists = charmap.contains(letter);

                if (exists)
                    break;

                charmap[letter] = true;
                
                std::string candidate = s.substr(start, end-start + 1);

                if (candidate.length() > longest.length()) {
                    longest = candidate;
                }

                ++end;
            }

            ++start;
            end = start;
        }

        return longest.length();
    }
};