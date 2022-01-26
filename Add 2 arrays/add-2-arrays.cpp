vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    vector<int> ans;
    vector<int> v;
    int i = n - 1, j = m - 1, carry = 0;
    while (std::max(i, j) >= 0){
        int val1, val2, elem;
        if (i < 0) val1 = 0;
        else val1 = a[i--];
        if (j < 0) val2 = 0;
        else val2 = b[j--];
        elem = val1 + val2 + carry;
        carry = elem / 10;
        elem %= 10;
        ans.push_back(elem);
    }
    if (carry) ans.push_back(carry);
    std::reverse(ans.begin(), ans.end());
    v = std::move(ans);
    return v;
}