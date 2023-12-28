/*
 *          MMXXIII December 11 PUBLIC DOMAIN by O'ksi'D
 *
 *        The authors disclaim copyright to this software.
 *
 * Anyone is free to copy, merge, modify, publish, use, compile, sell,
 * or distribute this software, either in source code form or as a
 * compiled binary, for any purpose, commercial or non-commercial, and
 * by any means.
 *
 * Anyone is free to create, communicate to the public, use, sell,
 * repair, modify, test, distribute or configure hardware in finished
 * or intermediate form, whether by manufacture, assembly, compiling,
 * processing, loading or applying this software or another hardware or
 * otherwise.
 *
 * THE SOFTWARE AND/OR HARDWARE ARE PROVIDED "AS IS", WITHOUT WARRANTY
 * OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT OF ANY PATENT, COPYRIGHT, TRADE SECRET OR OTHER
 * PROPRIETARY RIGHT.  IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE AND/OR HARDWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE
 * AND/OR HARDWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 */

var std__alloc(var size, var parent, var cid)
{
	var *m;
	m = (var*)MALLOC(sizeof(var) * (size + 2));
	m[0] = parent; /* reserved for memory managemnt (ref counting...) */
	m[1] = cid; /*  class ID */
	return (var)(m + 2);
}

var std___move(var obj, var parent)
{
	if (obj == 0) {
		return 0;
	}
	if (((var*)obj)[-2] >= 0) {
		((var*)obj)[-2] = parent;
	}
	return obj;
}

var std__panic()
{
	var m[1];
	m[0] = 0;
	printf("PANIC!\n");
	((int(*)())m[0])();
	exit(-1);
	return 0;
}

var std__new_string(var size, var __parent)
{
	var s;
	s = string__new(size, __parent);
	return s;
}

var bytes__new(var size, var __parent)
{
	var s;
	var *m;
	s = (size + sizeof(var) - 1) / sizeof(var);
	m = (var*)MALLOC((s+4) * sizeof(var));
	m[0] = __parent;
	m[1] = bytes___DcidD;
	m[2] = (var)(m + 4);
	m[3] = size;
	return (var)(m + 2);
}

var std__bytes_dispose(var bb)
{
	FREE((void*)(((var*)bb) - 2));
	return 0;
}

var bytes__get_buf(var bb)
{
	return (var)(((var*)bb) + 2);
}

#define bytes__get_at(bb, at) \
        ((char*)(((var*)bb) + 2))[at]

/*
var bytes__get_at(var bb, var at)
{
	char *b;
        b = (char*)(((var*)bb) + 1);
	return b[at];
}
*/

#define bytes__set_at(bb, at, v) \
	((char*)(((var*)(bb)) + 2))[at] = ((v) & 0xFF)

/*
var bytes__set_at(var bb, var at, var v)
{
	char *b;
	b = (char*)(((var*)bb) + 2);
	b[at] = v & 0xFF;
	return 0;
}
*/

var std__strfree(var b)
{
	void *m;

	if (((var*)b)[-1] >= 0) {
		m = (void*)string__get_buf(b);
		if (m) {
			FREE(m);
		}
	}
	return 0;
}

var std__string_release(var s)
{
	if (((var*)s)[-1] >= 0) {
		std__strfree(s);
		std__free(s);
	}
	return 0;
}

var std__stralloc(var obj, var len)
{
	char *b;
	b = MALLOC(len);
	b[0] = 0;
	std__strfree(obj);
	string__set_buf(obj, (var)b);
	return (var)b;
}

var std__strlen(var str)
{
	char *b;
	b =(char*)string__get_buf(str);
	if (!b) {
		return 0;
	}
#ifdef __SUBC__
	return (var)_strlen(b);
#else
	return (var)strlen(b);
#endif
}

