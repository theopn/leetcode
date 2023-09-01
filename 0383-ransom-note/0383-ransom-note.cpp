class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> hashbrown;
        for (auto m : magazine) {
            hashbrown[m]++;
        }
        
        for (auto r : ransomNote) {
            if (hashbrown[r] == 0) {
                return false;
            }
            hashbrown[r]--;
        }
        
        return true;
    }
};