#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    unordered_multiset<string> partmap;
    for(int i = 0; i < participant.size(); i++){
        partmap.insert(participant[i]);
    
    }
    for(int i = 0; i < completion.size(); i++){
        auto temp = partmap.find(completion[i]);
        if(temp != partmap.end())
            partmap.erase(temp);
       
    }
    
    auto it =  partmap.begin();
    string answer(*it);
    return answer;
}