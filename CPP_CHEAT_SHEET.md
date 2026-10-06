# C++ cheat sheet for competitive programming

For a Python programmer building C++ muscle memory. Matches this repository's **GNU C++20** setup; examples use standard C++ unless explicitly marked otherwise.

**Start with sections 1–8.** Look up the later sections when a problem needs them. You do not need to memorize the whole standard library before solving problems.

Most code blocks are independent fragments to put inside `main()`. The starter program and the function/struct examples show code that belongs outside `main()` too. Variables are local to each example. All examples assume the necessary headers and `using namespace std;`.

## 1. Everyday syntax: learn this first

| What you want | C++ pattern | Python equivalent / reminder |
| --- | --- | --- |
| Integer | `int n = 0;` | Python `int` has no fixed size; C++ integers do. |
| Larger integer | `long long total = 0;` | Use for large sums and products. |
| Boolean | `bool ok = true;` | `True` / `False` become `true` / `false`. |
| Character | `char c = 'a';` | Single quotes mean one character. |
| String | `string s = "hello";` | Double quotes mean a string. |
| Read a value | `cin >> n;` | `n = int(input())` |
| Read two values | `cin >> a >> b;` | Whitespace and line breaks both separate tokens. |
| Print a value | `cout << n << '\n';` | `print(n)` |
| Print with spaces | `cout << a << ' ' << b << '\n';` | Spaces are not inserted automatically. |
| Condition | `if (x > 0) { ... }` | Parentheses and braces replace the colon/indentation. |
| Alternative | `else if (...) { ... }` | `elif` |
| Conditional value | `ok ? "YES" : "NO"` | `"YES" if ok else "NO"` |
| Loop over indices | `for (int i = 0; i < n; ++i)` | `for i in range(n)` |
| Loop over values | `for (int x : v)` | `for x in v` |
| Change each element | `for (int& x : v)` | `&` makes `x` refer to the actual element. |
| Dynamic list | `vector<int> v;` | Closest everyday equivalent to a Python list. |
| List of `n` zeros | `vector<int> v(n, 0);` | `[0] * n` |
| Append | `v.push_back(x);` | `v.append(x)` |
| Length | `v.size()` / `s.size()` | `len(v)` / `len(s)` |
| Last element | `v.back()` / `s.back()` | `v[-1]` / `s[-1]`; requires nonempty data. |
| Sort in place | `sort(v.begin(), v.end());` | `v.sort()` |
| Reverse in place | `reverse(v.begin(), v.end());` | `v.reverse()` |
| Sum | `accumulate(v.begin(), v.end(), 0LL)` | `sum(v)`; `0LL` selects a `long long` accumulator. |
| Dictionary | `map<string, int> freq;` | Sorted by key; `unordered_map` uses hashing. |
| Set | `set<int> seen;` | Stores unique values in sorted order. |
| Comment | `// explanation` | `# explanation` |

Most declarations and expression statements end in `;`. An `if` or loop block does not need a semicolon after its closing brace. A `struct` definition does.

## 2. Starter program and headers

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read input, compute the answer, print output.

    return 0;
}
```

The two fast-I/O lines go before input/output. With synchronization disabled, keep using `cin`/`cout` instead of mixing them with `scanf`/`printf`. For interactive problems, explicitly flush when required.

| Header | Useful names |
| --- | --- |
| `<iostream>` | `cin`, `cout`, `cerr` |
| `<string>` | `string`, `to_string`, `stoi`, `stoll` |
| `<vector>`, `<array>` | `vector`, `array` |
| `<algorithm>` | `sort`, `reverse`, `min`, `max`, `find`, bounds, permutations |
| `<numeric>` | `accumulate`, `iota`, `gcd`, `lcm` |
| `<map>`, `<unordered_map>` | `map`, `unordered_map` |
| `<set>`, `<unordered_set>` | `set`, `multiset`, `unordered_set` |
| `<queue>`, `<stack>`, `<deque>` | `queue`, `priority_queue`, `stack`, `deque` |
| `<utility>`, `<tuple>` | `pair`, `tuple` |
| `<functional>` | `greater<int>` |
| `<iomanip>` | `fixed`, `setprecision` |
| `<cmath>`, `<cstdlib>` | `sqrt`, `abs` overloads |
| `<cctype>` | `isdigit`, `tolower`, `toupper` |
| `<limits>` | `numeric_limits` |
| `<bit>` | C++20 `popcount` |
| `<cassert>` | `assert` |

GNU shortcut: `#include <bits/stdc++.h>` includes many headers with GCC/libstdc++; it is not a standard C++ header. Explicit headers help you learn which library provides what. `using namespace std;` is convenient in small contest files; without it, write `std::vector`, `std::cout`, etc.

