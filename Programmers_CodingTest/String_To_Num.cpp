#include <string>
#include <vector>

#include <iostream>


using namespace std;

/*
*   Programmers [숫자 문자열과 영단어] (Level 1)
*/

int solution(string s) {
    int answer = 0;
    size_t idx = 0;
    vector<string> vecStr = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (int i = 0; i < vecStr.size(); i++)
    {
        idx = s.find(vecStr[i]);
        if (idx != s.npos)
        {
            s.replace(idx, vecStr[i].length(), to_string(i));
            i--;
        }
    }

    answer = stoi(s);

    return answer;
}

int main()
{
    return 0;
}