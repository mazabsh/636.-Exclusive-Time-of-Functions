#include<iostream> 
#include<sstream> 
#include<cassert>
#include<stack> 
#include<vector> 

using namespace std; 

;
class Solution{
public: 
      vector<int> exclusiveTime(int n, vector<string>& logs){
         vector<int> result(n, 0);
         stack<int> st;
         int prevTime = 0;

         for (const string& log : logs) {
            
            stringstream ss(log);
            string idStr, typeStr, timeStr;
            getline(ss, idStr, ':');
            getline(ss, typeStr, ':');
            getline(ss, timeStr, ':');

            int id = stoi(idStr);
            int time = stoi(timeStr);

            if (typeStr == "start") {
                if (!st.empty()) {
                    result[st.top()] += time - prevTime;
                }
                st.push(id);
                prevTime = time;
            } else { // "end"
                result[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }

        return result;
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
