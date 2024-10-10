# Leetcode Questions I Have Solved

These are (most of) the Leetcode questions I have solved.
I mainly use C++ and Python.
In fact, I think I exclusively use C++ and Python.

In this README file, you can find key idea and step-by-step instruction on how I approached the questions.
I also included templates for commonly used/important algorithms.
Bolded are ones I thought were interesting and worth revisiting.
Strikethrough are ones I thought were trivial.

In the [Top Interview 150](./top-interview-150) directory, you can see my solutions from 2023 when I attempted to complete [Top Interview 150](https://leetcode.com/studyplan/top-interview-150/) problem set (spoilers alert: I failed).
I would trust solutions in this directory more since they are more recent and I hopefully developed a better problem solving skill over time.

The solutions are uploaded using [LeetHub v2](https://github.com/arunbhardwaj/LeetHub-2.0).

## Substring & Subarray

- ~3110. Score of a String~ (Easy, 2024-06-01 Daily Q): Iterate [0, n - 1) and accumulate abs(s[i] - s[i + 1])
- ~344. Reverse String~ (Easy, 2024-06-02 Daily Q): Iterate [0, floor(n / 2) and swap s[n - i -1] and s[i]

## Sorting

- ~1051. Height Checker~ (Easy, 2024-06-10 Daily Q): Sort, check if heights[i] == sorted[i]
- **1122. Relative Sort Array** (Easy, 2024-06-11 Daily Q)
    - Use a modified counting sort
    1. Find the maximum in `arr1` (call it `k`)
    2. Find the `count` array of size `k + 1` with the count of each element in `arr1`
    3. Instead of prefix sum like in , we use `arr2` to populate `arr1`
    4. Iterate through elements in `arr2`
    5. While `count[arr2[i]]` is greater than 0, decrement the count and append `arr2[i]` to the output
    6. To append any remaining element, iterate `[0, k]` and append `i` with `count[i]` greater than 0

## Tree

- **1038. Binary Search Tree to Greater Sum Tree** (Medium, 2024-06-25 Daily Q)
    1. Define a global variable (or a parameter of a helper function) for `sum`
    2. Define a helper function that traverses tree in reverse in-order (RNL, as usual, base case when root is null)
    3. Sum the `node.val` to the `sum` in each recursion and assign it to node
- **1382. Balance a Binary Search Tree** (Medium, 2024-06-26 Daily Q)
    - In-order traversal of BST gives you the sorted array
    1. Run the in-order traversal to get the sorted value
    2. Build a helper that takes the sorted array, `lo`, and `hi` value and returns a `TreeNode`
    3. The base case is when `lo > hi`
    4. Calculate `mid = floor((lo + hi) / 2)`
    5. Make a new node with `arr[mid]` as its value
    6. Recursively call the helper with `lo` and `mid - 1` . assign the result to `node.left`
    7. Recursively call the helper with `mid + 1` and `hi`, assign the result to `node.right`
    8. Return the `node`
    9. Call this helper with `0` and the size of sorted array minus 1 in the main function

## Graph

- 1791. Find Center of Star Graph (2024-06-27 Daily Q)
    - Key point 1: non-center node should not appear more than once in the `edges`
    - Key point 2: the center node is either `edges[n][0]` or `edges[n][1]`
    - Compare `edges[0][0]` with `edges[1][0]` and `edges[1][1]`. If it matches either of them, it is the center
    - Otherwise, `edges[0][1]` is the center node


<!---LeetCode Topics Start-->
# LeetCode Topics
## String
|  |
| ------- |
| [0344-reverse-string](https://github.com/theopn/leetcode/tree/master/0344-reverse-string) |
| [3379-score-of-a-string](https://github.com/theopn/leetcode/tree/master/3379-score-of-a-string) |
## Two Pointers
|  |
| ------- |
| [0344-reverse-string](https://github.com/theopn/leetcode/tree/master/0344-reverse-string) |
<!---LeetCode Topics End-->
