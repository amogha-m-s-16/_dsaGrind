class Solution {
private:
    vector<int> findNSE(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> st;

        for(int i = nums.size() - 1; i >= 0; i--) {

            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();

            ans[i] = st.empty() ? nums.size() : st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> findNGE(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> st;

        for(int i = nums.size() - 1; i >= 0; i--) {

            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();

            ans[i] = st.empty() ? nums.size() : st.top();

            st.push(i); 
        }

        return ans;
    }

    vector<int> findPSEE(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> st;

        for(int i = 0; i < nums.size(); i++) {

            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();

            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> findPGEE(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> st;

        for(int i = 0; i < nums.size(); i++) {

            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();

            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return ans;
    }

public:
    long long subArrayMax(vector<int>& nums) {
        vector<int> nextGE = findNGE(nums);
        vector<int> prevGEE = findPGEE(nums);

        long long sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            long long left = i - prevGEE[i];
            long long right = nextGE[i] - i;

            long long val = (left * right) * nums[i];

            sum += val;
        }

        return sum;
    }

    long long subArrayMin(vector<int>& nums) {
        vector<int> nextSE = findNSE(nums);
        vector<int> prevSEE = findPSEE(nums);

        long long sum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            long long left = i - prevSEE[i];
            long long right = nextSE[i] - i;

            long long val = (left * right) * nums[i];

            sum += val;
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return subArrayMax(nums) - subArrayMin(nums);
    }
};