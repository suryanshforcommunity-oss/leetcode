#include <vector>
#include <string>

class Solution {
public:
    int compress(std::vector<char>& chars) {
        int write = 0;
        int read = 0;
        int n = chars.size();
        
        while (read < n) {
            char currentChar = chars[read];
            int count = 0;
            
            // Count consecutive repeating characters
            while (read < n && chars[read] == currentChar) {
                read++;
                count++;
            }
            
            // Write the character
            chars[write++] = currentChar;
            
            // If the character repeated, write its digit counts
            if (count > 1) {
                std::string countStr = std::to_string(count);
                for (char digit : countStr) {
                    chars[write++] = digit;
                }
            }
        }
        
        return write;
    }
};
