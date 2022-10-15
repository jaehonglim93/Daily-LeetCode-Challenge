class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> comparison;
        stack<char> comparison2;
        
        for (int i = 0; i < s.length(); i++) {
            if (!comparison.empty() && s[i] == '#') {
                comparison.pop();
            } else if (s[i] != '#'){
                comparison.push(s[i]);
            }
        }
        
        for (int i = 0; i < t.length(); i++) {
            if (!comparison2.empty() && t[i] == '#') {
                comparison2.pop();
            } else if (t[i] != '#') {
                comparison2.push(t[i]);
            }
        }
                
        if (comparison.size() != comparison2.size()) {
            return false;
        }
        
        while (!comparison.empty() && !comparison2.empty()) {
            if (comparison.top() != comparison2.top()) {
                return false;
            } 
            
            cout << comparison.size() << endl;
            comparison.pop();
            comparison2.pop();   
        }
        
        return true;
    }
};