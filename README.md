# ft_printf

---

A simplified re-implementation of the standard *printf* function for 42.

Supports the following flags:
 * 'c': character           (char)
 * 's': string              (char \*)
 * 'p': pointer             (unsigned long)
 * 'd': decimal             (int)
 * 'i': int                 (int)
 * 'u': unsigned int        (unsigned int)
 * 'x': small caps hex code (unsigned int)
 * 'X': big caps hex code   (unsigned int)
 * '%': percentage escaping

---

## Generating Doccumentation

Make sure you have [doxygen](https://www.doxygen.nl/download.html) installed on
your system. Version used is 1.9.5.

Run the following commands

```bash
doxygen Doxyfile
```

Generated doccumentation will be in *doxygen/* folder. Open
*doxygen/html/index.html* to view it.

---

## Project Structure

A [UML State Diagram](https://www.geeksforgeeks.org/unified-modeling-language-uml-state-diagrams/?ref=lbp)
can be found under *printf.drawio.pdf* describing the implementation logic
behind this version of printf. For further information, don't hesitate to
check out the documentation.
