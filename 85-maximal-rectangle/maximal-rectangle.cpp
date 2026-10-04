class Solution {
private:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                int ele = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxArea = max(maxArea, arr[ele] * (nse - pse - 1));
            }

            st.push(i);
        }

        while(!st.empty()) {
            int ele = st.top();
            st.pop();

            int nse = arr.size();
            int pse = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, arr[ele] * (nse - pse - 1));
        }

        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        vector<int> preSum(matrix[0].size(), 0);

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == '1') preSum[j] += 1;
                else preSum[j] = 0;
            }

            maxArea = max(maxArea, largestRectangleArea(preSum));
        }

        return maxArea;

    }
};