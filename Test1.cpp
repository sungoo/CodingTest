#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string makeAns(vector<string> q) {
    int a = stoi(q[0]);
    int b = stoi(q[2]);
    if (q[1] == "-")
        b *= -1;
    if (a + b == stoi(q[4]))
        return "O";
    else
        return "X";
}

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for (auto q : quiz) {
        istringstream iss(q);
        string buf;
        vector<string> bufs;
        while (getline(iss, buf, ' ')) {
            bufs.push_back(buf);
        }
        answer.push_back(makeAns(bufs));
    }
    return answer;
}

int main()
{
    vector<string> quiz = { "3 - 4 = -3", "5 + 6 = 11" };

    vector<string> ans = solution(quiz);
    for (auto it : ans) {
        cout << it << " ";
    }

    return 0;
}