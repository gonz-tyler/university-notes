# Week 2.1: Symmetric Cryptography Revision Notes

---

## 1. Block Ciphers

A **block cipher** is a type of symmetric-key encryption that works by breaking a plaintext message into fixed-length blocks and encrypting each block one at a time.

-   **Process**:
    1.  The plaintext `P` is divided into blocks: $P_1, P_2, ...$ each of `n` bits.
    2.  Each block $P_i$ is encrypted using the same secret key `K`.
    3.  The encrypted blocks are concatenated: $E_K(P) = E_K(P_1)E_K(P_2)...$

-   **Main Types**:
    -   **Substitution Cipher**: Replaces symbols or groups of symbols with others.
    -   **Transposition Cipher**: Permutes (rearranges) the symbols within a block.
    -   **Product Cipher**: A combination of both substitution and transposition ciphers, used in modern algorithms like DES and AES.

---

## 2. The Feistel Structure

The Feistel structure is a design model for constructing block ciphers, named after IBM cryptographer Horst Feistel. It's the core structure used in the DES algorithm.

-   **Key Features**:
    -   It uses multiple rounds of processing, where each round involves a substitution step followed by a permutation step.
    -   A major advantage is that the **encryption and decryption algorithms are identical**, except for the order of the subkeys.

### Encryption Process

For each round of encryption, the input block is split into two equal halves, a Left half ($L_{i-1}$) and a Right half ($R_{i-1}$).

-   The output for round `i` is calculated as follows:
    -   $LE_{i} = RE_{i-1}$
    -   $RE_{i} = LE_{i-1} \oplus F(RE_{i-1}, K_{i})$
-   Where:
    -   `F` is the **Feistel function**, a round-specific function.
    -   $K_i$ is the subkey for round `i`.
    -   $\oplus$ denotes the XOR operation.

After the final round, the two halves ($LE_{n}$ and $RE_{n}$) are combined to form the ciphertext block.

### Decryption Process

Decryption follows the exact same logic as encryption, but the round keys ($K_1, K_2, ..., K_n$) are applied in the reverse order ($K_n, K_{n-1}, ..., K_1$). The output of each decryption round is the input to the corresponding encryption round.

---

## 3. Data Encryption Standard (DES)

DES is a symmetric-key block cipher based on the Feistel structure. It was once the dominant standard for encryption.

-   **Key Facts**:
    -   **Plaintext Block Size**: 64 bits
    -   **Ciphertext Block Size**: 64 bits
    -   **Key Size**: 56 bits (though stored as a 64-bit number with 8 parity bits).
-   **History**:
    -   Developed by IBM and adopted as a US national standard in 1976.
    -   Considered insecure by 1998 due to its small 56-bit key, which became vulnerable to brute-force attacks (e.g., the "DES Deep Crack" machine).

### DES Algorithm Structure

The DES algorithm consists of three main stages:

1.  **Stage 1: Initial Permutation (IP)**
    -   The 64-bit plaintext block is subjected to an initial, fixed permutation that rearranges the bits.
    -   The permuted block is then split into two 32-bit halves: $L_0$ and $R_0$.

2.  **Stage 2: 16 Rounds of Processing**
    -   DES uses 16 identical rounds based on the Feistel structure.
    -   For each round `i` (from 1 to 16):
        -   $L_i = R_{i-1}$
        -   $R_i = L_{i-1} \oplus f(R_{i-1}, k_i)$
    -   Each round uses a unique 48-bit subkey ($k_i$) generated from the main 56-bit key.

3.  **Stage 3: Final Permutation (FP)**
    -   After 16 rounds, the final $L_{16}$ and $R_{16}$ are combined.
    -   This 64-bit block undergoes a final permutation, which is the inverse of the Initial Permutation ($IP^{-1}$).

### Subkey Generation

Sixteen 48-bit subkeys are generated from the initial 56-bit key.

