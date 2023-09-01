class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        HashMap<Character, Integer> hashbrown = new HashMap<>();
        
        for (int i = 0; i < magazine.length(); i++) {
            hashbrown.put(magazine.charAt(i), hashbrown.getOrDefault(magazine.charAt(i), 0) + 1);
        }
        //for (char m : magazine.toCharArray()) {
        //    hashbrown.put(m, hashbrown.getOrDefault(m, 0) + 1);
        //}
        
        for (int i = 0; i < ransomNote.length(); i++) {
            if (hashbrown.getOrDefault(ransomNote.charAt(i), 0) == 0) {
                return false;
            }
            hashbrown.put(ransomNote.charAt(i), hashbrown.getOrDefault(ransomNote.charAt(i), 0) - 1);
        }
        //for (char r : ransomNote.toCharArray()) {
        //    if (hashbrown.getOrDefault(r, 0) == 0) {
        //        return false;
        //    }
        //    hashbrown.put(r, hashbrown.getOrDefault(r, 0) - 1);
        //}
        
        return true;
    }
}