#include<bits/stdc++.h>

using namespace std;

int distinctSubsequences(string &s){
        vector<int> last(256,-1);
        
        int n = s.length();
        
        int dp[n+1];
        
        dp[0] = 1;
        
        for(int i = 1;i<=n;i++){
            dp[i] = 2 * dp[i-1];
            
            
            if(last[s[i-1]]!=-1){
                dp[i] = dp[i] - dp[last[s[i-1]]];
            }
            
            last[s[i-1]] = i - 1; 
        }
        
        return dp[n];
    }

int main(){

  return 0;
}
