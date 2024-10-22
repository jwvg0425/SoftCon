﻿# K-균등 문자열

- 제한 시간: 1초
- 메모리: 256MB

0과 1로 이루어진 문자열에서 길이가 K인 연속된 부분문자열을 뽑았을 때, 항상 그 부분문자열에 포함된 1의 개수가 같다면 이 문자열을 K-균등하다고 하자.

예를 들어, “100110”이라는 문자열이 있을 때, 이 문자열은 4-균등하다고 말할 수 있다. 길이가 4인 연속된 부분문자열은 {“1001”, “0011”, “0110”} 이 있고, 모두 1이 2개씩 포함되어 있기 때문이다.

온조는 0과 1로 이루어진 길이 N의 문자열을 만들려고 한다. 또한 온조는 M개의 좋아하는 구간과, M개의 좋아하는 수가 있다. 이때 i번째 구간은 L_i번째 문자부터 R_i번째 문자까지의 부분문자열을 의미하며, i번째 수는 K_i이다. 온조는 i번째 구간에 해당되는 부분문자열이 ‘K_i-균등’하기를 원한다. (K_i는 i번째 구간의 길이보다 크지 않다.) 이때, 온조가 만들 수 있는 문자열의 수를 구하시오. 수가 커질 수 있으니 1,000,000,007로 나눈 나머지를 출력하여라.

## 입력
첫째 줄에 N과 M이 주어진다. (1 ≤ N ≤ 1000, 0 ≤ M ≤ 1000) i+1번째 줄에는 L_i, R_i, K_i가 주어진다. (1 ≤ L_i ≤ R_i ≤ N, 1 ≤ K_i ≤ R_i - L_i + 1)

## 출력
첫째 줄에 만들 수 있는 문자열의 수를 1,000,000,007로 나눈 나머지를 출력하여라.

## 예시 입출력

### 입력
5 2  
1 4 2  
3 5 3  

### 출력
8  

### 입력
1000 0  

### 출력
688423210  

## 힌트
첫 번째 예제에서는, 다음의 8가지로 문자열을 만들 수 있다.
{“00000”, “00001”, “01010”, “01011”, “10100”, “10101”, “11110”, “11111”}

두 번째 예제에서는 온조가 좋아하는 구간과 수가 없으므로 길이 N의 아무런 문자열이나 만들어도 된다. 즉, 2^1000개의 문자열을 만들 수 있다.
