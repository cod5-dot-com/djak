
class ZjByteArray {

$(o) { return o; }


constructor()
{
	this.bufsize = 8;
	this.buffer = new Uint8Array(8);
	this.bufpos = 0;
}

dispose()
{

    delete this;
}

u8(v)
{
	if (this.bufpos >= this.bufsize) {
		let l = this.bufsize;
		let o = this.buffer;
		this.bufsize <<= 2;
		this.buffer = new Uint8Array(this.bufsize);
		let n = this.buffer;
		for (let i = 0; i < l; i++) {
			n[i] = o[i];
		}
	}
	this.buffer[this.bufpos] = v;
	this.bufpos++;
}

utf8(data)
{
// https://www.cl.cam.ac.uk/~mgk25/ucs/utf-8-history.txt
	
	if (data & 3221225472) { // 2^30 + 2^31
		this.u8(((data >>> 30) & 3) | 252); // 2^30
		this.u8(((data >>> 24) & 63) | 128); // 2^24
		this.u8(((data >>> 18) & 63) | 128);   // 2^18
		this.u8(((data >>> 12) & 63) | 128);    // 2^12
		this.u8(((data >>> 6) & 63) | 128);     // 2^6
		this.u8(((data) & 63) | 128);
	} else if (data > 2097152) {
		this.u8(((data >>> 24) & 3) | 248);
		this.u8(((data >>> 18) & 63) | 128);
		this.u8(((data >>> 12) & 63) | 128);
		this.u8(((data >>> 6) & 63) | 128);
		this.u8(((data) & 63) | 128);
	} else if (data > 65535) {
		this.u8(((data >>> 18) & 7) | 240);
		this.u8(((data >>> 12) & 63) | 128);
		this.u8(((data >>> 6) & 63) | 128);
		this.u8(((data) & 63) | 128);
	} else if (data > 2047) {
		this.u8(((data >>> 12) & 15) | 224);
		this.u8(((data >>> 6) & 63) | 128);
		this.u8(((data) & 63) | 128);
	} else if (data > 127) {
		this.u8(((data >> 6) & 31) | 192);
		this.u8(((data) & 63) | 128);
	} else { 
		this.u8(((data) & 127));
	}
}

utf16le(v)
{
	// https://stackoverflow.com/questions/66679330/convert-unicode-codepoint-to-utf-16
	if (v < 0xD800 || (v > 0xDFFF && v < 0x10000)) {
		this.u16le(v);
		return;
	}
	
	v -= 0x010000;
	this.u16le(((v & 0xFFC00) >>> 10) + 0xD800);
	this.u16le((v & 0x003FF) + 0xDC00);
}

u16le(v)
{
	this.u8(v);
	this.u8(v >>> 8);
}

u32le(v)
{
	this.u16le(v);
	this.u16le(v >>> 16);
}

u16be(v)
{
	this.u8(v >>> 8);
	this.u8(v);	
}

u32be(v)
{
	this.u16be(v >>> 16);
	this.u16be(v);
	
}


} // class