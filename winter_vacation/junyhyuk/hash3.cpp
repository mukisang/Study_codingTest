#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<vector<int>> combination(vector<int> container, int r){

    int n = container.size();
    if (n < r) return {};
    if (r < 0) return {};

    vector<vector<int>> totvec;
    vector<int> tempvec(r);

    vector<bool> v(n);
    fill(v.end() - r, v.end(), true);  //뒤에서 r만큼 true로 채움
    int idx;
   
    do {
        idx = 0;
        for(int i = 0; i < n; i++){
            if(v[i]){
              tempvec[idx++] = *(container.begin() + i);     
            }
        }
        totvec.push_back(tempvec);

    }while(next_permutation(v.begin(), v.end() ) );

    return totvec;
}


int solution(vector<vector<string>> clothes) {
    int answer = 0;  
    int row_size = clothes.size();
  
    
    unordered_multiset<string> clothes_hash;

    for(int i = 0 ; i < row_size; i++){
        clothes_hash.insert(clothes[i][1]);
    }

    vector<int> v;
    unordered_multiset<string>::iterator temp = clothes_hash.begin();
    v.push_back(clothes_hash.count(*temp));
 
    for(unordered_multiset<string>::iterator it = clothes_hash.begin(); it != clothes_hash.end(); it++){
        
        if(*temp != *it)
            v.push_back(clothes_hash.count(*it));
        temp = it;
        
    }

for(int i = 0; i < v.size(); i++){
    for(auto & vec : combination(v, i+1)){
        int temp1 = 1;
        for( auto & ele : vec){
            temp1 = temp1*ele;
        }    
        answer = answer + temp1;  
    }
}
    return answer;
}