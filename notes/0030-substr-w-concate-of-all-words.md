# 30. Substring with Concatenation of All Words

## Relevant Skills

- Sliding Window
- Hashmap
- Taking substring

## Approach

1. Make a Counter representation of the list `words`
    It could be a hashmap, it could be a list with word sorted in a particular order, it could be Python Counter object.
1. Calculate the length of the concatenation of all words, i.e., `words[0].n * words.n`
1. Loop through the length of the string
1. Set a Window at `s[i:i + total+_len]`
1. Loop through the window character, jump by `words[0].n`
1. Add the words to a temporary Counter representation
1. After the loop, see if the Counter representation is equal to the Counter representation of `words` we made earlier.
    If so, that means the occurrence of word in words were identical in the current window as the target representation we are finding
1. Since we verified that the current window is the concatenation of the all `words`, add the current index `i` to the list of answers
1. Return answers


## Optimization

- Instead of looping all the way through the end of the string `s`, we can stop at `s.n - total_len + 1`.
    E.g., in "foobarfoobar" where `words = ["foo", "bar"]`, there is no point looping through the last "oobar" since there is no way they will make the complete concate of words.
- ~~On a similar note, check if the `total_len` is greater than `s`~~
    -> checked by the optimization above
- Overall, solution isn't that elegant.
    If Python didn't support equal sign between two dictionaries, the code would have been much messier.
    I want to find a way to break out of the inner for loop as soon as we detect repeated words or words that isn't in the dictionary.

## Pseudocode

```lua
function find_concate_of_words(s, list)
    -- Target hashmap that a concate of all words should have
    word_counter_repr = {}
    for word in words do
        word_counter_repr[word]++
    end
    -- Window size
    total_len = words[0].n * words.n
    -- Array holding our answers
    ans = []

    for i = 0, words.n - total_len do --> optimization
        window = s.sub(i, i + total_len)
        curr_window_counter_repr = {}

        for j = 0, window.n, words[0].n do --> window.n == total_len
            -- Add words to hashmap
            curr_word = window.sub(j, j + word[0].n)
            curr_window_counter_repr[curr_word]++
        end

        -- See if the current window hashmap is equal to the target
        if word_counter_repr == curr_window_counter_repr then
            ans.append(i)
        end
    end

    return ans
end
```

## Analysis

- Let $k$ be the `total_len`
- The outer for loop is $O(n - k) \in O(n)$
- The inner for loop is $O(\log (k))$
- Thus, the total runtime is $O(n \log (k))$

## Relevant Coding Skills

- In Python, `Counter(list)` object is returns the dictionary of counts of each element (e.g., `Counter(["foo", "bar", "foo"]) = { "foo": 2, "bar": 1}`).
    This can be used in the place of building a dictionary

