#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    for (auto it = my_string.begin(); it < my_string.end(); it++) {
        if (*it >= 'A')
            continue;
        string temp;
        temp.push_back(*it);
        for (int i = 1; i <= 4; i++) {
            if (it[i] >= 'A')
                break;
            temp += it[i];
        }
        answer += stoi(temp);
    }
    return answer;
}

int main() {
    cout << solution("1a2b3c4d123Z");
    return 0;
}