"""
 *                             jack to python 
 *
 *                      1 april MMXXI PUBLIC DOMAIN
 *           The author disclaims copyright to this source code.
 *
 *
"""


class Tree:
    def __init__(self, tag, data, parent=None):
        self.children = []
        self.tag = tag
        self.data = data
        self.left = None;
        self.right = None;
        self.parent = parent

    def add(self, tag, data):
        child = Tree(tag, data, self)
        self.children.append(child)
        return child

    def addop(self, data, left):
        child = Tree("op", data, self)
        child.left = left
        return child

    def set(self, tag, data):
        child = None
        for c in self.children:
            if (c.data == data) and (c.tag == tag):
                return c
        return self.add(tag, data)

    def __str__(self):
        if not self.children:
           return str("<" + self.tag + " data=\"" + self.data + "\"/>")
        return '<{tag} data="{data}">{children}</{tag}>'.format(tag=self.tag,data=self.data, children='\n '.join(map(str, self.children)))

    def process(self, f, n):
        print (n + str(self.tag) + " " + str(self.data) + "")
        l = n + "  ";
        if (self.left != None):
            print (l + "left ")
            self.left.process(f, l + "  ")
        if (self.right != None):
            print (l + "right ")
            self.right.process(f, l + "  ")
        for c in self.children:
            c.process(f, l)


