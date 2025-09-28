# Practical 02
## Introduction to Cryptography

### Classical Cryptography
1. The original Caesar cipher is a monoalphabetic substitution cipher, in which each character is shifted forward by (k =) three places in the alphabet. Thus for English, each occurrence of A is enciphered as D, each occurrence of B is enciphered as E and so on, until W enciphered by Z, but then X is enciphered by A, Y is enciphered by B and Z is enciphered by C. We will refer to a Caesar cipher as a cipher of this form for which characters are shifted forward by some fixed k, not necessarily just k = 3. Let each character correspond to its position in the alphabet, counting from 0 at A , as in Table 1. Explain how the Caesar cipher 1 can be regarded as addition in modular arithmetic, giving the relevant formulae for encipherment and decipherment. [E,*]

| A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z |
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15| 16| 17| 18| 19| 20| 21| 22| 23| 24| 25|
  *Table 1: Position of letters in English alphabet for modular manipulation*

2. Decipher the following ciphertext, which was enciphered using the Caesar cipher:
  TEBK FKQE BZLR OPBL CERJ XKBS BKQP
You will have to find the number of places of the shift. [M,*]

3. The Vigenere cipher is an example of a polyalphabetic substiution cipher. The subkey used to encipher each character changes with the position of the character in the text. [E,*]

| | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| **A** | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z |
| **B** | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A |
| **C** | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B |
| **D** | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C |
| **E** | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D |
| **F** | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E |
| **G** | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F |
| **H** | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G |
| **I** | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H |
| **J** | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I |
| **K** | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J |
| **L** | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K |
| **M** | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L |
| **N** | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M |
| **O** | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N |
| **P** | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O |
| **Q** | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P |
| **R** | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q |
| **S** | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R |
| **T** | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S |
| **U** | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T |
| **V** | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U |
| **W** | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V |
| **X** | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W |
| **Y** | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X |
| **Z** | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y |
  *Table 2: The Vigenere Square*

The subkey is chosen using a chosen keyword and the Vignere square shown in *Table 2*. In such tables a row is a horizontal row all the way through the table (and so one copy of the alphabet, cycled a bit), and a column is a vertical column all the way through the table (and so one copy of the alphabet, cycled a bit). For example, suppose the keyword is KEYWORD which has seven characters, Suppose that we are enciphering
  SECRETSQUIRRELSSECRETESECRETSAUCE
which has 33 characters. First expand the keyword to the length of the message, by repeating. So it becomes
  KEYWORDKEYWORDKEYWORDKEYWORDKEYWO
with 33 characters. To encipher the first character, take the first character of the expanded keyword, here this is K. The current sub-key is the row of the square labelled by K. This row reads KLM . . .. Select the column with S at the top. Where the selected column and row intersect we find the letter C, and this is the enciphered character corresponding to the first S. To encipher the second character, take the second letter of the expand keyword, here this is E. The current sub-key is the row labelled by E. This row reads EF G . . .. The second letter to be enciphered is E, so we look at the column of the square labelled by E. Where the row and column intersect we find the letter I, and this gives the enciphered version of the second character E. When we get to the eight character to encipher Q use the eigth letter of the expanded keyword. This is K. And so on. 
  (a) Encipher at least five more letters from the given plaintext. [E,*]
  (b) How does decipherment work (given the key and ciphertext)? [M,*]

4. A more mathematical description of the Vigenere cipher can be given. Suppose that the expanded keyword has n characters and the *ith* letter corresponds to the integer ki for 1 ≤ i ≤ n. For the example of the previous question, k2 = 4 corresponding to the character E. Show that the formula ci = pi + ki mod 26 describes the Vigen`ere cipher, where ci, pi are the respective integer codes corresponding to the *ith* ciphertext and plaintext characters for 1 ≤ i ≤ length(plaintext). How does decipherment work in these terms? [E, *]

5. You have found an old ciphertext, where you know that the plaintext discusses cryptographic methods. You suspect that a Vigen`ere cipher has been used and therefore look for repeated strings in the ciphertext. You find that the string
  TICRMQUIRTJR
occurs twice in the ciphertext. The first occurrence starts at character position 10 in the text and the second at character position 241 (we start counting from 1). You make the inspired guess that this ciphertext sequence is the encryption of the plaintext word 
  CRYPTOGRAPHY
If this guess is correct, what is the key? Hint: Analyse the possible periods. [M, *]

