Problem Statement

You are given an array of integers 'ARR' containing N elements. Each integer is in the range [1, N-1], with exactly one element repeated in the array.

Your task is to find the duplicate element.

Note :

    All the integers in the array appear only once except for precisely one integer which appears two or more times.

Input format:

    The first line of input contains an integer ‘T’ denoting the number of test cases. Then the T test cases follow.

    The first line of each test case contains an integer ‘N’, the number of elements in the array. 

    The second line of each test case contains ‘N’ space-separated integers representing the elements of the array. 

Output format:

    For each test case, the duplicate element of the given array is printed.

The output of each test case is printed in a separate line. 

Note :

    You are not supposed to print anything; It has already been taken care of. Just implement the given function.

Constraints :

    1 <= T <= 5
    1 <= N <= 10^5
    1 <= ARR[i] <= N - 1

Time Limit: 1 sec

Sample Input 1:

    1
    3
    1 1 2

Sample Output 1:

    1

Explanation of Sample Input 1:

    1 is repeated in the array, hence function returns 1.

Sample Input 2:

    3
    5
    1 3 4 2 2
    5
    3 1 3 4 2
    3
    1 1 1

Sample Output 2:

    2
    3
    1