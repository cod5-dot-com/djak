
Public Domain JACK compiler
===========================

This public domain software is a sustainable economy project.

![public domain](https://raw.githubusercontent.com/cod5-dot-com/jackc/main/img/pd.png)


The Unofficial Jack Programming language
----------------------------------------

***

Abstract
--------
 
The [Jack programming language][1] is described in the book 
[The Elements of Computing Systems][8] and on the website 
[www.nand2tetris.org][7]. There is a [set of video][3] on Youtube talking about it.

This document is describing a Jack compiler written in Jack which 
outputs C code.

At the beginning it was itself bootstrapped with a simple Python3 Jack compiler.

Status of this document
-----------------------

``` 

This document is released into the public domain.

```

Table of Contents
-----------------

1. [Introduction](#1-introduction)
     1. [Background](#11-background)
     2. [Differences from the book](#12-differences-from-the-book)
     2. [Differences from VMEmulator](#13-differences-from-vmemulator)
2. [Hello World!](#2-hello-world)
3. [Specification](#3-specification)
4. [Classes](#4-classes)
5. [Grammar](#5-grammar)
     
***

## 1. Introduction

Elon Musk asks "is [life a video game][9]" ?

In a blues song (the roots of Hard Rock), AC/DC says "she's got [the Jack][4]" and "she's a dirty woman".

Could the roots of our Universe be coded in Jack programming language by our ancestors ?

Jack is easy to learn but it is designed to be yet useful.


### 1.1 Background

The Jack language was design for teaching the basis of computer construction.

![the number of](https://raw.githubusercontent.com/cod5-dot-com/jackc/main/img/beast.jpg)

### 1.2 Differences from the book

Differences from the original Jack specification are :

The range of decimal constant number and integer variable is unspecified. 
The size of the integer is at least the same size as the size of a memory 
address. (It could be from 8 to 512 bits).

The callback extension allows to call a `callback` method 
from a Callback object.

The inline assembly comment extension allows to insert target language code 
between `//#` and `/*# #*/` comments.

There is additional classes to allow interaction with the operating 
system (files and directories...).

### 1.3 Differences from VMEmulator  

With the `-hack` option the public domain jack compiler is 
disabling these differences.

Differences from the official first edition of Hack Java VMEmulator are :

The `\` in strings literal does  not escape `\` and `"`. 
The official JackCompiler does.

The `while` and `if` conditions are coherent. In the official JackCompiler the
`while` [condition is true if it is equal to -1][10], but the 
`if` condition is true if it is not equal to 0. 
The public domain jack compiler treats both conditions like the `if`.

The static and local variables are not initialized to 0 at start up.
The VMEmulator seems to do it.


## 2. Hello world

Source code :

``` 
class Main {
	function void main()
	{
		do Output.printString("Hello World!");
		do Output.println();
		return;
	}
}
```

With Debian or Ubuntu, you need to install a valid OpenGL development environment, using:
```
sudo apt install build-essential git libx11-dev libgl1-mesa-dev libglu1-mesa-dev 
```

Then clone this repository : 
```
git clone https://github.com/public-domain/jack.git 
```

Build the compiler : 
```
cd jack; make 
```

Create an empty directory structure using 
```
mkdir -p hello/lib 
```
 
Save the text source code in a file named `hello/Main.jack` using your
favorite plain text editor.

Copy the JackOS and the C run-time from the 
public domain jack compiler source code :
```
cp -r lib/std/ hello/lib/std; cp -r lib/c/ hello/lib/c/ 
```
 
Translate it to C using 
```
./jack.run -hack hello
```

Make an executable using 
```
cc -o hello.run hello.c -lX11 -lGL -lGLU 
```

Run it 
```
./hello.run
```

Done!

## 3. Specification

### 3.1 Structure of a program

A Jack program is composed of one or more files that each describe a single
class. Each class is compiled separately then they are all linked to create
a single executable file.

A class name begins with a capital letter and is saved in a text file with 
the same name with the `.jack` extension appended.

All the `.jack` files for a project are located in a single source
directory, possibly with sub-directories.

A class name, variable name or subroutine name (identifiers) always begin with
a letter or a `_` and next is composed of letters, `_` or digits.

The identifiers are case sensitive.

`Name.jack` :
```
/** class definition */

class Name {	// Name is the name of the class

	static int     static_variable_name; // static or field declarations
	field  int     field_variable_name;  // in any order, type or quantity
	static char    static_variable_name2;
	field  char    field_variable_name2;
	static boolean static_variable_name3;
	field  boolean field_variable_name3;
	static Name    static_variable_name4;
	field  Name    field_variable_name4;
	// ...

	/* subroutines declarations */
	// method, constructor or function in any order and quantity

	// a constructor always returns an object of type of its class.
	// subroutines can have any quantity of parametres.
	constuctor Name constructorName(int parameter1, String parameter2) {
		var int local_variable_name;	// local variable in any type
		var Array local_variable_name2; // or quantity
		// ...
		
		// statements
		let local_variable_name2 = null;

		return this;
	}

	// a function doesn't have the `this` object
	function int functionName(char parameter1) {
		var int local_variable_name;
		var Name object;
		var boolean condition;
		// ...

		// statements
		let condition = false;
		if (~condition) {
			let local_variable_name = 1 + 2;
		} else {
			let local_variable_name = 1 * 2;
		}

		let object = Name.constructorName(1, "Hello");
		do object.methodName(true, Array.new(3));
		do object.dispose();

		return 0;
	}

	// a method has an object `this` of its class
	method void methodName(boolean parameter1, Array parameter2) {
		var int local_variable_name;
		var boolean condition, local_var_2, local_var_3;
		var Name an_object;

		// ...

		// statements
		let an_object = this;
		let condition = true;
		let local_variable_name = 3 & 1;

		while (condition) {

			do Name.functionName(65);
			do methodName(false, null);

			let parameter2[0] = 7 - 1;
			if (local_variable_name > 0) {
				let parameter2[1] = 7 - (3 / 2);
			}
			if (local_variable_name > 0) {
				let parameter2[1] = 1 | 2;
			}
			if (local_variable_name = 0) {
				return;
			}
			let condition = ~condition;		 
		}
		return;
	}
}
```

### 3.2 Variables

`static` kind variables are living during all the program execution and
have a class scope.

`field` kind variables have the life of an object have an object scope.

`var` kind variables and parameter variables have the life of 
subroutine execution and a scope of the local subroutine.

Every kind of variable is accessed only by its identifier. You don not
need to add class identifier for static variable. And you cannot
access fields of object. If you need to access field, you need to
write getter and setter.

Each variable has a type that can be a primitive or a object type of a class.

The primitives types are `int` 2's complement integer, `boolean` that can be
`true` or `false`, and `char` an UTF-16 Unicode character.

A constant can be assigned to a variable.

Integer constant are always positive.
The unary minus `-` is used to get negative numbers.

There is only decimal constant. No hex, octal or character constants.

On 16bit platforms the biggest integer constant is 32767, on 32bit
2147483647, on 64bit 9223372036854775807.
To get the most negative number you must use these biggest constants 
and add `1` to them.

String constant are beginning and ending with `"` and can't contain `"` or 
newline (ascii character 10 in decimal). There is no escape
sequences (`\n \\ \t \"` are not producing the same result as in other
programming languages).

The `null` constant is a null reference to an object 
(equivalent to `0` or `false`).

Boolean `true` is `-1` and `false` is `0`.

Variables are weakly typed you can assign any type of variable to any
type of other.

That code is perfectly valid:
```
var int variable;
var Array arr;
let variable = 2000;
let arr = variable;
let arr[1] = 3;      // now memory located at address 2001 contains the value 3
```

### 3.3 Subroutines

`constructor` are automatically allocating the memory for an object of type
of their class. Inside the constructor `this` is a reference to the 
current newly created object. A constructor must end with `return this;` 
statement and its return type must be the one of its class.

Constructors are called using the 
```let obj = ClassName.constructorName(arguments);```
syntax.

The `dispose()` method is generally used in counterpart of constructors to
free memory used by the object.

`function` subroutines are called using the
```let data = ClassName.functionName(arguments);```
syntax.

`method` subroutines are called using the
```let data = obj.methodName(arguments);``` syntax outside their class and
```let data = methodName(arguments);``` syntax inside their class.
Methods have the `this` reference to the current object of type of their class.

The last statement of subroutines is always a `return` statement.

Note that the compiler has no way to find the return type of a subroutine
which is not inside its class scope. So in fact `void` subroutines return
`0`.


### 3.4 Statements

`let` syntax is 
```let variable = expression;``` or 
```let variable[expression] = expression;```.

`do` syntax is
```do ClassName.functionName(arguments);``` or
```do obj.methodName(arguments);```. 

`if` syntax is 
```
if (expression) {
	statements; // executed when expression evaluates to true
} else {
	statements; // executed when expression evaluates to false
}
```
The `else { statements; }` is an optional clause.

`while` syntax is
```
while (expression) {
	statements;   // executed in loop until expression evaluates to false
}
```

`return` syntax is
```return expression;``` for non void subroutines 
or ```return;``` for `void` subroutines.


### 3.5 Expressions

An expression can be:

- A constant (`1234` or `"Hello World"` or `true`/`false` or `null`)
- A variable name
- The `this` keyword
- A `variable_name[expression]`
- A subroutine call
- A `~expression` // bit-wise Boolean INVERT on int and logical NOT on others
- A `-expression` // unary minus
- A `(expression)` // expression enclosed in parenthesis 
- Or :
```
expression + expression // integer addition
expression - expression // integer 2's complement subtraction
expression * expression	// integer multiplication
expression / expression // integer division
expression & expression // bit-wise AND on int and logical AND on others
expression | expression // bit-wise OR on int and logical OR on others
expression > expression // is greater than
expression = expression // is equal
expression < expression // is less than
```

There is no priority of operators. You must always enclose sub-expressions
in parenthesis. Result of `let variable = 2 * 4 + 5;` is undetermined,
you must use `let variable = (2 * 4) + 5;`.

### 3.6 Comments

`//` is introducing a single line comment, the text after `//` is
ignored till the end of line.

`/*` is introducing a multi line is comment, the text after `/*` is
ignored till `*/` is encountered.

Special `/**` is introducing an API documentation comment.

Extension `/*#` is introducing an inline assembly source code and runs till
`#*/` is encountered. `/*#` is followed by one to four characters that
indicate the type of target assembly language.

Extension `//#` acts the same as `/*#` except it is single line.

WARNING: These extensions are only supported by the 
public domain jack compiler described in this document.

### 3.7 Callback extension

The `callback` keyword extension allows to call a method referenced 
by an object. It is useful for creating generic algorithms independent
of types.

WARNING: This extension is only supported by the 
public domain jack compiler described in this document.
Do not use it for the original Hack platform.

This extension is a cheap replacement for `virtual` C++ functions and 
Java non-static, non-final, non-private methods.

The syntax is:
```
class MyCallback {
	// the class must begin with a `int` field named "callback"
	field int callback;

	// There can be only one callback per class.
	// the callback is called by invoke()
	// it must return int and have two int parameters
	method int callback(int a, int b) {
		// do something with a and b.
		// a and b can be assigned to variable of a class type 
		// to do something useful by calling then a method.
		var Array array;
		let array = a;
		if (array) {
			do array.dispose();
		}
		return 0;
	}

	constructor MyCallback new() {
		// the compiler automatically assigns the callback method to the
		// callback field of the object
		return this;
	}

	method void dispose() {
		do Memory.deAlloc(this);
		return;
	}
	
	method int invoke(int a, int b) {
		return callback(a, b); // the magic is here.
				       // it calls the callback referred
				       // by the callback field in 
				       // the `this` reference 
	}
}
```

```
class MyOtherCallback {
	field int callback;
	constructor MyOtherCallback new() {
		return this;
	}
	method int callback(int a, int b) {
		return 0; // do nothing
	}
	// we dont need the invoke and dispose methods since we 
	// never use them in this class
}
```

```
class Main {
	function void Main() {
		var MyCallback cb;

		let cb = MyCallback.new();
		do cb.invoke(0, 0); // calls MyCallback.callback()
		do cb.dispose();
		let cb = MyOtherCallback.new();
		do cb.invoke(0, 0); // calls MyOtherCallback.callback()
				    // without the extension it would have
				    // called MyCallback.callback() again
		do cb.dispose();
		return;
	}
}

```

## 4. Classes

### 4.1. Math 

See the [book][8].

### 4.2. String

See the [book][8].

### 4.3. Array 

See the [book][8].

### 4.4. Output

See the [book][8].

### 4.5. Screen

Screen resolution is 512 x 256 pixels. 

The screen memory starts at memory location 16384 and ends at 24575. 

Pixels are single bit black and white packed in 16bit words.
There is 32 16bit words by line of screen.

See the [book][8] for more.

### 4.6. Keyboard

The current pressed key Unicode value is located at memory address 24576.

There is special key values:
- Newline     is 128.
- Backspace   is 129
- left arrow  is 130
- up arrow    is 131
- right arrow is 132
- down arrow  is 133

...

See the [book][8] for more.

### 4.7. Memory

See the [book][8].

### 4.8. Sys 

See the [book][8].

### 4.9. File

Manage files and directories.

```
	constructor File new(String path, boolean writing)
		path:    path of the file or directory.
		writing: true if you want write to the file.
		return:  an object of type File.

	method String getName()
		return: the path.

	method boolean isdir()
		return: true if path is a directory.

	method boolean open()
		return: true if the file has been successfuly opened.

	method int readByte()
		return: a single byte read from the file or -1 if the
			end of file has been reached.
	
	method String readLine(String buffer)
		return: a line from the file or `null` if end of file has
			been reached.

	method int seek(int position)
		Move the current byte position in the file 
		for writing or reading.
		return: position if successful.

	method int writeByte(int data)
		return: 1 if a single byte "data" has been writen to the file.

	method int writeString(String s)
		return: the length of the "s" String successfuly writen to 
		        the file.

	method boolean remove()
		return: true if the file or directory has been deleted.

	method boolean mkdir()
		return: true if the directory has been created successfuly.

	method Buffer list()
		return: a Buffer containing the list of files or directories
			in the "path" directory.

```

Usage :
```
	var Buffer dir;
	var File file;
	var int i, c;
	var String d;

	let file = File.new("./", false);
	let dir = File.list();
	if (~dir) { return; }
	let i = 0;
	while (i < dir.getSize()) {
		let d = dir.getAt(i);
		do Output.printString(d);
		do Output.println();
		do d.dispose();
		let i = i + 1; 
	}
	do dir.dispose();
	do file.dispose();

	let file = File.new("hello.txt", true);
	do file.writeString("Hello World!");
	do file.writeByte(10); // newline
	do file.dispose();

	let file = File.new("hello.txt", false);
	let c = file.readByte();	
	while (c > 0) {
		do Output.printChar(c);
		let c = file.readByte();
	}
	do file.dispose();
	
	let file = File.new("hello.txt", false);
	do file.remove();
	do file.dispose();

```

### 4.10. Buffer

An Array that grows automatically.

```
	constructor Buffer new(int initial, Callback dispose_cb)
		initial:    preallocated size of the internal Array.
		dispose_cb: a Callback to free elements when the Buffer is
 			    disposed or "null" if the elements don't need
			    to be unallocated.
		return:     a Buffer object with preallocated "initial" 
			    elements space.

	method Array getAt(int index)
		return : the element at postion "index".

	method int append(Array data)
		return: the index of the element "data" appended to the 
			internal Array.

	method int getSize()
		return : the number of elements in the buffer.
```

## 5. Grammar

``` 
keyword: one of
	class constructor function method callback field static var int char boolean void true false null this let do if else while return

symbol: one of
	{ } ( ) [ ] . , ; + - * / & | < > = ~

digit: one of
	0 1 2 3 4 5 6 7 8 9

letter: one of
	a b c d e f g h i j k l m n o p q r s t u v w x y z A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

integerConstant:
	digit digit_opt

stringConstant:
	" unicodeExceptNewlineAndDoublequote_opt "

letterOrUnderscore:
	_
	letter

digitOrLetterOrUnderscore:
	letterOrUnderscore
	digit

identifier:
	letterOrUnderscore digitOrLetterOrUnderscore_opt

classDec:
	class className { classVarDecList_opt subroutineDecList_opt }

varNameList:
	varName
	varNameList, varName

classVarKind:
	static
	field

classVarDecList:
	classVarDec
	classVarDecList classVarDec

classVarDec:
	classVarKind type varNameList ;
	field int callback ;

type:
	int
	char
	boolean
	className

subroutineKind:
	constructor
	function
	method

subroutineType:
	type
	void

subroutineDecList:
	subroutineDec
	subroutineDecList subroutineDec

subroutineDec:
	subroutineKind subroutineType subroutineName ( parameterList_opt ) subroutineBody

parameterList:
	type varName
	parameterList, type varName

subroutineBody:	
	{ varDecList_opt statements }

varDecList:
	varDec
	varDecList varDec

varDec:
	var type varNameList ;

varNameList:
	varName
	varNameList , varName

className:
	identifier

subroutineName:
	identifier
	callback

varName:
	identifier

statements:
	statement
	statements statement

statement:
	letStatement
	ifStatement
	whileStatement
	doSatement
	returnStatement

letStatement:
	let varName indexExpression_opt = expression ;

indexExpression:
	[ expression ]

ifStatement:
	if ( expression ) { statements } elseStatement_opt	

elseStatement:
	else { statements }

whileStatement:
	while ( expression ) { statements }

doStatement:
	do subroutineCall ;

returnStatement:
	return expression_opt;
	return callbackCall;

expression:
	term
	expression op term

term:
	integerConstant
	stringConstant
	keywordConstant
	varName indexExpression_opt
	subroutineCall
	( expression )
	unaryOp term

varOrClassName:
	className
	varName

subroutineCall:
	subroutineName ( expressionList_opt )
	varOrClassName . subroutineName ( expressionList_opt )

callbackCall:
	callback ( expression , expression )

expressionList:
	expression
	expressionList , expression

op: one of
	+ - * / & | < > =

unaryOp: one of
	- ~

keywordConstant:
	true
	false
	null
	this

``` 

***
[1]: https://www.nand2tetris.org/project09
[2]: https://www.csie.ntu.edu.tw/~cyy/courses/introCS/13fall/lectures/handouts/lec11_Jack.pdf
[3]: https://www.youtube.com/watch?v=KBTg0ju4rxM&list=PLrDd_kMiAuNmllp9vuPqCuttC1XL9VyVh
[4]: https://www.youtube.com/watch?v=kq_GSIw0X0w
[5]: https://commons.wikimedia.org/wiki/File:UN_emblem_blue.svg
[6]: https://tekeye.uk/playing_cards/svg-playing-cards 
[7]: https://www.nand2tetris.org/
[8]: https://www.amazon.com/Elements-Computing-Systems-Building-Principles/dp/0262640686/ref=ed_oe_p
[9]: https://www.youtube.com/watch?v=2KK_kzrJPS8 
[10]: http://nand2tetris-questions-and-answers-forum.32033.n3.nabble.com/Supplied-compiler-doesn-t-agree-what-is-true-between-if-statement-and-while-statement-td4032492.html
[11]: https://www.sustainable.org/economy/
[12]: https://web.archive.org/web/20110920035144/http://www.dcd.pl/asoft.php
[13]: https://archive.org/details/bitsavers_motorola
[14]: https://unlicense.org/
[15]: https://www.sqlite.org/copyright.html
[16]: https://ohwr.org/cern_ohl_p_v2.txt
[17]: https://www.youtube.com/watch?v=Q8RqgVjIDB8
[18]: https://www.economist.com/big-mac-index
[19]: https://www.travailler-en-suisse.ch/tendances-salaires-informaticiens-suisse.html
[20]: https://opensource.org/licenses
[21]: http://www.salaryexplorer.com/salary-survey.php?loc=210&loctype=1&job=1&jobtype=1


***

