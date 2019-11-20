#include <iostream>
using namespace std;

int main(void)
{
 cout << "1 이상 1000미만의 정수하나를 입력하시오: " << endl;
 int x;
 cin >> x;
 x = 1000 - x;
 cout << x;
 int count = 0;
 
 if( (x/500) > 0 ) 
  {   count += x/500;
      x = x % 500;
  }
 if( (x/100) > 0 ) 
  {   count += x/100;
      x = x % 100;
  }
 if( (x/50) > 0 ) 
  {   count += x/50;
      x = x % 50;
  }
 if( (x/10) > 0 ) 
  {   count += x/10;
      x = x % 10;
  }
 if( (x/5) > 0 ) 
  {   count += x/5;
      x = x % 5;
  }
 if( (x/1) > 0 ) 
  {   count += x/1;
      x = x % 1;
  }
 
 cout << endl << "거스름돈은" 
	  << count << "개의 동전으로 나타낼수 있음"
	  << endl;

}
