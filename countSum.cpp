#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    //num*x + (num-1)*num/2 = total
    int x = -50;
    for (x; x < 100 - num; x++) {
        if (2 * num * x == 2 * total - (num - 1) * num)
            break;
    }
    for (int i = 0; i < num; i++)
        answer.push_back(x + i);
    return answer;
}

int main() {
    vector<int> sol = solution(3, 12);
    for (auto s : sol)
        cout << s;
}