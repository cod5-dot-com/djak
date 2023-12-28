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

var std__panic();
var std__sweep();
var main__main(void);
var std__lambda(var __this, var lambda_id, var status, var data, var type);

#define array___DsizeD 1
#define array___DcidD 11
var array__new(var size, var __parent);
#define array__dispose(___this) virtual__dispose(___this)
var array___V_dispose(var __this);
#define buffer___DsizeD 4
#define buffer___DcidD 12
var buffer___new(var __this, var initial_size, var take_, var __parent);
var buffer__new(var initial_size, var take_, var __parent);
#define buffer__delayed_dispose(___this) virtual__delayed_dispose(___this)
var buffer___V_delayed_dispose(var __this);
#define buffer__dispose(___this) virtual__dispose(___this)
var buffer___V_dispose(var __this);
var buffer__length(var __this);
var buffer__empty(var __this);
var buffer__delete_at(var __this, var idx);
var buffer__set_at(var __this, var idx, var elem);
var buffer__get_at(var __this, var idx);
var buffer__push(var __this, var elem);
var buffer__append(var __this, var buf);
var buffer__set_last(var __this, var elem);
var buffer__get_last(var __this);
var buffer__pop(var __this);
var buffer__unshift(var __this, var elem);
var buffer__shift(var __this);
#define bytes___DsizeD 2
#define bytes___DcidD 13
#define bytes__dispose(___this) virtual__dispose(___this)
var bytes___V_dispose(var __this);
var bytes__get_size(var __this);
var bytes__set_size(var __this, var size1);
#define console___DsizeD 0
#define console___DcidD 14
var console__log(var str);
var console__log_str(var str);
var console__log_int(var n);
#define file___DsizeD 1
#define file___DcidD 15
var file___new(var __this, var folder, var __parent);
var file__new(var folder, var __parent);
#define file__dispose(___this) virtual__dispose(___this)
var file___V_dispose(var __this);
var file__mkfolder(var __this, var cb, var this_cb);
var file__mkdir(var __this, var name, var cb, var this_cb);
var file__read(var __this, var name, var seek, var size_, var cb, var this_cb);
var file__write(var __this, var name, var data, var type, var seek, var size, var cb, var this_cb);
var file__filesize(var __this, var name, var cb, var this_cb);
var file__scandir(var __this, var name, var cb, var this_cb);
var file__rmdir(var __this, var name, var cb, var this_cb);
var file__unlink(var __this, var name, var cb, var this_cb);
#define hash___DsizeD 2
#define hash___DcidD 16
#define hash__Cnext 0
#define hash__Chash 1
#define hash__Ckey 2
#define hash__Cvalue 3
var hash___new(var __this, var size_, var __parent);
var hash__new(var size_, var __parent);
#define hash__dispose(___this) virtual__dispose(___this)
var hash___V_dispose(var __this);
var hash__add(var __this, var key, var value);
var hash__get(var __this, var key);
#define object___DsizeD 1
#define object___DcidD 17
var object___new(var __this, var __parent);
var object__new(var __parent);
#define object__dispose(___this) virtual__dispose(___this)
var object___V_dispose(var __this);
#define worker___DsizeD 5
#define worker___DcidD 18
var worker___new(var __this, var lambda_this_, var lambda_, var status_, var data_, var type_, var __parent);
var worker__new(var lambda_this_, var lambda_, var status_, var data_, var type_, var __parent);
#define worker__dispose(___this) virtual__dispose(___this)
var worker___V_dispose(var __this);
var worker__process(var __this);
#define std___DsizeD 0
#define std___DcidD 19
#define string___DsizeD 2
#define string___DcidD 20
var string___new(var __this, var alloc, var __parent);
var string__new(var alloc, var __parent);
#define string__dispose(___this) virtual__dispose(___this)
var string___V_dispose(var __this);
var string__get_buf(var __this);
var string__set_buf(var __this, var b);
var string__get_size(var __this);
var string__set_size(var __this, var ns);
var string__length(var __this);
var string__set_int(var __this, var num);
var string__set(var __this, var src);
var string__add_char(var __this, var num);
var string__add(var __this, var src);
var string__add_at(var __this, var tl, var src);
var string__indexof(var __this, var start_pos, var needle);
var string__substr(var __this, var start_pos, var length_, var result);
var string__to_string(var __this);
var string__to_int(var __this);
var string__compare(var __this, var other);
var string__get_hash(var __this);
var string__get_at(var __this, var at);
var string__set_at(var __this, var at, var v);
#define Aclass___DsizeD 18
#define Aclass___DcidD 21
#define Aclass__Cstatic 2
#define Aclass__Cfield 3
#define Aclass__Cconst 4
#define Aclass__Cint 5
#define Aclass__Cvoid 7
#define Aclass__Cconstructor 8
#define Aclass__Cfunction 9
#define Aclass__Cmethod 10
#define Aclass__Cvirtual 11
#define Aclass__Cidentifier 12
#define Aclass__Cin 13
#define Aclass__Cout 14
#define Aclass__Cio 15
#define Aclass__Cvar 16
#define Aclass__Cbreak 17
#define Aclass__Cif 18
#define Aclass__Cwhile 19
#define Aclass__Creturn 20
#define Aclass__Cdo 21
#define Aclass__Clet 22
#define Aclass__Celse 23
#define Aclass__Celseif 24
#define Aclass__Cthis 25
#define Aclass__Cnull 26
#define Aclass__Cint_const 27
#define Aclass__Cchar_const 28
#define Aclass__Cstr_const 29
#define Aclass__Casync 32
#define Aclass__Cawait 33
#define Aclass__Clambda 34
#define Aclass__Cnew_wrap 35
#define Aclass__Ccase 36
#define Aclass__Cswitch 37
#define Aclass__Cifblock 38
#define Aclass__Cswitchblock 39
#define Aclass__Cdefault 40
#define Aclass__Croot 1000
#define Aclass__Cequal 1026
#define Aclass__Cnotequal 1027
#define Aclass__Clargerequal 1028
#define Aclass__Clesserequal 1029
#define Aclass__Clarger 1030
#define Aclass__Clesser 1031
#define Aclass__Clogicaland 1032
#define Aclass__Clogicalor 1033
#define Aclass__Cadd 1034
#define Aclass__Csub 1035
#define Aclass__Cmult 1036
#define Aclass__Cdiv 1037
#define Aclass__Cmodulo 1038
#define Aclass__Clogicalnot 1039
#define Aclass__Cparenthesis 1040
#define Aclass__Cunaryplus 1041
#define Aclass__Cunaryminus 1042
#define Aclass__Cdot 1043
#define Aclass__Ccall 1044
#define Aclass__Cindex 1045
#define Aclass__Ccomma 1046
#define Aclass__Cexpr 1047
#define Aclass__Cassign 1048
#define Aclass__Cconstant 1049
#define Aclass__Clr 1
#define Aclass__Crl 2
var Aclass___new(var __this, var token, var __parent);
var Aclass__new(var token, var __parent);
#define Aclass__dispose(___this) virtual__dispose(___this)
var Aclass___V_dispose(var __this);
#define Aclass__delayed_dispose(___this) virtual__delayed_dispose(___this)
var Aclass___V_delayed_dispose(var __this);
var Aclass__error(var __this, var err);
var Aclass__get_implements(var __this);
var Aclass__get_nb_lambda(var __this);
var Aclass__add_implements(var __this, var x);
var Aclass__get_members(var __this);
var Aclass__get_nb_fields(var __this);
var Aclass__set_next(var __this, var n);
var Aclass__get_next(var __this);
var Aclass__get_name(var __this);
var Aclass__pad(var __this, var p);
var Aclass__prepare_kind(var __this, var kind_);
var Aclass__prepare_type(var __this, var type_);
var Aclass__prepare_type_identifier(var __this, var id_);
var Aclass__prepare_set_name(var __this, var id_);
var Aclass__valid_member_name(var __this);
var Aclass__valid_param(var __this);
var Aclass__valid_var(var __this);
var Aclass__begin_else(var __this, var type_);
var Aclass__begin_stm(var __this, var type_, var orig);
var Aclass__finish_stm(var __this);
var Aclass__finish_const(var __this, var initialiser1);
var Aclass__begin_lambda(var __this, var id1);
var Aclass__finish_lambda(var __this);
var Aclass__finish_subroutine(var __this);
var Aclass__begin_expr(var __this, var orig);
var Aclass__finish_expr(var __this);
var Aclass__expr_op(var __this, var op_, var orig);
var Aclass__expr_open_par(var __this);
var Aclass__expr_in_par(var __this);
var Aclass__expr_close_par(var __this);
var Aclass__expr_open_index(var __this, var id_, var orig);
var Aclass__expr_close_index(var __this);
var Aclass__expr_begin_sub_call(var __this, var class_, var name_, var orig);
var Aclass__expr_next_expr(var __this, var orig);
var Aclass__expr_finish_sub_call(var __this);
var Aclass__expr_term(var __this, var term_, var orig);
var Aclass__expr_var(var __this, var name_, var orig);
var Aclass__expr_int_const(var __this, var value_, var orig);
var Aclass__expr_char_const(var __this, var value_, var orig);
var Aclass__expr_str_const(var __this, var value_, var orig);
var Aclass__expr_constant(var __this, var class_name_, var const_name_, var orig);
#define Aemmiter___DsizeD 3
#define Aemmiter___DcidD 22
var Aemmiter___new(var __this, var side1, var __parent);
var Aemmiter__new(var side1, var __parent);
#define Aemmiter__dispose(___this) virtual__dispose(___this)
var Aemmiter___V_dispose(var __this);
var Aemmiter__set_class(var __this, var class1);
var Aemmiter__set_member(var __this, var mb);
#define Aemmiter__emmit(___this, par) virtual__emmit(___this, par)
var Aemmiter___V_emmit(var __this, var par);
#define Aemmiter__get_head(___this) virtual__get_head(___this)
var Aemmiter___V_get_head(var __this);
#define Aemmiter__get_data(___this) virtual__get_data(___this)
var Aemmiter___V_get_data(var __this);
#define Aemmiter__get_mid(___this) virtual__get_mid(___this)
var Aemmiter___V_get_mid(var __this);
var Aemmiter__find_param(var __this, var stri);
var Aemmiter__find_field(var __this, var stri);
var Aemmiter__find_method(var __this, var stri);
var Aemmiter__find_static(var __this, var stri);
var Aemmiter__find_local(var __this, var stri);
var Aemmiter__find_variable(var __this, var stri);
var Aemmiter__is_switch(var __this, var st, var vari);
var Aemmiter__get_switch_expr(var __this, var st);
#define Aemmiter__gen_virtuals(___this) virtual__gen_virtuals(___this)
var Aemmiter___V_gen_virtuals(var __this);
#define Aemmiter__expr_process(___this, expr) virtual__expr_process(___this, expr)
var Aemmiter___V_expr_process(var __this, var expr);
var Aemmiter__expr_gen(var __this, var expr);
var Aemmiter__error(var __this, var t, var e);
var Aemmiter__dump(var __this);
#define Aemmitc___DsizeD 22
#define Aemmitc___DcidD 23
var Aemmitc___new(var __this, var debug1, var __parent);
var Aemmitc__new(var debug1, var __parent);
#define Aemmitc__dispose(___this) virtual__dispose(___this)
var Aemmitc___V_dispose(var __this);
#define Aemmitc__emmit(___this, par) virtual__emmit(___this, par)
var Aemmitc___V_emmit(var __this, var par);
#define Aemmitc__get_head(___this) virtual__get_head(___this)
var Aemmitc___V_get_head(var __this);
#define Aemmitc__get_data(___this) virtual__get_data(___this)
var Aemmitc___V_get_data(var __this);
#define Aemmitc__get_mid(___this) virtual__get_mid(___this)
var Aemmitc___V_get_mid(var __this);
var Aemmitc__add_to_data(var __this, var s);
var Aemmitc__add_to_head(var __this, var s);
var Aemmitc__gen_class(var __this);
var Aemmitc__gen_debug_context(var __this, var mb);
var Aemmitc__gen_member(var __this, var mb);
var Aemmitc__gen_conditional_call(var __this, var v, var mb);
#define Aemmitc__gen_virtuals(___this) virtual__gen_virtuals(___this)
var Aemmitc___V_gen_virtuals(var __this);
var Aemmitc__gen_virtual_lambda(var __this, var nb);
var Aemmitc__pass_0(var __this, var str, var mb, var k);
var Aemmitc__pass_1(var __this, var str, var mb, var k);
var Aemmitc__pass_2(var __this, var str, var mb, var k);
var Aemmitc__pad(var __this, var depth);
var Aemmitc__find_param(var __this, var stri);
var Aemmitc__find_field(var __this, var stri);
var Aemmitc__find_method(var __this, var stri);
var Aemmitc__find_static(var __this, var stri);
var Aemmitc__find_local(var __this, var stri);
var Aemmitc__expr_call_member(var __this, var expr, var ex1, var ex2, var stri, var obj);
var Aemmitc__expr_call_sub(var __this, var expr, var ex1, var ex2, var stri, var obj, var v, var sta, var fld);
var Aemmitc__expr_gen_call(var __this, var expr);
var Aemmitc__expr_gen_sub_expr(var __this, var expr);
var Aemmitc__expr_gen_comma(var __this, var expr);
var Aemmitc__expr_gen_index(var __this, var expr);
var Aemmitc__expr_gen_par(var __this, var expr);
var Aemmitc__expr_gen_constant(var __this, var expr);
var Aemmitc__expr_gen_dot(var __this, var expr);
var Aemmitc__expr_gen_lambda(var __this, var expr);
var Aemmitc__gen_string(var __this, var s2, var value);
var Aemmitc__number(var __this, var n);
var Aemmitc__new_string(var __this, var l);
var Aemmitc__expr_gen_str_const(var __this, var expr);
var Aemmitc__expr_gen_char_const(var __this, var expr);
var Aemmitc__expr_gen0(var __this, var expr, var op);
var Aemmitc__expr_gen1(var __this, var expr, var op);
var Aemmitc__expr_gen_assign(var __this, var expr, var op);
var Aemmitc__expr_gen2(var __this, var expr, var op);
var Aemmitc__expr_gen_var(var __this, var expr);
#define Aemmitc__expr_process(___this, expr) virtual__expr_process(___this, expr)
var Aemmitc___V_expr_process(var __this, var expr);
var Aemmitc__expr_gen_case(var __this, var expr, var padde);
var Aemmitc__expr_gen(var __this, var expr);
var Aemmitc__fix_datal(var __this);
var Aemmitc__body_gen_constructor(var __this, var mb);
var Aemmitc__set_member(var __this, var m);
var Aemmitc__body_gen(var __this, var mb, var k, var vars_, var body_);
var Aemmitc__gen_type(var __this, var mb);
var Aemmitc__add_virtual(var __this, var mb);
var Aemmitc__gen_virtual_caller(var __this, var mb);
var Aemmitc__gen_method_decl(var __this, var dest, var c_name, var name, var mb, var k);
var Aemmitc__pass_3(var __this, var str, var mb, var k);
var Aemmitc__pass_4(var __this, var str, var mb, var k);
var Aemmitc__error(var __this, var t, var e);
#define Acbody___DsizeD 19
#define Acbody___DcidD 24
var Acbody___new(var __this, var emmiter1, var side1, var class_name1, var debug1, var expr_stk1, var __parent);
var Acbody__new(var emmiter1, var side1, var class_name1, var debug1, var expr_stk1, var __parent);
#define Acbody__dispose(___this) virtual__dispose(___this)
var Acbody___V_dispose(var __this);
var Acbody__add_to_data(var __this, var s);
var Acbody__expr_gen(var __this, var expr);
var Acbody__expr_gen_var(var __this, var expr);
var Acbody__expr_gen_case(var __this, var expr, var padde);
var Acbody__body_gen(var __this, var mb, var k, var vars_, var body1);
var Acbody__gen_debug_rec(var __this, var mb, var k);
var Acbody__transform_ifblock(var __this);
var Acbody__prepare_ifblock(var __this);
var Acbody__gen_if(var __this);
var Acbody__gen_return(var __this);
var Acbody__gen_switch(var __this);
var Acbody__gen_while(var __this);
var Acbody__gen_do(var __this);
var Acbody__gen_let(var __this);
var Acbody__next_statement(var __this);
var Acbody__gen_statements(var __this);
var Acbody__pad(var __this, var padde);
#define Aexpr___DsizeD 10
#define Aexpr___DcidD 25
var Aexpr___new(var __this, var op1, var precedence1, var associativity1, var __parent);
var Aexpr__new(var op1, var precedence1, var associativity1, var __parent);
#define Aexpr__dispose(___this) virtual__dispose(___this)
var Aexpr___V_dispose(var __this);
#define Aexpr__delayed_dispose(___this) virtual__delayed_dispose(___this)
var Aexpr___V_delayed_dispose(var __this);
var Aexpr__clear_data(var __this);
var Aexpr__add_data(var __this, var value);
var Aexpr__get_data(var __this);
var Aexpr__merge_data(var __this, var buf);
var Aexpr__data_to_string(var __this, var s);
var Aexpr__get_origin(var __this);
var Aexpr__set_origin(var __this, var orig);
var Aexpr__get_right(var __this);
var Aexpr__set_right(var __this, var r);
var Aexpr__get_left(var __this);
var Aexpr__set_left(var __this, var l);
var Aexpr__get_parent(var __this);
var Aexpr__set_parent(var __this, var p);
var Aexpr__get_value2(var __this);
var Aexpr__set_value2(var __this, var v);
var Aexpr__get_value(var __this);
var Aexpr__set_value(var __this, var v);
var Aexpr__get_op(var __this);
var Aexpr__get_flags(var __this);
var Aexpr__set_flags(var __this, var flags_);
var Aexpr__set_precedence(var __this, var p);
var Aexpr__get_precedence(var __this);
var Aexpr__get_associativity(var __this);
var Aexpr__close(var __this, var op_);
var Aexpr__add(var __this, var ex);
var Aexpr__dump(var __this, var depth);
var Aexpr__is_equal_comp1(var __this, var v);
var Aexpr__get_case_expr1(var __this);
var Aexpr__get_switch_expr(var __this);
var Aexpr__get_case_expr(var __this, var pos);
var Aexpr__is_equal_comp(var __this, var v);
#define Alexer___DsizeD 24
#define Alexer___DcidD 26
#define Alexer__Cstring 1
#define Alexer__Cquote 2
#define Alexer__Ccomment 3
#define Alexer__Casm 4
#define Alexer__Cnumber 5
#define Alexer__Cidentifier 6
#define Alexer__Coperator 7
#define Alexer__Cerror 8
#define Alexer__Cnewline 9
#define Alexer__Cend 10
var Alexer___new(var __this, var __parent);
var Alexer__new(var __parent);
#define Alexer__dispose(___this) virtual__dispose(___this)
var Alexer___V_dispose(var __this);
var Alexer__begin(var __this, var file_);
var Alexer__get_at(var __this, var x);
var Alexer__shift(var __this);
var Alexer__empty(var __this);
var Alexer__set_enable_escape(var __this, var v);
var Alexer__get_string(var __this, var str_);
var Alexer__get_string_id(var __this, var str_);
var Alexer__add(var __this, var str_);
var Alexer__tokenize(var __this);
var Alexer__is_digit(var __this, var c);
var Alexer__is_letter(var __this, var c);
var Alexer__is_space(var __this, var c);
var Alexer__next(var __this);
var Alexer__validate(var __this, var type_);
var Alexer__error(var __this, var msg);
var Alexer__state(var __this);
var Alexer__finish(var __this);
#define Amember___DsizeD 10
#define Amember___DcidD 27
var Amember___new(var __this, var kind1, var type1, var type_id1, var name1, var __parent);
var Amember__new(var kind1, var type1, var type_id1, var name1, var __parent);
#define Amember__dispose(___this) virtual__dispose(___this)
var Amember___V_dispose(var __this);
var Amember__copy(var __this);
var Amember__pre_copy(var __this, var cp);
var Amember__take(var __this);
var Amember__copy_params(var __this, var o, var cp);
var Amember__dispose_body(var __this);
var Amember__get_kind(var __this);
var Amember__get_type(var __this);
var Amember__get_type_id(var __this);
var Amember__get_name(var __this);
var Amember__get_name_string(var __this);
var Amember__get_initial_value(var __this);
var Amember__set_initial_value(var __this, var initial_value1);
var Amember__set_index(var __this, var index1);
var Amember__get_index(var __this);
var Amember__get_body(var __this);
var Amember__get_vars(var __this);
var Amember__get_params(var __this);
var Amember__add_param(var __this, var kind1, var type1, var type_id1, var name1);
var Amember__add_var(var __this, var kind1, var type1, var type_id1, var name1);
var Amember__add_statement(var __this, var statement1);
#define Aparser___DsizeD 7
#define Aparser___DcidD 28
#define Aparser__Croot 1
#define Aparser__Cclass_dec 2
#define Aparser__Cstatement 3
#define Aparser__Cstatements 4
#define Aparser__Cexpression 5
#define Aparser__Creturn_statem1 6
#define Aparser__Cexpression1 7
#define Aparser__Cterm 8
#define Aparser__Cterm1 9
#define Aparser__Cterm2 10
#define Aparser__Cexpr_list 11
#define Aparser__Cexpr_list1 12
#define Aparser__Csub_call1 13
#define Aparser__Clet_statem1 14
#define Aparser__Clet_statem2 15
#define Aparser__Cdo_statem1 16
#define Aparser__Cwhile_statem1 17
#define Aparser__Cwhile_statem2 18
#define Aparser__Csubrout_body1 19
#define Aparser__Csubroutine_dec 20
#define Aparser__Cclass_dec1 21
#define Aparser__Cif_statem1 22
#define Aparser__Cif_statem2 23
#define Aparser__Celse_statem 24
#define Aparser__Celse_statem1 25
#define Aparser__Celse_statem2 26
#define Aparser__Clambda_body1 27
var Aparser___new(var __this, var __parent);
var Aparser__new(var __parent);
#define Aparser__dispose(___this) virtual__dispose(___this)
var Aparser___V_dispose(var __this);
var Aparser__get_data(var __this);
var Aparser__get_next(var __this);
var Aparser__release(var __this);
var Aparser__parse(var __this, var lexer_);
var Aparser__error(var __this, var e);
var Aparser__push(var __this, var step_);
var Aparser__pop(var __this);
var Aparser__root(var __this);
var Aparser__class_dec(var __this);
var Aparser__class_dec1(var __this);
var Aparser__class_var_dec(var __this);
var Aparser__var_name(var __this);
var Aparser__type(var __this);
var Aparser__clas_const_dec(var __this);
var Aparser__subroutine_dec(var __this);
var Aparser__param_list(var __this);
var Aparser__direction(var __this);
var Aparser__lambda_body(var __this);
var Aparser__lambda_body1(var __this);
var Aparser__subrout_body(var __this);
var Aparser__subrout_body1(var __this);
var Aparser__var_dec(var __this);
var Aparser__statements(var __this);
var Aparser__statement(var __this);
var Aparser__if_statem(var __this, var type_);
var Aparser__if_statem1(var __this);
var Aparser__else_statem(var __this);
var Aparser__else_statem1(var __this);
var Aparser__while_statem(var __this);
var Aparser__while_statem1(var __this);
var Aparser__while_statem2(var __this);
var Aparser__return_statem(var __this);
var Aparser__return_statem1(var __this);
var Aparser__dolet_statem(var __this);
var Aparser__let_statem(var __this, var id);
var Aparser__let_statem1(var __this);
var Aparser__let_statem2(var __this);
var Aparser__do_statem(var __this, var id);
var Aparser__do_statem1(var __this);
var Aparser__expression(var __this);
var Aparser__expression1(var __this);
var Aparser__op(var __this);
var Aparser__term(var __this);
var Aparser__subrout_call(var __this, var id);
var Aparser__term1(var __this);
var Aparser__term2(var __this);
var Aparser__sub_call(var __this, var class_, var id);
var Aparser__sub_call1(var __this);
var Aparser__expr_list(var __this);
var Aparser__expr_list1(var __this);
var Aparser__eat(var __this);
var Aparser__match_id(var __this, var id);
var Aparser__match_op(var __this, var id);
var Aparser__match_newline(var __this);
var Aparser__match_str(var __this, var id);
var Aparser__state_machine(var __this);
#define Astatement___DsizeD 6
#define Astatement___DcidD 29
var Astatement___new(var __this, var type1, var parent1, var depth1, var __parent);
var Astatement__new(var type1, var parent1, var depth1, var __parent);
#define Astatement__dispose(___this) virtual__dispose(___this)
var Astatement___V_dispose(var __this);
var Astatement__get_type(var __this);
var Astatement__set_type(var __this, var type1);
var Astatement__get_depth(var __this);
var Astatement__get_parent(var __this);
var Astatement__get_statements(var __this);
var Astatement__get_else(var __this);
var Astatement__get_expression(var __this);
var Astatement__add_else(var __this, var type1);
var Astatement__add_statement(var __this, var statement1);
var Astatement__set_expression(var __this, var expr1);
#define Atoken___DsizeD 4
#define Atoken___DcidD 30
var Atoken___new(var __this, var type1, var data1, var line1, var file1, var __parent);
var Atoken__new(var type1, var data1, var line1, var file1, var __parent);
#define Atoken__dispose(___this) virtual__dispose(___this)
var Atoken___V_dispose(var __this);
var Atoken__copy(var __this);
var Atoken__take(var __this);
var Atoken__get(var __this);
var Atoken__get_data(var __this);
var Atoken__get_type(var __this);
var Atoken__get_line(var __this);
var Atoken__get_file(var __this);
#define Avirtual___DsizeD 3
#define Avirtual___DcidD 31
var Avirtual___new(var __this, var memb1, var class1, var __parent);
var Avirtual__new(var memb1, var class1, var __parent);
#define Avirtual__dispose(___this) virtual__dispose(___this)
var Avirtual___V_dispose(var __this);
#define Avirtual__delayed_dispose(___this) virtual__delayed_dispose(___this)
var Avirtual___V_delayed_dispose(var __this);
var Avirtual__set_next(var __this, var n);
var Avirtual__get_next(var __this);
var Avirtual__get_class_name(var __this);
var Avirtual__get_member(var __this);
var Avirtual__get_member_name(var __this);
#define main___DsizeD 21
#define main___DcidD 32
#define main__Cblock 4096
#define main__Chello (var)(__string_mainChello+2)
#define main__Cc 0
#define main__Cjs 1
#define main__Cphp 2
var main__copy_block(var __this);
var main__0(var __this, var status, var data, var type);
var main__copyto(var __this, var f, var output, var cb, var this_cb);
var main__process_file_end(var __this, var stat);
var main__process_file_block(var __this, var n, var d);
var main__1(var __this, var status, var data, var type);
var main__process_file(var __this, var f, var cb, var this_cb);
var main__2(var __this, var status, var data, var type);
var main___new(var __this, var __parent);
var main__new(var __parent);
#define main__dispose(___this) virtual__dispose(___this)
var main___V_dispose(var __this);
var main__main();
var main__run(var __this);
var main__next_file(var __this);
var main__3(var __this, var status, var data, var type);
var main__4(var __this, var status, var data, var type);
var main__5(var __this, var status, var data, var type);
var main__finish(var __this);
var main__6(var __this, var status, var data, var type);
var main__finish1(var __this);
var main__7(var __this, var status, var data, var type);
#define main__lambda(a,b,c,d,e) std__lambda(a,b,c,d,e)
var main___V_lambda(var __this, var fcn, var status, var data, var type);
var virtual__expr_process(var __this, var expr);
var virtual__gen_virtuals(var __this);
var virtual__get_mid(var __this);
var virtual__get_data(var __this);
var virtual__get_head(var __this);
var virtual__emmit(var __this, var par);
var virtual__delayed_dispose(var __this);
var virtual__dispose(var __this);
static char __strings_array1[]="Size less than one";
static var __string_array1[]={0,-2, 0,-1};
static char __strings_string2[]="";
static var __string_string2[]={0,-2, 0,-1};
static char __strings_Aclass3[]="\t";
static var __string_Aclass3[]={0,-2, 0,-1};
static char __strings_Aclass4[]="Unknown operator.";
static var __string_Aclass4[]={0,-2, 0,-1};
static char __strings_Aclass5[]="What a mess in parenthesis..";
static var __string_Aclass5[]={0,-2, 0,-1};
static char __strings_Aclass6[]="What a mess in index..";
static var __string_Aclass6[]={0,-2, 0,-1};
static char __strings_Aclass7[]="What a mess..";
static var __string_Aclass7[]={0,-2, 0,-1};
static char __strings_Aemmiter8[]=": at line (";
static var __string_Aemmiter8[]={0,-2, 0,-1};
static char __strings_Aemmiter9[]=") '";
static var __string_Aemmiter9[]={0,-2, 0,-1};
static char __strings_Aemmiter10[]="' ";
static var __string_Aemmiter10[]={0,-2, 0,-1};
static char __strings_Aemmitc11[]="static void std__init_strings()\n{\n";
static var __string_Aemmitc11[]={0,-2, 0,-1};
static char __strings_Aemmitc12[]="}\n";
static var __string_Aemmitc12[]={0,-2, 0,-1};
static char __strings_Aemmitc13[]="/* class ";
static var __string_Aemmitc13[]={0,-2, 0,-1};
static char __strings_Aemmitc14[]=" */\n";
static var __string_Aemmitc14[]={0,-2, 0,-1};
static char __strings_Aemmitc15[]="#define ";
static var __string_Aemmitc15[]={0,-2, 0,-1};
static char __strings_Aemmitc16[]="___DsizeD ";
static var __string_Aemmitc16[]={0,-2, 0,-1};
static char __strings_Aemmitc17[]="\n";
static var __string_Aemmitc17[]={0,-2, 0,-1};
static char __strings_Aemmitc18[]="#define ";
static var __string_Aemmitc18[]={0,-2, 0,-1};
static char __strings_Aemmitc19[]="___DcidD ";
static var __string_Aemmitc19[]={0,-2, 0,-1};
static char __strings_Aemmitc20[]="\n";
static var __string_Aemmitc20[]={0,-2, 0,-1};
static char __strings_Aemmitc21[]="\tcase ";
static var __string_Aemmitc21[]={0,-2, 0,-1};
static char __strings_Aemmitc22[]="___DcidD:\n\t\treturn ";
static var __string_Aemmitc22[]={0,-2, 0,-1};
static char __strings_Aemmitc23[]="___V_";
static var __string_Aemmitc23[]={0,-2, 0,-1};
static char __strings_Aemmitc24[]="(__this";
static var __string_Aemmitc24[]={0,-2, 0,-1};
static char __strings_Aemmitc25[]=", ";
static var __string_Aemmitc25[]={0,-2, 0,-1};
static char __strings_Aemmitc26[]=");\n";
static var __string_Aemmitc26[]={0,-2, 0,-1};
static char __strings_Aemmitc27[]="virtual";
static var __string_Aemmitc27[]={0,-2, 0,-1};
static char __strings_Aemmitc28[]=";\n";
static var __string_Aemmitc28[]={0,-2, 0,-1};
static char __strings_Aemmitc29[]="virtual";
static var __string_Aemmitc29[]={0,-2, 0,-1};
static char __strings_Aemmitc30[]="\n{\n\tvar cid;\n";
static var __string_Aemmitc30[]={0,-2, 0,-1};
static char __strings_Aemmitc31[]="\tcid = ((var*)__this)[-1];\n";
static var __string_Aemmitc31[]={0,-2, 0,-1};
static char __strings_Aemmitc32[]="\tswitch (cid) {\n";
static var __string_Aemmitc32[]={0,-2, 0,-1};
static char __strings_Aemmitc33[]="\tdefault:\n\t\tbreak;\n\t}\n";
static var __string_Aemmitc33[]={0,-2, 0,-1};
static char __strings_Aemmitc34[]="\treturn 0;\n}\n";
static var __string_Aemmitc34[]={0,-2, 0,-1};
static char __strings_Aemmitc35[]="var std__lambda(var __this, var fcn, ";
static var __string_Aemmitc35[]={0,-2, 0,-1};
static char __strings_Aemmitc36[]="var status, var data, var type)";
static var __string_Aemmitc36[]={0,-2, 0,-1};
static char __strings_Aemmitc37[]="\n{\n\tvar cid;\n";
static var __string_Aemmitc37[]={0,-2, 0,-1};
static char __strings_Aemmitc38[]="\tcid = ((var*)__this)[-1];\n";
static var __string_Aemmitc38[]={0,-2, 0,-1};
static char __strings_Aemmitc39[]="\tswitch (cid) {\n";
static var __string_Aemmitc39[]={0,-2, 0,-1};
static char __strings_Aemmitc40[]="\tcase ";
static var __string_Aemmitc40[]={0,-2, 0,-1};
static char __strings_Aemmitc41[]="___DcidD:\n\t\treturn ";
static var __string_Aemmitc41[]={0,-2, 0,-1};
static char __strings_Aemmitc42[]="___V_lambda(__this, fcn, status, data, type);\n";
static var __string_Aemmitc42[]={0,-2, 0,-1};
static char __strings_Aemmitc43[]="\t}\n\treturn 0;\n}\n";
static var __string_Aemmitc43[]={0,-2, 0,-1};
static char __strings_Aemmitc44[]="#define ";
static var __string_Aemmitc44[]={0,-2, 0,-1};
static char __strings_Aemmitc45[]="__lambda(a,b,c,d,e) std__lambda(a,b,c,d,e)\n";
static var __string_Aemmitc45[]={0,-2, 0,-1};
static char __strings_Aemmitc46[]="var ";
static var __string_Aemmitc46[]={0,-2, 0,-1};
static char __strings_Aemmitc47[]="___V_lambda(var __this, var fcn, ";
static var __string_Aemmitc47[]={0,-2, 0,-1};
static char __strings_Aemmitc48[]="var status, var data, var type);\n";
static var __string_Aemmitc48[]={0,-2, 0,-1};
static char __strings_Aemmitc49[]="var ";
static var __string_Aemmitc49[]={0,-2, 0,-1};
static char __strings_Aemmitc50[]="___V_lambda(var __this, var fcn, ";
static var __string_Aemmitc50[]={0,-2, 0,-1};
static char __strings_Aemmitc51[]="var status, var data, var type)\n{";
static var __string_Aemmitc51[]={0,-2, 0,-1};
static char __strings_Aemmitc52[]="\tswitch(fcn) {\n";
static var __string_Aemmitc52[]={0,-2, 0,-1};
static char __strings_Aemmitc53[]="\tcase ";
static var __string_Aemmitc53[]={0,-2, 0,-1};
static char __strings_Aemmitc54[]=":\n\t\treturn ";
static var __string_Aemmitc54[]={0,-2, 0,-1};
static char __strings_Aemmitc55[]="__";
static var __string_Aemmitc55[]={0,-2, 0,-1};
static char __strings_Aemmitc56[]="(__this, status, data, type);\n";
static var __string_Aemmitc56[]={0,-2, 0,-1};
static char __strings_Aemmitc57[]="\t}\n\treturn 0;\n}\n";
static var __string_Aemmitc57[]={0,-2, 0,-1};
static char __strings_Aemmitc58[]="#define ";
static var __string_Aemmitc58[]={0,-2, 0,-1};
static char __strings_Aemmitc59[]="__";
static var __string_Aemmitc59[]={0,-2, 0,-1};
static char __strings_Aemmitc60[]=" ";
static var __string_Aemmitc60[]={0,-2, 0,-1};
static char __strings_Aemmitc61[]="(var)(__string_";
static var __string_Aemmitc61[]={0,-2, 0,-1};
static char __strings_Aemmitc62[]="+2)";
static var __string_Aemmitc62[]={0,-2, 0,-1};
static char __strings_Aemmitc63[]="'";
static var __string_Aemmitc63[]={0,-2, 0,-1};
static char __strings_Aemmitc64[]="'";
static var __string_Aemmitc64[]={0,-2, 0,-1};
static char __strings_Aemmitc65[]="\n";
static var __string_Aemmitc65[]={0,-2, 0,-1};
static char __strings_Aemmitc66[]="struct ";
static var __string_Aemmitc66[]={0,-2, 0,-1};
static char __strings_Aemmitc67[]=" {\n";
static var __string_Aemmitc67[]={0,-2, 0,-1};
static char __strings_Aemmitc68[]="\tvar ";
static var __string_Aemmitc68[]={0,-2, 0,-1};
static char __strings_Aemmitc69[]=";\n";
static var __string_Aemmitc69[]={0,-2, 0,-1};
static char __strings_Aemmitc70[]="};\n";
static var __string_Aemmitc70[]={0,-2, 0,-1};
static char __strings_Aemmitc71[]="static var ";
static var __string_Aemmitc71[]={0,-2, 0,-1};
static char __strings_Aemmitc72[]="__";
static var __string_Aemmitc72[]={0,-2, 0,-1};
static char __strings_Aemmitc73[]=" = 0;\n";
static var __string_Aemmitc73[]={0,-2, 0,-1};
static char __strings_Aemmitc74[]="\t";
static var __string_Aemmitc74[]={0,-2, 0,-1};
static char __strings_Aemmitc75[]="__";
static var __string_Aemmitc75[]={0,-2, 0,-1};
static char __strings_Aemmitc76[]="(__this, ";
static var __string_Aemmitc76[]={0,-2, 0,-1};
static char __strings_Aemmitc77[]=")";
static var __string_Aemmitc77[]={0,-2, 0,-1};
static char __strings_Aemmitc78[]="(__this)";
static var __string_Aemmitc78[]={0,-2, 0,-1};
static char __strings_Aemmitc79[]="cannot find method...";
static var __string_Aemmitc79[]={0,-2, 0,-1};
static char __strings_Aemmitc80[]="wrong type of method.";
static var __string_Aemmitc80[]={0,-2, 0,-1};
static char __strings_Aemmitc81[]="__";
static var __string_Aemmitc81[]={0,-2, 0,-1};
static char __strings_Aemmitc82[]="(";
static var __string_Aemmitc82[]={0,-2, 0,-1};
static char __strings_Aemmitc83[]="_this->";
static var __string_Aemmitc83[]={0,-2, 0,-1};
static char __strings_Aemmitc84[]="__";
static var __string_Aemmitc84[]={0,-2, 0,-1};
static char __strings_Aemmitc85[]=",";
static var __string_Aemmitc85[]={0,-2, 0,-1};
static char __strings_Aemmitc86[]="new";
static var __string_Aemmitc86[]={0,-2, 0,-1};
static char __strings_Aemmitc87[]=",__this";
static var __string_Aemmitc87[]={0,-2, 0,-1};
static char __strings_Aemmitc88[]=")";
static var __string_Aemmitc88[]={0,-2, 0,-1};
static char __strings_Aemmitc89[]="__";
static var __string_Aemmitc89[]={0,-2, 0,-1};
static char __strings_Aemmitc90[]="(";
static var __string_Aemmitc90[]={0,-2, 0,-1};
static char __strings_Aemmitc91[]="new";
static var __string_Aemmitc91[]={0,-2, 0,-1};
static char __strings_Aemmitc92[]=",__this";
static var __string_Aemmitc92[]={0,-2, 0,-1};
static char __strings_Aemmitc93[]="__this";
static var __string_Aemmitc93[]={0,-2, 0,-1};
static char __strings_Aemmitc94[]=")";
static var __string_Aemmitc94[]={0,-2, 0,-1};
static char __strings_Aemmitc95[]="";
static var __string_Aemmitc95[]={0,-2, 0,-1};
static char __strings_Aemmitc96[]=",";
static var __string_Aemmitc96[]={0,-2, 0,-1};
static char __strings_Aemmitc97[]="((var*)";
static var __string_Aemmitc97[]={0,-2, 0,-1};
static char __strings_Aemmitc98[]=")[";
static var __string_Aemmitc98[]={0,-2, 0,-1};
static char __strings_Aemmitc99[]="]";
static var __string_Aemmitc99[]={0,-2, 0,-1};
static char __strings_Aemmitc100[]="(";
static var __string_Aemmitc100[]={0,-2, 0,-1};
static char __strings_Aemmitc101[]=")";
static var __string_Aemmitc101[]={0,-2, 0,-1};
static char __strings_Aemmitc102[]="__";
static var __string_Aemmitc102[]={0,-2, 0,-1};
static char __strings_Aemmitc103[]=",__this";
static var __string_Aemmitc103[]={0,-2, 0,-1};
static char __strings_Aemmitc104[]="static char __strings_";
static var __string_Aemmitc104[]={0,-2, 0,-1};
static char __strings_Aemmitc105[]="[]=";
static var __string_Aemmitc105[]={0,-2, 0,-1};
static char __strings_Aemmitc106[]="\"";
static var __string_Aemmitc106[]={0,-2, 0,-1};
static char __strings_Aemmitc107[]="\"";
static var __string_Aemmitc107[]={0,-2, 0,-1};
static char __strings_Aemmitc108[]=";\n";
static var __string_Aemmitc108[]={0,-2, 0,-1};
static char __strings_Aemmitc109[]="static var __string_";
static var __string_Aemmitc109[]={0,-2, 0,-1};
static char __strings_Aemmitc110[]="[]={0,-2, ";
static var __string_Aemmitc110[]={0,-2, 0,-1};
static char __strings_Aemmitc111[]="0,-1};\n";
static var __string_Aemmitc111[]={0,-2, 0,-1};
static char __strings_Aemmitc112[]="\t__string_";
static var __string_Aemmitc112[]={0,-2, 0,-1};
static char __strings_Aemmitc113[]="[2]=";
static var __string_Aemmitc113[]={0,-2, 0,-1};
static char __strings_Aemmitc114[]="(var) __strings_";
static var __string_Aemmitc114[]={0,-2, 0,-1};
static char __strings_Aemmitc115[]=";\n";
static var __string_Aemmitc115[]={0,-2, 0,-1};
static char __strings_Aemmitc116[]="(var)(__string_";
static var __string_Aemmitc116[]={0,-2, 0,-1};
static char __strings_Aemmitc117[]="+ 2)";
static var __string_Aemmitc117[]={0,-2, 0,-1};
static char __strings_Aemmitc118[]="'";
static var __string_Aemmitc118[]={0,-2, 0,-1};
static char __strings_Aemmitc119[]="\\0";
static var __string_Aemmitc119[]={0,-2, 0,-1};
static char __strings_Aemmitc120[]="'";
static var __string_Aemmitc120[]={0,-2, 0,-1};
static char __strings_Aemmitc121[]="(";
static var __string_Aemmitc121[]={0,-2, 0,-1};
static char __strings_Aemmitc122[]=")";
static var __string_Aemmitc122[]={0,-2, 0,-1};
static char __strings_Aemmitc123[]="(";
static var __string_Aemmitc123[]={0,-2, 0,-1};
static char __strings_Aemmitc124[]=")";
static var __string_Aemmitc124[]={0,-2, 0,-1};
static char __strings_Aemmitc125[]="(";
static var __string_Aemmitc125[]={0,-2, 0,-1};
static char __strings_Aemmitc126[]=")";
static var __string_Aemmitc126[]={0,-2, 0,-1};
static char __strings_Aemmitc127[]="_this->";
static var __string_Aemmitc127[]={0,-2, 0,-1};
static char __strings_Aemmitc128[]="__";
static var __string_Aemmitc128[]={0,-2, 0,-1};
static char __strings_Aemmitc129[]="0";
static var __string_Aemmitc129[]={0,-2, 0,-1};
static char __strings_Aemmitc130[]="__this";
static var __string_Aemmitc130[]={0,-2, 0,-1};
static char __strings_Aemmitc131[]="wrong expression...";
static var __string_Aemmitc131[]={0,-2, 0,-1};
static char __strings_Aemmitc132[]="=";
static var __string_Aemmitc132[]={0,-2, 0,-1};
static char __strings_Aemmitc133[]="==";
static var __string_Aemmitc133[]={0,-2, 0,-1};
static char __strings_Aemmitc134[]="!=";
static var __string_Aemmitc134[]={0,-2, 0,-1};
static char __strings_Aemmitc135[]=">=";
static var __string_Aemmitc135[]={0,-2, 0,-1};
static char __strings_Aemmitc136[]="<=";
static var __string_Aemmitc136[]={0,-2, 0,-1};
static char __strings_Aemmitc137[]=">";
static var __string_Aemmitc137[]={0,-2, 0,-1};
static char __strings_Aemmitc138[]="<";
static var __string_Aemmitc138[]={0,-2, 0,-1};
static char __strings_Aemmitc139[]="&&";
static var __string_Aemmitc139[]={0,-2, 0,-1};
static char __strings_Aemmitc140[]="||";
static var __string_Aemmitc140[]={0,-2, 0,-1};
static char __strings_Aemmitc141[]="+";
static var __string_Aemmitc141[]={0,-2, 0,-1};
static char __strings_Aemmitc142[]="-";
static var __string_Aemmitc142[]={0,-2, 0,-1};
static char __strings_Aemmitc143[]="*";
static var __string_Aemmitc143[]={0,-2, 0,-1};
static char __strings_Aemmitc144[]="/";
static var __string_Aemmitc144[]={0,-2, 0,-1};
static char __strings_Aemmitc145[]="%";
static var __string_Aemmitc145[]={0,-2, 0,-1};
static char __strings_Aemmitc146[]="!";
static var __string_Aemmitc146[]={0,-2, 0,-1};
static char __strings_Aemmitc147[]="+";
static var __string_Aemmitc147[]={0,-2, 0,-1};
static char __strings_Aemmitc148[]="-";
static var __string_Aemmitc148[]={0,-2, 0,-1};
static char __strings_Aemmitc149[]="UNKNOW OP\n";
static var __string_Aemmitc149[]={0,-2, 0,-1};
static char __strings_Aemmitc150[]="Invalid case constant";
static var __string_Aemmitc150[]={0,-2, 0,-1};
static char __strings_Aemmitc151[]="\n";
static var __string_Aemmitc151[]={0,-2, 0,-1};
static char __strings_Aemmitc152[]="case ";
static var __string_Aemmitc152[]={0,-2, 0,-1};
static char __strings_Aemmitc153[]=": ";
static var __string_Aemmitc153[]={0,-2, 0,-1};
static char __strings_Aemmitc154[]="{\n\tNEW(";
static var __string_Aemmitc154[]={0,-2, 0,-1};
static char __strings_Aemmitc155[]=");\n\treturn ";
static var __string_Aemmitc155[]={0,-2, 0,-1};
static char __strings_Aemmitc156[]="___";
static var __string_Aemmitc156[]={0,-2, 0,-1};
static char __strings_Aemmitc157[]="(__this";
static var __string_Aemmitc157[]={0,-2, 0,-1};
static char __strings_Aemmitc158[]=", ";
static var __string_Aemmitc158[]={0,-2, 0,-1};
static char __strings_Aemmitc159[]=", __parent);\n}\n";
static var __string_Aemmitc159[]={0,-2, 0,-1};
static char __strings_Aemmitc160[]="var";
static var __string_Aemmitc160[]={0,-2, 0,-1};
static char __strings_Aemmitc161[]="void";
static var __string_Aemmitc161[]={0,-2, 0,-1};
static char __strings_Aemmitc162[]="unknown type";
static var __string_Aemmitc162[]={0,-2, 0,-1};
static char __strings_Aemmitc163[]="#define ";
static var __string_Aemmitc163[]={0,-2, 0,-1};
static char __strings_Aemmitc164[]="__";
static var __string_Aemmitc164[]={0,-2, 0,-1};
static char __strings_Aemmitc165[]="(___this";
static var __string_Aemmitc165[]={0,-2, 0,-1};
static char __strings_Aemmitc166[]=", ";
static var __string_Aemmitc166[]={0,-2, 0,-1};
static char __strings_Aemmitc167[]=") virtual__";
static var __string_Aemmitc167[]={0,-2, 0,-1};
static char __strings_Aemmitc168[]="(___this";
static var __string_Aemmitc168[]={0,-2, 0,-1};
static char __strings_Aemmitc169[]=", ";
static var __string_Aemmitc169[]={0,-2, 0,-1};
static char __strings_Aemmitc170[]=")\n";
static var __string_Aemmitc170[]={0,-2, 0,-1};
static char __strings_Aemmitc171[]="var ";
static var __string_Aemmitc171[]={0,-2, 0,-1};
static char __strings_Aemmitc172[]="__";
static var __string_Aemmitc172[]={0,-2, 0,-1};
static char __strings_Aemmitc173[]="_";
static var __string_Aemmitc173[]={0,-2, 0,-1};
static char __strings_Aemmitc174[]="(";
static var __string_Aemmitc174[]={0,-2, 0,-1};
static char __strings_Aemmitc175[]="var __this";
static var __string_Aemmitc175[]={0,-2, 0,-1};
static char __strings_Aemmitc176[]=", ";
static var __string_Aemmitc176[]={0,-2, 0,-1};
static char __strings_Aemmitc177[]="var ";
static var __string_Aemmitc177[]={0,-2, 0,-1};
static char __strings_Aemmitc178[]=", var this_";
static var __string_Aemmitc178[]={0,-2, 0,-1};
static char __strings_Aemmitc179[]="var ";
static var __string_Aemmitc179[]={0,-2, 0,-1};
static char __strings_Aemmitc180[]=", var __parent";
static var __string_Aemmitc180[]={0,-2, 0,-1};
static char __strings_Aemmitc181[]="var __parent";
static var __string_Aemmitc181[]={0,-2, 0,-1};
static char __strings_Aemmitc182[]=", var __parent";
static var __string_Aemmitc182[]={0,-2, 0,-1};
static char __strings_Aemmitc183[]=", var status, var data, var type";
static var __string_Aemmitc183[]={0,-2, 0,-1};
static char __strings_Aemmitc184[]=")";
static var __string_Aemmitc184[]={0,-2, 0,-1};
static char __strings_Aemmitc185[]="_V_";
static var __string_Aemmitc185[]={0,-2, 0,-1};
static char __strings_Aemmitc186[]=";\n";
static var __string_Aemmitc186[]={0,-2, 0,-1};
static char __strings_Aemmitc187[]="\n";
static var __string_Aemmitc187[]={0,-2, 0,-1};
static char __strings_Aemmitc188[]=";\n";
static var __string_Aemmitc188[]={0,-2, 0,-1};
static char __strings_Aemmitc189[]=";\n";
static var __string_Aemmitc189[]={0,-2, 0,-1};
static char __strings_Aemmitc190[]="\n";
static var __string_Aemmitc190[]={0,-2, 0,-1};
static char __strings_Aemmitc191[]="\n";
static var __string_Aemmitc191[]={0,-2, 0,-1};
static char __strings_Acbody192[]="{\n";
static var __string_Acbody192[]={0,-2, 0,-1};
static char __strings_Acbody193[]="\tstatic var recursive = 0;\n";
static var __string_Acbody193[]={0,-2, 0,-1};
static char __strings_Acbody194[]="\tvar __return__ = 0;\n";
static var __string_Acbody194[]={0,-2, 0,-1};
static char __strings_Acbody195[]="\tvar ";
static var __string_Acbody195[]={0,-2, 0,-1};
static char __strings_Acbody196[]=";\n";
static var __string_Acbody196[]={0,-2, 0,-1};
static char __strings_Acbody197[]="\tMAKETHIS(";
static var __string_Acbody197[]={0,-2, 0,-1};
static char __strings_Acbody198[]=");\n";
static var __string_Acbody198[]={0,-2, 0,-1};
static char __strings_Acbody199[]="\tFAKETHIS();\n";
static var __string_Acbody199[]={0,-2, 0,-1};
static char __strings_Acbody200[]="\tif (((var*)__this)[-1]!=";
static var __string_Acbody200[]={0,-2, 0,-1};
static char __strings_Acbody201[]="___DcidD";
static var __string_Acbody201[]={0,-2, 0,-1};
static char __strings_Acbody202[]="string";
static var __string_Acbody202[]={0,-2, 0,-1};
static char __strings_Acbody203[]="get_buf";
static var __string_Acbody203[]={0,-2, 0,-1};
static char __strings_Acbody204[]="to_string";
static var __string_Acbody204[]={0,-2, 0,-1};
static char __strings_Acbody205[]="length";
static var __string_Acbody205[]={0,-2, 0,-1};
static char __strings_Acbody206[]="&& ((var*)__this)[-1]!=-2";
static var __string_Acbody206[]={0,-2, 0,-1};
static char __strings_Acbody207[]="&& ((var*)__this)[-1]!=0";
static var __string_Acbody207[]={0,-2, 0,-1};
static char __strings_Acbody208[]="){\n\t\tprintf(\"CID: %ld \", ((var*)__this)[-1]);\n";
static var __string_Acbody208[]={0,-2, 0,-1};
static char __strings_Acbody209[]="\t\tstd__panic();\n\t}\n";
static var __string_Acbody209[]={0,-2, 0,-1};
static char __strings_Acbody210[]="\trecursive++;\n";
static var __string_Acbody210[]={0,-2, 0,-1};
static char __strings_Acbody211[]="\tif (recursive != 1) {\n";
static var __string_Acbody211[]={0,-2, 0,-1};
static char __strings_Acbody212[]="\t\tfprintf(stderr, \"recursive call in \\\"";
static var __string_Acbody212[]={0,-2, 0,-1};
static char __strings_Acbody213[]=".";
static var __string_Acbody213[]={0,-2, 0,-1};
static char __strings_Acbody214[]="\\\"\\n\");std__panic();\n\t}";
static var __string_Acbody214[]={0,-2, 0,-1};
static char __strings_Acbody215[]=" else if (";
static var __string_Acbody215[]={0,-2, 0,-1};
static char __strings_Acbody216[]="if (";
static var __string_Acbody216[]={0,-2, 0,-1};
static char __strings_Acbody217[]=") {";
static var __string_Acbody217[]={0,-2, 0,-1};
static char __strings_Acbody218[]="}";
static var __string_Acbody218[]={0,-2, 0,-1};
static char __strings_Acbody219[]="}";
static var __string_Acbody219[]={0,-2, 0,-1};
static char __strings_Acbody220[]="__return__ = ";
static var __string_Acbody220[]={0,-2, 0,-1};
static char __strings_Acbody221[]=";\n\trecursive--;\n\t";
static var __string_Acbody221[]={0,-2, 0,-1};
static char __strings_Acbody222[]="return __return__;";
static var __string_Acbody222[]={0,-2, 0,-1};
static char __strings_Acbody223[]="return ";
static var __string_Acbody223[]={0,-2, 0,-1};
static char __strings_Acbody224[]=";";
static var __string_Acbody224[]={0,-2, 0,-1};
static char __strings_Acbody225[]="recursive--;\n\t";
static var __string_Acbody225[]={0,-2, 0,-1};
static char __strings_Acbody226[]="return __return__;";
static var __string_Acbody226[]={0,-2, 0,-1};
static char __strings_Acbody227[]="return 0;";
static var __string_Acbody227[]={0,-2, 0,-1};
static char __strings_Acbody228[]="switch (";
static var __string_Acbody228[]={0,-2, 0,-1};
static char __strings_Acbody229[]=") {\n";
static var __string_Acbody229[]={0,-2, 0,-1};
static char __strings_Acbody230[]="while (";
static var __string_Acbody230[]={0,-2, 0,-1};
static char __strings_Acbody231[]=") {";
static var __string_Acbody231[]={0,-2, 0,-1};
static char __strings_Acbody232[]="}";
static var __string_Acbody232[]={0,-2, 0,-1};
static char __strings_Acbody233[]=";";
static var __string_Acbody233[]={0,-2, 0,-1};
static char __strings_Acbody234[]=";";
static var __string_Acbody234[]={0,-2, 0,-1};
static char __strings_Acbody235[]="\n";
static var __string_Acbody235[]={0,-2, 0,-1};
static char __strings_Acbody236[]="\n";
static var __string_Acbody236[]={0,-2, 0,-1};
static char __strings_Acbody237[]="} ";
static var __string_Acbody237[]={0,-2, 0,-1};
static char __strings_Acbody238[]="\tbreak;";
static var __string_Acbody238[]={0,-2, 0,-1};
static char __strings_Acbody239[]="}";
static var __string_Acbody239[]={0,-2, 0,-1};
static char __strings_Acbody240[]="\n";
static var __string_Acbody240[]={0,-2, 0,-1};
static char __strings_Acbody241[]=" else {";
static var __string_Acbody241[]={0,-2, 0,-1};
static char __strings_Acbody242[]="default:";
static var __string_Acbody242[]={0,-2, 0,-1};
static char __strings_Acbody243[]="break;";
static var __string_Acbody243[]={0,-2, 0,-1};
static char __strings_Acbody244[]="ERROR !!";
static var __string_Acbody244[]={0,-2, 0,-1};
static char __strings_Acbody245[]="\n";
static var __string_Acbody245[]={0,-2, 0,-1};
static char __strings_Aexpr246[]=" ";
static var __string_Aexpr246[]={0,-2, 0,-1};
static char __strings_Aexpr247[]=" ";
static var __string_Aexpr247[]={0,-2, 0,-1};
static char __strings_Aexpr248[]="";
static var __string_Aexpr248[]={0,-2, 0,-1};
static char __strings_Alexer249[]="Lexer: ";
static var __string_Alexer249[]={0,-2, 0,-1};
static char __strings_Alexer250[]=" @ (";
static var __string_Alexer250[]={0,-2, 0,-1};
static char __strings_Alexer251[]=") : '";
static var __string_Alexer251[]={0,-2, 0,-1};
static char __strings_Alexer252[]="' ";
static var __string_Alexer252[]={0,-2, 0,-1};
static char __strings_Alexer253[]="newline in string.";
static var __string_Alexer253[]={0,-2, 0,-1};
static char __strings_Alexer254[]="unterminated token.";
static var __string_Alexer254[]={0,-2, 0,-1};
static char __strings_Aparser255[]=": found '";
static var __string_Aparser255[]={0,-2, 0,-1};
static char __strings_Aparser256[]="' at line(";
static var __string_Aparser256[]={0,-2, 0,-1};
static char __strings_Aparser257[]="): ";
static var __string_Aparser257[]={0,-2, 0,-1};
static char __strings_Aparser258[]="class";
static var __string_Aparser258[]={0,-2, 0,-1};
static char __strings_Aparser259[]="expecting 'class' keyword";
static var __string_Aparser259[]={0,-2, 0,-1};
static char __strings_Aparser260[]="expecting identifier";
static var __string_Aparser260[]={0,-2, 0,-1};
static char __strings_Aparser261[]="implements";
static var __string_Aparser261[]={0,-2, 0,-1};
static char __strings_Aparser262[]="expecting class identifier";
static var __string_Aparser262[]={0,-2, 0,-1};
static char __strings_Aparser263[]=",";
static var __string_Aparser263[]={0,-2, 0,-1};
static char __strings_Aparser264[]="expecting class identifier";
static var __string_Aparser264[]={0,-2, 0,-1};
static char __strings_Aparser265[]="{";
static var __string_Aparser265[]={0,-2, 0,-1};
static char __strings_Aparser266[]="expecting '{'";
static var __string_Aparser266[]={0,-2, 0,-1};
static char __strings_Aparser267[]="}";
static var __string_Aparser267[]={0,-2, 0,-1};
static char __strings_Aparser268[]="expecting '}'";
static var __string_Aparser268[]={0,-2, 0,-1};
static char __strings_Aparser269[]="field";
static var __string_Aparser269[]={0,-2, 0,-1};
static char __strings_Aparser270[]="static";
static var __string_Aparser270[]={0,-2, 0,-1};
static char __strings_Aparser271[]=",";
static var __string_Aparser271[]={0,-2, 0,-1};
static char __strings_Aparser272[]=";";
static var __string_Aparser272[]={0,-2, 0,-1};
static char __strings_Aparser273[]="';' expected.";
static var __string_Aparser273[]={0,-2, 0,-1};
static char __strings_Aparser274[]="Name of variable expected.";
static var __string_Aparser274[]={0,-2, 0,-1};
static char __strings_Aparser275[]="int";
static var __string_Aparser275[]={0,-2, 0,-1};
static char __strings_Aparser276[]="void";
static var __string_Aparser276[]={0,-2, 0,-1};
static char __strings_Aparser277[]="Type expected.";
static var __string_Aparser277[]={0,-2, 0,-1};
static char __strings_Aparser278[]="const";
static var __string_Aparser278[]={0,-2, 0,-1};
static char __strings_Aparser279[]=":=";
static var __string_Aparser279[]={0,-2, 0,-1};
static char __strings_Aparser280[]="':=' expected.";
static var __string_Aparser280[]={0,-2, 0,-1};
static char __strings_Aparser281[]=";";
static var __string_Aparser281[]={0,-2, 0,-1};
static char __strings_Aparser282[]="Expected constant initialiser.";
static var __string_Aparser282[]={0,-2, 0,-1};
static char __strings_Aparser283[]=";";
static var __string_Aparser283[]={0,-2, 0,-1};
static char __strings_Aparser284[]="';' expected.";
static var __string_Aparser284[]={0,-2, 0,-1};
static char __strings_Aparser285[]="constructor";
static var __string_Aparser285[]={0,-2, 0,-1};
static char __strings_Aparser286[]="function";
static var __string_Aparser286[]={0,-2, 0,-1};
static char __strings_Aparser287[]="method";
static var __string_Aparser287[]={0,-2, 0,-1};
static char __strings_Aparser288[]="async";
static var __string_Aparser288[]={0,-2, 0,-1};
static char __strings_Aparser289[]="virtual";
static var __string_Aparser289[]={0,-2, 0,-1};
static char __strings_Aparser290[]="void";
static var __string_Aparser290[]={0,-2, 0,-1};
static char __strings_Aparser291[]="(";
static var __string_Aparser291[]={0,-2, 0,-1};
static char __strings_Aparser292[]="'(' expected.";
static var __string_Aparser292[]={0,-2, 0,-1};
static char __strings_Aparser293[]=")";
static var __string_Aparser293[]={0,-2, 0,-1};
static char __strings_Aparser294[]="')' expected.";
static var __string_Aparser294[]={0,-2, 0,-1};
static char __strings_Aparser295[]=")";
static var __string_Aparser295[]={0,-2, 0,-1};
static char __strings_Aparser296[]=",";
static var __string_Aparser296[]={0,-2, 0,-1};
static char __strings_Aparser297[]="in";
static var __string_Aparser297[]={0,-2, 0,-1};
static char __strings_Aparser298[]="out";
static var __string_Aparser298[]={0,-2, 0,-1};
static char __strings_Aparser299[]="io";
static var __string_Aparser299[]={0,-2, 0,-1};
static char __strings_Aparser300[]="async";
static var __string_Aparser300[]={0,-2, 0,-1};
static char __strings_Aparser301[]="Expected 'in/out/io/async'.";
static var __string_Aparser301[]={0,-2, 0,-1};
static char __strings_Aparser302[]="{";
static var __string_Aparser302[]={0,-2, 0,-1};
static char __strings_Aparser303[]="'{' expected.";
static var __string_Aparser303[]={0,-2, 0,-1};
static char __strings_Aparser304[]="}";
static var __string_Aparser304[]={0,-2, 0,-1};
static char __strings_Aparser305[]="'}' expected at end of lambda body.";
static var __string_Aparser305[]={0,-2, 0,-1};
static char __strings_Aparser306[]="{";
static var __string_Aparser306[]={0,-2, 0,-1};
static char __strings_Aparser307[]="'{' expected.";
static var __string_Aparser307[]={0,-2, 0,-1};
static char __strings_Aparser308[]="}";
static var __string_Aparser308[]={0,-2, 0,-1};
static char __strings_Aparser309[]="'}' expected at end of subroutine body.";
static var __string_Aparser309[]={0,-2, 0,-1};
static char __strings_Aparser310[]="var";
static var __string_Aparser310[]={0,-2, 0,-1};
static char __strings_Aparser311[]=",";
static var __string_Aparser311[]={0,-2, 0,-1};
static char __strings_Aparser312[]=";";
static var __string_Aparser312[]={0,-2, 0,-1};
static char __strings_Aparser313[]="';' expected at end of variable declaration";
static var __string_Aparser313[]={0,-2, 0,-1};
static char __strings_Aparser314[]="break";
static var __string_Aparser314[]={0,-2, 0,-1};
static char __strings_Aparser315[]=";";
static var __string_Aparser315[]={0,-2, 0,-1};
static char __strings_Aparser316[]="';' expected after break";
static var __string_Aparser316[]={0,-2, 0,-1};
static char __strings_Aparser317[]="if";
static var __string_Aparser317[]={0,-2, 0,-1};
static char __strings_Aparser318[]="(";
static var __string_Aparser318[]={0,-2, 0,-1};
static char __strings_Aparser319[]="'(' expected after if.";
static var __string_Aparser319[]={0,-2, 0,-1};
static char __strings_Aparser320[]=")";
static var __string_Aparser320[]={0,-2, 0,-1};
static char __strings_Aparser321[]="')' expected after if condition.";
static var __string_Aparser321[]={0,-2, 0,-1};
static char __strings_Aparser322[]="{";
static var __string_Aparser322[]={0,-2, 0,-1};
static char __strings_Aparser323[]="'{' expected after if ().";
static var __string_Aparser323[]={0,-2, 0,-1};
static char __strings_Aparser324[]="}";
static var __string_Aparser324[]={0,-2, 0,-1};
static char __strings_Aparser325[]="'}' expected after if body.";
static var __string_Aparser325[]={0,-2, 0,-1};
static char __strings_Aparser326[]="else";
static var __string_Aparser326[]={0,-2, 0,-1};
static char __strings_Aparser327[]="if";
static var __string_Aparser327[]={0,-2, 0,-1};
static char __strings_Aparser328[]="{";
static var __string_Aparser328[]={0,-2, 0,-1};
static char __strings_Aparser329[]="'{' expected after else.";
static var __string_Aparser329[]={0,-2, 0,-1};
static char __strings_Aparser330[]="}";
static var __string_Aparser330[]={0,-2, 0,-1};
static char __strings_Aparser331[]="'}' expected after else body.";
static var __string_Aparser331[]={0,-2, 0,-1};
static char __strings_Aparser332[]="while";
static var __string_Aparser332[]={0,-2, 0,-1};
static char __strings_Aparser333[]="(";
static var __string_Aparser333[]={0,-2, 0,-1};
static char __strings_Aparser334[]="'(' expected after while.";
static var __string_Aparser334[]={0,-2, 0,-1};
static char __strings_Aparser335[]=")";
static var __string_Aparser335[]={0,-2, 0,-1};
static char __strings_Aparser336[]="')' expected after while condition.";
static var __string_Aparser336[]={0,-2, 0,-1};
static char __strings_Aparser337[]="{";
static var __string_Aparser337[]={0,-2, 0,-1};
static char __strings_Aparser338[]="'{' expected after while ().";
static var __string_Aparser338[]={0,-2, 0,-1};
static char __strings_Aparser339[]="}";
static var __string_Aparser339[]={0,-2, 0,-1};
static char __strings_Aparser340[]="'}' expected after while body.";
static var __string_Aparser340[]={0,-2, 0,-1};
static char __strings_Aparser341[]="return";
static var __string_Aparser341[]={0,-2, 0,-1};
static char __strings_Aparser342[]=";";
static var __string_Aparser342[]={0,-2, 0,-1};
static char __strings_Aparser343[]=";";
static var __string_Aparser343[]={0,-2, 0,-1};
static char __strings_Aparser344[]="';' expected";
static var __string_Aparser344[]={0,-2, 0,-1};
static char __strings_Aparser345[]=":=";
static var __string_Aparser345[]={0,-2, 0,-1};
static char __strings_Aparser346[]="[";
static var __string_Aparser346[]={0,-2, 0,-1};
static char __strings_Aparser347[]="}";
static var __string_Aparser347[]={0,-2, 0,-1};
static char __strings_Aparser348[]=":=";
static var __string_Aparser348[]={0,-2, 0,-1};
static char __strings_Aparser349[]="[";
static var __string_Aparser349[]={0,-2, 0,-1};
static char __strings_Aparser350[]=";";
static var __string_Aparser350[]={0,-2, 0,-1};
static char __strings_Aparser351[]="';' expected at end of let statement";
static var __string_Aparser351[]={0,-2, 0,-1};
static char __strings_Aparser352[]="]";
static var __string_Aparser352[]={0,-2, 0,-1};
static char __strings_Aparser353[]="']' expected in left side of let statement";
static var __string_Aparser353[]={0,-2, 0,-1};
static char __strings_Aparser354[]=":=";
static var __string_Aparser354[]={0,-2, 0,-1};
static char __strings_Aparser355[]="':=' expected in let statement";
static var __string_Aparser355[]={0,-2, 0,-1};
static char __strings_Aparser356[]=";";
static var __string_Aparser356[]={0,-2, 0,-1};
static char __strings_Aparser357[]="';' expected at end of do statement";
static var __string_Aparser357[]={0,-2, 0,-1};
static char __strings_Aparser358[]="+";
static var __string_Aparser358[]={0,-2, 0,-1};
static char __strings_Aparser359[]="-";
static var __string_Aparser359[]={0,-2, 0,-1};
static char __strings_Aparser360[]="*";
static var __string_Aparser360[]={0,-2, 0,-1};
static char __strings_Aparser361[]="/";
static var __string_Aparser361[]={0,-2, 0,-1};
static char __strings_Aparser362[]="%";
static var __string_Aparser362[]={0,-2, 0,-1};
static char __strings_Aparser363[]="&&";
static var __string_Aparser363[]={0,-2, 0,-1};
static char __strings_Aparser364[]="||";
static var __string_Aparser364[]={0,-2, 0,-1};
static char __strings_Aparser365[]="==";
static var __string_Aparser365[]={0,-2, 0,-1};
static char __strings_Aparser366[]="!=";
static var __string_Aparser366[]={0,-2, 0,-1};
static char __strings_Aparser367[]=">=";
static var __string_Aparser367[]={0,-2, 0,-1};
static char __strings_Aparser368[]="<=";
static var __string_Aparser368[]={0,-2, 0,-1};
static char __strings_Aparser369[]=">";
static var __string_Aparser369[]={0,-2, 0,-1};
static char __strings_Aparser370[]="<";
static var __string_Aparser370[]={0,-2, 0,-1};
static char __strings_Aparser371[]="this";
static var __string_Aparser371[]={0,-2, 0,-1};
static char __strings_Aparser372[]="null";
static var __string_Aparser372[]={0,-2, 0,-1};
static char __strings_Aparser373[]="[";
static var __string_Aparser373[]={0,-2, 0,-1};
static char __strings_Aparser374[]=".$";
static var __string_Aparser374[]={0,-2, 0,-1};
static char __strings_Aparser375[]="constant name expected.";
static var __string_Aparser375[]={0,-2, 0,-1};
static char __strings_Aparser376[]="-";
static var __string_Aparser376[]={0,-2, 0,-1};
static char __strings_Aparser377[]="+";
static var __string_Aparser377[]={0,-2, 0,-1};
static char __strings_Aparser378[]="!";
static var __string_Aparser378[]={0,-2, 0,-1};
static char __strings_Aparser379[]="(";
static var __string_Aparser379[]={0,-2, 0,-1};
static char __strings_Aparser380[]="{";
static var __string_Aparser380[]={0,-2, 0,-1};
static char __strings_Aparser381[]="unexpected term";
static var __string_Aparser381[]={0,-2, 0,-1};
static char __strings_Aparser382[]="(";
static var __string_Aparser382[]={0,-2, 0,-1};
static char __strings_Aparser383[]=".";
static var __string_Aparser383[]={0,-2, 0,-1};
static char __strings_Aparser384[]=")";
static var __string_Aparser384[]={0,-2, 0,-1};
static char __strings_Aparser385[]="')' expected after term";
static var __string_Aparser385[]={0,-2, 0,-1};
static char __strings_Aparser386[]="]";
static var __string_Aparser386[]={0,-2, 0,-1};
static char __strings_Aparser387[]="']' expected after term";
static var __string_Aparser387[]={0,-2, 0,-1};
static char __strings_Aparser388[]="(";
static var __string_Aparser388[]={0,-2, 0,-1};
static char __strings_Aparser389[]="'(' expected in subroutine call.";
static var __string_Aparser389[]={0,-2, 0,-1};
static char __strings_Aparser390[]=")";
static var __string_Aparser390[]={0,-2, 0,-1};
static char __strings_Aparser391[]=")";
static var __string_Aparser391[]={0,-2, 0,-1};
static char __strings_Aparser392[]="')' expected at end of subroutrine call";
static var __string_Aparser392[]={0,-2, 0,-1};
static char __strings_Aparser393[]=",";
static var __string_Aparser393[]={0,-2, 0,-1};
static char __strings_Aparser394[]=",";
static var __string_Aparser394[]={0,-2, 0,-1};
static char __strings_Aparser395[]="unexpected state";
static var __string_Aparser395[]={0,-2, 0,-1};
static char __strings_Astatement396[]="Double else..";
static var __string_Astatement396[]={0,-2, 0,-1};
static char __strings_Astatement397[]="DONT KNOW WHAT";
static var __string_Astatement397[]={0,-2, 0,-1};
static char __strings_mainChello[]=" --- Just A C Kit 3.0.3 ---";
static var __string_mainChello[]={0,-2, 0,-1};
static char __strings_main398[]="Including : ";
static var __string_main398[]={0,-2, 0,-1};
static char __strings_main399[]="";
static var __string_main399[]={0,-2, 0,-1};
static char __strings_main400[]="";
static var __string_main400[]={0,-2, 0,-1};
static char __strings_main401[]="";
static var __string_main401[]={0,-2, 0,-1};
static char __strings_main402[]="Compiling : ";
static var __string_main402[]={0,-2, 0,-1};
static char __strings_main403[]="wrong number of command line arguments";
static var __string_main403[]={0,-2, 0,-1};
static char __strings_main404[]=".jack.c";
static var __string_main404[]={0,-2, 0,-1};
static char __strings_main405[]="";
static var __string_main405[]={0,-2, 0,-1};
static char __strings_main406[]=".jack";
static var __string_main406[]={0,-2, 0,-1};
static char __strings_main407[]=".h";
static var __string_main407[]={0,-2, 0,-1};
static char __strings_main408[]=".c";
static var __string_main408[]={0,-2, 0,-1};
static char __strings_main409[]="Output to : ";
static var __string_main409[]={0,-2, 0,-1};
static char __strings_main410[]=": bytes writing";
static var __string_main410[]={0,-2, 0,-1};
static char __strings_main411[]="Error writing file";
static var __string_main411[]={0,-2, 0,-1};
static void std__init_strings()
{
	__string_array1[2]=(var) __strings_array1;
	__string_string2[2]=(var) __strings_string2;
	__string_Aclass3[2]=(var) __strings_Aclass3;
	__string_Aclass4[2]=(var) __strings_Aclass4;
	__string_Aclass5[2]=(var) __strings_Aclass5;
	__string_Aclass6[2]=(var) __strings_Aclass6;
	__string_Aclass7[2]=(var) __strings_Aclass7;
	__string_Aemmiter8[2]=(var) __strings_Aemmiter8;
	__string_Aemmiter9[2]=(var) __strings_Aemmiter9;
	__string_Aemmiter10[2]=(var) __strings_Aemmiter10;
	__string_Aemmitc11[2]=(var) __strings_Aemmitc11;
	__string_Aemmitc12[2]=(var) __strings_Aemmitc12;
	__string_Aemmitc13[2]=(var) __strings_Aemmitc13;
	__string_Aemmitc14[2]=(var) __strings_Aemmitc14;
	__string_Aemmitc15[2]=(var) __strings_Aemmitc15;
	__string_Aemmitc16[2]=(var) __strings_Aemmitc16;
	__string_Aemmitc17[2]=(var) __strings_Aemmitc17;
	__string_Aemmitc18[2]=(var) __strings_Aemmitc18;
	__string_Aemmitc19[2]=(var) __strings_Aemmitc19;
	__string_Aemmitc20[2]=(var) __strings_Aemmitc20;
	__string_Aemmitc21[2]=(var) __strings_Aemmitc21;
	__string_Aemmitc22[2]=(var) __strings_Aemmitc22;
	__string_Aemmitc23[2]=(var) __strings_Aemmitc23;
	__string_Aemmitc24[2]=(var) __strings_Aemmitc24;
	__string_Aemmitc25[2]=(var) __strings_Aemmitc25;
	__string_Aemmitc26[2]=(var) __strings_Aemmitc26;
	__string_Aemmitc27[2]=(var) __strings_Aemmitc27;
	__string_Aemmitc28[2]=(var) __strings_Aemmitc28;
	__string_Aemmitc29[2]=(var) __strings_Aemmitc29;
	__string_Aemmitc30[2]=(var) __strings_Aemmitc30;
	__string_Aemmitc31[2]=(var) __strings_Aemmitc31;
	__string_Aemmitc32[2]=(var) __strings_Aemmitc32;
	__string_Aemmitc33[2]=(var) __strings_Aemmitc33;
	__string_Aemmitc34[2]=(var) __strings_Aemmitc34;
	__string_Aemmitc35[2]=(var) __strings_Aemmitc35;
	__string_Aemmitc36[2]=(var) __strings_Aemmitc36;
	__string_Aemmitc37[2]=(var) __strings_Aemmitc37;
	__string_Aemmitc38[2]=(var) __strings_Aemmitc38;
	__string_Aemmitc39[2]=(var) __strings_Aemmitc39;
	__string_Aemmitc40[2]=(var) __strings_Aemmitc40;
	__string_Aemmitc41[2]=(var) __strings_Aemmitc41;
	__string_Aemmitc42[2]=(var) __strings_Aemmitc42;
	__string_Aemmitc43[2]=(var) __strings_Aemmitc43;
	__string_Aemmitc44[2]=(var) __strings_Aemmitc44;
	__string_Aemmitc45[2]=(var) __strings_Aemmitc45;
	__string_Aemmitc46[2]=(var) __strings_Aemmitc46;
	__string_Aemmitc47[2]=(var) __strings_Aemmitc47;
	__string_Aemmitc48[2]=(var) __strings_Aemmitc48;
	__string_Aemmitc49[2]=(var) __strings_Aemmitc49;
	__string_Aemmitc50[2]=(var) __strings_Aemmitc50;
	__string_Aemmitc51[2]=(var) __strings_Aemmitc51;
	__string_Aemmitc52[2]=(var) __strings_Aemmitc52;
	__string_Aemmitc53[2]=(var) __strings_Aemmitc53;
	__string_Aemmitc54[2]=(var) __strings_Aemmitc54;
	__string_Aemmitc55[2]=(var) __strings_Aemmitc55;
	__string_Aemmitc56[2]=(var) __strings_Aemmitc56;
	__string_Aemmitc57[2]=(var) __strings_Aemmitc57;
	__string_Aemmitc58[2]=(var) __strings_Aemmitc58;
	__string_Aemmitc59[2]=(var) __strings_Aemmitc59;
	__string_Aemmitc60[2]=(var) __strings_Aemmitc60;
	__string_Aemmitc61[2]=(var) __strings_Aemmitc61;
	__string_Aemmitc62[2]=(var) __strings_Aemmitc62;
	__string_Aemmitc63[2]=(var) __strings_Aemmitc63;
	__string_Aemmitc64[2]=(var) __strings_Aemmitc64;
	__string_Aemmitc65[2]=(var) __strings_Aemmitc65;
	__string_Aemmitc66[2]=(var) __strings_Aemmitc66;
	__string_Aemmitc67[2]=(var) __strings_Aemmitc67;
	__string_Aemmitc68[2]=(var) __strings_Aemmitc68;
	__string_Aemmitc69[2]=(var) __strings_Aemmitc69;
	__string_Aemmitc70[2]=(var) __strings_Aemmitc70;
	__string_Aemmitc71[2]=(var) __strings_Aemmitc71;
	__string_Aemmitc72[2]=(var) __strings_Aemmitc72;
	__string_Aemmitc73[2]=(var) __strings_Aemmitc73;
	__string_Aemmitc74[2]=(var) __strings_Aemmitc74;
	__string_Aemmitc75[2]=(var) __strings_Aemmitc75;
	__string_Aemmitc76[2]=(var) __strings_Aemmitc76;
	__string_Aemmitc77[2]=(var) __strings_Aemmitc77;
	__string_Aemmitc78[2]=(var) __strings_Aemmitc78;
	__string_Aemmitc79[2]=(var) __strings_Aemmitc79;
	__string_Aemmitc80[2]=(var) __strings_Aemmitc80;
	__string_Aemmitc81[2]=(var) __strings_Aemmitc81;
	__string_Aemmitc82[2]=(var) __strings_Aemmitc82;
	__string_Aemmitc83[2]=(var) __strings_Aemmitc83;
	__string_Aemmitc84[2]=(var) __strings_Aemmitc84;
	__string_Aemmitc85[2]=(var) __strings_Aemmitc85;
	__string_Aemmitc86[2]=(var) __strings_Aemmitc86;
	__string_Aemmitc87[2]=(var) __strings_Aemmitc87;
	__string_Aemmitc88[2]=(var) __strings_Aemmitc88;
	__string_Aemmitc89[2]=(var) __strings_Aemmitc89;
	__string_Aemmitc90[2]=(var) __strings_Aemmitc90;
	__string_Aemmitc91[2]=(var) __strings_Aemmitc91;
	__string_Aemmitc92[2]=(var) __strings_Aemmitc92;
	__string_Aemmitc93[2]=(var) __strings_Aemmitc93;
	__string_Aemmitc94[2]=(var) __strings_Aemmitc94;
	__string_Aemmitc95[2]=(var) __strings_Aemmitc95;
	__string_Aemmitc96[2]=(var) __strings_Aemmitc96;
	__string_Aemmitc97[2]=(var) __strings_Aemmitc97;
	__string_Aemmitc98[2]=(var) __strings_Aemmitc98;
	__string_Aemmitc99[2]=(var) __strings_Aemmitc99;
	__string_Aemmitc100[2]=(var) __strings_Aemmitc100;
	__string_Aemmitc101[2]=(var) __strings_Aemmitc101;
	__string_Aemmitc102[2]=(var) __strings_Aemmitc102;
	__string_Aemmitc103[2]=(var) __strings_Aemmitc103;
	__string_Aemmitc104[2]=(var) __strings_Aemmitc104;
	__string_Aemmitc105[2]=(var) __strings_Aemmitc105;
	__string_Aemmitc106[2]=(var) __strings_Aemmitc106;
	__string_Aemmitc107[2]=(var) __strings_Aemmitc107;
	__string_Aemmitc108[2]=(var) __strings_Aemmitc108;
	__string_Aemmitc109[2]=(var) __strings_Aemmitc109;
	__string_Aemmitc110[2]=(var) __strings_Aemmitc110;
	__string_Aemmitc111[2]=(var) __strings_Aemmitc111;
	__string_Aemmitc112[2]=(var) __strings_Aemmitc112;
	__string_Aemmitc113[2]=(var) __strings_Aemmitc113;
	__string_Aemmitc114[2]=(var) __strings_Aemmitc114;
	__string_Aemmitc115[2]=(var) __strings_Aemmitc115;
	__string_Aemmitc116[2]=(var) __strings_Aemmitc116;
	__string_Aemmitc117[2]=(var) __strings_Aemmitc117;
	__string_Aemmitc118[2]=(var) __strings_Aemmitc118;
	__string_Aemmitc119[2]=(var) __strings_Aemmitc119;
	__string_Aemmitc120[2]=(var) __strings_Aemmitc120;
	__string_Aemmitc121[2]=(var) __strings_Aemmitc121;
	__string_Aemmitc122[2]=(var) __strings_Aemmitc122;
	__string_Aemmitc123[2]=(var) __strings_Aemmitc123;
	__string_Aemmitc124[2]=(var) __strings_Aemmitc124;
	__string_Aemmitc125[2]=(var) __strings_Aemmitc125;
	__string_Aemmitc126[2]=(var) __strings_Aemmitc126;
	__string_Aemmitc127[2]=(var) __strings_Aemmitc127;
	__string_Aemmitc128[2]=(var) __strings_Aemmitc128;
	__string_Aemmitc129[2]=(var) __strings_Aemmitc129;
	__string_Aemmitc130[2]=(var) __strings_Aemmitc130;
	__string_Aemmitc131[2]=(var) __strings_Aemmitc131;
	__string_Aemmitc132[2]=(var) __strings_Aemmitc132;
	__string_Aemmitc133[2]=(var) __strings_Aemmitc133;
	__string_Aemmitc134[2]=(var) __strings_Aemmitc134;
	__string_Aemmitc135[2]=(var) __strings_Aemmitc135;
	__string_Aemmitc136[2]=(var) __strings_Aemmitc136;
	__string_Aemmitc137[2]=(var) __strings_Aemmitc137;
	__string_Aemmitc138[2]=(var) __strings_Aemmitc138;
	__string_Aemmitc139[2]=(var) __strings_Aemmitc139;
	__string_Aemmitc140[2]=(var) __strings_Aemmitc140;
	__string_Aemmitc141[2]=(var) __strings_Aemmitc141;
	__string_Aemmitc142[2]=(var) __strings_Aemmitc142;
	__string_Aemmitc143[2]=(var) __strings_Aemmitc143;
	__string_Aemmitc144[2]=(var) __strings_Aemmitc144;
	__string_Aemmitc145[2]=(var) __strings_Aemmitc145;
	__string_Aemmitc146[2]=(var) __strings_Aemmitc146;
	__string_Aemmitc147[2]=(var) __strings_Aemmitc147;
	__string_Aemmitc148[2]=(var) __strings_Aemmitc148;
	__string_Aemmitc149[2]=(var) __strings_Aemmitc149;
	__string_Aemmitc150[2]=(var) __strings_Aemmitc150;
	__string_Aemmitc151[2]=(var) __strings_Aemmitc151;
	__string_Aemmitc152[2]=(var) __strings_Aemmitc152;
	__string_Aemmitc153[2]=(var) __strings_Aemmitc153;
	__string_Aemmitc154[2]=(var) __strings_Aemmitc154;
	__string_Aemmitc155[2]=(var) __strings_Aemmitc155;
	__string_Aemmitc156[2]=(var) __strings_Aemmitc156;
	__string_Aemmitc157[2]=(var) __strings_Aemmitc157;
	__string_Aemmitc158[2]=(var) __strings_Aemmitc158;
	__string_Aemmitc159[2]=(var) __strings_Aemmitc159;
	__string_Aemmitc160[2]=(var) __strings_Aemmitc160;
	__string_Aemmitc161[2]=(var) __strings_Aemmitc161;
	__string_Aemmitc162[2]=(var) __strings_Aemmitc162;
	__string_Aemmitc163[2]=(var) __strings_Aemmitc163;
	__string_Aemmitc164[2]=(var) __strings_Aemmitc164;
	__string_Aemmitc165[2]=(var) __strings_Aemmitc165;
	__string_Aemmitc166[2]=(var) __strings_Aemmitc166;
	__string_Aemmitc167[2]=(var) __strings_Aemmitc167;
	__string_Aemmitc168[2]=(var) __strings_Aemmitc168;
	__string_Aemmitc169[2]=(var) __strings_Aemmitc169;
	__string_Aemmitc170[2]=(var) __strings_Aemmitc170;
	__string_Aemmitc171[2]=(var) __strings_Aemmitc171;
	__string_Aemmitc172[2]=(var) __strings_Aemmitc172;
	__string_Aemmitc173[2]=(var) __strings_Aemmitc173;
	__string_Aemmitc174[2]=(var) __strings_Aemmitc174;
	__string_Aemmitc175[2]=(var) __strings_Aemmitc175;
	__string_Aemmitc176[2]=(var) __strings_Aemmitc176;
	__string_Aemmitc177[2]=(var) __strings_Aemmitc177;
	__string_Aemmitc178[2]=(var) __strings_Aemmitc178;
	__string_Aemmitc179[2]=(var) __strings_Aemmitc179;
	__string_Aemmitc180[2]=(var) __strings_Aemmitc180;
	__string_Aemmitc181[2]=(var) __strings_Aemmitc181;
	__string_Aemmitc182[2]=(var) __strings_Aemmitc182;
	__string_Aemmitc183[2]=(var) __strings_Aemmitc183;
	__string_Aemmitc184[2]=(var) __strings_Aemmitc184;
	__string_Aemmitc185[2]=(var) __strings_Aemmitc185;
	__string_Aemmitc186[2]=(var) __strings_Aemmitc186;
	__string_Aemmitc187[2]=(var) __strings_Aemmitc187;
	__string_Aemmitc188[2]=(var) __strings_Aemmitc188;
	__string_Aemmitc189[2]=(var) __strings_Aemmitc189;
	__string_Aemmitc190[2]=(var) __strings_Aemmitc190;
	__string_Aemmitc191[2]=(var) __strings_Aemmitc191;
	__string_Acbody192[2]=(var) __strings_Acbody192;
	__string_Acbody193[2]=(var) __strings_Acbody193;
	__string_Acbody194[2]=(var) __strings_Acbody194;
	__string_Acbody195[2]=(var) __strings_Acbody195;
	__string_Acbody196[2]=(var) __strings_Acbody196;
	__string_Acbody197[2]=(var) __strings_Acbody197;
	__string_Acbody198[2]=(var) __strings_Acbody198;
	__string_Acbody199[2]=(var) __strings_Acbody199;
	__string_Acbody200[2]=(var) __strings_Acbody200;
	__string_Acbody201[2]=(var) __strings_Acbody201;
	__string_Acbody202[2]=(var) __strings_Acbody202;
	__string_Acbody203[2]=(var) __strings_Acbody203;
	__string_Acbody204[2]=(var) __strings_Acbody204;
	__string_Acbody205[2]=(var) __strings_Acbody205;
	__string_Acbody206[2]=(var) __strings_Acbody206;
	__string_Acbody207[2]=(var) __strings_Acbody207;
	__string_Acbody208[2]=(var) __strings_Acbody208;
	__string_Acbody209[2]=(var) __strings_Acbody209;
	__string_Acbody210[2]=(var) __strings_Acbody210;
	__string_Acbody211[2]=(var) __strings_Acbody211;
	__string_Acbody212[2]=(var) __strings_Acbody212;
	__string_Acbody213[2]=(var) __strings_Acbody213;
	__string_Acbody214[2]=(var) __strings_Acbody214;
	__string_Acbody215[2]=(var) __strings_Acbody215;
	__string_Acbody216[2]=(var) __strings_Acbody216;
	__string_Acbody217[2]=(var) __strings_Acbody217;
	__string_Acbody218[2]=(var) __strings_Acbody218;
	__string_Acbody219[2]=(var) __strings_Acbody219;
	__string_Acbody220[2]=(var) __strings_Acbody220;
	__string_Acbody221[2]=(var) __strings_Acbody221;
	__string_Acbody222[2]=(var) __strings_Acbody222;
	__string_Acbody223[2]=(var) __strings_Acbody223;
	__string_Acbody224[2]=(var) __strings_Acbody224;
	__string_Acbody225[2]=(var) __strings_Acbody225;
	__string_Acbody226[2]=(var) __strings_Acbody226;
	__string_Acbody227[2]=(var) __strings_Acbody227;
	__string_Acbody228[2]=(var) __strings_Acbody228;
	__string_Acbody229[2]=(var) __strings_Acbody229;
	__string_Acbody230[2]=(var) __strings_Acbody230;
	__string_Acbody231[2]=(var) __strings_Acbody231;
	__string_Acbody232[2]=(var) __strings_Acbody232;
	__string_Acbody233[2]=(var) __strings_Acbody233;
	__string_Acbody234[2]=(var) __strings_Acbody234;
	__string_Acbody235[2]=(var) __strings_Acbody235;
	__string_Acbody236[2]=(var) __strings_Acbody236;
	__string_Acbody237[2]=(var) __strings_Acbody237;
	__string_Acbody238[2]=(var) __strings_Acbody238;
	__string_Acbody239[2]=(var) __strings_Acbody239;
	__string_Acbody240[2]=(var) __strings_Acbody240;
	__string_Acbody241[2]=(var) __strings_Acbody241;
	__string_Acbody242[2]=(var) __strings_Acbody242;
	__string_Acbody243[2]=(var) __strings_Acbody243;
	__string_Acbody244[2]=(var) __strings_Acbody244;
	__string_Acbody245[2]=(var) __strings_Acbody245;
	__string_Aexpr246[2]=(var) __strings_Aexpr246;
	__string_Aexpr247[2]=(var) __strings_Aexpr247;
	__string_Aexpr248[2]=(var) __strings_Aexpr248;
	__string_Alexer249[2]=(var) __strings_Alexer249;
	__string_Alexer250[2]=(var) __strings_Alexer250;
	__string_Alexer251[2]=(var) __strings_Alexer251;
	__string_Alexer252[2]=(var) __strings_Alexer252;
	__string_Alexer253[2]=(var) __strings_Alexer253;
	__string_Alexer254[2]=(var) __strings_Alexer254;
	__string_Aparser255[2]=(var) __strings_Aparser255;
	__string_Aparser256[2]=(var) __strings_Aparser256;
	__string_Aparser257[2]=(var) __strings_Aparser257;
	__string_Aparser258[2]=(var) __strings_Aparser258;
	__string_Aparser259[2]=(var) __strings_Aparser259;
	__string_Aparser260[2]=(var) __strings_Aparser260;
	__string_Aparser261[2]=(var) __strings_Aparser261;
	__string_Aparser262[2]=(var) __strings_Aparser262;
	__string_Aparser263[2]=(var) __strings_Aparser263;
	__string_Aparser264[2]=(var) __strings_Aparser264;
	__string_Aparser265[2]=(var) __strings_Aparser265;
	__string_Aparser266[2]=(var) __strings_Aparser266;
	__string_Aparser267[2]=(var) __strings_Aparser267;
	__string_Aparser268[2]=(var) __strings_Aparser268;
	__string_Aparser269[2]=(var) __strings_Aparser269;
	__string_Aparser270[2]=(var) __strings_Aparser270;
	__string_Aparser271[2]=(var) __strings_Aparser271;
	__string_Aparser272[2]=(var) __strings_Aparser272;
	__string_Aparser273[2]=(var) __strings_Aparser273;
	__string_Aparser274[2]=(var) __strings_Aparser274;
	__string_Aparser275[2]=(var) __strings_Aparser275;
	__string_Aparser276[2]=(var) __strings_Aparser276;
	__string_Aparser277[2]=(var) __strings_Aparser277;
	__string_Aparser278[2]=(var) __strings_Aparser278;
	__string_Aparser279[2]=(var) __strings_Aparser279;
	__string_Aparser280[2]=(var) __strings_Aparser280;
	__string_Aparser281[2]=(var) __strings_Aparser281;
	__string_Aparser282[2]=(var) __strings_Aparser282;
	__string_Aparser283[2]=(var) __strings_Aparser283;
	__string_Aparser284[2]=(var) __strings_Aparser284;
	__string_Aparser285[2]=(var) __strings_Aparser285;
	__string_Aparser286[2]=(var) __strings_Aparser286;
	__string_Aparser287[2]=(var) __strings_Aparser287;
	__string_Aparser288[2]=(var) __strings_Aparser288;
	__string_Aparser289[2]=(var) __strings_Aparser289;
	__string_Aparser290[2]=(var) __strings_Aparser290;
	__string_Aparser291[2]=(var) __strings_Aparser291;
	__string_Aparser292[2]=(var) __strings_Aparser292;
	__string_Aparser293[2]=(var) __strings_Aparser293;
	__string_Aparser294[2]=(var) __strings_Aparser294;
	__string_Aparser295[2]=(var) __strings_Aparser295;
	__string_Aparser296[2]=(var) __strings_Aparser296;
	__string_Aparser297[2]=(var) __strings_Aparser297;
	__string_Aparser298[2]=(var) __strings_Aparser298;
	__string_Aparser299[2]=(var) __strings_Aparser299;
	__string_Aparser300[2]=(var) __strings_Aparser300;
	__string_Aparser301[2]=(var) __strings_Aparser301;
	__string_Aparser302[2]=(var) __strings_Aparser302;
	__string_Aparser303[2]=(var) __strings_Aparser303;
	__string_Aparser304[2]=(var) __strings_Aparser304;
	__string_Aparser305[2]=(var) __strings_Aparser305;
	__string_Aparser306[2]=(var) __strings_Aparser306;
	__string_Aparser307[2]=(var) __strings_Aparser307;
	__string_Aparser308[2]=(var) __strings_Aparser308;
	__string_Aparser309[2]=(var) __strings_Aparser309;
	__string_Aparser310[2]=(var) __strings_Aparser310;
	__string_Aparser311[2]=(var) __strings_Aparser311;
	__string_Aparser312[2]=(var) __strings_Aparser312;
	__string_Aparser313[2]=(var) __strings_Aparser313;
	__string_Aparser314[2]=(var) __strings_Aparser314;
	__string_Aparser315[2]=(var) __strings_Aparser315;
	__string_Aparser316[2]=(var) __strings_Aparser316;
	__string_Aparser317[2]=(var) __strings_Aparser317;
	__string_Aparser318[2]=(var) __strings_Aparser318;
	__string_Aparser319[2]=(var) __strings_Aparser319;
	__string_Aparser320[2]=(var) __strings_Aparser320;
	__string_Aparser321[2]=(var) __strings_Aparser321;
	__string_Aparser322[2]=(var) __strings_Aparser322;
	__string_Aparser323[2]=(var) __strings_Aparser323;
	__string_Aparser324[2]=(var) __strings_Aparser324;
	__string_Aparser325[2]=(var) __strings_Aparser325;
	__string_Aparser326[2]=(var) __strings_Aparser326;
	__string_Aparser327[2]=(var) __strings_Aparser327;
	__string_Aparser328[2]=(var) __strings_Aparser328;
	__string_Aparser329[2]=(var) __strings_Aparser329;
	__string_Aparser330[2]=(var) __strings_Aparser330;
	__string_Aparser331[2]=(var) __strings_Aparser331;
	__string_Aparser332[2]=(var) __strings_Aparser332;
	__string_Aparser333[2]=(var) __strings_Aparser333;
	__string_Aparser334[2]=(var) __strings_Aparser334;
	__string_Aparser335[2]=(var) __strings_Aparser335;
	__string_Aparser336[2]=(var) __strings_Aparser336;
	__string_Aparser337[2]=(var) __strings_Aparser337;
	__string_Aparser338[2]=(var) __strings_Aparser338;
	__string_Aparser339[2]=(var) __strings_Aparser339;
	__string_Aparser340[2]=(var) __strings_Aparser340;
	__string_Aparser341[2]=(var) __strings_Aparser341;
	__string_Aparser342[2]=(var) __strings_Aparser342;
	__string_Aparser343[2]=(var) __strings_Aparser343;
	__string_Aparser344[2]=(var) __strings_Aparser344;
	__string_Aparser345[2]=(var) __strings_Aparser345;
	__string_Aparser346[2]=(var) __strings_Aparser346;
	__string_Aparser347[2]=(var) __strings_Aparser347;
	__string_Aparser348[2]=(var) __strings_Aparser348;
	__string_Aparser349[2]=(var) __strings_Aparser349;
	__string_Aparser350[2]=(var) __strings_Aparser350;
	__string_Aparser351[2]=(var) __strings_Aparser351;
	__string_Aparser352[2]=(var) __strings_Aparser352;
	__string_Aparser353[2]=(var) __strings_Aparser353;
	__string_Aparser354[2]=(var) __strings_Aparser354;
	__string_Aparser355[2]=(var) __strings_Aparser355;
	__string_Aparser356[2]=(var) __strings_Aparser356;
	__string_Aparser357[2]=(var) __strings_Aparser357;
	__string_Aparser358[2]=(var) __strings_Aparser358;
	__string_Aparser359[2]=(var) __strings_Aparser359;
	__string_Aparser360[2]=(var) __strings_Aparser360;
	__string_Aparser361[2]=(var) __strings_Aparser361;
	__string_Aparser362[2]=(var) __strings_Aparser362;
	__string_Aparser363[2]=(var) __strings_Aparser363;
	__string_Aparser364[2]=(var) __strings_Aparser364;
	__string_Aparser365[2]=(var) __strings_Aparser365;
	__string_Aparser366[2]=(var) __strings_Aparser366;
	__string_Aparser367[2]=(var) __strings_Aparser367;
	__string_Aparser368[2]=(var) __strings_Aparser368;
	__string_Aparser369[2]=(var) __strings_Aparser369;
	__string_Aparser370[2]=(var) __strings_Aparser370;
	__string_Aparser371[2]=(var) __strings_Aparser371;
	__string_Aparser372[2]=(var) __strings_Aparser372;
	__string_Aparser373[2]=(var) __strings_Aparser373;
	__string_Aparser374[2]=(var) __strings_Aparser374;
	__string_Aparser375[2]=(var) __strings_Aparser375;
	__string_Aparser376[2]=(var) __strings_Aparser376;
	__string_Aparser377[2]=(var) __strings_Aparser377;
	__string_Aparser378[2]=(var) __strings_Aparser378;
	__string_Aparser379[2]=(var) __strings_Aparser379;
	__string_Aparser380[2]=(var) __strings_Aparser380;
	__string_Aparser381[2]=(var) __strings_Aparser381;
	__string_Aparser382[2]=(var) __strings_Aparser382;
	__string_Aparser383[2]=(var) __strings_Aparser383;
	__string_Aparser384[2]=(var) __strings_Aparser384;
	__string_Aparser385[2]=(var) __strings_Aparser385;
	__string_Aparser386[2]=(var) __strings_Aparser386;
	__string_Aparser387[2]=(var) __strings_Aparser387;
	__string_Aparser388[2]=(var) __strings_Aparser388;
	__string_Aparser389[2]=(var) __strings_Aparser389;
	__string_Aparser390[2]=(var) __strings_Aparser390;
	__string_Aparser391[2]=(var) __strings_Aparser391;
	__string_Aparser392[2]=(var) __strings_Aparser392;
	__string_Aparser393[2]=(var) __strings_Aparser393;
	__string_Aparser394[2]=(var) __strings_Aparser394;
	__string_Aparser395[2]=(var) __strings_Aparser395;
	__string_Astatement396[2]=(var) __strings_Astatement396;
	__string_Astatement397[2]=(var) __strings_Astatement397;
	__string_mainChello[2]=(var) __strings_mainChello;
	__string_main398[2]=(var) __strings_main398;
	__string_main399[2]=(var) __strings_main399;
	__string_main400[2]=(var) __strings_main400;
	__string_main401[2]=(var) __strings_main401;
	__string_main402[2]=(var) __strings_main402;
	__string_main403[2]=(var) __strings_main403;
	__string_main404[2]=(var) __strings_main404;
	__string_main405[2]=(var) __strings_main405;
	__string_main406[2]=(var) __strings_main406;
	__string_main407[2]=(var) __strings_main407;
	__string_main408[2]=(var) __strings_main408;
	__string_main409[2]=(var) __strings_main409;
	__string_main410[2]=(var) __strings_main410;
	__string_main411[2]=(var) __strings_main411;
}
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

/* class array */
struct array {
	var dummy;
};
var array__new(var size, var __parent)
{
	static var recursive = 0;
	var __return__ = 0;
	var a;
	FAKETHIS();
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"array.new\"\n");std__panic();
	}
	if (size<1) {
		console__log((var)(__string_array1+ 2));
		std__panic();
	}
	a=std__alloc(size,__parent,array___DcidD);
	__return__ = a;
	recursive--;
	return __return__;
}
var array___V_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(array);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"array.dispose\"\n");std__panic();
	}
	std__free(__this);
	recursive--;
	return __return__;
}
/* class buffer */
struct buffer {
	var _arr;
	var size;
	var pos;
	var take;
};
var buffer___new(var __this, var initial_size, var take_, var __parent)
{
	static var recursive = 0;
	var __return__ = 0;
	var i;
	MAKETHIS(buffer);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"buffer.new\"\n");std__panic();
	}
	_this->take=take_;
	_this->_arr=array__new(initial_size,__this);
	_this->size=initial_size;
	_this->pos=0;
	i=0;
	while (i<initial_size) {
		((var*)_this->_arr)[i]=0;
		i=i+1;
	}
	__return__ = __this;
	recursive--;
	return __return__;
}
var buffer__new(var initial_size, var take_, var __parent)
{
	NEW(buffer);
	return buffer___new(__this, initial_size, take_, __parent);
}
var buffer___V_delayed_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var i;
	MAKETHIS(buffer);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"buffer.delayed_dispose\"\n");std__panic();
	}
	if ((_this->_arr!=0)&&(_this->take!=0)) {
		i=0;
		while (i<_this->pos) {
			buffer__delete_at(__this, i);
			i=i+1;
		}
	}
	std__delete(_this->_arr);
	_this->_arr=0;
	std__free(__this);
	recursive--;
	return __return__;
}
var buffer___V_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(buffer);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"buffer.dispose\"\n");std__panic();
	}
	std__delayed_delete(__this);
	recursive--;
	return __return__;
}
var buffer__length(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(buffer);
	if (((var*)__this)[-1]!=buffer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"buffer.length\"\n");std__panic();
	}
	__return__ = _this->pos;
	recursive--;
	return __return__;
}
var buffer__empty(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(buffer);
	if (((var*)__this)[-1]!=buffer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"buffer.empty\"\n");std__panic();
	}
	if (_this->pos>0) {
		__return__ = 0;
	recursive--;
	return __return__;
	}
	__return__ = 1;
	recursive--;
	return __return__;
}
var buffer__delete_at(var __this, var idx)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(buffer);
	if (((var*)__this)[-1]!=buffer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"buffer.delete_at\"\n");std__panic();
	}
	std__delete(((var*)_this->_arr)[idx]);
	((var*)_this->_arr)[idx]=0;
	recursive--;
	return __return__;
}
var buffer__set_at(var __this, var idx, var elem)
{
	static var recursive = 0;
	var __return__ = 0;
	var a;
	var i;
	MAKETHIS(buffer);
	if (((var*)__this)[-1]!=buffer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"buffer.set_at\"\n");std__panic();
	}
	if (((idx+1))>=_this->size) {
		a=array__new(idx+8,__this);
		i=0;
		while (i<_this->pos) {
			((var*)a)[i]=((var*)_this->_arr)[i];
			i=i+1;
		}
		_this->size=idx+8;
		while (i<_this->size) {
			((var*)a)[i]=0;
			i=i+1;
		}
		array__dispose(_this->_arr);
		_this->_arr=a;
	} else if ((_this->take!=0)&&(idx<_this->pos)) {
		buffer__delete_at(__this, idx);
	}
	if (_this->take!=0) {
		std__move(elem);
	}
	while (_this->pos<idx) {
		((var*)_this->_arr)[_this->pos]=0;
		_this->pos=_this->pos+1;
	}
	((var*)_this->_arr)[idx]=elem;
	if (idx>=_this->pos) {
		_this->pos=idx+1;
	}
	recursive--;
	return __return__;
}
var buffer__get_at(var __this, var idx)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(buffer);
	if (((var*)__this)[-1]!=buffer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"buffer.get_at\"\n");std__panic();
	}
	__return__ = ((var*)_this->_arr)[idx];
	recursive--;
	return __return__;
}
var buffer__push(var __this, var elem)
{
	static var recursive = 0;
	var __return__ = 0;
	var p;
	MAKETHIS(buffer);
	if (((var*)__this)[-1]!=buffer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"buffer.push\"\n");std__panic();
	}
	p=_this->pos+1;
	buffer__set_at(__this, _this->pos,elem);
	_this->pos=p;
	__return__ = 0;
	recursive--;
	return __return__;
}
var buffer__append(var __this, var buf)
{
	static var recursive = 0;
	var __return__ = 0;
	var l;
	var j;
	MAKETHIS(buffer);
	if (((var*)__this)[-1]!=buffer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"buffer.append\"\n");std__panic();
	}
	j=buffer__length(buf);
	l=(buffer__length(__this))+j;
	while (j>0) {
		l=l-1;
		j=j-1;
		buffer__set_at(__this, l,buffer__get_at(buf,j));
	}
	recursive--;
	return __return__;
}
var buffer__set_last(var __this, var elem)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(buffer);
	if (((var*)__this)[-1]!=buffer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"buffer.set_last\"\n");std__panic();
	}
	if (_this->pos<1) {
		recursive--;
	return __return__;
	}
	((var*)_this->_arr)[_this->pos-1]=elem;
	recursive--;
	return __return__;
}
var buffer__get_last(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(buffer);
	if (((var*)__this)[-1]!=buffer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"buffer.get_last\"\n");std__panic();
	}
	if (_this->pos<1) {
		__return__ = 0;
	recursive--;
	return __return__;
	}
	__return__ = ((var*)_this->_arr)[_this->pos-1];
	recursive--;
	return __return__;
}
var buffer__pop(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var elem;
	MAKETHIS(buffer);
	if (((var*)__this)[-1]!=buffer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"buffer.pop\"\n");std__panic();
	}
	elem=0;
	if (_this->pos>0) {
		elem=buffer__get_at(__this, _this->pos-1);
		_this->pos=_this->pos-1;
	}
	__return__ = elem;
	recursive--;
	return __return__;
}
var buffer__unshift(var __this, var elem)
{
	static var recursive = 0;
	var __return__ = 0;
	var i;
	var p;
	MAKETHIS(buffer);
	if (((var*)__this)[-1]!=buffer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"buffer.unshift\"\n");std__panic();
	}
	p=_this->pos+1;
	buffer__set_at(__this, _this->pos,0);
	i=_this->pos;
	while (i>1) {
		i=i-1;
		((var*)_this->_arr)[i]=((var*)_this->_arr)[i-1];
	}
	((var*)_this->_arr)[0]=elem;
	_this->pos=p;
	__return__ = 0;
	recursive--;
	return __return__;
}
var buffer__shift(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var elem;
	var i;
	var p;
	MAKETHIS(buffer);
	if (((var*)__this)[-1]!=buffer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"buffer.shift\"\n");std__panic();
	}
	if (_this->pos<1) {
		__return__ = 0;
	recursive--;
	return __return__;
	}
	p=_this->pos-1;
	elem=buffer__get_at(__this, 0);
	i=0;
	while (i<p) {
		((var*)_this->_arr)[i]=((var*)_this->_arr)[i+1];
		i=i+1;
	}
	_this->pos=p;
	__return__ = elem;
	recursive--;
	return __return__;
}
/* class bytes */
struct bytes {
	var buf;
	var size;
};
var bytes___V_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(bytes);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"bytes.dispose\"\n");std__panic();
	}
	std__bytes_dispose(__this);
	recursive--;
	return __return__;
}
var bytes__get_size(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(bytes);
	if (((var*)__this)[-1]!=bytes___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"bytes.get_size\"\n");std__panic();
	}
	__return__ = _this->size;
	recursive--;
	return __return__;
}
var bytes__set_size(var __this, var size1)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(bytes);
	if (((var*)__this)[-1]!=bytes___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"bytes.set_size\"\n");std__panic();
	}
	_this->size=size1;
	recursive--;
	return __return__;
}
/* class console */
var console__log(var str)
{
	static var recursive = 0;
	var __return__ = 0;
	FAKETHIS();
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"console.log\"\n");std__panic();
	}
	std__echo(str);
	std__echo_nl();
	recursive--;
	return __return__;
}
var console__log_str(var str)
{
	static var recursive = 0;
	var __return__ = 0;
	FAKETHIS();
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"console.log_str\"\n");std__panic();
	}
	std__echo(str);
	recursive--;
	return __return__;
}
var console__log_int(var n)
{
	static var recursive = 0;
	var __return__ = 0;
	FAKETHIS();
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"console.log_int\"\n");std__panic();
	}
	std__echo_int(n);
	recursive--;
	return __return__;
}
/* class file */
struct file {
	var _folder;
};
var file___new(var __this, var folder, var __parent)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(file);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"file.new\"\n");std__panic();
	}
	_this->_folder=string__to_string(folder);
	__return__ = __this;
	recursive--;
	return __return__;
}
var file__new(var folder, var __parent)
{
	NEW(file);
	return file___new(__this, folder, __parent);
}
var file___V_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(file);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"file.dispose\"\n");std__panic();
	}
	string__dispose(_this->_folder);
	std__free(__this);
	recursive--;
	return __return__;
}
var file__mkfolder(var __this, var cb, var this_cb)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(file);
	if (((var*)__this)[-1]!=file___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"file.mkfolder\"\n");std__panic();
	}
	std__mkfolder(cb,this_cb);
	recursive--;
	return __return__;
}
var file__mkdir(var __this, var name, var cb, var this_cb)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(file);
	if (((var*)__this)[-1]!=file___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"file.mkdir\"\n");std__panic();
	}
	std__mkdir(_this->_folder,name,cb,this_cb);
	recursive--;
	return __return__;
}
var file__read(var __this, var name, var seek, var size_, var cb, var this_cb)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(file);
	if (((var*)__this)[-1]!=file___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"file.read\"\n");std__panic();
	}
	std__read(_this->_folder,name,seek,size_,cb,this_cb);
	recursive--;
	return __return__;
}
var file__write(var __this, var name, var data, var type, var seek, var size, var cb, var this_cb)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(file);
	if (((var*)__this)[-1]!=file___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"file.write\"\n");std__panic();
	}
	std__write(_this->_folder,name,data,type,seek,size,cb,this_cb);
	recursive--;
	return __return__;
}
var file__filesize(var __this, var name, var cb, var this_cb)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(file);
	if (((var*)__this)[-1]!=file___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"file.filesize\"\n");std__panic();
	}
	std__filesize(_this->_folder,name,cb,this_cb);
	recursive--;
	return __return__;
}
var file__scandir(var __this, var name, var cb, var this_cb)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(file);
	if (((var*)__this)[-1]!=file___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"file.scandir\"\n");std__panic();
	}
	std__scandir(_this->_folder,name,cb,this_cb);
	recursive--;
	return __return__;
}
var file__rmdir(var __this, var name, var cb, var this_cb)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(file);
	if (((var*)__this)[-1]!=file___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"file.rmdir\"\n");std__panic();
	}
	std__rmdir(_this->_folder,name,cb,this_cb);
	recursive--;
	return __return__;
}
var file__unlink(var __this, var name, var cb, var this_cb)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(file);
	if (((var*)__this)[-1]!=file___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"file.unlink\"\n");std__panic();
	}
	std__unlink(_this->_folder,name,cb,this_cb);
	recursive--;
	return __return__;
}
/* class hash */
struct hash {
	var _arr;
	var size;
};
var hash___new(var __this, var size_, var __parent)
{
	static var recursive = 0;
	var __return__ = 0;
	var i;
	MAKETHIS(hash);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"hash.new\"\n");std__panic();
	}
	_this->size=size_;
	_this->_arr=array__new(_this->size,__this);
	i=0;
	while (i<size_) {
		((var*)_this->_arr)[i]=0;
		i=i+1;
	}
	__return__ = __this;
	recursive--;
	return __return__;
}
var hash__new(var size_, var __parent)
{
	NEW(hash);
	return hash___new(__this, size_, __parent);
}
var hash___V_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var i;
	var next;
	var cur;
	MAKETHIS(hash);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"hash.dispose\"\n");std__panic();
	}
	i=0;
	while (i<_this->size) {
		cur=((var*)_this->_arr)[i];
		while (cur!=0) {
			next=((var*)cur)[hash__Cnext];
			std__delete(cur);
			cur=next;
		}
		((var*)_this->_arr)[i]=0;
		i=i+1;
	}
	std__delete(_this->_arr);
	std__free(__this);
	recursive--;
	return __return__;
}
var hash__add(var __this, var key, var value)
{
	static var recursive = 0;
	var __return__ = 0;
	var h;
	var hh;
	var cur;
	var old;
	var next;
	var prev;
	var ret;
	var cmp;
	MAKETHIS(hash);
	if (((var*)__this)[-1]!=hash___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"hash.add\"\n");std__panic();
	}
	h=string__get_hash(key);
	hh=h;
	h=h%_this->size;
	old=((var*)_this->_arr)[h];
	cur=0;
	if (old==0) {
		cur=array__new(4,__this);
		((var*)cur)[hash__Cnext]=0;
		((var*)_this->_arr)[h]=cur;
	}
	next=old;
	prev=0;
	ret=0;
	while (((cur==0))&&((next!=0))) {
		if ((((var*)next)[hash__Chash])==hh) {
			cmp=string__compare(key,((var*)next)[hash__Ckey]);
			if (cmp>0) {
				cur=array__new(4,__this);
				((var*)cur)[hash__Cnext]=next;
				if (prev==0) {
					((var*)_this->_arr)[h]=cur;
				} else {
					((var*)prev)[hash__Cnext]=cur;
				}
			} else if (cmp==0) {
				cur=next;
				ret=((var*)next)[hash__Cvalue];
			}
		} else if ((((var*)next)[hash__Chash])>hh) {
			cur=array__new(4,__this);
			((var*)cur)[hash__Cnext]=next;
			if (prev==0) {
				((var*)_this->_arr)[h]=cur;
			} else {
				((var*)prev)[hash__Cnext]=cur;
			}
		}
		prev=next;
		next=((var*)next)[hash__Cnext];
	}
	if (cur==0) {
		cur=array__new(4,__this);
		((var*)cur)[hash__Cnext]=0;
		if (prev==0) {
			((var*)_this->_arr)[h]=cur;
		} else {
			((var*)prev)[hash__Cnext]=cur;
		}
	}
	((var*)cur)[hash__Chash]=hh;
	((var*)cur)[hash__Ckey]=key;
	((var*)cur)[hash__Cvalue]=value;
	__return__ = ret;
	recursive--;
	return __return__;
}
var hash__get(var __this, var key)
{
	static var recursive = 0;
	var __return__ = 0;
	var h;
	var hh;
	var next;
	var cmp;
	MAKETHIS(hash);
	if (((var*)__this)[-1]!=hash___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"hash.get\"\n");std__panic();
	}
	h=string__get_hash(key);
	hh=h;
	h=h%_this->size;
	next=((var*)_this->_arr)[h];
	while (next!=0) {
		if ((((var*)next)[hash__Chash])==hh) {
			cmp=string__compare(key,((var*)next)[hash__Ckey]);
			if (cmp>0) {
				__return__ = 0;
	recursive--;
	return __return__;
			} else if (cmp==0) {
				__return__ = ((var*)next)[hash__Cvalue];
	recursive--;
	return __return__;
			}
		} else if ((((var*)next)[hash__Chash])>hh) {
			__return__ = 0;
	recursive--;
	return __return__;
		}
		next=((var*)next)[hash__Cnext];
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
/* class object */
struct object {
	var dummy;
};
var object___new(var __this, var __parent)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(object);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"object.new\"\n");std__panic();
	}
	__return__ = __this;
	recursive--;
	return __return__;
}
var object__new(var __parent)
{
	NEW(object);
	return object___new(__this, __parent);
}
var object___V_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(object);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"object.dispose\"\n");std__panic();
	}
	std__free(__this);
	recursive--;
	return __return__;
}
/* class worker */
struct worker {
	var status;
	var data;
	var lambda_this;
	var lambda;
	var type;
};
var worker___new(var __this, var lambda_this_, var lambda_, var status_, var data_, var type_, var __parent)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(worker);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"worker.new\"\n");std__panic();
	}
	_this->type=type_;
	_this->lambda_this=lambda_this_;
	_this->lambda=lambda_;
	_this->status=status_;
	if (_this->type!=1) {
		_this->data=std__move(data_);
	} else {
		_this->data=data_;
	}
	std__push_worker(__this);
	__return__ = __this;
	recursive--;
	return __return__;
}
var worker__new(var lambda_this_, var lambda_, var status_, var data_, var type_, var __parent)
{
	NEW(worker);
	return worker___new(__this, lambda_this_, lambda_, status_, data_, type_, __parent);
}
var worker___V_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(worker);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"worker.dispose\"\n");std__panic();
	}
	if (_this->data) {
		if (_this->type==1) {
			std__bytes_dispose(_this->data);
		} else {
			std__delete(_this->data);
		}
		_this->data=0;
	}
	std__free(__this);
	recursive--;
	return __return__;
}
var worker__process(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(worker);
	if (((var*)__this)[-1]!=worker___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"worker.process\"\n");std__panic();
	}
	__return__ = std__lambda(_this->lambda_this,_this->lambda,_this->status,_this->data,_this->type);
	recursive--;
	return __return__;
}
/* class std */
/* class string */
struct string {
	var _str;
	var size;
};
var string___new(var __this, var alloc, var __parent)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(string);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"string.new\"\n");std__panic();
	}
	_this->_str=0;
	std__stralloc(__this,alloc+1);
	_this->size=alloc;
	__return__ = __this;
	recursive--;
	return __return__;
}
var string__new(var alloc, var __parent)
{
	NEW(string);
	return string___new(__this, alloc, __parent);
}
var string___V_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(string);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"string.dispose\"\n");std__panic();
	}
	std__string_release(__this);
	recursive--;
	return __return__;
}
var string__get_buf(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(string);
	if (((var*)__this)[-1]!=string___DcidD&& ((var*)__this)[-1]!=-2&& ((var*)__this)[-1]!=0){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"string.get_buf\"\n");std__panic();
	}
	__return__ = _this->_str;
	recursive--;
	return __return__;
}
var string__set_buf(var __this, var b)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(string);
	if (((var*)__this)[-1]!=string___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"string.set_buf\"\n");std__panic();
	}
	_this->_str=b;
	recursive--;
	return __return__;
}
var string__get_size(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(string);
	if (((var*)__this)[-1]!=string___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"string.get_size\"\n");std__panic();
	}
	__return__ = _this->size;
	recursive--;
	return __return__;
}
var string__set_size(var __this, var ns)
{
	static var recursive = 0;
	var __return__ = 0;
	var ops;
	var b;
	MAKETHIS(string);
	if (((var*)__this)[-1]!=string___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"string.set_size\"\n");std__panic();
	}
	if (_this->size>ns) {
		recursive--;
	return __return__;
	}
	ops=string__new(ns+1,__this);
	std__append(ops,0,__this,0,_this->size);
	b=_this->_str;
	_this->_str=string__get_buf(ops);
	string__set_buf(ops,b);
	std__delete(ops);
	_this->size=ns;
	recursive--;
	return __return__;
}
var string__length(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var l;
	MAKETHIS(string);
	if (((var*)__this)[-1]!=string___DcidD&& ((var*)__this)[-1]!=-2&& ((var*)__this)[-1]!=0){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"string.length\"\n");std__panic();
	}
	l=std__strlen(__this);
	__return__ = l;
	recursive--;
	return __return__;
}
var string__set_int(var __this, var num)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(string);
	if (((var*)__this)[-1]!=string___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"string.set_int\"\n");std__panic();
	}
	__return__ = std__str_set_int(__this,_this->size,num);
	recursive--;
	return __return__;
}
var string__set(var __this, var src)
{
	static var recursive = 0;
	var __return__ = 0;
	var sl;
	MAKETHIS(string);
	if (((var*)__this)[-1]!=string___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"string.set\"\n");std__panic();
	}
	sl=std__strlen(src);
	if (_this->size<sl) {
		std__stralloc(__this,sl+1);
		_this->size=sl;
	}
	std__str_set_at(__this,0,'\0');
	std__append(__this,0,src,0,sl);
	recursive--;
	return __return__;
}
var string__add_char(var __this, var num)
{
	static var recursive = 0;
	var __return__ = 0;
	var sl;
	var tl;
	var ns;
	var i;
	MAKETHIS(string);
	if (((var*)__this)[-1]!=string___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"string.add_char\"\n");std__panic();
	}
	sl=6;
	tl=std__strlen(__this);
	ns=(sl+tl)+1;
	i=0;
	if (_this->size<=ns) {
		ns=ns+8;
		string__set_size(__this, ns);
	}
	i=tl;
	std__str_set_at(__this,i,num);
	i=i+1;
	std__str_set_at(__this,i,'\0');
	recursive--;
	return __return__;
}
var string__add(var __this, var src)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(string);
	if (((var*)__this)[-1]!=string___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"string.add\"\n");std__panic();
	}
	string__add_at(__this, std__strlen(__this),src);
	recursive--;
	return __return__;
}
var string__add_at(var __this, var tl, var src)
{
	static var recursive = 0;
	var __return__ = 0;
	var sl;
	var ns;
	MAKETHIS(string);
	if (((var*)__this)[-1]!=string___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"string.add_at\"\n");std__panic();
	}
	sl=std__strlen(src);
	ns=(sl+tl)+1;
	if (ns>=_this->size) {
		string__set_size(__this, ns*2);
	}
	std__append(__this,tl,src,0,ns);
	__return__ = sl+tl;
	recursive--;
	return __return__;
}
var string__indexof(var __this, var start_pos, var needle)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(string);
	if (((var*)__this)[-1]!=string___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"string.indexof\"\n");std__panic();
	}
	__return__ = std__strindex(__this,start_pos,needle);
	recursive--;
	return __return__;
}
var string__substr(var __this, var start_pos, var length_, var result)
{
	static var recursive = 0;
	var __return__ = 0;
	var len;
	MAKETHIS(string);
	if (((var*)__this)[-1]!=string___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"string.substr\"\n");std__panic();
	}
	len=std__strlen(__this);
	if (start_pos<0) {
		start_pos=start_pos+len;
	}
	if (start_pos<0) {
		start_pos=0;
	}
	if (length_<0) {
		length_=(len+length_)-start_pos;
	} else if (length_==0) {
		length_=len;
	}
	if (((start_pos>=len))||((length_<1))) {
		string__set(result,(var)(__string_string2+ 2));
		recursive--;
	return __return__;
	}
	string__set_size(result,length_+1);
	std__str_set_at(result,0,'\0');
	std__append(result,0,__this,start_pos,length_);
	recursive--;
	return __return__;
}
var string__to_string(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var str;
	MAKETHIS(string);
	if (((var*)__this)[-1]!=string___DcidD&& ((var*)__this)[-1]!=-2&& ((var*)__this)[-1]!=0){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"string.to_string\"\n");std__panic();
	}
	str=string__new((string__length(__this))+1,__this);
	string__set(str,__this);
	__return__ = str;
	recursive--;
	return __return__;
}
var string__to_int(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(string);
	if (((var*)__this)[-1]!=string___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"string.to_int\"\n");std__panic();
	}
	__return__ = std__str_toint(__this);
	recursive--;
	return __return__;
}
var string__compare(var __this, var other)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(string);
	if (((var*)__this)[-1]!=string___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"string.compare\"\n");std__panic();
	}
	__return__ = std__strcmp(__this,other);
	recursive--;
	return __return__;
}
var string__get_hash(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(string);
	if (((var*)__this)[-1]!=string___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"string.get_hash\"\n");std__panic();
	}
	__return__ = std__strhash(__this);
	recursive--;
	return __return__;
}
var string__get_at(var __this, var at)
{
	static var recursive = 0;
	var __return__ = 0;
	var l;
	MAKETHIS(string);
	if (((var*)__this)[-1]!=string___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"string.get_at\"\n");std__panic();
	}
	l=_this->size;
	if (l<1) {
		l=std__strlen(__this);
	}
	if (((at<l))&&((at>=0))) {
		__return__ = std__str_get_at(__this,at);
	recursive--;
	return __return__;
	}
	__return__ = '\0';
	recursive--;
	return __return__;
}
var string__set_at(var __this, var at, var v)
{
	static var recursive = 0;
	var __return__ = 0;
	var l;
	MAKETHIS(string);
	if (((var*)__this)[-1]!=string___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"string.set_at\"\n");std__panic();
	}
	l=_this->size;
	if (l<1) {
		l=std__strlen(__this);
	}
	if (((at<l))&&((at>=0))) {
		std__str_set_at(__this,at,v);
	}
	recursive--;
	return __return__;
}
/* class Aclass */
struct Aclass {
	var tok;
	var next;
	var prep_kind;
	var prep_type;
	var prep_type_id;
	var prep_name;
	var implements;
	var members;
	var member;
	var field_index;
	var lambda_stack;
	var nb_lambda;
	var statement;
	var stm_stack;
	var expression;
	var cur_expr;
	var expr_id;
	var garbage_pool;
};
var Aclass___new(var __this, var token, var __parent)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.new\"\n");std__panic();
	}
	_this->tok=token;
	_this->next=0;
	_this->members=buffer__new(256,1,__this);
	_this->implements=buffer__new(1,0,__this);
	_this->garbage_pool=buffer__new(100,1,__this);
	_this->field_index=-(1);
	_this->statement=0;
	_this->stm_stack=buffer__new(2,0,__this);
	_this->lambda_stack=buffer__new(2,0,__this);
	_this->nb_lambda=0;
	_this->expression=0;
	_this->prep_type_id=0;
	_this->prep_name=0;
	__return__ = __this;
	recursive--;
	return __return__;
}
var Aclass__new(var token, var __parent)
{
	NEW(Aclass);
	return Aclass___new(__this, token, __parent);
}
var Aclass___V_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.dispose\"\n");std__panic();
	}
	if (_this->next!=0) {
		std__delayed_delete(_this->next);
	}
	_this->next=0;
	Aclass__delayed_dispose(__this);
	recursive--;
	return __return__;
}
var Aclass___V_delayed_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.delayed_dispose\"\n");std__panic();
	}
	if (_this->next!=0) {
		std__delayed_delete(_this->next);
	}
	std__delete(_this->tok);
	std__delete(_this->members);
	std__delete(_this->implements);
	std__delete(_this->statement);
	std__delete(_this->stm_stack);
	std__delete(_this->lambda_stack);
	std__delete(_this->expression);
	std__delete(_this->garbage_pool);
	std__free(__this);
	recursive--;
	return __return__;
}
var Aclass__error(var __this, var err)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.error\"\n");std__panic();
	}
	console__log(err);
	std__exit(-(1));
	recursive--;
	return __return__;
}
var Aclass__get_implements(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.get_implements\"\n");std__panic();
	}
	__return__ = _this->implements;
	recursive--;
	return __return__;
}
var Aclass__get_nb_lambda(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.get_nb_lambda\"\n");std__panic();
	}
	__return__ = _this->nb_lambda;
	recursive--;
	return __return__;
}
var Aclass__add_implements(var __this, var x)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.add_implements\"\n");std__panic();
	}
	buffer__push(_this->implements,x);
	recursive--;
	return __return__;
}
var Aclass__get_members(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.get_members\"\n");std__panic();
	}
	__return__ = _this->members;
	recursive--;
	return __return__;
}
var Aclass__get_nb_fields(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.get_nb_fields\"\n");std__panic();
	}
	__return__ = _this->field_index+1;
	recursive--;
	return __return__;
}
var Aclass__set_next(var __this, var n)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.set_next\"\n");std__panic();
	}
	_this->next=std__move(n);
	recursive--;
	return __return__;
}
var Aclass__get_next(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.get_next\"\n");std__panic();
	}
	__return__ = _this->next;
	recursive--;
	return __return__;
}
var Aclass__get_name(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.get_name\"\n");std__panic();
	}
	__return__ = _this->tok;
	recursive--;
	return __return__;
}
var Aclass__pad(var __this, var p)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.pad\"\n");std__panic();
	}
	while (p>0) {
		p=p-1;
		console__log_str((var)(__string_Aclass3+ 2));
	}
	recursive--;
	return __return__;
}
var Aclass__prepare_kind(var __this, var kind_)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.prepare_kind\"\n");std__panic();
	}
	_this->prep_kind=kind_;
	_this->prep_type=0;
	_this->prep_type_id=0;
	_this->prep_name=0;
	recursive--;
	return __return__;
}
var Aclass__prepare_type(var __this, var type_)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.prepare_type\"\n");std__panic();
	}
	_this->prep_type=type_;
	recursive--;
	return __return__;
}
var Aclass__prepare_type_identifier(var __this, var id_)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.prepare_type_identifier\"\n");std__panic();
	}
	_this->prep_type=Aclass__Cidentifier;
	_this->prep_type_id=id_;
	recursive--;
	return __return__;
}
var Aclass__prepare_set_name(var __this, var id_)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.prepare_set_name\"\n");std__panic();
	}
	_this->prep_name=id_;
	recursive--;
	return __return__;
}
var Aclass__valid_member_name(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.valid_member_name\"\n");std__panic();
	}
	_this->member=Amember__new(_this->prep_kind,_this->prep_type,_this->prep_type_id,_this->prep_name,__this);
	
	switch (_this->prep_kind) {
	case Aclass__Cfield: 
		_this->field_index=_this->field_index+1;
		Amember__set_index(_this->member,_this->field_index);
		break;
	case Aclass__Cstatic: 
		break;
	case Aclass__Cconst: 
		break;
	default:
		break;
	} 
	_this->prep_kind=0;
	_this->prep_type=0;
	_this->prep_type_id=0;
	_this->prep_name=0;
	buffer__push(_this->members,_this->member);
	recursive--;
	return __return__;
}
var Aclass__valid_param(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.valid_param\"\n");std__panic();
	}
	Amember__add_param(_this->member,_this->prep_kind,_this->prep_type,_this->prep_type_id,_this->prep_name);
	recursive--;
	return __return__;
}
var Aclass__valid_var(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.valid_var\"\n");std__panic();
	}
	Amember__add_var(_this->member,_this->prep_kind,_this->prep_type,_this->prep_type_id,_this->prep_name);
	recursive--;
	return __return__;
}
var Aclass__begin_else(var __this, var type_)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.begin_else\"\n");std__panic();
	}
	Astatement__add_else(_this->statement,type_);
	recursive--;
	return __return__;
}
var Aclass__begin_stm(var __this, var type_, var orig)
{
	static var recursive = 0;
	var __return__ = 0;
	var st;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.begin_stm\"\n");std__panic();
	}
	buffer__push(_this->stm_stack,_this->statement);
	st=Astatement__new(type_,_this->statement,buffer__length(_this->stm_stack),__this);
	if (_this->statement==0) {
		Amember__add_statement(_this->member,st);
	} else {
		Astatement__add_statement(_this->statement,st);
	}
	if (type_==(Aclass__Cdo)) {
		Aclass__begin_expr(__this, orig);
	} else if (type_==(Aclass__Clet)) {
		Aclass__begin_expr(__this, orig);
	}
	_this->statement=st;
	recursive--;
	return __return__;
}
var Aclass__finish_stm(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.finish_stm\"\n");std__panic();
	}
	std__delete(_this->statement);
	_this->statement=buffer__pop(_this->stm_stack);
	recursive--;
	return __return__;
}
var Aclass__finish_const(var __this, var initialiser1)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.finish_const\"\n");std__panic();
	}
	Aclass__valid_member_name(__this);
	Amember__set_initial_value(_this->member,initialiser1);
	recursive--;
	return __return__;
}
var Aclass__begin_lambda(var __this, var id1)
{
	static var recursive = 0;
	var __return__ = 0;
	var nam;
	var n;
	var ex;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.begin_lambda\"\n");std__panic();
	}
	nam=string__new(10,__this);
	string__set_int(nam,_this->nb_lambda);
	_this->nb_lambda=_this->nb_lambda+1;
	n=Atoken__new(Aclass__Clambda,nam,Atoken__get_line(id1),Atoken__get_file(id1),__this);
	Atoken__take(n);
	buffer__push(_this->garbage_pool,n);
	ex=Aexpr__new(Aclass__Clambda,900,Aclass__Clr,__this);
	Aexpr__set_value(ex,nam);
	Aexpr__set_origin(ex,id1);
	Aexpr__add(_this->cur_expr,ex);
	buffer__push(_this->lambda_stack,_this->stm_stack);
	buffer__push(_this->lambda_stack,_this->member);
	buffer__push(_this->lambda_stack,_this->cur_expr);
	buffer__push(_this->lambda_stack,_this->statement);
	buffer__push(_this->lambda_stack,_this->expression);
	_this->expression=0;
	_this->cur_expr=0;
	_this->statement=0;
	_this->stm_stack=buffer__new(2,0,__this);
	_this->member=Amember__new(Aclass__Casync,Aclass__Cvoid,0,n,__this);
	buffer__push(_this->members,_this->member);
	recursive--;
	return __return__;
}
var Aclass__finish_lambda(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.finish_lambda\"\n");std__panic();
	}
	std__delete(_this->stm_stack);
	_this->expression=buffer__pop(_this->lambda_stack);
	_this->statement=buffer__pop(_this->lambda_stack);
	_this->cur_expr=buffer__pop(_this->lambda_stack);
	_this->member=buffer__pop(_this->lambda_stack);
	_this->stm_stack=buffer__pop(_this->lambda_stack);
	recursive--;
	return __return__;
}
var Aclass__finish_subroutine(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.finish_subroutine\"\n");std__panic();
	}
	while ((buffer__length(_this->stm_stack))>0) {
		std__maybe_delete(buffer__pop(_this->stm_stack),_this->stm_stack);
	}
	recursive--;
	return __return__;
}
var Aclass__begin_expr(var __this, var orig)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.begin_expr\"\n");std__panic();
	}
	_this->expression=Aexpr__new(Aclass__Croot,0,0,__this);
	Aexpr__set_origin(_this->expression,orig);
	_this->cur_expr=_this->expression;
	recursive--;
	return __return__;
}
var Aclass__finish_expr(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.finish_expr\"\n");std__panic();
	}
	if (_this->expression!=0) {
		Astatement__set_expression(_this->statement,_this->expression);
	}
	_this->expression=0;
	_this->cur_expr=0;
	recursive--;
	return __return__;
}
var Aclass__expr_op(var __this, var op_, var orig)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.expr_op\"\n");std__panic();
	}
	ex=0;
	
	switch (op_) {
	case Aclass__Croot: 
		break;
	case Aclass__Cassign: 
		ex=Aexpr__new(op_,30,Aclass__Crl,__this);
		break;
	case Aclass__Cequal: 
		ex=Aexpr__new(op_,100,Aclass__Clr,__this);
		break;
	case Aclass__Cnotequal: 
		ex=Aexpr__new(op_,100,Aclass__Crl,__this);
		break;
	case Aclass__Clargerequal: 
		ex=Aexpr__new(op_,110,Aclass__Clr,__this);
		break;
	case Aclass__Clesserequal: 
		ex=Aexpr__new(op_,110,Aclass__Clr,__this);
		break;
	case Aclass__Clarger: 
		ex=Aexpr__new(op_,110,Aclass__Clr,__this);
		break;
	case Aclass__Clesser: 
		ex=Aexpr__new(op_,110,Aclass__Clr,__this);
		break;
	case Aclass__Clogicaland: 
		ex=Aexpr__new(op_,60,Aclass__Clr,__this);
		break;
	case Aclass__Clogicalor: 
		ex=Aexpr__new(op_,50,Aclass__Clr,__this);
		break;
	case Aclass__Cadd: 
		ex=Aexpr__new(op_,130,Aclass__Clr,__this);
		break;
	case Aclass__Csub: 
		ex=Aexpr__new(op_,130,Aclass__Clr,__this);
		break;
	case Aclass__Cmult: 
		ex=Aexpr__new(op_,140,Aclass__Clr,__this);
		break;
	case Aclass__Cdiv: 
		ex=Aexpr__new(op_,140,Aclass__Clr,__this);
		break;
	case Aclass__Cmodulo: 
		ex=Aexpr__new(op_,140,Aclass__Clr,__this);
		break;
	case Aclass__Clogicalnot: 
		ex=Aexpr__new(op_,160,Aclass__Crl,__this);
		break;
	case Aclass__Cunaryplus: 
		ex=Aexpr__new(op_,160,Aclass__Crl,__this);
		break;
	case Aclass__Cunaryminus: 
		ex=Aexpr__new(op_,160,Aclass__Crl,__this);
		break;
	case Aclass__Cdot: 
		ex=Aexpr__new(op_,170,Aclass__Clr,__this);
		break;
	case Aclass__Cconstant: 
		ex=Aexpr__new(op_,170,Aclass__Clr,__this);
		break;
	case Aclass__Ccall: 
		ex=Aexpr__new(op_,170,Aclass__Clr,__this);
		break;
	case Aclass__Cindex: 
		ex=Aexpr__new(op_,170,Aclass__Clr,__this);
		break;
	case Aclass__Ccomma: 
		ex=Aexpr__new(op_,10,Aclass__Clr,__this);
		break;
	default:
		console__log((var)(__string_Aclass4+ 2));
		std__exit(-(1));
		break;
	} 
	if (ex!=0) {
		Aexpr__set_origin(ex,orig);
		_this->cur_expr=Aexpr__add(_this->cur_expr,ex);
	}
	recursive--;
	return __return__;
}
var Aclass__expr_open_par(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.expr_open_par\"\n");std__panic();
	}
	ex=Aexpr__new(Aclass__Cparenthesis,1000,Aclass__Clr,__this);
	_this->cur_expr=Aexpr__add(_this->cur_expr,ex);
	Aexpr__set_precedence(ex,1);
	recursive--;
	return __return__;
}
var Aclass__expr_in_par(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.expr_in_par\"\n");std__panic();
	}
	ex=Aexpr__close(_this->cur_expr,Aclass__Cparenthesis);
	if (ex==0) {
		__return__ = 0;
	recursive--;
	return __return__;
	}
	__return__ = 1;
	recursive--;
	return __return__;
}
var Aclass__expr_close_par(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.expr_close_par\"\n");std__panic();
	}
	_this->cur_expr=Aexpr__close(_this->cur_expr,Aclass__Cparenthesis);
	if (_this->cur_expr==0) {
		Aclass__error(__this, (var)(__string_Aclass5+ 2));
	} else {
		Aexpr__set_precedence(_this->cur_expr,1000);
	}
	recursive--;
	return __return__;
}
var Aclass__expr_open_index(var __this, var id_, var orig)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.expr_open_index\"\n");std__panic();
	}
	Aclass__expr_var(__this, id_,orig);
	Aclass__expr_op(__this, Aclass__Cindex,orig);
	ex=Aexpr__new(Aclass__Cexpr,1000,Aclass__Clr,__this);
	_this->cur_expr=Aexpr__add(_this->cur_expr,ex);
	Aexpr__set_precedence(ex,2);
	recursive--;
	return __return__;
}
var Aclass__expr_close_index(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.expr_close_index\"\n");std__panic();
	}
	_this->cur_expr=Aexpr__close(_this->cur_expr,Aclass__Cindex);
	if (_this->cur_expr==0) {
		Aclass__error(__this, (var)(__string_Aclass6+ 2));
	} else {
		Aexpr__set_precedence(_this->cur_expr,1000);
	}
	recursive--;
	return __return__;
}
var Aclass__expr_begin_sub_call(var __this, var class_, var name_, var orig)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.expr_begin_sub_call\"\n");std__panic();
	}
	if (class_!=0) {
		Aclass__expr_var(__this, class_,orig);
		Aclass__expr_op(__this, Aclass__Cdot,orig);
		Aclass__expr_var(__this, name_,orig);
		Aclass__expr_op(__this, Aclass__Ccall,orig);
	} else {
		Aclass__expr_var(__this, name_,orig);
		Aclass__expr_op(__this, Aclass__Ccall,orig);
	}
	ex=Aexpr__new(Aclass__Cexpr,1000,Aclass__Clr,__this);
	_this->cur_expr=Aexpr__add(_this->cur_expr,ex);
	Aexpr__set_precedence(ex,2);
	Aexpr__set_origin(ex,orig);
	recursive--;
	return __return__;
}
var Aclass__expr_next_expr(var __this, var orig)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.expr_next_expr\"\n");std__panic();
	}
	Aclass__expr_op(__this, Aclass__Ccomma,orig);
	recursive--;
	return __return__;
}
var Aclass__expr_finish_sub_call(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.expr_finish_sub_call\"\n");std__panic();
	}
	_this->cur_expr=Aexpr__close(_this->cur_expr,Aclass__Ccall);
	if (_this->cur_expr==0) {
		Aclass__error(__this, (var)(__string_Aclass7+ 2));
	} else {
		Aexpr__set_precedence(_this->cur_expr,1000);
	}
	recursive--;
	return __return__;
}
var Aclass__expr_term(var __this, var term_, var orig)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.expr_term\"\n");std__panic();
	}
	ex=Aexpr__new(term_,1000,Aclass__Clr,__this);
	_this->cur_expr=Aexpr__add(_this->cur_expr,ex);
	Aexpr__set_origin(ex,orig);
	recursive--;
	return __return__;
}
var Aclass__expr_var(var __this, var name_, var orig)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.expr_var\"\n");std__panic();
	}
	ex=Aexpr__new(Aclass__Cvar,900,0,__this);
	_this->cur_expr=Aexpr__add(_this->cur_expr,ex);
	Aexpr__set_value(ex,name_);
	Aexpr__set_origin(ex,orig);
	recursive--;
	return __return__;
}
var Aclass__expr_int_const(var __this, var value_, var orig)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.expr_int_const\"\n");std__panic();
	}
	ex=Aexpr__new(Aclass__Cint_const,900,0,__this);
	_this->cur_expr=Aexpr__add(_this->cur_expr,ex);
	Aexpr__set_value(ex,value_);
	Aexpr__set_origin(ex,orig);
	recursive--;
	return __return__;
}
var Aclass__expr_char_const(var __this, var value_, var orig)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.expr_char_const\"\n");std__panic();
	}
	ex=Aexpr__new(Aclass__Cchar_const,900,0,__this);
	_this->cur_expr=Aexpr__add(_this->cur_expr,ex);
	Aexpr__set_value(ex,value_);
	Aexpr__set_origin(ex,orig);
	recursive--;
	return __return__;
}
var Aclass__expr_str_const(var __this, var value_, var orig)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.expr_str_const\"\n");std__panic();
	}
	ex=Aexpr__new(Aclass__Cstr_const,900,0,__this);
	_this->cur_expr=Aexpr__add(_this->cur_expr,ex);
	Aexpr__set_value(ex,value_);
	Aexpr__set_origin(ex,orig);
	recursive--;
	return __return__;
}
var Aclass__expr_constant(var __this, var class_name_, var const_name_, var orig)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex;
	MAKETHIS(Aclass);
	if (((var*)__this)[-1]!=Aclass___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aclass.expr_constant\"\n");std__panic();
	}
	Aclass__expr_var(__this, class_name_,orig);
	Aclass__expr_op(__this, Aclass__Cconstant,orig);
	ex=Aexpr__new(Aclass__Cconst,900,0,__this);
	Aexpr__set_origin(ex,orig);
	_this->cur_expr=Aexpr__add(_this->cur_expr,ex);
	Aexpr__set_value(ex,const_name_);
	recursive--;
	return __return__;
}
/* class Aemmiter */
struct Aemmiter {
	var side;
	var clas;
	var cur_memb;
};
var Aemmiter___new(var __this, var side1, var __parent)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmiter);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.new\"\n");std__panic();
	}
	_this->side=side1;
	_this->clas=0;
	_this->cur_memb=0;
	__return__ = __this;
	recursive--;
	return __return__;
}
var Aemmiter__new(var side1, var __parent)
{
	NEW(Aemmiter);
	return Aemmiter___new(__this, side1, __parent);
}
var Aemmiter___V_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmiter);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.dispose\"\n");std__panic();
	}
	std__free(__this);
	recursive--;
	return __return__;
}
var Aemmiter__set_class(var __this, var class1)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmiter);
	if (((var*)__this)[-1]!=Aemmiter___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.set_class\"\n");std__panic();
	}
	_this->clas=class1;
	recursive--;
	return __return__;
}
var Aemmiter__set_member(var __this, var mb)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmiter);
	if (((var*)__this)[-1]!=Aemmiter___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.set_member\"\n");std__panic();
	}
	_this->cur_memb=mb;
	recursive--;
	return __return__;
}
var Aemmiter___V_emmit(var __this, var par)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmiter);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.emmit\"\n");std__panic();
	}
	__return__ = Aemmiter__emmit(_this->side,par);
	recursive--;
	return __return__;
}
var Aemmiter___V_get_head(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmiter);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.get_head\"\n");std__panic();
	}
	__return__ = Aemmiter__get_head(_this->side);
	recursive--;
	return __return__;
}
var Aemmiter___V_get_data(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmiter);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.get_data\"\n");std__panic();
	}
	__return__ = Aemmiter__get_data(_this->side);
	recursive--;
	return __return__;
}
var Aemmiter___V_get_mid(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmiter);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.get_mid\"\n");std__panic();
	}
	__return__ = Aemmiter__get_mid(_this->side);
	recursive--;
	return __return__;
}
var Aemmiter__find_param(var __this, var stri)
{
	static var recursive = 0;
	var __return__ = 0;
	var v;
	var i;
	var vars;
	var tok;
	var s;
	MAKETHIS(Aemmiter);
	if (((var*)__this)[-1]!=Aemmiter___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.find_param\"\n");std__panic();
	}
	vars=Amember__get_params(_this->cur_memb);
	i=0;
	if (vars!=0) {
		i=buffer__length(vars);
	}
	while (i>0) {
		i=i-1;
		v=buffer__get_at(vars,i);
		if (v!=0) {
			tok=Amember__get_name(v);
			s=Atoken__get_data(tok);
			if (s!=0) {
				if ((string__compare(stri,s))==0) {
					__return__ = v;
	recursive--;
	return __return__;
				}
			}
		}
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var Aemmiter__find_field(var __this, var stri)
{
	static var recursive = 0;
	var __return__ = 0;
	var v;
	var i;
	var vars;
	var tok;
	var s;
	MAKETHIS(Aemmiter);
	if (((var*)__this)[-1]!=Aemmiter___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.find_field\"\n");std__panic();
	}
	i=0;
	vars=Aclass__get_members(_this->clas);
	if (vars!=0) {
		i=buffer__length(vars);
	}
	while (i>0) {
		i=i-1;
		v=buffer__get_at(vars,i);
		if (v!=0) {
			tok=Amember__get_name(v);
			s=Atoken__get_data(tok);
			if (((s!=0))&&(((Amember__get_kind(v))==(Aclass__Cfield)))) {
				if ((string__compare(stri,s))==0) {
					__return__ = v;
	recursive--;
	return __return__;
				}
			}
		}
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var Aemmiter__find_method(var __this, var stri)
{
	static var recursive = 0;
	var __return__ = 0;
	var v;
	var i;
	var vars;
	var tok;
	var s;
	var k;
	MAKETHIS(Aemmiter);
	if (((var*)__this)[-1]!=Aemmiter___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.find_method\"\n");std__panic();
	}
	i=0;
	vars=Aclass__get_members(_this->clas);
	if (vars!=0) {
		i=buffer__length(vars);
	}
	while (i>0) {
		i=i-1;
		v=buffer__get_at(vars,i);
		if (v!=0) {
			tok=Amember__get_name(v);
			k=Amember__get_kind(v);
			s=Atoken__get_data(tok);
			if (((s!=0))&&((((k==(Aclass__Cmethod))||(k==(Aclass__Cvirtual)))||(k==(Aclass__Casync))))) {
				if ((string__compare(stri,s))==0) {
					__return__ = v;
	recursive--;
	return __return__;
				}
			}
		}
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var Aemmiter__find_static(var __this, var stri)
{
	static var recursive = 0;
	var __return__ = 0;
	var v;
	var i;
	var vars;
	var tok;
	var s;
	var k;
	MAKETHIS(Aemmiter);
	if (((var*)__this)[-1]!=Aemmiter___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.find_static\"\n");std__panic();
	}
	i=0;
	vars=Aclass__get_members(_this->clas);
	if (vars!=0) {
		i=buffer__length(vars);
	}
	while (i>0) {
		i=i-1;
		v=buffer__get_at(vars,i);
		if (v!=0) {
			tok=Amember__get_name(v);
			k=Amember__get_kind(v);
			s=Atoken__get_data(tok);
			if (((s!=0))&&((k==(Aclass__Cstatic)))) {
				if ((string__compare(stri,s))==0) {
					__return__ = v;
	recursive--;
	return __return__;
				}
			}
		}
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var Aemmiter__find_local(var __this, var stri)
{
	static var recursive = 0;
	var __return__ = 0;
	var v;
	var i;
	var vars;
	var tok;
	var s;
	MAKETHIS(Aemmiter);
	if (((var*)__this)[-1]!=Aemmiter___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.find_local\"\n");std__panic();
	}
	vars=Amember__get_vars(_this->cur_memb);
	i=0;
	if (vars!=0) {
		i=buffer__length(vars);
	}
	while (i>0) {
		i=i-1;
		v=buffer__get_at(vars,i);
		if (v!=0) {
			tok=Amember__get_name(v);
			s=Atoken__get_data(tok);
			if ((s!=0)) {
				if ((string__compare(stri,s))==0) {
					__return__ = v;
	recursive--;
	return __return__;
				}
			}
		}
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var Aemmiter__find_variable(var __this, var stri)
{
	static var recursive = 0;
	var __return__ = 0;
	var v;
	MAKETHIS(Aemmiter);
	if (((var*)__this)[-1]!=Aemmiter___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.find_variable\"\n");std__panic();
	}
	v=Aemmiter__find_local(__this, stri);
	if (v==0) {
		v=Aemmiter__find_param(__this, stri);
	}
	if (v==0) {
		v=Aemmiter__find_field(__this, stri);
	}
	if (v==0) {
		v=Aemmiter__find_static(__this, stri);
	}
	__return__ = v;
	recursive--;
	return __return__;
}
var Aemmiter__is_switch(var __this, var st, var vari)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex;
	var sv;
	MAKETHIS(Aemmiter);
	if (((var*)__this)[-1]!=Aemmiter___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.is_switch\"\n");std__panic();
	}
	ex=Astatement__get_expression(st);
	if (ex==0) {
		__return__ = 0;
	recursive--;
	return __return__;
	}
	sv=Aexpr__is_equal_comp(ex,vari);
	__return__ = sv;
	recursive--;
	return __return__;
}
var Aemmiter__get_switch_expr(var __this, var st)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex;
	MAKETHIS(Aemmiter);
	if (((var*)__this)[-1]!=Aemmiter___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.get_switch_expr\"\n");std__panic();
	}
	ex=Astatement__get_expression(st);
	ex=Aexpr__get_switch_expr(ex);
	__return__ = ex;
	recursive--;
	return __return__;
}
var Aemmiter___V_gen_virtuals(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmiter);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.gen_virtuals\"\n");std__panic();
	}
	recursive--;
	return __return__;
}
var Aemmiter___V_expr_process(var __this, var expr)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmiter);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.expr_process\"\n");std__panic();
	}
	recursive--;
	return __return__;
}
var Aemmiter__expr_gen(var __this, var expr)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex;
	var ex1;
	var stack;
	MAKETHIS(Aemmiter);
	if (((var*)__this)[-1]!=Aemmiter___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.expr_gen\"\n");std__panic();
	}
	stack=buffer__new(4,0,__this);
	ex=Aexpr__get_right(expr);
	ex=expr;
	Aexpr__set_flags(ex,0);
	buffer__push(stack,ex);
	while ((buffer__length(stack))>0) {
		ex=buffer__get_last(stack);
		if ((Aexpr__get_flags(ex))!=0) {
			ex=buffer__pop(stack);
			Aemmiter__expr_process(_this->side,ex);
		} else {
			ex1=ex;
			Aexpr__set_flags(ex,1);
			ex=Aexpr__get_right(ex);
			if (ex!=0) {
				Aexpr__set_flags(ex,0);
				buffer__push(stack,ex);
			}
			ex=Aexpr__get_left(ex1);
			if (ex!=0) {
				Aexpr__set_flags(ex,0);
				buffer__push(stack,ex);
			}
		}
	}
	std__delete(stack);
	recursive--;
	return __return__;
}
var Aemmiter__error(var __this, var t, var e)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmiter);
	if (((var*)__this)[-1]!=Aemmiter___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.error\"\n");std__panic();
	}
	if (t!=0) {
		console__log_str(Atoken__get_file(t));
		console__log_str((var)(__string_Aemmiter8+ 2));
		console__log_int(Atoken__get_line(t));
		console__log_str((var)(__string_Aemmiter9+ 2));
		console__log_str(Atoken__get_data(t));
		console__log_str((var)(__string_Aemmiter10+ 2));
	}
	console__log(e);
	Aemmiter__dump(__this);
	std__exit(-(1));
	recursive--;
	return __return__;
}
var Aemmiter__dump(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmiter);
	if (((var*)__this)[-1]!=Aemmiter___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmiter.dump\"\n");std__panic();
	}
	recursive--;
	return __return__;
}
/* class Aemmitc */
struct Aemmitc {
	var _data;
	var _datal;
	var _head;
	var _headl;
	var _mid;
	var _str;
	var clas;
	var class_name;
	var cur_memb;
	var _proc;
	var _stk;
	var _expr_stk;
	var token1;
	var token2;
	var pass;
	var _virtuals;
	var _lambdas;
	var class_id;
	var string_id;
	var debug;
	var string_pool;
	var side;
};
var Aemmitc___new(var __this, var debug1, var __parent)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.new\"\n");std__panic();
	}
	_this->debug=debug1;
	_this->side=Aemmiter__new(__this,__this);
	_this->_proc=buffer__new(100,0,__this);
	_this->_stk=buffer__new(100,0,__this);
	_this->_expr_stk=buffer__new(100,0,__this);
	_this->_data=string__new(10000,__this);
	_this->_head=string__new(10000,__this);
	_this->_mid=string__new(10000,__this);
	_this->_str=string__new(10000,__this);
	_this->_virtuals=buffer__new(1024,1,__this);
	_this->_lambdas=buffer__new(1024,1,__this);
	_this->token1=0;
	_this->token2=0;
	_this->class_id=10;
	_this->string_id=0;
	_this->string_pool=buffer__new(100,1,__this);
	__return__ = __this;
	recursive--;
	return __return__;
}
var Aemmitc__new(var debug1, var __parent)
{
	NEW(Aemmitc);
	return Aemmitc___new(__this, debug1, __parent);
}
var Aemmitc___V_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.dispose\"\n");std__panic();
	}
	std__delete(_this->side);
	std__delete(_this->_proc);
	std__delete(_this->_stk);
	std__delete(_this->_data);
	std__delete(_this->_head);
	std__delete(_this->_mid);
	std__delete(_this->_str);
	std__delete(_this->_virtuals);
	std__delete(_this->_lambdas);
	std__delete(_this->_expr_stk);
	std__delete(_this->string_pool);
	std__free(__this);
	recursive--;
	return __return__;
}
var Aemmitc___V_emmit(var __this, var par)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.emmit\"\n");std__panic();
	}
	_this->clas=Aparser__get_next(par);
	while (_this->clas!=0) {
		Aemmiter__set_class(_this->side,_this->clas);
		Aemmitc__gen_class(__this);
		_this->clas=Aclass__get_next(_this->clas);
	}
	__return__ = 1;
	recursive--;
	return __return__;
}
var Aemmitc___V_get_head(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.get_head\"\n");std__panic();
	}
	__return__ = _this->_head;
	recursive--;
	return __return__;
}
var Aemmitc___V_get_data(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.get_data\"\n");std__panic();
	}
	__return__ = _this->_data;
	recursive--;
	return __return__;
}
var Aemmitc___V_get_mid(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var l;
	MAKETHIS(Aemmitc);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.get_mid\"\n");std__panic();
	}
	l=string__length(_this->_mid);
	l=string__add_at(_this->_mid,l,(var)(__string_Aemmitc11+ 2));
	l=string__add_at(_this->_mid,l,_this->_str);
	std__delete(_this->_str);
	_this->_str=string__new(1,__this);
	l=string__add_at(_this->_mid,l,(var)(__string_Aemmitc12+ 2));
	__return__ = _this->_mid;
	recursive--;
	return __return__;
}
var Aemmitc__add_to_data(var __this, var s)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.add_to_data\"\n");std__panic();
	}
	_this->_datal=string__add_at(_this->_data,_this->_datal,s);
	recursive--;
	return __return__;
}
var Aemmitc__add_to_head(var __this, var s)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.add_to_head\"\n");std__panic();
	}
	_this->_headl=string__add_at(_this->_head,_this->_headl,s);
	recursive--;
	return __return__;
}
var Aemmitc__gen_class(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var to;
	var s;
	var mem;
	var i;
	var l;
	var m;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.gen_class\"\n");std__panic();
	}
	to=Aclass__get_name(_this->clas);
	_this->class_name=Atoken__get_data(to);
	_this->_datal=string__length(_this->_data);
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc13+ 2));
	Aemmitc__add_to_data(__this, _this->class_name);
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc14+ 2));
	s=string__new(4,__this);
	string__set_int(s,Aclass__get_nb_fields(_this->clas));
	_this->_headl=string__length(_this->_head);
	Aemmitc__add_to_head(__this, (var)(__string_Aemmitc15+ 2));
	Aemmitc__add_to_head(__this, _this->class_name);
	Aemmitc__add_to_head(__this, (var)(__string_Aemmitc16+ 2));
	Aemmitc__add_to_head(__this, s);
	Aemmitc__add_to_head(__this, (var)(__string_Aemmitc17+ 2));
	_this->class_id=_this->class_id+1;
	string__set_int(s,_this->class_id);
	Aemmitc__add_to_head(__this, (var)(__string_Aemmitc18+ 2));
	Aemmitc__add_to_head(__this, _this->class_name);
	Aemmitc__add_to_head(__this, (var)(__string_Aemmitc19+ 2));
	Aemmitc__add_to_head(__this, s);
	Aemmitc__add_to_head(__this, (var)(__string_Aemmitc20+ 2));
	std__delete(s);
	_this->pass=0;
	while (_this->pass<3) {
		mem=Aclass__get_members(_this->clas);
		l=buffer__length(mem);
		i=0;
		while (i<l) {
			m=buffer__get_at(mem,i);
			Aemmitc__gen_debug_context(__this, m);
			Aemmitc__gen_member(__this, m);
			if (_this->pass==2) {
				Amember__dispose_body(m);
			}
			i=i+1;
		}
		_this->pass=_this->pass+1;
	}
	Aemmitc__gen_virtual_lambda(__this, Aclass__get_nb_lambda(_this->clas));
	recursive--;
	return __return__;
}
var Aemmitc__gen_debug_context(var __this, var mb)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.gen_debug_context\"\n");std__panic();
	}
	if (_this->debug) {
	}
	recursive--;
	return __return__;
}
var Aemmitc__gen_member(var __this, var mb)
{
	static var recursive = 0;
	var __return__ = 0;
	var k;
	var str;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.gen_member\"\n");std__panic();
	}
	str=string__new(8,__this);
	k=Amember__get_kind(mb);
	
	switch (_this->pass) {
	case 0: 
		Aemmitc__pass_0(__this, str,mb,k);
		Aemmitc__pass_1(__this, str,mb,k);
		Aemmitc__pass_2(__this, str,mb,k);
		break;
	case 1: 
		Aemmitc__pass_3(__this, str,mb,k);
		break;
	case 2: 
		Aemmitc__pass_4(__this, str,mb,k);
		break;
	} 
	std__delete(str);
	recursive--;
	return __return__;
}
var Aemmitc__gen_conditional_call(var __this, var v, var mb)
{
	static var recursive = 0;
	var __return__ = 0;
	var param;
	var params;
	var i;
	var l;
	var tok;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.gen_conditional_call\"\n");std__panic();
	}
	_this->_datal=string__length(_this->_data);
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc21+ 2));
	Aemmitc__add_to_data(__this, Avirtual__get_class_name(v));
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc22+ 2));
	params=Amember__get_params(mb);
	Aemmitc__add_to_data(__this, Avirtual__get_class_name(v));
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc23+ 2));
	Aemmitc__add_to_data(__this, Amember__get_name_string(mb));
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc24+ 2));
	if (params!=0) {
		l=buffer__length(params);
		i=0;
		while (i<l) {
			param=buffer__get_at(params,i);
			Aemmitc__add_to_data(__this, (var)(__string_Aemmitc25+ 2));
			tok=Amember__get_name(param);
			Aemmitc__add_to_data(__this, Atoken__get_data(tok));
			i=i+1;
		}
	}
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc26+ 2));
	recursive--;
	return __return__;
}
var Aemmitc___V_gen_virtuals(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var i;
	var v;
	var mb;
	var s;
	MAKETHIS(Aemmitc);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.gen_virtuals\"\n");std__panic();
	}
	i=buffer__length(_this->_virtuals);
	_this->_datal=string__length(_this->_data);
	while (i>0) {
		i=i-1;
		v=buffer__get_at(_this->_virtuals,i);
		mb=Avirtual__get_member(v);
		Aemmitc__gen_method_decl(__this, _this->_head,(var)(__string_Aemmitc27+ 2),Amember__get_name_string(mb),mb,Aclass__Cvirtual);
		_this->_headl=string__length(_this->_head);
		Aemmitc__add_to_head(__this, (var)(__string_Aemmitc28+ 2));
		Aemmitc__gen_method_decl(__this, _this->_data,(var)(__string_Aemmitc29+ 2),Amember__get_name_string(mb),mb,Aclass__Cvirtual);
		_this->_datal=string__length(_this->_data);
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc30+ 2));
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc31+ 2));
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc32+ 2));
		while (v!=0) {
			Aemmitc__gen_conditional_call(__this, v,mb);
			v=Avirtual__get_next(v);
		}
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc33+ 2));
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc34+ 2));
	}
	_this->_datal=string__length(_this->_data);
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc35+ 2));
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc36+ 2));
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc37+ 2));
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc38+ 2));
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc39+ 2));
	i=buffer__length(_this->_lambdas);
	while (i>0) {
		i=i-1;
		s=buffer__get_at(_this->_lambdas,i);
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc40+ 2));
		Aemmitc__add_to_data(__this, s);
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc41+ 2));
		Aemmitc__add_to_data(__this, s);
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc42+ 2));
	}
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc43+ 2));
	recursive--;
	return __return__;
}
var Aemmitc__gen_virtual_lambda(var __this, var nb)
{
	static var recursive = 0;
	var __return__ = 0;
	var i;
	var s;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.gen_virtual_lambda\"\n");std__panic();
	}
	if (nb<1) {
		recursive--;
	return __return__;
	}
	buffer__push(_this->_lambdas,_this->class_name);
	Aemmitc__add_to_head(__this, (var)(__string_Aemmitc44+ 2));
	Aemmitc__add_to_head(__this, _this->class_name);
	Aemmitc__add_to_head(__this, (var)(__string_Aemmitc45+ 2));
	Aemmitc__add_to_head(__this, (var)(__string_Aemmitc46+ 2));
	Aemmitc__add_to_head(__this, _this->class_name);
	Aemmitc__add_to_head(__this, (var)(__string_Aemmitc47+ 2));
	Aemmitc__add_to_head(__this, (var)(__string_Aemmitc48+ 2));
	_this->_datal=string__length(_this->_data);
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc49+ 2));
	Aemmitc__add_to_data(__this, _this->class_name);
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc50+ 2));
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc51+ 2));
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc52+ 2));
	i=0;
	s=string__new(20,__this);
	while (i<nb) {
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc53+ 2));
		string__set_int(s,i);
		Aemmitc__add_to_data(__this, s);
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc54+ 2));
		Aemmitc__add_to_data(__this, _this->class_name);
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc55+ 2));
		Aemmitc__add_to_data(__this, s);
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc56+ 2));
		i=i+1;
	}
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc57+ 2));
	std__delete(s);
	recursive--;
	return __return__;
}
var Aemmitc__pass_0(var __this, var str, var mb, var k)
{
	static var recursive = 0;
	var __return__ = 0;
	var t;
	var ty;
	var i;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.pass_0\"\n");std__panic();
	}
	_this->_datal=string__length(_this->_data);
	_this->_headl=string__length(_this->_head);
	if (k==(Aclass__Cconst)) {
		Aemmitc__add_to_head(__this, (var)(__string_Aemmitc58+ 2));
		Aemmitc__add_to_head(__this, _this->class_name);
		Aemmitc__add_to_head(__this, (var)(__string_Aemmitc59+ 2));
		Aemmitc__add_to_head(__this, Amember__get_name_string(mb));
		Aemmitc__add_to_head(__this, (var)(__string_Aemmitc60+ 2));
		t=Amember__get_initial_value(mb);
		ty=Atoken__get_type(t);
		if (ty==(Alexer__Cstring)) {
			Aemmitc__add_to_head(__this, (var)(__string_Aemmitc61+ 2));
			Aemmitc__add_to_head(__this, _this->class_name);
			Aemmitc__add_to_head(__this, Amember__get_name_string(mb));
			Aemmitc__add_to_head(__this, (var)(__string_Aemmitc62+ 2));
			Aemmitc__gen_string(__this, Amember__get_name_string(mb),Atoken__get_data(t));
		} else if (ty==(Alexer__Cquote)) {
			Aemmitc__add_to_head(__this, (var)(__string_Aemmitc63+ 2));
			Aemmitc__add_to_head(__this, Atoken__get_data(t));
			Aemmitc__add_to_head(__this, (var)(__string_Aemmitc64+ 2));
		} else {
			Aemmitc__add_to_head(__this, Atoken__get_data(t));
		}
		Aemmitc__add_to_head(__this, (var)(__string_Aemmitc65+ 2));
	}
	if (k==(Aclass__Cfield)) {
		i=Amember__get_index(mb);
		if (i==0) {
			Aemmitc__add_to_data(__this, (var)(__string_Aemmitc66+ 2));
			Aemmitc__add_to_data(__this, _this->class_name);
			Aemmitc__add_to_data(__this, (var)(__string_Aemmitc67+ 2));
		}
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc68+ 2));
		Aemmitc__add_to_data(__this, Amember__get_name_string(mb));
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc69+ 2));
		if (((i+1))==(Aclass__get_nb_fields(_this->clas))) {
			Aemmitc__add_to_data(__this, (var)(__string_Aemmitc70+ 2));
		}
	}
	recursive--;
	return __return__;
}
var Aemmitc__pass_1(var __this, var str, var mb, var k)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.pass_1\"\n");std__panic();
	}
	_this->_datal=string__length(_this->_data);
	if (k==(Aclass__Cstatic)) {
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc71+ 2));
		Aemmitc__add_to_data(__this, _this->class_name);
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc72+ 2));
		Aemmitc__add_to_data(__this, Amember__get_name_string(mb));
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc73+ 2));
	}
	recursive--;
	return __return__;
}
var Aemmitc__pass_2(var __this, var str, var mb, var k)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.pass_2\"\n");std__panic();
	}
	recursive--;
	return __return__;
}
var Aemmitc__pad(var __this, var depth)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.pad\"\n");std__panic();
	}
	_this->_datal=string__length(_this->_data);
	while (depth>0) {
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc74+ 2));
		depth=depth-1;
	}
	recursive--;
	return __return__;
}
var Aemmitc__find_param(var __this, var stri)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.find_param\"\n");std__panic();
	}
	__return__ = Aemmiter__find_param(_this->side,stri);
	recursive--;
	return __return__;
}
var Aemmitc__find_field(var __this, var stri)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.find_field\"\n");std__panic();
	}
	__return__ = Aemmiter__find_field(_this->side,stri);
	recursive--;
	return __return__;
}
var Aemmitc__find_method(var __this, var stri)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.find_method\"\n");std__panic();
	}
	__return__ = Aemmiter__find_method(_this->side,stri);
	recursive--;
	return __return__;
}
var Aemmitc__find_static(var __this, var stri)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.find_static\"\n");std__panic();
	}
	__return__ = Aemmiter__find_static(_this->side,stri);
	recursive--;
	return __return__;
}
var Aemmitc__find_local(var __this, var stri)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.find_local\"\n");std__panic();
	}
	__return__ = Aemmiter__find_local(_this->side,stri);
	recursive--;
	return __return__;
}
var Aemmitc__expr_call_member(var __this, var expr, var ex1, var ex2, var stri, var obj)
{
	static var recursive = 0;
	var __return__ = 0;
	var v;
	var s;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.expr_call_member\"\n");std__panic();
	}
	v=Aemmitc__find_field(__this, stri);
	if (v==0) {
		v=Aemmitc__find_method(__this, stri);
	}
	if ((v!=0)) {
		Aexpr__add_data(expr,_this->class_name);
		Aexpr__add_data(expr,(var)(__string_Aemmitc75+ 2));
		Aexpr__add_data(expr,stri);
		s=Aexpr__get_value(ex2);
		if ((s!=0)&&((string__length(s))>0)) {
			Aexpr__add_data(expr,(var)(__string_Aemmitc76+ 2));
			Aexpr__merge_data(expr,Aexpr__get_data(ex2));
			Aexpr__add_data(expr,(var)(__string_Aemmitc77+ 2));
		} else {
			Aexpr__add_data(expr,(var)(__string_Aemmitc78+ 2));
		}
		buffer__push(_this->_expr_stk,expr);
		recursive--;
	return __return__;
	}
	console__log(stri);
	Aemmitc__error(__this, Aexpr__get_origin(expr),(var)(__string_Aemmitc79+ 2));
	recursive--;
	return __return__;
}
var Aemmitc__expr_call_sub(var __this, var expr, var ex1, var ex2, var stri, var obj, var v, var sta, var fld)
{
	static var recursive = 0;
	var __return__ = 0;
	var tok;
	var s;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.expr_call_sub\"\n");std__panic();
	}
	tok=Amember__get_type_id(v);
	if (tok==0) {
		console__log(obj);
		console__log(Amember__get_name_string(v));
		Aemmitc__error(__this, Aexpr__get_origin(ex1),(var)(__string_Aemmitc80+ 2));
		recursive--;
	return __return__;
	}
	s=Atoken__get_data(tok);
	Aexpr__add_data(expr,s);
	Aexpr__add_data(expr,(var)(__string_Aemmitc81+ 2));
	Aexpr__merge_data(expr,Aexpr__get_data(ex1));
	s=Aexpr__get_value(ex2);
	Aexpr__add_data(expr,(var)(__string_Aemmitc82+ 2));
	if (fld!=0) {
		Aexpr__add_data(expr,(var)(__string_Aemmitc83+ 2));
	} else if (sta!=0) {
		Aexpr__add_data(expr,_this->class_name);
		Aexpr__add_data(expr,(var)(__string_Aemmitc84+ 2));
	}
	Aexpr__add_data(expr,Aexpr__get_value2(ex1));
	if ((s!=0)&&((string__length(s))>0)) {
		Aexpr__add_data(expr,(var)(__string_Aemmitc85+ 2));
		Aexpr__merge_data(expr,Aexpr__get_data(ex2));
	}
	if ((string__compare(stri,(var)(__string_Aemmitc86+ 2)))==0) {
		Aexpr__add_data(expr,(var)(__string_Aemmitc87+ 2));
	}
	Aexpr__add_data(expr,(var)(__string_Aemmitc88+ 2));
	buffer__push(_this->_expr_stk,expr);
	recursive--;
	return __return__;
}
var Aemmitc__expr_gen_call(var __this, var expr)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex1;
	var ex2;
	var stri;
	var v;
	var obj;
	var sta;
	var s;
	var fld;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.expr_gen_call\"\n");std__panic();
	}
	ex2=buffer__pop(_this->_expr_stk);
	ex1=buffer__pop(_this->_expr_stk);
	stri=Aexpr__data_to_string(ex1,Aemmitc__new_string(__this, 8));
	obj=Aexpr__get_value2(ex1);
	Aexpr__clear_data(expr);
	if (obj==0) {
		Aemmitc__expr_call_member(__this, expr,ex1,ex2,stri,obj);
		recursive--;
	return __return__;
	}
	fld=0;
	sta=0;
	v=Aemmitc__find_local(__this, obj);
	if (v==0) {
		v=Aemmitc__find_param(__this, obj);
	}
	if (v==0) {
		v=Aemmitc__find_field(__this, obj);
		if (v==0) {
			v=Aemmitc__find_method(__this, obj);
		}
		if (v!=0) {
			fld=1;
		}
	}
	if (v==0) {
		v=Aemmitc__find_static(__this, obj);
		if (v!=0) {
			sta=1;
		}
	}
	if (v!=0) {
		Aemmitc__expr_call_sub(__this, expr,ex1,ex2,stri,obj,v,sta,fld);
		recursive--;
	return __return__;
	}
	Aexpr__add_data(expr,obj);
	Aexpr__add_data(expr,(var)(__string_Aemmitc89+ 2));
	Aexpr__merge_data(expr,Aexpr__get_data(ex1));
	Aexpr__add_data(expr,(var)(__string_Aemmitc90+ 2));
	Aexpr__merge_data(expr,Aexpr__get_data(ex2));
	if ((string__compare(stri,(var)(__string_Aemmitc91+ 2)))==0) {
		s=Aexpr__get_value(ex2);
		if ((s!=0)&&((string__length(s))>0)) {
			Aexpr__add_data(expr,(var)(__string_Aemmitc92+ 2));
		} else {
			Aexpr__add_data(expr,(var)(__string_Aemmitc93+ 2));
		}
	}
	Aexpr__add_data(expr,(var)(__string_Aemmitc94+ 2));
	buffer__push(_this->_expr_stk,expr);
	recursive--;
	return __return__;
}
var Aemmitc__expr_gen_sub_expr(var __this, var expr)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.expr_gen_sub_expr\"\n");std__panic();
	}
	if ((Aexpr__get_right(expr))==0) {
		Aexpr__clear_data(expr);
		Aexpr__add_data(expr,(var)(__string_Aemmitc95+ 2));
		buffer__push(_this->_expr_stk,expr);
	}
	recursive--;
	return __return__;
}
var Aemmitc__expr_gen_comma(var __this, var expr)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex1;
	var ex2;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.expr_gen_comma\"\n");std__panic();
	}
	ex2=buffer__pop(_this->_expr_stk);
	ex1=buffer__pop(_this->_expr_stk);
	Aexpr__clear_data(expr);
	Aexpr__merge_data(expr,Aexpr__get_data(ex1));
	Aexpr__add_data(expr,(var)(__string_Aemmitc96+ 2));
	Aexpr__merge_data(expr,Aexpr__get_data(ex2));
	buffer__push(_this->_expr_stk,expr);
	recursive--;
	return __return__;
}
var Aemmitc__expr_gen_index(var __this, var expr)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex1;
	var ex2;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.expr_gen_index\"\n");std__panic();
	}
	ex2=buffer__pop(_this->_expr_stk);
	ex1=buffer__pop(_this->_expr_stk);
	Aexpr__clear_data(expr);
	Aexpr__add_data(expr,(var)(__string_Aemmitc97+ 2));
	Aexpr__merge_data(expr,Aexpr__get_data(ex1));
	Aexpr__add_data(expr,(var)(__string_Aemmitc98+ 2));
	Aexpr__merge_data(expr,Aexpr__get_data(ex2));
	Aexpr__add_data(expr,(var)(__string_Aemmitc99+ 2));
	buffer__push(_this->_expr_stk,expr);
	recursive--;
	return __return__;
}
var Aemmitc__expr_gen_par(var __this, var expr)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex1;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.expr_gen_par\"\n");std__panic();
	}
	ex1=buffer__pop(_this->_expr_stk);
	Aexpr__clear_data(expr);
	Aexpr__add_data(expr,(var)(__string_Aemmitc100+ 2));
	Aexpr__merge_data(expr,Aexpr__get_data(ex1));
	Aexpr__add_data(expr,(var)(__string_Aemmitc101+ 2));
	buffer__push(_this->_expr_stk,expr);
	recursive--;
	return __return__;
}
var Aemmitc__expr_gen_constant(var __this, var expr)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex1;
	var ex2;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.expr_gen_constant\"\n");std__panic();
	}
	Aexpr__clear_data(expr);
	ex2=buffer__pop(_this->_expr_stk);
	ex1=buffer__pop(_this->_expr_stk);
	Aexpr__merge_data(expr,Aexpr__get_data(ex1));
	Aexpr__add_data(expr,(var)(__string_Aemmitc102+ 2));
	Aexpr__merge_data(expr,Aexpr__get_data(ex2));
	buffer__push(_this->_expr_stk,expr);
	recursive--;
	return __return__;
}
var Aemmitc__expr_gen_dot(var __this, var expr)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex1;
	var ex2;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.expr_gen_dot\"\n");std__panic();
	}
	Aexpr__clear_data(expr);
	ex2=buffer__pop(_this->_expr_stk);
	ex1=buffer__pop(_this->_expr_stk);
	Aexpr__set_value2(expr,Aexpr__data_to_string(ex1,Aemmitc__new_string(__this, 8)));
	Aexpr__merge_data(expr,Aexpr__get_data(ex2));
	buffer__push(_this->_expr_stk,expr);
	recursive--;
	return __return__;
}
var Aemmitc__expr_gen_lambda(var __this, var expr)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.expr_gen_lambda\"\n");std__panic();
	}
	Aexpr__add_data(expr,(var)(__string_Aemmitc103+ 2));
	buffer__push(_this->_expr_stk,expr);
	recursive--;
	return __return__;
}
var Aemmitc__gen_string(var __this, var s2, var value)
{
	static var recursive = 0;
	var __return__ = 0;
	var l;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.gen_string\"\n");std__panic();
	}
	l=string__length(_this->_mid);
	l=string__add_at(_this->_mid,l,(var)(__string_Aemmitc104+ 2));
	l=string__add_at(_this->_mid,l,_this->class_name);
	l=string__add_at(_this->_mid,l,s2);
	l=string__add_at(_this->_mid,l,(var)(__string_Aemmitc105+ 2));
	l=string__add_at(_this->_mid,l,(var)(__string_Aemmitc106+ 2));
	l=string__add_at(_this->_mid,l,value);
	l=string__add_at(_this->_mid,l,(var)(__string_Aemmitc107+ 2));
	l=string__add_at(_this->_mid,l,(var)(__string_Aemmitc108+ 2));
	l=string__add_at(_this->_mid,l,(var)(__string_Aemmitc109+ 2));
	l=string__add_at(_this->_mid,l,_this->class_name);
	l=string__add_at(_this->_mid,l,s2);
	l=string__add_at(_this->_mid,l,(var)(__string_Aemmitc110+ 2));
	l=string__add_at(_this->_mid,l,(var)(__string_Aemmitc111+ 2));
	string__add(_this->_str,(var)(__string_Aemmitc112+ 2));
	string__add(_this->_str,_this->class_name);
	string__add(_this->_str,s2);
	string__add(_this->_str,(var)(__string_Aemmitc113+ 2));
	string__add(_this->_str,(var)(__string_Aemmitc114+ 2));
	string__add(_this->_str,_this->class_name);
	string__add(_this->_str,s2);
	string__add(_this->_str,(var)(__string_Aemmitc115+ 2));
	recursive--;
	return __return__;
}
var Aemmitc__number(var __this, var n)
{
	static var recursive = 0;
	var __return__ = 0;
	var s2;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.number\"\n");std__panic();
	}
	s2=string__new(8,__this);
	buffer__push(_this->string_pool,s2);
	string__set_int(s2,n);
	__return__ = s2;
	recursive--;
	return __return__;
}
var Aemmitc__new_string(var __this, var l)
{
	static var recursive = 0;
	var __return__ = 0;
	var s2;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.new_string\"\n");std__panic();
	}
	s2=string__new(l,__this);
	buffer__push(_this->string_pool,s2);
	__return__ = s2;
	recursive--;
	return __return__;
}
var Aemmitc__expr_gen_str_const(var __this, var expr)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.expr_gen_str_const\"\n");std__panic();
	}
	_this->string_id=_this->string_id+1;
	Aemmitc__gen_string(__this, Aemmitc__number(__this, _this->string_id),Aexpr__data_to_string(expr,Aemmitc__new_string(__this, 20)));
	Aexpr__clear_data(expr);
	Aexpr__add_data(expr,(var)(__string_Aemmitc116+ 2));
	Aexpr__add_data(expr,_this->class_name);
	Aexpr__add_data(expr,Aemmitc__number(__this, _this->string_id));
	Aexpr__add_data(expr,(var)(__string_Aemmitc117+ 2));
	buffer__push(_this->_expr_stk,expr);
	recursive--;
	return __return__;
}
var Aemmitc__expr_gen_char_const(var __this, var expr)
{
	static var recursive = 0;
	var __return__ = 0;
	var s;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.expr_gen_char_const\"\n");std__panic();
	}
	s=Aexpr__data_to_string(expr,Aemmitc__new_string(__this, 3));
	Aexpr__clear_data(expr);
	Aexpr__add_data(expr,(var)(__string_Aemmitc118+ 2));
	if ((string__length(s))>0) {
		Aexpr__add_data(expr,s);
	} else {
		Aexpr__add_data(expr,(var)(__string_Aemmitc119+ 2));
	}
	Aexpr__add_data(expr,(var)(__string_Aemmitc120+ 2));
	buffer__push(_this->_expr_stk,expr);
	recursive--;
	return __return__;
}
var Aemmitc__expr_gen0(var __this, var expr, var op)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.expr_gen0\"\n");std__panic();
	}
	Aexpr__clear_data(expr);
	Aexpr__add_data(expr,op);
	buffer__push(_this->_expr_stk,expr);
	recursive--;
	return __return__;
}
var Aemmitc__expr_gen1(var __this, var expr, var op)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex1;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.expr_gen1\"\n");std__panic();
	}
	Aexpr__clear_data(expr);
	ex1=buffer__pop(_this->_expr_stk);
	Aexpr__add_data(expr,op);
	Aexpr__add_data(expr,(var)(__string_Aemmitc121+ 2));
	Aexpr__merge_data(expr,Aexpr__get_data(ex1));
	Aexpr__add_data(expr,(var)(__string_Aemmitc122+ 2));
	buffer__push(_this->_expr_stk,expr);
	recursive--;
	return __return__;
}
var Aemmitc__expr_gen_assign(var __this, var expr, var op)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex1;
	var ex2;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.expr_gen_assign\"\n");std__panic();
	}
	Aexpr__clear_data(expr);
	ex2=buffer__pop(_this->_expr_stk);
	ex1=buffer__pop(_this->_expr_stk);
	Aexpr__merge_data(expr,Aexpr__get_data(ex1));
	Aexpr__add_data(expr,op);
	Aexpr__merge_data(expr,Aexpr__get_data(ex2));
	buffer__push(_this->_expr_stk,expr);
	recursive--;
	return __return__;
}
var Aemmitc__expr_gen2(var __this, var expr, var op)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex1;
	var ex2;
	var oper;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.expr_gen2\"\n");std__panic();
	}
	Aexpr__clear_data(expr);
	ex2=buffer__pop(_this->_expr_stk);
	ex1=buffer__pop(_this->_expr_stk);
	oper=Aexpr__get_op(ex1);
	if (oper>(Aclass__Croot)) {
		Aexpr__add_data(expr,(var)(__string_Aemmitc123+ 2));
	}
	Aexpr__merge_data(expr,Aexpr__get_data(ex1));
	if (oper>(Aclass__Croot)) {
		Aexpr__add_data(expr,(var)(__string_Aemmitc124+ 2));
	}
	Aexpr__add_data(expr,op);
	oper=Aexpr__get_op(ex2);
	if (oper>(Aclass__Croot)) {
		Aexpr__add_data(expr,(var)(__string_Aemmitc125+ 2));
	}
	Aexpr__merge_data(expr,Aexpr__get_data(ex2));
	if (oper>(Aclass__Croot)) {
		Aexpr__add_data(expr,(var)(__string_Aemmitc126+ 2));
	}
	buffer__push(_this->_expr_stk,expr);
	recursive--;
	return __return__;
}
var Aemmitc__expr_gen_var(var __this, var expr)
{
	static var recursive = 0;
	var __return__ = 0;
	var stri;
	var v;
	var ex;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.expr_gen_var\"\n");std__panic();
	}
	stri=Aexpr__data_to_string(expr,Aemmitc__new_string(__this, 8));
	Aexpr__clear_data(expr);
	if (stri==0) {
		buffer__push(_this->_expr_stk,expr);
		recursive--;
	return __return__;
	}
	v=Aemmitc__find_local(__this, stri);
	if (v!=0) {
		Aexpr__add_data(expr,stri);
		buffer__push(_this->_expr_stk,expr);
		recursive--;
	return __return__;
	}
	v=Aemmitc__find_param(__this, stri);
	if (v!=0) {
		Aexpr__add_data(expr,stri);
		buffer__push(_this->_expr_stk,expr);
		recursive--;
	return __return__;
	}
	ex=Aexpr__get_parent(expr);
	v=0;
	if (((Aexpr__get_op(ex))!=(Aclass__Cdot))&&((Aexpr__get_op(ex))!=(Aclass__Ccall))) {
		v=Aemmitc__find_field(__this, stri);
	}
	if (v!=0) {
		Aexpr__add_data(expr,(var)(__string_Aemmitc127+ 2));
		Aexpr__add_data(expr,stri);
		buffer__push(_this->_expr_stk,expr);
		recursive--;
	return __return__;
	}
	if ((Aexpr__get_op(ex))!=(Aclass__Cdot)) {
		v=Aemmitc__find_method(__this, stri);
	}
	if (v!=0) {
		Aexpr__add_data(expr,stri);
		buffer__push(_this->_expr_stk,expr);
		recursive--;
	return __return__;
	}
	if ((Aexpr__get_op(ex))!=(Aclass__Cdot)) {
		v=Aemmitc__find_static(__this, stri);
	}
	if (v!=0) {
		Aexpr__add_data(expr,_this->class_name);
		Aexpr__add_data(expr,(var)(__string_Aemmitc128+ 2));
		Aexpr__add_data(expr,stri);
		buffer__push(_this->_expr_stk,expr);
		recursive--;
	return __return__;
	}
	Aexpr__add_data(expr,stri);
	buffer__push(_this->_expr_stk,expr);
	recursive--;
	return __return__;
}
var Aemmitc___V_expr_process(var __this, var expr)
{
	static var recursive = 0;
	var __return__ = 0;
	var op;
	var ex;
	MAKETHIS(Aemmitc);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.expr_process\"\n");std__panic();
	}
	op=Aexpr__get_op(expr);
	if (op<(Aclass__Croot)) {
		
		switch (op) {
		case Aclass__Cnull: 
			Aemmitc__expr_gen0(__this, expr,(var)(__string_Aemmitc129+ 2));
			break;
		case Aclass__Cchar_const: 
			Aemmitc__expr_gen_char_const(__this, expr);
			break;
		case Aclass__Cint_const: 
			buffer__push(_this->_expr_stk,expr);
			break;
		case Aclass__Cstr_const: 
			Aemmitc__expr_gen_str_const(__this, expr);
			break;
		case Aclass__Cthis: 
			Aemmitc__expr_gen0(__this, expr,(var)(__string_Aemmitc130+ 2));
			break;
		case Aclass__Clambda: 
			Aemmitc__expr_gen_lambda(__this, expr);
			break;
		default:
			Aemmitc__expr_gen_var(__this, expr);
			break;
		} 
		recursive--;
	return __return__;
	}
	
	switch (op) {
	case Aclass__Croot: 
		if ((buffer__length(_this->_expr_stk))!=1) {
			Aemmitc__error(__this, Aexpr__get_origin(expr),(var)(__string_Aemmitc131+ 2));
			recursive--;
	return __return__;
		}
		ex=buffer__pop(_this->_expr_stk);
		Aexpr__data_to_string(ex,_this->_data);
		_this->_datal=string__length(_this->_data);
		break;
	case Aclass__Cassign: 
		Aemmitc__expr_gen_assign(__this, expr,(var)(__string_Aemmitc132+ 2));
		break;
	case Aclass__Cequal: 
		Aemmitc__expr_gen2(__this, expr,(var)(__string_Aemmitc133+ 2));
		break;
	case Aclass__Cnotequal: 
		Aemmitc__expr_gen2(__this, expr,(var)(__string_Aemmitc134+ 2));
		break;
	case Aclass__Clargerequal: 
		Aemmitc__expr_gen2(__this, expr,(var)(__string_Aemmitc135+ 2));
		break;
	case Aclass__Clesserequal: 
		Aemmitc__expr_gen2(__this, expr,(var)(__string_Aemmitc136+ 2));
		break;
	case Aclass__Clarger: 
		Aemmitc__expr_gen2(__this, expr,(var)(__string_Aemmitc137+ 2));
		break;
	case Aclass__Clesser: 
		Aemmitc__expr_gen2(__this, expr,(var)(__string_Aemmitc138+ 2));
		break;
	case Aclass__Clogicaland: 
		Aemmitc__expr_gen2(__this, expr,(var)(__string_Aemmitc139+ 2));
		break;
	case Aclass__Clogicalor: 
		Aemmitc__expr_gen2(__this, expr,(var)(__string_Aemmitc140+ 2));
		break;
	case Aclass__Cadd: 
		Aemmitc__expr_gen2(__this, expr,(var)(__string_Aemmitc141+ 2));
		break;
	case Aclass__Csub: 
		Aemmitc__expr_gen2(__this, expr,(var)(__string_Aemmitc142+ 2));
		break;
	case Aclass__Cmult: 
		Aemmitc__expr_gen2(__this, expr,(var)(__string_Aemmitc143+ 2));
		break;
	case Aclass__Cdiv: 
		Aemmitc__expr_gen2(__this, expr,(var)(__string_Aemmitc144+ 2));
		break;
	case Aclass__Cmodulo: 
		Aemmitc__expr_gen2(__this, expr,(var)(__string_Aemmitc145+ 2));
		break;
	case Aclass__Clogicalnot: 
		Aemmitc__expr_gen1(__this, expr,(var)(__string_Aemmitc146+ 2));
		break;
	case Aclass__Cparenthesis: 
		Aemmitc__expr_gen_par(__this, expr);
		break;
	case Aclass__Cunaryplus: 
		Aemmitc__expr_gen1(__this, expr,(var)(__string_Aemmitc147+ 2));
		break;
	case Aclass__Cunaryminus: 
		Aemmitc__expr_gen1(__this, expr,(var)(__string_Aemmitc148+ 2));
		break;
	case Aclass__Cdot: 
		Aemmitc__expr_gen_dot(__this, expr);
		break;
	case Aclass__Cconstant: 
		Aemmitc__expr_gen_constant(__this, expr);
		break;
	case Aclass__Ccall: 
		Aemmitc__expr_gen_call(__this, expr);
		break;
	case Aclass__Cindex: 
		Aemmitc__expr_gen_index(__this, expr);
		break;
	case Aclass__Ccomma: 
		Aemmitc__expr_gen_comma(__this, expr);
		break;
	case Aclass__Cexpr: 
		Aemmitc__expr_gen_sub_expr(__this, expr);
		break;
	default:
		Aemmitc__error(__this, Aexpr__get_origin(expr),(var)(__string_Aemmitc149+ 2));
		recursive--;
	return __return__;
		break;
	} 
	recursive--;
	return __return__;
}
var Aemmitc__expr_gen_case(var __this, var expr, var padde)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex;
	var op;
	var i;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.expr_gen_case\"\n");std__panic();
	}
	ex=Aexpr__get_case_expr(expr,0);
	i=0;
	while (ex!=0) {
		op=Aexpr__get_op(ex);
		if (op==(Aclass__Cint_const)) {
			buffer__push(_this->_expr_stk,ex);
		} else if (op==(Aclass__Cconstant)) {
			buffer__push(_this->_expr_stk,Aexpr__get_left(ex));
			buffer__push(_this->_expr_stk,Aexpr__get_right(ex));
			Aemmitc__expr_gen_constant(__this, ex);
		} else {
			Aemmitc__error(__this, Aexpr__get_origin(ex),(var)(__string_Aemmitc150+ 2));
			recursive--;
	return __return__;
		}
		if (i>0) {
			Aemmitc__add_to_data(__this, (var)(__string_Aemmitc151+ 2));
			Aemmitc__pad(__this, padde);
		}
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc152+ 2));
		ex=buffer__pop(_this->_expr_stk);
		Aexpr__data_to_string(ex,_this->_data);
		_this->_datal=string__length(_this->_data);
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc153+ 2));
		i=i+1;
		ex=Aexpr__get_case_expr(expr,i);
	}
	recursive--;
	return __return__;
}
var Aemmitc__expr_gen(var __this, var expr)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.expr_gen\"\n");std__panic();
	}
	Aemmiter__expr_gen(_this->side,expr);
	recursive--;
	return __return__;
}
var Aemmitc__fix_datal(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.fix_datal\"\n");std__panic();
	}
	_this->_datal=string__length(_this->_data);
	recursive--;
	return __return__;
}
var Aemmitc__body_gen_constructor(var __this, var mb)
{
	static var recursive = 0;
	var __return__ = 0;
	var i;
	var l;
	var params;
	var p;
	var tok;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.body_gen_constructor\"\n");std__panic();
	}
	params=Amember__get_params(mb);
	if (params==0) {
		l=0;
	} else {
		l=buffer__length(params);
	}
	_this->_datal=string__length(_this->_data);
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc154+ 2));
	Aemmitc__add_to_data(__this, _this->class_name);
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc155+ 2));
	Aemmitc__add_to_data(__this, _this->class_name);
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc156+ 2));
	tok=Amember__get_name(mb);
	Aemmitc__add_to_data(__this, Atoken__get_data(tok));
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc157+ 2));
	i=0;
	while (i<l) {
		p=buffer__get_at(params,i);
		tok=Amember__get_name(p);
		Aemmitc__add_to_data(__this, (var)(__string_Aemmitc158+ 2));
		Aemmitc__add_to_data(__this, Atoken__get_data(tok));
		i=i+1;
	}
	Aemmitc__add_to_data(__this, (var)(__string_Aemmitc159+ 2));
	recursive--;
	return __return__;
}
var Aemmitc__set_member(var __this, var m)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.set_member\"\n");std__panic();
	}
	_this->cur_memb=m;
	recursive--;
	return __return__;
}
var Aemmitc__body_gen(var __this, var mb, var k, var vars_, var body_)
{
	static var recursive = 0;
	var __return__ = 0;
	var b;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.body_gen\"\n");std__panic();
	}
	b=Acbody__new(__this,_this->side,_this->class_name,_this->debug,_this->_expr_stk,__this);
	Acbody__body_gen(b,mb,k,vars_,body_);
	std__delete(b);
	recursive--;
	return __return__;
}
var Aemmitc__gen_type(var __this, var mb)
{
	static var recursive = 0;
	var __return__ = 0;
	var ty;
	var tok;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.gen_type\"\n");std__panic();
	}
	_this->_datal=string__length(_this->_data);
	tok=Amember__get_type_id(mb);
	if (tok!=0) {
		Aemmitc__add_to_data(__this, Atoken__get_data(tok));
	} else {
		ty=Amember__get_type(mb);
		if (ty==(Aclass__Cint)) {
			Aemmitc__add_to_data(__this, (var)(__string_Aemmitc160+ 2));
		} else if (ty==(Aclass__Cvoid)) {
			Aemmitc__add_to_data(__this, (var)(__string_Aemmitc161+ 2));
		} else {
			Aemmitc__error(__this, Amember__get_name(mb),(var)(__string_Aemmitc162+ 2));
		}
	}
	recursive--;
	return __return__;
}
var Aemmitc__add_virtual(var __this, var mb)
{
	static var recursive = 0;
	var __return__ = 0;
	var n;
	var v;
	var nv;
	var i;
	var s;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.add_virtual\"\n");std__panic();
	}
	n=Amember__get_name_string(mb);
	nv=Avirtual__new(mb,_this->class_name,__this);
	i=buffer__length(_this->_virtuals);
	while (i>0) {
		i=i-1;
		v=buffer__get_at(_this->_virtuals,i);
		if (v!=0) {
			s=Avirtual__get_member_name(v);
			if (((s!=0))&&(((string__compare(n,s))==0))) {
				Avirtual__set_next(nv,Avirtual__get_next(v));
				Avirtual__set_next(v,nv);
				recursive--;
	return __return__;
			}
		}
	}
	buffer__push(_this->_virtuals,nv);
	recursive--;
	return __return__;
}
var Aemmitc__gen_virtual_caller(var __this, var mb)
{
	static var recursive = 0;
	var __return__ = 0;
	var param;
	var params;
	var i;
	var l;
	var tok;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.gen_virtual_caller\"\n");std__panic();
	}
	params=Amember__get_params(mb);
	_this->_headl=string__length(_this->_head);
	Aemmitc__add_to_head(__this, (var)(__string_Aemmitc163+ 2));
	Aemmitc__add_to_head(__this, _this->class_name);
	Aemmitc__add_to_head(__this, (var)(__string_Aemmitc164+ 2));
	Aemmitc__add_to_head(__this, Amember__get_name_string(mb));
	Aemmitc__add_to_head(__this, (var)(__string_Aemmitc165+ 2));
	if (params!=0) {
		l=buffer__length(params);
		i=0;
		while (i<l) {
			param=buffer__get_at(params,i);
			Aemmitc__add_to_head(__this, (var)(__string_Aemmitc166+ 2));
			tok=Amember__get_name(param);
			Aemmitc__add_to_head(__this, Atoken__get_data(tok));
			i=i+1;
		}
	}
	Aemmitc__add_to_head(__this, (var)(__string_Aemmitc167+ 2));
	Aemmitc__add_to_head(__this, Amember__get_name_string(mb));
	Aemmitc__add_to_head(__this, (var)(__string_Aemmitc168+ 2));
	if (params!=0) {
		l=buffer__length(params);
		i=0;
		while (i<l) {
			param=buffer__get_at(params,i);
			Aemmitc__add_to_head(__this, (var)(__string_Aemmitc169+ 2));
			tok=Amember__get_name(param);
			Aemmitc__add_to_head(__this, Atoken__get_data(tok));
			i=i+1;
		}
	}
	Aemmitc__add_to_head(__this, (var)(__string_Aemmitc170+ 2));
	recursive--;
	return __return__;
}
var Aemmitc__gen_method_decl(var __this, var dest, var c_name, var name, var mb, var k)
{
	static var recursive = 0;
	var __return__ = 0;
	var param;
	var params;
	var i;
	var l;
	var sub;
	var tok;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.gen_method_decl\"\n");std__panic();
	}
	string__add(dest,(var)(__string_Aemmitc171+ 2));
	string__add(dest,c_name);
	string__add(dest,(var)(__string_Aemmitc172+ 2));
	if (k==(Aclass__Cconstructor)) {
		string__add(dest,(var)(__string_Aemmitc173+ 2));
	}
	string__add(dest,name);
	params=Amember__get_params(mb);
	string__add(dest,(var)(__string_Aemmitc174+ 2));
	sub=1;
	if (((((k==(Aclass__Cmethod)))||((k==(Aclass__Cvirtual))))||((k==(Aclass__Cconstructor))))||((k==(Aclass__Casync)))) {
		string__add(dest,(var)(__string_Aemmitc175+ 2));
		sub=2;
	}
	if (params!=0) {
		l=buffer__length(params);
		i=0;
		while (i<l) {
			param=buffer__get_at(params,i);
			if (((i>0))||((sub==2))) {
				string__add(dest,(var)(__string_Aemmitc176+ 2));
			}
			if ((Amember__get_kind(param))==(Aclass__Casync)) {
				string__add(dest,(var)(__string_Aemmitc177+ 2));
				tok=Amember__get_name(param);
				string__add(dest,Atoken__get_data(tok));
				string__add(dest,(var)(__string_Aemmitc178+ 2));
				string__add(dest,Atoken__get_data(tok));
			} else {
				string__add(dest,(var)(__string_Aemmitc179+ 2));
				tok=Amember__get_name(param);
				string__add(dest,Atoken__get_data(tok));
			}
			i=i+1;
		}
		if (k==(Aclass__Cnew_wrap)) {
			string__add(dest,(var)(__string_Aemmitc180+ 2));
		}
	} else {
		if (k==(Aclass__Cnew_wrap)) {
			string__add(dest,(var)(__string_Aemmitc181+ 2));
		}
	}
	if (k==(Aclass__Cconstructor)) {
		string__add(dest,(var)(__string_Aemmitc182+ 2));
	}
	if (k==(Aclass__Casync)) {
		string__add(dest,(var)(__string_Aemmitc183+ 2));
	}
	string__add(dest,(var)(__string_Aemmitc184+ 2));
	recursive--;
	return __return__;
}
var Aemmitc__pass_3(var __this, var str, var mb, var k)
{
	static var recursive = 0;
	var __return__ = 0;
	var vars;
	var body;
	var sub;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.pass_3\"\n");std__panic();
	}
	_this->_datal=string__length(_this->_data);
	sub=0;
	
	switch (k) {
	case Aclass__Cconstructor: 
		sub=1;
		break;
	case Aclass__Cfunction: 
		sub=1;
		break;
	case Aclass__Cmethod: 
		sub=2;
		break;
	case Aclass__Casync: 
		sub=2;
		break;
	case Aclass__Cvirtual: 
		sub=2;
		break;
	} 
	if (sub!=0) {
		if (k==(Aclass__Cvirtual)) {
			Aemmitc__add_virtual(__this, mb);
			Aemmitc__gen_virtual_caller(__this, mb);
			string__set(str,(var)(__string_Aemmitc185+ 2));
			string__add(str,Amember__get_name_string(mb));
			Aemmitc__gen_method_decl(__this, _this->_head,_this->class_name,str,mb,k);
			_this->_headl=string__length(_this->_head);
			Aemmitc__add_to_head(__this, (var)(__string_Aemmitc186+ 2));
			Aemmitc__gen_method_decl(__this, _this->_data,_this->class_name,str,mb,k);
			_this->_datal=string__length(_this->_data);
			Aemmitc__add_to_data(__this, (var)(__string_Aemmitc187+ 2));
		} else {
			Aemmitc__gen_method_decl(__this, _this->_head,_this->class_name,Amember__get_name_string(mb),mb,k);
			_this->_headl=string__length(_this->_head);
			Aemmitc__add_to_head(__this, (var)(__string_Aemmitc188+ 2));
			if (k==(Aclass__Cconstructor)) {
				Aemmitc__gen_method_decl(__this, _this->_head,_this->class_name,Amember__get_name_string(mb),mb,Aclass__Cnew_wrap);
				_this->_headl=string__length(_this->_head);
				Aemmitc__add_to_head(__this, (var)(__string_Aemmitc189+ 2));
			}
			Aemmitc__gen_method_decl(__this, _this->_data,_this->class_name,Amember__get_name_string(mb),mb,k);
			_this->_datal=string__length(_this->_data);
			Aemmitc__add_to_data(__this, (var)(__string_Aemmitc190+ 2));
		}
		vars=Amember__get_vars(mb);
		body=Amember__get_body(mb);
		if (body!=0) {
			Aemmitc__body_gen(__this, mb,k,vars,body);
			if (k==(Aclass__Cconstructor)) {
				Aemmitc__gen_method_decl(__this, _this->_data,_this->class_name,Amember__get_name_string(mb),mb,Aclass__Cnew_wrap);
				_this->_datal=string__length(_this->_data);
				Aemmitc__add_to_data(__this, (var)(__string_Aemmitc191+ 2));
				Aemmitc__body_gen_constructor(__this, mb);
			}
		}
	}
	recursive--;
	return __return__;
}
var Aemmitc__pass_4(var __this, var str, var mb, var k)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.pass_4\"\n");std__panic();
	}
	recursive--;
	return __return__;
}
var Aemmitc__error(var __this, var t, var e)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aemmitc);
	if (((var*)__this)[-1]!=Aemmitc___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aemmitc.error\"\n");std__panic();
	}
	Aemmiter__error(_this->side,t,e);
	recursive--;
	return __return__;
}
/* class Acbody */
struct Acbody {
	var class_name;
	var _expr_stk;
	var debug;
	var string_pool;
	var side;
	var emmiter;
	var stack;
	var body;
	var buf;
	var ex;
	var stm;
	var ty;
	var padde;
	var l;
	var i;
	var end;
	var switchend;
	var caseend;
	var cmb;
};
var Acbody___new(var __this, var emmiter1, var side1, var class_name1, var debug1, var expr_stk1, var __parent)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Acbody);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Acbody.new\"\n");std__panic();
	}
	_this->emmiter=emmiter1;
	_this->side=side1;
	_this->class_name=class_name1;
	_this->debug=debug1;
	_this->_expr_stk=expr_stk1;
	__return__ = __this;
	recursive--;
	return __return__;
}
var Acbody__new(var emmiter1, var side1, var class_name1, var debug1, var expr_stk1, var __parent)
{
	NEW(Acbody);
	return Acbody___new(__this, emmiter1, side1, class_name1, debug1, expr_stk1, __parent);
}
var Acbody___V_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Acbody);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Acbody.dispose\"\n");std__panic();
	}
	std__free(__this);
	recursive--;
	return __return__;
}
var Acbody__add_to_data(var __this, var s)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Acbody);
	if (((var*)__this)[-1]!=Acbody___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Acbody.add_to_data\"\n");std__panic();
	}
	Aemmitc__add_to_data(_this->emmiter,s);
	recursive--;
	return __return__;
}
var Acbody__expr_gen(var __this, var expr)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Acbody);
	if (((var*)__this)[-1]!=Acbody___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Acbody.expr_gen\"\n");std__panic();
	}
	Aemmiter__expr_gen(_this->side,expr);
	recursive--;
	return __return__;
}
var Acbody__expr_gen_var(var __this, var expr)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Acbody);
	if (((var*)__this)[-1]!=Acbody___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Acbody.expr_gen_var\"\n");std__panic();
	}
	Aemmitc__expr_gen_var(_this->emmiter,expr);
	recursive--;
	return __return__;
}
var Acbody__expr_gen_case(var __this, var expr, var padde)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Acbody);
	if (((var*)__this)[-1]!=Acbody___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Acbody.expr_gen_case\"\n");std__panic();
	}
	Aemmitc__expr_gen_case(_this->emmiter,expr,padde);
	recursive--;
	return __return__;
}
var Acbody__body_gen(var __this, var mb, var k, var vars_, var body1)
{
	static var recursive = 0;
	var __return__ = 0;
	var l;
	var i;
	var tok;
	var va;
	MAKETHIS(Acbody);
	if (((var*)__this)[-1]!=Acbody___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Acbody.body_gen\"\n");std__panic();
	}
	_this->body=body1;
	Aemmitc__set_member(_this->emmiter,mb);
	Aemmiter__set_member(_this->side,mb);
	Aemmitc__fix_datal(_this->emmiter);
	Acbody__add_to_data(__this, (var)(__string_Acbody192+ 2));
	if (_this->debug>0) {
		Acbody__add_to_data(__this, (var)(__string_Acbody193+ 2));
		Acbody__add_to_data(__this, (var)(__string_Acbody194+ 2));
	}
	if (vars_!=0) {
		l=buffer__length(vars_);
	} else {
		l=0;
	}
	i=0;
	while (i<l) {
		va=buffer__get_at(vars_,i);
		Acbody__add_to_data(__this, (var)(__string_Acbody195+ 2));
		tok=Amember__get_name(va);
		Acbody__add_to_data(__this, Atoken__get_data(tok));
		Acbody__add_to_data(__this, (var)(__string_Acbody196+ 2));
		i=i+1;
	}
	if (((((k==(Aclass__Cvirtual)))||((k==(Aclass__Cmethod))))||((k==(Aclass__Cconstructor))))||((k==(Aclass__Casync)))) {
		Acbody__add_to_data(__this, (var)(__string_Acbody197+ 2));
		Acbody__add_to_data(__this, _this->class_name);
		Acbody__add_to_data(__this, (var)(__string_Acbody198+ 2));
	} else {
		Acbody__add_to_data(__this, (var)(__string_Acbody199+ 2));
	}
	if (_this->debug>0) {
		Acbody__gen_debug_rec(__this, mb,k);
	}
	Acbody__gen_statements(__this);
	recursive--;
	return __return__;
}
var Acbody__gen_debug_rec(var __this, var mb, var k)
{
	static var recursive = 0;
	var __return__ = 0;
	var mbs;
	MAKETHIS(Acbody);
	if (((var*)__this)[-1]!=Acbody___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Acbody.gen_debug_rec\"\n");std__panic();
	}
	if (_this->debug>0) {
		mbs=Amember__get_name_string(mb);
		if (k==(Aclass__Cmethod)) {
			Acbody__add_to_data(__this, (var)(__string_Acbody200+ 2));
			Acbody__add_to_data(__this, _this->class_name);
			Acbody__add_to_data(__this, (var)(__string_Acbody201+ 2));
			if ((string__compare(_this->class_name,(var)(__string_Acbody202+ 2)))==0) {
				if ((((string__compare(mbs,(var)(__string_Acbody203+ 2)))==0)||((string__compare(mbs,(var)(__string_Acbody204+ 2)))==0))||((string__compare(mbs,(var)(__string_Acbody205+ 2)))==0)) {
					Acbody__add_to_data(__this, (var)(__string_Acbody206+ 2));
					Acbody__add_to_data(__this, (var)(__string_Acbody207+ 2));
				}
			}
			Acbody__add_to_data(__this, (var)(__string_Acbody208+ 2));
			Acbody__add_to_data(__this, (var)(__string_Acbody209+ 2));
		}
		Acbody__add_to_data(__this, (var)(__string_Acbody210+ 2));
		if (_this->debug>1) {
			Acbody__add_to_data(__this, (var)(__string_Acbody211+ 2));
			Acbody__add_to_data(__this, (var)(__string_Acbody212+ 2));
			Acbody__add_to_data(__this, _this->class_name);
			Acbody__add_to_data(__this, (var)(__string_Acbody213+ 2));
			Acbody__add_to_data(__this, Amember__get_name_string(mb));
			Acbody__add_to_data(__this, (var)(__string_Acbody214+ 2));
		}
	}
	recursive--;
	return __return__;
}
var Acbody__transform_ifblock(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var children;
	var iv;
	var j;
	MAKETHIS(Acbody);
	if (((var*)__this)[-1]!=Acbody___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Acbody.transform_ifblock\"\n");std__panic();
	}
	children=Astatement__get_statements(_this->stm);
	_this->stm=buffer__get_at(children,0);
	iv=Aemmiter__is_switch(_this->side,_this->stm,0);
	if (iv==0) {
		_this->cmb=0;
	} else {
		_this->cmb=Aemmiter__find_variable(_this->side,iv);
	}
	if (_this->cmb==0) {
		iv=0;
	} else {
		if ((Amember__get_type(_this->cmb))!=(Aclass__Cint)) {
			iv=0;
		}
	}
	_this->ty=Aclass__Celseif;
	j=0;
	while (((j<(buffer__length(children)))&&(iv!=0))&&(_this->ty==(Aclass__Celseif))) {
		_this->stm=buffer__get_at(children,j);
		if ((Aemmiter__is_switch(_this->side,_this->stm,iv))==0) {
			iv=0;
			break;
		}
		j=j+1;
	}
	if (j>2) {
		j=j-1;
		_this->stm=buffer__get_at(children,j);
		_this->buf=Astatement__get_else(_this->stm);
		if (_this->buf!=0) {
			_this->stm=buffer__get_at(_this->buf,0);
			Astatement__set_type(_this->stm,Aclass__Cdefault);
		}
		while (j>0) {
			_this->stm=buffer__get_at(children,j);
			Astatement__set_type(_this->stm,Aclass__Ccase);
			j=j-1;
		}
		_this->stm=buffer__get_at(children,j);
		Astatement__set_type(_this->stm,Aclass__Cswitch);
		_this->stm=buffer__get_at(_this->body,_this->i);
		_this->ty=Aclass__Cswitchblock;
		Astatement__set_type(_this->stm,_this->ty);
	} else {
		_this->stm=buffer__get_at(_this->body,_this->i);
		_this->ty=Astatement__get_type(_this->stm);
	}
	recursive--;
	return __return__;
}
var Acbody__prepare_ifblock(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Acbody);
	if (((var*)__this)[-1]!=Acbody___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Acbody.prepare_ifblock\"\n");std__panic();
	}
	buffer__push(_this->stack,_this->l);
	buffer__push(_this->stack,_this->i+1);
	buffer__push(_this->stack,_this->body);
	buffer__push(_this->stack,_this->end);
	if (_this->ty==(Aclass__Cifblock)) {
		_this->end=0;
	} else {
		_this->end=_this->switchend;
	}
	_this->i=-(1);
	_this->l=0;
	_this->body=Astatement__get_statements(_this->stm);
	if (_this->body!=0) {
		_this->l=buffer__length(_this->body);
	}
	recursive--;
	return __return__;
}
var Acbody__gen_if(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Acbody);
	if (((var*)__this)[-1]!=Acbody___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Acbody.gen_if\"\n");std__panic();
	}
	if (_this->ty==(Aclass__Celseif)) {
		Acbody__add_to_data(__this, (var)(__string_Acbody215+ 2));
	} else {
		Acbody__add_to_data(__this, (var)(__string_Acbody216+ 2));
	}
	_this->ex=Astatement__get_expression(_this->stm);
	if (_this->ex!=0) {
		Acbody__expr_gen(__this, _this->ex);
	}
	Acbody__add_to_data(__this, (var)(__string_Acbody217+ 2));
	buffer__push(_this->stack,_this->l);
	buffer__push(_this->stack,_this->i+1);
	buffer__push(_this->stack,_this->body);
	buffer__push(_this->stack,_this->end);
	_this->end=(var)(__string_Acbody218+ 2);
	_this->buf=Astatement__get_else(_this->stm);
	if (_this->buf!=0) {
		buffer__push(_this->stack,buffer__length(_this->buf));
		buffer__push(_this->stack,0);
		buffer__push(_this->stack,_this->buf);
		buffer__push(_this->stack,_this->end);
		_this->end=(var)(__string_Acbody219+ 2);
	}
	_this->padde=_this->padde+1;
	_this->i=-(1);
	_this->l=0;
	_this->body=Astatement__get_statements(_this->stm);
	if (_this->body!=0) {
		_this->l=buffer__length(_this->body);
	}
	recursive--;
	return __return__;
}
var Acbody__gen_return(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Acbody);
	if (((var*)__this)[-1]!=Acbody___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Acbody.gen_return\"\n");std__panic();
	}
	_this->ex=Astatement__get_expression(_this->stm);
	if (_this->ex!=0) {
		if (_this->debug>0) {
			Acbody__add_to_data(__this, (var)(__string_Acbody220+ 2));
			Acbody__expr_gen(__this, _this->ex);
			Acbody__add_to_data(__this, (var)(__string_Acbody221+ 2));
			Acbody__add_to_data(__this, (var)(__string_Acbody222+ 2));
		} else {
			Acbody__add_to_data(__this, (var)(__string_Acbody223+ 2));
			Acbody__expr_gen(__this, _this->ex);
			Acbody__add_to_data(__this, (var)(__string_Acbody224+ 2));
		}
	} else {
		if (_this->debug>0) {
			Acbody__add_to_data(__this, (var)(__string_Acbody225+ 2));
			Acbody__add_to_data(__this, (var)(__string_Acbody226+ 2));
		} else {
			Acbody__add_to_data(__this, (var)(__string_Acbody227+ 2));
		}
	}
	recursive--;
	return __return__;
}
var Acbody__gen_switch(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Acbody);
	if (((var*)__this)[-1]!=Acbody___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Acbody.gen_switch\"\n");std__panic();
	}
	if (_this->ty==(Aclass__Cswitch)) {
		Acbody__add_to_data(__this, (var)(__string_Acbody228+ 2));
		_this->ex=Aemmiter__get_switch_expr(_this->side,_this->stm);
		Acbody__expr_gen_var(__this, _this->ex);
		_this->ex=buffer__pop(_this->_expr_stk);
		Aexpr__data_to_string(_this->ex,Aemmitc__get_data(_this->emmiter));
		Aemmitc__fix_datal(_this->emmiter);
		Acbody__add_to_data(__this, (var)(__string_Acbody229+ 2));
		Acbody__pad(__this, _this->padde);
	}
	_this->ex=Astatement__get_expression(_this->stm);
	if (_this->ex!=0) {
		Acbody__expr_gen_case(__this, _this->ex,_this->padde);
	}
	buffer__push(_this->stack,_this->l);
	buffer__push(_this->stack,_this->i+1);
	buffer__push(_this->stack,_this->body);
	buffer__push(_this->stack,_this->end);
	_this->end=_this->caseend;
	_this->buf=Astatement__get_else(_this->stm);
	if (_this->buf!=0) {
		buffer__push(_this->stack,buffer__length(_this->buf));
		buffer__push(_this->stack,0);
		buffer__push(_this->stack,_this->buf);
		buffer__push(_this->stack,_this->end);
	}
	_this->i=-(1);
	_this->l=0;
	_this->body=Astatement__get_statements(_this->stm);
	if (_this->body!=0) {
		_this->l=buffer__length(_this->body);
	}
	_this->padde=_this->padde+1;
	recursive--;
	return __return__;
}
var Acbody__gen_while(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Acbody);
	if (((var*)__this)[-1]!=Acbody___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Acbody.gen_while\"\n");std__panic();
	}
	Acbody__add_to_data(__this, (var)(__string_Acbody230+ 2));
	_this->ex=Astatement__get_expression(_this->stm);
	if (_this->ex!=0) {
		Acbody__expr_gen(__this, _this->ex);
	}
	Acbody__add_to_data(__this, (var)(__string_Acbody231+ 2));
	buffer__push(_this->stack,_this->l);
	buffer__push(_this->stack,_this->i+1);
	buffer__push(_this->stack,_this->body);
	buffer__push(_this->stack,_this->end);
	_this->end=(var)(__string_Acbody232+ 2);
	_this->i=-(1);
	_this->l=0;
	_this->body=Astatement__get_statements(_this->stm);
	if (_this->body!=0) {
		_this->l=buffer__length(_this->body);
	}
	_this->padde=_this->padde+1;
	recursive--;
	return __return__;
}
var Acbody__gen_do(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Acbody);
	if (((var*)__this)[-1]!=Acbody___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Acbody.gen_do\"\n");std__panic();
	}
	_this->ex=Astatement__get_expression(_this->stm);
	if (_this->ex!=0) {
		Acbody__expr_gen(__this, _this->ex);
	}
	Acbody__add_to_data(__this, (var)(__string_Acbody233+ 2));
	recursive--;
	return __return__;
}
var Acbody__gen_let(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Acbody);
	if (((var*)__this)[-1]!=Acbody___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Acbody.gen_let\"\n");std__panic();
	}
	_this->ex=Astatement__get_expression(_this->stm);
	if (_this->ex!=0) {
		Acbody__expr_gen(__this, _this->ex);
	}
	Acbody__add_to_data(__this, (var)(__string_Acbody234+ 2));
	recursive--;
	return __return__;
}
var Acbody__next_statement(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Acbody);
	if (((var*)__this)[-1]!=Acbody___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Acbody.next_statement\"\n");std__panic();
	}
	_this->i=_this->i+1;
	if ((_this->i>=_this->l)&&(_this->end!=0)) {
		_this->padde=_this->padde-1;
		Acbody__add_to_data(__this, (var)(__string_Acbody235+ 2));
		Acbody__pad(__this, _this->padde);
		Acbody__add_to_data(__this, _this->end);
	}
	while (((_this->i>=_this->l))&&(((buffer__length(_this->stack))>0))) {
		_this->end=buffer__pop(_this->stack);
		_this->body=buffer__pop(_this->stack);
		_this->i=buffer__pop(_this->stack);
		_this->l=buffer__pop(_this->stack);
		if ((_this->i>=_this->l)&&(_this->end!=0)) {
			if (_this->end!=_this->switchend) {
				_this->padde=_this->padde-1;
			}
			Acbody__add_to_data(__this, (var)(__string_Acbody236+ 2));
			Acbody__pad(__this, _this->padde);
			Acbody__add_to_data(__this, _this->end);
		}
	}
	recursive--;
	return __return__;
}
var Acbody__gen_statements(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Acbody);
	if (((var*)__this)[-1]!=Acbody___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Acbody.gen_statements\"\n");std__panic();
	}
	_this->switchend=(var)(__string_Acbody237+ 2);
	_this->caseend=(var)(__string_Acbody238+ 2);
	_this->stack=buffer__new(4,0,__this);
	_this->l=buffer__length(_this->body);
	_this->i=0;
	_this->padde=1;
	_this->end=(var)(__string_Acbody239+ 2);
	while (_this->i<_this->l) {
		_this->stm=buffer__get_at(_this->body,_this->i);
		_this->ty=Astatement__get_type(_this->stm);
		if (_this->ty==(Aclass__Cifblock)) {
			Acbody__transform_ifblock(__this);
		}
		if ((((_this->ty!=(Aclass__Cifblock)))&&((_this->ty!=(Aclass__Celseif))))&&((_this->ty!=(Aclass__Celse)))) {
			Acbody__add_to_data(__this, (var)(__string_Acbody240+ 2));
			Acbody__pad(__this, _this->padde);
		}
		if ((_this->ty==(Aclass__Cifblock))||(_this->ty==(Aclass__Cswitchblock))) {
			Acbody__prepare_ifblock(__this);
		} else if (((_this->ty==(Aclass__Cif)))||((_this->ty==(Aclass__Celseif)))) {
			Acbody__gen_if(__this);
		} else if (_this->ty==(Aclass__Celse)) {
			Acbody__add_to_data(__this, (var)(__string_Acbody241+ 2));
			_this->padde=_this->padde+1;
		} else if (_this->ty==(Aclass__Cdefault)) {
			Acbody__add_to_data(__this, (var)(__string_Acbody242+ 2));
			_this->padde=_this->padde+1;
		} else if (_this->ty==(Aclass__Cbreak)) {
			Acbody__add_to_data(__this, (var)(__string_Acbody243+ 2));
		} else if (_this->ty==(Aclass__Creturn)) {
			Acbody__gen_return(__this);
		} else if (_this->ty==(Aclass__Cdo)) {
			Acbody__gen_do(__this);
		} else if (_this->ty==(Aclass__Clet)) {
			Acbody__gen_let(__this);
		} else if ((_this->ty==(Aclass__Cswitch))||(_this->ty==(Aclass__Ccase))) {
			Acbody__gen_switch(__this);
		} else if (_this->ty==(Aclass__Cwhile)) {
			Acbody__gen_while(__this);
		} else {
			Acbody__add_to_data(__this, (var)(__string_Acbody244+ 2));
		}
		Acbody__next_statement(__this);
	}
	Acbody__add_to_data(__this, (var)(__string_Acbody245+ 2));
	std__delete(_this->stack);
	recursive--;
	return __return__;
}
var Acbody__pad(var __this, var padde)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Acbody);
	if (((var*)__this)[-1]!=Acbody___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Acbody.pad\"\n");std__panic();
	}
	if (0==0) {
		Aemmitc__pad(_this->emmiter,padde);
	}
	recursive--;
	return __return__;
}
/* class Aexpr */
struct Aexpr {
	var op;
	var prec;
	var asso;
	var left;
	var right;
	var parent;
	var value2;
	var flags;
	var origin;
	var data;
};
var Aexpr___new(var __this, var op1, var precedence1, var associativity1, var __parent)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.new\"\n");std__panic();
	}
	_this->op=op1;
	_this->prec=precedence1;
	_this->asso=associativity1;
	_this->parent=0;
	_this->left=0;
	_this->right=0;
	_this->value2=0;
	_this->flags=0;
	_this->origin=0;
	_this->data=0;
	__return__ = __this;
	recursive--;
	return __return__;
}
var Aexpr__new(var op1, var precedence1, var associativity1, var __parent)
{
	NEW(Aexpr);
	return Aexpr___new(__this, op1, precedence1, associativity1, __parent);
}
var Aexpr___V_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.dispose\"\n");std__panic();
	}
	std__delayed_delete(__this);
	recursive--;
	return __return__;
}
var Aexpr___V_delayed_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.delayed_dispose\"\n");std__panic();
	}
	std__delete(_this->left);
	std__delete(_this->right);
	std__delete(_this->value2);
	std__delete(_this->data);
	std__free(__this);
	recursive--;
	return __return__;
}
var Aexpr__clear_data(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.clear_data\"\n");std__panic();
	}
	std__delete(_this->data);
	_this->data=0;
	recursive--;
	return __return__;
}
var Aexpr__add_data(var __this, var value)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.add_data\"\n");std__panic();
	}
	if (value==0) {
		recursive--;
	return __return__;
	}
	if ((string__length(value))<1) {
		recursive--;
	return __return__;
	}
	if (_this->data==0) {
		_this->data=buffer__new(3,0,__this);
	}
	buffer__push(_this->data,value);
	recursive--;
	return __return__;
}
var Aexpr__get_data(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.get_data\"\n");std__panic();
	}
	__return__ = _this->data;
	recursive--;
	return __return__;
}
var Aexpr__merge_data(var __this, var buf)
{
	static var recursive = 0;
	var __return__ = 0;
	var l;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.merge_data\"\n");std__panic();
	}
	l=1;
	if (buf!=0) {
		l=buffer__length(buf);
	}
	if (_this->data==0) {
		_this->data=buffer__new(l,0,__this);
	}
	if (buf==0) {
		recursive--;
	return __return__;
	}
	buffer__append(_this->data,buf);
	recursive--;
	return __return__;
}
var Aexpr__data_to_string(var __this, var s)
{
	static var recursive = 0;
	var __return__ = 0;
	var l;
	var i;
	var ol;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.data_to_string\"\n");std__panic();
	}
	if (_this->data==0) {
		__return__ = s;
	recursive--;
	return __return__;
	}
	ol=string__length(s);
	l=buffer__length(_this->data);
	i=0;
	while (i<l) {
		ol=string__add_at(s,ol,buffer__get_at(_this->data,i));
		i=i+1;
	}
	__return__ = s;
	recursive--;
	return __return__;
}
var Aexpr__get_origin(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.get_origin\"\n");std__panic();
	}
	__return__ = _this->origin;
	recursive--;
	return __return__;
}
var Aexpr__set_origin(var __this, var orig)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.set_origin\"\n");std__panic();
	}
	_this->origin=orig;
	recursive--;
	return __return__;
}
var Aexpr__get_right(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.get_right\"\n");std__panic();
	}
	__return__ = _this->right;
	recursive--;
	return __return__;
}
var Aexpr__set_right(var __this, var r)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.set_right\"\n");std__panic();
	}
	_this->right=std__move(r);
	recursive--;
	return __return__;
}
var Aexpr__get_left(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.get_left\"\n");std__panic();
	}
	__return__ = _this->left;
	recursive--;
	return __return__;
}
var Aexpr__set_left(var __this, var l)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.set_left\"\n");std__panic();
	}
	_this->left=std__move(l);
	recursive--;
	return __return__;
}
var Aexpr__get_parent(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.get_parent\"\n");std__panic();
	}
	__return__ = _this->parent;
	recursive--;
	return __return__;
}
var Aexpr__set_parent(var __this, var p)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.set_parent\"\n");std__panic();
	}
	_this->parent=p;
	recursive--;
	return __return__;
}
var Aexpr__get_value2(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.get_value2\"\n");std__panic();
	}
	__return__ = _this->value2;
	recursive--;
	return __return__;
}
var Aexpr__set_value2(var __this, var v)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.set_value2\"\n");std__panic();
	}
	_this->value2=v;
	recursive--;
	return __return__;
}
var Aexpr__get_value(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.get_value\"\n");std__panic();
	}
	if (_this->data==0) {
		__return__ = 0;
	recursive--;
	return __return__;
	}
	__return__ = buffer__get_at(_this->data,0);
	recursive--;
	return __return__;
}
var Aexpr__set_value(var __this, var v)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.set_value\"\n");std__panic();
	}
	std__delete(_this->data);
	_this->data=buffer__new(1,0,__this);
	buffer__push(_this->data,v);
	recursive--;
	return __return__;
}
var Aexpr__get_op(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.get_op\"\n");std__panic();
	}
	__return__ = _this->op;
	recursive--;
	return __return__;
}
var Aexpr__get_flags(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.get_flags\"\n");std__panic();
	}
	__return__ = _this->flags;
	recursive--;
	return __return__;
}
var Aexpr__set_flags(var __this, var flags_)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.set_flags\"\n");std__panic();
	}
	_this->flags=flags_;
	recursive--;
	return __return__;
}
var Aexpr__set_precedence(var __this, var p)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.set_precedence\"\n");std__panic();
	}
	_this->prec=p;
	recursive--;
	return __return__;
}
var Aexpr__get_precedence(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.get_precedence\"\n");std__panic();
	}
	__return__ = _this->prec;
	recursive--;
	return __return__;
}
var Aexpr__get_associativity(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.get_associativity\"\n");std__panic();
	}
	__return__ = _this->asso;
	recursive--;
	return __return__;
}
var Aexpr__close(var __this, var op_)
{
	static var recursive = 0;
	var __return__ = 0;
	var cur;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.close\"\n");std__panic();
	}
	cur=__this;
	while (cur!=0) {
		if ((Aexpr__get_op(cur))==op_) {
			__return__ = cur;
	recursive--;
	return __return__;
		}
		cur=Aexpr__get_parent(cur);
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var Aexpr__add(var __this, var ex)
{
	static var recursive = 0;
	var __return__ = 0;
	var pre;
	var ass;
	var cur;
	var ri;
	var le;
	var par;
	var child;
	var p;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.add\"\n");std__panic();
	}
	pre=Aexpr__get_precedence(ex);
	ass=Aexpr__get_associativity(ex);
	cur=__this;
	par=Aexpr__get_parent(cur);
	child=0;
	while (par!=0) {
		p=Aexpr__get_precedence(cur);
		if (p>pre) {
			child=cur;
			cur=par;
			par=Aexpr__get_parent(cur);
		} else {
			if (((p==pre))&&((ass==(Aclass__Clr)))) {
				child=cur;
				cur=par;
				par=Aexpr__get_parent(cur);
			} else {
				par=0;
			}
		}
	}
	Aexpr__set_parent(ex,cur);
	ri=Aexpr__get_right(cur);
	if (ri==child) {
		if (ri!=0) {
			Aexpr__set_left(ex,ri);
			Aexpr__set_parent(ri,ex);
		}
		Aexpr__set_right(cur,ex);
	} else {
		le=Aexpr__get_left(cur);
		if (le!=0) {
			Aexpr__set_left(ex,le);
			Aexpr__set_parent(le,ex);
		}
		Aexpr__set_left(cur,ex);
	}
	__return__ = ex;
	recursive--;
	return __return__;
}
var Aexpr__dump(var __this, var depth)
{
	static var recursive = 0;
	var __return__ = 0;
	var i;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.dump\"\n");std__panic();
	}
	if (_this->left!=0) {
		Aexpr__dump(_this->left,depth+1);
	}
	i=depth;
	while (i>0) {
		i=i-1;
		console__log_str((var)(__string_Aexpr246+ 2));
	}
	console__log_str(Aexpr__get_value(__this));
	console__log_str((var)(__string_Aexpr247+ 2));
	console__log_int(_this->op);
	console__log((var)(__string_Aexpr248+ 2));
	if (_this->right!=0) {
		Aexpr__dump(_this->right,depth+1);
	}
	recursive--;
	return __return__;
}
var Aexpr__is_equal_comp1(var __this, var v)
{
	static var recursive = 0;
	var __return__ = 0;
	var l;
	var r;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.is_equal_comp1\"\n");std__panic();
	}
	if (_this->op==(Aclass__Cequal)) {
		l=Aexpr__get_op(_this->left);
		r=Aexpr__get_op(_this->right);
		if (l==(Aclass__Cvar)) {
			if ((r==(Aclass__Cint_const))||(r==(Aclass__Cconstant))) {
				if ((v==0)||(v==(Aexpr__get_value(_this->left)))) {
					__return__ = _this->left;
	recursive--;
	return __return__;
				}
			}
		} else if (r==(Aclass__Cvar)) {
			if ((l==(Aclass__Cint_const))||(l==(Aclass__Cconstant))) {
				if ((v==0)||(v==(Aexpr__get_value(_this->right)))) {
					__return__ = _this->right;
	recursive--;
	return __return__;
				}
			}
		}
		__return__ = 0;
	recursive--;
	return __return__;
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var Aexpr__get_case_expr1(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var l;
	var r;
	var o;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.get_case_expr1\"\n");std__panic();
	}
	o=0;
	if (_this->op==(Aclass__Cequal)) {
		l=Aexpr__get_op(_this->left);
		r=Aexpr__get_op(_this->right);
		if (l==(Aclass__Cvar)) {
			o=_this->right;
		} else if (r==(Aclass__Cvar)) {
			o=_this->left;
		}
		__return__ = o;
	recursive--;
	return __return__;
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var Aexpr__get_switch_expr(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.get_switch_expr\"\n");std__panic();
	}
	__return__ = Aexpr__is_equal_comp1(_this->right,0);
	recursive--;
	return __return__;
}
var Aexpr__get_case_expr(var __this, var pos)
{
	static var recursive = 0;
	var __return__ = 0;
	var opi;
	var n;
	var o;
	var stack;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.get_case_expr\"\n");std__panic();
	}
	if ((Aexpr__get_op(_this->right))==(Aclass__Cequal)) {
		if (pos==0) {
			__return__ = Aexpr__get_case_expr1(_this->right);
	recursive--;
	return __return__;
		}
		__return__ = 0;
	recursive--;
	return __return__;
	}
	stack=buffer__new(5,0,__this);
	buffer__push(stack,_this->right);
	n=0;
	while ((buffer__length(stack))>0) {
		o=buffer__pop(stack);
		opi=0;
		if (o!=0) {
			opi=Aexpr__get_op(o);
		}
		if (opi==(Aclass__Clogicalor)) {
			buffer__push(stack,Aexpr__get_right(o));
			buffer__push(stack,Aexpr__get_left(o));
		} else if (opi==(Aclass__Cequal)) {
			o=Aexpr__get_case_expr1(o);
			if ((o!=0)&&(n==pos)) {
				std__delete(stack);
				__return__ = o;
	recursive--;
	return __return__;
			}
			n=n+1;
		}
	}
	std__delete(stack);
	__return__ = 0;
	recursive--;
	return __return__;
}
var Aexpr__is_equal_comp(var __this, var v)
{
	static var recursive = 0;
	var __return__ = 0;
	var ret;
	var opi;
	var o;
	var stack;
	MAKETHIS(Aexpr);
	if (((var*)__this)[-1]!=Aexpr___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aexpr.is_equal_comp\"\n");std__panic();
	}
	ret=0;
	if ((_this->right!=0)&&(_this->op==(Aclass__Croot))) {
		if ((Aexpr__get_op(_this->right))==(Aclass__Clogicalor)) {
			stack=buffer__new(5,0,__this);
			buffer__push(stack,Aexpr__get_right(_this->right));
			buffer__push(stack,Aexpr__get_left(_this->right));
			while ((buffer__length(stack))>0) {
				o=buffer__pop(stack);
				opi=0;
				if (o!=0) {
					opi=Aexpr__get_op(o);
				}
				if (opi==(Aclass__Clogicalor)) {
					buffer__push(stack,Aexpr__get_right(o));
					buffer__push(stack,Aexpr__get_left(o));
				} else if (opi==(Aclass__Cequal)) {
					ret=Aexpr__is_equal_comp1(o,v);
					if (ret==0) {
						std__delete(stack);
						__return__ = 0;
	recursive--;
	return __return__;
					}
				} else {
					std__delete(stack);
					__return__ = 0;
	recursive--;
	return __return__;
				}
			}
			std__delete(stack);
		} else {
			ret=Aexpr__is_equal_comp1(_this->right,v);
		}
	}
	if (ret==0) {
		__return__ = 0;
	recursive--;
	return __return__;
	}
	__return__ = Aexpr__get_value(ret);
	recursive--;
	return __return__;
}
/* class Alexer */
struct Alexer {
	var _src;
	var _str;
	var _pool;
	var garbage_pool;
	var pos;
	var line;
	var _token;
	var type;
	var c;
	var len;
	var enable_escape;
	var _stringh;
	var _syms;
	var in_string;
	var in_quote;
	var in_comment;
	var in_com_multi;
	var in_escape;
	var in_asm;
	var in_asm_multi;
	var in_number;
	var in_identifier;
	var in_space;
	var need_char;
};
var Alexer___new(var __this, var __parent)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Alexer);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Alexer.new\"\n");std__panic();
	}
	_this->_str=string__new(1024,__this);
	_this->_token=string__new(256,__this);
	_this->_pool=buffer__new(32,0,__this);
	_this->garbage_pool=buffer__new(1024,1,__this);
	_this->_stringh=hash__new(4096,__this);
	_this->_syms=buffer__new(2048,1,__this);
	buffer__push(_this->_syms,0);
	_this->pos=0;
	_this->line=1;
	_this->c=0;
	_this->len=0;
	_this->enable_escape=0;
	_this->need_char=1;
	_this->in_string=0;
	_this->in_quote=0;
	_this->in_comment=0;
	_this->in_com_multi=0;
	_this->in_escape=0;
	_this->in_asm=0;
	_this->in_asm_multi=0;
	_this->in_number=0;
	_this->in_identifier=0;
	_this->in_space=1;
	__return__ = __this;
	recursive--;
	return __return__;
}
var Alexer__new(var __parent)
{
	NEW(Alexer);
	return Alexer___new(__this, __parent);
}
var Alexer___V_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Alexer);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Alexer.dispose\"\n");std__panic();
	}
	std__delete(_this->_str);
	std__delete(_this->_token);
	std__delete(_this->_pool);
	std__delete(_this->garbage_pool);
	std__delete(_this->_stringh);
	std__delete(_this->_syms);
	std__free(__this);
	recursive--;
	return __return__;
}
var Alexer__begin(var __this, var file_)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Alexer);
	if (((var*)__this)[-1]!=Alexer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Alexer.begin\"\n");std__panic();
	}
	_this->pos=0;
	_this->line=1;
	_this->_src=Alexer__get_string(__this, file_);
	recursive--;
	return __return__;
}
var Alexer__get_at(var __this, var x)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Alexer);
	if (((var*)__this)[-1]!=Alexer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Alexer.get_at\"\n");std__panic();
	}
	__return__ = buffer__get_at(_this->_pool,x);
	recursive--;
	return __return__;
}
var Alexer__shift(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Alexer);
	if (((var*)__this)[-1]!=Alexer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Alexer.shift\"\n");std__panic();
	}
	buffer__shift(_this->_pool);
	recursive--;
	return __return__;
}
var Alexer__empty(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Alexer);
	if (((var*)__this)[-1]!=Alexer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Alexer.empty\"\n");std__panic();
	}
	__return__ = buffer__empty(_this->_pool);
	recursive--;
	return __return__;
}
var Alexer__set_enable_escape(var __this, var v)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Alexer);
	if (((var*)__this)[-1]!=Alexer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Alexer.set_enable_escape\"\n");std__panic();
	}
	_this->enable_escape=v;
	recursive--;
	return __return__;
}
var Alexer__get_string(var __this, var str_)
{
	static var recursive = 0;
	var __return__ = 0;
	var s;
	var i;
	MAKETHIS(Alexer);
	if (((var*)__this)[-1]!=Alexer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Alexer.get_string\"\n");std__panic();
	}
	i=hash__get(_this->_stringh,str_);
	if (i>0) {
		__return__ = buffer__get_at(_this->_syms,i);
	recursive--;
	return __return__;
	}
	s=string__new((string__length(str_))+2,__this);
	string__add(s,str_);
	hash__add(_this->_stringh,s,buffer__length(_this->_syms));
	buffer__push(_this->_syms,s);
	__return__ = s;
	recursive--;
	return __return__;
}
var Alexer__get_string_id(var __this, var str_)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Alexer);
	if (((var*)__this)[-1]!=Alexer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Alexer.get_string_id\"\n");std__panic();
	}
	__return__ = hash__get(_this->_stringh,str_);
	recursive--;
	return __return__;
}
var Alexer__add(var __this, var str_)
{
	static var recursive = 0;
	var __return__ = 0;
	var ns;
	MAKETHIS(Alexer);
	if (((var*)__this)[-1]!=Alexer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Alexer.add\"\n");std__panic();
	}
	if (_this->len<0) {
		recursive--;
	return __return__;
	}
	if ((string__length(str_))<1) {
		Alexer__finish(__this);
		recursive--;
	return __return__;
	}
	if (_this->pos<(string__length(_this->_str))) {
		ns=string__new(32,__this);
		string__substr(_this->_str,_this->pos,0,ns);
		string__add(ns,str_);
		std__delete(_this->_str);
		_this->_str=ns;
		string__set(_this->_str,str_);
	} else {
		string__set(_this->_str,str_);
	}
	_this->pos=0;
	_this->len=string__length(_this->_str);
	if (_this->need_char!=0) {
		Alexer__next(__this);
	}
	Alexer__tokenize(__this);
	recursive--;
	return __return__;
}
var Alexer__tokenize(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var s;
	MAKETHIS(Alexer);
	if (((var*)__this)[-1]!=Alexer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Alexer.tokenize\"\n");std__panic();
	}
	s=Alexer__state(__this);
	while ((s!=0)) {
		if (_this->need_char!=0) {
			recursive--;
	return __return__;
		}
		s=Alexer__state(__this);
	}
	recursive--;
	return __return__;
}
var Alexer__is_digit(var __this, var c)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Alexer);
	if (((var*)__this)[-1]!=Alexer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Alexer.is_digit\"\n");std__panic();
	}
	if (((c>='0'))&&((c<='9'))) {
		__return__ = 1;
	recursive--;
	return __return__;
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var Alexer__is_letter(var __this, var c)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Alexer);
	if (((var*)__this)[-1]!=Alexer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Alexer.is_letter\"\n");std__panic();
	}
	if (((((c>='a'))&&((c<='z')))||((((c>='A'))&&((c<='Z')))))) {
		__return__ = 1;
	recursive--;
	return __return__;
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var Alexer__is_space(var __this, var c)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Alexer);
	if (((var*)__this)[-1]!=Alexer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Alexer.is_space\"\n");std__panic();
	}
	if (((((c==' '))||((c=='\t')))||((c=='\n')))||((c=='\r'))) {
		__return__ = 1;
	recursive--;
	return __return__;
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var Alexer__next(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Alexer);
	if (((var*)__this)[-1]!=Alexer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Alexer.next\"\n");std__panic();
	}
	if (_this->pos>=_this->len) {
		_this->need_char=1;
		_this->c='\0';
		__return__ = 0;
	recursive--;
	return __return__;
	}
	_this->need_char=0;
	_this->c=string__get_at(_this->_str,_this->pos);
	_this->pos=_this->pos+1;
	__return__ = 1;
	recursive--;
	return __return__;
}
var Alexer__validate(var __this, var type_)
{
	static var recursive = 0;
	var __return__ = 0;
	var t;
	MAKETHIS(Alexer);
	if (((var*)__this)[-1]!=Alexer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Alexer.validate\"\n");std__panic();
	}
	if (type_==(Alexer__Cnewline)) {
		_this->line=_this->line+1;
	}
	t=Atoken__new(type_,Alexer__get_string(__this, _this->_token),_this->line,_this->_src,__this);
	buffer__push(_this->_pool,t);
	buffer__push(_this->garbage_pool,t);
	string__set_at(_this->_token,0,'\0');
	recursive--;
	return __return__;
}
var Alexer__error(var __this, var msg)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Alexer);
	if (((var*)__this)[-1]!=Alexer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Alexer.error\"\n");std__panic();
	}
	console__log_str((var)(__string_Alexer249+ 2));
	console__log_str(_this->_src);
	console__log_str((var)(__string_Alexer250+ 2));
	console__log_int(_this->line);
	console__log_str((var)(__string_Alexer251+ 2));
	console__log_str(_this->_token);
	console__log_str((var)(__string_Alexer252+ 2));
	console__log(msg);
	_this->len=-(1);
	recursive--;
	return __return__;
}
var Alexer__state(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var l;
	var a;
	var b;
	var d;
	MAKETHIS(Alexer);
	if (((var*)__this)[-1]!=Alexer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Alexer.state\"\n");std__panic();
	}
	if (_this->in_escape!=0) {
		if (_this->enable_escape==0) {
			if (_this->c!='\n') {
				string__add_char(_this->_token,'\\');
				string__add_char(_this->_token,_this->c);
				Alexer__next(__this);
				_this->in_escape=0;
				__return__ = 1;
	recursive--;
	return __return__;
			}
			_this->line=_this->line+1;
		} else if (_this->c!='\n') {
			a=_this->c;
			if (_this->c=='0') {
				a=0;
			} else if (_this->c=='n') {
				a='\n';
			} else if (_this->c=='t') {
				a='\t';
			} else if (_this->c=='b') {
				a='\b';
			} else {
				string__add_char(_this->_token,'\\');
			}
			string__add_char(_this->_token,a);
		} else {
			_this->line=_this->line+1;
		}
		Alexer__next(__this);
		_this->in_escape=0;
		__return__ = 1;
	recursive--;
	return __return__;
	} else if (_this->in_string!=0) {
		if (_this->c=='"') {
			_this->in_string=0;
			Alexer__validate(__this, Alexer__Cstring);
		} else if (_this->c=='\\') {
			_this->in_escape=1;
		} else if (_this->c=='\n') {
			Alexer__error(__this, (var)(__string_Alexer253+ 2));
			__return__ = 0;
	recursive--;
	return __return__;
		} else {
			string__add_char(_this->_token,_this->c);
		}
		Alexer__next(__this);
		__return__ = 1;
	recursive--;
	return __return__;
	} else if (_this->in_quote!=0) {
		if (_this->c=='\'') {
			_this->in_quote=0;
			Alexer__validate(__this, Alexer__Cquote);
		} else if (_this->c=='\\') {
			_this->in_escape=1;
		} else {
			string__add_char(_this->_token,_this->c);
		}
		Alexer__next(__this);
		__return__ = 1;
	recursive--;
	return __return__;
	} else if (_this->in_comment!=0) {
		if (_this->in_comment==(-(1))) {
			if (_this->c=='/') {
				_this->in_comment=1;
				Alexer__next(__this);
				__return__ = 1;
	recursive--;
	return __return__;
			} else if (_this->c=='*') {
				_this->in_comment=0;
				_this->in_com_multi=1;
				Alexer__next(__this);
				__return__ = 1;
	recursive--;
	return __return__;
			}
			_this->in_comment=0;
			string__add_char(_this->_token,'/');
			__return__ = 1;
	recursive--;
	return __return__;
		} else if (_this->in_comment==1) {
			if (_this->c=='#') {
				_this->in_asm=1;
				_this->in_comment=0;
				Alexer__next(__this);
				__return__ = 1;
	recursive--;
	return __return__;
			}
			_this->in_comment=2;
		}
		if (_this->c=='\n') {
			_this->in_comment=0;
			Alexer__validate(__this, Alexer__Ccomment);
			Alexer__validate(__this, Alexer__Cnewline);
		}
		if (_this->c=='\0') {
			__return__ = 0;
	recursive--;
	return __return__;
		}
		Alexer__next(__this);
		__return__ = 1;
	recursive--;
	return __return__;
	} else if (_this->in_com_multi!=0) {
		
		switch (_this->in_com_multi) {
		case 1: 
			if (_this->c=='#') {
				_this->in_asm_multi=2;
				_this->in_com_multi=0;
				Alexer__next(__this);
				__return__ = 1;
	recursive--;
	return __return__;
			}
			_this->in_com_multi=2;
			break;
		case 2: 
			if (_this->c=='*') {
				_this->in_com_multi=3;
				Alexer__next(__this);
				__return__ = 1;
	recursive--;
	return __return__;
			}
			break;
		case 3: 
			if (_this->c=='/') {
				_this->in_com_multi=0;
				Alexer__validate(__this, Alexer__Ccomment);
				Alexer__next(__this);
				__return__ = 1;
	recursive--;
	return __return__;
			}
			_this->in_com_multi=2;
			break;
		} 
		Alexer__next(__this);
		__return__ = 1;
	recursive--;
	return __return__;
	} else if (_this->in_asm!=0) {
		if (_this->c=='\n') {
			Alexer__validate(__this, Alexer__Casm);
			Alexer__validate(__this, Alexer__Cnewline);
			_this->in_asm=0;
			Alexer__next(__this);
			__return__ = 1;
	recursive--;
	return __return__;
		}
		if (_this->c=='\0') {
			__return__ = 0;
	recursive--;
	return __return__;
		}
		string__add_char(_this->_token,_this->c);
		Alexer__next(__this);
		__return__ = 1;
	recursive--;
	return __return__;
	} else if (_this->in_asm_multi!=0) {
		if (_this->in_asm_multi==2) {
			if (_this->c=='*') {
				_this->in_asm_multi=3;
				Alexer__next(__this);
				__return__ = 1;
	recursive--;
	return __return__;
			}
		} else if (_this->in_asm_multi==3) {
			if (_this->c=='/') {
				_this->in_asm_multi=0;
				Alexer__validate(__this, Alexer__Casm);
				Alexer__next(__this);
				__return__ = 1;
	recursive--;
	return __return__;
			}
			_this->in_asm_multi=2;
		}
		string__add_char(_this->_token,_this->c);
		Alexer__next(__this);
		__return__ = 1;
	recursive--;
	return __return__;
	} else if (_this->in_number!=0) {
		if ((Alexer__is_digit(__this, _this->c))!=0) {
			string__add_char(_this->_token,_this->c);
			Alexer__next(__this);
		} else {
			_this->in_number=0;
			Alexer__validate(__this, Alexer__Cnumber);
		}
		__return__ = 1;
	recursive--;
	return __return__;
	} else if (_this->in_identifier!=0) {
		while ((((_this->c=='_'))||(((Alexer__is_letter(__this, _this->c))!=0)))||(((Alexer__is_digit(__this, _this->c))!=0))) {
			string__add_char(_this->_token,_this->c);
			if ((Alexer__next(__this))==0) {
				__return__ = 1;
	recursive--;
	return __return__;
			}
		}
		Alexer__validate(__this, Alexer__Cidentifier);
		_this->in_identifier=0;
		__return__ = 1;
	recursive--;
	return __return__;
	} else if (_this->in_space!=0) {
		while ((Alexer__is_space(__this, _this->c))!=0) {
			if (_this->c=='\n') {
				Alexer__validate(__this, Alexer__Cnewline);
			}
			if ((Alexer__next(__this))==0) {
				__return__ = 1;
	recursive--;
	return __return__;
			}
		}
		_this->in_space=0;
		__return__ = 1;
	recursive--;
	return __return__;
	} else {
		l=string__length(_this->_token);
		if ((Alexer__is_space(__this, _this->c))!=0) {
			if (l!=0) {
				Alexer__validate(__this, Alexer__Coperator);
			}
			_this->in_space=1;
			__return__ = 1;
	recursive--;
	return __return__;
		} else if (l==0) {
			if ((Alexer__is_digit(__this, _this->c))!=0) {
				string__add_char(_this->_token,_this->c);
				Alexer__next(__this);
				_this->in_number=1;
				__return__ = 1;
	recursive--;
	return __return__;
			} else if (((_this->c=='_'))||(((Alexer__is_letter(__this, _this->c))!=0))) {
				string__add_char(_this->_token,_this->c);
				Alexer__next(__this);
				_this->in_identifier=1;
				__return__ = 1;
	recursive--;
	return __return__;
			} else if (_this->c=='\'') {
				Alexer__next(__this);
				_this->in_quote=1;
				__return__ = 1;
	recursive--;
	return __return__;
			} else if (_this->c=='"') {
				Alexer__next(__this);
				_this->in_string=1;
				__return__ = 1;
	recursive--;
	return __return__;
			} else if ((_this->c=='/')) {
				Alexer__next(__this);
				_this->in_comment=-(1);
				__return__ = 1;
	recursive--;
	return __return__;
			}
			string__add_char(_this->_token,_this->c);
			Alexer__next(__this);
			__return__ = 1;
	recursive--;
	return __return__;
		} else if (l==1) {
			a=string__get_at(_this->_token,0);
			if (_this->c=='=') {
				if (((((((((((((a=='+'))||((a=='-')))||((a==':')))||((a=='*')))||((a=='/')))||((a=='%')))||((a=='&')))||((a=='^')))||((a=='|')))||((a=='>')))||((a=='<')))||((a=='~'))) {
					string__add_char(_this->_token,_this->c);
					Alexer__validate(__this, Alexer__Coperator);
					Alexer__next(__this);
					__return__ = 1;
	recursive--;
	return __return__;
				} else if (((a=='='))||((a=='!'))) {
					string__add_char(_this->_token,_this->c);
					Alexer__next(__this);
					__return__ = 1;
	recursive--;
	return __return__;
				}
			} else if (((((a=='+'))&&((_this->c=='+')))||(((((a=='-'))&&((_this->c=='>')))||(((((a==':'))&&((_this->c==':')))||(((((a=='|'))&&((_this->c=='|')))||(((((a=='&'))&&((_this->c=='&')))||(((((a=='.'))&&((_this->c=='$')))||((((a=='-'))&&((_this->c=='-')))))))))))))))) {
				string__add_char(_this->_token,_this->c);
				Alexer__validate(__this, Alexer__Coperator);
				Alexer__next(__this);
				__return__ = 1;
	recursive--;
	return __return__;
			} else if (((((a=='>'))&&((_this->c=='>')))||(((((a=='.'))&&((_this->c=='.')))||((((a=='<'))&&((_this->c=='<')))))))) {
				string__add_char(_this->_token,_this->c);
				Alexer__next(__this);
				__return__ = 1;
	recursive--;
	return __return__;
			}
			Alexer__validate(__this, Alexer__Coperator);
			__return__ = 1;
	recursive--;
	return __return__;
		} else if (l==2) {
			a=string__get_at(_this->_token,0);
			b=string__get_at(_this->_token,1);
			if ((((((a=='!'))&&((b=='=')))&&((_this->c=='=')))||((((((a=='='))&&((b=='=')))&&((_this->c=='=')))||((((((a=='>'))&&((b=='>')))&&((_this->c=='=')))||((((((a=='.'))&&((b=='.')))&&((_this->c=='.')))||(((((a=='<'))&&((b=='<')))&&((_this->c=='=')))))))))))) {
				string__add_char(_this->_token,_this->c);
				Alexer__validate(__this, Alexer__Coperator);
				Alexer__next(__this);
				__return__ = 1;
	recursive--;
	return __return__;
			} else if (((((a=='>'))&&((b=='>')))&&((_this->c=='>')))) {
				string__add_char(_this->_token,_this->c);
				Alexer__next(__this);
				__return__ = 1;
	recursive--;
	return __return__;
			}
			Alexer__validate(__this, Alexer__Coperator);
			__return__ = 1;
	recursive--;
	return __return__;
		} else {
			a=string__get_at(_this->_token,0);
			b=string__get_at(_this->_token,1);
			d=string__get_at(_this->_token,2);
			if (((((a=='>'))&&((b=='>')))&&((d=='>')))&&((_this->c=='='))) {
				string__add_char(_this->_token,_this->c);
				Alexer__validate(__this, Alexer__Coperator);
				Alexer__next(__this);
				__return__ = 1;
	recursive--;
	return __return__;
			}
			Alexer__validate(__this, Alexer__Coperator);
			__return__ = 1;
	recursive--;
	return __return__;
		}
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var Alexer__finish(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Alexer);
	if (((var*)__this)[-1]!=Alexer___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Alexer.finish\"\n");std__panic();
	}
	if ((string__length(_this->_token))>0) {
		Alexer__error(__this, (var)(__string_Alexer254+ 2));
	}
	Alexer__validate(__this, Alexer__Cend);
	recursive--;
	return __return__;
}
/* class Amember */
struct Amember {
	var kind;
	var type;
	var type_id;
	var name;
	var initial_value;
	var index;
	var params;
	var vars;
	var body;
	var own;
};
var Amember___new(var __this, var kind1, var type1, var type_id1, var name1, var __parent)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Amember);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.new\"\n");std__panic();
	}
	_this->own=0;
	_this->kind=kind1;
	_this->type=type1;
	_this->name=name1;
	_this->type_id=type_id1;
	_this->initial_value=0;
	_this->index=-(1);
	_this->params=0;
	_this->vars=0;
	_this->body=0;
	__return__ = __this;
	recursive--;
	return __return__;
}
var Amember__new(var kind1, var type1, var type_id1, var name1, var __parent)
{
	NEW(Amember);
	return Amember___new(__this, kind1, type1, type_id1, name1, __parent);
}
var Amember___V_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Amember);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.dispose\"\n");std__panic();
	}
	if (_this->own) {
		std__delete(_this->name);
		std__delete(_this->type_id);
	}
	std__delete(_this->params);
	_this->params=0;
	std__delete(_this->body);
	_this->body=0;
	std__delete(_this->vars);
	_this->vars=0;
	std__free(__this);
	recursive--;
	return __return__;
}
var Amember__copy(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var cp;
	var m;
	var o;
	var t;
	MAKETHIS(Amember);
	if (((var*)__this)[-1]!=Amember___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.copy\"\n");std__panic();
	}
	cp=buffer__new(64,0,__this);
	m=Amember__pre_copy(__this, cp);
	while ((buffer__length(cp))>0) {
		t=buffer__pop(cp);
		o=buffer__pop(cp);
		Amember__copy_params(o,t,cp);
	}
	std__delete(cp);
	__return__ = m;
	recursive--;
	return __return__;
}
var Amember__pre_copy(var __this, var cp)
{
	static var recursive = 0;
	var __return__ = 0;
	var id;
	var n;
	var m;
	var p;
	var l;
	MAKETHIS(Amember);
	if (((var*)__this)[-1]!=Amember___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.pre_copy\"\n");std__panic();
	}
	if (_this->type_id!=0) {
		id=Atoken__copy(_this->type_id);
	} else {
		id=0;
	}
	if (_this->name!=0) {
		n=Atoken__copy(_this->name);
	} else {
		n=0;
	}
	m=Amember__new(_this->kind,_this->type,id,n,__this);
	Amember__take(m);
	p=Amember__get_params(__this);
	if (p==0) {
		__return__ = m;
	recursive--;
	return __return__;
	}
	l=buffer__length(p);
	if (l<1) {
		__return__ = m;
	recursive--;
	return __return__;
	}
	buffer__push(cp,m);
	buffer__push(cp,__this);
	__return__ = m;
	recursive--;
	return __return__;
}
var Amember__take(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Amember);
	if (((var*)__this)[-1]!=Amember___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.take\"\n");std__panic();
	}
	std__move(_this->type_id);
	std__move(_this->name);
	_this->own=1;
	recursive--;
	return __return__;
}
var Amember__copy_params(var __this, var o, var cp)
{
	static var recursive = 0;
	var __return__ = 0;
	var l;
	var p;
	var m;
	MAKETHIS(Amember);
	if (((var*)__this)[-1]!=Amember___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.copy_params\"\n");std__panic();
	}
	p=Amember__get_params(o);
	if (p==0) {
		recursive--;
	return __return__;
	}
	l=buffer__length(p);
	if (l<1) {
		recursive--;
	return __return__;
	}
	_this->params=buffer__new(l,1,__this);
	while (l>0) {
		l=l-1;
		m=buffer__get_at(p,l);
		buffer__set_at(_this->params,l,Amember__pre_copy(m,cp));
	}
	recursive--;
	return __return__;
}
var Amember__dispose_body(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Amember);
	if (((var*)__this)[-1]!=Amember___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.dispose_body\"\n");std__panic();
	}
	std__delete(_this->body);
	_this->body=0;
	std__delete(_this->vars);
	_this->vars=0;
	recursive--;
	return __return__;
}
var Amember__get_kind(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Amember);
	if (((var*)__this)[-1]!=Amember___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.get_kind\"\n");std__panic();
	}
	__return__ = _this->kind;
	recursive--;
	return __return__;
}
var Amember__get_type(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Amember);
	if (((var*)__this)[-1]!=Amember___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.get_type\"\n");std__panic();
	}
	__return__ = _this->type;
	recursive--;
	return __return__;
}
var Amember__get_type_id(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Amember);
	if (((var*)__this)[-1]!=Amember___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.get_type_id\"\n");std__panic();
	}
	__return__ = _this->type_id;
	recursive--;
	return __return__;
}
var Amember__get_name(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Amember);
	if (((var*)__this)[-1]!=Amember___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.get_name\"\n");std__panic();
	}
	__return__ = _this->name;
	recursive--;
	return __return__;
}
var Amember__get_name_string(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Amember);
	if (((var*)__this)[-1]!=Amember___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.get_name_string\"\n");std__panic();
	}
	__return__ = Atoken__get_data(_this->name);
	recursive--;
	return __return__;
}
var Amember__get_initial_value(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Amember);
	if (((var*)__this)[-1]!=Amember___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.get_initial_value\"\n");std__panic();
	}
	__return__ = _this->initial_value;
	recursive--;
	return __return__;
}
var Amember__set_initial_value(var __this, var initial_value1)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Amember);
	if (((var*)__this)[-1]!=Amember___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.set_initial_value\"\n");std__panic();
	}
	_this->initial_value=initial_value1;
	recursive--;
	return __return__;
}
var Amember__set_index(var __this, var index1)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Amember);
	if (((var*)__this)[-1]!=Amember___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.set_index\"\n");std__panic();
	}
	_this->index=index1;
	recursive--;
	return __return__;
}
var Amember__get_index(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Amember);
	if (((var*)__this)[-1]!=Amember___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.get_index\"\n");std__panic();
	}
	__return__ = _this->index;
	recursive--;
	return __return__;
}
var Amember__get_body(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Amember);
	if (((var*)__this)[-1]!=Amember___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.get_body\"\n");std__panic();
	}
	__return__ = _this->body;
	recursive--;
	return __return__;
}
var Amember__get_vars(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Amember);
	if (((var*)__this)[-1]!=Amember___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.get_vars\"\n");std__panic();
	}
	__return__ = _this->vars;
	recursive--;
	return __return__;
}
var Amember__get_params(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Amember);
	if (((var*)__this)[-1]!=Amember___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.get_params\"\n");std__panic();
	}
	__return__ = _this->params;
	recursive--;
	return __return__;
}
var Amember__add_param(var __this, var kind1, var type1, var type_id1, var name1)
{
	static var recursive = 0;
	var __return__ = 0;
	var p;
	MAKETHIS(Amember);
	if (((var*)__this)[-1]!=Amember___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.add_param\"\n");std__panic();
	}
	if (_this->params==0) {
		_this->params=buffer__new(4,1,__this);
	}
	p=Amember__new(kind1,type1,type_id1,name1,__this);
	buffer__push(_this->params,p);
	recursive--;
	return __return__;
}
var Amember__add_var(var __this, var kind1, var type1, var type_id1, var name1)
{
	static var recursive = 0;
	var __return__ = 0;
	var p;
	MAKETHIS(Amember);
	if (((var*)__this)[-1]!=Amember___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.add_var\"\n");std__panic();
	}
	if (_this->vars==0) {
		_this->vars=buffer__new(4,1,__this);
	}
	p=Amember__new(kind1,type1,type_id1,name1,__this);
	buffer__push(_this->vars,p);
	recursive--;
	return __return__;
}
var Amember__add_statement(var __this, var statement1)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Amember);
	if (((var*)__this)[-1]!=Amember___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Amember.add_statement\"\n");std__panic();
	}
	if (_this->body==0) {
		_this->body=buffer__new(4,1,__this);
	}
	buffer__push(_this->body,statement1);
	__return__ = Astatement__get_parent(statement1);
	recursive--;
	return __return__;
}
/* class Aparser */
struct Aparser {
	var _states;
	var lex;
	var lookahead;
	var lookstring;
	var status;
	var debug;
	var _class;
};
var Aparser___new(var __this, var __parent)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.new\"\n");std__panic();
	}
	_this->debug=0;
	_this->status=0;
	_this->lex=0;
	_this->_states=buffer__new(8,0,__this);
	_this->_class=0;
	Aparser__push(__this, Aparser__Croot);
	__return__ = __this;
	recursive--;
	return __return__;
}
var Aparser__new(var __parent)
{
	NEW(Aparser);
	return Aparser___new(__this, __parent);
}
var Aparser___V_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.dispose\"\n");std__panic();
	}
	std__delete(_this->_states);
	std__delete(_this->_class);
	std__free(__this);
	recursive--;
	return __return__;
}
var Aparser__get_data(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.get_data\"\n");std__panic();
	}
	__return__ = _this->lookstring;
	recursive--;
	return __return__;
}
var Aparser__get_next(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.get_next\"\n");std__panic();
	}
	__return__ = _this->_class;
	recursive--;
	return __return__;
}
var Aparser__release(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.release\"\n");std__panic();
	}
	std__delete(_this->_class);
	_this->_class=0;
	recursive--;
	return __return__;
}
var Aparser__parse(var __this, var lexer_)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.parse\"\n");std__panic();
	}
	_this->lex=lexer_;
	while ((Alexer__empty(_this->lex))==0) {
		_this->lookahead=Alexer__get_at(_this->lex,0);
		_this->lookstring=Atoken__get_data(_this->lookahead);
		if ((((Atoken__get_type(_this->lookahead))==(Alexer__Cnewline)))||(((Atoken__get_type(_this->lookahead))==(Alexer__Ccomment)))) {
			Aparser__eat(__this);
		} else {
			Aparser__state_machine(__this);
		}
		if ((Alexer__empty(_this->lex))!=0) {
			__return__ = 0;
	recursive--;
	return __return__;
		}
		if ((Atoken__get_type(_this->lookahead))==(Alexer__Cend)) {
			Aparser__eat(__this);
			__return__ = 0;
	recursive--;
	return __return__;
		}
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var Aparser__error(var __this, var e)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.error\"\n");std__panic();
	}
	console__log_str(Atoken__get_file(_this->lookahead));
	console__log_str((var)(__string_Aparser255+ 2));
	console__log_str(Atoken__get_data(_this->lookahead));
	console__log_str((var)(__string_Aparser256+ 2));
	console__log_int(Atoken__get_line(_this->lookahead));
	console__log_str((var)(__string_Aparser257+ 2));
	console__log(e);
	std__exit(-(1));
	_this->status=-(1);
	recursive--;
	return __return__;
}
var Aparser__push(var __this, var step_)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.push\"\n");std__panic();
	}
	buffer__push(_this->_states,step_);
	recursive--;
	return __return__;
}
var Aparser__pop(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.pop\"\n");std__panic();
	}
	buffer__pop(_this->_states);
	recursive--;
	return __return__;
}
var Aparser__root(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.root\"\n");std__panic();
	}
	if (_this->status!=0) {
		__return__ = -(1);
	recursive--;
	return __return__;
	}
	Aparser__push(__this, Aparser__Cclass_dec);
	__return__ = 0;
	recursive--;
	return __return__;
}
var Aparser__class_dec(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var c;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.class_dec\"\n");std__panic();
	}
	if ((Aparser__match_id(__this, (var)(__string_Aparser258+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser259+ 2));
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	if ((Aparser__match_id(__this, 0))==0) {
		Aparser__error(__this, (var)(__string_Aparser260+ 2));
		recursive--;
	return __return__;
	}
	c=_this->_class;
	_this->_class=Aclass__new(_this->lookahead,__this);
	Aclass__set_next(_this->_class,c);
	Aparser__eat(__this);
	if (Aparser__match_id(__this, (var)(__string_Aparser261+ 2))) {
		Aparser__eat(__this);
		if ((Aparser__match_id(__this, 0))==0) {
			Aparser__error(__this, (var)(__string_Aparser262+ 2));
			recursive--;
	return __return__;
		}
		Aclass__add_implements(_this->_class,_this->lookahead);
		Aparser__eat(__this);
		while ((Aparser__match_op(__this, (var)(__string_Aparser263+ 2)))!=0) {
			Aparser__eat(__this);
			if ((Aparser__match_id(__this, 0))==0) {
				Aparser__error(__this, (var)(__string_Aparser264+ 2));
				recursive--;
	return __return__;
			}
			Aclass__add_implements(_this->_class,_this->lookahead);
			Aparser__eat(__this);
		}
	}
	if ((Aparser__match_op(__this, (var)(__string_Aparser265+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser266+ 2));
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	while (_this->status>=0) {
		Aparser__class_var_dec(__this);
	}
	_this->status=0;
	while (_this->status>=0) {
		Aparser__clas_const_dec(__this);
	}
	_this->status=0;
	Aparser__push(__this, Aparser__Cclass_dec1);
	Aparser__push(__this, Aparser__Csubroutine_dec);
	recursive--;
	return __return__;
}
var Aparser__class_dec1(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.class_dec1\"\n");std__panic();
	}
	_this->status=0;
	if ((Aparser__match_op(__this, (var)(__string_Aparser267+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser268+ 2));
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	Aparser__pop(__this);
	recursive--;
	return __return__;
}
var Aparser__class_var_dec(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.class_var_dec\"\n");std__panic();
	}
	if ((Aparser__match_id(__this, (var)(__string_Aparser269+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Cfield);
	} else if ((Aparser__match_id(__this, (var)(__string_Aparser270+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Cstatic);
	} else {
		_this->status=-(1);
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	Aparser__type(__this);
	Aparser__var_name(__this);
	while ((Aparser__match_op(__this, (var)(__string_Aparser271+ 2)))!=0) {
		Aclass__valid_member_name(_this->_class);
		Aparser__var_name(__this);
	}
	if ((Aparser__match_op(__this, (var)(__string_Aparser272+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser273+ 2));
		recursive--;
	return __return__;
	}
	Aclass__valid_member_name(_this->_class);
	Aparser__eat(__this);
	recursive--;
	return __return__;
}
var Aparser__var_name(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.var_name\"\n");std__panic();
	}
	if ((Aparser__match_id(__this, 0))!=0) {
		Aclass__prepare_set_name(_this->_class,_this->lookahead);
		Aparser__eat(__this);
		recursive--;
	return __return__;
	}
	Aparser__error(__this, (var)(__string_Aparser274+ 2));
	recursive--;
	return __return__;
}
var Aparser__type(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.type\"\n");std__panic();
	}
	if ((Aparser__match_id(__this, (var)(__string_Aparser275+ 2)))!=0) {
		Aclass__prepare_type(_this->_class,Aclass__Cint);
	} else if ((Aparser__match_id(__this, (var)(__string_Aparser276+ 2)))!=0) {
		Aclass__prepare_type(_this->_class,Aclass__Cvoid);
	} else if ((Aparser__match_id(__this, 0))!=0) {
		Aclass__prepare_type_identifier(_this->_class,_this->lookahead);
	} else {
		Aparser__error(__this, (var)(__string_Aparser277+ 2));
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	recursive--;
	return __return__;
}
var Aparser__clas_const_dec(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.clas_const_dec\"\n");std__panic();
	}
	if ((Aparser__match_id(__this, (var)(__string_Aparser278+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Cconst);
	} else {
		_this->status=-(1);
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	Aparser__type(__this);
	Aparser__var_name(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser279+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser280+ 2));
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser281+ 2)))==0) {
		Aclass__finish_const(_this->_class,_this->lookahead);
	} else {
		Aparser__error(__this, (var)(__string_Aparser282+ 2));
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser283+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser284+ 2));
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	recursive--;
	return __return__;
}
var Aparser__subroutine_dec(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.subroutine_dec\"\n");std__panic();
	}
	if (_this->status!=0) {
		Aparser__pop(__this);
		recursive--;
	return __return__;
	}
	if ((Aparser__match_id(__this, (var)(__string_Aparser285+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Cconstructor);
	} else if ((Aparser__match_id(__this, (var)(__string_Aparser286+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Cfunction);
	} else if ((Aparser__match_id(__this, (var)(__string_Aparser287+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Cmethod);
	} else if ((Aparser__match_id(__this, (var)(__string_Aparser288+ 2)))!=0) {
		std__panic();
		Aclass__prepare_kind(_this->_class,Aclass__Casync);
	} else if ((Aparser__match_id(__this, (var)(__string_Aparser289+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Cvirtual);
	} else {
		Aparser__pop(__this);
		_this->status=-(1);
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	if ((Aparser__match_id(__this, (var)(__string_Aparser290+ 2)))!=0) {
		Aclass__prepare_type(_this->_class,Aclass__Cvoid);
		Aparser__eat(__this);
	} else {
		Aparser__type(__this);
	}
	Aparser__var_name(__this);
	Aclass__valid_member_name(_this->_class);
	if ((Aparser__match_op(__this, (var)(__string_Aparser291+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser292+ 2));
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	Aparser__param_list(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser293+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser294+ 2));
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	Aparser__subrout_body(__this);
	recursive--;
	return __return__;
}
var Aparser__param_list(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.param_list\"\n");std__panic();
	}
	if ((Aparser__match_op(__this, (var)(__string_Aparser295+ 2)))!=0) {
		recursive--;
	return __return__;
	}
	Aparser__direction(__this);
	Aparser__type(__this);
	Aparser__var_name(__this);
	while ((Aparser__match_op(__this, (var)(__string_Aparser296+ 2)))!=0) {
		Aclass__valid_param(_this->_class);
		Aparser__eat(__this);
		Aparser__direction(__this);
		Aparser__type(__this);
		Aparser__var_name(__this);
	}
	Aclass__valid_param(_this->_class);
	recursive--;
	return __return__;
}
var Aparser__direction(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.direction\"\n");std__panic();
	}
	if ((Aparser__match_id(__this, (var)(__string_Aparser297+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Cin);
		Aparser__eat(__this);
		recursive--;
	return __return__;
	} else if ((Aparser__match_id(__this, (var)(__string_Aparser298+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Cout);
		Aparser__eat(__this);
		recursive--;
	return __return__;
	} else if ((Aparser__match_id(__this, (var)(__string_Aparser299+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Cio);
		Aparser__eat(__this);
		recursive--;
	return __return__;
	} else if ((Aparser__match_id(__this, (var)(__string_Aparser300+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Casync);
		Aparser__eat(__this);
		recursive--;
	return __return__;
	}
	Aparser__error(__this, (var)(__string_Aparser301+ 2));
	recursive--;
	return __return__;
}
var Aparser__lambda_body(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.lambda_body\"\n");std__panic();
	}
	if ((Aparser__match_op(__this, (var)(__string_Aparser302+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser303+ 2));
		recursive--;
	return __return__;
	}
	Aclass__begin_lambda(_this->_class,_this->lookahead);
	Aparser__eat(__this);
	while (_this->status==0) {
		Aparser__var_dec(__this);
	}
	_this->status=0;
	Aparser__push(__this, Aparser__Clambda_body1);
	Aparser__push(__this, Aparser__Cstatements);
	recursive--;
	return __return__;
}
var Aparser__lambda_body1(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.lambda_body1\"\n");std__panic();
	}
	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser304+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser305+ 2));
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	Aclass__finish_lambda(_this->_class);
	recursive--;
	return __return__;
}
var Aparser__subrout_body(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.subrout_body\"\n");std__panic();
	}
	if ((Aparser__match_op(__this, (var)(__string_Aparser306+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser307+ 2));
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	while (_this->status==0) {
		Aparser__var_dec(__this);
	}
	_this->status=0;
	Aparser__push(__this, Aparser__Csubrout_body1);
	Aparser__push(__this, Aparser__Cstatements);
	recursive--;
	return __return__;
}
var Aparser__subrout_body1(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.subrout_body1\"\n");std__panic();
	}
	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser308+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser309+ 2));
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	Aclass__finish_subroutine(_this->_class);
	recursive--;
	return __return__;
}
var Aparser__var_dec(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.var_dec\"\n");std__panic();
	}
	if ((Aparser__match_id(__this, (var)(__string_Aparser310+ 2)))==0) {
		_this->status=1;
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	Aclass__prepare_kind(_this->_class,Aclass__Cvar);
	Aparser__type(__this);
	Aparser__var_name(__this);
	while ((Aparser__match_op(__this, (var)(__string_Aparser311+ 2)))!=0) {
		Aclass__valid_var(_this->_class);
		Aparser__eat(__this);
		Aparser__var_name(__this);
	}
	Aclass__valid_var(_this->_class);
	if ((Aparser__match_op(__this, (var)(__string_Aparser312+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser313+ 2));
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	recursive--;
	return __return__;
}
var Aparser__statements(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.statements\"\n");std__panic();
	}
	if (_this->status==0) {
		Aparser__push(__this, Aparser__Cstatement);
		recursive--;
	return __return__;
	}
	if (_this->status>0) {
		_this->status=0;
	}
	Aparser__pop(__this);
	recursive--;
	return __return__;
}
var Aparser__statement(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var r;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.statement\"\n");std__panic();
	}
	Aparser__pop(__this);
	r=0;
	if ((Aparser__match_id(__this, (var)(__string_Aparser314+ 2)))!=0) {
		r=1;
		Aclass__begin_stm(_this->_class,Aclass__Cbreak,_this->lookahead);
		Aparser__eat(__this);
		if ((Aparser__match_op(__this, (var)(__string_Aparser315+ 2)))==0) {
			Aparser__error(__this, (var)(__string_Aparser316+ 2));
			recursive--;
	return __return__;
		}
		Aclass__finish_stm(_this->_class);
		Aparser__eat(__this);
		recursive--;
	return __return__;
	}
	if (r==0) {
		r=Aparser__if_statem(__this, Aclass__Cif);
	}
	if (r==0) {
		r=Aparser__while_statem(__this);
	}
	if (r==0) {
		r=Aparser__return_statem(__this);
	}
	if (r==0) {
		r=Aparser__dolet_statem(__this);
	}
	if (r==0) {
		_this->status=1;
	}
	recursive--;
	return __return__;
}
var Aparser__if_statem(var __this, var type_)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.if_statem\"\n");std__panic();
	}
	if ((Aparser__match_id(__this, (var)(__string_Aparser317+ 2)))==0) {
		__return__ = 0;
	recursive--;
	return __return__;
	}
	if (type_==(Aclass__Cif)) {
		Aclass__begin_stm(_this->_class,Aclass__Cifblock,_this->lookahead);
	}
	Aclass__begin_stm(_this->_class,type_,_this->lookahead);
	Aparser__eat(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser318+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser319+ 2));
		__return__ = 1;
	recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	Aparser__push(__this, Aparser__Cif_statem1);
	Aparser__push(__this, Aparser__Cexpression);
	Aclass__begin_expr(_this->_class,_this->lookahead);
	__return__ = 1;
	recursive--;
	return __return__;
}
var Aparser__if_statem1(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.if_statem1\"\n");std__panic();
	}
	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser320+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser321+ 2));
		recursive--;
	return __return__;
	}
	Aclass__finish_expr(_this->_class);
	Aparser__eat(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser322+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser323+ 2));
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	Aparser__push(__this, Aparser__Celse_statem);
	Aparser__push(__this, Aparser__Cstatements);
	recursive--;
	return __return__;
}
var Aparser__else_statem(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.else_statem\"\n");std__panic();
	}
	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser324+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser325+ 2));
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	if ((Aparser__match_id(__this, (var)(__string_Aparser326+ 2)))==0) {
		Aclass__finish_stm(_this->_class);
		Aclass__finish_stm(_this->_class);
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	if ((Aparser__match_id(__this, (var)(__string_Aparser327+ 2)))!=0) {
		Aclass__finish_stm(_this->_class);
		Aparser__if_statem(__this, Aclass__Celseif);
		recursive--;
	return __return__;
	}
	Aclass__begin_else(_this->_class,Aclass__Celse);
	if ((Aparser__match_op(__this, (var)(__string_Aparser328+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser329+ 2));
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	Aparser__push(__this, Aparser__Celse_statem1);
	Aparser__push(__this, Aparser__Cstatements);
	recursive--;
	return __return__;
}
var Aparser__else_statem1(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.else_statem1\"\n");std__panic();
	}
	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser330+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser331+ 2));
		recursive--;
	return __return__;
	}
	Aclass__finish_stm(_this->_class);
	Aclass__finish_stm(_this->_class);
	Aparser__eat(__this);
	recursive--;
	return __return__;
}
var Aparser__while_statem(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.while_statem\"\n");std__panic();
	}
	if ((Aparser__match_id(__this, (var)(__string_Aparser332+ 2)))==0) {
		__return__ = 0;
	recursive--;
	return __return__;
	}
	Aclass__begin_stm(_this->_class,Aclass__Cwhile,_this->lookahead);
	Aparser__eat(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser333+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser334+ 2));
		__return__ = 1;
	recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	Aclass__begin_expr(_this->_class,_this->lookahead);
	Aparser__push(__this, Aparser__Cwhile_statem1);
	Aparser__push(__this, Aparser__Cexpression);
	__return__ = 1;
	recursive--;
	return __return__;
}
var Aparser__while_statem1(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.while_statem1\"\n");std__panic();
	}
	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser335+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser336+ 2));
		recursive--;
	return __return__;
	}
	Aclass__finish_expr(_this->_class);
	Aparser__eat(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser337+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser338+ 2));
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	Aparser__push(__this, Aparser__Cwhile_statem2);
	Aparser__push(__this, Aparser__Cstatements);
	recursive--;
	return __return__;
}
var Aparser__while_statem2(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.while_statem2\"\n");std__panic();
	}
	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser339+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser340+ 2));
		recursive--;
	return __return__;
	}
	Aclass__finish_stm(_this->_class);
	Aparser__eat(__this);
	recursive--;
	return __return__;
}
var Aparser__return_statem(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.return_statem\"\n");std__panic();
	}
	if ((Aparser__match_id(__this, (var)(__string_Aparser341+ 2)))==0) {
		__return__ = 0;
	recursive--;
	return __return__;
	}
	Aclass__begin_stm(_this->_class,Aclass__Creturn,_this->lookahead);
	Aparser__eat(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser342+ 2)))!=0) {
		Aclass__finish_stm(_this->_class);
		Aparser__eat(__this);
	} else {
		Aclass__begin_expr(_this->_class,_this->lookahead);
		Aparser__push(__this, Aparser__Creturn_statem1);
		Aparser__push(__this, Aparser__Cexpression);
	}
	__return__ = 1;
	recursive--;
	return __return__;
}
var Aparser__return_statem1(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.return_statem1\"\n");std__panic();
	}
	if ((Aparser__match_op(__this, (var)(__string_Aparser343+ 2)))!=0) {
		Aclass__finish_expr(_this->_class);
		Aclass__finish_stm(_this->_class);
		Aparser__eat(__this);
		Aparser__pop(__this);
		recursive--;
	return __return__;
	}
	Aparser__error(__this, (var)(__string_Aparser344+ 2));
	recursive--;
	return __return__;
}
var Aparser__dolet_statem(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var id;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.dolet_statem\"\n");std__panic();
	}
	if ((Aparser__match_id(__this, 0))==0) {
		__return__ = 0;
	recursive--;
	return __return__;
	}
	id=_this->lookahead;
	Aparser__eat(__this);
	if ((((Aparser__match_op(__this, (var)(__string_Aparser345+ 2)))!=0))||(((Aparser__match_op(__this, (var)(__string_Aparser346+ 2)))!=0))) {
		Aclass__begin_stm(_this->_class,Aclass__Clet,_this->lookahead);
		__return__ = Aparser__let_statem(__this, id);
	recursive--;
	return __return__;
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser347+ 2)))==0) {
		Aclass__begin_stm(_this->_class,Aclass__Cdo,_this->lookahead);
		__return__ = Aparser__do_statem(__this, id);
	recursive--;
	return __return__;
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var Aparser__let_statem(var __this, var id)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.let_statem\"\n");std__panic();
	}
	if ((Aparser__match_op(__this, (var)(__string_Aparser348+ 2)))!=0) {
		Aclass__expr_var(_this->_class,Atoken__get_data(id),_this->lookahead);
		Aclass__expr_op(_this->_class,Aclass__Cassign,_this->lookahead);
		Aparser__eat(__this);
		Aparser__push(__this, Aparser__Clet_statem1);
		Aparser__push(__this, Aparser__Cexpression);
		__return__ = 1;
	recursive--;
	return __return__;
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser349+ 2)))!=0) {
		Aclass__expr_open_index(_this->_class,Atoken__get_data(id),_this->lookahead);
		Aparser__eat(__this);
		Aparser__push(__this, Aparser__Clet_statem2);
		Aparser__push(__this, Aparser__Cexpression);
		__return__ = 1;
	recursive--;
	return __return__;
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var Aparser__let_statem1(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.let_statem1\"\n");std__panic();
	}
	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser350+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser351+ 2));
		recursive--;
	return __return__;
	}
	Aclass__finish_expr(_this->_class);
	Aclass__finish_stm(_this->_class);
	Aparser__eat(__this);
	recursive--;
	return __return__;
}
var Aparser__let_statem2(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.let_statem2\"\n");std__panic();
	}
	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser352+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser353+ 2));
		recursive--;
	return __return__;
	}
	Aclass__expr_close_index(_this->_class);
	Aparser__eat(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser354+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Cassign,_this->lookahead);
		Aparser__eat(__this);
		Aparser__push(__this, Aparser__Clet_statem1);
		Aparser__push(__this, Aparser__Cexpression);
		recursive--;
	return __return__;
	}
	Aparser__error(__this, (var)(__string_Aparser355+ 2));
	recursive--;
	return __return__;
}
var Aparser__do_statem(var __this, var id)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.do_statem\"\n");std__panic();
	}
	Aparser__push(__this, Aparser__Cdo_statem1);
	__return__ = Aparser__subrout_call(__this, id);
	recursive--;
	return __return__;
}
var Aparser__do_statem1(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.do_statem1\"\n");std__panic();
	}
	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser356+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser357+ 2));
		recursive--;
	return __return__;
	}
	Aclass__finish_expr(_this->_class);
	Aclass__finish_stm(_this->_class);
	Aparser__eat(__this);
	recursive--;
	return __return__;
}
var Aparser__expression(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.expression\"\n");std__panic();
	}
	Aparser__pop(__this);
	Aparser__push(__this, Aparser__Cexpression1);
	Aparser__push(__this, Aparser__Cterm);
	recursive--;
	return __return__;
}
var Aparser__expression1(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.expression1\"\n");std__panic();
	}
	if ((Aparser__op(__this))!=0) {
		Aparser__push(__this, Aparser__Cterm);
		recursive--;
	return __return__;
	} else {
		Aparser__pop(__this);
	}
	recursive--;
	return __return__;
}
var Aparser__op(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.op\"\n");std__panic();
	}
	if ((Aparser__match_op(__this, (var)(__string_Aparser358+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Cadd,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser359+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Csub,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser360+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Cmult,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser361+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Cdiv,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser362+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Cmodulo,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser363+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Clogicaland,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser364+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Clogicalor,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser365+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Cequal,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser366+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Cnotequal,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser367+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Clargerequal,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser368+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Clesserequal,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser369+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Clarger,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser370+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Clesser,_this->lookahead);
	} else {
		__return__ = 0;
	recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	__return__ = 1;
	recursive--;
	return __return__;
}
var Aparser__term(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var id;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.term\"\n");std__panic();
	}
	Aparser__pop(__this);
	if ((Aparser__match_id(__this, (var)(__string_Aparser371+ 2)))!=0) {
		Aclass__expr_term(_this->_class,Aclass__Cthis,_this->lookahead);
		Aparser__eat(__this);
	} else if ((Aparser__match_id(__this, (var)(__string_Aparser372+ 2)))!=0) {
		Aclass__expr_term(_this->_class,Aclass__Cnull,_this->lookahead);
		Aparser__eat(__this);
	} else if ((Atoken__get_type(_this->lookahead))==(Alexer__Cidentifier)) {
		id=_this->lookahead;
		Aparser__eat(__this);
		if ((Aparser__match_op(__this, (var)(__string_Aparser373+ 2)))!=0) {
			Aclass__expr_open_index(_this->_class,Atoken__get_data(id),_this->lookahead);
			Aparser__eat(__this);
			Aparser__push(__this, Aparser__Cterm2);
			Aparser__push(__this, Aparser__Cexpression);
		} else if ((Aparser__subrout_call(__this, id))!=0) {
		} else if ((Aparser__match_op(__this, (var)(__string_Aparser374+ 2)))!=0) {
			Aparser__eat(__this);
			if ((Atoken__get_type(_this->lookahead))!=(Alexer__Cidentifier)) {
				Aparser__error(__this, (var)(__string_Aparser375+ 2));
				recursive--;
	return __return__;
			}
			Aclass__expr_constant(_this->_class,Atoken__get_data(id),Atoken__get_data(_this->lookahead),_this->lookahead);
			Aparser__eat(__this);
		} else {
			Aclass__expr_var(_this->_class,Atoken__get_data(id),_this->lookahead);
		}
	} else if ((Atoken__get_type(_this->lookahead))==(Alexer__Cquote)) {
		Aclass__expr_char_const(_this->_class,Atoken__get_data(_this->lookahead),_this->lookahead);
		Aparser__eat(__this);
	} else if ((Atoken__get_type(_this->lookahead))==(Alexer__Cstring)) {
		Aclass__expr_str_const(_this->_class,Atoken__get_data(_this->lookahead),_this->lookahead);
		Aparser__eat(__this);
	} else if ((Atoken__get_type(_this->lookahead))==(Alexer__Cnumber)) {
		Aclass__expr_int_const(_this->_class,Atoken__get_data(_this->lookahead),_this->lookahead);
		Aparser__eat(__this);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser376+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Cunaryminus,_this->lookahead);
		Aparser__eat(__this);
		Aparser__push(__this, Aparser__Cterm);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser377+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Cunaryplus,_this->lookahead);
		Aparser__eat(__this);
		Aparser__push(__this, Aparser__Cterm);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser378+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Clogicalnot,_this->lookahead);
		Aparser__eat(__this);
		Aparser__push(__this, Aparser__Cterm);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser379+ 2)))!=0) {
		Aclass__expr_open_par(_this->_class);
		Aparser__eat(__this);
		Aparser__push(__this, Aparser__Cterm1);
		Aparser__push(__this, Aparser__Cexpression);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser380+ 2)))!=0) {
		Aparser__lambda_body(__this);
	} else {
		Aparser__error(__this, (var)(__string_Aparser381+ 2));
		recursive--;
	return __return__;
	}
	recursive--;
	return __return__;
}
var Aparser__subrout_call(var __this, var id)
{
	static var recursive = 0;
	var __return__ = 0;
	var id2;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.subrout_call\"\n");std__panic();
	}
	if ((Aparser__match_op(__this, (var)(__string_Aparser382+ 2)))!=0) {
		Aparser__sub_call(__this, 0,id);
		__return__ = 1;
	recursive--;
	return __return__;
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser383+ 2)))!=0) {
		id2=id;
		Aparser__eat(__this);
		id=_this->lookahead;
		Aparser__eat(__this);
		Aparser__sub_call(__this, id2,id);
		__return__ = 1;
	recursive--;
	return __return__;
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var Aparser__term1(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.term1\"\n");std__panic();
	}
	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser384+ 2)))!=0) {
		Aclass__expr_close_par(_this->_class);
		Aparser__eat(__this);
		recursive--;
	return __return__;
	}
	Aparser__error(__this, (var)(__string_Aparser385+ 2));
	recursive--;
	return __return__;
}
var Aparser__term2(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.term2\"\n");std__panic();
	}
	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser386+ 2)))!=0) {
		Aclass__expr_close_index(_this->_class);
		Aparser__eat(__this);
		recursive--;
	return __return__;
	}
	Aparser__error(__this, (var)(__string_Aparser387+ 2));
	recursive--;
	return __return__;
}
var Aparser__sub_call(var __this, var class_, var id)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.sub_call\"\n");std__panic();
	}
	if ((Aparser__match_op(__this, (var)(__string_Aparser388+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser389+ 2));
		recursive--;
	return __return__;
	}
	Aparser__eat(__this);
	if (class_!=0) {
		Aclass__expr_begin_sub_call(_this->_class,Atoken__get_data(class_),Atoken__get_data(id),_this->lookahead);
	} else {
		Aclass__expr_begin_sub_call(_this->_class,0,Atoken__get_data(id),_this->lookahead);
	}
	Aparser__push(__this, Aparser__Csub_call1);
	if ((Aparser__match_op(__this, (var)(__string_Aparser390+ 2)))==0) {
		Aparser__push(__this, Aparser__Cexpr_list);
		Aparser__push(__this, Aparser__Cexpression);
		recursive--;
	return __return__;
	}
	Aclass__expr_finish_sub_call(_this->_class);
	recursive--;
	return __return__;
}
var Aparser__sub_call1(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.sub_call1\"\n");std__panic();
	}
	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser391+ 2)))!=0) {
		Aclass__expr_finish_sub_call(_this->_class);
		Aparser__eat(__this);
		recursive--;
	return __return__;
	}
	Aparser__error(__this, (var)(__string_Aparser392+ 2));
	recursive--;
	return __return__;
}
var Aparser__expr_list(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.expr_list\"\n");std__panic();
	}
	Aparser__pop(__this);
	if (_this->status!=0) {
		_this->status=0;
		recursive--;
	return __return__;
	}
	if ((Aparser__match_op(__this, (var)(__string_Aparser393+ 2)))!=0) {
		Aparser__eat(__this);
		Aclass__expr_next_expr(_this->_class,_this->lookahead);
		Aparser__push(__this, Aparser__Cexpr_list1);
		Aparser__push(__this, Aparser__Cexpression);
	}
	recursive--;
	return __return__;
}
var Aparser__expr_list1(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.expr_list1\"\n");std__panic();
	}
	Aparser__pop(__this);
	if (_this->status!=0) {
		recursive--;
	return __return__;
	}
	if ((Aparser__match_op(__this, (var)(__string_Aparser394+ 2)))!=0) {
		Aclass__expr_next_expr(_this->_class,_this->lookahead);
		Aparser__eat(__this);
		Aparser__push(__this, Aparser__Cexpr_list1);
		Aparser__push(__this, Aparser__Cexpression);
	}
	recursive--;
	return __return__;
}
var Aparser__eat(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.eat\"\n");std__panic();
	}
	Alexer__shift(_this->lex);
	if ((Alexer__empty(_this->lex))!=0) {
		_this->lookstring=0;
		_this->lookahead=0;
		recursive--;
	return __return__;
	}
	_this->lookahead=Alexer__get_at(_this->lex,0);
	if (_this->lookahead==0) {
		_this->lookstring=0;
		recursive--;
	return __return__;
	}
	while ((((Atoken__get_type(_this->lookahead))==(Alexer__Cnewline)))||(((Atoken__get_type(_this->lookahead))==(Alexer__Ccomment)))) {
		Alexer__shift(_this->lex);
		if ((Alexer__empty(_this->lex))!=0) {
			_this->lookstring=0;
			_this->lookahead=0;
			recursive--;
	return __return__;
		}
		_this->lookahead=Alexer__get_at(_this->lex,0);
	}
	_this->lookstring=Atoken__get_data(_this->lookahead);
	recursive--;
	return __return__;
}
var Aparser__match_id(var __this, var id)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.match_id\"\n");std__panic();
	}
	if ((Atoken__get_type(_this->lookahead))!=(Alexer__Cidentifier)) {
		__return__ = 0;
	recursive--;
	return __return__;
	}
	if (id==0) {
		__return__ = 1;
	recursive--;
	return __return__;
	}
	if ((string__compare(_this->lookstring,id))==0) {
		__return__ = 1;
	recursive--;
	return __return__;
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var Aparser__match_op(var __this, var id)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.match_op\"\n");std__panic();
	}
	if ((Atoken__get_type(_this->lookahead))!=(Alexer__Coperator)) {
		__return__ = 0;
	recursive--;
	return __return__;
	}
	if ((string__compare(_this->lookstring,id))==0) {
		__return__ = 1;
	recursive--;
	return __return__;
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var Aparser__match_newline(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.match_newline\"\n");std__panic();
	}
	if ((Atoken__get_type(_this->lookahead))==(Alexer__Cnewline)) {
		__return__ = 1;
	recursive--;
	return __return__;
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var Aparser__match_str(var __this, var id)
{
	static var recursive = 0;
	var __return__ = 0;
	var t;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.match_str\"\n");std__panic();
	}
	t=Atoken__get_type(_this->lookahead);
	if (((t!=(Alexer__Cstring)))&&((t!=(Alexer__Cquote)))) {
		__return__ = 0;
	recursive--;
	return __return__;
	}
	if (((id==0))||(((string__compare(_this->lookstring,id))==0))) {
		__return__ = 1;
	recursive--;
	return __return__;
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var Aparser__state_machine(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var state;
	MAKETHIS(Aparser);
	if (((var*)__this)[-1]!=Aparser___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Aparser.state_machine\"\n");std__panic();
	}
	state=buffer__get_last(_this->_states);
	if (_this->debug>0) {
		console__log(_this->lookstring);
		console__log_int(state);
	}
	
	switch (state) {
	case Aparser__Croot: 
		Aparser__root(__this);
		break;
	case Aparser__Cclass_dec: 
		Aparser__class_dec(__this);
		break;
	case Aparser__Cstatement: 
		Aparser__statement(__this);
		break;
	case Aparser__Cstatements: 
		Aparser__statements(__this);
		break;
	case Aparser__Cexpression: 
		Aparser__expression(__this);
		break;
	case Aparser__Cexpression1: 
		Aparser__expression1(__this);
		break;
	case Aparser__Cterm: 
		Aparser__term(__this);
		break;
	case Aparser__Cterm1: 
		Aparser__term1(__this);
		break;
	case Aparser__Cterm2: 
		Aparser__term2(__this);
		break;
	case Aparser__Creturn_statem1: 
		Aparser__return_statem1(__this);
		break;
	case Aparser__Cexpr_list: 
		Aparser__expr_list(__this);
		break;
	case Aparser__Cexpr_list1: 
		Aparser__expr_list1(__this);
		break;
	case Aparser__Csub_call1: 
		Aparser__sub_call1(__this);
		break;
	case Aparser__Clet_statem1: 
		Aparser__let_statem1(__this);
		break;
	case Aparser__Clet_statem2: 
		Aparser__let_statem2(__this);
		break;
	case Aparser__Cdo_statem1: 
		Aparser__do_statem1(__this);
		break;
	case Aparser__Cwhile_statem1: 
		Aparser__while_statem1(__this);
		break;
	case Aparser__Cwhile_statem2: 
		Aparser__while_statem2(__this);
		break;
	case Aparser__Clambda_body1: 
		Aparser__lambda_body1(__this);
		break;
	case Aparser__Csubrout_body1: 
		Aparser__subrout_body1(__this);
		break;
	case Aparser__Csubroutine_dec: 
		Aparser__subroutine_dec(__this);
		break;
	case Aparser__Cclass_dec1: 
		Aparser__class_dec1(__this);
		break;
	case Aparser__Cif_statem1: 
		Aparser__if_statem1(__this);
		break;
	case Aparser__Celse_statem: 
		Aparser__else_statem(__this);
		break;
	case Aparser__Celse_statem1: 
		Aparser__else_statem1(__this);
		break;
	default:
		Aparser__error(__this, (var)(__string_Aparser395+ 2));
		Alexer__shift(_this->lex);
		_this->status=-(1);
		break;
	} 
	__return__ = 1;
	recursive--;
	return __return__;
}
/* class Astatement */
struct Astatement {
	var type;
	var expr;
	var statements;
	var else_stms;
	var parent;
	var depth;
};
var Astatement___new(var __this, var type1, var parent1, var depth1, var __parent)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Astatement);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Astatement.new\"\n");std__panic();
	}
	_this->type=type1;
	_this->parent=parent1;
	_this->depth=depth1;
	_this->expr=0;
	_this->statements=0;
	_this->else_stms=0;
	__return__ = __this;
	recursive--;
	return __return__;
}
var Astatement__new(var type1, var parent1, var depth1, var __parent)
{
	NEW(Astatement);
	return Astatement___new(__this, type1, parent1, depth1, __parent);
}
var Astatement___V_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Astatement);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Astatement.dispose\"\n");std__panic();
	}
	std__delete(_this->expr);
	std__delete(_this->statements);
	std__delete(_this->else_stms);
	std__free(__this);
	recursive--;
	return __return__;
}
var Astatement__get_type(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Astatement);
	if (((var*)__this)[-1]!=Astatement___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Astatement.get_type\"\n");std__panic();
	}
	__return__ = _this->type;
	recursive--;
	return __return__;
}
var Astatement__set_type(var __this, var type1)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Astatement);
	if (((var*)__this)[-1]!=Astatement___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Astatement.set_type\"\n");std__panic();
	}
	_this->type=type1;
	recursive--;
	return __return__;
}
var Astatement__get_depth(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Astatement);
	if (((var*)__this)[-1]!=Astatement___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Astatement.get_depth\"\n");std__panic();
	}
	__return__ = _this->depth;
	recursive--;
	return __return__;
}
var Astatement__get_parent(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Astatement);
	if (((var*)__this)[-1]!=Astatement___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Astatement.get_parent\"\n");std__panic();
	}
	__return__ = _this->parent;
	recursive--;
	return __return__;
}
var Astatement__get_statements(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Astatement);
	if (((var*)__this)[-1]!=Astatement___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Astatement.get_statements\"\n");std__panic();
	}
	__return__ = _this->statements;
	recursive--;
	return __return__;
}
var Astatement__get_else(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Astatement);
	if (((var*)__this)[-1]!=Astatement___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Astatement.get_else\"\n");std__panic();
	}
	__return__ = _this->else_stms;
	recursive--;
	return __return__;
}
var Astatement__get_expression(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Astatement);
	if (((var*)__this)[-1]!=Astatement___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Astatement.get_expression\"\n");std__panic();
	}
	__return__ = _this->expr;
	recursive--;
	return __return__;
}
var Astatement__add_else(var __this, var type1)
{
	static var recursive = 0;
	var __return__ = 0;
	var st;
	MAKETHIS(Astatement);
	if (((var*)__this)[-1]!=Astatement___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Astatement.add_else\"\n");std__panic();
	}
	if (_this->else_stms!=0) {
		console__log((var)(__string_Astatement396+ 2));
		std__exit(-(1));
	}
	_this->else_stms=buffer__new(2,1,__this);
	st=Astatement__new(type1,_this->parent,_this->depth,__this);
	Astatement__add_statement(__this, st);
	recursive--;
	return __return__;
}
var Astatement__add_statement(var __this, var statement1)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Astatement);
	if (((var*)__this)[-1]!=Astatement___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Astatement.add_statement\"\n");std__panic();
	}
	if (_this->statements==0) {
		_this->statements=buffer__new(2,1,__this);
	}
	if (_this->else_stms!=0) {
		buffer__push(_this->else_stms,statement1);
	} else {
		buffer__push(_this->statements,statement1);
	}
	recursive--;
	return __return__;
}
var Astatement__set_expression(var __this, var expr1)
{
	static var recursive = 0;
	var __return__ = 0;
	var ex1;
	MAKETHIS(Astatement);
	if (((var*)__this)[-1]!=Astatement___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Astatement.set_expression\"\n");std__panic();
	}
	std__delete(_this->expr);
	_this->expr=0;
	ex1=std__move(expr1);
	
	switch (_this->type) {
	case Aclass__Cif: 
		_this->expr=ex1;
		break;
	case Aclass__Celseif: 
		_this->expr=ex1;
		break;
	case Aclass__Clet: 
		_this->expr=ex1;
		break;
	case Aclass__Cdo: 
		_this->expr=ex1;
		break;
	case Aclass__Cwhile: 
		_this->expr=ex1;
		break;
	case Aclass__Creturn: 
		_this->expr=ex1;
		break;
	default:
		console__log((var)(__string_Astatement397+ 2));
		std__exit(-(1));
		break;
	} 
	recursive--;
	return __return__;
}
/* class Atoken */
struct Atoken {
	var type;
	var data;
	var line;
	var file_;
};
var Atoken___new(var __this, var type1, var data1, var line1, var file1, var __parent)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Atoken);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Atoken.new\"\n");std__panic();
	}
	_this->type=type1;
	_this->data=data1;
	_this->line=line1;
	_this->file_=file1;
	__return__ = __this;
	recursive--;
	return __return__;
}
var Atoken__new(var type1, var data1, var line1, var file1, var __parent)
{
	NEW(Atoken);
	return Atoken___new(__this, type1, data1, line1, file1, __parent);
}
var Atoken___V_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Atoken);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Atoken.dispose\"\n");std__panic();
	}
	std__delete(_this->data);
	_this->data=0;
	std__free(__this);
	recursive--;
	return __return__;
}
var Atoken__copy(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	var t;
	var d;
	MAKETHIS(Atoken);
	if (((var*)__this)[-1]!=Atoken___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Atoken.copy\"\n");std__panic();
	}
	if (_this->data!=0) {
		d=string__to_string(_this->data);
	} else {
		d=0;
	}
	t=Atoken__new(_this->type,d,_this->line,_this->file_,__this);
	Atoken__take(t);
	__return__ = t;
	recursive--;
	return __return__;
}
var Atoken__take(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Atoken);
	if (((var*)__this)[-1]!=Atoken___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Atoken.take\"\n");std__panic();
	}
	std__move(_this->data);
	recursive--;
	return __return__;
}
var Atoken__get(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Atoken);
	if (((var*)__this)[-1]!=Atoken___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Atoken.get\"\n");std__panic();
	}
	__return__ = __this;
	recursive--;
	return __return__;
}
var Atoken__get_data(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Atoken);
	if (((var*)__this)[-1]!=Atoken___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Atoken.get_data\"\n");std__panic();
	}
	__return__ = _this->data;
	recursive--;
	return __return__;
}
var Atoken__get_type(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Atoken);
	if (((var*)__this)[-1]!=Atoken___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Atoken.get_type\"\n");std__panic();
	}
	__return__ = _this->type;
	recursive--;
	return __return__;
}
var Atoken__get_line(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Atoken);
	if (((var*)__this)[-1]!=Atoken___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Atoken.get_line\"\n");std__panic();
	}
	__return__ = _this->line;
	recursive--;
	return __return__;
}
var Atoken__get_file(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Atoken);
	if (((var*)__this)[-1]!=Atoken___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Atoken.get_file\"\n");std__panic();
	}
	__return__ = _this->file_;
	recursive--;
	return __return__;
}
/* class Avirtual */
struct Avirtual {
	var _class;
	var _memb;
	var next;
};
var Avirtual___new(var __this, var memb1, var class1, var __parent)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Avirtual);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Avirtual.new\"\n");std__panic();
	}
	_this->_class=std__move(string__to_string(class1));
	_this->_memb=std__move(Amember__copy(memb1));
	_this->next=0;
	__return__ = __this;
	recursive--;
	return __return__;
}
var Avirtual__new(var memb1, var class1, var __parent)
{
	NEW(Avirtual);
	return Avirtual___new(__this, memb1, class1, __parent);
}
var Avirtual___V_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Avirtual);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Avirtual.dispose\"\n");std__panic();
	}
	std__delayed_delete(__this);
	recursive--;
	return __return__;
}
var Avirtual___V_delayed_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Avirtual);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Avirtual.delayed_dispose\"\n");std__panic();
	}
	std__delete(_this->_class);
	std__delete(_this->_memb);
	std__delete(_this->next);
	std__free(__this);
	recursive--;
	return __return__;
}
var Avirtual__set_next(var __this, var n)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Avirtual);
	if (((var*)__this)[-1]!=Avirtual___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Avirtual.set_next\"\n");std__panic();
	}
	_this->next=std__move(n);
	recursive--;
	return __return__;
}
var Avirtual__get_next(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Avirtual);
	if (((var*)__this)[-1]!=Avirtual___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Avirtual.get_next\"\n");std__panic();
	}
	__return__ = _this->next;
	recursive--;
	return __return__;
}
var Avirtual__get_class_name(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Avirtual);
	if (((var*)__this)[-1]!=Avirtual___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Avirtual.get_class_name\"\n");std__panic();
	}
	__return__ = _this->_class;
	recursive--;
	return __return__;
}
var Avirtual__get_member(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Avirtual);
	if (((var*)__this)[-1]!=Avirtual___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Avirtual.get_member\"\n");std__panic();
	}
	__return__ = _this->_memb;
	recursive--;
	return __return__;
}
var Avirtual__get_member_name(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(Avirtual);
	if (((var*)__this)[-1]!=Avirtual___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"Avirtual.get_member_name\"\n");std__panic();
	}
	__return__ = Amember__get_name_string(_this->_memb);
	recursive--;
	return __return__;
}
/* class main */
struct main {
	var str;
	var tmp;
	var args;
	var fd;
	var n;
	var i;
	var end;
	var lex;
	var par;
	var emi;
	var head;
	var body;
	var to;
	var l;
	var pf_tmp;
	var pf_out;
	var pf_fd;
	var pf_off;
	var pf_f;
	var pf_cb;
	var pf_cb_this;
};
var main__copy_block(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(main);
	if (((var*)__this)[-1]!=main___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"main.copy_block\"\n");std__panic();
	}
	file__read(_this->pf_fd,_this->pf_f,_this->pf_off,main__Cblock,0,__this);
	recursive--;
	return __return__;
}
var main__0(var __this, var status, var data, var type)
{
	static var recursive = 0;
	var __return__ = 0;
	var d;
	var n;
	var i;
	var l;
	MAKETHIS(main);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"main.0\"\n");std__panic();
	}
	if ((status==200)&&(type==1)) {
		d=data;
		n=bytes__get_size(d);
		i=0;
		l=string__length(_this->pf_out);
		string__set_size(_this->pf_out,(l+n)+1);
		while (i<n) {
			string__set_at(_this->pf_out,i+l,bytes__get_at(d,i));
			i=i+1;
		}
		string__set_at(_this->pf_out,i+l,0);
		_this->pf_off=_this->pf_off+(main__Cblock);
		main__copy_block(__this);
	} else {
		std__delete(_this->pf_fd);
		worker__new(_this->pf_cb_this,_this->pf_cb,200,0,0,__this);
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var main__copyto(var __this, var f, var output, var cb, var this_cb)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(main);
	if (((var*)__this)[-1]!=main___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"main.copyto\"\n");std__panic();
	}
	console__log_str((var)(__string_main398+ 2));
	console__log(f);
	_this->pf_out=output;
	_this->pf_f=f;
	_this->pf_off=0;
	_this->pf_fd=file__new((var)(__string_main399+ 2),__this);
	_this->pf_cb=cb;
	_this->pf_cb_this=std__this(cb);
	main__copy_block(__this);
	recursive--;
	return __return__;
}
var main__process_file_end(var __this, var stat)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(main);
	if (((var*)__this)[-1]!=main___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"main.process_file_end\"\n");std__panic();
	}
	std__delete(_this->pf_fd);
	Alexer__finish(_this->lex);
	std__delete(_this->pf_tmp);
	worker__new(_this->pf_cb_this,_this->pf_cb,stat,0,0,__this);
	recursive--;
	return __return__;
}
var main__process_file_block(var __this, var n, var d)
{
	static var recursive = 0;
	var __return__ = 0;
	var i;
	MAKETHIS(main);
	if (((var*)__this)[-1]!=main___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"main.process_file_block\"\n");std__panic();
	}
	i=0;
	while (i<n) {
		string__add_char(_this->pf_tmp,bytes__get_at(d,i));
		i=i+1;
	}
	_this->pf_off=_this->pf_off+(main__Cblock);
	Alexer__add(_this->lex,_this->pf_tmp);
	string__set(_this->pf_tmp,(var)(__string_main400+ 2));
	file__read(_this->pf_fd,_this->pf_f,_this->pf_off,main__Cblock,1,__this);
	recursive--;
	return __return__;
}
var main__1(var __this, var status, var data, var type)
{
	static var recursive = 0;
	var __return__ = 0;
	var d;
	MAKETHIS(main);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"main.1\"\n");std__panic();
	}
	if ((status==200)&&(type==1)) {
		d=data;
		main__process_file_block(__this, bytes__get_size(d),d);
	} else {
		main__process_file_end(__this, 200);
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var main__process_file(var __this, var f, var cb, var this_cb)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(main);
	if (((var*)__this)[-1]!=main___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"main.process_file\"\n");std__panic();
	}
	_this->pf_f=f;
	_this->pf_off=0;
	_this->pf_tmp=string__new(10000,__this);
	_this->pf_fd=file__new((var)(__string_main401+ 2),__this);
	_this->pf_cb=cb;
	_this->pf_cb_this=std__this(cb);
	console__log_str((var)(__string_main402+ 2));
	console__log(_this->pf_f);
	Alexer__begin(_this->lex,_this->pf_f);
	file__read(_this->pf_fd,_this->pf_f,0,main__Cblock,2,__this);
	recursive--;
	return __return__;
}
var main__2(var __this, var status, var data, var type)
{
	static var recursive = 0;
	var __return__ = 0;
	var d;
	MAKETHIS(main);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"main.2\"\n");std__panic();
	}
	if ((status==200)&&(type==1)) {
		d=data;
		main__process_file_block(__this, bytes__get_size(d),d);
	} else {
		main__process_file_end(__this, 400);
	}
	__return__ = 0;
	recursive--;
	return __return__;
}
var main___new(var __this, var __parent)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(main);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"main.new\"\n");std__panic();
	}
	__return__ = __this;
	recursive--;
	return __return__;
}
var main__new(var __parent)
{
	NEW(main);
	return main___new(__this, __parent);
}
var main___V_dispose(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(main);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"main.dispose\"\n");std__panic();
	}
	std__delete(_this->tmp);
	std__free(__this);
	recursive--;
	return __return__;
}
var main__main()
{
	static var recursive = 0;
	var __return__ = 0;
	var m;
	FAKETHIS();
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"main.main\"\n");std__panic();
	}
	m=main__new(__this);
	main__run(m);
	std__loop();
	std__delete(m);
	recursive--;
	return __return__;
}
var main__run(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(main);
	if (((var*)__this)[-1]!=main___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"main.run\"\n");std__panic();
	}
	console__log(main__Chello);
	_this->args=std__get_args();
	_this->n=std__get_argc();
	if (_this->n<3) {
		console__log((var)(__string_main403+ 2));
		std__exit(-(1));
	}
	_this->head=string__new(2048,__this);
	_this->body=string__new(2048,__this);
	_this->str=((var*)_this->args)[1];
	_this->to=string__new(20,__this);
	string__add(_this->to,_this->str);
	string__add(_this->to,(var)(__string_main404+ 2));
	_this->fd=file__new((var)(__string_main405+ 2),__this);
	_this->tmp=string__new(100,__this);
	_this->lex=Alexer__new(__this);
	_this->par=Aparser__new(__this);
	_this->emi=Aemmitc__new(2,__this);
	_this->i=2;
	main__next_file(__this);
	recursive--;
	return __return__;
}
var main__next_file(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(main);
	if (((var*)__this)[-1]!=main___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"main.next_file\"\n");std__panic();
	}
	if (_this->i<_this->n) {
		string__set(_this->tmp,((var*)_this->args)[_this->i]);
		_this->i=_this->i+1;
		_this->end=string__length(_this->tmp);
		if ((string__indexof(_this->tmp,0,(var)(__string_main406+ 2)))==((_this->end-5))) {
			std__delete(_this->lex);
			_this->lex=Alexer__new(__this);
			main__process_file(__this, _this->tmp,3,__this);
		} else if ((string__indexof(_this->tmp,0,(var)(__string_main407+ 2)))==((_this->end-2))) {
			main__copyto(__this, _this->tmp,_this->head,4,__this);
		} else if ((string__indexof(_this->tmp,0,(var)(__string_main408+ 2)))==((_this->end-2))) {
			main__copyto(__this, _this->tmp,_this->body,5,__this);
		} else {
			main__finish(__this);
		}
	} else {
		main__finish(__this);
	}
	recursive--;
	return __return__;
}
var main__3(var __this, var status, var data, var type)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(main);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"main.3\"\n");std__panic();
	}
	Aparser__parse(_this->par,_this->lex);
	Aemmiter__emmit(_this->emi,_this->par);
	Aparser__release(_this->par);
	main__next_file(__this);
	__return__ = 0;
	recursive--;
	return __return__;
}
var main__4(var __this, var status, var data, var type)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(main);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"main.4\"\n");std__panic();
	}
	main__next_file(__this);
	__return__ = 0;
	recursive--;
	return __return__;
}
var main__5(var __this, var status, var data, var type)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(main);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"main.5\"\n");std__panic();
	}
	main__next_file(__this);
	__return__ = 0;
	recursive--;
	return __return__;
}
var main__finish(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(main);
	if (((var*)__this)[-1]!=main___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"main.finish\"\n");std__panic();
	}
	_this->i=0;
	_this->str=0;
	_this->l=0;
	Aemmiter__gen_virtuals(_this->emi);
	file__unlink(_this->fd,_this->to,6,__this);
	recursive--;
	return __return__;
}
var main__6(var __this, var status, var data, var type)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(main);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"main.6\"\n");std__panic();
	}
	main__finish1(__this);
	__return__ = 0;
	recursive--;
	return __return__;
}
var main__finish1(var __this)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(main);
	if (((var*)__this)[-1]!=main___DcidD){
		printf("CID: %ld ", ((var*)__this)[-1]);
		std__panic();
	}
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"main.finish1\"\n");std__panic();
	}
	_this->i=_this->i+_this->l;
	_this->l=0;
	while (_this->l<=0) {
		if (_this->str==0) {
			_this->str=_this->head;
		} else if (_this->str==_this->head) {
			_this->str=Aemmiter__get_head(_this->emi);
		} else if (_this->str==(Aemmiter__get_head(_this->emi))) {
			_this->str=Aemmiter__get_mid(_this->emi);
		} else if (_this->str==(Aemmiter__get_mid(_this->emi))) {
			_this->str=_this->body;
		} else if (_this->str==_this->body) {
			_this->str=Aemmiter__get_data(_this->emi);
		} else {
			console__log_str((var)(__string_main409+ 2));
			console__log(_this->to);
			std__delete(_this->to);
			std__delete(_this->fd);
			std__delete(_this->lex);
			std__delete(_this->par);
			std__delete(_this->emi);
			std__delete(_this->head);
			std__delete(_this->body);
			recursive--;
	return __return__;
		}
		_this->l=string__length(_this->str);
	}
	console__log_int(_this->l);
	console__log((var)(__string_main410+ 2));
	file__write(_this->fd,_this->to,_this->str,0,_this->i,_this->l,7,__this);
	recursive--;
	return __return__;
}
var main__7(var __this, var status, var data, var type)
{
	static var recursive = 0;
	var __return__ = 0;
	MAKETHIS(main);
	recursive++;
	if (recursive != 1) {
		fprintf(stderr, "recursive call in \"main.7\"\n");std__panic();
	}
	if (status!=200) {
		console__log((var)(__string_main411+ 2));
		std__exit(-(1));
	}
	main__finish1(__this);
	__return__ = 0;
	recursive--;
	return __return__;
}
var main___V_lambda(var __this, var fcn, var status, var data, var type)
{	switch(fcn) {
	case 0:
		return main__0(__this, status, data, type);
	case 1:
		return main__1(__this, status, data, type);
	case 2:
		return main__2(__this, status, data, type);
	case 3:
		return main__3(__this, status, data, type);
	case 4:
		return main__4(__this, status, data, type);
	case 5:
		return main__5(__this, status, data, type);
	case 6:
		return main__6(__this, status, data, type);
	case 7:
		return main__7(__this, status, data, type);
	}
	return 0;
}
var virtual__expr_process(var __this, var expr)
{
	var cid;
	cid = ((var*)__this)[-1];
	switch (cid) {
	case Aemmiter___DcidD:
		return Aemmiter___V_expr_process(__this, expr);
	case Aemmitc___DcidD:
		return Aemmitc___V_expr_process(__this, expr);
	default:
		break;
	}
	return 0;
}
var virtual__gen_virtuals(var __this)
{
	var cid;
	cid = ((var*)__this)[-1];
	switch (cid) {
	case Aemmiter___DcidD:
		return Aemmiter___V_gen_virtuals(__this);
	case Aemmitc___DcidD:
		return Aemmitc___V_gen_virtuals(__this);
	default:
		break;
	}
	return 0;
}
var virtual__get_mid(var __this)
{
	var cid;
	cid = ((var*)__this)[-1];
	switch (cid) {
	case Aemmiter___DcidD:
		return Aemmiter___V_get_mid(__this);
	case Aemmitc___DcidD:
		return Aemmitc___V_get_mid(__this);
	default:
		break;
	}
	return 0;
}
var virtual__get_data(var __this)
{
	var cid;
	cid = ((var*)__this)[-1];
	switch (cid) {
	case Aemmiter___DcidD:
		return Aemmiter___V_get_data(__this);
	case Aemmitc___DcidD:
		return Aemmitc___V_get_data(__this);
	default:
		break;
	}
	return 0;
}
var virtual__get_head(var __this)
{
	var cid;
	cid = ((var*)__this)[-1];
	switch (cid) {
	case Aemmiter___DcidD:
		return Aemmiter___V_get_head(__this);
	case Aemmitc___DcidD:
		return Aemmitc___V_get_head(__this);
	default:
		break;
	}
	return 0;
}
var virtual__emmit(var __this, var par)
{
	var cid;
	cid = ((var*)__this)[-1];
	switch (cid) {
	case Aemmiter___DcidD:
		return Aemmiter___V_emmit(__this, par);
	case Aemmitc___DcidD:
		return Aemmitc___V_emmit(__this, par);
	default:
		break;
	}
	return 0;
}
var virtual__delayed_dispose(var __this)
{
	var cid;
	cid = ((var*)__this)[-1];
	switch (cid) {
	case buffer___DcidD:
		return buffer___V_delayed_dispose(__this);
	case Avirtual___DcidD:
		return Avirtual___V_delayed_dispose(__this);
	case Aexpr___DcidD:
		return Aexpr___V_delayed_dispose(__this);
	case Aclass___DcidD:
		return Aclass___V_delayed_dispose(__this);
	default:
		break;
	}
	return 0;
}
var virtual__dispose(var __this)
{
	var cid;
	cid = ((var*)__this)[-1];
	switch (cid) {
	case array___DcidD:
		return array___V_dispose(__this);
	case main___DcidD:
		return main___V_dispose(__this);
	case Avirtual___DcidD:
		return Avirtual___V_dispose(__this);
	case Atoken___DcidD:
		return Atoken___V_dispose(__this);
	case Astatement___DcidD:
		return Astatement___V_dispose(__this);
	case Aparser___DcidD:
		return Aparser___V_dispose(__this);
	case Amember___DcidD:
		return Amember___V_dispose(__this);
	case Alexer___DcidD:
		return Alexer___V_dispose(__this);
	case Aexpr___DcidD:
		return Aexpr___V_dispose(__this);
	case Acbody___DcidD:
		return Acbody___V_dispose(__this);
	case Aemmitc___DcidD:
		return Aemmitc___V_dispose(__this);
	case Aemmiter___DcidD:
		return Aemmiter___V_dispose(__this);
	case Aclass___DcidD:
		return Aclass___V_dispose(__this);
	case string___DcidD:
		return string___V_dispose(__this);
	case worker___DcidD:
		return worker___V_dispose(__this);
	case object___DcidD:
		return object___V_dispose(__this);
	case hash___DcidD:
		return hash___V_dispose(__this);
	case file___DcidD:
		return file___V_dispose(__this);
	case bytes___DcidD:
		return bytes___V_dispose(__this);
	case buffer___DcidD:
		return buffer___V_dispose(__this);
	default:
		break;
	}
	return 0;
}
var std__lambda(var __this, var fcn, var status, var data, var type)
{
	var cid;
	cid = ((var*)__this)[-1];
	switch (cid) {
	case main___DcidD:
		return main___V_lambda(__this, fcn, status, data, type);
	}
	return 0;
}
