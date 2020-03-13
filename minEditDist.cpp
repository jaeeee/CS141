#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int min(int x, int y, int z) {
    return min(min(x,y),z);
}

double minEditDist(string str1, string str2, int str1_length, int str2_length) {
    if (str1_length == 0) {
        return str2_length;
    }
    if (str2_length == 0) {
        return str1_length;
    }
    if(str1[str1_length - 1] == str2[str2_length - 1])
        return minEditDist(str1, str2, str1_length - 1, str2_length - 1);
    
    if (minEditDist(str1, str2, str1_length, str2_length-1) < minEditDist(str1, str2, str1_length-1, str2_length) && minEditDist(str1, str2, str1_length, str2_length-1) < minEditDist(str1, str2, str1_length-1, str2_length-1)) {
        return 0.7 + minEditDist(str1, str2, str1_length, str2_length-1);
    } else if (minEditDist(str1, str2, str1_length-1, str2_length) < minEditDist(str1, str2, str1_length, str2_length-1) && minEditDist(str1, str2, str1_length-1, str2_length) < minEditDist(str1, str2, str1_length-1, str2_length-1)) {
        return 0.9 + minEditDist(str1, str2, str1_length-1, str2_length);
    } else {
        return 1.0 + minEditDist(str1, str2, str1_length-1, str2_length-1);
    }
}

int main() {
    string first;
    string second;
    cout << "Enter first string: ";
    cin >> first;
    cout << "Enter second string: ";
    cin >> second;
    cout << "Minimum edit distance for both strings is: " << minEditDist(first, second, first.length(), second.length()) << endl;
}
