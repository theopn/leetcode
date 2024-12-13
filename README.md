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

## Array

- ~1550. Three Consecutive Odds~ (Easy, 2024-07-01 Daily Q): Iterate the array while keeping the consecutive odd count, return if the count is 3

## Substring & Subarray

- ~3110. Score of a String~ (Easy, 2024-06-01 Daily Q): Iterate [0, n - 1) and accumulate abs(s[i] - s[i + 1])
- ~344. Reverse String~ (Easy, 2024-06-02 Daily Q): Iterate [0, floor(n / 2) and swap s[n - i -1] and s[i]
- 1395. Count Number of Teams (Medium 2024-07-29 Daily Q)
    1. Iterate from `0` to `n -1` , let the current index be `j`
    2. At `j`, find the number of elements smaller/greater than `rating[j]` in (0, j] (”left” of `j`. You can find one of them and subtract it from `j` to find the other since all elements are unique)
    3. At `j`, find the number of elements smaller/greater than `rating[j]` in [j + 1, n) (”right” of `j`. You can find one of them and subtract it from `n - 1 - j` to find the other since all elements are unique)
    4. Multiplying the number of elements smaller than `rating[j]` in (0, j] to the number of elements greater than `rating[j]` in [j + 1, n) gives you the permutation of strictly increasing sub-sequence when we fix the middle element to `rating[j]`
    5. Multiplying the rest two gives you the permutation of strictly decreasing sub-sequence
    6. Add those two the total number of `sub-sequences` at each `j`

## Hash Table

- ~350. Intersection of Two Arrays II~ (Easy, 2024-07-02 Daily Q): Make a Counter hash table of one array, iterate through the others and add elements in the table. Decrement the count

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
- 2418. Sort the People (Easy, 2024-07-22 Daily Q)
    1. Follow the standard quick sort template above, but take an extra parameter `names` along with `heights`
    2. All comparisons are done with `heights`, but also make `leftNames`, `midNames` , and `rightNames`, and whenever we append `height[i]` to `left` , `mid`, or `right`, append `names[i]` to the corresponding arrays
    3. Since we are sorting in reverse order, return `quicksort(right, rightNames + midNames + quicksort(left, leftNames)`
- **1636. Sort Array by Increasing Frequency** (Easy, 2024-07-23 Daily Q)
    - Make a counter and use a built-in sorting algorithm with lambda comparator. A worthy practice
- **912. Sort an Array** (Medium, 2024-07-25 Daily Q)
    - Either merge sort or RANDOMIZED quick sort works. A good practice to learn efficient sorting algorithms

## Linked List

- 2181. Merge Nodes in Between Zeros (Medium, 2024-07-04 Daily Q)
    - You can modify the existing list (see the C++ solution), but I find making a new list much easier
    1. Create a sentinel node and make a copy of it for the return value
    2. Iterate through the list. If the value is 0, set the next of sentinel to the accumulated sum so far
    3. Else, accumulate the value
    4. Return `sentinel_save.next.next` since they do not want the first 0 in the list

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

## Graph

- 1791. Find Center of Star Graph (2024-06-27 Daily Q)
    - Key point 1: non-center node should not appear more than once in the `edges`
    - Key point 2: the center node is either `edges[n][0]` or `edges[n][1]`
    - Compare `edges[0][0]` with `edges[1][0]` and `edges[1][1]`. If it matches either of them, it is the center
    - Otherwise, `edges[0][1]` is the center node

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

## String

- ~2678. Number of Senior Citizens~ (Easy, 2024-08-01 Daily Q): Parse the age part

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
