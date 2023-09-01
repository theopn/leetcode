class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        HashMap<Character, Integer> hashbrown = new HashMap<>();

        for (char m : magazine.toCharArray()) {
            hashbrown.put(m, hashbrown.getOrDefault(m, 0) + 1);
        }
        
        for (char r : ransomNote.toCharArray()) {
            if (hashbrown.getOrDefault(r, 0) == 0) {
                return false;
            }
            hashbrown.put(r, hashbrown.getOrDefault(r, 0) - 1);
        }
        
        return true;
    }
}