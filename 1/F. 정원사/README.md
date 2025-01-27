﻿# 정원사

- 제한 시간: 3초
- 메모리: 128MB

온조는 N개의 정원을 가꾸는 정원사이다. 모든 정원에는 아직 아무런 식물도 심어져 있지 않고, 각각의 정원에는 식물을 무한정 심을 수 있다. 모든 식물은 하루에 k만큼 자란다. 즉, 높이 h의 어떤 식물이 심어진 날이 x번째 날이라면, y번째 날에는 높이가 h + k(y-x)가 된다. 온조는 M개의 작업을 수행해 N개의 정원을 예쁘게 가꾸려고 한다.


다음은 작업의 종류 세 가지이다:  
- 1 t x h : t번째 날에 x번째 정원에 높이가 h인 식물을 하나 추가한다.
- 2 t l r h : t번째 날에 l번째 정원부터 r번째 정원까지에 심어져 있는 모든 식물들 중에서 높이가 h를 초과한 식물들을 모두 뽑아 버린다.
- 3 t l r : t번째 날에 l번째 정원부터 r번째 정원까지에 심어져 있는 모든 식물들의 수를 출력한다.


온조는 뛰어난 정원사였기 때문에 첫 번째 작업과 두 번째 작업은 손쉽게 할 수 있었지만, 세 번째 작업은 수학에 약한 온조로서는 수행하기 어려웠다. 세 번째 작업에 대한 답을 우리가 대신 해 주자!

## 입력
첫째 줄에 정원의 수 N (1 ≤ N ≤ 10^5)과 온조와 당신이 수행할 작업의 수 M (1 ≤ M ≤ 10^6), 모든 식물이 하루에 자라는 높이 k (1 ≤ k ≤ 10^9)가 주어진다. 그 다음 줄부터 M개의 줄에는 작업의 정보가 주어진다. 작업의 정보는 날짜가 증가하는 순으로 주어지고, l과 r, x는 1 이상 N 이하이며, 그 외의 모든 수는 1 이상 10^9 이하의 자연수이다. 참고로 온조는 같은 날에 두 개의 작업을 하는 것을 원치 않기 때문에, 하루에는 최대 하나의 작업만 수행한다는 것이 보장된다.

## 출력
세 번째 작업에 대한 답을 각각의 줄에 출력한다. M개의 작업 중 세 번째 작업이 적어도 하나가 있다는 것이 보장된다.

## 예시 입출력

### 입력
3 5 1  
1 1 2 3  
1 2 2 3  
1 3 3 6  
2 4 2 3 6  
3 100 1 3  

### 출력
2  
