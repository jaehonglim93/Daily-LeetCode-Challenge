class Solution {
    public String sortSentence(String s) {
        String[] original = s.split(" ");
        String[] result = new String[original.length];
        for (String str : original) {
            int i = str.length() - 1;
            result[str.charAt(i) - '1'] = str.substring(0, i);
        }
        return String.join(" ", result);
    }
}