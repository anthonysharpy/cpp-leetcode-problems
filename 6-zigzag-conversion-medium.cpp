class Solution {
public:
    string convert(string s, int numRows) {
        std::vector<std::vector<char*>> grid{};

        grid.resize(s.length());

        for (auto& column : grid) {
            column.resize(numRows);
        }

        int x = 0;
        int y = 0;
        int lastX = 0;
        bool bouncing = false;

        for (auto& c : s) {
            lastX = x;

            grid[x][y] = &c;

            if (y >= numRows-1) {
                bouncing = true;
            } else if (y <= 0) {
                bouncing = false;
            }

            if (bouncing) {
                --y;
                ++x;

                y = std::max(y, 0);
            } else {
                ++y;
            }
        }

        std::string output = "";

        for (y = 0; y < numRows; ++y)
        {
            for (x = 0; x <= lastX; ++x)
            {
                if (grid[x][y] != nullptr) {
                    output += *grid[x][y];
                }
            }
        }

        return output; 
    }
};