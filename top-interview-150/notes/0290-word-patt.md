 # 290. Word Pattern

## Relevant Skills

- Hashmap
- Checking if key exists

## Approach

Same approach as [Isomorphic String](./0205-isomorphic-str.md).

## Optimization

- Trade readability and combine the if statements together

## Pseudocode

```lua
function word_patt(pattern, s)
    words = []
    for w in s do words.insert(w) end

    if pattern.n ~= words.n then return false end

    patt_to_w = {}
    w_to_patt = {}

    for i = 0, s.n - 1 do
        if (patt_to_w[pattern[i]] ~= nil and patt_to_w[pattern[i]] ~= words[i])
            or (w_to_patt[words[i]] ~= nil and w_to_patt[words[i]] ~= pattern[i])
        then
            return false
        else
            patt_to_w[pattern[i]] = words[i]
            w_to_patt[words[i]] = pattern[i]
        end
    end

    return true
end
```

## Analysis

- $O(n)$

## Relevant Coding Skills

- Use `stringstream` in C++ to separate string by spaces
    ```cpp
    string s = "hello I would like to be separated";
    vector<string> words;
    stringstream(ss);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    ```

