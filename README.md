# My Leetcode Solutions

Here is the list of questions I solved along with the language(s) used and relevant topics.
Questions and solutions I believe to be important or unique are bolded.

There are detailed explanations in the [notes directory](./notes/).
It includes the explanations of my approach in English, Lua-style pseudocode, runtime analysis, and relevant programming language skills that could be used.

I prioritize approaching questions algorithmically.
But I also love Python one liners.

## Array/String

- [88. Merge Sorted Array](./notes/0088-merge-sorted-arr.md) (Easy, Python): `Merge` subroutine from `MergeSort`
- [27. Remove Element](./notes/0027-remove-elem.md) (Easy, Java): Pointless question
- [26. Remove Duplicates from Sorted Array](./notes/0026-remove-dup-from-sorted-arr.md) (Easy, C++): Build-up for the 80.
- [**80. Remove Duplicates from Sorted Array II**](./notes/0080-remove-dup-from-sorted-arr-ii.md) (Medium, C++): Remove dup template
- [**169. Majority Element**](./notes/0169-majority-elem.md) (Easy, C++, Python): Hashmap (C++), Boyer-Moore majority vote algorithm (Python)
- [**189. Rotate Array**](./notes/0189-rotate-arr.md) (Medium, C++, Python): Modulus (Python), Array reversal (C++)
- [**121. Best Time to Buy and Sell Stock**](./notes/0121-best-time-to-buy-and-sell-stock.md) (Easy, Python, C++): Sliding window, Kadane's Algorithm
- [122. Best Time to Buy and Sell Stock II](./notes/0122-best-time-to-buy-and-sell-stock-ii.md) (Medium, Python): Greedy algorithm
- [55. Jump Game](./notes/0055-jump-game.md) (Medium, C++, Python): Two Pointers. Both solutions use the same logic.
- [45. Jump Game II](./notes/0045-jump-game-ii.md) (Medium, C++, Python): Two Pointers, DP
- [274. H-Index](./notes/0274-h-idx.md) (Medium, C++, Python): Array sorting //TODO
- [380. Insert Delete GetRandom O(1)]() (Medium, Python): OOP, random //TODO
- [**238. Product of Array Except Self**](./notes/0238-prod-of-arr-except-self.md) (Medium, Python): Prefix sum

## Two Pointers

- [125. Valid Palindrome](./notes/0125-valid-palindrome.md) (Easy, C++): Two Pointers
- **392. Is Subsequence [Easy, Python, C++]**: Straightforward, just keep the pointer to the subsequence.
- [167. Two Sum II - Input Array Is Sorted](./notes/0167-two-sum-ii-input-arr-is-sorted.md) (Medium, Python, C++): Two Pointers
- [11. Container With Most Water](./notes/0011-container-w-most-water.md) (Medium, Python): Two Pointers
- [15. 3Sum](./notes/0015-3sum.md) (Medium, Python): Two pointers, Array sorting, Set

## Sliding Window

- **209. Minimum Size Subarray Sum [Medium, C++, Java, Python]**: Classic Sliding Window problem. Read the comment on the C++ code.
- [**3. Longest Substring Without Repeating Characters**](./notes/0003-longest-substr-wo-repeating-char.md) (Medium, C++): Sliding window, Hashmap
- [30. Substring with Concatenation of All Words](./notes/0030-substr-w-concate-of-all-words.md) (Hard, Python): Sliding Window, Hashmap, Substring

## Matrix

## Hashmap

- **383. Ransome Note [Easy, C++, Python, Java]**: Really straightforward question, and I did all three languages to give you the example of hashmap.
    - C++: `std::unordered_map` is the hashmap with $O(1)$ average search, insertion, and deletion, time (16ms 63% beat), and `std::map` is a self balanacing BST with $O(\log (n))$ time (27ms 22% beat).
        Also one nice thing, the default values of the `Operator` class will be initialized to zero, so no need to call default value method like with Python and Java.
    - Python: Use dictionary, and utilize `dict.get(key, default_value)` for the case where dictionary key hasn't been initialized
    - Java: Use `HashMap<Character, Integer>`. It looks disgusting.