## 3. Types, arithmetic, and operators

```cpp
int count = 0;
long long total = 0;
double average = 0.0;
bool found = false;
char letter = 'a';
string name = "Ada";
const int LIMIT = 100000;
constexpr long long MOD = 1000000007LL;
auto value = 42;  // Deduces int; it does not become dynamically typed.
```

In this repository's GCC target, `int` is 32-bit (about ±2.1 billion) and `long long` is 64-bit (about ±9.2 quintillion). `long` is not a portable substitute for `long long`.

| Operation | C++ | Reminder |
| --- | --- | --- |
| Assign / compare | `x = 5` / `x == 5` | `=` changes a value; `==` compares. |
| Other comparisons | `!=`, `<`, `<=`, `>`, `>=` | Same familiar meanings. |
| Logic | `a && b`, `a \|\| b`, `!a` | Python `and`, `or`, `not`. |
| Arithmetic | `+`, `-`, `*`, `/`, `%` | `%` requires integer operands. |
| Update | `x += 3;`, `x -= 3;`, `x *= 2;` | Also `/=` and `%=`. |
| Increment / decrement | `++x;`, `--x;` | Prefix is a good loop habit. |
| Conditional value | `condition ? a : b` | An expression, so it can be printed or assigned. |

```cpp
int a = 100000, b = 100000;
long long product = 1LL * a * b;  // Widen BEFORE multiplication.
double ratio = static_cast<double>(a) / b;
int truncated = 7 / 2;           // 3
double precise = 7.0 / 2;        // 3.5
int negative = -7 / 2;           // -3: integer division truncates toward zero.
int remainder = -7 % 2;          // -1: unlike Python's positive-modulus result.
long long x = -7, mod = 5;       // mod must be positive.
long long normalized = ((x % mod) + mod) % mod;
```

`long long product = a * b;` can still overflow because two `int`s are multiplied first. Signed overflow is undefined behavior. Keep the intermediate calculations within the chosen type's range.

Avoid `pow(a, b)` for exact integer powers: it uses floating-point arithmetic. For a square, write `1LL * a * a`; use integer multiplication or a suitable integer-power algorithm for other powers.

## 4. Input and output

```cpp
int n;
long long k;
string word;
char c;
cin >> n >> k >> word >> c;
cout << n << ' ' << word << '\n';
```

`cin >> word` reads one whitespace-delimited word. To read a whole line:

```cpp
string line;
getline(cin, line);  // Includes spaces; does not include the terminating newline.
```

When switching from `>>` to `getline`, consume the rest of the current line first:

```cpp
int n;
cin >> n;
cin.ignore(numeric_limits<streamsize>::max(), '\n');
string line;
getline(cin, line);  // Reads the next line, preserving its leading spaces.
```

For a line whose leading whitespace and blank lines do not matter, `getline(cin >> ws, line);` is a shorter option. `ws` skips all leading whitespace, including blank lines.

```cpp
double answer = 1.0 / 3.0;
cout << fixed << setprecision(6) << answer << '\n';  // 0.333333
cerr << "debug: " << answer << '\n';                // Separate diagnostic stream.
```

Use `'\n'` for ordinary output. `endl` also flushes the stream, which can slow down large output. Print only what the statement requests.

## 5. Conditions and loops

```cpp
int x = 4;
if (x > 0) {
    cout << "positive\n";
} else if (x == 0) {
    cout << "zero\n";
} else {
    cout << "negative\n";
}
cout << (x > 0 ? "YES" : "NO") << '\n';
```

```cpp
int n = 5;
for (int i = 0; i < n; ++i) {      // 0, 1, ..., n - 1
    cout << i << ' ';
}
for (int i = n - 1; i >= 0; --i) { // n - 1, ..., 0
    cout << i << ' ';
}

vector<int> v = {2, 4, 6};
for (int x : v) cout << x << ' ';  // Copies each integer.
for (int& x : v) x += 1;          // Modifies each stored integer.

vector<string> words = {"red", "blue"};
for (const auto& word : words) {  // Read without copying each string.
    cout << word << '\n';
}
```

