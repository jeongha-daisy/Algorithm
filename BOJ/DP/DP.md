# DP

## [9095 1, 2, 3 더하기](https://www.acmicpc.net/problem/9095)

    void DP()
    {
        D[1] = 1;
        D[2] = 2;
        D[3] = 4;

        for (int i = 4; i < 11; i++)
            D[i] = D[i - 1] + D[i - 2] + D[i - 3];
    }

## [2579 계단 오르기](https://www.acmicpc.net/problem/2579)

계단이 한 개일 때는 하나만 오르는 게 최대,
계단이 두 개일 때는 둘 다 오르는 게 최대,
계단이 세 개일 때는 1,3 혹은 2,3 둘 중에 하나가 최대.(여기까지 초기 값)

n번 계단에 도달하는 방법은 두 계단 올라 오거나 한 계단 올라 오기.
즉, n번 계단에서 값을 가지는 경우는

1. n번 계단 값 + n - 2번 계단의 토탈 점수
2. n번 계단 값 + n - 1번 계단 값 + n - 3번 계단의 토탈 점수 (한 계단 올라온 거면 무조건 n - 3을 밟고 와야함.)

   for (int i = 3; i < n; i++)
   {
   answer[i] = max(answer[i - 2] + stairs[i], answer[i - 3] + stairs[i - 1] + stairs[i]);
   }
