#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    if (A == B)
        return 0;
    int i = A.size() - 1;
    for (i; i >= 0; i--) {
        string temp = A;
        rotate(temp.begin(), temp.begin() + i, temp.end());
        if (temp == B)
            break;
    }
    if (i<0)
        return -1;
    answer = A.size() - i;
    return answer;
}

int main() {
    cout << solution("hello", "ohell");
}