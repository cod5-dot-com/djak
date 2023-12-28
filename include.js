/*******************************************************************************

            7 December MMXXI PUBLIC DOMAIN by Jean-Marc Lienher

            The authors disclaim copyright to this source code.

 ******************************************************************************/


let include_loading = 0;

if (typeof process != "undefined") {
	global.include = global.include || include;
	global.bind = global.bind || bind;
}

function node_alert(m)
{
	console.log(m);
}

function include(src)
{
	if ((typeof navigator == "undefined")) {
		global.window = global.window || global;
		global.document = global.document || {};
		global.alert = global.alert || node_alert;
		global.run = global.run || run;
		require(src);
		return;
	}
	window.process = window.process || {};
	window.process.argv = window.process.argv || [];
	include_loading++;
	let s = document.createElement("script");
	let r = document.getElementById("scripts").parentNode;
	let x = null;
	r.appendChild(s);
	s.setAttribute("src", src + ".js");
	s.addEventListener("load", includeScriptLoaded, false);
}

function includeScriptLoaded(ev)
{
	include_loading--;
	if (include_loading == 0) {
	
		include_loading = -128;

	}
	//window[ev.target.data] ;
}

function run(app)
{
	if (typeof navigator == "undefined") {
		app.main();	
	} else {
		if (include_loading < 0) {
			app.main();
		} else {
			setTimeout(run, 50, app);
		}
	}
}

/*
function bind(cls, callback) {
	return cls[callback].bind(cls);
}
*/
