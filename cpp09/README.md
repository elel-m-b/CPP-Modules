# CPP09 ex02: PmergeMe

## Goal

The goal of `PmergeMe` is to sort a sequence of positive integers using the **Ford-Johnson merge-insertion algorithm**.

The project requires two different STL containers, for example:

* `std::vector`
* `std::deque`

---

# Algorithm Overview

```text
Input
  ↓
Create pairs
  ↓
Compare each pair
  ↓
Separate bigger / smaller
  ↓
Recursively sort bigger elements
  ↓
Build main chain
  ↓
Generate Ford-Johnson insertion order
  ↓
Insert smaller elements using binary search
  ↓
Sorted result
```

---

# 1. Create Pairs

Example:

```text
8 3 7 4 9 1
```

Create pairs:

```text
(8,3) (7,4) (9,1)
```

Compare each pair:

```text
(8,3) → bigger = 8, smaller = 3
(7,4) → bigger = 7, smaller = 4
(9,1) → bigger = 9, smaller = 1
```

So:

```text
Bigger:
8 7 9

Smaller:
3 4 1
```

---

# 2. Sort the Bigger Elements

We recursively sort only the bigger elements:

```text
8 7 9
```

Result:

```text
7 8 9
```

This becomes the **main chain**:

```text
Main chain:
7 8 9
```

The smaller elements are kept as **pending elements**:

```text
Pending:
3 4 1
```

---

# 3. Keep the Pair Relationship

Each smaller element has a corresponding bigger element:

```text
(8,3) → 3 belongs to 8
(7,4) → 4 belongs to 7
(9,1) → 1 belongs to 9
```

After sorting the bigger elements:

```text
7 8 9
```

the relationships are still:

```text
4 → 7
3 → 8
1 → 9
```

This is important because when inserting a smaller element, we only search **before its bigger partner**.

---

# 4. Ford-Johnson Insertion Order

We don't insert the pending elements randomly.

Ford-Johnson uses **Jacobsthal numbers** to determine an efficient insertion order.

The beginning of the sequence is:

```text
0 1 1 3 5 11 21 43 ...
```

The useful positions are:

```text
1 3 5 11 21 43 ...
```

The algorithm uses these positions to decide which pending elements should be inserted first.

The purpose is not to create sorted order.

The purpose is to **reduce the number of comparisons during binary insertion**.

Conceptually:

```text
Pending elements
      ↓
Jacobsthal-based order
      ↓
Binary search
      ↓
Insert
```

---

# 5. Binary Search

Binary search is used to find **where an element should be inserted** into an already sorted range.

It works by repeatedly cutting the search range in half.

Example:

```text
Main chain:

1 4 7 8 9

Insert:

6
```

We search for the position of `6`.

### Step 1

Search range:

```text
1 4 7 8 9
```

Middle element:

```text
1 4 [7] 8 9
```

Compare:

```text
6 < 7
```

Therefore, `6` must be on the **left side**.

New search range:

```text
1 4
```

---

### Step 2

Middle:

```text
1 [4]
```

Compare:

```text
6 > 4
```

Therefore, `6` must be **after 4**.

So the insertion position is:

```text
1 4 | 7 8 9
    ↑
   insert 6
```

Result:

```text
1 4 6 7 8 9
```

---

# 6. Binary Search in PmergeMe

In PmergeMe, we also have an important limitation.

A smaller element is inserted **before its bigger partner**.

Example:

```text
(7,4)
```

means:

```text
4 → 7
```

If the main chain is:

```text
1 3 7 8 9
```

we want to insert `4`.

We only search before `7`:

```text
1 3 | 7 8 9
```

Binary search works on:

```text
1 3
```

and finds:

```text
1 3 4 7 8 9
```

We don't need to search after `7`, because we already know:

```text
4 < 7
```

This reduces the search range and therefore the number of comparisons.

---

# 7. Binary Search Logic

The idea can be remembered as:

```text
left = beginning
right = end

while left < right:

    middle = middle of the range

    if middle element < value:
        search right
    else:
        search left
```

At the end:

```text
left == right
```

That position is where the new element should be inserted.

---

# 8. Complete Example

Input:

```text
8 3 7 4 9 1
```

### Step 1 — Create pairs

```text
(8,3)
(7,4)
(9,1)
```

### Step 2 — Bigger / Smaller

```text
Bigger:
8 7 9

Smaller:
3 4 1
```

### Step 3 — Sort bigger elements

```text
7 8 9
```

Main chain:

```text
7 8 9
```

### Step 4 — Keep relationships

```text
4 → 7
3 → 8
1 → 9
```

### Step 5 — Generate insertion order

Use the Ford-Johnson / Jacobsthal strategy to choose the order in which pending elements are inserted.

### Step 6 — Binary search + insert

For every pending element:

```text
1. Find its bigger partner.
2. Search only before that partner.
3. Use binary search.
4. Insert at the found position.
```

Eventually:

```text
1 3 4 7 8 9
```

---

# 9. Odd Number of Elements

If the input contains an odd number of elements, one element has no pair.

Example:

```text
8 3 7 4 9
```

Pairs:

```text
(8,3)
(7,4)
```

Remaining element:

```text
9
```

This is called the **straggler**.

It is kept separately and inserted into the sorted chain later.

---

# Important Terms

| Term               | Meaning                                                |
| ------------------ | ------------------------------------------------------ |
| Pair               | Two numbers grouped together                           |
| Bigger             | Larger element of a pair                               |
| Smaller            | Smaller element of a pair                              |
| Main chain         | Sorted bigger elements                                 |
| Pending            | Smaller elements waiting to be inserted                |
| Pair relationship  | Connection between smaller and bigger                  |
| Jacobsthal numbers | Used to create an efficient insertion order            |
| Insertion order    | Order used to insert pending elements                  |
| Binary search      | Finds the position where an element should be inserted |
| Search range       | Part of the chain where binary search is allowed       |
| Straggler          | Unpaired element when input size is odd                |

---

# Algorithm Summary

```text
1. Create pairs.
2. Compare each pair.
3. Separate bigger and smaller elements.
4. Recursively sort the bigger elements.
5. Build the main chain.
6. Keep the smaller → bigger relationships.
7. Generate the Ford-Johnson insertion order.
8. Take pending elements in that order.
9. Find each element's bigger partner.
10. Binary-search only before that partner.
11. Insert the element.
12. Insert the straggler if one exists.
13. The final chain is sorted.
```

## Key Idea

```text
Sort the biggers
      ↓
Create main chain
      ↓
Choose smart insertion order
      ↓
For each smaller:
    ↓
    Find its bigger partner
    ↓
    Search before that partner
    ↓
    Binary search
    ↓
    Insert
      ↓
Sorted result
```

The three most important ideas are:

```text
Jacobsthal sequence
        ↓
chooses the insertion order

Pair relationship
        ↓
limits the search range

Binary search
        ↓
finds the exact insertion position
```
