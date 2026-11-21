# 100 C++ muscle-memory drills

A practical course for competitive programming, using GNU C++20. The goal is to translate small instructions into code without stopping to look up syntax. These are building blocks, not algorithm puzzles. Use [the C++ cheat sheet](CPP_CHEAT_SHEET.md) whenever you need a reminder.

## How to train

1. Do 5–10 levels per session. Aim for 1–2 minutes per level **after** you understand the operation; take longer when learning it for the first time.
2. For each level, write a small complete program. Unless the level says otherwise, use the given values directly; print exactly the requested result. Values in brackets describe a sequence, not literal input or required output formatting.
3. Compile and run. Compare with the expected output. Then redo the level from an empty file without looking. Say the operation aloud as you type if that helps.
4. Mark it: ✓ = correct unaided; ~ = needed a reminder or correction; blank = not yet attempted. Repeat ~ levels the next day, then again a few days later. Mix 5 older levels into later sessions. A level is fluent when you can do it correctly twice on different days without looking.
5. For input drills, type or paste the stated input; whitespace separates tokens unless noted. Each line in a displayed output is a separate output line. Do not memorize the particular numbers: repeat with your own values after passing.

Use your normal C++20 compiler. A minimal reusable shell is below; add the standard headers needed for each task. GCC users may use `<bits/stdc++.h>` for practice, though it is not a standard header.

```cpp
#include <iostream>
using namespace std;

int main() {
    // Your code goes here.
}
```

Use `\n` for newlines. A trailing newline is fine. Never access an element or call `front`, `back`, `top`, or `pop` on an empty container. Unless otherwise stated, all indices are zero-based and all given values fit the intended types. No complete answers are provided: use the cheat sheet to unblock yourself.

## 1–10: Values and output

- [ ] **1. Integer.** Declare an `int` with value 17 and print it. Expected: `17`.
- [ ] **2. Two values.** Declare integers 4 and 9; print them on one line separated by one space. Expected: `4 9`.
- [ ] **3. Change a variable.** Set an integer to 8, add 3 to it, and print it. Expected: `11`.
- [ ] **4. Large integer.** Store 3000000000 in a `long long` and print it. Expected: `3000000000`.
- [ ] **5. Decimal.** Store 2.5 in a `double` and print it with exactly two digits after the decimal point. Expected: `2.50`.
- [ ] **6. Character.** Store the character `Q` in a `char` and print it. Expected: `Q`.
- [ ] **7. Text.** Store `hello` in a `string` and print it. Expected: `hello`.
- [ ] **8. Boolean.** Set a `bool` to the result of `7 < 10`; print `YES` if true and `NO` otherwise. Expected: `YES`.
- [ ] **9. Constant.** Declare a named constant integer with value 100, subtract 4, and print the result. Expected: `96`.
- [ ] **10. Type deduction.** Use `auto` to store the result of `12LL + 5`; print it. Expected: `17`. Explain to yourself why the deduced type is `long long`.

## 11–20: Input and arithmetic

- [ ] **11. One input.** Read an integer, then print twice its value. Input: `6`. Expected: `12`.
- [ ] **12. Two inputs.** Read two integers and print their sum. Input: `7 8`. Expected: `15`.
- [ ] **13. Quotient and remainder.** Read integers `a b`, with `a >= 0` and `b > 0`; print `a / b` and `a % b`. Input: `17 5`. Expected: `3 2`.
- [ ] **14. Real division.** Read two integers, divide the first by the second as a `double`, and print two decimal places. Input: `7 2`. Expected: `3.50`.
- [ ] **15. Safe product.** Read two `int` values, multiply them using `long long` arithmetic, and print the product. Input: `100000 100000`. Expected: `10000000000`.
- [ ] **16. Update operators.** Start with `x = 10`; subtract 3, multiply by 2, and print `x`. Expected: `14`.
- [ ] **17. Min and max.** Read two integers and print their minimum and maximum in that order. Input: `8 -2`. Expected: `-2 8`.
- [ ] **18. Absolute value.** Read an integer and print its absolute value; assume its absolute value fits in `int`. Input: `-13`. Expected: `13`.
- [ ] **19. Token and character.** Read a word and a character; print the word, a space, and the character. Input: `cat Z`. Expected: `cat Z`.
- [ ] **20. Whole line.** Read one whole line, including spaces, with `getline`, and print it. Input line: `hello C++ world`. Expected: `hello C++ world`.

## 21–30: Conditions and loops