6. Explain why a monoalphabetic substitution cipher does not provide any diffusion. [E, *]

7. The following text is encrypted using a simple substitution method:
  ODQSOCL OW GIU BOEE QRROHOCS QV GIUR KIA QF Q DQCQSLR WIR ICL IW CQFQF EIYQE YIDJUVLR FGFVLDF GIU SLV OCVI GIUR IWWOYL IC VXQV DICPQG DIRCOCS VI WOCP VXL JXICLF ROCSOCS LHLRG YQEELR OF Q POFVRQUSXV YICWUFLP CQFQ BIRMLR QCP LHLRG YQEELR QFFURLF GIU VXQV XOF IR XLR WOEL IR QYYIUCVOCS RLYIRP IR RLFLQRYX JRIKLYV LHLRG ICL IW BXOYX OF DOFFOCS WRID VXL YIDJUVLR FGFVLD OF QAFIEUVLEG HOVQE

| Letter | Probability |
|--------|-------------|
| A | 8.2% |
| B | 1.5% |
| C | 2.8% |
| D | 4.3% |
| E | 12.7% |
| F | 2.2% |
| G | 2.0% |
| H | 6.1% |
| I | 7.0% |
| J | 0.2% |
| K | 0.8% |
| L | 4.0% |
| M | 2.4% |
| N | 6.7% |
| O | 7.5% |
| P | 1.9% |
| Q | 0.1% |
| R | 6.0% |
| S | 6.3% |
| T | 9.1% |
| U | 2.8% |
| V | 1.0% |
| W | 2.3% |
| X | 0.1% |
| Y | 2.0% |
| Z | 0.1% |

  *Table 3: Distribution of the characters in a typical English text*

The plaintext is part of an English text encoded in upper case characters without punctuation marks. Using the distribution of the characters in English texts (see Table 3), recover the plaintext. This question may take quite a lot of work to answer. [H]

### Mathematical Background

These are background questions to make sure that you have all the background, and to remind you in case you have forgotten it. They are not really the main point of this tutorial.

1. This is a question about the size of a key space K. The size of the keyspace is the size (cardinality) of the set K, written |K|. Suppose keys are composed of a finite sequence of bits (binary digits (0 and 1)). Suppose that finite sequence of bits in the key is of fixed length n.
  (a) If n = 1, explain why the keyspace has size 2.
  (b) If n = 2, explain why |K| = 2 × 2 = 22 = 4.
  (c) Prove that |K| = 2n for any n by mathematical induction.

2. This is a question about O-notation for orders of magnitude. Consider two function f, g : N → N on the natural numbers. The function f is said to be O(g) if for some m, we have f (n) ≤ g(n) for all n ≥ m. Consider a function f that takes the length of keys (of a fixed length in a given keyspace), and outputs the number of possible keys of that length. Use Question 1 to argue that f (n) is O(2n).

3. FACT 1: Given a positive integer n and non-negative integer m, there is a unique pair of non-negative integers (q, r), the quotient and remainder, respecively, with 0 ≤ r < n such that m = nq + r. This is just the usual definition of integer division of m by n, although some may not have seen it stated exactly like this. 
   FACT 2: When r is the remainder of division of m by n, then r = m mod n.
Use these facts to simplify 15 mod 12 and 31 mod 26 to their smallest non-negative values.

4. The notation |x| stands for the absolute value of x: if x is non-negative, then |x| = x, but if x is negative, then |x| = −x; for exampe | − 3| = 3. It is the case that y = x mod n if and only if n divides |x − y| (that is, it divides it exactly, with remainder zero.) Demonstrate that this is the case for each of the answers that you gave to question 3, i.e. if you found that r = m mod n show that n divides m − r.

5. Prove that r = m mod n whenever r is the remainder of division of m by n.

6. Prove (x mod n) + (y mod n) = (x + y) mod n.

7. Prove (x mod n)(y mod n) = (xy) mod n. Use this to prove (x mod n)m = xm mod n for any non-negative integer m.

8. Prove that the boolean ‘exclusive or’ operation, written ⊕, on the set of Boolean values {0, 1} has the following properties:
  - Commutativity: x ⊕ y = y ⊕ x
  - Associativity: (x ⊕ y) ⊕ z = x ⊕ (y ⊕ z)
  - Identity exists: x ⊕ 0 = x
  - Each element is its own inverse: x ⊕ x = 0.
Hint: you can do all of these things by examining the possible cases for the values of x, y, z.

