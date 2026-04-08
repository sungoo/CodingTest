#include <string>
#include <vector>

using namespace std;

int solution(int M, int N) {
    int answer = 0;
    //가로로 M-1번 세로로 (N-1)*M번
    answer = (M - 1) + (N - 1) * M;
    return answer;
}