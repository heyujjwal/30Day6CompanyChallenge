class Solution {
public:
    // Recursive helper function to find the word break
    bool wordBreakHelper(int ind, string& s, vector<string>& word, vector<int>& dp) {

        int n = s.length();

        // Base case: reached the end of the string 
        if (ind == n) return true; 

        // Return precomputed result if available
        if (dp[ind] != -1) return dp[ind]; 

        for (int i = ind; i < n; i++) {

            // Extract substring from ind to i
            string temp = s.substr(ind, i - ind + 1); 
            if (find(word.begin(), word.end(), temp) != word.end()) {

                // If the current substring is in the word dictionary, try breaking the rest
                if (wordBreakHelper(i + 1, s, word, dp)) return dp[ind] = true;
            }
        }

        // If no valid word break is found, mark and return false
        return dp[ind] = false; 
    }

    // Main function to find the word break
    bool wordBreak(string s, vector<string>& word) {
        int n = s.length(); 
        vector<int> dp(n, -1); 
        return wordBreakHelper(0, s, word, dp); 
    }
};
