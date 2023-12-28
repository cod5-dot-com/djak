/*******************************************************************************

            3 January MMXXII PUBLIC DOMAIN by Jean-Marc Lienher

            The authors disclaim copyright to this source code.

 ******************************************************************************/
class ZjT {
static STRING = 1;
static QUOTE = 2;
static INTEGER = 3;
static FLOAT = 4;
static OP = 5;
static IDENTIFIER = 6;
static PUNCTUATION = 7;
static LEFT_CURLY_BRACKET = 8;
static RIGHT_CURLY_BRACKET = 9;
static LEFT_PARENTHESIS = 10;
static RIGHT_PARENTHESIS = 11;
static LEFT_SQUARE_BRACKET = 12;
static RIGHT_SQUARE_BRACKET = 13;
static SEMICOLON = 14;
static RETURN = 15;
static STATIC = 16;
static ASSIGN = 17;
static EQUAL = 18;
static STATIC_METHOD = 19;
static STATIC_VAR = 20;
static COMMA = 21;
static IF = 22;
static ELSE = 23;
static SWITCH = 24;
static FOR = 25;
static WHILE = 26;
static DO = 27;
static LET = 28;
static POSTFIX_DECREMENT = 29;
static POSTFIX_INCREMENT = 30;
static PREFIX_DECREMENT = 31;
static PREFIX_INCREMENT = 32;
static CLASS = 33;
static METHOD = 34;
static MEMBER = 35;
static EXPRESSION = 36;
static STATEMENT = 37;
}


