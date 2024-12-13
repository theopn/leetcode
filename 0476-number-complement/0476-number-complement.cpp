class Solution {
public:
    int findComplement(int num) {
        // finds the bit length
        unsigned int bits = 0;
        for (unsigned int var = num; var != 0; bits++) var >>= 1;
        //unsigned int bits = int(log2(num)) + 1;

        // creates the bitmask of the given bit length
        unsigned int mask = (unsigned int)(1 << bits) - 1;

        // returns xor
        return num ^ mask;
    }
};