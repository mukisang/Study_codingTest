#include <iostream>
#include <cstdio>
using namespace std;

int compare(int x, int y, char *a, char *b)   // x는 A의 문자열의 개수 
{
   int count = 0;
	for(int i = y; i < (y+x); i++)
   {
     if(a[(i - y)] == b[i])
		 count++;
   }
   return count;

}

int main(void)
{
   char A[50];
   char B[50];

   cout << "A를 입력하시오 : ";
   gets(A);
   cout << "B를 입력하시오 : ";
   gets(B);
   
   int number_a = 0;    // 문자열 A의 개수 
   int number_b = 0;    // 문자열 B의 개수 

   for(int i = 0; i < 50; i++)
   {
	   if(A[i] == '\0')
		   break;
	   number_a++;
   }
   for(int i = 0; i < 50; i++)
   {
	   if(B[i] == '\0')
		   break;
	   number_b++;
   }
   
   int index = number_b - number_a;
   int result = compare(number_a, 0, A, B);
  
   for(int i = 0; i < index; i++)
   { 
     cout << i << endl;
	 cout << compare(number_a, i, A, B) << endl;
	 
	 if(compare(number_a, i, A, B) < compare(number_a, i+1, A, B))
		 result = compare(number_a, i+1, A, B);
     
	 else
		 result = compare(number_a, i, A, B);
   
	 }	  
    cout << result << endl;  
    cout << "정답" << (number_a - result) << endl;  
  
  
  return 0;
}




