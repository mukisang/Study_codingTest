#include<iostream>
using namespace std;

int main(void)
{
  int N, K;
  cin >> N >> K;
   if( N > 10 )
	{
      cout << "N값을 잘못 입력했습니다." << endl; 
	}
   if( K > 100000000)
    {
      cout << "K값을 잘못 입력했습니다." << endl;
    }
    
    int *p = new int[N];

    for(int i = 0; i < N; i++) 
	  cin >> p[i];
	
	int temp = 0;
    int n1 = 0;
    

	while(K != 0)	
    {  
     for(int i = 0; i < N; i++)
	 {
      if( K < p[i])
	  {	
		  temp = p[--i];  
		  break;
	  }
	  if( K == p[i])
	  {
          temp = p[i];
          break;
	  }	  
	 }
	 n1 += K / temp;  
     K = K % temp;
     
	}  
	 
	 cout << endl << n1 << endl;	
	 return 0;

}
