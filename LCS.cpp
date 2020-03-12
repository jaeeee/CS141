//#include <bits/std.h>
#include <iostream>
using namespace std;

int max(int a, int b);

int lcs(char *input1, char *input2, int x, int y)
{
    if (x == 0 || y == 0)
        return 0;
    if (input1[x - 1] == input2[y - 1])
        return 1 + lcs(input1, input2, x - 1, y - 1);
    else
        return max(lcs(input1, input2, x, y - 1), lcs(input1, input2, x - 1, y));
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs_bottom(char *input1, char *input2, int x, int y)  
{  
    int out[x + 1][y + 1];  
    int i, j;  
    for (i = 0; i <= x; i++)  
    {  
        for (j = 0; j <= y; j++)  
        {  
        if (i == 0 || j == 0)  
            out[i][j] = 0;  
      
        else if (input1[i - 1] == input2[j - 1])  
            out[i][j] = out[i - 1][j - 1] + 1;  
      
        else
            out[i][j] = max(out[i - 1][j], out[i][j - 1]);  
        }  
    }  
    return out[x][y];  
}

/* Driver code */
int main()
{
    char X[100];
    char Y[100];

    cout << "Enter X sequence: ";
    cin >> X;
    cout << "Enter Y sequence: ";
    cin >> Y;
 
    int m = strlen(X);
    int n = strlen(Y);

   // cout << "Length of LCS is " << lcs(X, Y, m, n);
    cout << "Length of LCS is " << lcs_bottom(X,Y,m,n) << endl;
    return 0;
}
