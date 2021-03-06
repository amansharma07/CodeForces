#include <cstdio>
#include <vector>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

using namespace std;

int main()
{
    int no_of_elements;
    long long p, q, r;
    scanf("%d %I64d %I64d %I64d", &no_of_elements, &p, &q, &r);

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &A[i]);

    vector <int> left_min(no_of_elements + 1);
    vector <int> left_max(no_of_elements + 1);
    left_min[1] = left_max[1] = A[1];

    for(int i = 2; i <= no_of_elements; i++)
    {
        left_min[i] = min(left_min[i - 1], A[i]);
        left_max[i] = max(left_max[i - 1], A[i]);
    }

    vector <int> right_min(no_of_elements + 1);
    vector <int> right_max(no_of_elements + 1);
    right_min[no_of_elements] = right_max[no_of_elements] = A[no_of_elements];

    for(int i = no_of_elements - 1; i >= 1; i--)
    {
        right_max[i] = max(right_max[i + 1], A[i]);
        right_min[i] = min(right_min[i + 1], A[i]);
    }

    long long ans = p*A[1] + q*A[1] + r*A[1];
    for(int i = 1; i <= no_of_elements; i++)
    {
        long long y = q*A[i];
        long long x = (p > 0 ? p*left_max[i] : p*left_min[i]);
        long long z = (r > 0 ? r*right_max[i] : r*right_min[i]);

        ans = max(ans, x + y + z);
    }

    printf("%I64d\n", ans);
    return 0;
}