1.  **Permuted Choice 1 (PC1)**: The initial 64-bit key is passed through PC1, which discards the 8 parity bits and permutes the remaining 56 bits.
2.  **Splitting**: The 56-bit key is split into two 28-bit halves, $C_0$ and $D_0$.
3.  **Shifting**: For each of the 16 rounds, $C$ and $D$ are cyclically shifted to the left by either one or two positions.
4.  **Permuted Choice 2 (PC2)**: After each shift, the combined 56-bit block ($C_i D_i$) is passed through PC2, which compresses and permutes it to produce a 48-bit subkey, $k_i$.

### The DES `f` Function

The `f` function is the core of each DES round and takes a 32-bit R-half and a 48-bit subkey as input.

1.  **Expansion**: The 32-bit R-half is expanded to 48 bits using an expansion permutation.
2.  **XOR**: The 48-bit expanded R-half is XORed with the 48-bit round subkey.
3.  **S-Boxes**: The resulting 48 bits are divided into eight 6-bit chunks. Each chunk is fed into a corresponding S-box (Substitution Box), which outputs a 4-bit value.
4.  **Permutation (P-Box)**: The eight 4-bit outputs (32 bits total) are passed through a final permutation box (P-box).

### 3DES (Triple DES)

To overcome the small key size of DES, 3DES was introduced. It applies the DES algorithm three times.

-   **Process (DES-EDE)**:
    -   $Ciphertext = E_{k3}(D_{k2}(E_{k1}(Plaintext)))$
-   This provides a key length of $3 \times 56 = 168$ bits, making it much stronger against brute-force attacks.

---

## 4. Advanced Encryption Standard (AES)

AES is the current symmetric encryption standard, chosen by the U.S. NIST in 2001 to replace DES. The winning algorithm was **Rijndael**.

-   **Key Features**:
    -   **Block Size**: Fixed at 128 bits (16 bytes).
    -   **Key Sizes**: 128, 192, or 256 bits.
    -   **Structure**: It is **not** a Feistel network. It operates on a 4x4 matrix of bytes called the **state**.

### AES Algorithm Structure

The number of rounds depends on the key size:
-   **128-bit key**: 10 rounds
-   **192-bit key**: 12 rounds
-   **256-bit key**: 14 rounds

The high-level algorithm is:
1.  **KeyExpansion**: Derive a set of round keys from the initial cipher key.
2.  **Initial Round**:
    -   `AddRoundKey`: XOR the initial state with the first round key.
3.  **Main Rounds (Nr - 1 rounds)**: Each main round consists of four steps:
    -   `SubBytes`
    -   `ShiftRows`
    -   `MixColumns`
    -   `AddRoundKey`
4.  **Final Round**: The final round is slightly different and omits one step:
    -   `SubBytes`
    -   `ShiftRows`
    -   `AddRoundKey` (No `MixColumns` step).

### The Four Steps of an AES Round

1.  **`SubBytes` (Substitution)**
    -   A non-linear step where each byte of the state is replaced with another byte according to a lookup table called the Rijndael S-box. This provides confusion.

2.  **`ShiftRows` (Permutation)**
    -   A transposition step where the bytes in each row of the state are cyclically shifted to the left by a certain offset.
        -   Row 0: Shifted by 0 bytes (no change).
        -   Row 1: Shifted by 1 byte.
        -   Row 2: Shifted by 2 bytes.
        -   Row 3: Shifted by 3 bytes.

3.  **`MixColumns` (Mixing)**
    -   An invertible linear transformation that operates on the columns of the state. Each column is treated as a four-term polynomial and multiplied by a fixed polynomial in the Galois Field $GF(2^8)$. This provides diffusion, ensuring that the input bytes of a column affect all four output bytes.

4.  **`AddRoundKey` (Key Addition)**
    -   Each byte of the current state is combined with the corresponding byte of the round key using a bitwise XOR operation.

### AES KeyExpansion

The `KeyExpansion` routine takes the initial cipher key and expands it to generate a unique 128-bit round key for each of the `Nr+1` rounds.
