// CodingTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = "";
    auto end = my_string.end();
    //vector<string::iterator> rit;
    auto rit = end;
    for (auto it = my_string.begin(); it != end; it++)
        for (auto dit = it + 1; dit != end; dit++)
            if (*dit == *it)
                rit = remove(it + 1, end, *it);
    my_string.erase(rit, my_string.end());
    answer = my_string;
    return answer;
}

int main()
{
    std::cout << solution("123142") << endl;
}

