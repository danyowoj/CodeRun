#include <iostream>
#include <string>
#include <stack>

int main()
{
    std::string input;
    std::getline(std::cin, input);

    std::stack<char> sequence;
    bool valid = true;

    for (char character : input)
    {
        if (character == '(' || character == '[' || character == '{')
        {
            sequence.push(character);
        }
        else
        {
            if (sequence.empty())
            {
                valid = false;
                break;
            }
            char open = sequence.top();
            if (open == '(' && character == ')' ||
                open == '[' && character == ']' ||
                open == '{' && character == '}')
            {
                sequence.pop();
            }
            else
            {
                valid = false;
                break;
            }
        }
    }

    if (!sequence.empty())
        valid = false;

    std::cout << (valid ? "yes" : "no") << std::endl;

    return 0;
}
