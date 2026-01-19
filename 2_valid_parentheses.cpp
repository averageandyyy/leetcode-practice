/*
 * Key Learning Point: Use stack to track how many opens we have. Cannot start with closes i.e. if we encounter
 * close, stack should not be empty. Stack must then be empty at the end i.e. will not be empty if we only
 * had consecutive opens.
 *
 * Runtime: O(n)
 * Memory: O(n)
 *
 * Improvement: Use hashmap for comparisons instead! I tried to be special and use switch statements for practice haha.
 */
class Solution {
public:
    bool isOpen(char c)
    {
        switch (c)
        {
            case '(':
            case '{':
            case '[':
                return true;
            default:
                return false;
        }
    }

    bool isSame(char o, char c)
    {
        switch (o)
        {
            case '(':
                return c == ')';
            case '{':
                return c == '}';
            case '[':
                return c == ']';
        }

        return false;
    }

    bool isValid(string s) {
        // Use stack, push on open, pop on close
        stack<char> st;

        for (char c : s)
        {
            if (isOpen(c))
            {
                st.push(c);
            }
            else
            {
                if (st.empty()) // Evaluates to true if we start with closing bracket
                {
                    return false;
                }

                char p = st.top();
                st.pop();

                if (!isSame(p, c)) // Quit immediately if different
                {
                    return false;
                }
            }
        }

        return st.empty(); // All brackets must be accounred for (think consecutive opens)
    }
};
