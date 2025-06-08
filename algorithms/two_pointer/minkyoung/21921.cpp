// [투포인터] 21921: 블로그

#include <iostream>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    int arr[250000]; // 비교를 위한 배열
    int sum=0; // sum: 단위마다 더한 값
    int max, count = 1; // max: 현재까지의 최대 방문자 수, count 1로 초기화

    for (int i=0; i<N; i++) {
        cin >> arr[i];
        if (i < X) {
            sum += arr[i]; 
        }
    }

    max = sum; // 일단 더한 값을 max에 넣음

    for (int i=X; i<N; i++) { // 다 비교한 후 max 정하기
        sum -= arr[i-X];  // 맨 앞 값 뺌
        sum += arr[i];  // 맨 뒷 값 더함

        if (max == sum) // max 정해진 후
            count++; 
        else if (max < sum) {
            max = sum; 
            count = 1;
        }
    }

    if (max == 0) 
        cout << "SAD";
    else
        cout << max << "\n" << count;

    return 0;
}

// X일 동안 가장 많이 들어온 방문자 수 & 기간이 몇 개인가