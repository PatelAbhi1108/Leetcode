class Solution {
public:

    string encode(vector<string>& strs) {
    string res;
    
    // Iterate through each string in the vector using an index-based for loop
    for (int i = 0; i < strs.size(); i++) {
        string s = strs[i]; // Get the current string
        int length = s.size(); // Get the length of the current string
        res += to_string(length) + "#" + s; // Append length, separator, and string
    }
    
    return res;
}


    vector<string> decode(string s) {
    vector<string> res; // To store the decoded strings
    int i = 0; // Pointer to track the current position in the string

    // Process the entire encoded string
    while (i < s.size()) {
        int j = i; // Pointer to find the `#` character

        // Find the position of `#` that separates the length and string
        while (s[j] != '#') {
            j++;
        }

        // Extract the substring that represents the length of the next string
        string lengthStr = s.substr(i, j - i);
        int length = stoi(lengthStr); // Convert it to an integer

        i = j + 1; // Move past the `#` symbol

        // Extract the actual string of given `length`
        string decodedStr = s.substr(i, length);
        res.push_back(decodedStr); // Store in result

        i = i + length; // Move `i` to the next encoded part
    }

    return res;
}

};
