#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> babb = { "aya", "ye", "woo", "ma" };
int Babbling(string b) {
    //빈 문자열이 들어옴 = 전부 조합 가능
    if (b.empty())
        return 1;
    else {
        for (int a = 0; a < 4; a++) {
            if (b.size() < 2) {
                return 0;
            }
            string sub = b.substr(0, babb[a].size());
            if (sub == babb[a])
                return Babbling(b.substr(babb[a].size()));
        }
        //for문 탈출: babb로는 만들 수 없는 단어
        return 0;
    }
}
int solution(vector<string> babbling) {
    int answer = 0;
    for (auto bb : babbling)
        answer += Babbling(bb);
    return answer;
}

int main() {
    cout << solution({ "aya", "yee", "u", "maa", "wyeoo" });
}