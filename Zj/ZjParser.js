/*******************************************************************************

           6 January MMXXII PUBLIC DOMAIN by Jean-Marc Lienher

            The authors disclaim copyright to this source code.

 ******************************************************************************/


class ZjParser {

$(o) { return o; }

constructor()
{
    this.progressCB = null;
    this.tk = null;
    this.s = "";
    this.ast = new ZjAst("", 0, null);
    this.root = this.ast;
    this.ok = true;
    this.member = this.root;
}

dispose()
{
    this.ast.dispose();
    delete this;
}

reset()
{
    delete this.ast;
    this.ast = new ZjAst("", 0, null);
    this.root = ast;
    this.ok = true;
}

log(d)
{
    this.s += "" + d;
}

parse(tok, cb)
{
    this.s = ">>>";
    this.progressCB = cb;
    this.tk = tok;

    setTimeout(this.parseCB.bind(this), 1);
}

match(token, id, precedence, advance) 
{
	let a = this.ast;
    	if (advance) {
        	this.advance();
    	}
    	if (token == null) {
        	if (id != this.tk.type) {
            		return false;
        	}
    	} else {
        	if (token != this.tk.token) {
            		return false;
        	}
    	}

	if (precedence < 0) {
		switch (-precedence) {
		case 2:
			this.ast = this.ast.add_child(id, this.tk.token, 0);
			break;
		case 1:
			this.ast = this.ast.add(id, this.tk.token, 0);
			break;
		}
		return true;
	}
	
	switch (id) {
	case ZjT.RIGHT_CURLY_BRACKET:
		while (a.parent != null && a.id != ZjT.LEFT_CURLY_BRACKET) {
			a = a.parent;
		}
		
		if (a.id != ZjT.LEFT_CURLY_BRACKET) {	
			this.log("unmatched }");
			return false;
		}
		this.ast = a;
		return true;
	case ZjT.RIGHT_SQUARE_BRACKET:
		while (a.parent != null && a.id != ZjT.LEFT_SQUARE_BRACKET) {
			a = a.parent;
		}
		
		if (a.id != ZjT.LEFT_SQUARE_BRACKET) {
			this.log("unmatched ]");
			return false;
		}
		this.ast = a;
		return true;
	case ZjT.RIGHT_PARENTHESIS:
		while ((a.parent != null) && (a.id != ZjT.LEFT_PARENTHESIS)) {
			a = a.parent;
		}
		if (a.id != ZjT.LEFT_PARENTHESIS) {
			this.log("unmatched ) ");
			return false;
		}
		this.ast = a;
		return true;
    	}
	    
	
	if (precedence > 0) {
		// 0xA = left to right
            	// 0xB = right to left
		let to = precedence & 0x0F;
		let p = precedence & 0xFFF0;
		let a = this.ast;
		if ((a.preced <= 0x1000) && (a.preced > 0) && (a.parent.preced > 0)) {
			while ((a.parent.preced > 0)) {
				if ((a.parent.preced & 0x0F) == 0) {
					break;
				}
				if (to == 0x0B) {
					if ((a.parent.preced & 0xFFF0) <= p) {
						break;
					}
				} else {
					if ((a.parent.preced & 0xFFF0) < p) {
						break;
					}
				}
				a = a.parent;
			}
		} else if ((to == 0x0B) && (a.preced < 0x1000)) {
			this.ast = a.add(id, this.tk.token, precedence);
			return true;
		}
		if ((to == 0x00)) {
			this.ast = a.add(id, this.tk.token, precedence);
			return true;
		}
		this.ast = a.add_op(id, this.tk.token, precedence);
		return true;
	}
    	this.ast = this.ast.add(id, this.tk.token, precedence);
    	return true;
}

add_member(m)
{
	this.ast = this.ast.add_child(ZjT.MEMBER, m, 0);
	this.member = this.ast;	
}


semicolon()
{
	
	while (this.ast.parent) {
		if (this.ast.id == ZjT.LEFT_CURLY_BRACKET ||
			this.ast.id == ZjT.LEFT_PARENTHESIS)
		{
			break;
		}
		this.ast = this.ast.parent;
	}
}

advance()
{
    if (this.tk.hasMoreTokens()) {
        return this.tk.advance();
    }
    return null;
}

parseCB() 
{ 
    let n = 10;
    while (this.ok && this.tk.hasMoreTokens()) {
        this.ast = this.root;
        let t = this.tk.advance();
        if (t == null) {
            break;
        }
        switch (t) {
        case "include":
            break;
        case "class":
            if (!this.parseClass()) {
                this.ok = false;
            } 
            this.ast = this.root;
            break;
        default:
            this.s += "Unknown " + t;
            this.ok = false;
            break;
        }

        
        //n--;
        if (this.ok && n <= 0) {
            setTimeout(this.parseCB.bind(this), 1);
            return;
        }
    }
    if (this.ok || true) {
        
        this.root.process(this.log.bind(this), 0);
    }
    let r = [];
    r.status = 200;
    r.response = "OK...";
    r.response = this.s + "END";
    this.progressCB(r);
}

parseClass()
{
    let z = false;
    z = this.match("class", ZjT.CLASS, -2, false);
    let a = this.ast;
    z = this.match(null, ZjT.IDENTIFIER, -2, true);
    if (!z) {
        this.log("missing identifier");
        return false;
    }
    this.ast = a;
    z = this.match("{", ZjT.LEFT_CURLY_BRACKET, -2, true);
    if (!z) {
        this.log("missing {");
        return false;  
    }
    let b = this.ast;
    this.advance();
   /* 
    z = this.classWrap();
    if (!z) {
	this.log("missing static  $(o) { return o; } !!!");
        return false;
    }*/
    
    while (this.tk.token != null) {
        this.ast = b;
        z = this.match("}", ZjT.RIGHT_CURLY_BRACKET, 0, false);
        if (z) {
            return true;
        }
        z = this.classStatic();
        if (!z) {
            z = this.classMethod();
        }
	if (!z) {
		return false;
	}
    }
    this.log("missing } got " + this.tk.token);
    return false;
}

classStatic()
{
    let z = false;
    if (this.tk.token != "static") {
	    return false;
    }

    this.add_member("staticVarOrMethod");
    
    z = this.match(null, ZjT.IDENTIFIER, -2, true);
    if (!z) {
        this.log("missing identifier");
        return false;
    }
    	let a = this.ast;
	a.preced = 0x1000;
    	this.ast = this.member;
    	z = this.match("(", ZjT.LEFT_PARENTHESIS, -2, true);
	if (z) {
        	this.member.id = ZjT.STATIC_METHOD;
        	this.advance();
        	return this.classMethodCommon();
    	}
	
    	this.member.id = ZjT.STATIC_VAR;
    	this.ast = a;
    	z = this.match("=", ZjT.ASSIGN, 0x02B, false);
    if (z) {
        this.advance();
        z = this.expression();
        if (!z) {
            return false;
        }
    }
    if (this.tk.token == ";") {
	    this.semicolon();
	    this.advance();
	    return true;
    }
    return false;
}

classMethod()
{
	let z = false;
	this.add_member("method");
	
	z = this.match(null, ZjT.IDENTIFIER, -2, false);
	if (!z) {
	    this.log("missing identifier");
	    return false;
	}
	let a = this.ast;
	this.ast = this.member;
	z = this.match("(", ZjT.LEFT_PARENTHESIS, -2, true);
	if (z) {
		this.member.id = ZjT.METHOD;
		this.advance();
		return this.classMethodCommon();
	}
	this.log("missing ( in method declaration ");
	return false;
}

classMethodCommon()
{
    let z = false;
    z = this.parameterList();
    if (!z) {
        return false;
    }
    z = this.match(")", ZjT.RIGHT_PARENTHESIS, 0, false);
    if (!z) {
        return false;
    }
    this.ast = this.member;
    z = this.match("{", ZjT.LEFT_CURLY_BRACKET, -2, true);
    if (!z) {
        return false;
    }
    this.advance();
    z = this.methodBody();
    if (!z) {
        return false;
    }
    z = this.match("}", ZjT.RIGHT_CURLY_BRACKET, 0, false);
    if (!z) {
        return false;
    }
    this.advance();
    return true;
}

methodBody()
{
    let z = true;
    while (z) {
        z = this.statement();
        if (!z) {
            return true;
        }
    }
    return true;
}

statement()
{
	let z = true;
	let a = this.ast;

	switch(this.tk.token) {
	case "if":
        	this.match("if", ZjT.IF, -2, false);
		this.advance();
        	z = this.ifStatement();
        	break;
	case "switch":
        	this.match("switch", ZjT.SWITCH, -2, false);
		this.advance();
        	z = this.switchStatement();
        	break;
	case "for":
        	this.match("for", ZjT.FOR, -2, false);
		this.advance();
        	z = this.forStatement();
        	break;
    	case "while":
        	this.match("while", ZjT.WHILE, -2, false);
		this.advance();
		z = this.whileStatement();
        	break;
    	case "do":
        	this.match("do", ZjT.DO, -2, false);
		this.advance();
        	z = this.doStatement();
        	break;
	case "let":
        	this.match("let", ZjT.LET, -2, false);
		this.advance();
        	z = this.letStatement();
        	break;
	case "return":
        	this.match("return", ZjT.RETURN, -2, false);
		this.advance();
        	z = this.returnStatement();
        	break;
    	case "}":
        	z = false;
        	break;
    	default:
		this.ast = this.ast.add_child(ZjT.STATEMENT, "stmt", 0);
        	z = this.expressionStatement();
        	break;
	}
	this.ast = a;
    	return z;
}

parameterList()
{
	let a = this.ast;
    	let z = this.match(null, ZjT.IDENTIFIER, -2, false);
    	if (!z) {
        	if (this.tk.token != ")") {
			return false;
		} else {
		
			return true;
		}
    	}
    	while (z) {
		this.advance();
		if (this.tk.token != ",") {
			if (this.tk.token != ")") {
				return false;
			} else {
				return true;
			}
		}
		this.ast = a;
        	z = this.match(null, ZjT.IDENTIFIER, -2, true);
        	if (!z) {
			this.log("missing identifier");
            		return false;
        	}     
    	}
    	return false;
}

ifStatement()
{
    	let z = this.match("(", ZjT.LEFT_PARENTHESIS, -1, true);

    	return z;
}

switchStatement()
{

}

forStatement()
{

}

whileStatement()
{

}

doStatement()
{

}

letStatement()
{
	let z = true;
	while (z) {
		z = this.varAssign();
		if (this.tk.token == ";") {
			this.advance();
			return true;
		}
		z = this.match(",", ZjT.COMMA, 0x01A, false);
		if (!z) {
			return true;
		}
		this.advance();
	}
	
	return false;
}

returnStatement()
{
	this.expression();
	if (this.tk.token == ";") {
		this.advance();
		return true;
	}
	return false;
}

varAssign()
{
	let z = false;
	z = this.match(null, ZjT.IDENTIFIER, -2, false);
	if (!z) {
		this.log("missing identifier");
	    	return false;
	}
	//this.log(this.tk.token);
	this.ast.preced = 0x1000;
	this.advance();
	if (this.tk.token == ";") {
		return false;
	}
	z = this.assignOp();
	if (!z) {
		this.log("missing assignment op");
		return false;
	}
	z = this.expression();
	if (!z) {
		return false;
	}
	return true;
}

expressionStatement()
{
	/*
	expressionStatement: assignTerm ';'
    | postfixTerm ';'
    | prefixTerm ';'
    | callTerm ';'*/
	let z = false;

	z = this.prefixOp();
	if (z) {
		z = this.expressionName();
		if (!z) {
			this.log("missing identifier");
			return false;
		}
		if (this.tk.token != ";") {
			this.log("missing ; ");
			return false;
		}
		this.advance();
		return true;
	}
	z = this.expressionName();
	if (z) {
		z = this.expressionStatementNext(); 
		if (!z) {
			this.log("bad expression");
			return false;
		}
		if (this.tk.token != ";") {
			this.log("missing ; ");
			return false;
		}
		this.advance();
		return true;
	}
	return false;
    	if (this.tk.type == ZjT.IDENTIFIER) {
        	z = this.match(null, ZjT.IDENTIFIER, -2, false);
        	this.advance();
        	switch (this.tk.token) {
            	case "(":
            	case "[":
            	case ".":
            	    // TODO:
                	break;
            	case "++":
                	this.match("++", ZjT.POSTFIX_INCREMENT, 0x160, false);
                	this.advance();
                	return true;
            	case "--":
                	this.match("--", ZjT.POSTFIX_DECREMENT, 0x160, false);
                	this.advance();
                	return true;
            	case ";":
			this.semicolon();
                	this.advance();
                	return true;
            	default:
                	z = this.assignOp();
                	if (!z) {
                    		return false;
                	}
                	// FIXME
                	return this.expression();
            	}       
    	} else {
        	switch (this.tk.token) {
        	case "++":
        	case "--":
            		return this.expression();
        	case ";":
	    		this.semicolon();
            		this.advance();
            		return true;
        	}
    	}
    	return false;
}

expressionStatementNext()
{
	let z = this.postfixOp();
	if (z) {
		return true;
	}
	z = this.assignOp();
	if (z) {
		return this.expression();
	}
	z = this.match("(", ZjT.LEFT_PARENTHESIS, 0x190, false);
	if (z) {
		this.advance();
		z = this.expressionList();
		if (z) {
			// FIXME
			z = this.match(")", ZjT.RIGHT_PARENTHESIS, 0x190, false);
			if (z) {
				this.advance();
				return true;
			}
		}
		return false;
	}
	return false;
/*	expressionStatementNext: postfixOp
	| assingOp expression
	| '(' expressionList ')'
	*/
}

expression()
{
    // TODO:
    if (this.tk.token == ";") {
	    return true;
    }
    //this.log("OOOIIII"+ this.tk.token + "\n");
    let z = this.term();
    if (!z) {
        return false;
    }
    while (z) {
        z = this.op();
	//this.log(z + "PO"+ this.tk.token + "\n")
        if (z) {
            z = this.term();
        }
	//this.log(z + "PU"+ this.tk.token + "\n")
    }
/*
    switch (this.tk.token) {
        case "++":
            // 0xA = left to right
            // 0xB = right to left
            this.match("++", ZjT.PREFIX_INCREMENT, 0x15B, false);
            this.advance();
            return true;
        case "--":
            this.match("--", ZjT.PREFIX_DECREMENT, 0x15B, false);
            this.advance();
            return true;
        case ";":
            return true;
        }*/
    return true;
}


term()
{
	let z = false;
	switch (this.tk.type) {
	case ZjT.INTEGER:
	case ZjT.STRING:
	case ZjT.QUOTE:
		this.ast = this.ast.add(this.tk.type, this.tk.token, 0x1000);
		this.advance();
		return true;

	default:
		z = this.match("(", ZjT.LEFT_PARENTHESIS, 0x190, false);
		if (z) {
			this.advance();
			z = this.expression();
			if (!z) {
				this.log("missing expression");
				return false;
			}
			//this.log(z + "PAA"+ this.tk.token + "\n")
			z = this.match(")", ZjT.RIGHT_PARENTHESIS, 0x19B, false);
			if (!z) {
				this.log(") expected...");
				return false;
			}
			//this.log("OOOOOOOOOOOOOO");
			this.advance();
			return true;
		}
		if (this.expressionName()) {
			return true;
		}
		break;
	}
   	return false;
}

expressionName()
{
	switch (this.tk.type) {
	case ZjT.IDENTIFIER:
		this.ast = this.ast.add(this.tk.type, this.tk.token, 0x1000);
		this.advance();
		return true;
	}
	return false;
}

op()
{
	let t = 0;
	let p = 0x001A;
	if (this.assignOp()) {
		return true;
	}
	switch(this.tk.token) {
	case "+":
	case "-":
	    	//t = ZjT.ASSIGN;
		p = 0x12A;
	    	break;
	case "*":
	case "/":
	case "%":
		p = 0x13A;
		break;
	case ",":
		t = ZjT.COMMA;
		p = 0x01A;
		break;
	default:
		return false;       
	}
	this.match(this.tk.token, t, p, false);
	this.advance();
	return true;
}


postfixOp()
{
    	let t = 0;
    	let p = 0x0160;
    	switch(this.tk.token) {
    	case "++":
		t = ZjT.POSTFIX_INCREMENT;
		break;
	case "--":
		t = ZjT.POSTFIX_DECREMENT;
        	break;
	default:
	     return false;       
	}
	this.match(this.tk.token, t, p, false);
	this.advance();
	return true;
}

prefixOp()
{
    	let t = 0;
    	let p = 0x015B;
    	switch(this.tk.token) {
    	case "++":
	case "--":
        	//t = ZjT.ASSIGN;
		// FIXME
        	break;
	default:
	     return false;       
	}
	this.match(this.tk.token, t, p, false);
	this.advance();
	return true;
}
prefixOp()
{
    	let t = 0;
    	let p = 0x015B;
    	switch(this.tk.token) {
    	case "++":
	case "--":
        	//t = ZjT.ASSIGN;
		// FIXME
        	break;
	default:
	     return false;       
	}
	this.match(this.tk.token, t, p, false);
	this.advance();
	return true;
}

assignOp()
{
    let t = 0;
    let p = 0x002B;
    switch(this.tk.token) {
    case "=":
        t = ZjT.ASSIGN;
        break;
    case "|=":
    case "^=":
    case "&=":
    case "%=":
    case "/=":
    case "*=":
    case "-=":
    case "+=":
    case "??=":
    case "||=":
    case "&&=":
    case ">>=":
    case "<<=":
    case "**=":
    case ">>>=":
 
        break;
    default:
         return false;       
    }
    this.match(this.tk.token, t, p, false);
    this.advance();
    return true;
}

/*classWrap()
{
    let z = false;

    if (this.tk.token != "static") {
	    return false;
    }
    this.add_member("classWrap");
    this.ast.id = ZjT.STATIC_METHOD;
    let a = this.ast;

    z = this.match("$", ZjT.IDENTIFIER, -2, true);
    if (!z) {
        return false;
    }
    this.ast = a;
    z = this.match("(", ZjT.LEFT_PARENTHESIS, -2, true);
    if (!z) {
        return false;
    }
    z = this.match(null, ZjT.IDENTIFIER, -2, true);
    if (!z) {
        return false;
    }
    z = this.match(")", ZjT.RIGHT_PARENTHESIS, 0, true);
    if (!z) {
        return false;
    }
    this.ast = a;
    z = this.match("{", ZjT.LEFT_CURLY_BRACKET, -2, true);
    if (!z) {
        return false;
    }
    z = this.match("return", ZjT.RETURN, -2, true);
    if (!z) {
        return false;
    }
    z = this.match(null, ZjT.IDENTIFIER, 0, true);
    if (!z) {
        return false;
    }
    this.advance();
    if (this.tk.token == ";") {
	    this.semicolon();
    } else {
	    return false;
    }
    z = this.match("}", ZjT.RIGHT_CURLY_BRACKET, 0, true);
    if (!z) {
        return false;
    }
    this.advance();
    return true;
}*/

}