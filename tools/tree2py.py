"""
 *                             jack to python 
 *
 *                      1 april MMXXI PUBLIC DOMAIN
 *           The author disclaims copyright to this source code.
 *
 *
"""

stati = 0
memory = {}

def w(f, txt):
    f.write(txt)

def isbool(a):
    if (a.left and isbool(a.left)):
            return 1
    if (a.right and isbool(a.right)):
            return 1
    if (a.data == "="or a.data == ">" or a.data == "<"
            or a.data == "true" or a.data == "false"):
        return 1
    if (get_class(a) == "boolean"):
            return 1
    for b in a.children:
        if (isbool(b)):
            return 1
    return 0

def global_(f, a, tab):
    o = a.parent;
    while (o != None and o.tag != "class"):
        o = o.parent
    if (o != None):
        for b in o.children:
            if (b.tag == "static"):
                w(f, tab + "global " + o.data + "__" + b.data + "\n")

def get_var(f, a):
    o = a.parent;
    while (o != None and o.tag != "class"):
        o = o.parent
    if (o != None):
        nf = 0;
        for b in o.children:
            if (b.tag == "static" and b.data == a.data):
                return o.data + "__" + a.data
            elif (b.tag == "field"):
                if (b.data == a.data):
                    return "__memory[__this+" + str(nf) + "]" 
                nf += 1
    v = a.data
    if (v == "this"):
        v = "__this"
    return v

def expr_(f, e, tab):
    for a in e.children:
        sexpr_(f, a, tab)

def static_end():
    i = 0
    n = 1;
    while (i < stati):
        i += 1;
        j = 0
        n += 1
        for m in memory[i]:
            if (m != '"'):
                n += 1
        n += 1
    return n + 1;

def sexpr_(f, a, tab):
        global stati
        if a.tag == "string":
            #w(f,"get_string(" + str(static_end()) + ")")
            stati = stati + 1
            memory[stati] = a.data
            w(f,"get_string(" + str(stati) + ")")
        elif a.tag == "expr":
            expr_(f, a, tab)
        elif a.tag == "int":
            w(f, a.data)
        elif a.tag == "varname":
            if a.data == "this":
                w(f, "__this")
            elif a.data == "false":
                w(f, "0")
            elif a.data == "true":
                w(f, "-1")
            elif a.data == "null":
                w(f, "0")
            else:
                w(f, get_var(f, a))
        elif a.tag == "arrayvar":
            v = get_var(f, a);
            w(f, "__memory[" + v + "+(")
            for b in a.children:
                if (b.tag == "expr"):
                    expr_(f, b, tab)
            w(f, ")]")
        elif a.tag == "op":
            ib = 0
            o = a.data
            if o == "=":
                o = "=="
            if (isbool(a)):
                ib = 1
                if (o == "&"):
                    o = " and "
                elif (o == "|"):
                    o = " or "
            if (ib):
                if (o == "~"):
                    o = "";
                    w(f, "(0==");
                else:
                    w(f, "(0!=");
            elif (o == "/" or o == "*"):
                    w(f, "(int");
            else:
                    w(f, "(int");

            w(f, "(")
            sexpr_(f, a.left, tab)
            w(f, o)
            expr_(f, a.right, tab)
            w(f, ")")
            w(f, ")");
        elif a.tag == "paran":
            w(f, "( ")
            for b in a.children:
                if (b.tag == "expr"):
                    expr_(f, b, tab)
            w(f, " )")
        elif (a.tag == "call"):
            call_(f, a, tab)
        elif a.tag == "unaryop":
            o = a.data
            if (isbool(a)):
                if (o == "~"):
                    o = "0=="
            w(f, o)
            expr_(f, a, tab)


def vars_(f, b):
    for d in b.children:
        if (d.tag == "Array"):
            w(f, "")

