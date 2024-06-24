## 2048 (Easy)
https://www.acmicpc.net/problem/12100

### ✅ 문제 분석
* 블록은 동, 서, 남, 북 4개의 방향으로 한 번에 이동하며 보드판 밖을 벗어날 수는 없다.
* 같은 수를 가진 두 블록이 충돌하면 2배의 값을 가진 하나의 블록으로 합쳐진다.
* 한 번의 이동에 두 개의 블록만 합쳐질 수 있으며  이동하려고 하는 쪽의 블록들이 먼저 합쳐진다.
    * 2->2->4일 경우 8이 되지 못하고 4->4   
    * 2->2->2일 경우 2->4

* 정사각형 보드 크기 N과 초기 보드 구성이 주어졌을 때, 최대 5번 이동해서 만들 수 있는 가장 큰 블록의 값을 구하면 된다.

<br/>

### ✅ 알고리즘 설계
* 최대 5번의 실행을 하기 때문에 방향 (0, 1, 2, 3)에 대한 모든 경우의 수를 따져보는 백트래킹으로 풀어야겠다는 생각을 했다.
* solve 함수에서 크기가 5인 방향 순서를 담은 벡터를 만든다.
* 방향 순서 5개가 모두 정해지면 calculate 함수에서 시뮬레이션을 돌린다.
* 0(북), 1(서), 2(남), 3(동) 이라고 방향값을 지정해놓았을 때, 코드를 간략하게 짜기 위해서 규칙을 찾고자 했다.
x는 행번호, y는 열번호라고 했을 때
    * 0(북): x=0부터 x=N-1까지 차례대로 합쳐질 블록을 찾음
    * 1(서): y=0부터 y=N-1까지 차례대로 합쳐질 블록을 찾음
    * 2(남): x=N-1부터 x=0까지 차례대로 합쳐질 블록을 찾음
    * 3(동): y=N-1부터 y=0까지 차례대로 합쳐질 블록을 찾음

* 방향이 0과 1일때는 행/열이 0부터 1씩 증가하고 방향이 2와 3일 때는 행/열이 N-1부터 1씩 감소한다.
* 방향이 0과 2일때는 행에 대해 충돌을 고려하고 방향이 1과 3일 때는 열에 대해 충돌을 고려한다.

* curr와 next 포인터를 두고 queue 자료구조를 이용해 해당 행/열의 계산 값을 집어넣는다.    
    * curr와 next가 같으면 queue에 curr 2배 값을 삽입 후 curr는 현재 next 포인터 다음부터 search
    * curr와 next가 다르면 queue에 curr 값 삽입 

* 한 행/열에 대한 계산이 끝날 때마다 queue의 값을 board에 집어넣고 모든 계산이 끝나면 최대값을 찾아 answer와 비교한다.

<br/>

### ✅ 시간 복잡도
* solve 함수: 4(방향개수)^5(5가지 select) = 1024 
* calculate 함수: N^2 + 5*N^2 + N^2 = O(N^2)

* 총 시간 복잡도 O(n^2)
* 이 문제에서 N <= 20이므로 1초 안에 실행가능하다.

<br/>

### ✅ 부족했던 부분
처음 풀이에서 아래 케이스를 생각하지 못해 다음과 같은 output이 도출되었다.

```
[input]
5
2 2 4 8 16
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
2 2 4 8 16

[output]
0       0       0       0       0
0       0       0       0       0
0       0       0       0       0
2       2       4       8       16
2       2       4       8       16
```

아래 방향으로 블록을 이동시켰을 때, 바로 이웃한 블록 간의 충돌만 고려하여 중간에 빈 블록들이 있고 그 위에 같은 수를 가진 블록이 떠 있는 경우 잘못된 실행 결과가 출력되었다.

이 문제를 바로잡기 위해 
1) 기존에는 curr, next 포인터를 두고 바로 이웃한 curr와 next 값이 같지 않을 때 curr 값을 queue에 삽입하고 다음 curr = next가 되어 실행 과정이 반복되었다면 curr와 next를 하나의 쌍으로 인식해 curr가 결정되면 그 다음 순차적으로 0이 아닌 next를 찾아서 떨어진 블록 간에도 값의 비교가 가능하게 했다.

2) 해당 행/열의 숫자를 가진 블록이 홀수 개라 curr와 next가 짝을 이룰 수 없는 경우, for문을 나온 후에 짝이 없는 curr를 queue에 삽입할 수 있도록 예외처리해주었다.

<br/>
