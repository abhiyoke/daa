#include <iostream>
#include <vector>

using namespace std;

// Iteratively calculating Fibonacci using memoization
int iStepFibonacci(int n, int &steps)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    vector<int> f(n + 1);
    f[0] = 0;
    f[1] = 1;
    steps = 2; // for initializing the first two values

    for (int i = 2; i <= n; i++)
    {
        steps++;
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

// Recursive calculation of Fibonacci with step tracking
int rSteps = 0;
int rStepFibonacci(int n)
{
    rSteps++; // count each function call
    if (n <= 1)
        return n;
    return rStepFibonacci(n - 1) + rStepFibonacci(n - 2);
}

int main()
{
    int n;
    cout << "Enter Fibonacci term to compute: ";
    cin >> n;

    // Recursive approach
    int recursiveFib = rStepFibonacci(n);
    cout << "Fibonacci Value (Recursive): " << recursiveFib << '\n';
    cout << "Steps required using recursion: " << rSteps << '\n';

    // Iterative approach
    int iSteps = 0;
    int iterativeFib = iStepFibonacci(n, iSteps);
    cout << "Fibonacci Value (Iterative): " << iterativeFib << '\n';
    cout << "Steps required using iteration: " << iSteps << '\n';

    return 0;
}

/*
Time and Space Complexity Analysis:

1. Recursive Fibonacci:
   - Time Complexity: O(2^n) - Each call spawns two more calls, leading to exponential growth.
   - Auxiliary Space: O(n) - Due to recursion stack depth, where n is the input number.

2. Iterative Fibonacci:
   - Time Complexity: O(n) - Linear iteration up to the nth term.
   - Auxiliary Space: O(n) - For storing computed values in a vector.
*/
