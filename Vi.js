/*******************************************************************************

            15 November MMXXI PUBLIC DOMAIN by Jean-Marc Lienher

            The authors disclaim copyright to this source code.

 ******************************************************************************/

class Vi {

mousemoveCb (e)
{
}

clickCb (e)
{
}

keyupCb(e)
{
	if (this.getsel) {
		this.sel = window.getSelection().getRangeAt(0);
		this.getsel = false;
	}
	if (this.takefocus) {
		this.ed.focus();
		window.getSelection().removeAllRanges();
		window.getSelection().addRange(this.sel);
		this.takefocus = false;
		this.cmd.innerText = "";
	}
}

cutCb(e)
{
}

pasteCb(event)
{
    	let paste = (event.clipboardData || window.clipboardData).getData('text');

    	const selection = window.getSelection();
    	if (!selection.rangeCount) {
		return false;
	}
    	selection.deleteFromDocument();
	let n = document.createTextNode(paste);
    	selection.getRangeAt(0).insertNode(n);
	selection.getRangeAt(0).setEndAfter(n);
	selection.getRangeAt(0).setStartAfter(n);

    	event.preventDefault();	
}

copyCb(e)
{
}

focusinCb(e)
{
	this.insert = true;
	this.cmd.innerText = "";
}

keydownCb(e)
{
	var cmd = "";
	if (this.cmd.innerText.length > 0) {
		cmd = this.cmd.innerText.substring(0, 1);
	}
	//this.cmd.innerText = e.code;
	if (!this.insert && cmd == "") {
		if (e.code == "ArrowUp" 
			|| e.code == "ArrowDown"
			|| e.code == "ArrowLeft"
			|| e.code == "ArrowRight")
		{
			this.getsel = true;
			return true;
		}

		if (e.key == "i") {
			this.insert = true;
			this.cmd.focus();
			this.takefocus = true;
			return true;
		}
		if (e.key == ":" || e.key == "/") {
			this.cmd.focus();
			this.takefocus = false;
			return true;
		}

		if (e.key == "x") {
			this.takefocus = true;
			document.getSelection().deleteFromDocument();
			this.cmd.focus();
			return true;
		}
		e.preventDefault();
		return false;
	}
	if (!this.insert && cmd == ":") {
		if (e.code == "Enter") {
			if (this.exec) {
				this.exec(this.cmd.innerText.substring(1));
			}
			this.cmd.innerText = "";
			this.takefocus = false;
			this.getsel = false;
			this.ed.focus();
			window.getSelection().removeAllRanges();
			window.getSelection().addRange(this.sel);
			e.preventDefault();
			this.insert = false;
			return false;
		} else {
			this.cmd.focus();
		}
		return true;
	}
	if (!this.insert && cmd == "/") {
		this.cmd.focus();
		if (e.code == "Enter") {
			this.cmd.innerText = "";
		}
		return true;
	}

	if (e.code == "Escape") {
		this.ed.focus();
		if (this.insert) {
			this.insert = false;
			this.getsel = true;
		}
		this.cmd.innerText = "";
	}
	if (this.insert && e.code == "Enter") {
		e.preventDefault();
		this.sel = window.getSelection().getRangeAt(0);
		let n = document.createTextNode("\n");
		this.sel.insertNode(n);
		this.sel.setEndAfter(n);
		this.sel.setStartAfter(n);
	}
	return true;
}

setExec(c)
{
	this.exec = c;
}

constructor () {
	this.ed = document.getElementById("editor");
	this.cmd = document.getElementById("cmd");
	this.insert = true;
	this.takefocus = false;
	this.getsel = false;
	this.exec = null;
	//this.sel = document.getSelection().getRangeAt(0);
	this.sel = null;
	window.addEventListener("mousemove", this.mousemoveCb.bind(this));
	window.addEventListener("click", this.clickCb.bind(this));
	window.addEventListener("keydown", this.keydownCb.bind(this));
	window.addEventListener("keyup", this.keyupCb.bind(this));
	window.addEventListener("cut", this.cutCb.bind(this));
	window.addEventListener("copy", this.copyCb.bind(this));
	window.addEventListener("paste", this.pasteCb.bind(this));
	this.ed.addEventListener("focusin", this.focusinCb.bind(this));

	this.ed.focus();
}

}; // class
