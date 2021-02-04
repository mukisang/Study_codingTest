function solution(board, moves) {
  let result = 0; //최종 결과를 낼 변수
  let size = board.length; 
  let num = 0;
  let basket = []; //인형을 뽑아 담은 바구니
  
  moves.forEach(move => {
      let count = 0;
      while (true) {
          //board[0][0]은 인형이 아무 것도 없는 상태이기 때문에 move-1로 해야한다.
          if (board[count][move - 1] != 0) {
              //만약 바구니 안에 있는 인형과 움직인 인형이 같으면 빼고 결과값 2 플러스 (바구니 크기가 0이면 안된다!)
              if (basket.length !== 0 && basket[basket.length - 1] === board[count][move - 1]) {
                  basket.pop();
                  result += 2;
              } else { //그렇지 않은 경우는 바구니에 쌓기
                  basket.push(board[count][move - 1]);
              }
              //인형이 아무것도 없으면 반복문 종료
              board[count][move - 1] = 0;
              break;
          }
          count++;
          //count가 board 길이인 size만큼 도달했으면 반복문 종료 
          if (count == size) {
              break;
          }
      }
  })
  //크레인을 모두 작동시킨 후 터트려져 사라진 인형의 개수 return
  return result;
}