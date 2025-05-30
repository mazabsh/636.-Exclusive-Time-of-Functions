#include<iostream> 
#include<sstream> 
#include<cassert>
#include<stack> 
#include<vector> 

using namespace std; 

struct Log{
    int id; 
    string status; 
    int timestamp; 
};
class Solution{
public: 
      vector<int> exclusiveTime(int n, vector<string>& logs){
         stack<Log> st; 
         vector<int> res(n,0); 
         for(auto log:logs){
           stringstream ss(log); 
           string temp, temp2, temp3; 
           getline(ss, temp, ':'); 
           getline(ss, temp2, ':'); 
           getline(ss, temp3, ':'); 
           Log item={stoi(temp), temp2, stoi(temp3)}; 
           if(item.status=="start"){
             st.push(item); 
           }else{
             assert(st.top().id==item.id); 
             int timeadded = (item.timestamp-st.top().timestamp)+1; 
             res[item.id]+=timeadded; 
             st.pop(); 
             if(!st.empty()){
               assert(st.top().status=="start"); 
               res[st.top().id] -=timeadded; 
             }
           }
         }
         return res; 
      }
}; 
int main(){
  vector<string> logs = {"0:start:0" , "1:start:2", "1:end:5", "0:end:6"}; 
  int n =2; 
  Solution sol; 
  vector<int> res = sol.exclusiveTime(n, logs); 
  for(int num:res){
    cout << num << " , " << endl; 
  }
  return 0; 
}
