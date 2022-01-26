Problem Statement

Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.

You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under a constraint that any painter will only paint the continuous sections of boards.

For Example :

    In the below figure where array/list elements are {2, 1, 5, 6, 2, 3}.

    A painter can paint blocks {5,6} or {1,5,6,2} together but not {2,5,6} or {5,6,3}.

<img src="https://files.codingninjas.in/histogram-6831.PNG">

Input Format :

The first line contains a single integer ‘T’ denoting the number of test cases.

The first line of each test case contains two integers ‘N’ and ‘K’ denoting the number of elements in the array/list and number of painters available.

The second line contains ‘N’ single space-separated integers denoting the elements of the array/list.

Output Format :

For each test case, print the minimum time required to get the job done.

Note :

    You do not need to print anything; it has already been taken care of.

Constraints :

    1 <= T <= 5
    1 <= N <= 10^4
    1 <= K <= N
    1 <= ARR[i] <= 10^5

    Where ‘T’ is the number of test cases.
    'N' is the length of the given array/list (boards).

    ‘K’ is the number of painters available.
    And, ARR[i] denotes the i-th element in the array/list.

    Time Limit: 1 sec.

Sample Input 1 :

    2
    4 2
    5 5 5 5
    4 2
    10 20 30 40

Sample Output 1 :

    10
    60

Explanation For Sample Input 1 :

    In the first test case, we can divide the boards into 2 equal-sized partitions, so each painter gets 10 units of the board and the total time taken is 10.


    In the second test case, we can divide the first 3 boards for one painter and the last board for the second painter.

Sample Input 2 :

    2
    2 2
    48 90
    4 2
    1 2 3 4

Sample Output 2 :

    90
    6