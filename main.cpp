#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

# 이 문제에 해당하는 조건은, 논문 인용수를 순위로 따졌을 때 n번째 순위를 가진 논문의 인용횟수가 n보다 크거나 같아야한다.
# 위에 적힌 n보다 더 작은 값에서도 조건은 만족하지만 최대 n을 구하는 조건에는 맞지 않다.
# 따라서 논문 인용수를 내림차순으로 정렬하고 n번째 순위를 가진 논문의 인용횟수가 n보다 작아질 때 직전의 n이 답이다.
# 예외로 모든 논문이 최대 n의 조건에 부합하는 경우 논문의 개수가 답이다.

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.rbegin(),citations.rend());

    for (int i = 0; i < citations.size(); i++)
    {
        if (citations[i] < i+1)
        {
            answer = i;
            break;
        }
        else if (i == citations.size() - 1)
        {
            answer = i+1;
        }
    }
    
    return answer;
}
