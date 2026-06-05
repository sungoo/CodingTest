#include <string>
#include <vector>
#include <iostream>

using namespace std;

//최대공약수
int findGDC(int big, int small) {
    if (big % small == 0) return small;
    return findGDC(small, big % small);
}
//최소공배수
int findLCM(int x, int y) {
    return x * y / findGDC(x, y);
}

//다수(<= 5) 상대로 공약수와공배수
int findMlcm(vector<int> mess) {
    int Msize = mess.size();
    switch (Msize)
    {
    case 2:
        return findLCM(mess[0], mess[1]);
    case 3:
        return findLCM(findLCM(mess[0], mess[1]), mess[2]);
    case 4:
        return findLCM(findLCM(findLCM(mess[0], mess[1]), mess[2]), mess[3]);
    case 5:
        return findLCM(findLCM(findLCM(findLCM(mess[0], mess[1]), mess[2]), mess[3]), mess[4]);
    }
}

int solution(vector<vector<int>> signals) {
    int answer = 0;
    //[g, g, y, r, r] 과 같은 형태로 바꾸기
    vector<vector<char>> sigs;
    vector<int> siglen;
    for (int i = 0; i < signals.size(); i++) {
        int len = 0;
        vector<char> temp;
        for (int j = 0; j < 3; j++) {
            for (int x = 0; x < signals[i][j]; x++) {
                char t;
                switch (j) {
                case 0:
                    t = 'g';
                    break;
                case 1:
                    t = 'y';
                    break;
                case 2:
                    t = 'r';
                    break;
                }
                temp.push_back(t);
                len++;
            }
        }
        sigs.push_back(temp);
        siglen.push_back(len);
        cout << "signal" << i << " size : " << len << endl;
    }
    cout << "signal total : " << sigs.size() << endl;
    //순환
    bool isAllYell = false;
    int turn = 0;
    //전체 순환의 끝 : 신호들의 최소공배수
    int limit = findMlcm(siglen);
    do {
        vector<char> now;
        int yCNT = 0;
        for (int i = 0; i < sigs.size(); i++) {
            now.push_back(sigs[i][turn % sigs[i].size()]);
        }
        for (auto it : now)
            if (it == 'y') 
                yCNT++;
        isAllYell = (yCNT == sigs.size());
        //전체 최소공배수 만큼 돌았는데 정전안됨 => 앞으로도 정전되지 않음
        if (turn > limit) {
            answer = -1;
            isAllYell = true;
        }
        turn++;
    } while (!isAllYell);
    if(answer != -1)
        answer = turn;
    return answer;
}

int cleanerSignal(vector<vector<int>> signals) {
    int answer = 0;
    //각 신호등 길이 저장
    vector<int> siglen;
    for (int i = 0; i < signals.size(); i++) {
        int len = 0;
        for (int j = 0; j < 3; j++) {
            len += signals[i][j];
        }
        siglen.push_back(len);
    }
    //순환
    int turn = 0;
    vector<int> signalTurn = vector<int>(signals.size(), 0);
    bool isAllYell = false;
    do {
        int isYell = 0;
        for (int i = 0; i < signalTurn.size(); i++) {
            signalTurn[i] = turn % siglen[i];
            if (signalTurn[i] >= signals[i][0] && signalTurn[i] - signals[i][0] < signals[i][1])
                isYell++;
        }

        if (turn != 0 && signalTurn == vector<int>(signals.size(), 0)) {
            answer = -1;
            isAllYell = true;
        }
        if (isYell >= signals.size()) 
            isAllYell = true;
        turn++;
    } while (!isAllYell);
    if (answer != -1)
        answer = turn;
    return answer;
}

int main() {
    cout << cleanerSignal({ {1, 1, 4}, { 2, 1, 3 }, {3, 1, 2 }, {4, 1, 1 } });
    return 0;
}