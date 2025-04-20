# Week 08.2: Secure Programming II
## Notes
---

### Introduction

- Secure programming = writing code that is hard to attack
- Free from bugs exploitable for malicious use
- Important across all languages: C, Java, HTML, etc.

---

### SQL Injection

- Happens when SQL queries are created using string concatenation
- Exploits unescaped user input in SQL expressions

#### Example:

```java
statement = "SELECT * FROM users WHERE name = '" + userName + "'"
```

#### Attacker Input:

```java
userName = "fred' OR 'x'='x"
```

#### Resulting Query:

```sql
SELECT * FROM users WHERE name = 'fred' OR 'x'='x'
```

➡ Returns entire table

---

### SQL Injection Defense

- Use **PreparedStatements** instead of string concatenation
- Validate input
- Never connect as root

#### Example:

```java
PreparedStatement pstmt = con.prepareStatement("UPDATE EMPLOYEES SET SALARY = ? WHERE ID = ?");
pstmt.setBigDecimal(1, 153833.00);
pstmt.setInt(2, 110592);
```

---

### JDBC Queries

- JDBC `Statement` used for SQL execution
- Use `ResultSet` to iterate over returned data

#### Example:

```java
Statement stmt = dbCon.createStatement();
ResultSet rs = stmt.executeQuery("SELECT * FROM Students");
while (rs.next()) {
    System.out.println(rs.getString(1));
}
```

- `ResultSetMetaData` gives schema info like column names and count

---

### Efficiency Tips

- Avoid parsing SQL repeatedly
- Use:
    - Optimized JDBC drivers
    - **PreparedStatements**
    - **Query batching**

---

### Query Batching

- Reduces overhead of repeated DB accesses

```java
PreparedStatement pstmt = dbCon.prepareStatement("INSERT INTO Students (SID, FirstName, LastName) VALUES (?, ?, ?)");
pstmt.setInt(1, 1234);
pstmt.setString(2, "John");
pstmt.setString(3, "Smith");
pstmt.addBatch();
pstmt.executeBatch();
```

---

### Transactions in JDBC

- JDBC uses **auto-commit** by default
- For atomic operations, disable it:

```java
con.setAutoCommit(false);
// perform multiple updates
con.commit();
con.setAutoCommit(true);
```

---

### Web Security Issues

#### Name Variants

- URLs/names can look identical but differ internally due to:
    - Unicode
    - HTML entities
    - Font differences

#### Defense:

- Use **whitelists**, not blacklists
- Reject unusual encodings

---

### Cross-Site Scripting (XSS)

- Client-side injection using JavaScript
- Attackers inject scripts into web pages
- Can steal cookies, impersonate users

#### Example:

```html
<script>alert(document.cookie);</script>
```

---

### XSS Types

- **Reflected XSS**: Script included in URL, executed upon visit
- **Persistent XSS**: Stored on server, shown in pages to users

---

### XSS Defense

- HTML Encoding:
    - `&` → `&amp;`
    - `<` → `&lt;`
    - `>` → `&gt;`
- Filter bad tags: `<script>`, `<embed>`, etc.
- Set character encoding explicitly
- Use OWASP guidelines

---

### General Secure Coding Tips

#### Permissions:

- Run with **least privilege**
- Don't connect as root

#### Cryptography:

- Use secure, **standard libraries**
- Never hardcode secrets
- Store passwords as **hashes**

---

### Protecting Secrets

- Zero sensitive data (e.g., credit card numbers) ASAP
- Prefer `StringBuffer` over `String` for mutability

```java
StringBuffer sb = new StringBuffer(cardnum);
creditco.checkCredit(sb);
sb.delete(0, sb.length());

```

---

### Compilers and Optimization

- Compiler may **remove security logic** if it looks redundant

```c
ZeroMemory(password, 64); // may be optimized away

```

---

### Error Handling

- Ensure proper recovery after exceptions
- Clean up sensitive data in logs/temp files
- Return to **safe state** after failures

---

### Golden Rule

> All Input is Evil
> 
- Never trust user input
- Use whitelists for validation
- Use regex for pattern checks
- Clients should not be trusted by the server

---

### Summary Table

| Topic | Key Risk | Recommended Practice |
| --- | --- | --- |
| SQL Injection | Query manipulation | PreparedStatements |
| XSS | Script injection | HTML escaping, tag filtering |
| Permissions | Privilege escalation | Least privilege principle |
| Cryptography | Weak encryption, leaks | Use secure libraries and hashing |
| Error Handling | Incomplete recovery | Safe state assurance, cleanup |
| Input Validation | Code and data injection | Whitelisting, regular expressions |
