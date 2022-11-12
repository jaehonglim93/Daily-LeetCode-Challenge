class Solution {
    public boolean checkIfPangram(String sentence) {
        
        if (sentence.length() < 26) {
            return false;
        }
        
        HashMap<Character, Integer> map = new HashMap<>();
        char j = 'a';
        
        for (int i = 0; i < 26; i++) {
            map.put(j, 0);
            j++;
        }
        
        for (int i = 0; i < sentence.length(); i++) {
            map.put(sentence.charAt(i), map.get(sentence.charAt(i)) + 1);
        }
        
        j = 'a';
        
        for (int i = 0; i < map.size(); i++) {
            if (map.get(j) == 0) {
                return false;
            }
            j++;
        }
        
        return true;
    }
}