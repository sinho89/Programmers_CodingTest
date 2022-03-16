#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    int dotCount = 0;
    int firstPos = 0;

    for (int i = 0; i < new_id.size(); i++)
        new_id[i] = tolower(new_id[i]);

    for (int i = 0; i < new_id.size(); i++)
    {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9')
            || (new_id[i] == '-') || (new_id[i] == '_') || (new_id[i] == '.'))
            answer = answer + new_id[i];
    }

    for (int i = 0; i < answer.size(); i++)
    {
        if (answer[i] == '.')
        {
            if (dotCount == 0)
                firstPos = i;
            dotCount++;
        }
        else
            dotCount = 0;
        
        if (dotCount >= 2)
        {
            answer.replace(firstPos, dotCount, ".");
            i -= dotCount;
            dotCount = 0;
        }
    }

    for (int i = 0; i < answer.size(); i++)
    {
        if ((i == 0 || i == answer.size() - 1) && answer[i] == '.')
            answer.erase(i, 1);
    }

    if (answer.size() == 0)
        answer = 'a';

    if (answer.size() <= 2)
    {
        for (int i = 0; i < answer.size(); i++)
        {
            if (answer.size() > 2)
                break;

            if (i == answer.size() - 1)
                answer.append(1, answer[i]);
        }
    }

    if (answer.size() >= 16)
    {
        answer.erase(15);
        if (answer[answer.size()-1] == '.')
            answer.erase(answer.size() - 1, 1);
    }

    return answer;
}
