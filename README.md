# My Leetcode

- 88. Merge Sorted Array [Easy, Python]: I did something like the `Merge` algorithm from `MergeSort`, but because there's a space constraint (had to modify the array 1, which the spots for array 2 is filled with 0's), I started comparing from the larger element instead of smaller.
    And finally, if the pointer for the second array (`j`) still has numbers left, assign it to the first array.
    We don't have to worry about "leftover" `i` because the first array is what holds the final elements.
- 27. Remove Element [Easy, Java]: Use single pointer, loop through the element in `nums` and assign it in the pointer position.
    Pretty pointless question.
- 125. Valid Palindrome [Easy, C++]: I originally thought about using "Neetcode" method of going from the middle and check left and right element, but I was overcomplicating it.
    Simply use two pointers for the front and back, pass a character if it's not alphanumeric.