class ZjTokenizer {

static $(o) { return o; }



constructor(log)
{
    this.log = log;
    this.progressCB = null;
    this.buffer = [];
    this.token = "";
    this.index = 0;
    this.len = 0;
    this.type = 0;
}

dispose()
{
    delete this;
}

reset()
{

}

open(file, cb)
{
    this.progressCB = cb;
    Fs.read(file, -1, -1, this.openCB.bind(this));
}

openCB(r)
{
    if (r.status == 200) {
        this.buffer = r.response;
        this.len = this.buffer.length;
        this.index = 0;
    } else if (r.status == 102) {

    } else {
    
    }
    this.progressCB(r); // FIXME
}

skipSpaces()
{
   
    let i = this.index;
    let l = this.len;
    let b = this.buffer;
    let c = "";
    while (i < l) {
        c = b[i];
        switch (c) {
        case " ".codePointAt(0):
        case "\n".codePointAt(0):
        case "\r".codePointAt(0):
        case "\t".codePointAt(0):
            i++;
            break;
        default:
            l = -1;
            break;
        }
    }
    this.index = i;
}

hasMoreTokens()
{
    this.skipSpaces();

    while (this.index < this.len) {
        if (this.buffer[this.index] == "/".codePointAt(0)) {
            let i = this.index + 2;
            let l = this.len;
            let b = this.buffer;
            let ok = false;
            switch (this.buffer[this.index + 1]) {
            case "/".codePointAt(0):
                while (i < l) {
                    if (b[i] == "\n".codePointAt(0) 
                        || b[i] == "\r".codePointAt(0))
                    {
                        break;
                    }
                    i++;
                }
                break;
            case "*".codePointAt(0):
                while (i < l + 1) {
                    if (b[i] == "*".codePointAt(0) 
                        && b[i + 1] == "/".codePointAt(0))
                    {
                        i = i + 2;
                        ok = true;
                        break;
                    }
                    i++;
                }
                if (!ok) {
                    this.log("Comment toward end of file.");
                    return false;
                }
                break;
            default:
                return true;
            }
            this.index = i;
            this.skipSpaces();
        } else {
            return true;
        }
    }
    return false;
}

advance()
{
    if (this.index >= this.len) {
        this.token = null;
        this.type = 0;
        return null;
    }
    let i = this.index;
    let l = this.len;
    let t = "";
    let b = this.buffer;
    let c = "";
    let a = 0;

    let single_quote = false;
    let double_quote = false;
    let escape = false;
    let floating = false;
    let decimal = false;
    let hexa = false;
    let identifier = false;
    let dot = false;
    let ll = 0;

    while (i < l) {
        a = b[i];
        c = String.fromCodePoint(a);

        if (double_quote || single_quote) {
            if (escape) {
                escape = false;
                switch (c) {
                // FIXME
                case "n":
                    c = "\n";
                    break;
                case "r":
                    c = "\r";
                    break;
                case "t":
                    c = "\t";
                    break;
                }
            } else {
                switch (c) {
                case "\\":
                    escape = true;
                    i++;
                    continue;
                case "\"":
                    if (double_quote) {
                        l = -1;
                        i++;
                    }
                    break;
                case "'":
                    if (single_quote) {
                        l = -1;
                        i++;
                    }
                    break;
                }
            }
        } else if (decimal || floating || hexa)  {
            if (c >= "0" && c <= "9") {

            } else if ((c == "x" || c == "X")  && t == "0") {
                decimal = false;
                hexa = true;
                this.type = ZjT.INTEGER;
            } else if (decimal && c == ".") {
                floating = true;
                decimal = false;
                this.type = ZjT.FLOAT;               
            } else if (hexa && 
                ((c >= "a" && c <= "f")
                || (c >= "A" && c <= "F") 
                ))
            {
                    //
            } else if (floating && (
                c == "E" || c == "e" || c == "-"
            )) {
                    //
            } else {
                l = -1;
            }
        } else if (dot) {
            if (c >= "0" && c <= "9") {
                dot = false;
                floating = true;
                this.type = ZjT.FLOAT;
            } else {
                l = -1;
            }
        } else if (identifier) {
            if ((c >= "0" && c <= "9")
                || (c >= "a" && c <= "z")
                || (c >= "A" && c <= "Z")
                || c == "_" || c == "$") 
            {
            } else {
                l = -1;
            }
        } else if (ll == 1) {
            switch (t) {
            case "=":
                if (c != "=") {
                    l = -1;
                    this.type = ZjT.OP;
                }
                break;
            case "?":
                if (c != "?") {
                    l = -1;
                    this.type = ZjT.OP;
                }
                break;
            case "|":
                if (c != "|" && c != "=") {
                    l = -1;
                    this.type = ZjT.OP;
                }
                break;
            case "^":
                if (c != "=") {
                    l = -1;
                    this.type = ZjT.OP;
                }
                break;
            case "&":
                if (c != "&" && c != "=") {
                    l = -1;
                    this.type = ZjT.OP;
                }
                break;
            case ">":
                if (c != ">" && c != "=") {
                    l = -1;
                    this.type = ZjT.OP;
                }
                break;
            case "<":
                if (c != "<" && c != "=") {
                    l = -1;
                    this.type = ZjT.OP;
                }
                break;
            case "-":
                if (c != "-" && c != "=") {
                    l = -1;
                    this.type = ZjT.OP;
                }
                break;
            case "+":
                if (c != "+" && c != "=") {
                    l = -1;
                    this.type = ZjT.OP;
                }
                break;
            case "%":
                if (c != "=") {
                    l = -1;
                    this.type = ZjT.OP;
                }
                break;
            case "/":
                if (c != "=") {
                    l = -1;
                    this.type = ZjT.OP;
                }
                break;
            case "*":
                if (c != "*") {
                    l = -1;
                    this.type = ZjT.OP;
                }
                break;
            case "~":
            case "!":
                if (c != "=") {
                    l = -1;
                    this.type = ZjT.OP;
                }
                break;
            }
        } else if (ll == 2) {
            switch (t) {
            case "|=":
            case "^=":
            case "&=":
            case "%=":
            case "/=":
            case "*=":
            case "-=":
            case "+=":
            case "--":
            case "++":
            case ">=":
            case "<=":
                l = -1;
                this.type = ZjT.OP;
                break;
            case ">>":
                if (c != "=" && c != ">") {
                    l = -1;
                    this.type = ZjT.OP;
                }
                break;
            case "??":
            case "||":
            case "&&":
            case "!=":
            case "<<":
            case "**":
            case "==":
               if (c != "=") {
                    l = -1;
                    this.type = ZjT.OP;
                }          
                break;  
            }
        } else if (ll == 3) {
            switch (t) {
            case ">>>":
                if (c != "=") {
                    l = -1;
                    this.type = ZjT.OP;
                } 
                break;   
            case "??=":
            case "||=":
            case "&&=":
            case ">>=":
            case "<<=":
            case "**=":
            case "!==":
            case "===":
                l = -1;
                this.type = ZjT.OP;
                break;
            }
        } else if (ll == 4) {
            switch (t) {
            case ">>>=":
                this.type = ZjT.OP;
                break;
            }
        } else {
            switch (c) {
            case "\"":
                double_quote = true;
                this.type = ZjT.STRING;
                i++;
                continue;
            case "'":
                single_quote = true;
                this.type = ZjT.QUOTE;
                i++;
                continue;
            case " ":
            case "\n":
            case "\r":
            case "\t":
                l = -1;
                break;
            case ".":
                dot = true;
                break;
            case "~":
                this.type = ZjT.OP;
                t = c;
                i++;
                l = -1;
                break;
            case ",":
            case ";":
            case ":":
            case "(":
            case ")":
            case "{":
            case "}":
            case "[":
            case "]":
                t = c;
                i++;
                l = -1;
                this.type = ZjT.PUNCTUATION;
                break;
            default:
                if (c >= "0" && c <= "9") {
                    decimal = true;
                    this.type = ZjT.INTEGER;
                } else if ((c >= "a" && c <= "z")
                    || (c >= "A" && c <= "Z")
                    || c == "_" || c == "$") 
                {
                    this.type = ZjT.IDENTIFIER;
                    identifier = true;
                }
                break;
            }
        }
        if (l > 0) {
            t += c;
            i++;
            ll++;
        }
    }
 
    this.index = i;
    this.token = t;
    return t;
}


getToken() 
{
    return this.token;
}

getType()
{
    return this.type;
}

}