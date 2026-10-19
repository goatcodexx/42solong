_This project has been created as part of the **42 curriculum** by **sywee**._

# 📌 Description

**ft_printf** is a reimplementation of the standard C `printf()` function.  
The goal of this project is to gain a solid understanding of **variadic functions** in C and how formatted output works internally.

The project produces a static library, **libftprintf.a**, which mimics the behavior of `printf()` for a defined set of conversion specifiers.

---
# Instructions

## ✨ Supported Conversions

The following format specifiers are fully supported:

- `%c` — Print a single character  
- `%s` — Print a string  
- `%p` — Print a pointer in hexadecimal format  
- `%d` / `%i` — Print a signed decimal integer  
- `%u` — Print an unsigned decimal integer  
- `%x` — Print a hexadecimal number (lowercase)  
- `%X` — Print a hexadecimal number (uppercase)  
- `%%` — Print a percent sign  

---

## ⚙️ Algorithm & Technical Choices

### Parsing Strategy

`ft_printf` uses a **linear parsing algorithm** to process the format string:

- **Regular characters** are written directly using `write()`
- **Format specifiers** are detected when a `%` is encountered
- The character following `%` determines the conversion type

### Variadic Arguments

The project relies on `<stdarg.h>` macros:

- `va_start`
- `va_arg`
- `va_end`

These macros allow the function to retrieve arguments dynamically based on the detected format specifier.

---

## 🧠 Data Structures

- No buffering system is used (as required by the subject)
- Output is written directly using `write()`
- No complex data structures (lists, buffers, etc.)
- A simple **dispatcher** (`if/else`) routes each format specifier to its corresponding handler function

This design keeps the implementation lightweight, readable, and extensible for bonus features.

---

## 🛠️ Installation & Compilation

The project includes a **Makefile** with standard rules.

# Resources & AI
AI Usage:
AI was used to help structure this README and to brainstorm the logic for handling hexadecimal conversions.

Parts: Specifically, I used AI to clarify how va_arg interacts with different data types (like promoting char to int).

Verification: All AI-generated suggestions were manually verified against the project Norm and tested for memory leaks.

### Build the library
```bash
make
