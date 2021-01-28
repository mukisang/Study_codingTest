function solution(array, commands) {
  var answer = [];
  
  for (var i = 0; i < commands.length; i++) {
      /* 배열은 0부터 시작하기 때문에 원소 값에서 -1을 해줘야한다. slice된 배열을 정렬할 때 그냥 정렬하면 두자릿수가 나올 때           아스키코드로 인식하므로 오류가 난다. 따라서 a-b를 해줘야 오름차순 정렬이 된다! 
        cf. b-a는 내림차순 정렬! */
      var newArr = array.slice(commands[i][0]-1, commands[i][1]).sort((a,b) => {return a-b});
      
      answer.push(newArr[commands[i][2]-1]); // 잊지말자 배열은 0부터 시작!
  }
  return answer;
}