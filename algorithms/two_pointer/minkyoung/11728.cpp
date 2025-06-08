// [투포인터] 11728: 배열 합치기

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);

    // 벡터에 입력값 넣음
    for (int i=0; i<N; i++)
        cin >> A[i];
    for (int i=0; i<M; i++) 
        cin >> B[i];

    int i=0, j=0;
    // 결과 벡터 사용하지 않고 바로 출력
    while (i < N && j < M) {
        if (A[i] < B[j]) {
            cout << A[i++] << ' ';
        } else {
            cout << B[j++] << ' ';
        }
    }

    // 비교 후 나머지 수들 넣음
    while (i < N) 
        cout << A[i++] << ' ';
    while (j < M) 
        cout << B[j++] << ' ';

    return 0;
}

// * 메모리 초과 발생 * 
// int main() {
//     int N, M;
//     cin >> N >> M;

//     vector<int> A(N), B(M);

//     // 벡터에 입력값 넣음
//     for (int i=0; i<N; i++)
//         cin >> A[i];
//     for (int i=0; i<M; i++) 
//         cin >> B[i];

//     // 크기비교해서 하나로 합칠 벡터 선언
//     vector<int> answer;
//     int i=0, j=0;
//     while (i < N && j < M) {
//         if (A[i] < B[j]) 
//             answer.push_back(A[i]); // 크기 작은 것 먼저 넣음
//         else   
//             answer.push_back(B[j]);
//     }

//     // 비교 후 나머지 수들 넣음
//     while (i < N)
//         answer.push_back(A[i++]);
//     while (j < M)
//         answer.push_back(B[j++]);

//     for (int ans : answer)
//         cout << ans << ' ';

//     return 0;
// }

// 이미 정렬되어 있는 배열을 이용 -> merge sort 이용
// 크기 비교해서 하나씩 넣음 