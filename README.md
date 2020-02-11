# SW-Algorithm
Online Judge

알고리즘 문제를 해결하고 코드를 공유합니다. 

## 에러 해결 방법
- 런타임 에러
1. 라이브러리 함수를 사용하지만 해당하는 헤더파일을 include 하지 않았을 때
     * [cplusplus.com](http://www.cplusplus.com/) 에서 레퍼런스를 참조하여 해당하는 헤더파일을 넣어준다.
2. 반환을 해야하는 함수이지만 반환값이 없이 반환했을 때
3. main 함수가 0이 아닌 값을 반환할 때
4. 배열 인덱스 범위를 초과하는 위치를 참조할 때
5. 이터레이터가 삭제된 위치나 end를 참조할 때

- 시간 초과
1. 무한루프 (재귀의 경우 반환을 하지 않는 경우가 있을 때)
2. 알고리즘의 효율이 떨어질 때
    * 계산한 값을 다시 사용할 수 있는 방법을 찾아본다. (메모이제이션)
    * 불필요한 중복 접근은 없는지 확인해 본다.
3. 입력을 받다가 시간을 다 써버렸을 때
    * 빠른 입출력 방법을 사용한다.

- 틀렸습니다
1. 반례가 있을 때
    * 입력의 최소값, 최대값이 입력으로 들어왔을 경우를 테스트 해본다.
2. 기본 자료형의 범위를 넘어갈 때
    * int 형이 표시 할 수 있는 범위 -2,147,483,648~ 2,147,483,647를 넘어가는 경우 long long으로 대체할 수 있는지 확인해 본다.