`while (condition) { ... }` repeats while its condition is true. `break;` exits the nearest loop; `continue;` skips to its next iteration. In nested loops, `break` exits only the inner loop.

Only use a test-case loop when the statement gives a test-case count:

```cpp
int t;
cin >> t;
while (t--) {
    // Declare/reset this case's variables here, then read and solve it.
}
```

## 6. Vectors and arrays

```cpp
int n = 5, m = 3;
vector<int> v(n);                  // n zeros.
vector<int> filled(n, -1);         // n copies of -1.
vector<int> values = {8, 3, 5};
vector<string> words(n);           // n empty strings.
vector<vector<int>> grid(n, vector<int>(m, 0));

for (int& x : v) cin >> x;         // Read n integers.
values.push_back(7);               // Add at the end.
values.pop_back();                 // Remove last; does not return it.
cout << values[0] << ' ' << values.back() << '\n';
cout << values.size() << ' ' << values.empty() << '\n';
values.resize(5, 0);               // Size becomes 5; new entries are zero.
values.clear();                   // Size becomes zero.
```

- Indices are `0` through `size() - 1`. There is no negative indexing.
- `v[i]` does not check bounds. `v.at(i)` checks and throws on an invalid index.
- `front()`, `back()`, and `pop_back()` require a nonempty vector.
- `reserve(n)` reserves storage; it **does not create elements**. Use `resize(n)` or `vector<int> v(n)` before indexing `0..n-1`.
- `size()` is unsigned. For contest inputs known to fit in `int`, `int n = static_cast<int>(v.size());` simplifies index arithmetic. Avoid `v.size() - 1` when the vector might be empty.
- Adding/removing elements can invalidate iterators and references. Do not change a vector's size inside a range-based loop over that vector.

For a fixed, compile-time size:

```cpp
array<int, 5> a{};  // Five zeros; requires <array>.
int b[5]{};        // Built-in array; also five zeros.
```

If `n` comes from input, use `vector<int> a(n);`. `int a[n];` is a GCC extension when `n` is known only at runtime, not standard C++.

## 7. Strings and characters

```cpp
string s = "contest";
cout << s.size() << ' ' << s[0] << ' ' << s.back() << '\n';
s[0] = 'C';                       // C++ strings are mutable.
s += '!';                         // Append a character.
s += " today";                    // Append a string.
string part = s.substr(1, 3);      // Start at index 1, take 3 characters.
string tail = s.substr(2);         // From index 2 to the end.
auto pos = s.find("test");
if (pos != string::npos) cout << pos << '\n';
reverse(s.begin(), s.end());

string repeated(4, 'x');           // "xxxx"
string digits = to_string(123);    // "123"
int value = stoi("123");           // 123
long long big = stoll("10000000000");
int digit = '7' - '0';             // 7, for a character '0'..'9'.
char c = 'A';
char lower = static_cast<char>(tolower(static_cast<unsigned char>(c)));
```

Python `s[l:r]` becomes `s.substr(l, r - l)` for valid nonnegative bounds. The second argument is a **length**, not an ending index. `stoi`/`stoll` can throw if input is invalid or out of range; they do not require the entire string to be numeric.

`'a' + 'b'` adds character values; it does not make `"ab"`. To concatenate, start with a string: `string(1, 'a') + 'b'`. Comparisons like `s == "hello"` and `s < other` work; ordering is lexicographic.

## 8. Functions, copies, and references

```cpp
// Define these outside main(), before any call to them.
long long square(long long x) {
    return x * x;  // Assumes the result fits in long long.
}

long long total(const vector<int>& v) {
    return accumulate(v.begin(), v.end(), 0LL);
}

void add_one(vector<int>& v) {
    for (int& x : v) ++x;
}
```

| Parameter / variable | Meaning |
| --- | --- |
| `int x` | A copy; changing it does not change the caller's integer. |
| `vector<int> v` | A copy of the whole vector. |
| `vector<int>& v` | A reference; changes affect the caller's vector. |
| `const vector<int>& v` | Read the caller's vector without copying or modifying it. |
| `auto x = v;` | A copy of `v`. |
| `auto& x = v;` | Another name for `v`. |

