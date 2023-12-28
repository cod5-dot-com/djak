
include("./Zj/ZjHash");
include("./Zj/ZjTokenizer");
include("./Zj/ZjAst");
include("./Zj/ZjByteArray")
include("./Zj/ZjAmd64");
include("./Zj/ZjParser");

class Zjc {
    
$(o) { return o; }

constructor(log, cb)
{
    this.tokenizer = new ZjTokenizer(log);
    this.parser = new ZjParser();
    this.completeCB = cb;
    this.log = log;
}   

dispose()
{
    delete this;
}



compile(file)
{
    this.log(file);
    this.tokenizer.reset();
    this.tokenizer.open(file, this.compileCB.bind(this));
}

compileCB(r)
{
    for (let i =0, b = 3; i <10; i++) {}

    if (r.status == 200) { // success
        //this.log(JSON.stringify(r));
        this.parser.parse(this.tokenizer, this.parseCB.bind(this));
        return;
    } else if (r.status == 102) { // progress
            this.log(r.response);
            return;
	} else { // error
		this.log("Error!" + JSON.stringify(r));
	}
    this.completeCB(r);
}

parseCB(r)
{
    this.completeCB(r);
}

}
