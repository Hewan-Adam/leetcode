using int4=array<uint8_t, 4>;
constexpr int4 ONE{};
int4 PF[11];
class Solution {
public:
    inline static int4 exp(unsigned x){
        uint8_t e2=0, e3=0, e5=0, e7=0;
        e2=countr_zero(x);
        x>>=e2;
        while (x%3==0) {x/=3; e3++;}
        while (x%5==0) {x/=5; e5++;}
        while (x%7==0) {x/=7; e7++;}
        return int4({e2, e3, e5, e7});
    }
    static void computePF(){
        if (PF[2]!=ONE) return;// compute once
        for(int x=2; x<=10; x++){
            PF[x]=exp(x);
        }
    }
    static int4 GCD(int4& x, int4& y){
        return int4({min(x[0], y[0]), min(x[1], y[1]),\
         min(x[2], y[2]), min(x[3], y[3])});
    }
    static inline int4 expAdd(const int4 x, const int4 y, bool add=1){
        int4 ans=x;
        for (int i=0; i<4; i++)
            ans[i]+=(add)?y[i]:-y[i];
        return ans;
    }
    static int maxLength(vector<int>& nums) {
        computePF();
        int cnt=2, n=nums.size();
        int4 P=ONE;
        for(int l=0, r=0; r<n; r++){
            int4 x=PF[nums[r]];
            for(; GCD(x, P)!=ONE; l++) 
                P=expAdd(P, PF[nums[l]],0);
            P=expAdd(P, x);
            cnt=max(cnt, r-l+1);
        }
        return cnt;
    }
};