Copying a vector or string is different from Python assigning another name to the same list. Use `const auto&` when looping over larger objects you only need to read. A `void` function returns no value; `return;` exits it early. Deep recursion can exhaust the stack.

## 9. Iterators and everyday algorithms

An iterator identifies a position in a container. `begin()` points to the first element; `end()` points **one past** the last. Library ranges are usually `[first, last)`: the last position is excluded. Never dereference `end()`.

```cpp
vector<int> v = {4, 1, 4, 2};
sort(v.begin(), v.end());                 // Ascending.
sort(v.rbegin(), v.rend());               // Descending.
reverse(v.begin(), v.end());
long long sum = accumulate(v.begin(), v.end(), 0LL);
int smallest = *min_element(v.begin(), v.end());  // v must be nonempty.
int largest = *max_element(v.begin(), v.end());   // v must be nonempty.
auto it = find(v.begin(), v.end(), 4);
if (it != v.end()) cout << (it - v.begin()) << '\n';
auto occurrences = count(v.begin(), v.end(), 4);
fill(v.begin(), v.end(), 0);
iota(v.begin(), v.end(), 0);               // 0, 1, 2, ...
```

Additional patterns:

| Task | Pattern | Requirement / effect |
| --- | --- | --- |
| Smaller / larger of two values | `min(a, b)` / `max(a, b)` | Usually give both arguments the same type. |
| Minimum of several values | `min({a, b, c})` | Requires `<algorithm>`; same element type. |
| Swap values | `swap(a, b);` | Works for common types and containers. |
| Sort a slice | `sort(v.begin() + l, v.begin() + r);` | Valid indices, `l <= r`; sorts `[l, r)`. |
| Sort by custom rule | `sort(v.begin(), v.end(), comparator);` | Comparator must use a strict ordering. |
| Remove duplicate values | `sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());` | Sorts first; `unique` alone only groups adjacent duplicates. |
| Next permutation | `next_permutation(v.begin(), v.end())` | Returns whether a next lexicographic arrangement exists. |

`sort` is `O(n log n)`; searching with `find`, counting, summing, reversing, and finding a minimum are `O(n)`. Include `<algorithm>` for these algorithms and `<numeric>` for `accumulate`/`iota`.

## 10. Binary search on sorted vectors

```cpp
vector<int> v = {1, 3, 3, 7};     // Must be sorted ascending for these calls.
int x = 3;
auto lo = lower_bound(v.begin(), v.end(), x); // First value >= x.
auto hi = upper_bound(v.begin(), v.end(), x); // First value > x.
bool exists = binary_search(v.begin(), v.end(), x);
cout << (lo - v.begin()) << ' ' << (hi - lo) << '\n'; // 1 2
if (lo != v.end()) cout << *lo << '\n';
```

These searches take `O(log n)` on a vector. Their iterators may equal `end()`. For `set`/`map`, use the container's own `.lower_bound(x)` / `.upper_bound(x)` to get logarithmic lookup; the generic algorithms can take linear iterator movement there.

## 11. Pairs, tuples, structs, and custom sorting

```cpp
pair<int, int> p = {3, 7};
cout << p.first << ' ' << p.second << '\n';
auto [a, b] = p;                    // Structured binding: copies the values here.
tuple<int, string, int> record = {5, "Ada", 9};
cout << get<1>(record) << '\n';

vector<pair<int, int>> items = {{2, 8}, {1, 9}, {2, 3}};
sort(items.begin(), items.end());   // First component, then second.
sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
});                               // Second component, then first.
```

Use `<`, not `<=`, in a sorting comparator. Equal values must not be considered smaller than themselves. A lambda is an inline function: `[]` captures nothing; `[&]` captures surrounding variables by reference; `[=]` captures used surrounding values by copy.

```cpp
// Put a struct definition outside main() when sharing it across functions.
struct Item {
    int id;
    long long cost;
};  // This semicolon is required.
```

Then `Item item{1, 50};`, `item.cost`, and `vector<Item> items;` work inside your program. Learn structs when named fields make your code clearer.

## 12. Maps and frequency counting

```cpp
map<string, int> freq;
++freq["apple"];                       // Missing key starts with integer value 0.
freq["pear"] = 3;
if (freq.find("apple") != freq.end()) {
    cout << freq.at("apple") << '\n';
}
if (freq.contains("pear")) cout << "present\n"; // C++20.
for (const auto& [key, value] : freq) {
    cout << key << ' ' << value << '\n';        // Sorted by key.
}
freq.erase("pear");

unordered_map<int, int> counts;
++counts[42];                                 // Hashed keys, unspecified order.
```

`m[key]` **inserts** a missing key with a default value, even when you only meant to check it. Use `find`, `contains` (C++20), or `count` for membership; `at` accesses an existing key and throws if it is absent.

`map` lookup/insertion is `O(log n)`. `unordered_map` lookup/insertion is average `O(1)`, worst-case `O(n)`. Use `map` when key order or predictable lookup complexity matters. For a small known integer domain, a frequency `vector<int>` can be simpler.

## 13. Sets and multisets

```cpp
set<int> seen;
seen.insert(5);
seen.insert(2);
seen.insert(5);                    // Still only one 5.
bool has_five = seen.contains(5);  // C++20; alternatively seen.count(5) > 0.
auto it = seen.lower_bound(3);     // First element >= 3.
if (it != seen.end()) cout << *it << '\n';
cout << *seen.begin() << ' ' << *seen.rbegin() << '\n'; // Nonempty set.
seen.erase(5);

multiset<int> bag = {2, 2, 5};
auto one = bag.find(2);
if (one != bag.end()) bag.erase(one); // Removes one occurrence.
bag.erase(2);                        // Removes ALL remaining occurrences of 2.
```

`set` stores distinct sorted keys; `multiset` allows duplicates. Lookup/insertion and erasing one element are `O(log n)`; erasing all copies also costs time proportional to the copies removed. `unordered_set` is a hashed alternative with unspecified iteration order and average `O(1)` lookup/insertion, worst-case `O(n)`.

## 14. Queue, stack, deque, and priority queue

```cpp
queue<int> q;                      // First in, first out.
q.push(10);
int first = q.front();
q.pop();                          // Removes; does not return a value.

stack<int> st;                     // Last in, first out.
st.push(10);
int last = st.top();
st.pop();

deque<int> d;                      // Insert/remove at either end.
d.push_back(2);
d.push_front(1);
d.pop_back();
d.pop_front();

priority_queue<int> max_heap;      // Largest value at top().
max_heap.push(8);
max_heap.push(3);
cout << max_heap.top() << '\n';    // 8
max_heap.pop();

priority_queue<int, vector<int>, greater<int>> min_heap;
min_heap.push(8);
min_heap.push(3);
cout << min_heap.top() << '\n';    // 3
```

All have `.empty()` and `.size()`. Check that they are nonempty before accessing/removing an element. Queue/stack/deque operations at the supported ends are `O(1)`; heap insertion/removal is `O(log n)` and `.top()` is `O(1)`. A priority queue does not support arbitrary indexing or general iteration.

## 15. Integer math and bits: learn as needed

```cpp
long long a = 24, b = 18;
cout << gcd(a, b) << ' ' << lcm(a, b) << '\n'; // <numeric>; result must fit.
cout << abs(-12LL) << '\n';                   // Not valid for LLONG_MIN.

long long n = 10, d = 3;                     // n >= 0, d > 0.
long long rounded_up = n / d + (n % d != 0); // Ceiling without n + d overflow.

unsigned long long mask = 10;                // Binary 1010.
int k = 1;                                  // Keep shift counts within 0..63.
bool bit_set = (mask & (1ULL << k)) != 0;
mask |= (1ULL << k);                         // Set bit k.
mask &= ~(1ULL << k);                        // Clear bit k.
mask ^= (1ULL << k);                         // Toggle bit k.
int ones = popcount(mask);                   // C++20, <bit>, unsigned input.
```

Bit operators: `&` AND, `|` OR, `^` XOR, `~` NOT, `<<` left shift, `>>` right shift. **`^` is not exponentiation.** These differ from logical `&&`/`||`. Use parentheses around bit tests. Do not shift by a negative count or a count at least as large as the type's bit width.

## 16. Python-to-C++ traps worth remembering

