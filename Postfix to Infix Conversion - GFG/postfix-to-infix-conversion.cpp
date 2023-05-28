//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   bool isOperand(char x){
       return (x>= 'a' && x<='z') || (x>='A' && x<= 'Z');
   }
    string postToInfix(string exp) {
        // Write your code here
        stack<string> s;
        
        for(int i=0; exp[i]!='\0'; i++){
            if(isOperand(exp[i]))
            {
                string op(1,exp[i]);
                s.push(op);
            }
            else
            {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + exp[i] +
                   op1 + ")");
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
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends