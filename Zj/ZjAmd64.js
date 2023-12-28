class ZjAmd64Symbol {

$(o) { return o; }

constructor(next, hash, key, data) 
{
    this.next = next;
    this.hash = hash;
    this.key = key;
    this.data = data;
}

dispose() 
{
    delete this.data;
    delete this;
}

} // class

class ZjAmd64 {

$(o) { return o; }


constructor()
{
	this.buffer = new ZjByteArray();
}

dispose()
{
	this.buffer.dispose();
	delete this;
}

label(name)
{

}

org(pos) {

}

section(name) {

}

u8(v)
{
	this.buffer.u8(v);	
}

utf8(data)
{
	this.buffer.utf8(data);
}

utf16le(v)
{
	this.buffer.utf16le(v);
}

u16le(v)
{
	this.buffer.u16le(v);
}

u32le(v)
{
	this.buffer.u32le(v);
}

u64le(high, low)
{
	this.buffer.u32le(low);
	this.buffer.u32le(high);
}

u16be(v)
{
	this.buffer.u16be(v);	
}

u32be(v)
{
	this.buffer.u32be(v);
}

u64be(high, low)
{
	this.buffer.u32be(high);
	this.buffer.u32be(low);
}

} // class

