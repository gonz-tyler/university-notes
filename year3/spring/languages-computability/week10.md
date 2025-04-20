# Week 10: P and NP Classes

## Notes
---

### 1. Nondeterministic Turing Machines (NTMs)
- **Definition**: 7-tuple `(Q, Σ, Γ, δ, q₀, q_accept, q_reject)` where δ is a relation (not function)
- **Acceptance**: NTM accepts w if at least one computational path reaches `q_accept`
- **Time Complexity**: Maximum steps on any branch for input length n

### 2. Model Comparisons
- **NTM vs DTM**: NTMs can be simulated by DTMs with exponential time overhead (`2^O(t(n))`)
- **Polynomial Equivalence**: All reasonable deterministic models are polynomially equivalent

### 3. Complexity Classes
#### P (Polynomial Time)
- `P = ∪ TIME(nᵏ)` for k ≥ 0
- Problems solvable in polynomial time on deterministic TM
- Example: `{0ᵏ1ᵏ | k ≥ 0} ∈ P`

#### NP (Nondeterministic Polynomial Time)
Two equivalent definitions:
1. **Verifier Definition**: Languages with polynomial-time verifiers
   - `A = {w | V accepts ⟨w,c⟩ for some c}`
   - Example: COMPOSITES has verifier that checks `x = pq`
2. **NTM Definition**: `NP = ∪ NTIME(nᵏ)`

#### coNP
- Languages where non-membership can be verified quickly
- `A ∈ coNP` iff `A = {w | V rejects ⟨w,c⟩ for some c}`

### 4. Important Problems
- **PATH**: `{⟨G,s,t⟩ | directed path from s to t}` (∈ P)
- **HAMPATH**: Hamiltonian path problem (∈ NP)
- **CLIQUE**: `{⟨G,k⟩ | G has k-clique}` (∈ NP)
- **SUBSET-SUM**: `{⟨S,t⟩ | subset sums to t}` (∈ NP)

### 5. NP-Completeness
#### Key Concepts
- **Reduction**: `A ≤ₚ B` means B is at least as hard as A
- **NP-Complete**: 
  1. `L ∈ NP`
  2. Every NP problem reduces to L
- **Implications**:
  - If any NP-complete problem ∈ P, then P = NP
  - NP-complete problems are the hardest in NP

#### Cook-Levin Theorem
**SAT is NP-Complete**
- SAT = `{φ | Boolean formula φ is satisfiable}`
- Proof outline:
  1. SAT ∈ NP (easy to verify assignments)
  2. For any `A ∈ NP`, show `A ≤ₚ SAT`:
     - Encode NTM computation as polynomial-size formula
     - Variables represent tableau cells
     - Constraints ensure valid computation

### 6. Open Questions
- **P vs NP**: Whether P = NP (unresolved)
- **NP vs coNP**: Whether NP = coNP (believed unequal)

## Key Theorems
1. **Polynomial Reduction**: If `A ≤ₚ B` and `B ∈ P`, then `A ∈ P`
2. **NP-Completeness Propagation**: If B is NP-complete and `B ≤ₚ C`, then C is NP-complete
3. **P=NP Implication**: If any NP-complete problem ∈ P, then P = NP

## Complexity Hierarchy
```
EXPTIME
│
├── NP
│ ├── NP-complete (e.g., SAT, HAMPATH, CLIQUE)
│ └── P (e.g., PATH)
│
└── coNP
└── coNP-complete
```

## Key Takeaways
- **P**: Problems solvable quickly
- **NP**: Problems verifiable quickly
- **NP-complete**: Hardest problems in NP
- **Reductions**: Tool to prove problem hardness
- **SAT**: First proven NP-complete problem
- **Practical Impact**: NP-complete problems lack known efficient solutions
