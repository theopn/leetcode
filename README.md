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

## Daily Question Status

- June 2024: 7/30
- July 2024: 12/31
- August 2024: 15/31
- September 2024: 20/30

## Array

- ~~1550. Three Consecutive Odds~~ (Easy, 2024-07-01 Daily Q): Iterate the array while keeping the consecutive odd count, return if the count is 3

## Substring & Subarray

- ~~3110. Score of a String~~ (Easy, 2024-06-01 Daily Q): Iterate [0, n - 1) and accumulate abs(s[i] - s[i + 1])
- ~~344. Reverse String~~ (Easy, 2024-06-02 Daily Q): Iterate [0, floor(n / 2) and swap s[n - i -1] and s[i]
- 1395\. Count Number of Teams (Medium 2024-07-29 Daily Q)
    1. Iterate from `0` to `n -1` , let the current index be `j`
    2. At `j`, find the number of elements smaller/greater than `rating[j]` in (0, j] (”left” of `j`. You can find one of them and subtract it from `j` to find the other since all elements are unique)
    3. At `j`, find the number of elements smaller/greater than `rating[j]` in [j + 1, n) (”right” of `j`. You can find one of them and subtract it from `n - 1 - j` to find the other since all elements are unique)
    4. Multiplying the number of elements smaller than `rating[j]` in (0, j] to the number of elements greater than `rating[j]` in [j + 1, n) gives you the permutation of strictly increasing sub-sequence when we fix the middle element to `rating[j]`
    5. Multiplying the rest two gives you the permutation of strictly decreasing sub-sequence
    6. Add those two the total number of `sub-sequences` at each `j`
- 1508\. Range Sum of Sorted Subarray Sums (Medium, 2024-08-04 Daily Q):
    - Brute force works
    1. Build an array for subarray sums (size `n * (n + 1) / 2`)
    2. Sort the subarray sum array
    3. Iterate `[left - 1, right)`, accumulate `(accumulated_sum + subarraySum[i] % (1e9 + 7)` to prevent overflow
- ~~1945. Sum of Digits of String After Convert~~ (Easy, 2024-09-03 Daily Q): Follow the direction
- 884\. Uncommon Words from Two Sentences (Easy, 2024-09-17 Daily Q):
    1. add every space-separated words to the counter
    2. iterate over the counter and return unique words (count 1)
- 1813\. Sentence Similarity III (Medium, 2024-10-06 Daily Q):
    1. Tokenize `sentence1` and `sentence2`. Let the arrays containing tokenized words be `words1` and `words2`
    2. Let `m = words1.size`, `n = word2.size`
    3. Count the number of the common prefix words (for [0, `min(m, n)`), count until `words1[i] != words2[i]`
    4. Count the number of the commn suffix words (initialize `i = m - 1, j = n - 1`, iterate while `i >= 0 and j >= 0 and words1[i] == words2[j]`)
    5. If the sum of two counts are equal to the length of the shorter string, it means the shorter string is the combination of the common prefix and the common suffix. If the sum is greater than the length of the shorter string, the common prefix and suffix overlaps (e.g., `aaa` and `aaaa`). Either way, they can have words inserted in the middle and form the longer sentence
- 1545\. Find Kth Bit in Nth Binary String (Medium, 2024-10-19 Daily Q):
    - Brute force works
    1. Initialize `s` as `"0"`
    2. Iterate `i = [1, n)`, append `"1"` and save the string to `tmp`
    3. From `j = [tmp.len - 2, 0]`, append `"1"` to the `s` if `tmp[j] == 0` , `"0"` otherwise
    4. Break out of the loop if the current length of the `s` is greater than `k`

## Hash Table

- ~~350. Intersection of Two Arrays II~~ (Easy, 2024-07-02 Daily Q): Make a Counter hash table of one array, iterate through the others and add elements in the table. Decrement the count
- ~~1460. Make Two Arrays Equal by Reversing Subarrays~~ (Easy, 2024-08-03 Daily Q): This is only possible when two arrays have the same members, so… choose sorted, Counter, hash table, or whichever way is the most convenient for you.
- ~~2053. Kth Distinct String in an Array~~ (Easy, 2024-08-05 Daily Q): Build a hash table/Counter mapping the frequency of each string, and iterate through the arr and find kth distinct string
- ~~1. Two Sum~~ (Easy, 2024-08-27 Daily Q, but it was originally 1514. Path with Maximum Probability): Build a hash table for `num[i]` to `i`, iterate through the nums and check if target - nums[i] exists
- 1684\. Count the Number of Consistent Strings (Easy, 2024-09-12 Daily Q): build a hash table (or even better, boolean array of size 26) and count number of “consistent” strings
- 1331\. Rank Transform of an Array (Easy, 2024-10-02 Daily Q):
    1. Define a hash table `ranks` and iterate the sorted copy of `arr`. Define a variable `rank` initialized to 1
    2. If `ranks[sorted_arr_copy[i]]` is nil or 0, assign `rank` to it and increment `rank` . If the hash table already contains value at the given index, it means that the number is not unique; do nothing
    3. Define a new array and assign `rank[arr[i]]`
- 2501\. Longest Square Streak in an Array (Medium, 2024-10-28 Daily Q):
    1. Define a set of all elements in the array
    2. Iterate through the `num in nums` , set the current `num` to the starting point (variable named `curr`
    3. Iterate until we find the `curr^2` in the set. If found, update `curr` to `curr^2`
    4. If `curr^2` becomes larger than 1e5, break out of the loop
    5. Record the number of iteration as `streaks` . Keep track of max `streaks`

## Sorting

- ~~1051. Height Checker~~ (Easy, 2024-06-10 Daily Q): Sort, check if heights[i] == sorted[i]
- **1122. Relative Sort Array** (Easy, 2024-06-11 Daily Q)
    - Use a modified counting sort
    1. Find the maximum in `arr1` (call it `k`)
    2. Find the `count` array of size `k + 1` with the count of each element in `arr1`
    3. Instead of prefix sum like in , we use `arr2` to populate `arr1`
    4. Iterate through elements in `arr2`
    5. While `count[arr2[i]]` is greater than 0, decrement the count and append `arr2[i]` to the output
    6. To append any remaining element, iterate `[0, k]` and append `i` with `count[i]` greater than 0
- 2418\. Sort the People (Easy, 2024-07-22 Daily Q)
    1. Follow the standard quick sort template above, but take an extra parameter `names` along with `heights`
    2. All comparisons are done with `heights`, but also make `leftNames`, `midNames` , and `rightNames`, and whenever we append `height[i]` to `left` , `mid`, or `right`, append `names[i]` to the corresponding arrays
    3. Since we are sorting in reverse order, return `quicksort(right, rightNames + midNames + quicksort(left, leftNames)`
- **1636. Sort Array by Increasing Frequency** (Easy, 2024-07-23 Daily Q)
    - Make a counter and use a built-in sorting algorithm with lambda comparator. A worthy practice
- **912. Sort an Array** (Medium, 2024-07-25 Daily Q)
    - Either merge sort or RANDOMIZED quick sort works. A good practice to learn efficient sorting algorithms
- 179\. Largest Number (Medium, 2024-09-18 Daily Q):
    - Run merge sort in the string-ified nums array, but let the condition in the merge algorithm be `if int(l[i] + r[j]) > int(r[j] + l[i])` . It is because if `a..b > b..a and b.. c > c .. b` then `a..c > c..a` (transitivity). So if `l[i]..r[j] > r[j]..l[i]`, then `l[i]` should come before `r[j]`.

## Linked List

- 2181\. Merge Nodes in Between Zeros (Medium, 2024-07-04 Daily Q)
    - You can modify the existing list (see the C++ solution), but I find making a new list much easier
    1. Create a sentinel node and make a copy of it for the return value
    2. Iterate through the list. If the value is 0, set the next of sentinel to the accumulated sum so far
    3. Else, accumulate the value
    4. Return `sentinel_save.next.next` since they do not want the first 0 in the list
- **3217. Delete Nodes From Linked List Present in Array** (Medium, 2024-09-06 Daily Q):
    - This is a great question to practice singlely LL deletion and utilization of sentinel node for bulk deletion
    1. Define a hash table or set for the array elements
    2. Define a sentinel node and let `sentinel.next` be the head. Also let the `curr` be the sentinel
    3. Iterate while `curr.next` exists
    4. If `curr.next.val` is in the array elements, delete the node (`temp = curr.next; curr.next = curr.next.next; delete tmp`)
    5. If no element is deleted, regularly traverse the list
    6. Return `sentinel.next`
- **2807. Insert Greatest Common Divisors in Linked List** (Medium, 2024-09-10 Daily Q):
    1. Traverse until `node.next` exists
    2. get the GCD of `node` and `node.next`
    3. insert the new GCD node

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
- **2196. Create Binary Tree From Descriptions** (Medium, 2024-07-15 Daily Q)
    1. Create two hash tables, one that maps integer (value of the node) to a `TreeNode` object, and one that maps integer (value of the node) to a boolean to track if it is a child of another node
    2. Iterate through the `descriptions`
    3. If the parent node value does not exist in the hash table, make a new one and add it to the table
    4. If the child node value does not exist in the hash table, make a new one and add it to the table
    5. Set the child node according to the `isLeft` value
    6. Add the child node to the `isChild` hash table
    7. Once we are done creating a tree, iterate through the `parent` of the `descriptions` again. Look for a node where `isChild[parent] == false`, because the root is not a child of any node
- 145\. Binary Tree Postorder Traversal (Easy, 2024-08-25 Daily Q): LRN
- 590\. N-ary Tree Postorder Traversal (Easy, 2024-08-26 Daily Q):
    - Remember that postorder in binary tree is LRN, meaning in n-ary tree, we can visit children node in order then visit the node
- **1367. Linked List in Binary Tree** (Medium, 2024-09-07 Daily Q):
    1. Define a DFS algorithm where a) if we run out of LL nodes, since it means the entire LL is present in the tree, return true b) if we run out of tree nodes, return false, since we reach the leaf without matching the LL fully c) check if the values of the LL node and tree node match d) if so, recursively return DFS(next LL node, left children of the tree node) OR DFS(next LL node, right children of the tree node)
    2. In the main function, if root is not null, call DFS on the current tree node and LL head
    3. If that did returns false, recursively return MAIN(LL head, left children of the tree node) OR MAIN(LL head, right children of the tree node)
