# Developer Log (DEVLOG.md)
## Expression Format Detector + Stack Evaluator (Spring 2026)

Minimum **6 entries** required.

Each entry must document learning and reasoning. Fabricated bugs are not expected.

---

## Allowed Entry Types
Each entry may be one of the following:

1) **Bug Fix Entry**
- The issue encountered.
- Error messages or symptoms.
- Attempts made.
- Final resolution.

2) **Edge Case / Testing Entry**
- A failure discovered through testing.
- The specific input/state that caused it.
- The change you made to handle it correctly.

3) **Engineering Decision Entry (up to 2 allowed)**
- A design decision you made.
- An alternative approach you considered.
- Why you chose one approach over another (tradeoffs).

---

### Entry 1
**Date:** 2026-03-20

**Entry Type:** Engineering Decision

**Task worked on:** ArrayStack.h

**Issue or decision:** I decided to throw an error rather than print an error message when invalid stack operations happen.

**Error message / symptom (if applicable):** NA

**What I tried:** I tried to print "error" when pop() or top() was being called on an empty stack.

**Fix / resolution (or final decision):** I threw an underflow error when the stack was accessed when empty to allow the error to be handled more effectively.

**Commit(s):** Commit #2: ArrayStack Implementation

---

### Entry 2
**Date:** 2026-03-23

**Entry Type:** Bug Fix

**Task worked on:** tokenize(const string& line)

**Issue or decision:** The tokenizer did not update the index after processing a multi-digit number, resulting in extra repeated processing of the same digits.

**Error message / symptom (if applicable):** Extra unwanted numbers were added to the token vector after the correct multi-digit number.

**What I tried:** When a number was found, I looped to save each consecutive digit into a single number. However, I did not update the main index afterward, so the outer loop continued from the next position and repeated looping for digits that were already included.

**Fix / resolution (or final decision):** I added "i = temp - 1;" to update the main loop index to the end index of a multi-digit number, ensuring that a number is only processed once.

**Commit(s):** Commit #4: Tokenizer

---

### Entry 3
**Date:** 2026-03-24

**Entry Type:** Engineering Decision / Bug Fix

**Task worked on:** isValidPostfix(const vector<Token>& tokens)

**Issue or decision:** I initially tried to use a stack to keep track of numbers and operators when evaluating postfix expressions, but realized that my approach was incorrect. Instead, I switched to a depth counter that track of the operands since each operator needs two operands.

**Error message / symptom (if applicable):** When testing a valid postfix expression by hardcoding input into main, isValidPostfix returned 0 rather than 1. I began to look closer into the issue and realized that my understanding and logic of postfix expressions was incorrect, which prompted me to start over.

**What I tried:** I first attempted to use stack by pushing numbers and popping when encountering operators. However, my implementation became overly complex and incorrectly managed operands.

**Fix / resolution (or final decision):** I decided to use a counter (ctr) instead of a stack that keeps track of operands. Each number increase the ctr by one, and each operator requires two operands so the ctr is reduced by one. At the end of the loop, if ctr == 1, the expression is valid because all operators have the required operands.

**Commit(s):** Commit #5: isValidPostfix and ArrayStack Fix

---

### Entry 4
**Date:** 2026-03-26

**Entry Type:** Edge Case

**Task worked on:** isValidInfix(const vector<Token>& tokens)

**Issue or decision:** When using a stack to evaluate valid use of parentheses, I initially did not consider how operators and numbers should be placed relative to parentheses for a valid infix expression. For example, 3 (3 + 4) is invalid because a number cannot be next to an open parentheses without an operator inbetween.

**Error message / symptom (if applicable):** Incorrect expressions involving parentheses such as 3 (3 + 4) were returned as valid infix expressions.

**What I tried:** I tested multiple different expressions that used parentheses, numbers, and operators. I found that using a stack alone to check matching parentheses did not by itself correctly enforce the order of tokens.

**Fix / resolution (or final decision):** I used the expectOp flag to track whether the next token should be an operator or operand. For open parentheses, I checked if an operator was expected, the function returns false. For a closed parenthesis, I check that the stack is not empty and that an operator was expected before popping from the stack.

**Commit(s):** Commit #6: isValidInfix

---

### Entry 5
**Date:** 2026-03-28

**Entry Type:** Bug Fix

**Task worked on:** evalPostfix(const vector<Token>& tokens)

**Issue or decision:** I discovered that subtraction and division in postfix expressions returned incorrect results. 

**Error message / symptom (if applicable):** The final result of evalPostfix was often incorrect, sometimes even returning negative numbers.

**What I tried:** I tried to use "first" and then "second" (first = s.top(); s.pop(); second = s.top(); s.pop();) when applying operations pushed to the stack (first - second). After adding debug prints after each expression, I realized that I had reversed the order of operands, meaning that second should go before first for correct computations.

**Fix / resolution (or final decision):** I swapped "first" with "second" which fixed the operand order (second - first or second/ first). The expressions that used + or * were unaffected by this change since operand order does not matter for multiplication and addition.

**Commit(s):** Commit #7: evalPostfix   

---

### Entry 6
**Date:** 2026-03-30

**Entry Type:** Bug Fix

**Task worked on:** infixToPostfix(const vector<Token>& tokens)

**Issue or decision:** I initially used a for loop that depended on s.size() at the end of the function to pop the remaining operators from the stack to the output. However, since the stack size changes as elements are popped, some operators were skipped.

**Error message / symptom (if applicable):** Some operators in the stack were not popped, resulting in incorrect postfix expressions.

**What I tried:** I tested multiple infix expressions with different precedence and format. I noticed that the remaining operators in the stack were not all being popped and added to the output.

**Fix / resolution (or final decision):** I replaced the for loop with a while loop that runs until the stack is empty, ensuring that each operator is correctly popped and added to the postfix output.

**Commit(s):** Commit #8: infixToPostfix
