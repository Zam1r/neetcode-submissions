#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st; // Changed name to 'st' for clarity, type to char
        
        for (char c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[':
                    st.push(c); // Push the opening brackets
                    break;
                
                case ')':
                    // FIX: Check if empty FIRST, then check if top matches
                    if (!st.empty() && st.top() == '(') {
                        st.pop(); // Pop from the STACK 'st', not the string 's'
                    } else {
                        return false;
                    }
                    break;
                
                case '}':
                    if (!st.empty() && st.top() == '{') {
                        st.pop();
                    } else {
                        return false;
                    }
                    break;
                
                case ']':
                    if (!st.empty() && st.top() == '[') {
                        st.pop();
                    } else {
                        return false;
                    }
                    break;
            }
        }
        
        // If the stack is empty, all brackets were matched perfectly
        return st.empty(); 
    }
};