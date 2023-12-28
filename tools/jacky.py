"""
 *                             jack to python 
 *
 *                      14 march MMXXI PUBLIC DOMAIN
 *           The author disclaims copyright to this source code.
 *
 *
"""

import re
import tree
import tree2py
import os
import sys

tokens = []
__file = ""
__line = ""

def identifier_():
    return tokens_pop(0)

def tokens_pop(n):
    global __line
    global tokens
    r = tokens.pop(n)
    while (len(tokens) > 0) and (tokens[0][:1] == "@"):
        __line = tokens[0][1:]
        tokens.pop(0)
    return r

def match(txt):
    global __file
    global __line
    global tokens
    if len(tokens) < 1:
        print ("syntax error: " + __file + "(" + __line + ") expected '" 
                + txt + "' got 'no token'")
        exit(-2)
    if tokens[0] == txt:
        tokens_pop(0)
        return 1
    else:
        print ("syntax error: " + __file + "(" + __line + ") expected '" 
                + txt + "' got '" + tokens[0] + "'")
        exit(-1)

def classVarDec_():
    global current
    current
    p = tokens[0]
    if tokens[0] == "static":
        tokens_pop(0)
    elif tokens[0] == "field":
        tokens_pop(0)
    else:
        return 0
    type_ = identifier_()
    varName = identifier_()
    
    t2 = current.add(p, varName)
    t2.add("type", type_)
    while tokens[0] == ",":
        tokens_pop(0)
        varName = identifier_()
        t2 = current.add(p, varName)
        t2.add("type", type_)
    match(";")
    return 1
       
def stringConstant_():
    if (tokens[0][0] == "\""):
        strin = tokens_pop(0)
        current.add("string", strin)
        return 1
    return 0

def integerConstant_():
    if (is_integer(tokens[0][0])):
        num = tokens_pop(0)
        current.add("int", num)
        return 1
    return 0

def is_integer(t):    
    if (ord(t[0]) >= ord("0") and ord(t[0]) <= ord("9")):
        return 1
    return 0

def is_identifier():    
    if (tokens[0][0] == "_"  or
        (ord(tokens[0][0]) >= ord("a") and ord(tokens[0][0]) <= ord("z"))  or
            (ord(tokens[0][0]) >= ord("A") and ord(tokens[0][0]) <= ord("Z"))): 
        return 1
    return 0

def term_():
    global current
    last = current
    if integerConstant_():
        return 1
    elif stringConstant_():
        return 1
    elif subroutineCall_():
        return 1
    elif tokens[1] == "[":
        varName = tokens_pop(0)
        current = current.add("arrayvar", varName)
        match("[")
        expression_()
        match("]")
        current = last
        return 1
    elif tokens[0] == "(":
        current = current.add("paran", "(")
        match("(")
        expression_()
        match(")")
        current = last
        return 1
    elif tokens[0] == "-" or tokens[0] == "~":
        unaryOp = tokens_pop(0)
        current = current.add("unaryop", unaryOp)
        term_()
        current = last
        return 1
    elif is_identifier():
        varName = tokens_pop(0)
        current.add("varname", varName)
        return 1;
    return 0

def expression_():
    global current
    last = current
    current = current.add("expr", "")
    ret = 0;
    rt = None
    exp = current
    while term_():
        ret = 1
        if (tokens[0] == "+" or 
            tokens[0] == "-" or 
            tokens[0] == "+" or 
            tokens[0] == "/" or 
            tokens[0] == "*" or 
            tokens[0] == "&" or 
            tokens[0] == "|" or 
            tokens[0] == "<" or 
            tokens[0] == ">" or 
            tokens[0] == "="): 
            op = tokens_pop(0)
            if len(current.children) != 1:
                print ("syntax error: " + __file + "(" + __line + 
                            ") single expression expected near '" + op + "'")
                exit(-1)
            rt = tree.Tree("op", op, current)
            rt.left = current.children.pop(0)
            rt.left.parent = rt
            current.children.append(rt)
            current = tree.Tree("expr", "", rt);
            rt.right = current;
        else:
            current = last
            return ret
    current = last
    return ret

def subroutineCall_():
    global current
    last = current
    classVarName = ""
    if is_identifier() == 0:
        return 0
    if (tokens[1] == "."):
        if tokens[3] != "(":
            return 0
        classVarName = identifier_()
        match(".")
    elif tokens[1] != "(":
        return 0
    subroutineName = identifier_()
    current = current.add("call", subroutineName)
    current.add("className", classVarName)
    match("(");
    current = current.add("args", "")
    if expression_():
        while tokens[0] == ",":
            tokens_pop(0)
            expression_()
    match(")");
    current = last
    return 1


