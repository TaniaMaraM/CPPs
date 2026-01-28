# PhoneBook (ex01) - Defense Guide

## Table of Contents
1. [Quick Overview](#quick-overview)
2. [Program Flow](#program-flow)
3. [Key C++ Concepts](#key-cpp-concepts)
4. [How to Explain](#how-to-explain)
5. [Common Questions - Beginners](#common-questions---beginners)
6. [Common Questions - Advanced](#common-questions---advanced)
7. [Testing Scenarios](#testing-scenarios)

---

## Quick Overview

**What it does:** A phonebook that stores up to 8 contacts with commands ADD, SEARCH, EXIT.

**Key features:**
- Stores: first name, last name, nickname, phone number, darkest secret
- Maximum 8 contacts (oldest replaced when full)
- Displays contacts in formatted table (10 chars per column)
- No dynamic allocation (stack-only)

**Files structure:**
```
ex01/
├── Makefile
├── include/
│   ├── Contact.hpp      (Contact class declaration)
│   └── PhoneBook.hpp    (PhoneBook class declaration)
└── src/
    ├── Contact.cpp      (Contact implementation)
    ├── PhoneBook.cpp    (PhoneBook implementation)
    └── main.cpp         (program entry point)
```

---

## Program Flow

### 1. Startup (main.cpp)

```
./phonebook
    ↓
main() starts
    ↓
PhoneBook phoneBook;  ← Constructor runs
    ↓
  PhoneBook::PhoneBook() : totalContacts(0), nextIndex(0)
    ↓
  Array contacts[8] initialized
    ↓
  Each Contact() constructor runs → 5 std::string = ""
    ↓
PhoneBook ready!
    ↓
Welcome message printed
    ↓
while (true) loop starts
    ↓
Prompt: >
```

---

### 2. ADD Command Flow

```
User types: ADD
    ↓
phoneBook.addContact() called
    ↓
readField("First Name")
    ├─ Prompt: "First Name: "
    ├─ Read input with std::getline
    ├─ Check EOF (Ctrl+D) → cancel if pressed
    ├─ Check empty → re-ask if empty
    └─ Return valid input
    ↓
Repeat for: Last Name, Nickname, Phone Number, Darkest Secret
    ↓
Store in contacts[nextIndex]:
    contacts[0].setFirstName("John")
    contacts[0].setLastName("Doe")
    contacts[0].setNickname("JD")
    contacts[0].setPhoneNumber("123456789")
    contacts[0].setDarkestSecret("Afraid of cats")
    ↓
Update indices:
    nextIndex = (nextIndex + 1) % 8  ← circular: 0→1→...→7→0
    totalContacts++  (max 8)
    ↓
"Contact added successfully!"
    ↓
Return to main loop
```

---

### 3. SEARCH Command Flow

```
User types: SEARCH
    ↓
phoneBook.searchContact() called
    ↓
Check if empty (totalContacts == 0)
    ├─ Yes → "PhoneBook is empty!" → return
    └─ No → continue
    ↓
displayTable()
    ├─ Print header:
    │   "     Index|First Name| Last Name|  Nickname"
    │   "---------------------------------------------"
    ├─ For each contact (i = 0 to totalContacts-1):
    │   displayRow(i)
    │       ├─ Get fields: firstName, lastName, nickname
    │       ├─ Truncate if > 10 chars: "Christopher" → "Christoph."
    │       └─ Print with setw(10): "      John|       Doe|        JD"
    └─ Table displayed
    ↓
Prompt: "Enter index: "
    ↓
std::cin >> index  (read number)
    ↓
Validate:
    ├─ cin.fail()? → invalid input (letters) → error
    ├─ index < 0? → error
    └─ index >= totalContacts? → error
    ↓
contacts[index].displayFull()
    ├─ Print all 5 fields (full length, no truncation)
    └─ "First Name: John\nLast Name: Doe\n..."
    ↓
Return to main loop
```

---

### 4. EXIT Command Flow

```
User types: EXIT
    ↓
Print "Goodbye!"
    ↓
break  ← exits while(true) loop
    ↓
return 0  ← exits main()
    ↓
phoneBook goes out of scope
    ↓
PhoneBook::~PhoneBook() called
    ├─ Array contacts[8] destroyed
    │   ├─ contacts[7].~Contact() → 5 std::string destructors
    │   ├─ contacts[6].~Contact() → 5 std::string destructors
    │   └─ ... → contacts[0].~Contact()
    └─ Memory freed automatically
    ↓
Program terminates
```

---

## Key C++ Concepts

### 1. Classes vs Structs (C comparison)

**C way:**
```c
typedef struct s_contact {
    char first_name[50];
    char last_name[50];
} t_contact;

void contact_init(t_contact *c);  // separate function
void contact_print(t_contact *c);
```

**C++ way:**
```cpp
class Contact {
private:
    std::string firstName;  // no malloc needed!
public:
    Contact();              // constructor (automatic)
    void displayFull();     // method inside class
};
```

**Key difference:** In C++, data and functions are together. Object "knows" how to handle itself.

---

### 2. Encapsulation (private/public)

**Purpose:** Hide internal details, expose clean interface.

```cpp
class Contact {
private:  // HIDDEN - only Contact can access
    std::string firstName;

public:   // EXPOSED - anyone can use
    void setFirstName(std::string name) {
        // Can add validation here!
        if (!name.empty())
            firstName = name;
    }
    std::string getFirstName() const {
        return firstName;
    }
};
```

**Benefits:**
- **Control:** Validation in setters
- **Security:** Can't corrupt data directly
- **Flexibility:** Can change implementation without breaking external code

**Example:**
```cpp
Contact c;
// c.firstName = "John";  ❌ ERROR! firstName is private
c.setFirstName("John");   ✅ OK! Uses public setter
```

---

### 3. Constructor & Destructor

**Constructor:** Automatic initialization when object is created.

```cpp
Contact::Contact() {
    // Empty because std::string already initializes to ""
}

// Usage:
Contact c;  // Constructor runs automatically here!
```

**What happens internally:**
1. Allocate memory for Contact
2. Call `std::string()` constructor for each of 5 fields
3. Run `Contact::Contact()` body (empty)
4. Object ready!

**Destructor:** Automatic cleanup when object dies.

```cpp
Contact::~Contact() {
    // Empty because std::string cleans itself
}

// Usage:
{
    Contact c;
}  // Destructor runs automatically here!
```

**Comparison with C:**
```c
// C way - manual:
t_contact *c = malloc(sizeof(t_contact));
contact_init(c);
// ... use ...
free(c);  // YOU must remember!

// C++ way - automatic:
Contact c;  // constructor runs
// ... use ...
// destructor runs automatically
```

---

### 4. const Correctness

```cpp
std::string getFirstName() const;  // const at end
```

**Meaning:** Promise that this method WON'T modify the object.

**Compiler enforces:**
```cpp
std::string Contact::getFirstName() const {
    // firstName = "test";  ❌ ERROR! Can't modify in const method
    return firstName;       ✅ OK, just reading
}
```

**Rule:** Mark all read-only methods as `const`.

---

### 5. Initialization List

```cpp
PhoneBook::PhoneBook() : totalContacts(0), nextIndex(0) {
    // Variables already initialized before entering body
}
```

**Why not assign in body?**
```cpp
// Less efficient:
PhoneBook::PhoneBook() {
    totalContacts = 0;  // 1. Creates with garbage, 2. Assigns 0
    nextIndex = 0;
}

// More efficient:
PhoneBook::PhoneBook() : totalContacts(0), nextIndex(0) {
    // Variables created with correct value directly
}
```

---

### 6. Array vs Dynamic Allocation

**Why array `Contact[8]` instead of pointer?**

```cpp
// ALLOWED (stack):
Contact contacts[8];  ✅

// FORBIDDEN (heap):
Contact *contacts = new Contact[8];  ❌
// Subject says: "dynamic allocation is forbidden"
```

**What happens with array:**
- Allocated on stack (automatic)
- All 8 contacts created (constructor runs 8 times)
- Cleaned automatically (destructor runs 8 times)

---

## How to Explain

### For evaluator who doesn't know C++:

**Start simple:**
1. "It's like a phonebook app with 3 commands: ADD, SEARCH, EXIT"
2. Show running: `./phonebook` → try ADD, SEARCH
3. Explain classes: "Like structs in C, but with functions inside"
4. Show encapsulation: "Private = hidden, Public = accessible"

**Visual demo:**
```
> ADD
First Name: John
Last Name: Doe
...
Contact added!

> SEARCH
     Index|First Name| Last Name|  Nickname
         0|      John|       Doe|        JD
Enter index: 0
First Name: John
Last Name: Doe
...
```

---

### Key points to mention:

1. **No malloc/free needed** - `std::string` manages its own memory
2. **Constructors run automatically** - initialization is automatic
3. **Destructors run automatically** - cleanup is automatic
4. **Encapsulation** - data is protected (private), interface is clean (public)
5. **Circular array** - `% 8` makes index wrap around: 0→1→...→7→0

---

## Common Questions - Beginners

### Q1: "Why is the constructor empty?"

**Answer:**
```cpp
Contact::Contact() {
    // Empty because std::string already initializes itself to ""
}
```

When you create `Contact c;`, this happens:
1. Memory allocated
2. `firstName` calls `std::string()` → `""`
3. `lastName` calls `std::string()` → `""`
4. ... 3 more strings
5. `Contact::Contact()` body runs (empty)

No need to initialize strings manually!

---

### Q2: "What's the difference between private and public?"

**Answer:**
```cpp
class Contact {
private:
    std::string firstName;  // Only Contact can access

public:
    void setFirstName(std::string name);  // Anyone can call
};

// Usage:
Contact c;
// c.firstName = "John";  ❌ ERROR! private
c.setFirstName("John");   ✅ OK! public
```

**Analogy:** Private = locked room (only you have key), Public = front door (everyone can use).

---

### Q3: "Why do you need getters/setters?"

**Answer:**

**Without (bad):**
```cpp
struct Contact {
    std::string firstName;  // public
};

Contact c;
c.firstName = "";  // ❌ Can put garbage data!
```

**With (good):**
```cpp
class Contact {
private:
    std::string firstName;
public:
    void setFirstName(std::string name) {
        if (!name.empty())  // ← VALIDATION!
            firstName = name;
    }
};

Contact c;
c.setFirstName("");  // ✅ Setter rejects invalid data
```

**Benefit:** Centralized validation and control.

---

### Q4: "What happens when program ends?"

**Answer:**

```cpp
int main() {
    PhoneBook pb;
    // ...
    return 0;  // ← What happens here?
}
```

**Automatic cleanup:**
1. `pb` goes out of scope
2. `PhoneBook::~PhoneBook()` called
3. Array `contacts[8]` destroyed
4. Each `Contact::~Contact()` called (8 times)
5. Each contact's 5 `std::string` destructors called
6. All memory freed automatically

**No `free()` needed!** Unlike C where you must `free()` manually.

---

### Q5: "Why truncate strings in table?"

**Answer:** Subject requirement!

> "Each column must be 10 characters wide. If text is longer, it must be truncated and last character replaced by a dot."

**Example:**
```cpp
truncate("Christopher")  // 11 chars
// Returns "Christoph."   // 10 chars (9 + dot)
```

**In table:**
```
     Index|First Name| Last Name|  Nickname
         0|Christoph.|       Doe|        JD
```

**In details (after choosing index):**
```
First Name: Christopher  ← full length shown here!
```

---

## Common Questions - Advanced

### Q1: "Why use initialization list instead of assignment?"

**Answer:**

```cpp
// Assignment (2 steps):
PhoneBook::PhoneBook() {
    totalContacts = 0;  // 1. Create with garbage, 2. Assign
}

// Initialization list (1 step):
PhoneBook::PhoneBook() : totalContacts(0) {
    // Variable created with correct value directly
}
```

**For primitives (int):** Small difference.
**For complex objects:** Big performance difference (avoids default construction + copy).

---

### Q2: "Why `std::cin >> index` and not `std::getline`?"

**Answer:** Both work, but `cin >>` is more idiomatic for numbers:

**Option A (current):**
```cpp
int index;
std::cin >> index;
if (std::cin.fail()) {  // automatic error detection
    // handle error
}
std::cin.ignore(..., '\n');  // clean buffer
```

**Option B (getline):**
```cpp
std::string input;
std::getline(std::cin, input);
std::stringstream ss(input);
int index;
if (!(ss >> index)) {  // manual parsing
    // handle error
}
```

**Trade-off:** `cin >>` is shorter but needs `ignore()`. `getline` is cleaner but needs parsing.

---

### Q3: "Why not use `std::vector` instead of array?"

**Answer:** STL containers forbidden until module 08/09.

> "You are allowed to use the STL only in Modules 08 and 09. That means: no Containers (vector/list/map)"

Fixed array `Contact[8]` is sufficient and follows subject requirements.

---

### Q4: "Could you optimize the circular index?"

**Current implementation:**
```cpp
nextIndex = (nextIndex + 1) % 8;
```

**Already optimal!** Modulo operator `%` is efficient and clear.

**Alternative (not better):**
```cpp
nextIndex++;
if (nextIndex >= 8)
    nextIndex = 0;
```

Both have same performance, but `% 8` is more concise.

---

### Q5: "Why separate `.hpp` and `.cpp`?"

**Answer:** Separation of interface and implementation.

**`.hpp` (header):**
- **Declares** class structure (what it has)
- Included by other files
- Multiple inclusion possible (include guards prevent duplicates)

**`.cpp` (implementation):**
- **Defines** how methods work (what they do)
- Compiled once
- Linked at end

**Benefits:**
1. **Compilation speed:** Only recompile `.cpp` when implementation changes
2. **Readability:** See class structure without implementation details
3. **Modularity:** Can share `.hpp` without revealing implementation

---

### Q6: "Explain the difference between `const` methods and non-const"

**Answer:**

```cpp
class Contact {
public:
    std::string getFirstName() const;  // read-only
    void setFirstName(std::string);    // modifies
};
```

**const method:**
- Promises not to modify object
- Can be called on `const` objects
- Compiler enforces (try to modify → compile error)

**non-const method:**
- Can modify object
- Cannot be called on `const` objects

**Example:**
```cpp
const Contact c;
c.getFirstName();   ✅ OK (const method)
c.setFirstName(...) ❌ ERROR (non-const method on const object)
```

---

## Testing Scenarios

### Basic Tests

```bash
# Test 1: Empty phonebook
> SEARCH
Error: PhoneBook is empty!

# Test 2: Add contact
> ADD
First Name: John
Last Name: Doe
Nickname: JD
Phone Number: 123456789
Darkest Secret: Afraid of cats
Contact added successfully!

# Test 3: Search and display
> SEARCH
     Index|First Name| Last Name|  Nickname
         0|      John|       Doe|        JD
Enter index: 0
First Name: John
Last Name: Doe
Nickname: JD
Phone Number: 123456789
Darkest Secret: Afraid of cats
```

---

### Edge Cases

```bash
# Test 4: Empty field rejection
> ADD
First Name: [Enter]
Error: Field cannot be empty!
First Name: John

# Test 5: Long name truncation
> ADD
First Name: Christopher  # 11 chars
> SEARCH
     Index|First Name|...
         0|Christoph.|...  # Truncated to 10 (9 + .)

# Test 6: Invalid index (negative)
> SEARCH
Enter index: -1
Error: Index out of range!

# Test 7: Invalid index (too large)
> SEARCH
Enter index: 99
Error: Index out of range!

# Test 8: Invalid input (letters)
> SEARCH
Enter index: abc
Error: Invalid input!

# Test 9: EOF (Ctrl+D)
> ADD
First Name: [Ctrl+D]
Input cancelled.

# Test 10: Replace oldest (9th contact)
> ADD [contact 1]
> ADD [contact 2]
...
> ADD [contact 8]
> ADD [contact 9]  ← replaces contact 1
```

---

## Quick Reference

### Constructor calls
```
Contact c;
    ↓
1. Allocate memory
2. std::string() × 5 (firstName, lastName, ...)
3. Contact::Contact() body
4. Ready!
```

### Destructor calls
```
} ← c goes out of scope
    ↓
1. Contact::~Contact() body
2. ~std::string() × 5
3. Free memory
4. Done!
```

### Encapsulation
```
Private = Only class can access
Public = Anyone can use
```

### Circular index
```
nextIndex = (nextIndex + 1) % 8
0→1→2→3→4→5→6→7→0→1→...
```

---

## Final Tips for Defense

1. **Run the program first** - show it works
2. **Explain high-level first** - what it does before how
3. **Compare with C when possible** - helps understanding
4. **Draw diagrams** - show memory layout, flow
5. **Be honest** - if you don't know, say so and reason through it

**Good luck! 🚀**