- 2583\. Kth Largest Sum in a Binary Tree (Medium, 2024-10-22 Daily Q):
    - DFS approach; barely avoids TLE with C++ loop unrolling and the`sync_with_stdio` tricks
    1. Define a global hashmap `levelSumMap`  and a helper function `getLevelSum` that takes `node, currLevel` as arguments. If `node` is nil, return. Accumulate `node.val` to `levelSumMap[currLevel]`. Recursively call `getLevelSum` with `node.left and right, currLevel + 1`
    2. Call `getLevelSum` with `currLevel == 1` in the main function
    3. Define a max-heap and push the values of `levelSumMap` to it
    4. Pop `k - 1` times, if the heap becomes empty while popping, return -1. Return the top element of the heap
    - BFS approach; much faster
    1. Follow the BFS (level order traversal) template above
    2. If the size of priority queue is less than `k`, return -1
    3. Pop the priority queue `k - 1` time and return the top element
- 951. Flip Equivalent Binary Trees (Medium, 2024-10-24 Daily Q):
    1. If both root are nil, return true
    2. If only one of the root are nil, return false
    3. If the values of the root do not match, return false
    4. Case 1 is having children of both node match as they are (without flipping, i.e., `flipEquiv(root1.left, root2.left) && flipEquiv(root1.right, root2.right)`
    5. Case 2 is having children of both node match after flipping (i.e., `flipEquiv(root1.left, root2.right) && flipEquiv(root1.right, root2.left)`
    6. If one of two cases satisfy, you can make an “equivalent” binary sub-tree

## Graph

- 1791\. Find Center of Star Graph (2024-06-27 Daily Q)
    - Key point 1: non-center node should not appear more than once in the `edges`
    - Key point 2: the center node is either `edges[n][0]` or `edges[n][1]`
    - Compare `edges[0][0]` with `edges[1][0]` and `edges[1][1]`. If it matches either of them, it is the center
    - Otherwise, `edges[0][1]` is the center node
- **1514. Path with Maximum Probability** (Medium, was August 27th Daily Q then Leetcode changed it to 2024-08-31 Daily Q and substituted Two Sum for the 27th??):
    - Use the standard Dijkstra template with the following changes
    1. Initialize `dist` array with `0.0` instead of infinity
    2. Instead of min-heap, use max-heap priority queue
    3. Push `1.0` as a key for the starting node
    4. When `dist[node]` is 0.0 or 1.0, do not use that for the calculation of the `candidate` (which actually is the probability, and multiplying 0.0 or 1.0 would not go very well). Let the `candidate`be just the `weight` of the `node` and `v`
    5. Otherwise, set the candidate to the product of `dist[node]` and the `weight` between the `node` and `v`, and if that is GREATER than `dist[v]`. update the distance array accordingly and push it to the queue.
    6. Return `dist[end_node]`

### Shortest Path

- **1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance** (Medium, 2024-07-26 Daily Q)
    1. Run Floyd-Warshall using the standard template above
    2. For each node, iterate through the matrix, find reachable cities within `distanceThreshold`, update if it can reach the minimum number of cities
- **2976. Minimum Cost to Convert String I** (Medium, 2024-07-27 Daily Q)
    - I thought iterating through the number of characters and calling Dijkstra at each `source[i]` and `target[i]` should be faster. But it was significantly slower, even after I memoized the result of Dijkstra in case we get the same `source` to `target` pair (in fact, I would get TLE without this optimization). So Floyd-Warshall it is. For the Dijkstra solution, reference my C++ submission
    1. Follow the standard Floyd-Warshall template with 26 x 26 matrix and `ord(char) - 97` conversion. One thing to be careful about is that they can give you different cost for the same pairs ("a -> b costs 2" ... "a -> b costs 3"), so take the minimum cost when initializing the matrix
    2. Once we complete the Floyd-Warshall, accumulate the `dist[source[i] - 97][target[i] - 97]`. If we encounter infinity at any point, it means that the conversion is not possible, return -1
- **2045. Second Minimum Time to Reach Destination** (Hard, 2024-07-28 Daily Q)
    1. Build the adjacency list. Since the graph is undirected/bi-directional, do not forget `adj[v].append(u)`
    2. Maintain two distance array (`dist1` and `dist2`) for Dijkstra. Initially, push `(0, 1)` (1 being the starting node) to the queue and set `dist1[1] = 0`. Do not forget that this changes the `if p == dist[u]` optimization within the while loop to `if p == dist1[u] or p == dist2[u]` (or entirely omit this check)
    3. The `priority` popped in each while loop iteration shall be called `timesofar` for the sake of clarity. Following step is how to calculate the `candidate` , which can be calculated before the for loop iterating adjacent nodes since there is no weight
    4. If `(timesofar // change)` (i.e., how many times light has changed so far) is odd, it means we are stuck at the red light. The `candidate` would be `change * (timesofar // change + 1) + time` . If it is even, `candidate` is simply the addition of `time` and `timesofar`
    5. In the adjacent node for loop, if `candidate< dist1[v]` , move `dist1[v]` to `dist2[v]` before updating `dist[1]` and pushing the new pair to the queue.
    6. If `candidate < dist2[v] and dist1[v] != candidate` (i.e., it is the 2nd shortest path), update `dist2[v]` with `candidate` and push the `(candidate, v)` pair to the queue
    7. Return `dist2[n]`

## Simulation

- ~1598. Crawler Log Folder~ (Easy, 2024-07-10 Daily Q): If the operation is "./", skip the iteration. If it is "../", check if the current number of operations is 0 (if it is, keep it 0) and decrement. If it is anything else, increase the number of operations.
- 1894\. Find the Student that Will Replace the Chalk (Medium, 2024-09-02 Daily Q):
    1. Using `long`, accumulate in `chalk`
    2. Subtract the accumulated `chalk` from `k` while it is positive (i.e., `k %= sum(chalk)`)
    3. Iterate `chalk`and return `i` if `chalk[i]` has a value greater than `k`. If `chalk[i]` is smaller, subtract it from `k` and continue with the loop
    4. Return the last student if the last loop ends without premature return

## String

- ~~2678. Number of Senior Citizens~~ (Easy, 2024-08-01 Daily Q): Parse the age part

## Sliding Window

- 2134\. Minimum Swaps to Group All 1's Together II (Medium, 2024-08-02 Daily Q):
    1. Let the window size be the number of 1’s in the array
    2. Append the first `windowsize` elements of the array to maintain the circular property
    3. First, count the number of 0’s from `i = 0 to windowsize`
    4. Iterate from `head = 0 to length of nums`, in each iteration, add zero count at the tail (`head + windowsize`) and subtract zero count at the `head`. Update the minimum zero if the current window contains the minimum zero count
    5. This minimum zero count is the minimum swap to group all 1’s together

## Matrix

- 840\. Magic Squares In Grid (Medium, 2024-08-09 Daily Q):
    1. Iterate from `0` to `m` (`i`), and within that, iterate from `0` to `n` (`j`) . For each iteration, the helper function arguments are `grid`, `i`, and `j`. Within the helper functions, iterate from `i` to `i + 2` and `j` to `j + 2`.
    2. Define a function to check if numbers in the current matrix is with in [1, 9]
    3. Define a function to check if there are any duplicate values. Make a boolean array with size 10 filled with false to achieve this.
    4. Define a function to check if the grid is indeed a magic square.
        ```
        // rowsum[0] += grid[m + 0][col + 0-2]
        // rowsum[1] += grid[m + 1][col + 0-2]
        // rowsum[2] += grid[m + 2][col + 0-2]
        for i = 0 to 2:
            for j = 0 to 2:
                rowsum[i] += grid[m + i][n - j]

        // colsum[0] += grid[m + 0-2][col + 0]
        // colsum[1] += grid[m + 0-2][col + 1]
        // colsum[2] += grid[m + 0-2][col + 2]
        for j = 0 to 2:
            for i = 0 to 2:
                colsum[j] += grid[m + i][n + j]

        // diasum[0] += grid[m + 0-2][col + 0-2]
        // diasum[1] += grid[m + 0-2][col + 2-0]
        for i = 0 to 2:
            diasum[0] += grid[m + i][col + i]
        for i = 0 to 2:
            diasum[1] += grid[m + i][col + (2 - i)]

        return rowsum[0] == rowsum[1] && ... && rowsum[2] == colsum[2] && ...
        ```
    5. If we pass all three checks, yay, we found the magic square!
- 2022\. Convert 1D Array Into 2D Array (Easy, 2024-09-01 Daily Q):
    - for `i`th element in the original array, the matrix position is `matrix[i // n][i % n]`
- **2326. Spiral Matrix IV** (Medium, 2024-09-09 Daily Q):
    1. initialize the matrix with -1
    2. follow the basic principle of spiral matrix traversal, but instead of traversing `m * n` times, traverse until we run out of linked list node
- 2684\. Maximum Number of Moves in a Grid (Medium, 2024-10-29 Daily Q):
    - Perform a matrix BFS with following modifications, return the largest value in the `dist` array
    1. The starting nodes are all cells at the first column (i.e., `for i = 0 to m - 1, (i, 0)`)
    2. The column direction is always adding 1, the row direction is `{-1, 0, 1}`
    3. When checking visit-able adjacent cell, add `grid[row][co] < grid[adjrow][adjcol]`

## Binary Search

- 719\. Find K-th Smallest Pair Distance (Hard, 2024-08-14 Daily Q):
    1. Sort `nums`
    2. Find the largest difference and the smallest difference (upon research, I just made this 0 and it worked) to `hi` and `lo` values of the binary search
    3. Perform binary search
    4. After finding `mid` , run it through the auxilary function `countSmaller`
    5. In `countSmaller`, use sliding window technique to count the number of pairs where the difference is smaller than the parameter (i.e., `mid`)
        ```python
        E.g., parameter = 30
        [10, 20, 30, 40, 50]
          l               r
        50 - 10 > 30, thus decrement r
        [10, 20, 30, 40, 50]
          l          r
        40 - 10 > 30, thus add r - l to the count
        ```
    6. If the return value of `countSmaller` is greater than `k`, move `hi`. Return `lo` after the binary search
- 729\. My Calendar I (Medium, 2024-09-26 Daily Q):
    1. Either keep two arrays for start and end values of existing events or an array of tuples
    2. Perform binary search for the end parameter in the existing start value arrays
    3. Perform binary search for the start parameter in the existing end value arrays, but this time, make it return the rightmost position if the end value is the same as the existing start value, since we are allowed to have an event that starts right after one ends
    4. If the result of both binary search is the same, meaning there is no overlapping events and that `(start, end)` tuple can fit right in between existing array elements, we insert this tuple in the found binary search position and return true

## Greedy

- 860\. Lemonade Change (Easy, 2024-08-15 Daily Q):
    1. Keep track of number of $5 and $10. $20 is not needed since we will never use that as a change
    2. Iterate through the `bills`
    3. If we receive $5, increment the `numFive`, if we receive $10, check the number of $10 and see if we can decrement `numFive` and increment `numTen`
    4. If we receive $20, we can give eiither $10 + $5 or $5 * 3. Check $10 + $5 first since that is always helpful in the long run
- 624\. Maximum Distance in Arrays (Medium, 2024-08-16 Daily Q):
    - The key point is that we only need to consider the first and last element of each array and update the maximum distance greedily
    1. Let the `currMin` and `currMax` be the first and last element of the first array. Let `maxDist` be 0
    2. Iterate from the second array to the last array
    3. Get the first and last element of the current array, compute `currMax - currentFirstElement` and `currentLastElement - currMin` and find the bigger of two (let this be `currentDist`
    4. Compare `currentDist` with `maxDist` and update `maxDist` accordingly
    5. Update `currMin` and `currMax` to the first and last element of the current array, if needed
    6. Return the final `maxDist`

## Dynamic Programming

Longest Increasing/Decreasing Sequence (solution for 300. Longest Increasing Subsequence):

```cpp
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n, 1);

    int lis = 1;
    for (int i = 0; i < n; i++) {      // LDS: for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < i; j++) {  // LDS: for (int j = i + 1; j < n; j++)
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        lis = max(lis, dp[i]);
    }
    return lis;
}
```

- 264\. Ugly Number II (Medium, 2024-08-18 Daily Q):
    1. Define an array `dp` and let the first element be 1
    2. Define pointers for multiples of 2, 3, and 5
    3. Iterate from 1 to `n`, find the next “Ugly Number” candidate by multiplying 2, 3, or 5 to the `dp[<multiple pointer>` (e.g., `multiple2Candidate = dp[multiple2Ptr] * 2`)
    4. Assign the minimum of three to the `dp[i]` and advance the pointer to it by one
    5. Return `dp[n - 1]`
- 1277\. Count Square Submatrices with All Ones (Medium, 2024-10-27 Daily Q):
    - We can keep track of number of continuous 1 in end of the bottom edge of the square at the given cell using tabulation technique
    ```jsx
    mx = | 1 | 1 | 1 |
         | 1 | 1 | 1 |
         | 1 | 1 | 0 |

    dp = | 1 | 1 | 1 |
         | 1 | 2 | 2 |
         | 1 | 2 | 3 |
    can produce 1 + 1 + 1 + 1 + 1 + 2 + 2 + 2 + 3 = 14 "all 1 matrices"

    mx = | 1 | 1 | 1 |
         | 1 | 1 | 1 |
         | 1 | 1 | 0 |

    dp = | 1 | 1 | 1 |
         | 1 | 2 | 2 |
         | 1 | 2 | 0 |
    can produce 1 + 1 + 1 + 1 + 1 + 2 + 2 + 2 + 0 = 11 "all 1 matrices"
    ```
    1. Define a matrix `dp` of size `m + 1 X n + 1`
    2. Iterate through the elements in the `matrix`
    3. If the `matrix[i][j]` is 1, set the `dp[i + 1][j + 1]` to `1 + min(dp[i][j], dp[i + 1][j], dp[i][j + 1])` (left above diagonal, above, left, respectively)
    4. Sum up the values of all `dp` cells and return
- 1671\. Minimum Number of Removals to Make Mountain Array (Hard, 2024-10-30 Daily Q):
    1. Compute LIS DP array
    2. Compute LDS DP array
    3. For each index, if `nums[i]` is a valid mountain peak (i.e., `lis[i] > 1 && lds[i] > 1`), `n - lis[i] - lds[i] + 1` (`+ 1` since `lis[i]` and `lds[i]` are both counting `nums[i]` as part of LIS/LDS) is the number of removals to make a mountain array with `nums[i]` as the peak
    4. Keep track of the minimum removals

## Bit

- 476\. Number Complement (Easy, 2024-08-22 Daily Q):
    1. Find the length of the bit representation of `num` and make a bitmask
    2. Return XOR of the `num` and the bitmask
- **2220. Minimum Bit Flips to Convert Number** (Easy, 2024-09-11 Daily Q):
    1. Take the XOR of start and goal
    2. Count the number of 1’s in the XOR result
- ~~1310. XOR Queries of a Subarray~~ (Medium, 2024-09-13 Daily Q): we just take the XOR of the elements in each subarray (queries) and add it to the result??
- ~~2419. Longest Subarray With Maximum Bitwise AND~~ (Medium, 2024-09-14 Daily Q): find the longest consecutive sequence of the maximum value in the array

## Math

- 539\. Minimum Time Difference (Medium, 2024-09-16 Daily Q):
    1. convert time to minutes relative to midnight
    2. sort
    3. find the smallest `time[i] - time[i - 1]`
    4. find the `1440 - abs(time[last] - time[0])`
    5. return the smallest of two

## KMP

- **214. Shortest Palindrome** (Hard, 2024-09-20 Daily Q):
    - The “Failure” function in KMP algorithm returns the array with the length of matching prefix and suffix of the substring at the given index. For example, for `"abaa"`, `pi[0] ("a") = 0`, `pi[1] ("ab") = 0`, `pi[2] ("|a| b |a|") = 1`, `pi[3] ("|a| b a |a|")` = 1
    1. Run the Failure function with `s + <one character seperator> + s.reverse`
    2. get the last value of the Failure function result
    3. Prepend `s[:len(s) - pi[-1]` to the `s`

## Trie

- **3043. Find the Length of the Longest Common Prefix** (Medium, 2024-09-24 Daily Q):
    1. Build a trie with either of `arr1` or `arr2`
    2. Walk the trie with elements in `arr2` , while counting the steps
    3. return the minimum
- **2416. Sum of Prefix Scores of Strings** (Hard, 2024-09-25 Daily Q):
    1. build a trie that keeps track of the number of visits per each node during insertion
    2. walk the trie again with each word
    3. accumulate the number of visits, which is the total prefix scores
- **1233. Remove Sub-Folders from the Filesystem** (Medium, 2024-10-25 Daily Q):
    1. Build a Trie, treating each components in the `f in folder` as a single character (`f.split(”/”)`)
    2. Make a method `isSubfolder` in the Trie class, which is a modified search method that returns false `if node.end and i > length of the components in the current folder`
    3. Add `f in folder` that passes `isSubfolder` test to the non-subfolder list

## Queue

- **641. Design Circular Deque** (Medium, 2024-09-28 Daily Q):
    - Do 622. Design Circular Queue first
    1. Tackle `insertLast` (`enqueue` in standard queue) and `deleteFront` (`dequeue` in standard queue), as well as auxiliary methods the same way as 622.
    2. `insertFront` and `deleteLast` use a similar logic as `insertLast` and `deleteFront`, except the new `head` and `tail` calculation becomes `(head/tail - 1 + k) % k`

## Stack

- ~~1381. Design a Stack With Increment Operation~~ (Medium, 2024-09-30 Daily Q): Keep track of size and maxSize. push and pop are as trivial as stack[size++] = x and size--; return stack[size] after checking the size conditions for each operation (i.e., whether size exceeds maxSize and whether the size == 0). Increment is trivial.
- 2696\. Minimum String Length After Removing Substrings (Easy, 2024-10-07 Daily Q):
    1. Iterate the characters in string
    2. Pop the stack (if it is not empty), if it is ‘A’ and the current char is ‘B’ (or ‘C’ and ‘D’ combination), pop the stack
    3. Else, push the current character to the stack
    4. Return the size of the stack
- 1963\. Minimum Number of Swaps to Make the String Balanced (Medium, 2024-10-08 Daily Q):
    1. Iterate over the characters in `s`
    2. If the character is `[`, push it to the stack
    3. Else (i.e., the character is `]`), check if the stack is empty, if so, increment the number of imbalance bracket
    4. If the stack is not empty (and the top element must be `[` since that is the only char we are pushing to the stack), pop the stack
    5. Return `(numImbalances + 1) / 2`
    - As you can see, you really do not need stack, we can have an integer variable to replace it (push = incrementing, empty = check if integer is greater than 0, pop = decrement)
- **921. Minimum Add to Make Parentheses Valid** (Medium, 2024-10-09 Daily Q):
    1. Iterate over the characters in `s`
    2. If the char is `(` push it to the stack
    3. If the char is `)` and stack is not empty (which has to contain `(`), pop the stack
    4. If the stack is empty, increment the number of stray `)`
    5. Return the size of stack plus number of stray `)`
    - As with 1963, you do not necessarily need a stack, you can use an integer variable
- **1106. Parsing A Boolean Expression** (Hard, 2024-10-20 Daily Q):
    1. Initialize two stacks, `operators` and `operands`
    2. Iterate through the characters in `expression`
    3. If it is `,`, skip
    4. If it is one of the operators (`!`, `&`, or `|`), push it to the `operators`
    5. If it is one of the operands or opening parenthesis (`t`, `f`, or `(`), push it to the `operands`
    6. If it is `)`, initialize an array. Pop until the `operands` until it gives you `(`, add the popped elements into the array
    7. Pop an operator from `operators` stack
    8. If it is `!`, the result of the current operation is opposite of the one and only element in the operand array
    9. If it is `&`, see if the array contains any `f`
    10. If it is `|`, see if the array contains any `t`
    11. Add the result of the operation back to `operands` stack
    12. Return the top element of the `operands`
    - Optimization: in 6, instead of holding every operands in an array, you only need to keep track of `lastOperand` (used to compute `!`), `seenTrue` (used to compute `|`), and `seenFalse` (used to compute `&`)

## Two Pointers

- ~~2491. Divide Players Into Teams of Equal Skill~~ (Medium, 2024-10-04 Daily Q): Sort the array, have the skill[0] + skill[n - 1] be the target chemistry (since it is always optimal to pair the current minimum and maximum skills), iterate through the array with two pointers, if we encounter chemistry that is not equal to the target chemistry, return -1
- ~~2938. Separate Black and White Balls~~ (Medium, 2024-10-15 Daily Q):
    1. Initialize the current white ball index at 0
    2. Iterate through the characters in `s`
    3. If we encounter `‘0’`, we need at least current index - current white ball index swaps to bring the white ball to the front. Accumulate this
    4. Increment the current white ball index

## Priority Queue

- **1942. The Number of the Smallest Unoccupied Chair** (Medium, 2024-10-11 Daily Q):
    1. Before sorting, make a map of arrival time which are unique to the original index
    2. Sort `times` based on the arrival time
    3. Add [0, n) to a min-heap named `available`
    4. Declare a min-heap named `occupied`
    5. Iterate through the `times`
    6. Before processing the current person, if the top element of `occupied` has a departure time earlier than the current arrival time, pop and add it to the `available`. Repeat this until the top element is still in use
    7. Assign the top element of the available to the current person. Push `(departureTime, chairNo)` to the `occupied`
    8. During the loop, if we encounter `targetFriend`, return the chair
- ~~2530. Maximal Score After Applying K Operations~~ (Medium, 2024-10-14 Daily Q):
    - It is optimal to pick the greatest element
    1. Define a max-heap and push all elements in `nums`
    2. Iterate `k` times, pop an element, add it to the score, and push the ceiling of third of the element to the max-heap

---
Below is generated by Leethub extension.
I frankly do not understand how they are classified.

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
## Array
|  |
| ------- |
| [1293-three-consecutive-odds](https://github.com/theopn/leetcode/tree/master/1293-three-consecutive-odds) |
## Linked List
|  |
| ------- |
| [2299-merge-nodes-in-between-zeros](https://github.com/theopn/leetcode/tree/master/2299-merge-nodes-in-between-zeros) |
## Simulation
|  |
| ------- |
| [2299-merge-nodes-in-between-zeros](https://github.com/theopn/leetcode/tree/master/2299-merge-nodes-in-between-zeros) |
<!---LeetCode Topics End-->
