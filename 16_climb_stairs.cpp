/**
 * Key Learning Point: Figured the solution right below (Time Exceeded) by myself just through the math and testing. Watching
 * neetcode's explaination shows us that this is basically some Fibonacci sequence. So, we can either use memoization, so that we dont
 * recalculate things we calculated before which incurs O(n) memory, or we can just do it iteratively.
 *
 * Runtime: O(n), optimal solution below
 *
 * Memory: O(1)
 */
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 0)
        {
            return 1;
        }

        int endWithOne = climbStairs(n - 1);
        int endWithTwo = climbStairs(n - 2);

        return endWithOne + endWithTwo;
    }
};

// Optimal Solution, DP because solve smaller problem as solution to bigger problem
class Solution {
public:
    int climbStairs(int n) {
        int i = 1;
        int j = 1;
        n -= 2;
        while (n >= 0)
        {
            int temp = i;
            i += j;
            j = temp;
            n--;
        }

        return i;
    }
};
