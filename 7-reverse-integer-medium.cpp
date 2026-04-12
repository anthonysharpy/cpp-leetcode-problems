class Solution {
public:
    int reverse(int x) {
        try {
            int sign = x < 0 ? -1 : 1;

            auto as_string = std::to_string(x);
            auto reversed_string = as_string;

            std::reverse(reversed_string.begin(), reversed_string.end());

            std::int32_t reversed_int = std::stoi(reversed_string);

            auto back_to_string = std::to_string(reversed_int);
            std::int32_t back_to_int = std::stoi(back_to_string);

            if (reversed_int != back_to_int) {
                return 0;
            }

            return reversed_int * sign;
        }
        catch (...) {
            return 0;
        }
    }
};