#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    char K = k + '0';
    for (int a = i; a <= j; a++) {
        string str = to_string(a);
        if (str.find(K) != string::npos)
            for (auto aa : str)
                if (aa == K)
                    answer++;
    }
    return answer;
}

int main() {
    cout << solution(1, 13, 1);
    return 0;
}