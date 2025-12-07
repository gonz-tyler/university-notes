# Tutorial 07: Access Control, Models, and Information Flow Control

**Instructions:**

- **[R]** = Review question (covered in lectures).
- **[C]** = Challenge question (may be harder/outside typical exam scope).
- **[E/M]** = Easy/Moderate.
- **Note:** Use the space provided to write your answers or draw diagrams where requested.

---

## Part 1: Access Control

### Question 1 [R, \*]

**(a)** Draw a diagram and explain a fundamental model of access control discussed in lectures. This should involve a subject, a guard, and an object.

<details>
<summary>**Diagram:**</summary>

>
</details>
<details>
<summary>**Explanation:**</summary>

>
</details>

**(b)** Explain the AAA framework, including what each of those components involves.

<details>
<summary>**Answer:**</summary>

>
</details>

**(c)** Re-draw the picture that you gave for the first part, showing the use of a separate access policy store and a logging system.

<details>
<summary>**Diagram:**</summary>

>
</details>

### Question 2 [R]

Explain the principle of least privilege.

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 3 [C]

In some security systems, there is a rule that says that a particular access request requires two subjects to make simultaneous requests in order for it to be granted. This is sometimes known as the "two-man rule".
_Example: Two keys are used to fire a nuclear missile from a submarine. Both keys must be turned simultaneously, and the locks are too far apart for one person to reach. One key is held by the captain, the other by the first officer._

**(a)** Why is this not exactly like the 'fundamental model' from Question 1a?

<details>
<summary>**Answer:**</summary>

>
</details>

**(b)** Can you think of any information security situations which might require this kind of control?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 4 [R]

Explain DAC (Discretionary Access Control) and MAC (Mandatory Access Control). Give examples of each.

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 5 [R]

The principle of **attenuation of privilege** says that a subject should not be allowed to grant permission for something for which it does not itself have permission.
Give a brief example showing why this can be required (i.e., how something could go wrong if this were not the case).

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 6 [C]

In an **Originator-Controlled Access Control** system (ORCON/ORGCON), the final ability to authorize access resides with the originator (creator) of an object.

**(a)** Think of and write down a sensible potential application of ORCON.

<details>
<summary>**Answer:**</summary>

>
</details>

**(b)** Briefly comment on the differences and similarities between ORCON and DAC. Next, comment on the differences and similarities between ORCON and MAC.

<details>
<summary>**ORCON vs DAC:**</summary>

>
</details>
<details>
<summary>**ORCON vs MAC:**</summary>

>
</details>

**(c)** **Scenario:** A university gives a copy of a contract to a lecturer. The lecturer owns that copy. The university does not allow them to show it to anyone else without permission.
If the university allows the lecturer to give a copy to their spouse, but fails to stipulate that the spouse may not show it to anyone else, is this still ORCON?

<details>
<summary>**Answer:**</summary>

>
</details>

**(d)** How does the previous sub-part relate to attenuation of privileges?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 7 [R]

Consider a UNIX-like system with three users: **Alice**, **Bob**, and **Cindy**.

- Alice owns `aliceF` (Bob and Cindy can only read it).
- Bob owns `bobF` (Cindy can read and write; Alice can only read).
- Cindy owns `cindyF` (Only she can read, write, or execute).
- _Note:_ Owners can read, write, and execute their own files. No other users exist.

**(a)** Write down the part of the access control matrix for these three users and three files.

<details>
<summary>**Answer:**</summary>

> | | aliceF | bobF | cindyF |
> | :--- | :--- | :--- | :--- |
> | **Alice** | | | |
> | **Bob** | | | |
> | **Cindy** | | | |
</details>

**(b)** Cindy now gives Alice permission to read `cindyF`, and Alice removes Bob's ability to read `aliceF`. Show the new access control matrix.

<details>
<summary>**Answer:**</summary>

> | | aliceF | bobF | cindyF |
> | :--- | :--- | :--- | :--- |
> | **Alice** | | | |
> | **Bob** | | | |
> | **Cindy** | | | |
</details>

**(c)** Is this whole set-up DAC or MAC?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 8 [R, C]

Look back at Question 7. We now want to specify this using the UNIX-like `owner-group-other` format.

**(a)** We can create a group `GROUP` so that Alice can correctly specify permissions for `aliceF` (before the permissions changes in Q7b).
The group associated with `aliceF` is `GROUP`.

- Who are the members?
- Write down the corresponding permissions (using the nine-place `rwxrwxrwx` system).

<details>
<summary>**Members:**</summary>

