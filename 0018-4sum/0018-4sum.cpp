class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if(n<4) return ans;             //Return empty vector if there are not sufficient elements in input vector
        sort(nums.begin(), nums.end()); //Since the total TC would come out to be O(n^3), we know there would be no issue in useing sorting(takes nlogn i.e. < n^3)
        for(int i = 0; i<n-3; i++){     //This loop fixes the first element TC now becomes -> O(n)
            if(i>0 && nums[i]==nums[i-1]) continue; //This simply skips the iterations for duplicate values
            
            long long min1 = (long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3];        //This is first pruning/early-exit optimisation - explained above
            if(min1 > target) break;

            long long max1 = (long long)nums[i] + nums[n-3] + nums[n-2] + nums[n-1];        //2nd Pruning
            if(max1 < target) continue;

            int a = nums[i];    //Instead of look-up for value of nums[i] again and again in inner loop(of 2 ptr approach), we just kept a variable that stores its value for "this" iteration [YOU CAN SKIP USING THIS! JUST IN ALL INNER LOOPS USE "nums[i]" instead of "a", but that optimisation helps lower the runtime]
            for(int j = i+1; j<n-2; j++){       //This is the second loop for fixing second value TC now becomes O(n^2)
                
                if(j>i+1 && nums[j]==nums[j-1]) continue;   //For skipping duplicate values
                
                long long min2 = (long long)nums[i] + nums[j] + nums[j+1] + nums[j+2];      //3rd Pruning now for inner loop-> it just is a mathematical statement that guides early skips if the current iteration can't make up to target 
                if(min2 > target) break;

                long long max2 = (long long)nums[i] + nums[j] + nums[n-2] + nums[n-1];      //4th Pruning
                if(max2 < target) continue;
                
                int b = nums[j];    //Again storing another fixed value for reducing lookup times in inner while loop
                
                //Now what we have to do is just implement the 2 Sum problem using "long long rem" as "new target" for the 2 Sum
                long long rem = (long long)target - a - b;  
                int l = j+1, r = n-1;
                
                while(l<r){
                        long long sum = nums[l] + nums[r];
                        if(sum == rem){
                            ans.push_back({a,b,nums[l],nums[r]});
                            l++;
                            r--;
                            while(l<r && nums[l]==nums[l-1]) l++;   //These while loops just skip duplicates and move l,r till a diff value than the one just previous to it is reached -> since the vector is sorted, all duplicate values would reside side-by-side
                            while(l<r && nums[r]==nums[r+1]) r--;
                        }
                        else if(sum < rem) l++;
                        else r--;
                }
            }
        }
        return ans;
    }
};
//For a better understanding, dry run for -> nums   = [-2, -1, -1, 0, 1, 2, 2]
//target = 0