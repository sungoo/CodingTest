#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string binAdd(char b1, char b2) {
    if (b1 == '0' && b2 == '0')
        return "00";
    if ((b1 == '1' && b2 == '0') || (b1 == '0' && b2 == '1'))
        return "10";
    if (b1 == '1' && b2 == '1')
        return "01";
}

string binSum(string b1, string b2) {
    if (b2.find('1') == string::npos)
        return b1;
    else {
        string aRes = "";
        string bRes = "0";
        int c = 0;
        for (c; c < b1.size(); c++) {
            if (c >= b2.size())
                aRes.push_back(b1[c]);
            else {
                string res = binAdd(b1[c], b2[c]);
                aRes.push_back(res[0]);
                bRes.push_back(res[1]);
            }
        }
        if (c < b2.size())
            for (c; c < b2.size(); c++)
                aRes.push_back(b2[c]);
        return binSum(aRes, bRes);
    }
}

string solution(string bin1, string bin2) {
    string answer = "";
    reverse(bin1.begin(), bin1.end());
    reverse(bin2.begin(), bin2.end());
    answer = binSum(bin1, bin2);
    for (auto a = answer.end() - 1; a > answer.begin(); a--) {
        if (*a == '1')
            break;
        else
            answer.pop_back();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int main() {
    cout << solution("1001", "1111");
}