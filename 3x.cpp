#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> visited = vector<bool>(101, false);
    for (int a = 1; a <= n; a++) {
        string str = to_string(a);
        if (a % 3 == 0 || str.find("3") != string::npos) {
            answer+=2;
        }
    }
    answer += n;
    return answer;
}

int main() {
    cout << solution(10);
    return 0;
}