>
</details>
<details>
<summary>**Permission Strings:**</summary>

>
</details>

**(b)** Can the same group be used initially for `bobF`? Why, or why not?

<details>
<summary>**Answer:**</summary>

>
</details>

**(c)** Can the same group be used initially for `cindyF`? Why, or why not?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 9 [R]

Consider a file with permissions `rw-r--r-x`. Who can do what?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 10 [R]

Consider a file with permissions `rw----rw-`. Who has read and write access to this file?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 11 [R]

What is a **capability** in access control? Give an example.

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 12 [R, C]

Suppose a user wishes to edit a sensitive file in a capability-based system.

- How can the user be sure that the editor cannot access any other file?
- Could this be done in an ACL-based system?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 13 [R, C]

Suppose that you are regularly given certain objects for which you have to **revoke permissions for certain users**.
Would this be easier with ACLs or capabilities? Explain why, with reference to the algorithms required.

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 14 [R, C]

Suppose that you are regularly given the name of a user for whom you have to **revoke permissions for certain objects**.
Would this be easier with ACLs or capabilities? Explain why, with reference to the algorithms required.

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 15 [R, C]

Consider a system with four access operations: `read`, `write`, `grant`, and `revoke`.
Any user, say $U$, can use `grant` to give other subjects read and write access, and also the right to grant access to the objects that $U$ owns.
Which data structure and algorithm would make it easy to implement both the `grant` and `revoke` operations so that you can revoke all access to an object that you own?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 16 [C]

In a social network, what access rights would you give to the friends of your friends?
How would access rights tend to vary with the length of such recommendation chains? Can you think of exceptions?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 17 [R]

Briefly discuss the similarities and differences between **roles** (e.g., in RBAC) and **groups**.

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 18 [R]

**Context:** Refer to Figure 1 (described below):

- $u_1$ is the owner of object $o_1$.
- $u_1$ does not currently have any access to $o_1$.
- A group $g_1$ exists.
- Users $u_2$ and $u_3$ are in group $g_1$.
- All members of group $g_1$ have all (`r,w,x`) access to $o_1$.
- Nobody else has access.

Write down the UNIX-style `owner-group-other` permissions for $o_1$.

<details>
<summary>**Answer:**</summary>

>
</details>

---

## Part 2: AC Models

### Question 1 [R]

Consider a scenario where an organisation needs to protect sensitive information using security models.
Explain how the **Bell-LaPadula (BLP)** and **Biba** security models differ in their approaches to data protection regarding:

- Goals
- Security properties
- Scenarios where each is most suitable

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 2 [R]

Explain the **Chinese Wall model** in the context of access control.

- How does it prevent conflicts of interest?
- What are the key challenges in implementing this model in modern systems?
- Provide an example to illustrate how the model works.

<details>
<summary>**Answer:**</summary>

>
</details>

---

## Part 3: Information Flow Control

### Question 1 [R]

What is **non-interference**? Why is it usually considered impractical in real-world systems?

<details>
<summary>**Answer:**</summary>

>
</details>

### Question 2 [E/M]

Consider the following programs on uniform distributed 2-bit integers, acting as noisy channels.

- **Input:** `pwd` (sensitive)
- **Output:** `o` (public/observable)

Are they non-interfering?

- If **Yes**: Explain why.
- If **No**: Measure the information (in bits) the attacker can learn about `pwd` by observing `o`.

**(a)** $C_1$: `o := o XOR pwd`
_(Assume o is initialized or previous state)_

<details>
<summary>**Answer:**</summary>

>
</details>

**(b)** $C_2$: `o := pwd`

<details>
<summary>**Answer:**</summary>

>
</details>

**(c)** $C_3$: `o := pwd % 2`

<details>
<summary>**Answer:**</summary>

>
</details>

**(d)** $C_5$: `if (pwd % 2 = 0) then o := 0 else o := 1`

<details>
<summary>**Answer:**</summary>

>
</details>

**(e)** $C_{input}$: `x := input(); if (x = pwd) then o := 0 else o := 1`

<details>
<summary>**Answer:**</summary>

>
</details>

**(f)** $C_6$: `if (pwd < 2) then o := 1 % 2 else o := 3`
_(Note: text says `l%2`, assuming integer literal 1 or variable l)_

<details>
<summary>**Answer:**</summary>

>
</details>

**(g)** $C_7$:

```text
o := 0;
while (pwd > 0) do
   o := o + 1;
   pwd := pwd - 1;
od
```

<details>
<summary>**Answer:**</summary>

>
</details>
