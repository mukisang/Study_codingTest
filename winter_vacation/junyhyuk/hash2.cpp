#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());

 
    for(auto it = phone_book.begin(); it != phone_book.end()-1; it++)
    {
           string strtemp(*it);
         
           
           string strtemp2(*(it+1));
           const char *temp2 = strtemp.c_str();
           const char *temp3 = strtemp2.c_str();
           if(strstr(temp3, temp2) != NULL){ 
                    answer = false;
                    return answer;
           }
          
    }
    return answer;
}