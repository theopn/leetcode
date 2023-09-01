# My Leetcode Solutions

Here are brief overviews of my solutions.
I take handwritten notes for all questions, and they contain more details.
Feel free to let me know if you need more explanation.

88. **Merge Sorted Array [Easy, Python]**: I did something like the `Merge` algorithm from `MergeSort`, but because there's a space constraint (had to modify the array 1, which the spots for array 2 is filled with 0's), I started comparing from the larger element instead of smaller.
        And finally, if the pointer for the second array (`j`) still has numbers left, assign it to the first array.
        We don't have to worry about "leftover" `i` because the first array is what holds the final elements.
27. **Remove Element [Easy, Java]**: Use single pointer, loop through the element in `nums` and assign it in the pointer position. Pretty pointless question.
125. **Valid Palindrome [Easy, C++]**: I originally thought about using "Neetcode" method of going from the middle and check left and right element, but I was overcomplicating it.
        Simply use two pointers for the front and back, pass a character if it's not alphanumeric.
215. **Kth Largest Element in an Array [Medium, C++, Python, Java]**: There are three solutions.
        - Using a min-heap (cpp): Whenever the heap size exceeds k, remove the smallest element.
        After the loop, smallest element in the min-heap is the kth largest element.
        Pro tip: even though `std::priority_queue` is a max-heap, you can use it like a min-heap by multiplying -1 when pushing and popping.
        - `QuickSelect` (Python): Suppose we have the array `[6 5 2 1 4 3 4]`
            1. Randomly choose a pivot `nums[rand() % nums.len]`. Let's say we got 4 as our pivot
            2. Relative to the pivot, determine left, mid, and right array
                `left = [ 2 1 3 ]`, `mid = [4 4]`, `right = [6 5]`
                (We can do this in-place by swapping elements and keeping the index of `mid`, but it was too slow for some reason. Read my iPad notes)
            3. Forget about finding the kth largest, we are finding (n - k)th smallest.
                So if we are finding the 4th largest, we are in fact finding 7 - 4 = 3rd smallest (e.g., in `[1 2 3 4]`, 3 is the 2nd largest and 4 - 2 + 1 = 3rd smallest. But because of zero-indexing, we consider it to be 2nd smallest with 1 being the 0th smallest element).
            4. Let's say we are finding the 5th smallest (4). 3 elements in the `left`, 2 elements in the `mid`, so it has to be in the `mid` (i.e., pivot value).

                What about finding 2nd smallest (3)? Since the length of `left` is 3 and it only contains values smaller than the pivot, call `QuickSelect` on the `left` to find its 2nd smallest.

                What about finding 6th smallest (6)? Call `QuickSelect` on the right to find the 6th smallest... No! Find the 1st smallest in the `right`, where `1 = 6 - left.len - mid.len`.
        - Sorting and choosing (Java): `QuickSelect` was only 40% beat, so I did `Arrays.sort` and returned `nums[nums.length - k]`. 80% beat. Wtf.
26. **Remove Duplicates from Sorted Array [Easy. C++]**: Here's the template for removing duplicate elements in an array:
    ```cpp
    int removeDuplicates(vector<int>& nums) {
        int pos = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[pos - 1]) {
                nums[pos] = nums[i];
                pos++;
            }
        }
        return pos;
    }
    ```
80. **Remove Duplicates from Sorted Array II [Medium, C++]**: Same as 26, but keep up to 2 duplicate elements. Modifying the template from 26:
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
383. **Ransome Note [Easy, C++, Python, Java]**: Really straightforward question, and I did all three languages to give you the example of hashmap.
    - C++: `std::unordered_map` is the hashmap with $O(1)$ average search, insertion, and deletion, time (16ms 63% beat for this q), and `std::map` is a self balanacing BST with `O(\log (n))` time (27ms 22% beat for this question). Also a nice thing, the default values of the `Operator` class will be initialized to zero, so no need to call default value method like with Python and Java.
    - Python: Use dictionary, and utilize `dict.get(key, default_value)` for the case where dictionary key hasn't been initialized
    - Java: Use `HashMap<Character, Integer>`. It looks the most disgusting.

