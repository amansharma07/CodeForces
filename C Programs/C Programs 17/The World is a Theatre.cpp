#include <cstdio>

int main()
{
    const int N = 60;
    long long combinations[N + 1][N + 1];

    combinations[0][0] = 1;

    for(int n = 1; n <= N; n++)
    {
        for(int r = 0; r <= n; r++)
        {
            if(r == 0 || r == n)
                combinations[n][r] = 1;
            else
                combinations[n][r] = combinations[n - 1][r] + combinations[n - 1][r - 1];
        }
    }


    int no_of_actors, boys, girls;
    scanf("%d %d %d", &boys, &girls, &no_of_actors);

    long long no_of_ways = 0;
    for(int i = 4; i < no_of_actors; i++)
        no_of_ways += combinations[boys][i]*combinations[girls][no_of_actors - i];

    printf("%I64d\n", no_of_ways);
    return 0;
}