def statement_():
    global current
    last = current
    if tokens[0] == "let":
        current = current.add("let", "")
        tokens_pop(0)
        varName = identifier_()
        l2 = current.add("varname", varName)
        if tokens[0] == "[":
            current = l2.add("array", "[")
            match("[")
            expression_()
            match("]")
        current = l2;
        match("=")
        current = current.add("assign", "=")
        expression_()
        match(";")
    elif tokens[0] == "if":
        current = current.add("if", "")
        tokens_pop(0)
        match("(")
        expression_()
        match(")")
        match("{")
        last2 = current
        current = current.add("statements", "")
        while (statement_()):
            pass
        match("}")
        current = last2.add("else", "")
        if tokens[0] == "else":
            match("else")
            match("{")
            while (statement_()):
                pass
            match("}")
    elif tokens[0] == "while":
        current = current.add("while", "")
        tokens_pop(0)
        match("(")
        expression_()
        match(")")
        match("{")
        current = current.add("statements", "")
        while (statement_()):
            pass
        match("}")
    elif tokens[0] == "do":
        current = current.add("do", "")
        tokens_pop(0)
        subroutineCall_()
        match(";")
    elif tokens[0] == "return":
        current = current.add("return", "")
        tokens_pop(0)
        expression_()
        match(";")
    elif tokens[0][0] == "#":
        current.add("#", tokens[0])
        tokens_pop(0)
    else:
        return 0
    current = last
    return 1

def subroutineDec_():
    global className
    global m
    global current
    last = current
    if len(tokens) < 1:
            return 0
    m = tokens[0]
    if tokens[0] == "constructor":
        tokens_pop(0)
    elif tokens[0] == "function":
        tokens_pop(0)
    elif tokens[0] == "method":
        tokens_pop(0)
    elif tokens[0] == "callback":
        current.add("field", "callback");
        tokens_pop(0)
    else:
        return 0
    type_ = identifier_()
    subroutineName = identifier_()
    current = current.add(m, subroutineName)
    current.add("return", type_)
   
    p = current.add("params", "");
    match("(")
    if tokens[0] != ")":
        type_ = identifier_()
        paramName = identifier_()
        p.add(type_, paramName)
        while tokens[0] == ",":
            tokens_pop(0)
            type_ = identifier_()
            paramName = identifier_()
            p.add(type_, paramName)
    match(")")
    match("{")
    p = current.add("vars", "");
    while tokens[0] == "var":
        match("var")
        type_ = identifier_()
        varName = identifier_()
        p.add(type_, varName)
        while tokens[0] == ",":
            tokens_pop(0)
            varName = identifier_()
            p.add(type_, varName)
        match(";");
        
    current = current.add("statements", "")
    while (statement_()):
        pass
    match("}")
    current = last
    return 1


def class_(txt):
    global className
    global current
    last = current
    
    match("class")
    className = identifier_()
    
    current = current.add("class", className)

    match("{")

    while (classVarDec_()):
        pass
    while (subroutineDec_()):
        pass
    match("}");

    current = last;
    return 1


incomment = 0
s = ""

def tokenize(x):
    global incomment
    global s
    insinglec = 0
    inquote = 0
    insharp = 0
    r = []
    l = ""
    for c in x:
        if inquote == 0 and c == "*" and l == "/" and incomment == 0:
            incomment = 1
            if s != "":
                r.append(s)
            s = ""
            s = s + "/"
        
        elif inquote == 0 and c == "/" and l == "*" and incomment == 1:
            incomment = 0
            s = s + "*/"
            c = ""
            s = ""
        elif inquote == 1 and c == "\"":
            inquote = 0
            s = s + l + c
            r.append(s)
            s = ""
            c = ""
        elif incomment == 1 or insinglec == 1 or inquote == 1 or insharp == 1:
            s = s + l
        elif l == "#":
            insharp = 1
            if s != "":
                r.append(s)
            s = l;
        elif l == "\"":
            inquote = 1
            if s != "":
                r.append(s)
            if (c == "\""):
                inquote = 0
                r.append("\"\"")
                c = ""
                s = ""
            else:
                s = "\""
        elif c == "/" and l == "/":
            insinglec = 1
            if s != "":
                r.append(s)
            s = "/"
        elif l == " " or l == "\t" or l == "\n" or l == "\r":
            if s != "":
                r.append(s)
            s = ""
        elif (l == "(" or l == ")" or l == "{" or l == "}"
            or l == "[" or l == "]" or l == ";" or l == "," 
            or l == "=" or l == "+" or l == "-" or l == "*"
            or l == "/" or l == "<" or l == ">" or l == "&"
            or l == "|" or l == "." or l == "~"):
            if s != "":
                r.append(s)
            s = l
            r.append(s)
            s = ""
        else:
            s = s + l
        l = c
    s = s + l
    if incomment == 0:
        if insinglec == 1:
            s = ""
        elif s != "" and s != " " and s != "\n"  and s != "\t":
            r.append(s)
            s =  ""
        else :
            s = ""
    return r

def parse (f):
    global tokens
    global __file
    __file = f
    line = 0
    tokens = []
    fi = open(f, "r");
    for x in fi:
        line = line + 1
        tokens.append("@" + str(line))
        for y in tokenize(x):
            tokens.append(y)

    
    if len(tokens) > 0:
        if (tokens[0][:1] == "@"):
            tokens_pop(0)

    while len(tokens) > 0:
        class_(tokens[0])

    fi.close()

def go(files, p):
    for f in files:
        pf = p + f
        if (os.path.isdir(pf)):
            fi = os.listdir(pf)
            go(fi, pf + "/")
        elif (pf[-5:] != ".jack"):
            None
        else:    
            parse(pf)

if __name__ == "__main__":
    out = sys.argv[1] + ".py"

    ast = tree.Tree("root", sys.argv[1])
    current = ast

    if os.path.exists(out):
        os.remove(out)

    files = os.listdir(sys.argv[1])
    go(files, sys.argv[1] + "/")

    tree2py.process(ast, out)

