/*******************************************************************************

           10 December MMXXI PUBLIC DOMAIN by Jean-Marc Lienher

            The authors disclaim copyright to this source code.

 ******************************************************************************/

class Md {

is_biblio = false;
in_pre = false;
in_list = false;
no_br = false;
links = [];
toc = [];
toc_id = 0;

tocLine(txt)
{
	let i = 0;
	let l = txt.length;

	while (i < l && txt[i] == "#") {
		i++;
	}
	if (txt[i] != " ") {
		return;
	}
	if (i == 2) {
		this.toc.push("<li><a href=\"#toc" + this.toc.length + "\">" + 
			this.removeLinks(txt.substring(3), 1) + "</a><li>\n");		
	} else if (i == 3) {
		this.toc.push("<li> &nbsp; &nbsp; <a href=\"#toc" + 
			this.toc.length + "\">" + 
			this.removeLinks(txt.substring(4)) + "</a><li>\n");		
	}
}

genToc()
{
	let o = "";
	let i = 0;
	let l = this.toc.length;
	for (i = 0; i < l; i++) {
		o += this.toc[i];
	}
	return o;
}

genBiblio()
{
	let out = "";
	let l = this.links.length;
	out += "<ul class=\"biblio\">\n";
	for (let i = 0; i < l; i++) {
		out += "<li>[" + (i + 1);
		out += "] <a href=\"" + this.links[i];
		out += "\">" + this.links[i] + "</a></li>\n";
	}
	out += "</ul>";
	return out;
}

removeLinks(txt)
{
	let o = "";
	let e = "";
	let l = txt.length;
	let s = 0;
	let i = s;
	
	i = s; 
	while (i < l) {
		let img = false
		s = i;
		if (i < l - 4) {
			if (txt[i] == "!" && txt[i + 1] == "[") {
				img = true;
				i++;
			} 
			if (txt[i] == "[") {
				let n = 1;
				let lab = "";
				i++;
				while (i < l && n > 0) {
					if (txt[i] == "[") {
						n++;
					} else if (txt[i] == "]") {
						n--;
					}	
					if (n > 0) {
						lab += txt[i];
					}
					i++;
				}
				if (n == 0 && i < l && txt[i] == "(") {
					let href = "";
					i++;
					n = 1;
					while (i < l && n > 0) {
						if (txt[i] == "(") {
							n++;
						} else if (txt[i] == ")") {
							n--;
						} 
						if (n > 0) {
							href += txt[i];
						}
 						i++;
					}
					if (n == 0) {
						o += this.removeLinks(lab)
						continue;
					} else {
						i = s;
					}
				} else {
					i = s;
				}
			} else {
				i = s;
			}
		}
		if (i < l - 1 && txt[i] == "_") {
			if (txt[i + 1] == "_") {
				i++;
				let sub = "";
				i++;
				o += "";
				while (i < l) {
					if (txt[i] == "_" && i < l - 1 &&
						txt[i + 1] == "_") 
					{
						i++;
						i++;
						break;	
					}
					sub += txt[i];
					i++;
				}
				o += this.parseLine(sub, 1) + "";
				continue; 
			}
		}
	
		if (i < l - 1 && txt[i] == "*") {
			if (txt[i + 1] == "*") {
				i++;
				let sub = "";
				i++;
				o += "";
				while (i < l) {
					if (txt[i] == "*" && i < l - 1 &&
						txt[i + 1] == "*") 
					{
						i++;
						i++;
						break;	
					}
					sub += txt[i];
					i++;
				}
				o += this.parseLine(sub, 1) + "";
				continue; 
			}
		}
		o += txt[i];
		i++;
	}
	return o + e;
	
}


parseLine(txt, depth)
{
	let o = "";
	let e = "";
	let l = txt.length;
	let s = 0;
	let i = s;
	let in_list = false;

	this.is_biblio = false;
	
	// preformated
	if (i == 0) {
		while (i < l && txt[i] == "`") {
			i++;
		}
		if ((i - s) >= 3) {
			if (this.in_pre) {
				o += "</code></pre>\n";
				this.no_br = true;
			} else {
				o += "<pre><code>";
			}
			this.in_pre = !this.in_pre;
			s = i;
			return o;
		} 
	}
	if (this.in_pre) {
		while (i < l) {
			o += txt[i];
			i++;
		}
		return o;
	}

	if (depth == 0) {
		if (l == 0) {
			if (!this.no_br) {
				return "<br>\n";
			} 
			this.no_br = false;
			return "";
		}
	}
 
	// Header
	i = s;
	while (i < l && txt[i] == "#") {
		i++;
	}
	if (i > 0 && txt[i] == " ") {
		if (i == 2 || i == 3) {
			this.toc_id++;
			o += "<h" + i + " id=\"toc" + this.toc_id + "\">";
		} else {
			o += "<h" + i + ">";
		}
		e = "</h" + i + ">" + e;
		i++;
		s = i;
		this.no_br = true;
	}
	
	// Separator
	i = s;
	while (i < l && txt[i] == "*") {
		i++;
	}
	if ((i - s) >= 3) {
		o += "<hr>";
		this.no_br = true;
		s = i;
	}
	// text
	i = s; 
	while (i < l) {
		let img = false
		s = i;
		if (i < l - 4) {
			if (txt[i] == "!" && txt[i + 1] == "[") {
				img = true;
				i++;
			} 
			if (txt[i] == "[") {
				let n = 1;
				let lab = "";
				i++;
				while (i < l && n > 0) {
					if (txt[i] == "[") {
						n++;
					} else if (txt[i] == "]") {
						n--;
					}	
					if (n > 0) {
						lab += txt[i];
					}
					i++;
				}
				if (n == 0 && i < l && txt[i] == "(") {
					let href = "";
					i++;
					n = 1;
					while (i < l && n > 0) {
						if (txt[i] == "(") {
							n++;
						} else if (txt[i] == ")") {
							n--;
						} 
						if (n > 0) {
							href += txt[i];
						}
 						i++;
					}
					if (n == 0) {
						if (img && (href.length > 0)) {
							o += "<img src=\"" 
								+ href
								+ "\" alt=\"" 
								+ lab 
								+ "\">";
						} else if (img) {
							if (lab == "toc") {
								o += this.genToc();
								this.no_br = true;
							} else if (lab == "links") {
								this.no_br = true;
								this.is_biblio = true;
								return "";
							}
						} else if (href[0] != ".") {
							this.links.push(href);
							o += "<a href=\"" 
								+ href
								+ "\">" 
								+ this.parseLine(lab, depth + 1)
								+ "<sup>[" 
								+ this.links.length
								+ "]</sup></a>";
						} else {
							o += "<a href=\"" 
								+ href
								+ "\">" 
								+ this.parseLine(lab, depth + 1) 
								+ "</a>";
	
						}
						continue;
					} else {
						i = s;
					}
				} else {
					i = s;
				}
			} else {
				i = s;
			}
		}
		if (i < l - 1 && txt[i] == "_") {
			if (txt[i + 1] == "_") {
				i++;
				let sub = "";
				i++;
				o += "<i>";
				while (i < l) {
					if (txt[i] == "_" && i < l - 1 &&
						txt[i + 1] == "_") 
					{
						i++;
						i++;
						break;	
					}
					sub += txt[i];
					i++;
				}
				o += this.parseLine(sub, depth + 1) + "</i>";
				continue; 
			}
		}
	
		if (i < l - 1 && txt[i] == "*") {
			if (txt[i + 1] == " ") {
				let x = i - 1;
				while (x >= 0 && txt[x] == " ") {
					x--;
				}
				if (x == -1) {
					if (!this.in_list) {
						o += "<ul>\n";
						this.in_list = true;
					}
					in_list = true;
					o += "<li>";
					e = "</li>" + e;
					this.no_br = true;
					i++;
					i++;
					continue;
				}
			} else if (txt[i + 1] == "*") {
				i++;
				let sub = "";
				i++;
					o += "<b>";
				while (i < l) {
					if (txt[i] == "*" && i < l - 1 &&
						txt[i + 1] == "*") 
					{
						i++;
						i++;
						break;	
					}
					sub += txt[i];
					i++;
				}
				o += this.parseLine(sub, depth + 1) + "</b>";
				continue; 
			}
		}
		o += txt[i];
		i++;
	}
	if (depth == 0 && this.in_list && !in_list) {
		o = "</ul>\n" + o;
		this.no_br = true;
		this.in_list = false;
	}
	if (depth == 0) {
		e += "\n";
	}
	return o + e;
	
}

toHtml(txt, title, lang, foot)
{
	this.toc_id = 0;
	this.toc = [];
	this.links = [];
	this.in_list = false;
	this.in_pre = false;
	this.no_br = false;

	let out = "<!DOCTYPE html>\n"
	+ "<html lang=\"" + lang + "\" style=\"height:100%\">\n"
	+ "<head>\n"
	+ "<meta charset=\"utf-8\">\n"
	+ "<meta name=\"viewport\"" 
	+ " content=\"width=device-width, initial-scale=1.0\">\n"
	+ "<title>" + title + "</title>\n"
	+ "<link rel=\"stylesheet\" href=\"style.css\">\n"
	+ "</head>\n"
	+ "<body><div class=\"c\">\n"

	let lines = txt.split("\n");
	let l = lines.length;
	let body = "";
	let before_biblio = "";

	this.toc.push("<ul>\n");
	for (let i = 0; i < l; i++) {
		this.tocLine(lines[i]);	
	}
	this.toc.push("</ul>");


	for (let i = 0; i < l; i++) {
		let v = "";
		if (!this.in_pre && i < l - 1) {
			let sub = lines[i + 1].substr(0, 3);
			if (sub == "===") {
				v = this.parseLine(lines[i], 1);
				v = "<h1><u>" + v + "</u></h1>\n";
				this.no_br = true;
				i++;
			} else if (sub == "---") {
				v = this.parseLine(lines[i], 1);
				v = "<h3>" + v + "</h3>\n";
				this.no_br = true;
				i++;
			} else {
				v = this.parseLine(lines[i], 0);
			}	
		} else {
			v = this.parseLine(lines[i], 0);
		}
		if (this.is_biblio) {
			before_biblio = body;
			body = "";
		}
		body += v;
	}
	if (before_biblio != "") {
		out += before_biblio + this.genBiblio() + body;
	} else {
		out += body;
	}

	out += "</div><div>" + foot + "</div></body>\n</html>";
	return out;
}

constructor () 
{

}

}; // class
