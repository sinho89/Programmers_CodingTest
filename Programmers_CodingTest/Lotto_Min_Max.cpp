#include <string>
#include <vector>

using namespace std;

/*
*   Programmers [로또의 최고순위와 최저 순위] (Level 1) 
*/

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int maxCount = 0;
    int minCount = 0;

    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
        {
            maxCount++;
            continue;
        }

        for (int j = 0; j < win_nums.size(); j++)
        {
            if (lottos[i] == win_nums[j])
            {
                maxCount++;
                minCount++;
            } 
        }
    }

    answer.push_back(maxCount);
    answer.push_back(minCount);

    for (int i = 0; i < answer.size(); i++)
    {
        switch (answer[i])
        {
            case 6:
                answer[i] = 1;
                break;
            case 5:
                answer[i] = 2;
                break;
            case 4:
                answer[i] = 3;
                break;
            case 3:
                answer[i] = 4;
                break;
            case 2:
                answer[i] = 5;
                break;
            default:
                answer[i] = 6;
                break;
        }
    }

    return answer;
}
