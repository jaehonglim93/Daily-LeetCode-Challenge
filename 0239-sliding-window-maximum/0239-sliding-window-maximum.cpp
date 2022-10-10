class Monoqueue {
    deque<int> list;
    
    public:
        void push(int n) {
            while(!list.empty() && list.back() < n) {
                list.pop_back();
            }
            list.push_back(n);
        }
    
        int front() {
            return list.front();
        }
    
        void pop(int n) {
            if (n == list.front()) {
                list.pop_front();   
            }
        }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Monoqueue list;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i < k - 1) {
                list.push(nums[i]);
            } else {
                list.push(nums[i]);
                result.push_back(list.front());
                list.pop(nums[i - k + 1]);
            }
        }
        
        return result;
    }
};