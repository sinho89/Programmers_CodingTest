using System;

namespace Programmers_CodingTest_CSharp
{
    public class DotSolution // 내적 문제
    {
        public int solution(int[] a, int[] b)
        {
            int answer = 0;

            for (int i = 0; i < a.Length; i++)
                answer += a[i] * b[i];

            return answer;
        }
    }
    public class AbsoluteSolution // 음양 더하기
    {
        public int solution(int[] absolutes, bool[] signs)
        {
            int answer = 0;

            for (int i = 0; i < absolutes.Length; i++)
            {
                if (signs[i] == true)
                    answer += absolutes[i];
                else
                    answer -= absolutes[i];
            }
            return answer;
        }
    }
    public class PrimeSolution // 소수 구하기
    {
        public int solution(int[] nums)
        {
            int answer = 0;
            int temp = 0;

            for (int i = 0; i < nums.Length-2; i++)
            {
                for(int j = i+1; j < nums.Length-1; j++)
                {
                    for (int k = j+1; k < nums.Length; k++)
                    {
                        temp = nums[i] + nums[j] + nums[k];

                        int cnt = 0;

                        for (int l = 1; l <= temp; l++)
                        {

                            if (temp % l == 0)
                                cnt++;
                        }

                        if (cnt <= 2)
                            answer++;
                    }

                }
            }
            return answer;
        }
    }

    class Program
    {

        static void Main(string[] args)
        {
            int[] a = new int[5] { 1,2,7,6,4 };
            bool[] b = new bool[3] { false, false, true };

            PrimeSolution prime = new PrimeSolution();

            Console.WriteLine($"{prime.solution(a)}");
        }
    }
}
