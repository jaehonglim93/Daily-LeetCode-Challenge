class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        int count = 0;
        queue<int> line;
        
        for (int i = 0; i < tickets.size(); i++) {
            line.push(tickets[i]);
        }
        
        while (tickets[k] != 0) {
            
            if (line.front() != 0) {
                int temp = line.front() - 1; 
                line.pop();
                line.push(temp);
                time++;
            } else {
                int temp = line.front();
                line.pop();
                line.push(temp);
            }
            
            if (count == k) {
                tickets[k]--;
            }
        
            count++;
            
            if (count == tickets.size()) {
                count = 0;
            }
        }
        
        return time;
    }
};