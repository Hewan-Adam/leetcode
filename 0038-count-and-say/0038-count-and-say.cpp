class Solution {
public:
    
    string solve(string ans){
        int count=1;
        int n=ans.size();
        int i=1;
        string newStr="";

        while(i<n){
            if(ans[i-1]==ans[i])
            {
                i++;
                count++;
            }
            else{
                newStr+=(to_string(count)+ans[i-1]);
                count=1;
                i++;
            }
        }
       newStr+=(to_string(count)+ans[n-1]);
      return newStr;  
    }
    
    string countAndSay(int n) {
    string ans="1";

    for(int i=2;i<=n;i++){
        ans=solve(ans);
    }
    return ans;
    }
};