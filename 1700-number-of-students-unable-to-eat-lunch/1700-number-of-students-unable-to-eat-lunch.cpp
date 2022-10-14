class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zeroCount = 0;
        int oneCount = 0;
        queue<int> studentQueue;
        stack<int> sandwichStack;
        
        for (int i = 0; i < students.size(); i++) {
            studentQueue.push(students[i]);
            if (students[i] == 0) {
                zeroCount++;
            } else {
                oneCount++;
            }
        }
        
        for (int i = sandwiches.size() - 1; i >= 0; i--) {
            sandwichStack.push(sandwiches[i]);
        }
        
        while (!studentQueue.empty() && !sandwichStack.empty()) {
            if (sandwichStack.top() == 0) {
                if (zeroCount == 0) {
                    break;
                }
            } else {
                if (oneCount == 0) {
                    break;
                }
            }         
            if (studentQueue.front() == sandwichStack.top()) {
                if (studentQueue.front() == 0) {
                    zeroCount--;
                } else {
                    oneCount--;
                }
                studentQueue.pop();
                sandwichStack.pop();
            } else {
                int temp = studentQueue.front();
                studentQueue.pop();
                studentQueue.push(temp);
            }
        }
           
        return studentQueue.size();
    }
};