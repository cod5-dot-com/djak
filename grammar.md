
## Precedence & Associativity	

19	Grouping	n/a	( … )

18	Member Access	left-to-right	… . …
Computed Member Access	left-to-right	… [ … ]
new (with argument list)	n/a	new … ( … )
Function Call	left-to-right	… ( … )
Optional chaining	left-to-right	?.

17	new (without argument list)	right-to-left	new …

16	Postfix Increment	n/a	… ++
Postfix Decrement	… --

15	Logical NOT (!)	right-to-left	! …
Bitwise NOT (~)	~ …
Unary plus (+)	+ …
Unary negation (-)	- …
Prefix Increment	++ …
Prefix Decrement	-- …
typeof	typeof …
void	void …
delete	delete …
await	await …

14	Exponentiation (**)	right-to-left	… ** …

13	Multiplication (*)	left-to-right	… * …
Division (/)	… / …
Remainder (%)	… % …

12	Addition (+)	left-to-right	… + …
Subtraction (-)	… - …

11	Bitwise Left Shift (<<)	left-to-right	… << …
Bitwise Right Shift (>>)	… >> …
Bitwise Unsigned Right Shift (>>>)	… >>> …

10	Less Than (<)	left-to-right	… < …
Less Than Or Equal (<=)	… <= …
Greater Than (>)	… > …
Greater Than Or Equal (>=)	… >= …
in	… in …
instanceof	… instanceof …

9	Equality (==)	left-to-right	… == …
Inequality (!=)	… != …
Strict Equality (===)	… === …
Strict Inequality (!==)	… !== …

8	Bitwise AND (&)	left-to-right	… & …

7	Bitwise XOR (^)	left-to-right	… ^ …

6	Bitwise OR (|)	left-to-right	… | …

5	Logical AND (&&)	left-to-right	… && …

4	Logical OR (||)	left-to-right	… || …
Nullish coalescing operator (??)	left-to-right	… ?? …

3	Conditional (ternary) operator	right-to-left	… ? … : …

2	Assignment	right-to-left	… = …
… += …
… -= …
… **= …
… *= …
… /= …
… %= …
… <<= …
… >>= …
… >>>= …
… &= …
… ^= …
… |= …
… &&= …
… ||= …
… ??= …
yield	right-to-left	yield …
yield*	yield* …

1	Comma / Sequence	left-to-right	… , …

 
## Program structure

class: 'class' className '{' 
    classWrap 
    classStatic*
    classMethod*
    '}'

classStatic: classStaticVar | classStaticMethod

classStaticVar: 'static' varName ('=' expression)? ';'

classWrap: '$' '(' varName ')' '{' 'return' varName ';' '}'

classStaticMethod: 'static' classMethod

classMethod: methodName '(' parameterList ')' methodBody

parameterList: (varName (',', varName)*)?

methodBody: '{' statements '}'

varName: identifier

methodName: identifier

className: identifier

constant: string 
    | interger
    | floating

## Statements

statements: statement*

statement: letStatement 
    | ifStatement
    | whileStatement
    | forStatement
    | doStatement
    | switchStatement
    | returnStatement
    | expressionStatement

expressionStatement: prefixOp expressionName ';'
	| expressionName expressionStatementNext ';'

expressionStatementNext: postfixOp
	| assingOp expression
	| '(' expressionList ')'

returnStatement: 'return' expression? ';'

letStatement: 'let' varAssign (',' varAssign)* ';'

varAssign: varName ('=' expression)?

ifStatement: 'if' '(' expression ')' bodyState elseStatement?

elseStatement: 'else' ifStatement
    | 'else' bodyState

whileStatement: 'while' '(' expression ')' bodyState

doStatement: 'do' bodyState 'while' '(' expression ')'  ';'

switchStatement: 'switch' '(' expression ')' '{' statements* '}'

forStatement: 'for' '(' forDef ';'
    expression ';'
    expressionList ')' 
    bodyState

forDef: letStatement?
    | expressionStatement (',' expressionStatement)*

bodyState: '{' statements '}'

## Expressions

expression: term (op term)*

expressionList: (expression (',' expression*))?

term: constant
    | expressionName
    | '(' expression ')'
    | unaryOp term
    | prefixOp term
    | term postfixOp

expressionName: varName ('.' varName)?
    | expressionName '.' methodName '(' expressionList ')'
    | expressionName '[' expression ']'
    | className '.' varName
    | className '.' methodName '(' expressionList ')'
    | 


op: assignOp
    | ">"
    | "<<"
    | "=="

unaryOp: '+'
    | '-'
    | '~'
    | '!'

assignOp: '='
    | '+='

postfixOp: '++'

prefixOp: '--'
