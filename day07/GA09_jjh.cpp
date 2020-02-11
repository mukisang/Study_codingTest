
#include <iostream>


2.#include <cstdio>


3.using namespace std;


4. 


5.int compare(int x, int y, char *a, char *b)   // x는 A의 문자열의 개수 


6.{


7.   int count = 0;


8.    for(int i = y; i < (y+x); i++)


9.   {


10.     if(a[(i - y)] == b[i])


11.         count++;


12.   }


13.   return count;


14. 


15.}


16. 


17.int main(void)


18.{


19.   char A[50];


20.   char B[50];


21. 


22.   cout << "A를 입력하시오 : ";


23.   gets(A);


24.   cout << "B를 입력하시오 : ";


25.   gets(B);


26.   


27.   int number_a = 0;    // 문자열 A의 개수 


28.   int number_b = 0;    // 문자열 B의 개수 


29. 


30.   for(int i = 0; i < 50; i++)


31.   {


32.       if(A[i] == '\0')


33.           break;


34.       number_a++;


35.   }


36.   for(int i = 0; i < 50; i++)


37.   {


38.       if(B[i] == '\0')


39.           break;


40.       number_b++;


41.   }


42.   


43.   int index = number_b - number_a;


44.   int result = compare(number_a, 0, A, B);


45.  


46.   for(int i = 0; i < index; i++)


47.   { 


48.     cout << i << endl;


49.     cout << compare(number_a, i, A, B) << endl;


50.     


51.     if(compare(number_a, i, A, B) < compare(number_a, i+1, A, B))


52.         result = compare(number_a, i+1, A, B);


53.     


54.     else


55.         result = compare(number_a, i, A, B);


56.   


57.     }    


58.    cout << result << endl;  


59.    cout << "정답" << (number_a - result) << endl;  


60.  


61.  


62.  return 0;


63.}
