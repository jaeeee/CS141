#include <iostream>

using namespace std;

string X, Y;

int find_LCS(int i, int j, int count)
{
    // X = "abcdxyz";
    // Y = "xyzabcd";
    if (i == 0 || j == 0)
    {
        return count;
    }
    if (X[i - 1] == Y[j - 1])
    {
        count = find_LCS(i - 1, j - 1, count + 1);
    }
    count = max(count, max(find_LCS(i, j - 1, 0), find_LCS(i - 1, j, 0)));
    return count;
}

int find_LCS_bottom_up(int a, int b) {
    int result = -1;
    int LCS[a+1][b+1];
    for (int i = 0; i <= b; i++) {
        LCS[0][i] = 0;
    } 
    for (int i = 0; i <= a; i++) {
        LCS[i][0] = 0;
    }
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (X[i-1] == Y[j-1]) {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            } else {
                LCS[i][j] = 0;
            }
        }
    }
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if (result < LCS[i][j]) {
                result = LCS[i][j];
            }
        }
    }
    return result;
}

int main()
{
    int n, m;
    cout << "Enter a string: " << endl;
    cin >> X;
    cout << "Enter another string: " << endl;
    cin >> Y;
    n = X.size();
    m = Y.size();
    // cout << find_LCS(n, m, 0) << endl;
    cout << find_LCS_bottom_up(n, m) << endl;
    return 0;
}