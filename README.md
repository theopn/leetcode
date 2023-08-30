# My Leetcode Solutions

Here are brief overviews of my solutions.
I take handwritten notes for all questions, and they contain more details.
Feel free to let me know if you need more explanation.

88. **Merge Sorted Array [Easy, Python]**: I did something like the `Merge` algorithm from `MergeSort`, but because there's a space constraint (had to modify the array 1, which the spots for array 2 is filled with 0's), I started comparing from the larger element instead of smaller.
  And finally, if the pointer for the second array (`j`) still has numbers left, assign it to the first array.
  We don't have to worry about "leftover" `i` because the first array is what holds the final elements.
27. **Remove Element [Easy, Java]**: Use single pointer, loop through the element in `nums` and assign it in the pointer position.
  Pretty pointless question.
125. **Valid Palindrome [Easy, C++]**: I originally thought about using "Neetcode" method of going from the middle and check left and right element, but I was overcomplicating it.
    Simply use two pointers for the front and back, pass a character if it's not alphanumeric.
215. **Kth Largest Element in an Array [Medium, C++]**: A simple solution (the question states not to sort the array) using min-heap.
    Pro tip: even though `std::priority_queue` is a max-heap, you can use it like a min-heap by multiplying -1 when pushing and popping.
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

