class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());

        int target = skill[0] + skill[n - 1];
        long long chemistry = 0;
        for (int lo = 0, hi = n - 1; lo < hi; lo++, hi--) {
            if (skill[lo] + skill[hi] != target) return -1;
            chemistry += skill[lo] * skill[hi];
        }

        return chemistry;
    }
};