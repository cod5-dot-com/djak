/*
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

#define _DEFAULT_SOURCE
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <signal.h>

/* #define JACKDEBUG 1 */

#ifdef __SUBC__
#define var int
#else
#define var long
#endif
#define STR(s) ((var)(s + 2))
#define GETSTR(s) ((char*) string__get_buf(s))
#define GETLEN(s) ((var)strlen((char*)string__get_buf(s)))

#define FREE(m) free(m)

#define std__free(mem) if (((var*)mem)[-1] > 0) \
	free((((var*)mem)-2))

#define MALLOC(s) malloc(s)

#define NEW(c) var __this; \
	__this = std__alloc(c##___DsizeD, __parent, c##___DcidD); \
	std__sweep()

#define std__this(a) this_##a

#define std__delete(a) \
	std__maybe_delete(a, __this)

#define std__maybe_delete(a,b) \
	if (a != 0 && ((((var*)a)[-2] == b) || (((var*)a)[-2]) == -1)) { \
		virtual__dispose(a); \
	}

#define std__move(a) std___move(a, __this)

#define std__move_to(a, b) std___move(a, b)

#define MAKETHIS(a) struct a *_this; \
		_this = (void*)__this; \
		(void)_this
#define FAKETHIS() var __this = 1; \
		(void)__this

#define std__address_of(v) \
        ((var)&v)

#define std__or(a, b) ((a) | (b))
#define std__xor(a, b) ((a) ^ (b))
#define std__and(a, b) ((a) & (b))
#define std__sll(a, b) ((a) << (b))
#define std__slr(a, b) ((var)(((unsigned var)(a)) >> (b)))


var std__panic();
var std__sweep();
var main__main(void);
var std__lambda(var __this, var lambda_id, var status, var data, var type);

