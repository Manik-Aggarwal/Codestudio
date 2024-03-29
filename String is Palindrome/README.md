Problem Statement

You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, consider alphabets and numbers only and ignore the symbols and whitespaces.

Note :

    String 'S' is NOT case sensitive.

Example :

    Let S = “c1 O$d@eeD o1c”.
    If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase, we get S = “c1odeedo1c”, which is a palindrome. Hence, the given string is also a palindrome.

Input Format :

The very first line of input contains an integer 'T' denoting the number of test cases. 

The first line of every test case contains the string 'S'.

Output Format :

For each test case, print “Yes” if 'S' is a palindrome, and “No” otherwise.

Print the output of each test case in a separate line.

Note :

    You do not need to print anything, it has already been taken care of. Just implement the given function.

Follow Up :

    Can you solve the problem using O(1) space complexity?

Constraints :

    1 <= T <= 100 
    1 <= Length(S) <= 10^4

    Where 'T' denotes the number of test cases and 'S' denotes the given string.

    Time Limit : 1 sec

Sample Input 1 :

    2
    N2 i&nJA?a& jnI2n
    A1b22Ba

Sample Output 1 :

    Yes
    No

Explanation 1 :

    For the first test case, S = “N2 i&nJA?a& jnI2n”. If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase, we get S = “n2injaajni2n”, which is a palindrome. Hence, the given string is also a palindrome.

    For the second test case, S = “A1b22Ba”. If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase, we get S = “a1b22ba”, which is not a palindrome. Hence, the given string is not a palindrome.

Sample Input 2 :

    3
    codingninjassajNiNgNidoc
    5?36@6?35
    aaBBa@

Sample Output 2 :

    Yes
    Yes
    No