- [205. Isomorphic Strings](./notes/0205-isomorphic-str.md) (Easy, Python, C++): Hashmap, checking if key exists
- [290. Word Pattern](./notes/0290-word-patt.md) (Easy, C++): Hashmap, checking if key exists
- [242. Valid Anagram](./notes/0242-valid-anagram.md) (Easy, Python): Python one-liner
- [**49. Group Anagrams**](./notes/0049-group-anagrams.md) (Medium, Python): Hashmap, string hashmap
- [1. Two Sum](./notes/0001-two-sum.md) (Easy, C++): Hashmap
- [202. Happy Number](./notes/0202-happy-num.md) (Easy, C++, Python): Hashmap, Floyd's tortoise and hare algorithm
- [219. Contains Duplicate II](./notes/0219-contain-dup-ii.md) (Easy, Python): Hashmap

## Intervals

- [228. Summary Ranges](./notes/0228-summary-ranges.md) (Easy, C++): String appending

## Stack

- [20. Valid Parentheses](./notes/0020-valid-paren.md) (Easy, C++): Stack operations, dictionary
- [71. Simplify Path](./notes/0071-simplify-path.md) (Medium, Python): Stack, string split

## Linked List

- [**141. Linked List Cycle**](./notes/0141-linked-list-cycle.md) (Easy, C++, Python): Floyd's tortoise and hare algorithm
- [**2. Add Two Numbers**](./notes/0002-add-two-nums.md) (Medium, C++): Dummy node for return list
- [21. Merge Two Sorted Lists](./notes/0021-merge-two-sorted-lists.md) (Easy, C++): `Merge` algorithm from `MergeSort`, dummy node for return list
- [138. Copy List with Random Pointer](./notes/0138-cp-list-w-rand-ptr.md) (Medium, C++): Hashmap

## Binary Tree General

- [104. Maximum Depth of Binary Tree](./notes/0104-max-depth-of-binary-tree.md) (Easy, Python, C++): Recursive DFS (Python), iterative BFS using queue (C++) // TODO
- [100. Same Tree](./notes/0100-same-tree.md) (Easy, C++, Python): Recursive DFS (C++), iterative BFS using queue (Python)
- [226. Invert Binary Tree](./notes/0226-invert-binary-tree.md) (Easy, C++, Python): Tree traversal, recursion, DFS (stack), BFS (queue)
- [101. Symmetric Tree](./notes/0101-symmetric-tree.md) (Easy, Python): Recursive DFS

## Binary Tree BFS

## Graph General

## Graph BFS

## Trie

## Backtracking

## Divide & Conquer

## Kadane's Algorithm

## Binary Search

- [35. Search Insert Position](./notes/0035-search-ins-pos.md) (Easy, C++): Binary search

## Heap

- [**215. Kth Largest Element in an Array**](./notes/0215-kth-largest-elem-in-an-arr.md) (Medium, C++, Python, Java): Min-heap (C++), QuickSelect (Python), array sorting (Java)

## Bit Manipulation

- [**67. Add Binary**](./notes/0067-add-binary.md) (Easy, C++): Binary addition, casting
- [136. Single Number](./notes/0136-single-num.md) (Easy, C++): XOR

## Math

- [9. Palindrome Number](./notes/0009-palindrome-num.md) (Easy, Python, C++): Python one-liner

## 1D DP

- [**70. Climbing Stairs**](./notes/0070-climbing-stairs.md) (Easy, C++, Python): Tabulation
- [**198. House Robber**](./notes/0198-house-robber.md) (Medium, C++): Tabulation
- [139. Word Break](./notes/0139-word-break.md) (Medium, Python): Tabulation, Substring

## Multidimensional DP

