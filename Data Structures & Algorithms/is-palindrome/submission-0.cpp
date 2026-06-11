#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;

        while (start < end) {
            // Skip non-alphanumeric characters
            while (start < end && !isalnum(s[start])) start++;
            while (start < end && !isalnum(s[end])) end--;

            // Compare characters (case insensitive)
            if (tolower(s[start]) != tolower(s[end])) {
                return false; // If mismatch found, return false
            }

            start++;
            end--;
        }

        return true; // If all characters matched, return true
    }
};
