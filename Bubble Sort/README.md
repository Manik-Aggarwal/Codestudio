Problem Statement

Bubble Sort is one of the sorting algorithms that works by repeatedly swapping the adjacent elements of the array if they are not in sorted order.

You are given an unsorted array consisting of N non-negative integers. Your task is to sort the array in non-decreasing order using the Bubble Sort algorithm.

For Example:

Bubble Sort implementation for the given array:  {6,2,8,4,10} is shown below :-

<img src="https://files.codingninjas.in/capture-6583.JPG">

Input Format:

The first line of input contains an integer 'T' representing the number of test cases.

Then the test case follows.

The first line of each test case contains integer N denoting the size of the array.

The second line of each test case contains 'N' space-separated integers representing the array elements

Output Format:

The only line of output of each test case should print the sorted array in increasing order.

Output for each test case will be printed in a separate line.

Note:

    You do not need to print anything, it has already been taken care of. Just implement the given function. Also, you need to update the given array in place only.

Constraints:

    1 <= T <= 100
    1 <= N <= 100
    1 <= Arr[i] <= 1000

Where 'T' represents the number of test cases, 'N' represents the size of the array, and Arr[i] represents the elements of the array.

Time Limit: 1 sec.

Sample Input 1:

    1
    5
    6 2 8 4 10

Sample Output 1:

    2 4 6 8 10

Sample Input 2:

    2
    2
    1 2
    4
    4 3 2 1

Sample Output 2:

    1 2
    1 2 3 4
