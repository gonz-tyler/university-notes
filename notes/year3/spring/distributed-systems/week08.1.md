
# Week 08.1: Secure Programming
## Notes
---

### What is Secure Programming?

- Writing code that is difficult to attack
- Avoiding security-relevant bugs
- Involves general principles and language-specific rules (C, Java, HTML, etc.)

---

### Buffer Overflow

- Problem mainly in **C/C++**: no built-in checks on buffer size
- Overflows can overwrite stack frames, including return addresses
- Example:
```c
void silly(char* input) {
    char buf[10];
    strcpy(buf, input); // unsafe
}
```

#### Solution:
```c
void notSoSilly(char* input) {
    char buf[10];
    strncpy(buf, input, sizeof(buf));
    buf[sizeof(buf)-1] = '\0';
}
```

---

### Safer Alternatives

- Use C++ strings or libraries (e.g., STL)
- Avoid legacy C-style functions like `strcpy`, `gets`, etc.

---

### Major Attack Vector

- Buffer overflows account for **50–75% of attacks**
- Example: Media file exploits in DirectShow or browser bugs

---

### Java Security Issues

- Exception handling
- Hardcoded credentials
- Inheritance issues
- Mutable objects
- Dangerous features (inner classes, cloning, serialization)

---

### Java: Exception Handling

#### Example:
```java
boolean checkPIN(String userPIN, int realPIN) {
    try {
        int userPINint = Integer.parseInt(userPIN);
        if (userPINint != realPIN) return false;
    } catch (NumberFormatException e) {
        System.out.println("PIN is not a number!");
    }
    return true; // ❌ still returns true
}
```

- Don’t let exceptions hide incorrect logic.

---

### Hardcoded Passwords

Avoid:
```java
dbURL = "jdbc:mysql://localhost/db?user=root&password=secret";
```

- Can be reverse engineered from bytecode or logs

---

### Inheritance Risks

- Inherited methods may be overridden or misunderstood
- Subclasses may behave unexpectedly if superclass behavior changes

---

### Mutability Issues

- Mutable objects can be exploited
- External code may retain references to internal structures

#### Example:
```java
class Cart {
    private final List items;
    public Cart(List items) { this.items = items; }
    public List getItems() { return items; }
}
```
- Declaring `final` does not make `items` immutable!

---

### Immutable Wrappers

#### Example:
```java
class ImmutableCart {
    private final List items;
    public ImmutableCart(List items) {
        this.items = Collections.unmodifiableList(new ArrayList(items));
    }
    public List getItems() { return items; }
}
```

- Wrap mutable items with decorators to prevent modifications

---

### Secure Period Class Example

#### Vulnerable:
```java
public final class Period {
    private final Date start, end;
    public Period(Date start, Date end) {
        if (start.compareTo(end) > 0) throw new IllegalArgumentException();
        this.start = start;
        this.end = end;
    }
}
```

#### Exploits:
```java
end.setYear(78); // Mutates the object externally
```

#### Secure Version:
```java
public final class Period {
    private final Date start, end;
    public Period(Date start, Date end) {
        this.start = new Date(start.getTime());
        this.end = new Date(end.getTime());
    }
    public Date start() { return new Date(start.getTime()); }
    public Date end() { return new Date(end.getTime()); }
}
```

---

### Java Features to Avoid

- **Inner Classes**: Break encapsulation via compiler-generated methods
- **Cloning**: Can bypass constructor logic
- **Serialization**: Can expose internal state

---

### Example: Inner Class Access

#### Compiled View:
```java
static int access$0(A aObj) { return aObj.m; }
```

- This synthetic method can be used reflectively to read private values

---

### Initialization Management

- Use `private boolean initialized`
- Constructor sets it at end
- All other methods check it

---

### Cloning and Serialization

#### Disable Cloning:
```java
public final Object clone() throws CloneNotSupportedException {
    throw new CloneNotSupportedException();
}
```

#### Disable Serialization:
```java
private final void writeObject(ObjectOutputStream o) throws IOException {
    throw new IOException("Not serializable");
}
```

---

### Serialization Management

- Use `transient` to exclude sensitive fields
- Implement custom (de)serialization logic to encrypt/decrypt data

---

### Final Tips

| Practice                     | Reason                                     |
|-----------------------------|--------------------------------------------|
| Avoid buffer overflows      | Prevent stack manipulation                 |
| Validate all inputs         | Avoid injection, corruption                |
| Avoid mutable data sharing  | Ensure object integrity                    |
| Control serialization       | Prevent state leakage                      |
| Never hardcode credentials  | Prevent easy extraction                    |
| Monitor exception handling  | Avoid incorrect fallback logic             |

---