/* dest size must be maxlen+1 */
var std__append(var dest, var dpos, var src, var start, var maxlen)
{
	char *d;
	char *s;
	d = (char*)string__get_buf(dest) + dpos;
	s = (char*)string__get_buf(src) + start;
	maxlen -= dpos;
	if (maxlen < 0) {
		maxlen = 0;
	}
	memmove(d, s, maxlen);
	d += maxlen;
	*d = '\0';
	return 0;
}

var std__str_set_int(var dest, var maxlen, var n)
{
#ifdef __SUBC__
	sprintf((char*)string__get_buf(dest), "%d", n);
#else
	sprintf((char*)string__get_buf(dest), "%ld", n);
#endif
	return 0;
}

var std__str_toint(var src)
{
	return atol((char*)string__get_buf(src));
}

var std__str_set_at(var dest, var pos, var val)
{
	char *b;
	b = (char*)string__get_buf(dest);
	b[pos] = (char)val;
	return 0;
}

var std__str_get_at(var dest, var pos)
{
	return ((char*)string__get_buf(dest))[pos];
}

var std__strindex(var haystack, var offset, var needle)
{
	char *r;
	char *h;
	char *n;
	h = (char*)string__get_buf(haystack);
	n = (char*)string__get_buf(needle);
	r = (char*)strstr(h + offset, n);
	if (r == NULL) {
		return -1;
	}
	return (var)(r - h);
}

var std__strcmp(var s1, var s2)
{
	return strcmp((char*)string__get_buf(s1), (char*)string__get_buf(s2));
}

var std__strhash(var s)
{
	char *p;
	var h = 0;
	p = (char*)string__get_buf(s);
	while (*p) {
		h += (h << 4) ^ *p;
		p++;
	}
	if (h < 0) {
		h = -h;
		if (h < 0) {
			h = 0;
		}
	}
	return h;
}

var std__get_size(var mem)
{
	var *m;
	m = (var*)((mem - 1) * sizeof(var));
	return (-m[0]) - 1;
}

var std__string2native(var data, char *buf, var maxlen)
{
	var l;
	char *sb;
	var i;

	l = GETLEN(data);
	sb = GETSTR(data);
	i = 0;
	while (i <= l && (i < maxlen)) {
		buf[i] = sb[i];
		i++;
	}
	if (i == maxlen) {
		buf[i-1] = 0;
	} else {
		buf[i] = 0;
	}
	return i;
}

var std__native2string(char *buf)
{
	var l;
	char *sb;
	var data;
	var i;

	l = strlen(buf);
	data = std__new_string(l + 1, -1);
	sb = GETSTR(data);
	i = 0;
	while (i <= l) {
		sb[i] = buf[i];
		i++;
	}
	return data;
}

