class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26, 0);
        for(char c: word){
            mp[c-'a']++;
        }

        vector<pair<int,char>> f(26);
        for(int i=0; i<26; i++){
            f[i]={mp[i], 'a'+i};
        }

        sort(f.begin(), f.end(), [](const auto& a, const auto& b){
            return a.first > b.first;
        });

        int n=word.size();
        int ans=0;
        int cnt=0;
        int add=1;
        
        for(auto [fq, ch]: f){
            if(fq == 0) break;
            cnt++;
            ans+=(add*fq);
            if(cnt == 8){
                cnt=0;
                add++;
            }
        }

        return ans;
    }
};