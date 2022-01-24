Problem Statement

You are given ‘N’ integers in the form of an array ‘ARR’. Print the sorted array using the insertion sort.

Note :

    No need to return anything. You should sort the array in-place.

For Example :

    Let ‘ARR’ be: [1, 4, 2]
    The sorted array will be: [1, 2, 4].

Input Format :

The first line of input contains an integer ‘T’, denoting the number of test cases.

The first line of each test case contains an integer, ‘N’, representing the size of the array.

The second line of each test case contains ‘N’ space-separated integers, representing the array ‘ARR’ elements.

Output Format :

For each test case, print the sorted array.

Print output of each test case in a separate line.

Note :

You do not need to print anything. It has already been taken care of. Just implement the given function. 

Constraints :

    1 <= T <= 10
    1 <= N <= 5*10^3
    1 <= ARR[i] <= 10^5

    Time Limit: 1 sec

Sample Input 1 :

    2
    4
    3 1 2 2
    3
    1 4 2

Sample Output 1 :

    1 2 2 3
    1 2 4

Explanation For Sample Output 1 :

    For test case 1: 
    The sorted array will be: [1, 2, 2, 3].

    For test case 2: 
    The sorted array will be: [1, 2, 4].

Sample Input 2 :

    2
    4
    4 12 11 20
    6
    6 5 4 3 2 1

Sample Output 2 :

    4 11 12 20
    1 2 3 4 5 6