- [ ] **21. Sign.** Read a nonzero integer; print `positive` or `negative`. Input: `-4`. Expected: `negative`.
- [ ] **22. Range.** Read an integer and print `YES` if it is between 1 and 10 inclusive, otherwise `NO`. Input: `10`. Expected: `YES`.
- [ ] **23. Even or odd.** Read an integer and print `even` or `odd`. Input: `7`. Expected: `odd`.
- [ ] **24. Count up.** Use a `for` loop to print 1 through 5 on one line, separated by spaces. Expected: `1 2 3 4 5`.
- [ ] **25. Count down.** Use a loop to print 5 through 1 on one line, separated by spaces. Expected: `5 4 3 2 1`.
- [ ] **26. Sum.** Use a loop and a `long long` accumulator to sum 1 through 100. Expected: `5050`.
- [ ] **27. While.** Starting at 1, repeatedly double a value while it is less than 20; print the final value. Expected: `32`.
- [ ] **28. Count matches.** Read `n`, then `n` integers; print how many are positive. Input: `5 -2 3 0 7 -1`. Expected: `2`.
- [ ] **29. Nested loops.** Print three lines, each containing four `*` characters. Expected:

  ```text
  ****
  ****
  ****
  ```

- [ ] **30. Break and continue.** Loop over 1 through 10; skip even numbers using `continue`, and stop before printing 7 using `break`. Print remaining values separated by spaces. Expected: `1 3 5`.

## 31–40: Strings and characters

- [ ] **31. Length.** Read a word and print its length. Input: `coding`. Expected: `6`.
- [ ] **32. Indexing.** Read a nonempty word and print its first and last characters separated by a space. Input: `apple`. Expected: `a e`.
- [ ] **33. Change a character.** Set `s = "cat"`, change its first character to `b`, and print it. Expected: `bat`.
- [ ] **34. Build a string.** Start with an empty string, append `a`, then `b`, then `c`, and print it. Expected: `abc`.
- [ ] **35. Traverse.** Count the `a` characters in `banana` using a loop over characters. Expected: `3`.
- [ ] **36. Reverse.** Reverse `stressed` in place with a standard algorithm and print it. Expected: `desserts`.
- [ ] **37. Substring.** Extract three characters from `abcdef`, starting at index 2, and print them. Expected: `cde`.
- [ ] **38. Find.** Find the first occurrence of `cat` in `concatenate`; print its zero-based position, or `-1` if absent. Expected: `3`.
- [ ] **39. Digit to integer.** Convert the character `'7'` to its numeric value and add 2. Expected: `9`.
- [ ] **40. Number conversions.** Convert the string `"123"` to an integer, add 4, convert the result back to a string, and print it. Expected: `127`.

## 41–50: Vectors and arrays

- [ ] **41. Create and index.** Create `vector<int>` containing 4, 8, 15; print its element at index 1. Expected: `8`.
- [ ] **42. Sized vector.** Create a vector of five integers initialized to 7; print its size and last element. Expected: `5 7`.
- [ ] **43. Append and remove.** Start with an empty integer vector, append 3, 5, 8, remove the last element, and print the new last element. Expected: `5`.
- [ ] **44. Read a vector.** Read `n`, then `n` integers into a vector; print the element at index 2. Input: `4 10 20 30 40`. Expected: `30`.
- [ ] **45. Indexed loop.** Print every element of `[2, 4, 6]` in order, separated by spaces, using an indexed loop. Expected: `2 4 6`.
- [ ] **46. Modify by reference.** Double every element of `[1, 2, 3]` using a range-based loop with a reference; print the elements. Expected: `2 4 6`.
- [ ] **47. Sum.** Sum `[1000000000, 1000000000, 1000000000]` with `accumulate` and a `long long` initial value. Expected: `3000000000`.
- [ ] **48. Sort.** Sort `[7, 1, 9, 1]` in ascending order and print it. Expected: `1 1 7 9`.
- [ ] **49. Fixed-size array.** Create `array<int, 3>` holding 5, 6, 7; change index 1 to 0 and print all elements. Expected: `5 0 7`.
- [ ] **50. Two dimensions.** Create a 2-by-3 `vector<vector<int>>` filled with zero; set row 1, column 2 to 9 and print that element. Expected: `9`.

## 51–60: Standard algorithms and iterators

