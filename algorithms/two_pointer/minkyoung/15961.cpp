// [투포인터] 15961: 회전초밥

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, d, k, c; 
    cin >> N >> d >> k >> c;

    vector<int> sushi(N);

    for (int i=0; i<N; i++)
        cin >> sushi[i]; // 현재 레일에 있는 초밥

    vector<int> cnt(d + 1, 0);  // 초밥 종류마다 등장 횟수 저장하는 벡터
    int count = 0;

    // sliding window 이용
    for (int i=0; i<k; i++) {
        if (cnt[sushi[i]]++ == 0)
            count++; // 이전엔 없던 것이라는 뜻
    }
    
    int maxCount = count;
    if (cnt[c] == 0) // 없을 때만 1 추가 
        maxCount = count + 1;
    else
        maxCount = count;


    for (int i=1; i<N; i++) {
        int out = sushi[(i-1) % N]; // 버리는 거
        int in = sushi[(i+k-1) % N]; // 추가하는 거
        
        if (--cnt[out] == 0)
            count--;
        if (cnt[in]++ == 0)
            count++;

        int total = count;
        if (cnt[c] == 0)
            total++; // 쿠폰 초밥 추가 가능 여부
        maxCount = max(maxCount, total); // 큰 게 최종
    }

    cout << maxCount << "\n";
    return 0;
}

// 1. 벨트의 임의의 한 위치부터 k개의 접시를 연속해서 먹을 경우 할인된 정액 가격으로 제공
// 2. 할인 쿠폰 제공 -> 1에 참가할 경우: 쿠폰 종류의 초밥 하나 무료 제공
// 가능한 한 다양한 종류의 초밥을 먹는 게 목표 
// N: 회전 초밥 벨트에 놓인 접시의 수 / d: 초밥의 가짓수
// k: 연속해서 먹는 접시의 수 / c: 쿠폰 번호 

// 구현방식
// 1. 가장 다양한 초밥을 먹을 수 있는 배열들 만듦 (쿠폰 고려 x)
// 2. 쿠폰을 고려해 best를 선택
// sliding window 이용