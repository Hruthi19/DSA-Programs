Convert an infix expression to its equivalent postfix expression.
Note: The code should have the modularity and should include following functions apart from 
main():

1. getNextToken(): This functions returns the next token in the input infix expression. The 
token may be an operator or “(“ or “)” or an operand. The operands can be of multiple 
digits. For example the infix expression 1000/(10+240) contains operands 1000, 10, and 
240.

2. infixToPostfix(): Converts the input infix expression to postfix. This function calls 
getNextToken() repeatedly to get the next token until it reaches the end. The token is 
then processed depending on whether it is an operand or operator or ( or )