class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int countNum = 0;
        char operation = '+';

        for (int i = 0; i < s.size(); i++) {
            char charNum = s[i];

            if (isdigit(charNum)) {
                countNum = (countNum * 10) + (charNum - '0');
            }
            if (!isdigit(charNum) && !isspace(charNum) || i == s.size() - 1) {
                if (operation == '+') {
                    st.push(countNum);
                } else if (operation == '-') {
                    st.push(-countNum);
                } else if (operation == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * countNum);
                } else if (operation == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / countNum);
                }

                operation = charNum;
                countNum = 0;
            }
        }

        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