- [ ] **51. Descending order.** Sort `[3, 9, 1, 5]` from largest to smallest; print it. Expected: `9 5 3 1`.
- [ ] **52. Reverse vector.** Reverse `[1, 2, 3, 4]` and print it. Expected: `4 3 2 1`.
- [ ] **53. Minimum and maximum.** Find the minimum and maximum elements of `[8, 3, 6]` with standard algorithms; print their values. Expected: `3 8`.
- [ ] **54. Find an element.** Use `find` to search `[4, 7, 9]` for 7. If found, print its zero-based index; otherwise print `-1`. Expected: `1`.
- [ ] **55. Lower bound.** In sorted `[1, 2, 2, 5, 8]`, print the index of the first element at least 2 using `lower_bound`. Expected: `1`.
- [ ] **56. Upper bound.** In the same vector, print the index of the first element greater than 2 using `upper_bound`. Expected: `3`.
- [ ] **57. Count.** Use `count` to count occurrences of 4 in `[4, 1, 4, 4, 2]`. Expected: `3`.
- [ ] **58. Remove duplicates.** Sort `[3, 1, 3, 2, 1]`, then use `unique` and `erase` to keep one of each value; print the vector. Expected: `1 2 3`.
- [ ] **59. Iterator traversal.** Traverse `[10, 20, 30]` with an explicit iterator from `begin()` to `end()` and print its values. Expected: `10 20 30`.
- [ ] **60. Next permutation.** Apply `next_permutation` once to `[1, 2, 3]` and print it. Expected: `1 3 2`.

## 61–70: Pairs, tuples, functions, and structs

- [ ] **61. Pair.** Create a `pair<int, string>` holding 7 and `Ada`; print its two members. Expected: `7 Ada`.
- [ ] **62. Structured binding.** Unpack the pair `(4, 9)` into two variables using structured binding; print their sum. Expected: `13`.
- [ ] **63. Sort pairs.** Sort the pairs `(2, 3)`, `(1, 9)`, `(2, 1)` using their default order; print each pair as `first,second`, separated by spaces. Expected: `1,9 2,1 2,3`.
- [ ] **64. Tuple.** Create a tuple containing integer 2, character `X`, and integer 5. Unpack it and print the values separated by spaces. Expected: `2 X 5`.
- [ ] **65. Return a value.** Write `int square(int x)` and call it for 6. Expected: `36`.
- [ ] **66. Reference parameter.** Write a function taking an `int&` that adds 5 to its argument; call it on 10 and print the changed variable. Expected: `15`.
- [ ] **67. Read-only vector parameter.** Write a function taking `const vector<int>&` that returns the first element; call it on `[8, 2]`. Expected: `8`.
- [ ] **68. Struct.** Define a `struct Player` with `string name` and `int score`; create one for `Mina`, 12, and print both fields. Expected: `Mina 12`.
- [ ] **69. Lambda comparator.** Sort `["bbb", "a", "cc"]` by increasing length using a lambda and print the words separated by spaces. Expected: `a cc bbb`.
- [ ] **70. Swap.** Swap integers 4 and 9 using `swap` and print them. Expected: `9 4`.

## 71–80: Sets and maps

- [ ] **71. Set insert.** Insert 4, 2, 4 into a `set<int>`; print its size. Expected: `2`.
- [ ] **72. Set traversal.** Insert 8, 1, 5 into a `set<int>` and print its elements in iteration order. Expected: `1 5 8`.
- [ ] **73. Membership.** Insert 3 and 7 into a set; print `YES` if it contains 7, otherwise `NO`. Expected: `YES`.
- [ ] **74. Set erase.** Insert 1, 2, 3 into a set, erase 2, and print the remaining elements. Expected: `1 3`.
- [ ] **75. Multiset.** Insert 2, 2, 5 into a `multiset<int>`; erase exactly one occurrence of 2 using an iterator, then print the elements. Expected: `2 5`.
- [ ] **76. Map lookup.** Store `cat -> 3` and `dog -> 5` in a `map<string, int>`; print the value for `dog`. Expected: `5`.
- [ ] **77. Frequency map.** Count the frequencies in `[4, 2, 4, 4, 2]` using a map; print the counts for 2 and 4. Expected: `2 3`.
- [ ] **78. Traverse map.** Insert `(3, 30)`, `(1, 10)`, `(2, 20)` into a `map<int, int>`; print each as `key:value`, separated by spaces. Expected: `1:10 2:20 3:30`.
- [ ] **79. Hash set.** Insert `red` and `blue` into an `unordered_set<string>`; print `1` if `red` exists and `0` otherwise. Expected: `1`. Do not rely on iteration order.
- [ ] **80. Hash map.** Count `a`, `b`, `a` with an `unordered_map<char, int>`; print the counts for `a` and `b` in that order. Expected: `2 1`. Do not rely on iteration order.

