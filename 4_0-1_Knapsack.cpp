#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int items, capacity;
    cout << "Enter the number of items: ";
    cin >> items;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    vector<int> price(items + 1), wt(items + 1);
    cout << "Enter the price and weight of each item:\n";
    for (int i = 1; i <= items; i++)
    {
        cout << "Item " << i << " - Price: ";
        cin >> price[i];
        cout << "Item " << i << " - Weight: ";
        cin >> wt[i];
    }

    vector<vector<int>> dp(items + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= items; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (wt[i] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], price[i] + dp[i - 1][j - wt[i]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << "Maximum Profit Earned: " << dp[items][capacity] << "\n";
    return 0;
}
// tc and sc=0(items*capacity)