def get_class(q):
    o = q.parent;
    while (o != None and o.tag != "method" and o.tag != "function" and
            o.tag != "constructor" and o.tag != "callback"):
        o = o.parent;
    if (o != None):
        for e in o.children:
            if (e.tag == "vars" or e.tag == "params"):
                for t in e.children:
                    if (t.data == q.data):
                       return t.tag
    o = q.parent;
    while (o != None and o.tag != "class"):
        o = o.parent;
    if (o != None):
        for e in o.children:
            if (e.tag == "method" or e.tag == "field" or e.tag == "callback"):
                if (e.data == q.parent.data and q.data == ""):
                    return o.data
                if (e.data == q.data):
                    return e.children[0].data
    return q.data

def replace(f, c ,tab):
    key = "";
    for q in c.children:
        if q.tag == "className":
            if (q.data == "Math"):
                if (c.data == "xor"):
                    key = "^"
                elif (c.data == "shiftRight"):
                    key = ">>"
                elif (c.data == "shiftLeft"):
                    key = "<<"
                elif (c.data == "rem"):
                    key = "%"
            if (key != ""):
                w(f, "(")
                for r in c.children:
                    if r.tag == "args":
                        i = 0
                        for e in r.children:
                            if (i == 1):
                                w(f, key)
                            if (len(e.children) > 0):
                                expr_(f, e, "")
                            i = i + 1
                w(f, ")")
                return True
        return False

def call_(f, c, tab):
    cla = ""
    if replace(f,c,tab):
        return;
    for q in c.children:
        if q.tag == "className":
            cla = get_class(q) 
            if c.data == "callback":
                w(f, tab + "__memory[__this](__this")
            else:
                w(f, tab + cla + "__" + c.data + "(")
                if (cla != "" and q.data == ""):
                    w(f, "__this")
            for r in c.children:
                if r.tag == "args":
                    if (q.data == cla):
                        com = ""
                    else:
                        w(f, get_var(f, q))
                        com = ", "

                    for e in r.children:
                        if (len(e.children) > 0):
                            w(f, com)
                            expr_(f, e, "")
                            com = ", "
            w(f, ")")

def statements_(f, b, tab):
    for d in b.children:
        if (d.data[0:4] == "#py "):
            w(f, d.data[4:])
        elif (d.tag == "do"):
            for c in d.children:
                if (c.tag == "call"):
                    call_(f, c, tab)
                    w(f, "\n")
        elif (d.tag == "let"):
            for c in d.children:
                is_array = 0
                for e in c.children:
                    if (e.tag == "assign"):
                        if (c.tag == "varname" and is_array == 0):
                            w(f, tab + get_var(f, c)) 
                        w(f, "=")
                        for k in e.children:
                            if (k.tag == "expr"):
                                expr_(f, k, "")
                    elif (e.tag == "array"):
                        is_array = 1
                        w(f, tab + "__memory[" + get_var(f, c)+ " +int(")
                        for k in e.children:
                            if (k.tag == "expr"):
                                expr_(f, k, "")
                        w(f, ")]")
            w(f, "\n")
        elif (d.tag == "while"):
            w(f, tab + "while (")
            for c in d.children:
                if (c.tag == "expr"):
                    expr_(f, c, "")
                    w(f, "):\n")
                elif (c.tag == "statements"):
                    statements_(f, c, tab + "\t")
        elif (d.tag == "if"):
            w(f, tab + "if (")
            for c in d.children:
                if (c.tag == "expr"):
                    expr_(f, c, "")
                    w(f, "):\n")
                elif (c.tag == "statements"):
                    statements_(f, c, tab + "\t" )
                elif (c.tag == "else" and len(c.children) > 0):
                    w(f, tab + "else:\n")
                    statements_(f, c, tab + "\t")
        elif (d.tag == "return"):
            w(f, tab + "return ")
            for e in d.children:
                expr_(f, e, "")
            w(f, "\n")

def escape(s):
    return s.replace("\\", "\\\\")

