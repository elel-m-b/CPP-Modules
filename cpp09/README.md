# CPP09 — ex02: PmergeMe

## Goal

The goal of `PmergeMe` is to sort a sequence of positive integers using the **Ford-Johnson merge-insertion algorithm**.

The project requires using two different STL containers, for example:

* `std::vector`
* `std::deque`

The final result must be sorted in ascending order.

---

## Algorithm Overview

The algorithm works like this:

```text
Input
  ↓
Create pairs
  ↓
Find bigger and smaller in each pair
  ↓
Recursively sort the bigger elements
  ↓
Build the main chain
  ↓
Choose insertion order
  ↓
Insert smaller elements using binary search
  ↓
Sorted result
```

---

## 1. Create Pairs

Example:

```text
8 3 7 4 9 1
```

Create pairs:

```text
(8,3) (7,4) (9,1)
```

Compare the numbers in each pair:

```text
(8,3) → bigger = 8, smaller = 3
(7,4) → bigger = 7, smaller = 4
(9,1) → bigger = 9, smaller = 1
```

Now we have:

```text
Bigger:
8 7 9

Smaller:
3 4 1
```

---

## 2. Sort the Bigger Elements

We recursively sort only the bigger elements:

```text
8 7 9
```

becomes:

```text
7 8 9
```

These elements form the beginning of the main chain:

```text
Main chain:
7 8 9
```

The smaller elements are kept separately:

```text
Pending:
3 4 1
```

---

## 3. Insertion Order

We don't insert the smaller elements randomly.

Ford-Johnson uses the **Jacobsthal sequence** to determine an efficient insertion order.

The purpose is to reduce the number of comparisons.

For example, the pending elements might be inserted in an order such as:

```text
1 → 4 → 3
```

The important idea is:

```text
Insertion order ≠ sorted order
```

The order is chosen to make the insertion process more efficient.

---

## 4. Binary Search

Now we insert each pending element into the main chain.

Binary search is used to find the correct position.

It is not being used to search for an existing value.

It answers:

```text
"Where should this value be inserted?"
```

Example:

```text
Main chain:

7 8 9

Insert 4
```

Binary search determines that `4` belongs before `7`:

```text
4 7 8 9
```

Now insert `6`:

```text
4 7 8 9
```

Binary search finds the position:

```text
4 6 7 8 9
```

---

## 5. Complete Example

Input:

```text
8 3 7 4 9 1
```

### Step 1: Create pairs

```text
(8,3)
(7,4)
(9,1)
```

### Step 2: Separate bigger and smaller

```text
Bigger:
8 7 9

Smaller:
3 4 1
```

### Step 3: Sort bigger elements

```text
7 8 9
```

This is our main chain:

```text
7 8 9
```

### Step 4: Choose insertion order

The smaller elements are inserted according to the Ford-Johnson insertion order.

For example:

```text
1 → 4 → 3
```

### Step 5: Insert using binary search

Insert `1`:

```text
1 7 8 9
```

Insert `4`:

```text
1 4 7 8 9
```

Insert `3`:

```text
1 3 4 7 8 9
```

### Final result

```text
1 3 4 7 8 9
```

---

## 6. Odd Number of Elements

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

This element is called the **straggler**.

It is kept separately and inserted into the sorted chain later.

---

## Important Terms

| Term            | Meaning                                              |
| --------------- | ---------------------------------------------------- |
| Pair            | Two numbers grouped together                         |
| Bigger          | Larger number in a pair                              |
| Smaller         | Smaller number in a pair                             |
| Main chain      | Sorted bigger elements                               |
| Pending         | Smaller elements waiting to be inserted              |
| Insertion order | Order used to insert pending elements                |
| Jacobsthal      | Sequence used to create an efficient insertion order |
| Binary search   | Finds where an element should be inserted            |
| Straggler       | Unpaired element when input size is odd              |

---

## Algorithm Summary

```text
1. Create pairs.
2. Compare each pair.
3. Separate bigger and smaller elements.
4. Recursively sort the bigger elements.
5. Use them to create the main chain.
6. Generate the insertion order.
7. Insert smaller elements using binary search.
8. Insert the straggler if one exists.
9. The result is sorted.
```