## 81–90: Stacks, queues, heaps, and grids

- [ ] **81. Stack.** Push 3, 5, 8 onto a `stack<int>`; pop once and print the top. Expected: `5`.
- [ ] **82. Queue.** Push 3, 5, 8 onto a `queue<int>`; pop once and print the front. Expected: `5`.
- [ ] **83. Deque.** Start with an empty `deque<int>`; push 2 at the back, 1 at the front, and 3 at the back. Print front and back. Expected: `1 3`.
- [ ] **84. Max heap.** Push 4, 9, 2 into a default `priority_queue<int>`; print the top, pop it, then print the new top. Expected: `9 4`.
- [ ] **85. Min heap.** Create a min-priority queue of integers, push 4, 9, 2, and print the top. Expected: `2`.
- [ ] **86. Grid input.** Read two rows of three integers into a 2D vector and print the value at row 1, column 0. Input: `1 2 3 4 5 6`. Expected: `4`.
- [ ] **87. Grid traversal.** For the grid `[[1, 2, 3], [4, 5, 6]]`, use nested loops to print the sum of each row on a separate line. Expected:

  ```text
  6
  15
  ```

- [ ] **88. Direction arrays.** From grid coordinate `(2, 3)`, use direction arrays for up, right, down, left; print each resulting coordinate as `row,column`, separated by spaces. Expected: `1,3 2,4 3,3 2,2`.
- [ ] **89. Visited flags.** Create a `vector<bool>` of four false values, set index 2 to true, and print the four flags as `0` or `1`, separated by spaces. Expected: `0 0 1 0`.
- [ ] **90. Adjacency list.** Create `vector<vector<int>>` for four vertices 0–3. Add directed edges `0 -> 1`, `0 -> 3`, `2 -> 0`; print the neighbors of 0 in insertion order. Expected: `1 3`.

## 91–100: Contest essentials and mixed fluency

- [ ] **91. Bit test.** Given unsigned integer `10`, print whether bit 1 and bit 2 are set, as `0` or `1` separated by a space. Bit 0 is the least significant bit. Expected: `1 0`.
- [ ] **92. Set and toggle bits.** Starting with unsigned integer 0, set bit 3, then toggle bit 1; print the resulting integer. Expected: `10`.
- [ ] **93. GCD.** Read two positive integers and print their greatest common divisor using `gcd`. Input: `18 24`. Expected: `6`.
- [ ] **94. Precision.** Read a `double` and print it using `fixed` and three digits after the decimal point. Input: `2.5`. Expected: `2.500`.
- [ ] **95. Multiple test cases.** Read `t`; for each case read two integers and print their sum on its own line. Input: `3 1 2 10 20 -1 5`. Expected:

  ```text
  3
  30
  4
  ```

- [ ] **96. Prefix sums.** For `[2, 1, 3]`, build a `long long` prefix-sum vector of length 4 with initial zero; print it. Expected: `0 2 3 6`.
- [ ] **97. Frequency array.** For `[2, 0, 2, 1, 2]`, use a vector of three counters for values 0 through 2; print the counters. Expected: `1 1 3`.
- [ ] **98. Sort and select.** Read `n` and `n` integers, with `n >= 2`; sort them and print the second element in sorted order, counting duplicates. Input: `5 8 2 2 9 4`. Expected: `2`.
- [ ] **99. Word counts.** Read `n` words and count them with a map; print the count for `apple`. Input: `4 apple pear apple plum`. Expected: `2`.
- [ ] **100. Combined routine.** Read `n` and `n` integers. Store them in a vector, sort it, then print the minimum, maximum, and `long long` sum on one line. Assume `n >= 1`. Input: `5 8 -2 4 8 1`. Expected: `-2 8 19`.

## What to do after level 100

Keep solving actual problems alongside the drills: recognizing when to combine operations is a separate skill. Revisit a level whenever its syntax slows you down, and make a personal variation using different values or a different container. If you need a feature not covered here—such as custom comparators with tie-breaks, binary search on an answer, graphs, or modular arithmetic—add a focused mini-drill when you first encounter it. This course covers common foundations, not every C++ feature or every contest technique.

Watch for the most common sources of silent errors: integer overflow before assignment, integer division, out-of-bounds indexing, empty containers, mixing signed indices with unsigned sizes, and assuming hash-container iteration is sorted. For a reminder on a specific operation, use the cheat sheet; for a problem, first identify the small operations you need and practice them separately.
