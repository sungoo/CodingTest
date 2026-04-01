#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string polynomial) {
    string answer = "";
    istringstream iss(polynomial);
    string temp;
    vector<string> hang;
    while (getline(iss, temp, ' '))
        hang.push_back(temp);
    int x = 0;
    int d = 0;
    for (auto h : hang) {
        if (h == "+")
            continue;
        int xp = h.find('x');
        if (xp == string::npos)
            d += stoi(h);
        else {
            if (xp == 0)
                x++;
            else
                x += stoi(h.substr(0, xp));
        }
    }
    if (x == 0 && d == 0)
        return "0";
    //x 붙이기
    if (x == 0)
        answer = "";
    else if (x == 1)
        answer = "x";
    else
        answer = to_string(x) + "x";
    //d 붙이기
    if (d == 0)
        return answer;
    if (answer.empty())
        return to_string(d);
    else
        answer += " + " + to_string(d);
    return answer;
}

int main()
{
    string aa = solution("10x + 4x");
    
    cout << aa;
    return 0;
}