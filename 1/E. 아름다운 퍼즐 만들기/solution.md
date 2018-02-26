퍼즐의 가로길이가 10(m <= 10)이하 이기때문에, 마지막으로 사용한 m개의 퍼즐조각의 색을 유지하면 dp로 풀 수 있습니다.

dp[y][x][mask] = (1,1) ~ (y,x) 까지 퍼즐 조각을 둔 상태이고, 마지막으로 사용한 m개의 퍼즐조각의 집합이 mask일때 얻을 수 있는 최대아름다움.

way[y][x][mask] = dp[y][x][mask]를 만들 수 잇는 경우의 수.

 현재 보고 있는 dp테이블 (y,x,current_mask)
 
 현재 상태로부터 도달가능한 다음 상태의 dp테이블 (y,x+1,next_mask)
 
 beauty = (y,x+1)칸에 (y-1,x+1),(y,x)과는 다른 색의 퍼즐조각을 뒀을 때 얻을 수 있는 아름다움.

  
1.dp[y][x][current_mask] + beauty > dp[y][x+1][next_mask]

     dp[y][x+1][next_mask] = dp[y][x][current_mask] + beauty
     way[y][x+1][next_mask] = way[y][x][current_mask]
     
2.dp[y][x][current_mask] + beauty == dp[y][x+1][next_mask]

     dp[y][x+1][next_mask] = dp[y][x][current_mask] + beauty
     way[y][x+1][next_mask] = way[y][x][current_mask] + way[y][x+1][next_mask]


시간 복잡도 O( nm * 4^m ) 

공간 복잡도 O( 4^m )  메모리 제한 때문에 토글링 필요







