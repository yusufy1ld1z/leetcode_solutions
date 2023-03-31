#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> left_hand;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                left_hand.push(s[i]);
            else if (s[i] == ')' && !left_hand.empty() && left_hand.top() == '(')
                left_hand.pop();
            else if (s[i] == ']' && !left_hand.empty() && left_hand.top() == '[')
                left_hand.pop();
            else if (s[i] == '}' && !left_hand.empty() && left_hand.top() == '{')
                left_hand.pop();
            else
                ;
        }

        return left_hand.empty();
    }
};

int main()
{
    Solution exp;
    string text;
    getline(cin, text);

    cout << (exp.isValid(text) ? "Valid" : "Not Valid") << "\n";
}