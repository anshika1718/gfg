//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool  isOperator(char x){
      switch(x){
          case '+':
          case '-':
          case '/':
          case '*':
          case '^':
          case '%':
          return true;
       }
       return false;
  }
  
    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string> s;
        int length= pre_exp.size();
        for(int i=length-1;i>=0;i--){
            if(isOperator(pre_exp[i]))
            {
                string op1=s.top();
                s.pop();
                string op2=s.top();
                s.pop();
                
                string temp= "(" + op1 + pre_exp[i] + op2 + ")";
                s.push(temp);
            }
            else{
                s.push(string(1,pre_exp[i]));
            }
        }
        return s.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends