# Week 09: Time Complexity

## Notes
---

### 1. Time Complexity Basics
- **Definition**: For a deterministic TM `M` that halts on all inputs, the time complexity is the function `f(n)` representing the maximum number of steps `M` uses on any input of length `n`.
- **Input Parameters**: Typically measured by input string length, but can vary (e.g., nodes in a graph, pixels in an image).
- **Simplification**: Complex expressions like `9n⁵ + 5n² + n log n` are approximated as `O(n⁵)`.

### 2. Big-O and Small-o Notation
- **Big-O (O)**:
  - `f(n) = O(g(n))` if `f(n) ≤ c·g(n)` for some `c > 0` and all `n ≥ n₀`
  - Example: `3n log n + 5n log log n + 2 = O(n log n)`
- **Small-o (o)**:
  - `f(n) = o(g(n))` if `lim(n→∞) f(n)/g(n) = 0`
  - Example: `2n² = O(n²)` but `2n² ≠ o(n²)`

### 3. Example: Deciding A = {0ᵏ1ᵏ | k ≥ 0}
#### Single-Tape TM M₁:
- **Steps**:
  1. Check 0s before 1s (`O(n)`)
  2. Cross off pairs of 0s and 1s (`O(n²)`)
  3. Final check (`O(n)`)
- **Total Time**: `O(n²)`

#### Optimized Single-Tape TM M₂:
- **Steps**:
  1. Check 0s before 1s (`O(n)`)
  2. Cross off every other 0 and 1 (`O(n log n)`)
  3. Final check (`O(n)`)
- **Total Time**: `O(n log n)`

#### Two-Tape TM M₃:
- **Steps**:
  1. Copy 0s to second tape (`O(n)`)
  2. Cross off 0s while scanning 1s (`O(n)`)
- **Total Time**: `O(n)`

### 4. Complexity Classes
- **TIME(t(n))**: Class of languages decidable by a TM in `O(t(n))` time
  - Example: `A ∈ TIME(n²)` and `A ∈ TIME(n log n)`
- **Lower Bound**: For `f(n) = o(n log n)`, `TIME(f(n))` contains only regular languages. Since `A` is not regular, it cannot be decided in `o(n log n)` time on a single-tape TM.

### 5. Model Comparisons
- **Multi-Tape vs. Single-Tape TMs**:
  - **Proposition**: A `t(n)`-time multi-tape TM can be simulated by a single-tape TM in `O(t²(n))` time
  - **Implication**: Time complexity differences between models are polynomial, not exponential

## Key Takeaways
- **Time Complexity**: Measures the maximum steps a TM takes for inputs of length `n`
- **Asymptotic Notation**: Big-O and small-o simplify analysis by focusing on dominant terms
- **Optimization**: Algorithm improvements can reduce time complexity (e.g., from `O(n²)` to `O(n log n)`)
- **Model Impact**: Multi-tape TMs can solve problems faster, but single-tape simulations remain polynomial
- **Lower Bounds**: Some problems have inherent time complexity limits (e.g., `Ω(n log n)` for non-regular languages)

## Hierarchy of Language Classes
`Regular ⊂ Context-Free ⊂ Context-Sensitive ⊂ Decidable ⊂ Turing-Recognizable`


## Time Complexity Classes
- `TIME(n)`, `TIME(n log n)`, `TIME(n²)`, etc.
- `A ∈ TIME(n log n)` but `A ∉ TIME(o(n log n))` for single-tape TMs