def process(ast, out):
    f = open(out, "a+")
    f.write("#! /usr/bin/python3\n")
    f.write("import sys\n")
    f.write("import time\n")
    f.write("import tty\n")
    f.write("import os\n")
    f.write("import termios\n")
    f.write("import select\n")
    f.write("import atexit\n")
    f.write("import signal\n")
    f.write("import tkinter\n")
    f.write("import array\n")
    f.write("__NativeObject = {}\n")
    f.write("__NativeObjectId = -1\n")
  #  f.write("__memory = array.array('l', 100000 * [0])\n")

    f.write("__stringOBJ = {}\n")
    f.write("i = 0\n")
    f.write("while (i < 10000):\n")
    f.write("\t__stringOBJ[i] = 0\n")
    f.write("\ti += 1\n")

    f.write("__strings = {}\n")
    f.write("i = 0\n")
    f.write("while (i < 10000):\n")
    f.write("\t__strings[i] = 0\n")
    f.write("\ti += 1\n")



    f.write("__memory = {}\n")
    f.write("i = 0\n")
    f.write("while (i < 10000):\n")
    f.write("\t__memory[i] = 0\n")
    f.write("\ti += 1\n")

    w(f, "def Sys__disposeStrings():\n")
    w(f, "\tfor s in __stringOBJ:\n")
    w(f, "\t\tString__dispose(s)\n")



    w(f, "def get_string(n):\n")
    w(f, "\ttry:\n")
    w(f, "\t\t__stringOBJ[n]\n")
    w(f, "\texcept NameError:\n")
    w(f, "\t\ts=String__new(len(__strings[n]) + 2)\n")
    w(f, "\t\tString__appendFromNative(s, __strings[n])\n")
    w(f, "\t\t__stringOBJ[n] = s\n")
    w(f, "\t\treturn __stringOBJ[n]\n")
    w(f, "\telse:\n")
    w(f, "\t\treturn __stringOBJ[n]\n")



#ast.process(f, "")
    callback = 0
    for c in ast.children:
        if (c.tag == "class"):
            nb_field = 0
            for m in c.children:
                if (m.tag == "function"):
                    w(f, "def " + c.data + "__" + m.data + "(")
                    for b in m.children:
                        if b.tag == "params":
                            co = ""
                            for a in b.children:
                                w(f, co + a.data)
                                co = ", "
                    w(f, "):\n")
                    global_(f, m, "\t");
                    for b in m.children:
                        if b.tag == "statements":
                            statements_(f, b, "\t")
                        elif b.tag == "vars":
                            vars_(f,b)
                    w(f, "\n")
                elif (m.tag == "field"):
                    nb_field += 1
                elif (m.tag == "static"):
                    w(f, c.data + "__" + m.data + "=0\n")
                elif (m.tag == "method" or m.tag == "callback"):
                    if (m.tag == "callback"):
                        callback=1
                    w(f, "def " + c.data + "__" + m.data + "(")
                    for b in m.children:
                        if b.tag == "params":
                            w(f, "__this")
                            for a in b.children:
                                w(f, ", " + a.data)
                    w(f, "):\n")
                    global_(f, m, "\t");
                    for b in m.children:
                        if b.tag == "statements":
                            statements_(f, b, "\t")
                        elif b.tag == "vars":
                            vars_(f,b)
                    w(f, "\n")
                elif (m.tag == "constructor"):
                    w(f, "def " + c.data + "__" + m.data + "(")
                    for b in m.children:
                        if b.tag == "params":
                            co = ""
                            for a in b.children:
                                w(f, co + a.data)
                                co = ", "
                    w(f, "):\n")

                    global_(f, m, "\t");
                    si = 0
                    w(f, "\t__this = Memory__alloc(" + str(nb_field) 
                            +  ")\n")
                    if (callback):
                        callback = 0
                        w(f, "\t__memory[__this] = " + c.data + "__callback\n")
                    for b in m.children:
                        if b.tag == "statements":
                            statements_(f,b, "\t")
                        elif b.tag == "vars":
                            vars_(f,b)
                    w(f, "\n")
    i = 0
    n = 1;
    while (i < stati):
        i += 1;
        j = 0
        k = 2
        for m in memory[i]:
            if (m != '"'):
                k = k + 1
        w(f, "__strings[" + str(i) + "] = \"\"" )
        n += 1
        for m in memory[i]:
            if (m != '"'):
                w(f, "+ chr(" + str(ord(m)) + ")") 
                n += 1
        w(f, "\n")
        n += 1
    f.write("__memory[0] = 1\n")
    w(f, "Sys__init()\n")
    f.close

