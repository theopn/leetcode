# My Leetcode Solutions

Here is the list of questions I solved along with the language(s) used and relevant topics.
Questions and solutions I believe to be important or unique are bolded.

There are detailed explanations in the [notes directory](./notes/).
It includes the explanations of my approach in English, Lua-style pseudocode, runtime analysis, and relevant programming language skills that could be used.

## Array String

- [88. Merge Sorted Array](./notes/0088-merge-sorted-arr.md) (Easy, Python): `Merge` subroutine from `MergeSort`
- [27. Remove Element](./notes/0027-remove-elem.md) (Easy, Java): Pointless question
- [26. Remove Duplicates from Sorted Array](./notes/0026-remove-dup-from-sorted-arr.md) (Easy, C++): Build-up for the 80.
- **80. Remove Duplicates from Sorted Array II [Medium, C++]**: Same as 26, but keep up to 2 duplicate elements. Modifying the template from 26:
    ```cpp
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }
        int pos = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[pos - 2]) {
                nums[pos] = nums[i];
                pos++;
            }
        }
        return pos;
    }
    ```
    Hopefully you get the logic for removing duplicates from an array, keeping up to $n$ number of same elements.
- **169. Majority Element [Easy, C++, Python]**: C++ solution is a simple solution using Hashmap.
    It checks if the current value is the majority after we increment the counter in the Hashmap.
    The Python code is something called "Boyer-Moore majority vote algorithm."
    It's quite nice.
- **189. Rotate Array [Medium, C++, Python]**: Python solution is the easy way of making a copy of the array and calculating a new index using modulus.
    C++ solution is more complicated, but easier way to think about rotating an array.
    - Consider `arr = [1 2 3 4 5 6 7]` and `rotated_by_3 = [5 6 7 1 2 3 4]`. At `k = 3`, you can separate the resultant array into `rotated_by_3 = [(5 6 7) (1 2 3 4)]`. `(5 6 7)` is `(7 6 5)` reversed and `(1 2 3 4)` is `(4 3 2 1)` reversed. Thus, reverse the whole array, and rotate sub-arrays to have the rotated array. For the implemented logic, look at my C++ solution.
    - I actually meant to do the above way in Python, but oh god, reversing a partial list is harder in Python. I somehow ended up with one-line, cryptic solution in Python. Here it is:
        ```python
        def rotate(self, nums: List[int], k: int) -> None:
            k = k % len(nums)
            nums[:] = nums[-k:] + nums[:-k]
        ```
- **121. Best Time to Buy and Sell Stock [Easy, Python]**: Very simple, Sliding Window-ish solution.
    Checking both the maximum profit and minimum element as you slide the window.
- **122. Best Time to Buy and Sell Stock II [Medium, Python]**: An approach that is very simple, once you wrap your head around it.
    You are buying it from yesterday and selling it today as long as it makes a positive profit.
- [55. Jump Game](./notes/0055-jump-game.md) (Medium, C++, Python): Two Pointers. Both solutions use the same logic.

## Two Pointers

- [125. Valid Palindrome](./notes/0125-valid-palindrome.md) (Easy, C++): Two Pointers
- **392. Is Subsequence [Easy, Python, C++]**: Straightforward, just keep the pointer to the subsequence.
- [167. Two Sum II - Input Array Is Sorted](./notes/0167-two-sum-ii-input-arr-is-sorted.md) (Medium, Python, C++): Two Pointers
- [11. Container With Most Water](./notes/0011-container-w-most-water.md) (Medium, Python): Two Pointers

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

## Intervals

## Stack

- [20. Valid Parentheses](./notes/0020-valid-paren.md) (Easy, C++): Stack operations, dictionary

## Linked List

- [**141. Linked List Cycle**](./notes/0141-linked-list-cycle.md) (Easy, C++, Python): Floyd's tortoise and hare algorithm
- [**2. Add Two Numbers**](./notes/0002-add-two-nums.md) (Medium, C++): Dummy node for return list
- [21. Merge Two Sorted Lists](./notes/0021-merge-two-sorted-lists.md) (Easy, C++): `Merge` algorithm from `MergeSort`, dummy node for return list
- [138. Copy List with Random Pointer](./notes/0138-cp-list-w-rand-ptr.md) (Medium, C++): Hashmap

## Binary Tree General

## Binary Tree BFS

## Graph General

## Graph BFS

## Trie

## Backtracking

## Divide & Conquer

## Kadane's Algorithm

## Binary Search

## Heap

- **215. Kth Largest Element in an Array [Medium, C++, Python, Java]**: There are three solutions.
    - Using a min-heap (cpp): Whenever the heap size exceeds k, remove the smallest element.
        After the loop, smallest element in the min-heap is the kth largest element.
        Pro tip: even though `std::priority_queue` is a max-heap, you can use it like a min-heap by multiplying -1 when pushing and popping.
    - `QuickSelect` (Python): Suppose we have the array `[6 5 2 1 4 3 4]`
        1. Randomly choose a pivot `nums[rand() % nums.len]`. Let's say we got 4 as our pivot
        2. Relative to the pivot, determine left, mid, and right array
            `left = [ 2 1 3 ]`, `mid = [4 4]`, `right = [6 5]`
            (We can do this in-place by swapping elements and keeping the index of `mid`, but it was too slow for some reason. Read my iPad notes)
        3. Forget about finding the kth largest, we are finding (n - k)th smallest.
            So if we are finding the 4th largest, we are in fact finding 7 - 4 = 3rd smallest
            (e.g., in `[1 2 3 4]`, 3 is the 2nd largest and 4 - 2 + 1 = 3rd smallest. But because of zero-indexing, we consider it to be 2nd smallest with 1 being the 0th smallest element).
        4. Let's say we are finding the 5th smallest (4). 3 elements in the `left`, 2 elements in the `mid`, so it has to be in the `mid` (i.e., pivot value).

            What about finding 0nd smallest (1)? Since the length of `left` is 3 and it only contains values smaller than the pivot, call `QuickSelect` on the `left` to find its 2nd smallest.

            What about finding 6th smallest (5)? Call `QuickSelect` on the right to find the 6th smallest... No! Find the 1st smallest in the `right`, where `1 = 6 - left.len - mid.len`.
    - Sorting and choosing (Java): `QuickSelect` was only 40% beat, so I did `Arrays.sort` and returned `nums[nums.length - k]`. 80% beat. Wtf.

## Bit Manipulation

## Math

## 1D DP

## Multidimensional DP

