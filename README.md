#lexer
Made a too complex lexical analyser for my other project.

---
- <h5>lexer</h5> source lexical analyse, producing tokens stream.
---
 - <h5>lexer_color</h5> My own extreme detailed lexical highlight colourizer.

---
This lexer is not 100% without glitches and bugs. It is still in devel stage, experimenting
pre-analysed arithmetic operands, operators and universal arithmetic syntax style, including one-letter-factor identifier sequence
such as "2a(b + 4c)".
Numbers scanning I am building is really becoming too complex and is not conventional. The actual code (algorithm) might be removed and replaced by standard scanning method (libc:sscanf for example, or more safer std::iostringstream scanners).