var std__mkfolder(var cb, var this_cb)
{
	var status = 200;
	var data = 0;
	var t;
	struct tm *tp;
	char buf[255];
	int r;

	t = time(NULL);
	if (t < 0) {
		status = 403;
	} else {
		tp = gmtime(&t);
		if (tp == NULL) {
			status = 403;
		} else {
			sprintf(buf,
				"%s/%04d%02d%02d%02d%02d%02d",
				(char*)((var)getenv("HOME")),
				tp->tm_year + 1900,
				tp->tm_mon + 1, tp->tm_mday,
				tp->tm_hour, tp->tm_min, tp->tm_sec);
		}
	}
	if (status == 200) {
		r = mkdir(buf, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		if (r == 0) {
			data = std__native2string(buf);
		} else {
			data = std__native2string(strerror(errno));
			status = 403;
		}
	}
	worker__new(this_cb, cb, status, data, 0, -1);
	return 0;
}

static var std__concat(var folder, var name, char *buf, var size)
{
	var l;
	var fullpath;

	fullpath = std__new_string(1024, 0);
	string__add(fullpath, folder);
	string__add(fullpath, name);
	l = std__string2native(fullpath, buf, size);
	if (l >= size) {
		std__string_release(fullpath);
		fullpath = 0;
	}
	return fullpath;
}

var std__mkdir(var folder, var name, var cb, var this_cb)
{
	char buf[1024];
	var status = 200;
	var data = 0;
	var fullpath;
	int r;

	fullpath = std__concat(folder, name, buf, sizeof(buf));

	if (fullpath == 0) {
		data = std__native2string("invalid name.");
		status = 403;
	} else {
		r = mkdir(buf, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		if (r == 0) {
			data = fullpath;
		} else {
			std__string_release(fullpath);
			data = std__native2string(strerror(errno));
			status = 403;
		}
	}
	worker__new(this_cb, cb, status, data, 0, -1);
	return 0;
}

var std__read(var folder, var name, var seek, var size, var cb, var this_cb)
{
	char fname[1024];
	var status = 200;
	var data = 0;
	var fullpath;
	FILE *fp;
	char *buf;
	int r;
	struct stat st;

	fullpath = std__concat(folder, name, fname, sizeof(fname));
	if (fullpath == 0) {
		data = std__native2string("invalid name.");
		status = 403;
	} else {
		if (size < 1) {
			if (access(fname, 0) == 0) {
				stat(fname, &st);
				if (S_ISDIR(st.st_mode) != 0) {
					data = std__native2string(
						       "path is a directory.");
					status = 403;
				} else {
					size = st.st_size;
				}
			}
		}
		if (seek < 0) {
			seek = 0;
		}
		if (size > 0 && status == 200) {
			data = bytes__new(size + 1, -1);
			buf = (char*)bytes__get_buf(data);
			fp = fopen(fname, "r");
			if (fp) {
				fseek(fp, seek, SEEK_SET);
				r = fread(buf, 1, size, fp);
				fclose(fp);
			} else {
				r = -1;
			}
			bytes__set_size(data, r);
			if (r > size || r < 0) {
				bytes__dispose(data);
				data = std__native2string(
					       "error reading file.");
				status = 403;
			} else {
				if (r == 0) {
					status = 201;
				}
				buf[r] = '\0';
				bytes__set_size(data, r);
				worker__new(this_cb, cb, status, data, 1, -1);
				std__string_release(fullpath);
				return 0;
			}
		} else {
			data = std__native2string("nothing to read.");
			status = 403;
		}
	}
	worker__new(this_cb, cb, status, data, 0, -1);
	std__string_release(fullpath);
	return 0;
}

var std__write(var folder, var name, var data, var type, var seek,
	       var size, var cb, var this_cb)
{
	char fname[1024];
	var status = 200;
	var outstr = 0;
	var fullpath;
	FILE *fp;
	char *buf;
	int r;
	struct stat st;
	char *mode;

	mode = "w";
	fullpath = std__concat(folder, name, fname, sizeof(fname));
	if (fullpath == 0) {
		outstr = std__native2string("invalid name.");
		status = 403;
	} else {
		if (access(fname, 0) == 0) {
			stat(fname, &st);
			if (S_ISDIR(st.st_mode) != 0) {
				std__string_release(fullpath);
				outstr = std__native2string(
						 "path is a directory.");
				status = 403;
			} else {
				mode = "rs+";
			}
		}
		if (seek < 0) {
			seek = 0;
			truncate(fname, 0);
		}
		if (size > 0 && status == 200) {
			if (type == 0) {
				buf = (char*)string__get_buf(data);
			} else {
				buf = (char*)bytes__get_buf(data);
			}
			fp = fopen(fname, mode);
			if (fp) {
				if (seek != 0) {
					fseek(fp, seek, SEEK_SET);
				}
				r = 0;
				if (r < size) {
					r = fwrite(buf, 1, size, fp);
				}
				fclose(fp);
			} else {
				r = -1;
			}
			if (type != 0) {
				bytes__set_size(data, r);
			}
			if (r != size) {
				std__string_release(fullpath);
				outstr = std__native2string(
						 "error writing file.");
				status = 403;
			} else {
				outstr = fullpath;
			}
		} else {
			std__string_release(fullpath);
			outstr = std__native2string("nothing to write.");
			status = 403;
		}
	}
	worker__new(this_cb, cb, status, outstr, 0, -1);
	return 0;
}

var std__filesize(var folder, var name, var cb, var this_cb)
{
	char fname[1024];
	var status = 200;
	var outstr = 0;
	var fullpath;
	var size;
	struct stat st;

	fullpath = std__concat(folder, name, fname, sizeof(fname));
	if (fullpath == 0) {
		outstr = std__native2string("invalid name.");
		status = 403;
	} else {
		if (access(fname, 0) == 0) {
			stat(fname, &st);
			if (S_ISDIR(st.st_mode) != 0) {
				std__string_release(fullpath);
				outstr = std__native2string(
						 "path is a directory.");
				status = 403;
			} else {
				size = st.st_size;
				string__set_int(fullpath, size);
				outstr = fullpath;
			}
		} else {
			std__string_release(fullpath);
			outstr = std__native2string(strerror(errno));
			status = 403;
		}
	}
	worker__new(this_cb, cb, status, outstr, 0, -1);
	return 0;
}

var std__scandir(var folder, var name, var cb, var this_cb)
{
	char dname[1024];
	var status = 200;
	var outstr = 0;
	var fullpath;
	struct dirent *dp;
	DIR *dir;
	char *s;
	char *outp;
	var outl;
	var outa;
	var l;
	var dl;
	char *tmp;

	fullpath = std__concat(folder, name, dname, sizeof(dname));

	if (fullpath == 0) {
		outstr = std__native2string("invalid name.");
		status = 403;
	} else {
		dir = opendir(dname);
		if (dir == (void*)0) {
			std__string_release(fullpath);
			outstr = std__native2string(strerror(errno));
			status = 403;
		}
	}
	if (status == 200) {
		std__string_release(fullpath);

		std__string2native(name, dname, sizeof(dname) - 1);
		dl = strlen(dname);
		if (dl == 0) {
			std__string2native(folder, dname, sizeof(dname) - 1);
			dl = strlen(dname);
			if (dl == 0 || (dname[dl - 1] != '/')) {
				dname[0] = '\0';
				strcat(dname, "./");
				dl = 2;
			}
		} else {
			if (dname[dl - 1] != '/') {
				dname[dl] = '/';
				dl++;
				dname[dl] = '\0';
			}
		}
		dp = readdir(dir);
		outl = 0;
		outa = 4096;
		outp = MALLOC(outa);
		outp[0] = '\0';
		while (dp != (void*)0) {
			s = dp->d_name;
			if (s[0] == '.' && (s[1] == '\0' ||
					    (s[1] == '.' && s[2] == '\0'))) {

			} else {
				l = strlen(s);
				while ((outa - outl) <= (l + dl + 3)) {
					outa += 4096;
					tmp = MALLOC(outa);
					tmp[0] = '\0';
					strcat(tmp, outp);
					FREE(outp);
					outp = tmp;
				}
				strcat(outp + outl, dname);
				outl += dl;
				strcat(outp + outl, s);
				outl += l;
				if (dp->d_type == DT_DIR) {
					outp[outl] = '/';
					outl++;
				}
				outp[outl] = '\n';
				outl++;
			}
			dp = readdir(dir);
		}
		closedir(dir);
		outstr = std__native2string(outp);
		FREE(outp);
	}
	worker__new(this_cb, cb, status, outstr, 0, -1);
	return 0;
}

var std__rmdir(var folder, var name, var cb, var this_cb)
{
	char fname[1024];
	var status = 200;
	var outstr = 0;
	var fullpath;
	var r;

	fullpath = std__concat(folder, name, fname, sizeof(fname));
	if (fullpath == 0) {
		outstr = std__native2string("invalid name.");
		status = 403;
	} else {
		r = rmdir(fname);
		if (r != 0) {
			std__string_release(fullpath);
			outstr = std__native2string(strerror(errno));
			status = 403;
		} else {
			outstr = fullpath;
		}
	}
	worker__new(this_cb, cb, status, outstr, 0, -1);
	return 0;
}

var std__unlink(var folder, var name, var cb, var this_cb)
{
	char fname[1024];
	var status = 200;
	var outstr = 0;
	var fullpath;
	var r;
	struct stat st;

	fullpath = std__concat(folder, name, fname, sizeof(fname));
	if (fullpath == 0) {
		outstr = std__native2string("invalid name.");
		status = 403;
	} else {
		if (access(fname, 0) == 0) {
			stat(fname, &st);
			if (S_ISDIR(st.st_mode) != 0) {
				std__string_release(fullpath);
				outstr = std__native2string(
						 "path is a directory.");
				status = 403;
			} else {
				r = remove(fname);
				if (r == -1) {
					std__string_release(fullpath);
					outstr = std__native2string(
							 strerror(errno));
					status = 403;
				} else {
					outstr = fullpath;
				}
			}
		} else {
			std__string_release(fullpath);
			outstr = std__native2string(strerror(errno));
			status = 403;
		}
	}
	worker__new(this_cb, cb, status, outstr, 0, -1);
	return 0;
}

var std__echo_nl()
{
	printf("\n");
	return 0;
}

var std__echo_int(var n)
{
#ifdef __SUBC__
	printf("%d", n);
#else
	printf("%ld", n);
#endif
	return 0;
}

var std__echo(var str)
{
	if (!str) return 0;
	fputs(GETSTR(str), stdout);
	return 0;
}

var std__exit(var n)
{
	exit(n);
	return 0;
}

static var std_args = 0;
static var std_argc = 0;

var std__get_args()
{
	return std_args;
}

var std__get_argc()
{
	return std_argc;
}

static var std__workers = 0;
static var std__delayed_dispose_buf = 0;

var std__push_worker(var ev)
{
	buffer__push(std__workers, ev);
	return 0;
}

var std__pending()
{
	if (buffer__length(std__workers) > 0) {
		return 1;
	}
	return 0;
}

var std__loop()
{
	var ev;
	ev = buffer__shift(std__workers);
	while (ev != 0) {
		if (worker__process(ev) != 0) {
			std__push_worker(ev);
		} else {
			worker__dispose(ev);
		}
		ev = buffer__shift(std__workers);
	}
	return 0;
}

var std__sweep()
{
	var ev;
	if (std__delayed_dispose_buf == 0) {
		return 0;
	}
	while (buffer__length(std__delayed_dispose_buf) > 0) {
		ev = buffer__shift(std__delayed_dispose_buf);
		if (ev != 0) {
			virtual__delayed_dispose(ev);
		}
	}
	return 0;
}

var std__delayed_delete(var obj)
{
	buffer__push(std__delayed_dispose_buf, obj);
	return 0;
}


int main(int argc, char *argv[])
{
	int i;
	var s;
	var __this = 2;

	std__init_strings();
	std__delayed_dispose_buf = buffer__new(4, 0, __this);

	std_argc = argc;
	std_args = array__new(argc+1, __this);
	for (i = 0; i < argc; i++) {
		s = std__native2string(argv[i]);
		((var*)std_args)[i] = s;
	}
	((var*)std_args)[i] = 0;

	std__workers = buffer__new(10, 1, __this);

	main__main();
	std__sweep();

	for (i = 0; i < argc; i++) {
		std__string_release(((var*)std_args)[i]);
	}
	array__dispose(std_args);
	std_args = 0;
	buffer__dispose(std__workers);
	std__workers = 0;
	std__sweep();
	buffer__delayed_dispose(std__delayed_dispose_buf);
	std__delayed_dispose_buf = 0;
	return 0;
}

#undef GETSTR
#undef GETLEN
#undef FREE
#undef MALLOC