| Python habit | C++ habit to build |
| --- | --- |
| Integers grow automatically. | Check ranges; widen operands before multiplication. |
| A list variable can refer to the same list. | `vector` assignment makes a copy; `&` makes a reference. |
| Negative indexing works. | Use `.back()` or a valid nonnegative index. |
| `//` floors integer division. | Integer `/` truncates toward zero, including negative operands. |
| `%` is nonnegative for a positive divisor. | A negative dividend can give a negative remainder. |
| Strings cannot be modified in place. | `s[i] = 'x';` can change a C++ string. |
| `s[l:r]` takes an end index. | `s.substr(l, r - l)` takes a length. |
| `a < b < c` is a chained comparison. | Write `a < b && b < c`; chaining gives a different result. |
| Printing inserts separators and a newline. | Add `' '` and `'\n'` explicitly. |
| Removing the last list element returns it. | Read `.back()`/`.top()`/`.front()` first, then call `pop`. |
| A missing dictionary lookup raises an error. | `map[key]` inserts a default value. |
| A container's truth value shows emptiness. | Use `!v.empty()` or `v.empty()`. |
| Indentation determines blocks. | Braces determine blocks; indentation is for humans. |

Also watch for uninitialized local numbers (`int x;` before assignment), `if (condition);` with an accidental semicolon, indices equal to `size()`, and data left over between test cases. Ordinary `vector<int> v(n)` elements are zero-initialized; an uninitialized local built-in array is not.

## 17. Compile, run, and debug in this repository

In VS Code, use **Terminal → Run Build Task → build current C++ file** to select the configured GNU C++20 build. This repository also has a generated default build task, so select the named task explicitly when you want these settings.

From PowerShell, in the folder containing `solution.cpp`:

```powershell
g++ -std=gnu++20 -Wall -Wextra -Wshadow -O2 -g solution.cpp -o solution.exe
.\solution.exe
```

If `g++` is not on that terminal's PATH, use the configured compiler's full path:

```powershell
& 'C:\msys64\ucrt64\bin\g++.exe' -std=gnu++20 -Wall -Wextra -Wshadow -O2 -g solution.cpp -o solution.exe
```

Compile first and run only after a successful build, so you do not accidentally execute an old executable. `-Wall -Wextra -Wshadow` enable helpful warnings; `-g` adds debug information. For an extra standards check, use `-std=c++20 -pedantic-errors` to reject extensions such as runtime-sized built-in arrays.

`assert(condition);` from `<cassert>` stops the program if a checked assumption is false (unless assertions are disabled). Use `cerr` for temporary diagnostics, and start with the **first** compiler error; later ones may follow from it.

## 18. A five-minute muscle-memory routine

1. Close this sheet and type the starter program from memory.
2. Read `n` integers into a vector and print them with spaces and a final newline.
3. Type a loop that modifies every element, then sort the vector and compute a `long long` sum.
4. Read a string, access a character, take a substring, and append a character.
5. Compile, check the first error or warning, and look up only what you forgot. Repeat that pattern from memory tomorrow.

Start with those patterns. Add maps, sets, binary search, and heaps as exercises require them. Type examples yourself instead of copying them every time.

For now, an easy problem can train implementation even when you already know the algorithm. As a practical progression rule, after several problems where you can implement and test without consulting basic syntax, add 900–1100-rated problems and keep occasional easy ones as warm-ups. Increase difficulty when the work becomes routine; a particular rating or number of problems is not a requirement.

## References for checking details

These are reference documentation, not extra reading you need to complete before practising:

- Compiler options: [GCC C++ dialect options](https://gcc.gnu.org/onlinedocs/gcc/C_002b_002b-Dialect-Options.html) and [runtime-sized arrays as an extension](https://gcc.gnu.org/onlinedocs/gcc/Variable-Length.html).
- Types and references: [Microsoft C++ built-in types](https://learn.microsoft.com/en-us/cpp/cpp/fundamental-types-cpp?view=msvc-170) and [references](https://learn.microsoft.com/en-us/cpp/cpp/references-cpp?view=msvc-170).
- Containers: [vector](https://learn.microsoft.com/en-us/cpp/standard-library/vector-class?view=msvc-170), [string](https://learn.microsoft.com/en-us/cpp/standard-library/basic-string-class?view=msvc-170), [map](https://learn.microsoft.com/en-us/cpp/standard-library/map-class?view=msvc-170), and [set](https://learn.microsoft.com/en-us/cpp/standard-library/set-class?view=msvc-170).
- Algorithms: [algorithm functions](https://learn.microsoft.com/en-us/cpp/standard-library/algorithm-functions?view=msvc-170) and [numeric functions](https://learn.microsoft.com/en-us/cpp/standard-library/numeric-functions?view=msvc-170).
