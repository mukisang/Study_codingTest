function solution(participant, completion) {
  participant.sort();
  completion.sort(); // 참여 선수들과 완주한 선수들 배열 먼저 정렬하기
  
  for(var i = 0; i < participant.length; i++) { // 하나씩 key값 비교하다가 불일치하는 값 return
      if (participant[i] != completion[i]) {
          return participant[i]; // 이 값이 바로 비완주자!
      }
  }
}