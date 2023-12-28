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

#ifdef __SUBC__
#define var int
#else
#define var long
#endif
#define STR(s) ((var)(s + 2))
#define NEW(c) var __this; \
	__this = std__alloc(c##___DsizeD); \
	((var*)__this)[-1] = c##___DcidD

var main__main(void);
var std__free(var mem);

#define std___DsizeD 0
#define std___DcidD 11
#define console___DsizeD 0
#define console___DcidD 12
var console__log(var str);
var console__log_str(var str);
var console__log_int(var n);
#define Amember___DsizeD 9
#define Amember___DcidD 13
var Amember__new(var kind_, var type_, var type_id_, var name_);
#define Amember__dispose(___this) virtual__dispose(___this)
var Amember___V_dispose(var __this);
var Amember__dispose_body(var __this);
var Amember__get_kind(var __this);
var Amember__get_type(var __this);
var Amember__get_type_id(var __this);
var Amember__get_name(var __this);
var Amember__get_name_string(var __this);
var Amember__get_initial_value(var __this);
var Amember__set_initial_value(var __this, var initial_value_);
var Amember__set_index(var __this, var index_);
var Amember__get_index(var __this);
var Amember__get_body(var __this);
var Amember__get_vars(var __this);
var Amember__get_params(var __this);
var Amember__add_param(var __this, var kind_, var type_, var type_id_, var name_);
var Amember__add_var(var __this, var kind_, var type_, var type_id_, var name_);
var Amember__add_statement(var __this, var statement_);
#define Astatement___DsizeD 6
#define Astatement___DcidD 14
var Astatement__new(var type_, var parent_, var depth_);
#define Astatement__dispose(___this) virtual__dispose(___this)
var Astatement___V_dispose(var __this);
var Astatement__get_type(var __this);
var Astatement__get_depth(var __this);
var Astatement__get_parent(var __this);
var Astatement__get_statements(var __this);
var Astatement__get_else(var __this);
var Astatement__get_expression(var __this);
var Astatement__add_else(var __this, var type_);
var Astatement__add_statement(var __this, var statement_);
var Astatement__set_expression(var __this, var expr_);
#define Avirtual___DsizeD 3
#define Avirtual___DcidD 15
var Avirtual__new(var memb_, var class_);
#define Avirtual__dispose(___this) virtual__dispose(___this)
var Avirtual___V_dispose(var __this);
var Avirtual__set_next(var __this, var n);
var Avirtual__get_next(var __this);
var Avirtual__get_class_name(var __this);
var Avirtual__get_member(var __this);
var Avirtual__get_member_name(var __this);
#define bytes___DsizeD 0
#define bytes___DcidD 16
#define file___DsizeD 2
#define file___DcidD 17
var file__new(var folder, var fscb);
#define file__dispose(___this) virtual__dispose(___this)
var file___V_dispose(var __this);
var file__mkfolder(var __this);
var file__mkdir(var __this, var name);
var file__read(var __this, var name, var seek, var size_);
var file__write(var __this, var name, var data, var seek, var size);
var file__filesize(var __this, var name);
var file__scandir(var __this, var name);
var file__rmdir(var __this, var name);
var file__unlink(var __this, var name);
#define response___DsizeD 3
#define response___DcidD 18
var response__new();
#define response__dispose(___this) virtual__dispose(___this)
var response___V_dispose(var __this);
var response__clear(var __this);
var response__set_string(var __this, var status_, var data_);
var response__set_bytes(var __this, var status_, var data_);
var response__get_status(var __this);
var response__get_string(var __this);
var response__get_bytes(var __this);
#define Aclass___DsizeD 15
#define Aclass___DcidD 19
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
var Aclass__new(var token);
#define Aclass__dispose(___this) virtual__dispose(___this)
var Aclass___V_dispose(var __this);
var Aclass__error(var __this, var err);
var Aclass__get_implement(var __this);
var Aclass__add_implement(var __this, var x);
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
var Aclass__finish_const(var __this, var initialiser_);
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
#define Aparser___DsizeD 7
#define Aparser___DcidD 20
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
#define Aparser__Celse_statem 29
#define Aparser__Celse_statem1 30
#define Aparser__Celse_statem2 31
var Aparser__new();
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
#define main___DsizeD 0
#define main___DcidD 21
#define main__Cblock 10
#define main__Chello (var)(__string_mainChello+2)
var main__copyto(var f, var output);
var main__process_file(var f, var lex);
var main__main();
#define Atoken___DsizeD 5
#define Atoken___DcidD 22
var Atoken__new(var type1, var _data1, var line1, var file1);
#define Atoken__dispose(___this) virtual__dispose(___this)
var Atoken___V_dispose(var __this);
var Atoken__get_data(var __this);
var Atoken__get_type(var __this);
var Atoken__get_line(var __this);
var Atoken__get_file(var __this);
#define Alexer___DsizeD 23
#define Alexer___DcidD 23
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
var Alexer__new();
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
#define hash___DsizeD 2
#define hash___DcidD 24
#define hash__Cnext 0
#define hash__Chash 1
#define hash__Ckey 2
#define hash__Cvalue 3
var hash__new(var size_);
#define hash__dispose(___this) virtual__dispose(___this)
var hash___V_dispose(var __this);
var hash__add(var __this, var key, var value);
var hash__get(var __this, var key);
#define array___DsizeD 1
#define array___DcidD 25
var array__new(var size);
#define array__dispose(___this) virtual__dispose(___this)
var array___V_dispose(var __this);
#define buffer___DsizeD 3
#define buffer___DcidD 26
var buffer__new(var initial_size);
var buffer__dispose_all(var __this);
#define buffer__dispose(___this) virtual__dispose(___this)
var buffer___V_dispose(var __this);
var buffer__length(var __this);
var buffer__empty(var __this);
var buffer__set_at(var __this, var idx, var elem);
var buffer__get_at(var __this, var idx);
var buffer__push(var __this, var elem);
var buffer__append(var __this, var buf);
var buffer__set_last(var __this, var elem);
var buffer__get_last(var __this);
var buffer__pop(var __this);
var buffer__unshift(var __this, var elem);
var buffer__shift(var __this);
#define string___DsizeD 2
#define string___DcidD 27
var string__new(var alloc);
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
#define Aexpr___DsizeD 11
#define Aexpr___DcidD 28
var Aexpr__new(var op_, var precedence_, var associativity_);
#define Aexpr__dispose(___this) virtual__dispose(___this)
var Aexpr___V_dispose(var __this);
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
#define Aemmiter___DsizeD 18
#define Aemmiter___DcidD 29
var Aemmiter__new();
#define Aemmiter__dispose(___this) virtual__dispose(___this)
var Aemmiter___V_dispose(var __this);
var Aemmiter__emmit(var __this, var par);
var Aemmiter__get_head(var __this);
var Aemmiter__get_data(var __this);
var Aemmiter__get_mid(var __this);
var Aemmiter__add_to_data(var __this, var s);
var Aemmiter__gen_class(var __this);
var Aemmiter__gen_member(var __this, var mb);
var Aemmiter__gen_conditional_call(var __this, var v, var mb);
var Aemmiter__gen_virtuals(var __this);
var Aemmiter__pass_0(var __this, var str, var mb, var k);
var Aemmiter__pass_1(var __this, var str, var mb, var k);
var Aemmiter__pass_2(var __this, var str, var mb, var k);
var Aemmiter__pad(var __this, var depth);
var Aemmiter__find_param(var __this, var stri);
var Aemmiter__find_member(var __this, var stri);
var Aemmiter__find_field(var __this, var stri);
var Aemmiter__find_static(var __this, var stri);
var Aemmiter__find_meth_virt(var __this, var stri);
var Aemmiter__find_local(var __this, var stri);
var Aemmiter__expr_gen_call(var __this, var expr);
var Aemmiter__expr_gen_sub_expr(var __this, var expr);
var Aemmiter__expr_gen_comma(var __this, var expr);
var Aemmiter__expr_gen_index(var __this, var expr);
var Aemmiter__expr_gen_par(var __this, var expr);
var Aemmiter__expr_gen_constant(var __this, var expr);
var Aemmiter__expr_gen_dot(var __this, var expr);
var Aemmiter__gen_string(var __this, var s2, var value);
var Aemmiter__number(var __this, var n);
var Aemmiter__new_string(var __this, var l);
var Aemmiter__expr_gen_str_const(var __this, var expr);
var Aemmiter__expr_gen_char_const(var __this, var expr);
var Aemmiter__expr_gen0(var __this, var expr, var op);
var Aemmiter__expr_gen1(var __this, var expr, var op);
var Aemmiter__expr_gen_assign(var __this, var expr, var op);
var Aemmiter__expr_gen2(var __this, var expr, var op);
var Aemmiter__expr_gen_var(var __this, var expr);
var Aemmiter__expr_process(var __this, var expr);
var Aemmiter__expr_gen(var __this, var expr);
var Aemmiter__is_switch(var __this, var body_, var i, var l);
var Aemmiter__body_gen(var __this, var mb, var k, var vars_, var body_);
var Aemmiter__gen_type(var __this, var mb);
var Aemmiter__add_virtual(var __this, var mb);
var Aemmiter__gen_virtual_caller(var __this, var mb);
var Aemmiter__gen_method_decl(var __this, var dest, var c_name, var name, var mb, var k);
var Aemmiter__pass_3(var __this, var str, var mb, var k);
var Aemmiter__pass_4(var __this, var str, var mb, var k);
var Aemmiter__error(var __this, var t, var e);
var Aemmiter__dump(var __this);
var virtual__dispose(var __this);
static char __strings_Astatement1[]="DONT KNOW WAHT";
static var __string_Astatement1[]={0,0, 0,-1};
static char __strings_Aclass2[]="\t";
static var __string_Aclass2[]={0,0, 0,-1};
static char __strings_Aclass3[]="Unknown operator.";
static var __string_Aclass3[]={0,0, 0,-1};
static char __strings_Aclass4[]="What a mess in parenthesis..";
static var __string_Aclass4[]={0,0, 0,-1};
static char __strings_Aclass5[]="What a mess in index..";
static var __string_Aclass5[]={0,0, 0,-1};
static char __strings_Aclass6[]="What a mess..";
static var __string_Aclass6[]={0,0, 0,-1};
static char __strings_Aparser7[]=": found '";
static var __string_Aparser7[]={0,0, 0,-1};
static char __strings_Aparser8[]="' at line(";
static var __string_Aparser8[]={0,0, 0,-1};
static char __strings_Aparser9[]="): ";
static var __string_Aparser9[]={0,0, 0,-1};
static char __strings_Aparser10[]="class";
static var __string_Aparser10[]={0,0, 0,-1};
static char __strings_Aparser11[]="expecting 'class' keyword";
static var __string_Aparser11[]={0,0, 0,-1};
static char __strings_Aparser12[]="expecting identifier";
static var __string_Aparser12[]={0,0, 0,-1};
static char __strings_Aparser13[]="implements";
static var __string_Aparser13[]={0,0, 0,-1};
static char __strings_Aparser14[]="expecting class identifier";
static var __string_Aparser14[]={0,0, 0,-1};
static char __strings_Aparser15[]=",";
static var __string_Aparser15[]={0,0, 0,-1};
static char __strings_Aparser16[]="expecting class identifier";
static var __string_Aparser16[]={0,0, 0,-1};
static char __strings_Aparser17[]="{";
static var __string_Aparser17[]={0,0, 0,-1};
static char __strings_Aparser18[]="expecting '{'";
static var __string_Aparser18[]={0,0, 0,-1};
static char __strings_Aparser19[]="}";
static var __string_Aparser19[]={0,0, 0,-1};
static char __strings_Aparser20[]="expecting '}'";
static var __string_Aparser20[]={0,0, 0,-1};
static char __strings_Aparser21[]="field";
static var __string_Aparser21[]={0,0, 0,-1};
static char __strings_Aparser22[]="static";
static var __string_Aparser22[]={0,0, 0,-1};
static char __strings_Aparser23[]=",";
static var __string_Aparser23[]={0,0, 0,-1};
static char __strings_Aparser24[]=";";
static var __string_Aparser24[]={0,0, 0,-1};
static char __strings_Aparser25[]="';' expected.";
static var __string_Aparser25[]={0,0, 0,-1};
static char __strings_Aparser26[]="Name of variable expected.";
static var __string_Aparser26[]={0,0, 0,-1};
static char __strings_Aparser27[]="int";
static var __string_Aparser27[]={0,0, 0,-1};
static char __strings_Aparser28[]="void";
static var __string_Aparser28[]={0,0, 0,-1};
static char __strings_Aparser29[]="Type expected.";
static var __string_Aparser29[]={0,0, 0,-1};
static char __strings_Aparser30[]="const";
static var __string_Aparser30[]={0,0, 0,-1};
static char __strings_Aparser31[]=":=";
static var __string_Aparser31[]={0,0, 0,-1};
static char __strings_Aparser32[]="':=' expected.";
static var __string_Aparser32[]={0,0, 0,-1};
static char __strings_Aparser33[]=";";
static var __string_Aparser33[]={0,0, 0,-1};
static char __strings_Aparser34[]="Expected constant initialiser.";
static var __string_Aparser34[]={0,0, 0,-1};
static char __strings_Aparser35[]=";";
static var __string_Aparser35[]={0,0, 0,-1};
static char __strings_Aparser36[]="';' expected.";
static var __string_Aparser36[]={0,0, 0,-1};
static char __strings_Aparser37[]="constructor";
static var __string_Aparser37[]={0,0, 0,-1};
static char __strings_Aparser38[]="function";
static var __string_Aparser38[]={0,0, 0,-1};
static char __strings_Aparser39[]="method";
static var __string_Aparser39[]={0,0, 0,-1};
static char __strings_Aparser40[]="virtual";
static var __string_Aparser40[]={0,0, 0,-1};
static char __strings_Aparser41[]="void";
static var __string_Aparser41[]={0,0, 0,-1};
static char __strings_Aparser42[]="(";
static var __string_Aparser42[]={0,0, 0,-1};
static char __strings_Aparser43[]="'(' expected.";
static var __string_Aparser43[]={0,0, 0,-1};
static char __strings_Aparser44[]=")";
static var __string_Aparser44[]={0,0, 0,-1};
static char __strings_Aparser45[]="')' expected.";
static var __string_Aparser45[]={0,0, 0,-1};
static char __strings_Aparser46[]=")";
static var __string_Aparser46[]={0,0, 0,-1};
static char __strings_Aparser47[]=",";
static var __string_Aparser47[]={0,0, 0,-1};
static char __strings_Aparser48[]="in";
static var __string_Aparser48[]={0,0, 0,-1};
static char __strings_Aparser49[]="out";
static var __string_Aparser49[]={0,0, 0,-1};
static char __strings_Aparser50[]="io";
static var __string_Aparser50[]={0,0, 0,-1};
static char __strings_Aparser51[]="Expected 'in/out/io'.";
static var __string_Aparser51[]={0,0, 0,-1};
static char __strings_Aparser52[]="{";
static var __string_Aparser52[]={0,0, 0,-1};
static char __strings_Aparser53[]="'{' expected.";
static var __string_Aparser53[]={0,0, 0,-1};
static char __strings_Aparser54[]="}";
static var __string_Aparser54[]={0,0, 0,-1};
static char __strings_Aparser55[]="'}' expected at end of subroutine body.";
static var __string_Aparser55[]={0,0, 0,-1};
static char __strings_Aparser56[]="var";
static var __string_Aparser56[]={0,0, 0,-1};
static char __strings_Aparser57[]=",";
static var __string_Aparser57[]={0,0, 0,-1};
static char __strings_Aparser58[]=";";
static var __string_Aparser58[]={0,0, 0,-1};
static char __strings_Aparser59[]="';' expected at end of variable declaration";
static var __string_Aparser59[]={0,0, 0,-1};
static char __strings_Aparser60[]="break";
static var __string_Aparser60[]={0,0, 0,-1};
static char __strings_Aparser61[]=";";
static var __string_Aparser61[]={0,0, 0,-1};
static char __strings_Aparser62[]="';' expected after break";
static var __string_Aparser62[]={0,0, 0,-1};
static char __strings_Aparser63[]="if";
static var __string_Aparser63[]={0,0, 0,-1};
static char __strings_Aparser64[]="(";
static var __string_Aparser64[]={0,0, 0,-1};
static char __strings_Aparser65[]="'(' expected after if.";
static var __string_Aparser65[]={0,0, 0,-1};
static char __strings_Aparser66[]=")";
static var __string_Aparser66[]={0,0, 0,-1};
static char __strings_Aparser67[]="')' expected after if condition.";
static var __string_Aparser67[]={0,0, 0,-1};
static char __strings_Aparser68[]="{";
static var __string_Aparser68[]={0,0, 0,-1};
static char __strings_Aparser69[]="'{' expected after if ().";
static var __string_Aparser69[]={0,0, 0,-1};
static char __strings_Aparser70[]="}";
static var __string_Aparser70[]={0,0, 0,-1};
static char __strings_Aparser71[]="'}' expected after if body.";
static var __string_Aparser71[]={0,0, 0,-1};
static char __strings_Aparser72[]="else";
static var __string_Aparser72[]={0,0, 0,-1};
static char __strings_Aparser73[]="if";
static var __string_Aparser73[]={0,0, 0,-1};
static char __strings_Aparser74[]="{";
static var __string_Aparser74[]={0,0, 0,-1};
static char __strings_Aparser75[]="'{' expected after else.";
static var __string_Aparser75[]={0,0, 0,-1};
static char __strings_Aparser76[]="}";
static var __string_Aparser76[]={0,0, 0,-1};
static char __strings_Aparser77[]="'}' expected after else body.";
static var __string_Aparser77[]={0,0, 0,-1};
static char __strings_Aparser78[]="while";
static var __string_Aparser78[]={0,0, 0,-1};
static char __strings_Aparser79[]="(";
static var __string_Aparser79[]={0,0, 0,-1};
static char __strings_Aparser80[]="'(' expected after while.";
static var __string_Aparser80[]={0,0, 0,-1};
static char __strings_Aparser81[]=")";
static var __string_Aparser81[]={0,0, 0,-1};
static char __strings_Aparser82[]="')' expected after while condition.";
static var __string_Aparser82[]={0,0, 0,-1};
static char __strings_Aparser83[]="{";
static var __string_Aparser83[]={0,0, 0,-1};
static char __strings_Aparser84[]="'{' expected after while ().";
static var __string_Aparser84[]={0,0, 0,-1};
static char __strings_Aparser85[]="}";
static var __string_Aparser85[]={0,0, 0,-1};
static char __strings_Aparser86[]="'}' expected after while body.";
static var __string_Aparser86[]={0,0, 0,-1};
static char __strings_Aparser87[]="return";
static var __string_Aparser87[]={0,0, 0,-1};
static char __strings_Aparser88[]=";";
static var __string_Aparser88[]={0,0, 0,-1};
static char __strings_Aparser89[]=";";
static var __string_Aparser89[]={0,0, 0,-1};
static char __strings_Aparser90[]="';' expected";
static var __string_Aparser90[]={0,0, 0,-1};
static char __strings_Aparser91[]=":=";
static var __string_Aparser91[]={0,0, 0,-1};
static char __strings_Aparser92[]="[";
static var __string_Aparser92[]={0,0, 0,-1};
static char __strings_Aparser93[]="}";
static var __string_Aparser93[]={0,0, 0,-1};
static char __strings_Aparser94[]=":=";
static var __string_Aparser94[]={0,0, 0,-1};
static char __strings_Aparser95[]="[";
static var __string_Aparser95[]={0,0, 0,-1};
static char __strings_Aparser96[]=";";
static var __string_Aparser96[]={0,0, 0,-1};
static char __strings_Aparser97[]="';' expected at end of let statement";
static var __string_Aparser97[]={0,0, 0,-1};
static char __strings_Aparser98[]="]";
static var __string_Aparser98[]={0,0, 0,-1};
static char __strings_Aparser99[]="']' expected in left side of let statement";
static var __string_Aparser99[]={0,0, 0,-1};
static char __strings_Aparser100[]=":=";
static var __string_Aparser100[]={0,0, 0,-1};
static char __strings_Aparser101[]="':=' expected in let statement";
static var __string_Aparser101[]={0,0, 0,-1};
static char __strings_Aparser102[]=";";
static var __string_Aparser102[]={0,0, 0,-1};
static char __strings_Aparser103[]="';' expected at end of do statement";
static var __string_Aparser103[]={0,0, 0,-1};
static char __strings_Aparser104[]="+";
static var __string_Aparser104[]={0,0, 0,-1};
static char __strings_Aparser105[]="-";
static var __string_Aparser105[]={0,0, 0,-1};
static char __strings_Aparser106[]="*";
static var __string_Aparser106[]={0,0, 0,-1};
static char __strings_Aparser107[]="/";
static var __string_Aparser107[]={0,0, 0,-1};
static char __strings_Aparser108[]="%";
static var __string_Aparser108[]={0,0, 0,-1};
static char __strings_Aparser109[]="&&";
static var __string_Aparser109[]={0,0, 0,-1};
static char __strings_Aparser110[]="||";
static var __string_Aparser110[]={0,0, 0,-1};
static char __strings_Aparser111[]="==";
static var __string_Aparser111[]={0,0, 0,-1};
static char __strings_Aparser112[]="!=";
static var __string_Aparser112[]={0,0, 0,-1};
static char __strings_Aparser113[]=">=";
static var __string_Aparser113[]={0,0, 0,-1};
static char __strings_Aparser114[]="<=";
static var __string_Aparser114[]={0,0, 0,-1};
static char __strings_Aparser115[]=">";
static var __string_Aparser115[]={0,0, 0,-1};
static char __strings_Aparser116[]="<";
static var __string_Aparser116[]={0,0, 0,-1};
static char __strings_Aparser117[]="this";
static var __string_Aparser117[]={0,0, 0,-1};
static char __strings_Aparser118[]="null";
static var __string_Aparser118[]={0,0, 0,-1};
static char __strings_Aparser119[]="[";
static var __string_Aparser119[]={0,0, 0,-1};
static char __strings_Aparser120[]=".$";
static var __string_Aparser120[]={0,0, 0,-1};
static char __strings_Aparser121[]="constant name expected.";
static var __string_Aparser121[]={0,0, 0,-1};
static char __strings_Aparser122[]="-";
static var __string_Aparser122[]={0,0, 0,-1};
static char __strings_Aparser123[]="+";
static var __string_Aparser123[]={0,0, 0,-1};
static char __strings_Aparser124[]="!";
static var __string_Aparser124[]={0,0, 0,-1};
static char __strings_Aparser125[]="(";
static var __string_Aparser125[]={0,0, 0,-1};
static char __strings_Aparser126[]="unexpected term";
static var __string_Aparser126[]={0,0, 0,-1};
static char __strings_Aparser127[]="(";
static var __string_Aparser127[]={0,0, 0,-1};
static char __strings_Aparser128[]=".";
static var __string_Aparser128[]={0,0, 0,-1};
static char __strings_Aparser129[]=")";
static var __string_Aparser129[]={0,0, 0,-1};
static char __strings_Aparser130[]="')' expected after term";
static var __string_Aparser130[]={0,0, 0,-1};
static char __strings_Aparser131[]="]";
static var __string_Aparser131[]={0,0, 0,-1};
static char __strings_Aparser132[]="']' expected after term";
static var __string_Aparser132[]={0,0, 0,-1};
static char __strings_Aparser133[]="(";
static var __string_Aparser133[]={0,0, 0,-1};
static char __strings_Aparser134[]="'(' expected in subroutine call.";
static var __string_Aparser134[]={0,0, 0,-1};
static char __strings_Aparser135[]=")";
static var __string_Aparser135[]={0,0, 0,-1};
static char __strings_Aparser136[]=")";
static var __string_Aparser136[]={0,0, 0,-1};
static char __strings_Aparser137[]="')' expected at end of subroutrine call";
static var __string_Aparser137[]={0,0, 0,-1};
static char __strings_Aparser138[]=",";
static var __string_Aparser138[]={0,0, 0,-1};
static char __strings_Aparser139[]=",";
static var __string_Aparser139[]={0,0, 0,-1};
static char __strings_Aparser140[]="unexpected state";
static var __string_Aparser140[]={0,0, 0,-1};
static char __strings_mainChello[]=" --- The Jack 3.0.3 ---";
static var __string_mainChello[]={0,0, 0,-1};
static char __strings_main141[]="Including : ";
static var __string_main141[]={0,0, 0,-1};
static char __strings_main142[]="";
static var __string_main142[]={0,0, 0,-1};
static char __strings_main143[]="Compiling : ";
static var __string_main143[]={0,0, 0,-1};
static char __strings_main144[]="";
static var __string_main144[]={0,0, 0,-1};
static char __strings_main145[]="";
static var __string_main145[]={0,0, 0,-1};
static char __strings_main146[]="wrong number of command line arguments";
static var __string_main146[]={0,0, 0,-1};
static char __strings_main147[]=".jack.c";
static var __string_main147[]={0,0, 0,-1};
static char __strings_main148[]="";
static var __string_main148[]={0,0, 0,-1};
static char __strings_main149[]="\n";
static var __string_main149[]={0,0, 0,-1};
static char __strings_main150[]=".jack";
static var __string_main150[]={0,0, 0,-1};
static char __strings_main151[]=".h";
static var __string_main151[]={0,0, 0,-1};
static char __strings_main152[]=".c";
static var __string_main152[]={0,0, 0,-1};
static char __strings_main153[]="\n";
static var __string_main153[]={0,0, 0,-1};
static char __strings_main154[]="";
static var __string_main154[]={0,0, 0,-1};
static char __strings_main155[]="Output to : ";
static var __string_main155[]={0,0, 0,-1};
static char __strings_Alexer156[]="Lexer: ";
static var __string_Alexer156[]={0,0, 0,-1};
static char __strings_Alexer157[]=" @ (";
static var __string_Alexer157[]={0,0, 0,-1};
static char __strings_Alexer158[]=") : '";
static var __string_Alexer158[]={0,0, 0,-1};
static char __strings_Alexer159[]="' ";
static var __string_Alexer159[]={0,0, 0,-1};
static char __strings_Alexer160[]="newline in string.";
static var __string_Alexer160[]={0,0, 0,-1};
static char __strings_Alexer161[]="unterminated token.";
static var __string_Alexer161[]={0,0, 0,-1};
static char __strings_string162[]="";
static var __string_string162[]={0,0, 0,-1};
static char __strings_Aexpr163[]=" ";
static var __string_Aexpr163[]={0,0, 0,-1};
static char __strings_Aexpr164[]="";
static var __string_Aexpr164[]={0,0, 0,-1};
static char __strings_Aemmiter165[]="static void std__init_strings()\n{\n";
static var __string_Aemmiter165[]={0,0, 0,-1};
static char __strings_Aemmiter166[]="}\n";
static var __string_Aemmiter166[]={0,0, 0,-1};
static char __strings_Aemmiter167[]="// class ";
static var __string_Aemmiter167[]={0,0, 0,-1};
static char __strings_Aemmiter168[]="\n";
static var __string_Aemmiter168[]={0,0, 0,-1};
static char __strings_Aemmiter169[]="#define ";
static var __string_Aemmiter169[]={0,0, 0,-1};
static char __strings_Aemmiter170[]="___DsizeD ";
static var __string_Aemmiter170[]={0,0, 0,-1};
static char __strings_Aemmiter171[]="\n";
static var __string_Aemmiter171[]={0,0, 0,-1};
static char __strings_Aemmiter172[]="#define ";
static var __string_Aemmiter172[]={0,0, 0,-1};
static char __strings_Aemmiter173[]="___DcidD ";
static var __string_Aemmiter173[]={0,0, 0,-1};
static char __strings_Aemmiter174[]="\n";
static var __string_Aemmiter174[]={0,0, 0,-1};
static char __strings_Aemmiter175[]="\tcase ";
static var __string_Aemmiter175[]={0,0, 0,-1};
static char __strings_Aemmiter176[]="___DcidD:\n\t\treturn ";
static var __string_Aemmiter176[]={0,0, 0,-1};
static char __strings_Aemmiter177[]="___V_";
static var __string_Aemmiter177[]={0,0, 0,-1};
static char __strings_Aemmiter178[]="(__this";
static var __string_Aemmiter178[]={0,0, 0,-1};
static char __strings_Aemmiter179[]=", ";
static var __string_Aemmiter179[]={0,0, 0,-1};
static char __strings_Aemmiter180[]=");\n";
static var __string_Aemmiter180[]={0,0, 0,-1};
static char __strings_Aemmiter181[]="virtual";
static var __string_Aemmiter181[]={0,0, 0,-1};
static char __strings_Aemmiter182[]=";\n";
static var __string_Aemmiter182[]={0,0, 0,-1};
static char __strings_Aemmiter183[]="virtual";
static var __string_Aemmiter183[]={0,0, 0,-1};
static char __strings_Aemmiter184[]="\n{\n\tvar cid;\n";
static var __string_Aemmiter184[]={0,0, 0,-1};
static char __strings_Aemmiter185[]="\tcid = ((var*)__this)[-1];\n";
static var __string_Aemmiter185[]={0,0, 0,-1};
static char __strings_Aemmiter186[]="\tswitch (cid) {\n";
static var __string_Aemmiter186[]={0,0, 0,-1};
static char __strings_Aemmiter187[]="\tdefault:\n\t\tstd__panic();\n\t}\n";
static var __string_Aemmiter187[]={0,0, 0,-1};
static char __strings_Aemmiter188[]="\treturn 0;\n}\n";
static var __string_Aemmiter188[]={0,0, 0,-1};
static char __strings_Aemmiter189[]="#define ";
static var __string_Aemmiter189[]={0,0, 0,-1};
static char __strings_Aemmiter190[]="__";
static var __string_Aemmiter190[]={0,0, 0,-1};
static char __strings_Aemmiter191[]=" ";
static var __string_Aemmiter191[]={0,0, 0,-1};
static char __strings_Aemmiter192[]="(var)(__string_";
static var __string_Aemmiter192[]={0,0, 0,-1};
static char __strings_Aemmiter193[]="+2)";
static var __string_Aemmiter193[]={0,0, 0,-1};
static char __strings_Aemmiter194[]="'";
static var __string_Aemmiter194[]={0,0, 0,-1};
static char __strings_Aemmiter195[]="'";
static var __string_Aemmiter195[]={0,0, 0,-1};
static char __strings_Aemmiter196[]="\n";
static var __string_Aemmiter196[]={0,0, 0,-1};
static char __strings_Aemmiter197[]="struct ";
static var __string_Aemmiter197[]={0,0, 0,-1};
static char __strings_Aemmiter198[]=" {\n";
static var __string_Aemmiter198[]={0,0, 0,-1};
static char __strings_Aemmiter199[]="\tvar ";
static var __string_Aemmiter199[]={0,0, 0,-1};
static char __strings_Aemmiter200[]=";\n";
static var __string_Aemmiter200[]={0,0, 0,-1};
static char __strings_Aemmiter201[]="};\n";
static var __string_Aemmiter201[]={0,0, 0,-1};
static char __strings_Aemmiter202[]="static var ";
static var __string_Aemmiter202[]={0,0, 0,-1};
static char __strings_Aemmiter203[]="__";
static var __string_Aemmiter203[]={0,0, 0,-1};
static char __strings_Aemmiter204[]=" = 0;\n";
static var __string_Aemmiter204[]={0,0, 0,-1};
static char __strings_Aemmiter205[]="\t";
static var __string_Aemmiter205[]={0,0, 0,-1};
static char __strings_Aemmiter206[]="__";
static var __string_Aemmiter206[]={0,0, 0,-1};
static char __strings_Aemmiter207[]="(__this, ";
static var __string_Aemmiter207[]={0,0, 0,-1};
static char __strings_Aemmiter208[]=")";
static var __string_Aemmiter208[]={0,0, 0,-1};
static char __strings_Aemmiter209[]="(__this)";
static var __string_Aemmiter209[]={0,0, 0,-1};
static char __strings_Aemmiter210[]="cannot find method.";
static var __string_Aemmiter210[]={0,0, 0,-1};
static char __strings_Aemmiter211[]="wrong type of method.";
static var __string_Aemmiter211[]={0,0, 0,-1};
static char __strings_Aemmiter212[]="__";
static var __string_Aemmiter212[]={0,0, 0,-1};
static char __strings_Aemmiter213[]="(";
static var __string_Aemmiter213[]={0,0, 0,-1};
static char __strings_Aemmiter214[]="_this->";
static var __string_Aemmiter214[]={0,0, 0,-1};
static char __strings_Aemmiter215[]=",";
static var __string_Aemmiter215[]={0,0, 0,-1};
static char __strings_Aemmiter216[]=")";
static var __string_Aemmiter216[]={0,0, 0,-1};
static char __strings_Aemmiter217[]="__";
static var __string_Aemmiter217[]={0,0, 0,-1};
static char __strings_Aemmiter218[]="(";
static var __string_Aemmiter218[]={0,0, 0,-1};
static char __strings_Aemmiter219[]=")";
static var __string_Aemmiter219[]={0,0, 0,-1};
static char __strings_Aemmiter220[]="";
static var __string_Aemmiter220[]={0,0, 0,-1};
static char __strings_Aemmiter221[]=",";
static var __string_Aemmiter221[]={0,0, 0,-1};
static char __strings_Aemmiter222[]="((var*)";
static var __string_Aemmiter222[]={0,0, 0,-1};
static char __strings_Aemmiter223[]=")[";
static var __string_Aemmiter223[]={0,0, 0,-1};
static char __strings_Aemmiter224[]="]";
static var __string_Aemmiter224[]={0,0, 0,-1};
static char __strings_Aemmiter225[]="(";
static var __string_Aemmiter225[]={0,0, 0,-1};
static char __strings_Aemmiter226[]=")";
static var __string_Aemmiter226[]={0,0, 0,-1};
static char __strings_Aemmiter227[]="__";
static var __string_Aemmiter227[]={0,0, 0,-1};
static char __strings_Aemmiter228[]="static char __strings_";
static var __string_Aemmiter228[]={0,0, 0,-1};
static char __strings_Aemmiter229[]="[]=";
static var __string_Aemmiter229[]={0,0, 0,-1};
static char __strings_Aemmiter230[]="\"";
static var __string_Aemmiter230[]={0,0, 0,-1};
static char __strings_Aemmiter231[]="\"";
static var __string_Aemmiter231[]={0,0, 0,-1};
static char __strings_Aemmiter232[]=";\n";
static var __string_Aemmiter232[]={0,0, 0,-1};
static char __strings_Aemmiter233[]="static var __string_";
static var __string_Aemmiter233[]={0,0, 0,-1};
static char __strings_Aemmiter234[]="[]={0,0, ";
static var __string_Aemmiter234[]={0,0, 0,-1};
static char __strings_Aemmiter235[]="0,-1};\n";
static var __string_Aemmiter235[]={0,0, 0,-1};
static char __strings_Aemmiter236[]="\t__string_";
static var __string_Aemmiter236[]={0,0, 0,-1};
static char __strings_Aemmiter237[]="[2]=";
static var __string_Aemmiter237[]={0,0, 0,-1};
static char __strings_Aemmiter238[]="(var) __strings_";
static var __string_Aemmiter238[]={0,0, 0,-1};
static char __strings_Aemmiter239[]=";\n";
static var __string_Aemmiter239[]={0,0, 0,-1};
static char __strings_Aemmiter240[]="(var)(__string_";
static var __string_Aemmiter240[]={0,0, 0,-1};
static char __strings_Aemmiter241[]="+ 2)";
static var __string_Aemmiter241[]={0,0, 0,-1};
static char __strings_Aemmiter242[]="'";
static var __string_Aemmiter242[]={0,0, 0,-1};
static char __strings_Aemmiter243[]="\\0";
static var __string_Aemmiter243[]={0,0, 0,-1};
static char __strings_Aemmiter244[]="'";
static var __string_Aemmiter244[]={0,0, 0,-1};
static char __strings_Aemmiter245[]="(";
static var __string_Aemmiter245[]={0,0, 0,-1};
static char __strings_Aemmiter246[]=")";
static var __string_Aemmiter246[]={0,0, 0,-1};
static char __strings_Aemmiter247[]="(";
static var __string_Aemmiter247[]={0,0, 0,-1};
static char __strings_Aemmiter248[]=")";
static var __string_Aemmiter248[]={0,0, 0,-1};
static char __strings_Aemmiter249[]="(";
static var __string_Aemmiter249[]={0,0, 0,-1};
static char __strings_Aemmiter250[]=")";
static var __string_Aemmiter250[]={0,0, 0,-1};
static char __strings_Aemmiter251[]="_this->";
static var __string_Aemmiter251[]={0,0, 0,-1};
static char __strings_Aemmiter252[]="__";
static var __string_Aemmiter252[]={0,0, 0,-1};
static char __strings_Aemmiter253[]="0";
static var __string_Aemmiter253[]={0,0, 0,-1};
static char __strings_Aemmiter254[]="__this";
static var __string_Aemmiter254[]={0,0, 0,-1};
static char __strings_Aemmiter255[]="wrong expression...";
static var __string_Aemmiter255[]={0,0, 0,-1};
static char __strings_Aemmiter256[]="=";
static var __string_Aemmiter256[]={0,0, 0,-1};
static char __strings_Aemmiter257[]="==";
static var __string_Aemmiter257[]={0,0, 0,-1};
static char __strings_Aemmiter258[]="!=";
static var __string_Aemmiter258[]={0,0, 0,-1};
static char __strings_Aemmiter259[]=">=";
static var __string_Aemmiter259[]={0,0, 0,-1};
static char __strings_Aemmiter260[]="<=";
static var __string_Aemmiter260[]={0,0, 0,-1};
static char __strings_Aemmiter261[]=">";
static var __string_Aemmiter261[]={0,0, 0,-1};
static char __strings_Aemmiter262[]="<";
static var __string_Aemmiter262[]={0,0, 0,-1};
static char __strings_Aemmiter263[]="&&";
static var __string_Aemmiter263[]={0,0, 0,-1};
static char __strings_Aemmiter264[]="||";
static var __string_Aemmiter264[]={0,0, 0,-1};
static char __strings_Aemmiter265[]="+";
static var __string_Aemmiter265[]={0,0, 0,-1};
static char __strings_Aemmiter266[]="-";
static var __string_Aemmiter266[]={0,0, 0,-1};
static char __strings_Aemmiter267[]="*";
static var __string_Aemmiter267[]={0,0, 0,-1};
static char __strings_Aemmiter268[]="/";
static var __string_Aemmiter268[]={0,0, 0,-1};
static char __strings_Aemmiter269[]="%";
static var __string_Aemmiter269[]={0,0, 0,-1};
static char __strings_Aemmiter270[]="!";
static var __string_Aemmiter270[]={0,0, 0,-1};
static char __strings_Aemmiter271[]="+";
static var __string_Aemmiter271[]={0,0, 0,-1};
static char __strings_Aemmiter272[]="-";
static var __string_Aemmiter272[]={0,0, 0,-1};
static char __strings_Aemmiter273[]="UNKNOW OP\n";
static var __string_Aemmiter273[]={0,0, 0,-1};
static char __strings_Aemmiter274[]="";
static var __string_Aemmiter274[]={0,0, 0,-1};
static char __strings_Aemmiter275[]="||";
static var __string_Aemmiter275[]={0,0, 0,-1};
static char __strings_Aemmiter276[]="{\n";
static var __string_Aemmiter276[]={0,0, 0,-1};
static char __strings_Aemmiter277[]="\tvar ";
static var __string_Aemmiter277[]={0,0, 0,-1};
static char __strings_Aemmiter278[]=";\n";
static var __string_Aemmiter278[]={0,0, 0,-1};
static char __strings_Aemmiter279[]="\tstruct ";
static var __string_Aemmiter279[]={0,0, 0,-1};
static char __strings_Aemmiter280[]=" *_this;\n";
static var __string_Aemmiter280[]={0,0, 0,-1};
static char __strings_Aemmiter281[]="\tNEW(";
static var __string_Aemmiter281[]={0,0, 0,-1};
static char __strings_Aemmiter282[]=");\n";
static var __string_Aemmiter282[]={0,0, 0,-1};
static char __strings_Aemmiter283[]="\t_this = (void*)__this;\n";
static var __string_Aemmiter283[]={0,0, 0,-1};
static char __strings_Aemmiter284[]="\t(void)_this;\n";
static var __string_Aemmiter284[]={0,0, 0,-1};
static char __strings_Aemmiter285[]="\tstruct ";
static var __string_Aemmiter285[]={0,0, 0,-1};
static char __strings_Aemmiter286[]=" *_this;\n";
static var __string_Aemmiter286[]={0,0, 0,-1};
static char __strings_Aemmiter287[]="\t_this = (void*)__this;\n";
static var __string_Aemmiter287[]={0,0, 0,-1};
static char __strings_Aemmiter288[]="\t(void)_this;\n";
static var __string_Aemmiter288[]={0,0, 0,-1};
static char __strings_Aemmiter289[]="\n";
static var __string_Aemmiter289[]={0,0, 0,-1};
static char __strings_Aemmiter290[]=" else if (";
static var __string_Aemmiter290[]={0,0, 0,-1};
static char __strings_Aemmiter291[]="if (";
static var __string_Aemmiter291[]={0,0, 0,-1};
static char __strings_Aemmiter292[]=") {";
static var __string_Aemmiter292[]={0,0, 0,-1};
static char __strings_Aemmiter293[]=" else {";
static var __string_Aemmiter293[]={0,0, 0,-1};
static char __strings_Aemmiter294[]="break;";
static var __string_Aemmiter294[]={0,0, 0,-1};
static char __strings_Aemmiter295[]="return ";
static var __string_Aemmiter295[]={0,0, 0,-1};
static char __strings_Aemmiter296[]=";";
static var __string_Aemmiter296[]={0,0, 0,-1};
static char __strings_Aemmiter297[]="return 0;";
static var __string_Aemmiter297[]={0,0, 0,-1};
static char __strings_Aemmiter298[]=";";
static var __string_Aemmiter298[]={0,0, 0,-1};
static char __strings_Aemmiter299[]=";";
static var __string_Aemmiter299[]={0,0, 0,-1};
static char __strings_Aemmiter300[]="while (";
static var __string_Aemmiter300[]={0,0, 0,-1};
static char __strings_Aemmiter301[]=") {";
static var __string_Aemmiter301[]={0,0, 0,-1};
static char __strings_Aemmiter302[]="ERROR !!";
static var __string_Aemmiter302[]={0,0, 0,-1};
static char __strings_Aemmiter303[]="\n";
static var __string_Aemmiter303[]={0,0, 0,-1};
static char __strings_Aemmiter304[]="}";
static var __string_Aemmiter304[]={0,0, 0,-1};
static char __strings_Aemmiter305[]="\n";
static var __string_Aemmiter305[]={0,0, 0,-1};
static char __strings_Aemmiter306[]="}";
static var __string_Aemmiter306[]={0,0, 0,-1};
static char __strings_Aemmiter307[]="\n";
static var __string_Aemmiter307[]={0,0, 0,-1};
static char __strings_Aemmiter308[]="var";
static var __string_Aemmiter308[]={0,0, 0,-1};
static char __strings_Aemmiter309[]="void";
static var __string_Aemmiter309[]={0,0, 0,-1};
static char __strings_Aemmiter310[]="unknown type";
static var __string_Aemmiter310[]={0,0, 0,-1};
static char __strings_Aemmiter311[]="#define ";
static var __string_Aemmiter311[]={0,0, 0,-1};
static char __strings_Aemmiter312[]="__";
static var __string_Aemmiter312[]={0,0, 0,-1};
static char __strings_Aemmiter313[]="(___this";
static var __string_Aemmiter313[]={0,0, 0,-1};
static char __strings_Aemmiter314[]=", ";
static var __string_Aemmiter314[]={0,0, 0,-1};
static char __strings_Aemmiter315[]=") virtual__";
static var __string_Aemmiter315[]={0,0, 0,-1};
static char __strings_Aemmiter316[]="(___this";
static var __string_Aemmiter316[]={0,0, 0,-1};
static char __strings_Aemmiter317[]=", ";
static var __string_Aemmiter317[]={0,0, 0,-1};
static char __strings_Aemmiter318[]=")\n";
static var __string_Aemmiter318[]={0,0, 0,-1};
static char __strings_Aemmiter319[]="var ";
static var __string_Aemmiter319[]={0,0, 0,-1};
static char __strings_Aemmiter320[]="__";
static var __string_Aemmiter320[]={0,0, 0,-1};
static char __strings_Aemmiter321[]="(";
static var __string_Aemmiter321[]={0,0, 0,-1};
static char __strings_Aemmiter322[]="var __this";
static var __string_Aemmiter322[]={0,0, 0,-1};
static char __strings_Aemmiter323[]=", ";
static var __string_Aemmiter323[]={0,0, 0,-1};
static char __strings_Aemmiter324[]="var ";
static var __string_Aemmiter324[]={0,0, 0,-1};
static char __strings_Aemmiter325[]=")";
static var __string_Aemmiter325[]={0,0, 0,-1};
static char __strings_Aemmiter326[]="_V_";
static var __string_Aemmiter326[]={0,0, 0,-1};
static char __strings_Aemmiter327[]=";\n";
static var __string_Aemmiter327[]={0,0, 0,-1};
static char __strings_Aemmiter328[]="\n";
static var __string_Aemmiter328[]={0,0, 0,-1};
static char __strings_Aemmiter329[]=";\n";
static var __string_Aemmiter329[]={0,0, 0,-1};
static char __strings_Aemmiter330[]="\n";
static var __string_Aemmiter330[]={0,0, 0,-1};
static char __strings_Aemmiter331[]=": at line (";
static var __string_Aemmiter331[]={0,0, 0,-1};
static char __strings_Aemmiter332[]=") '";
static var __string_Aemmiter332[]={0,0, 0,-1};
static char __strings_Aemmiter333[]="' ";
static var __string_Aemmiter333[]={0,0, 0,-1};
static void std__init_strings()
{
	__string_Astatement1[2]=(var) __strings_Astatement1;
	__string_Aclass2[2]=(var) __strings_Aclass2;
	__string_Aclass3[2]=(var) __strings_Aclass3;
	__string_Aclass4[2]=(var) __strings_Aclass4;
	__string_Aclass5[2]=(var) __strings_Aclass5;
	__string_Aclass6[2]=(var) __strings_Aclass6;
	__string_Aparser7[2]=(var) __strings_Aparser7;
	__string_Aparser8[2]=(var) __strings_Aparser8;
	__string_Aparser9[2]=(var) __strings_Aparser9;
	__string_Aparser10[2]=(var) __strings_Aparser10;
	__string_Aparser11[2]=(var) __strings_Aparser11;
	__string_Aparser12[2]=(var) __strings_Aparser12;
	__string_Aparser13[2]=(var) __strings_Aparser13;
	__string_Aparser14[2]=(var) __strings_Aparser14;
	__string_Aparser15[2]=(var) __strings_Aparser15;
	__string_Aparser16[2]=(var) __strings_Aparser16;
	__string_Aparser17[2]=(var) __strings_Aparser17;
	__string_Aparser18[2]=(var) __strings_Aparser18;
	__string_Aparser19[2]=(var) __strings_Aparser19;
	__string_Aparser20[2]=(var) __strings_Aparser20;
	__string_Aparser21[2]=(var) __strings_Aparser21;
	__string_Aparser22[2]=(var) __strings_Aparser22;
	__string_Aparser23[2]=(var) __strings_Aparser23;
	__string_Aparser24[2]=(var) __strings_Aparser24;
	__string_Aparser25[2]=(var) __strings_Aparser25;
	__string_Aparser26[2]=(var) __strings_Aparser26;
	__string_Aparser27[2]=(var) __strings_Aparser27;
	__string_Aparser28[2]=(var) __strings_Aparser28;
	__string_Aparser29[2]=(var) __strings_Aparser29;
	__string_Aparser30[2]=(var) __strings_Aparser30;
	__string_Aparser31[2]=(var) __strings_Aparser31;
	__string_Aparser32[2]=(var) __strings_Aparser32;
	__string_Aparser33[2]=(var) __strings_Aparser33;
	__string_Aparser34[2]=(var) __strings_Aparser34;
	__string_Aparser35[2]=(var) __strings_Aparser35;
	__string_Aparser36[2]=(var) __strings_Aparser36;
	__string_Aparser37[2]=(var) __strings_Aparser37;
	__string_Aparser38[2]=(var) __strings_Aparser38;
	__string_Aparser39[2]=(var) __strings_Aparser39;
	__string_Aparser40[2]=(var) __strings_Aparser40;
	__string_Aparser41[2]=(var) __strings_Aparser41;
	__string_Aparser42[2]=(var) __strings_Aparser42;
	__string_Aparser43[2]=(var) __strings_Aparser43;
	__string_Aparser44[2]=(var) __strings_Aparser44;
	__string_Aparser45[2]=(var) __strings_Aparser45;
	__string_Aparser46[2]=(var) __strings_Aparser46;
	__string_Aparser47[2]=(var) __strings_Aparser47;
	__string_Aparser48[2]=(var) __strings_Aparser48;
	__string_Aparser49[2]=(var) __strings_Aparser49;
	__string_Aparser50[2]=(var) __strings_Aparser50;
	__string_Aparser51[2]=(var) __strings_Aparser51;
	__string_Aparser52[2]=(var) __strings_Aparser52;
	__string_Aparser53[2]=(var) __strings_Aparser53;
	__string_Aparser54[2]=(var) __strings_Aparser54;
	__string_Aparser55[2]=(var) __strings_Aparser55;
	__string_Aparser56[2]=(var) __strings_Aparser56;
	__string_Aparser57[2]=(var) __strings_Aparser57;
	__string_Aparser58[2]=(var) __strings_Aparser58;
	__string_Aparser59[2]=(var) __strings_Aparser59;
	__string_Aparser60[2]=(var) __strings_Aparser60;
	__string_Aparser61[2]=(var) __strings_Aparser61;
	__string_Aparser62[2]=(var) __strings_Aparser62;
	__string_Aparser63[2]=(var) __strings_Aparser63;
	__string_Aparser64[2]=(var) __strings_Aparser64;
	__string_Aparser65[2]=(var) __strings_Aparser65;
	__string_Aparser66[2]=(var) __strings_Aparser66;
	__string_Aparser67[2]=(var) __strings_Aparser67;
	__string_Aparser68[2]=(var) __strings_Aparser68;
	__string_Aparser69[2]=(var) __strings_Aparser69;
	__string_Aparser70[2]=(var) __strings_Aparser70;
	__string_Aparser71[2]=(var) __strings_Aparser71;
	__string_Aparser72[2]=(var) __strings_Aparser72;
	__string_Aparser73[2]=(var) __strings_Aparser73;
	__string_Aparser74[2]=(var) __strings_Aparser74;
	__string_Aparser75[2]=(var) __strings_Aparser75;
	__string_Aparser76[2]=(var) __strings_Aparser76;
	__string_Aparser77[2]=(var) __strings_Aparser77;
	__string_Aparser78[2]=(var) __strings_Aparser78;
	__string_Aparser79[2]=(var) __strings_Aparser79;
	__string_Aparser80[2]=(var) __strings_Aparser80;
	__string_Aparser81[2]=(var) __strings_Aparser81;
	__string_Aparser82[2]=(var) __strings_Aparser82;
	__string_Aparser83[2]=(var) __strings_Aparser83;
	__string_Aparser84[2]=(var) __strings_Aparser84;
	__string_Aparser85[2]=(var) __strings_Aparser85;
	__string_Aparser86[2]=(var) __strings_Aparser86;
	__string_Aparser87[2]=(var) __strings_Aparser87;
	__string_Aparser88[2]=(var) __strings_Aparser88;
	__string_Aparser89[2]=(var) __strings_Aparser89;
	__string_Aparser90[2]=(var) __strings_Aparser90;
	__string_Aparser91[2]=(var) __strings_Aparser91;
	__string_Aparser92[2]=(var) __strings_Aparser92;
	__string_Aparser93[2]=(var) __strings_Aparser93;
	__string_Aparser94[2]=(var) __strings_Aparser94;
	__string_Aparser95[2]=(var) __strings_Aparser95;
	__string_Aparser96[2]=(var) __strings_Aparser96;
	__string_Aparser97[2]=(var) __strings_Aparser97;
	__string_Aparser98[2]=(var) __strings_Aparser98;
	__string_Aparser99[2]=(var) __strings_Aparser99;
	__string_Aparser100[2]=(var) __strings_Aparser100;
	__string_Aparser101[2]=(var) __strings_Aparser101;
	__string_Aparser102[2]=(var) __strings_Aparser102;
	__string_Aparser103[2]=(var) __strings_Aparser103;
	__string_Aparser104[2]=(var) __strings_Aparser104;
	__string_Aparser105[2]=(var) __strings_Aparser105;
	__string_Aparser106[2]=(var) __strings_Aparser106;
	__string_Aparser107[2]=(var) __strings_Aparser107;
	__string_Aparser108[2]=(var) __strings_Aparser108;
	__string_Aparser109[2]=(var) __strings_Aparser109;
	__string_Aparser110[2]=(var) __strings_Aparser110;
	__string_Aparser111[2]=(var) __strings_Aparser111;
	__string_Aparser112[2]=(var) __strings_Aparser112;
	__string_Aparser113[2]=(var) __strings_Aparser113;
	__string_Aparser114[2]=(var) __strings_Aparser114;
	__string_Aparser115[2]=(var) __strings_Aparser115;
	__string_Aparser116[2]=(var) __strings_Aparser116;
	__string_Aparser117[2]=(var) __strings_Aparser117;
	__string_Aparser118[2]=(var) __strings_Aparser118;
	__string_Aparser119[2]=(var) __strings_Aparser119;
	__string_Aparser120[2]=(var) __strings_Aparser120;
	__string_Aparser121[2]=(var) __strings_Aparser121;
	__string_Aparser122[2]=(var) __strings_Aparser122;
	__string_Aparser123[2]=(var) __strings_Aparser123;
	__string_Aparser124[2]=(var) __strings_Aparser124;
	__string_Aparser125[2]=(var) __strings_Aparser125;
	__string_Aparser126[2]=(var) __strings_Aparser126;
	__string_Aparser127[2]=(var) __strings_Aparser127;
	__string_Aparser128[2]=(var) __strings_Aparser128;
	__string_Aparser129[2]=(var) __strings_Aparser129;
	__string_Aparser130[2]=(var) __strings_Aparser130;
	__string_Aparser131[2]=(var) __strings_Aparser131;
	__string_Aparser132[2]=(var) __strings_Aparser132;
	__string_Aparser133[2]=(var) __strings_Aparser133;
	__string_Aparser134[2]=(var) __strings_Aparser134;
	__string_Aparser135[2]=(var) __strings_Aparser135;
	__string_Aparser136[2]=(var) __strings_Aparser136;
	__string_Aparser137[2]=(var) __strings_Aparser137;
	__string_Aparser138[2]=(var) __strings_Aparser138;
	__string_Aparser139[2]=(var) __strings_Aparser139;
	__string_Aparser140[2]=(var) __strings_Aparser140;
	__string_mainChello[2]=(var) __strings_mainChello;
	__string_main141[2]=(var) __strings_main141;
	__string_main142[2]=(var) __strings_main142;
	__string_main143[2]=(var) __strings_main143;
	__string_main144[2]=(var) __strings_main144;
	__string_main145[2]=(var) __strings_main145;
	__string_main146[2]=(var) __strings_main146;
	__string_main147[2]=(var) __strings_main147;
	__string_main148[2]=(var) __strings_main148;
	__string_main149[2]=(var) __strings_main149;
	__string_main150[2]=(var) __strings_main150;
	__string_main151[2]=(var) __strings_main151;
	__string_main152[2]=(var) __strings_main152;
	__string_main153[2]=(var) __strings_main153;
	__string_main154[2]=(var) __strings_main154;
	__string_main155[2]=(var) __strings_main155;
	__string_Alexer156[2]=(var) __strings_Alexer156;
	__string_Alexer157[2]=(var) __strings_Alexer157;
	__string_Alexer158[2]=(var) __strings_Alexer158;
	__string_Alexer159[2]=(var) __strings_Alexer159;
	__string_Alexer160[2]=(var) __strings_Alexer160;
	__string_Alexer161[2]=(var) __strings_Alexer161;
	__string_string162[2]=(var) __strings_string162;
	__string_Aexpr163[2]=(var) __strings_Aexpr163;
	__string_Aexpr164[2]=(var) __strings_Aexpr164;
	__string_Aemmiter165[2]=(var) __strings_Aemmiter165;
	__string_Aemmiter166[2]=(var) __strings_Aemmiter166;
	__string_Aemmiter167[2]=(var) __strings_Aemmiter167;
	__string_Aemmiter168[2]=(var) __strings_Aemmiter168;
	__string_Aemmiter169[2]=(var) __strings_Aemmiter169;
	__string_Aemmiter170[2]=(var) __strings_Aemmiter170;
	__string_Aemmiter171[2]=(var) __strings_Aemmiter171;
	__string_Aemmiter172[2]=(var) __strings_Aemmiter172;
	__string_Aemmiter173[2]=(var) __strings_Aemmiter173;
	__string_Aemmiter174[2]=(var) __strings_Aemmiter174;
	__string_Aemmiter175[2]=(var) __strings_Aemmiter175;
	__string_Aemmiter176[2]=(var) __strings_Aemmiter176;
	__string_Aemmiter177[2]=(var) __strings_Aemmiter177;
	__string_Aemmiter178[2]=(var) __strings_Aemmiter178;
	__string_Aemmiter179[2]=(var) __strings_Aemmiter179;
	__string_Aemmiter180[2]=(var) __strings_Aemmiter180;
	__string_Aemmiter181[2]=(var) __strings_Aemmiter181;
	__string_Aemmiter182[2]=(var) __strings_Aemmiter182;
	__string_Aemmiter183[2]=(var) __strings_Aemmiter183;
	__string_Aemmiter184[2]=(var) __strings_Aemmiter184;
	__string_Aemmiter185[2]=(var) __strings_Aemmiter185;
	__string_Aemmiter186[2]=(var) __strings_Aemmiter186;
	__string_Aemmiter187[2]=(var) __strings_Aemmiter187;
	__string_Aemmiter188[2]=(var) __strings_Aemmiter188;
	__string_Aemmiter189[2]=(var) __strings_Aemmiter189;
	__string_Aemmiter190[2]=(var) __strings_Aemmiter190;
	__string_Aemmiter191[2]=(var) __strings_Aemmiter191;
	__string_Aemmiter192[2]=(var) __strings_Aemmiter192;
	__string_Aemmiter193[2]=(var) __strings_Aemmiter193;
	__string_Aemmiter194[2]=(var) __strings_Aemmiter194;
	__string_Aemmiter195[2]=(var) __strings_Aemmiter195;
	__string_Aemmiter196[2]=(var) __strings_Aemmiter196;
	__string_Aemmiter197[2]=(var) __strings_Aemmiter197;
	__string_Aemmiter198[2]=(var) __strings_Aemmiter198;
	__string_Aemmiter199[2]=(var) __strings_Aemmiter199;
	__string_Aemmiter200[2]=(var) __strings_Aemmiter200;
	__string_Aemmiter201[2]=(var) __strings_Aemmiter201;
	__string_Aemmiter202[2]=(var) __strings_Aemmiter202;
	__string_Aemmiter203[2]=(var) __strings_Aemmiter203;
	__string_Aemmiter204[2]=(var) __strings_Aemmiter204;
	__string_Aemmiter205[2]=(var) __strings_Aemmiter205;
	__string_Aemmiter206[2]=(var) __strings_Aemmiter206;
	__string_Aemmiter207[2]=(var) __strings_Aemmiter207;
	__string_Aemmiter208[2]=(var) __strings_Aemmiter208;
	__string_Aemmiter209[2]=(var) __strings_Aemmiter209;
	__string_Aemmiter210[2]=(var) __strings_Aemmiter210;
	__string_Aemmiter211[2]=(var) __strings_Aemmiter211;
	__string_Aemmiter212[2]=(var) __strings_Aemmiter212;
	__string_Aemmiter213[2]=(var) __strings_Aemmiter213;
	__string_Aemmiter214[2]=(var) __strings_Aemmiter214;
	__string_Aemmiter215[2]=(var) __strings_Aemmiter215;
	__string_Aemmiter216[2]=(var) __strings_Aemmiter216;
	__string_Aemmiter217[2]=(var) __strings_Aemmiter217;
	__string_Aemmiter218[2]=(var) __strings_Aemmiter218;
	__string_Aemmiter219[2]=(var) __strings_Aemmiter219;
	__string_Aemmiter220[2]=(var) __strings_Aemmiter220;
	__string_Aemmiter221[2]=(var) __strings_Aemmiter221;
	__string_Aemmiter222[2]=(var) __strings_Aemmiter222;
	__string_Aemmiter223[2]=(var) __strings_Aemmiter223;
	__string_Aemmiter224[2]=(var) __strings_Aemmiter224;
	__string_Aemmiter225[2]=(var) __strings_Aemmiter225;
	__string_Aemmiter226[2]=(var) __strings_Aemmiter226;
	__string_Aemmiter227[2]=(var) __strings_Aemmiter227;
	__string_Aemmiter228[2]=(var) __strings_Aemmiter228;
	__string_Aemmiter229[2]=(var) __strings_Aemmiter229;
	__string_Aemmiter230[2]=(var) __strings_Aemmiter230;
	__string_Aemmiter231[2]=(var) __strings_Aemmiter231;
	__string_Aemmiter232[2]=(var) __strings_Aemmiter232;
	__string_Aemmiter233[2]=(var) __strings_Aemmiter233;
	__string_Aemmiter234[2]=(var) __strings_Aemmiter234;
	__string_Aemmiter235[2]=(var) __strings_Aemmiter235;
	__string_Aemmiter236[2]=(var) __strings_Aemmiter236;
	__string_Aemmiter237[2]=(var) __strings_Aemmiter237;
	__string_Aemmiter238[2]=(var) __strings_Aemmiter238;
	__string_Aemmiter239[2]=(var) __strings_Aemmiter239;
	__string_Aemmiter240[2]=(var) __strings_Aemmiter240;
	__string_Aemmiter241[2]=(var) __strings_Aemmiter241;
	__string_Aemmiter242[2]=(var) __strings_Aemmiter242;
	__string_Aemmiter243[2]=(var) __strings_Aemmiter243;
	__string_Aemmiter244[2]=(var) __strings_Aemmiter244;
	__string_Aemmiter245[2]=(var) __strings_Aemmiter245;
	__string_Aemmiter246[2]=(var) __strings_Aemmiter246;
	__string_Aemmiter247[2]=(var) __strings_Aemmiter247;
	__string_Aemmiter248[2]=(var) __strings_Aemmiter248;
	__string_Aemmiter249[2]=(var) __strings_Aemmiter249;
	__string_Aemmiter250[2]=(var) __strings_Aemmiter250;
	__string_Aemmiter251[2]=(var) __strings_Aemmiter251;
	__string_Aemmiter252[2]=(var) __strings_Aemmiter252;
	__string_Aemmiter253[2]=(var) __strings_Aemmiter253;
	__string_Aemmiter254[2]=(var) __strings_Aemmiter254;
	__string_Aemmiter255[2]=(var) __strings_Aemmiter255;
	__string_Aemmiter256[2]=(var) __strings_Aemmiter256;
	__string_Aemmiter257[2]=(var) __strings_Aemmiter257;
	__string_Aemmiter258[2]=(var) __strings_Aemmiter258;
	__string_Aemmiter259[2]=(var) __strings_Aemmiter259;
	__string_Aemmiter260[2]=(var) __strings_Aemmiter260;
	__string_Aemmiter261[2]=(var) __strings_Aemmiter261;
	__string_Aemmiter262[2]=(var) __strings_Aemmiter262;
	__string_Aemmiter263[2]=(var) __strings_Aemmiter263;
	__string_Aemmiter264[2]=(var) __strings_Aemmiter264;
	__string_Aemmiter265[2]=(var) __strings_Aemmiter265;
	__string_Aemmiter266[2]=(var) __strings_Aemmiter266;
	__string_Aemmiter267[2]=(var) __strings_Aemmiter267;
	__string_Aemmiter268[2]=(var) __strings_Aemmiter268;
	__string_Aemmiter269[2]=(var) __strings_Aemmiter269;
	__string_Aemmiter270[2]=(var) __strings_Aemmiter270;
	__string_Aemmiter271[2]=(var) __strings_Aemmiter271;
	__string_Aemmiter272[2]=(var) __strings_Aemmiter272;
	__string_Aemmiter273[2]=(var) __strings_Aemmiter273;
	__string_Aemmiter274[2]=(var) __strings_Aemmiter274;
	__string_Aemmiter275[2]=(var) __strings_Aemmiter275;
	__string_Aemmiter276[2]=(var) __strings_Aemmiter276;
	__string_Aemmiter277[2]=(var) __strings_Aemmiter277;
	__string_Aemmiter278[2]=(var) __strings_Aemmiter278;
	__string_Aemmiter279[2]=(var) __strings_Aemmiter279;
	__string_Aemmiter280[2]=(var) __strings_Aemmiter280;
	__string_Aemmiter281[2]=(var) __strings_Aemmiter281;
	__string_Aemmiter282[2]=(var) __strings_Aemmiter282;
	__string_Aemmiter283[2]=(var) __strings_Aemmiter283;
	__string_Aemmiter284[2]=(var) __strings_Aemmiter284;
	__string_Aemmiter285[2]=(var) __strings_Aemmiter285;
	__string_Aemmiter286[2]=(var) __strings_Aemmiter286;
	__string_Aemmiter287[2]=(var) __strings_Aemmiter287;
	__string_Aemmiter288[2]=(var) __strings_Aemmiter288;
	__string_Aemmiter289[2]=(var) __strings_Aemmiter289;
	__string_Aemmiter290[2]=(var) __strings_Aemmiter290;
	__string_Aemmiter291[2]=(var) __strings_Aemmiter291;
	__string_Aemmiter292[2]=(var) __strings_Aemmiter292;
	__string_Aemmiter293[2]=(var) __strings_Aemmiter293;
	__string_Aemmiter294[2]=(var) __strings_Aemmiter294;
	__string_Aemmiter295[2]=(var) __strings_Aemmiter295;
	__string_Aemmiter296[2]=(var) __strings_Aemmiter296;
	__string_Aemmiter297[2]=(var) __strings_Aemmiter297;
	__string_Aemmiter298[2]=(var) __strings_Aemmiter298;
	__string_Aemmiter299[2]=(var) __strings_Aemmiter299;
	__string_Aemmiter300[2]=(var) __strings_Aemmiter300;
	__string_Aemmiter301[2]=(var) __strings_Aemmiter301;
	__string_Aemmiter302[2]=(var) __strings_Aemmiter302;
	__string_Aemmiter303[2]=(var) __strings_Aemmiter303;
	__string_Aemmiter304[2]=(var) __strings_Aemmiter304;
	__string_Aemmiter305[2]=(var) __strings_Aemmiter305;
	__string_Aemmiter306[2]=(var) __strings_Aemmiter306;
	__string_Aemmiter307[2]=(var) __strings_Aemmiter307;
	__string_Aemmiter308[2]=(var) __strings_Aemmiter308;
	__string_Aemmiter309[2]=(var) __strings_Aemmiter309;
	__string_Aemmiter310[2]=(var) __strings_Aemmiter310;
	__string_Aemmiter311[2]=(var) __strings_Aemmiter311;
	__string_Aemmiter312[2]=(var) __strings_Aemmiter312;
	__string_Aemmiter313[2]=(var) __strings_Aemmiter313;
	__string_Aemmiter314[2]=(var) __strings_Aemmiter314;
	__string_Aemmiter315[2]=(var) __strings_Aemmiter315;
	__string_Aemmiter316[2]=(var) __strings_Aemmiter316;
	__string_Aemmiter317[2]=(var) __strings_Aemmiter317;
	__string_Aemmiter318[2]=(var) __strings_Aemmiter318;
	__string_Aemmiter319[2]=(var) __strings_Aemmiter319;
	__string_Aemmiter320[2]=(var) __strings_Aemmiter320;
	__string_Aemmiter321[2]=(var) __strings_Aemmiter321;
	__string_Aemmiter322[2]=(var) __strings_Aemmiter322;
	__string_Aemmiter323[2]=(var) __strings_Aemmiter323;
	__string_Aemmiter324[2]=(var) __strings_Aemmiter324;
	__string_Aemmiter325[2]=(var) __strings_Aemmiter325;
	__string_Aemmiter326[2]=(var) __strings_Aemmiter326;
	__string_Aemmiter327[2]=(var) __strings_Aemmiter327;
	__string_Aemmiter328[2]=(var) __strings_Aemmiter328;
	__string_Aemmiter329[2]=(var) __strings_Aemmiter329;
	__string_Aemmiter330[2]=(var) __strings_Aemmiter330;
	__string_Aemmiter331[2]=(var) __strings_Aemmiter331;
	__string_Aemmiter332[2]=(var) __strings_Aemmiter332;
	__string_Aemmiter333[2]=(var) __strings_Aemmiter333;
}

#define GETSTR(s) ((char*) string__get_buf(s))
#define GETLEN(s) ((var)strlen((char*)string__get_buf(s)))
#define FREE(m) free(m)
#define MALLOC(s) malloc(s)

var std__alloc(var size)
{
	var *m;
	m = (var*)MALLOC(sizeof(var) * (size + 2));
	m[0] = 0; // reserved for memory managemnt (ref counting...)
	m[1] = 0; // overwritten in constructor by class ID
	return (var)(m + 2);
}

var std__free(var mem)
{
	FREE(((var*)mem) - 2);
	return 0;
}

var std__delete(var obj)
{
	if (((var*)obj)[-2] >= 1) {
		virtual__dispose(obj);	
	}
	return 0;
}

var std__panic()
{
	printf("PANIC!\n");
	exit(-1);
	return 0;
}

var bytes__new(var size)
{
	var s;
	var r;
	s = (size + sizeof(var) - 1) / sizeof(var);
	r = std__alloc(s + 1);
	((var*)r)[0] = size;
	return r;
}

var bytes__dispose(var bb)
{
	std__free(bb);
	return 0;
}

var bytes__get_buf(var bb)
{
	return (var)(((var*)bb) + 1);
}

var bytes__get_at(var bb, var at)
{
	char *b;
        b = (char*)(((var*)bb) + 1);
	return b[at];
}

var bytes__set_at(var bb, var at, var v)
{
	char *b;
        b = (char*)(((var*)bb) + 1);
	b[at] = v & 0xFF;
	return 0;
}

var bytes__set_size(var bb, var v)
{
	((var*)bb)[0] = v;
	return 0;
}


var bytes__get_size(var bb)
{
	return ((var*)bb)[0];
}


var std__stralloc(var obj, var len)
{
	char *b;
	b = MALLOC(len); // UTF-8
	b[0] = 0;
	string__set_buf(obj, (var)b);
	return (var)b;
}

var std__strfree(var b)
{
	FREE((void*)string__get_buf(b));
	return 0;
}

var std__strlen(var str)
{
#ifdef __SUBC__
	return (var)_strlen((char*)string__get_buf(str));
#else
	return (var)strlen((char*)string__get_buf(str));
#endif
}

// dest size must be maxlen+1
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
		buf[i] = sb[i]; // FIXME UTF-8
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
	data = string__new(l + 1);
	sb = GETSTR(data);
	i = 0;
	while (i <= l) {
		sb[i] = buf[i]; // FIXME UTF-8
		i++;
	}
	return data;
}
	
var std__mkfolder(var fs_cb)
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
	response__set_string(fs_cb, status, data);
	return 0;
}

static var std__concat(var folder, var name, char *buf, var size)
{
	var l;
	var fullpath;

	fullpath = string__new(1024);
	string__add(fullpath, folder);
	string__add(fullpath, name);
	l = std__string2native(fullpath, buf, size);
	if (l >= size) {
		string__dispose(fullpath);
		fullpath = 0;
	}
	return fullpath;
}


var std__mkdir(var folder, var name, var fs_cb)
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
			string__dispose(fullpath);
			data = std__native2string(strerror(errno));
			status = 403;
		}
	}
	response__set_string(fs_cb, status, data);
	return 0;
}

var std__read(var folder, var name, var seek, var size, var fs_cb)
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
				if ((st.st_mode & S_IFDIR) != 0) {
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
			data = bytes__new(size + 1);
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
				response__set_bytes(fs_cb, status, data);
				return 0;
			}
		} else {
			data = std__native2string("nothing to read.");
			status = 403;
		}
	}
	response__set_string(fs_cb, status, data);
	return 0;
}

var std__write(var folder, var name, var data, var seek, var size, var fs_cb)
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
			if ((st.st_mode & S_IFDIR) != 0) {
				string__dispose(fullpath);
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
			buf = (char*)bytes__get_buf(data);
			buf -= sizeof(var);
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
			bytes__set_size(data, r);
			if (r != size) {
				string__dispose(fullpath);
				outstr = std__native2string(
					"error writing file.");
				status = 403;
			} else {
				outstr = fullpath;
			}
		} else {
			string__dispose(fullpath);
			data = std__native2string("nothing to read.");
			status = 403;
		}
	}
	response__set_string(fs_cb, status, outstr);
	return 0;
}

var std__filesize(var folder, var name, var fs_cb)
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
			if ((st.st_mode & S_IFDIR) != 0) {
				string__dispose(fullpath);
				outstr = std__native2string(
					"path is a directory.");
				status = 403;
			} else {
				size = st.st_size;
				string__set_int(fullpath, size);
				outstr = fullpath;
			}
		} else {
			string__dispose(fullpath);
			outstr = std__native2string(strerror(errno));
			status = 403;
		}
	}
	response__set_string(fs_cb, status, outstr);
	return 0;
}

var std__scandir(var folder, var name, var fs_cb)
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
			string__dispose(fullpath);
			outstr = std__native2string(strerror(errno));
			status = 403;
		}		
	}
	if (status == 200) {
		string__dispose(fullpath);
		
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
				(s[1] == '.' && s[2] == '\0')))
			{

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
	response__set_string(fs_cb, status, outstr);
	return 0;
}

var std__rmdir(var folder, var name, var fs_cb)
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
			string__dispose(fullpath);
			outstr = std__native2string(strerror(errno));
			status = 403;
		} else {
			outstr = fullpath;
		}		
	}
	response__set_string(fs_cb, status, outstr);
	return 0;
}

var std__unlink(var folder, var name, var fs_cb)
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
			if ((st.st_mode & S_IFDIR) != 0) {
				string__dispose(fullpath);
				outstr = std__native2string(
					"path is a directory.");
				status = 403;
			} else {
				r = remove(fname);
				if (r == -1) {
					string__dispose(fullpath);
					outstr = std__native2string(
						strerror(errno));
					status = 403;
				} else {
					outstr = fullpath;
				}
			}
		} else {
			string__dispose(fullpath);
			outstr = std__native2string(strerror(errno));
			status = 403;
		}
	}
	response__set_string(fs_cb, status, outstr);
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
	printf("%s", GETSTR(str));
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


int main(int argc, char *argv[]) {
	int i;
	var s;
	std_argc = argc;
	std_args = array__new(argc+1);
	for (i = 0; i < argc; i++) {
		s = std__native2string(argv[i]);
		((var*)std_args)[i] = s;
	}
	((var*)std_args)[i] = 0;
	std__init_strings();
	main__main();
	// FIXME cleanup
	array__dispose(std_args);
	std_args = 0;
	return 0;
}

#undef GETSTR
#undef GETLEN
#undef FREE
#undef MALLOC 

// class std
// class console
var console__log(var str)
{

	std__echo(str);
	std__echo_nl();
	return 0;
}
var console__log_str(var str)
{

	std__echo(str);
	return 0;
}
var console__log_int(var n)
{

	std__echo_int(n);
	return 0;
}
// class Amember
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
};
var Amember__new(var kind_, var type_, var type_id_, var name_)
{
	struct Amember *_this;
	NEW(Amember);
	_this = (void*)__this;
	(void)_this;

	_this->kind=kind_;
	_this->type=type_;
	_this->type_id=type_id_;
	_this->name=name_;
	_this->initial_value=0;
	_this->index=-(1);
	_this->params=0;
	_this->vars=0;
	_this->body=0;
	return __this;
}
var Amember___V_dispose(var __this)
{
	struct Amember *_this;
	_this = (void*)__this;
	(void)_this;

	Amember__dispose_body(__this);
	std__free(__this);
	return 0;
}
var Amember__dispose_body(var __this)
{
	struct Amember *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->body!=0) {
		buffer__dispose(_this->body);
		_this->body=0;
	}
	if (_this->vars!=0) {
		buffer__dispose(_this->vars);
		_this->vars=0;
	}
	return 0;
}
var Amember__get_kind(var __this)
{
	struct Amember *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->kind;
}
var Amember__get_type(var __this)
{
	struct Amember *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->type;
}
var Amember__get_type_id(var __this)
{
	struct Amember *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->type_id;
}
var Amember__get_name(var __this)
{
	struct Amember *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->name;
}
var Amember__get_name_string(var __this)
{
	struct Amember *_this;
	_this = (void*)__this;
	(void)_this;

	return Atoken__get_data(_this->name);
}
var Amember__get_initial_value(var __this)
{
	struct Amember *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->initial_value;
}
var Amember__set_initial_value(var __this, var initial_value_)
{
	struct Amember *_this;
	_this = (void*)__this;
	(void)_this;

	_this->initial_value=initial_value_;
	return 0;
}
var Amember__set_index(var __this, var index_)
{
	struct Amember *_this;
	_this = (void*)__this;
	(void)_this;

	_this->index=index_;
	return 0;
}
var Amember__get_index(var __this)
{
	struct Amember *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->index;
}
var Amember__get_body(var __this)
{
	struct Amember *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->body;
}
var Amember__get_vars(var __this)
{
	struct Amember *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->vars;
}
var Amember__get_params(var __this)
{
	struct Amember *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->params;
}
var Amember__add_param(var __this, var kind_, var type_, var type_id_, var name_)
{
	var p;
	struct Amember *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->params==0) {
		_this->params=buffer__new(4);
	}
	p=Amember__new(kind_,type_,type_id_,name_);
	buffer__push(_this->params,p);
	return 0;
}
var Amember__add_var(var __this, var kind_, var type_, var type_id_, var name_)
{
	var p;
	struct Amember *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->vars==0) {
		_this->vars=buffer__new(4);
	}
	p=Amember__new(kind_,type_,type_id_,name_);
	buffer__push(_this->vars,p);
	return 0;
}
var Amember__add_statement(var __this, var statement_)
{
	struct Amember *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->body==0) {
		_this->body=buffer__new(4);
	}
	buffer__push(_this->body,statement_);
	return Astatement__get_parent(statement_);
}
// class Astatement
struct Astatement {
	var type;
	var expr;
	var statements;
	var else_stms;
	var parent;
	var depth;
};
var Astatement__new(var type_, var parent_, var depth_)
{
	struct Astatement *_this;
	NEW(Astatement);
	_this = (void*)__this;
	(void)_this;

	_this->type=type_;
	_this->parent=parent_;
	_this->depth=depth_;
	_this->expr=0;
	_this->statements=0;
	_this->else_stms=0;
	return __this;
}
var Astatement___V_dispose(var __this)
{
	struct Astatement *_this;
	_this = (void*)__this;
	(void)_this;

	std__free(__this);
	return 0;
}
var Astatement__get_type(var __this)
{
	struct Astatement *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->type;
}
var Astatement__get_depth(var __this)
{
	struct Astatement *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->depth;
}
var Astatement__get_parent(var __this)
{
	struct Astatement *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->parent;
}
var Astatement__get_statements(var __this)
{
	struct Astatement *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->statements;
}
var Astatement__get_else(var __this)
{
	struct Astatement *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->else_stms;
}
var Astatement__get_expression(var __this)
{
	struct Astatement *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->expr;
}
var Astatement__add_else(var __this, var type_)
{
	var st;
	struct Astatement *_this;
	_this = (void*)__this;
	(void)_this;

	_this->else_stms=buffer__new(2);
	st=Astatement__new(type_,_this->parent,_this->depth);
	Astatement__add_statement(__this, st);
	return 0;
}
var Astatement__add_statement(var __this, var statement_)
{
	struct Astatement *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->statements==0) {
		_this->statements=buffer__new(2);
	}
	if (_this->else_stms!=0) {
		buffer__push(_this->else_stms,statement_);
	} else {
		buffer__push(_this->statements,statement_);
	}
	return 0;
}
var Astatement__set_expression(var __this, var expr_)
{
	struct Astatement *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->type==(Aclass__Cif)) {
		_this->expr=expr_;
	} else if (_this->type==(Aclass__Celseif)) {
		_this->expr=expr_;
	} else if (_this->type==(Aclass__Clet)) {
		_this->expr=expr_;
	} else if (_this->type==(Aclass__Cdo)) {
		_this->expr=expr_;
	} else if (_this->type==(Aclass__Cwhile)) {
		_this->expr=expr_;
	} else if (_this->type==(Aclass__Creturn)) {
		_this->expr=expr_;
	} else {
		console__log((var)(__string_Astatement1+ 2));
		std__exit(-(1));
	}
	return 0;
}
// class Avirtual
struct Avirtual {
	var _class;
	var _memb;
	var next;
};
var Avirtual__new(var memb_, var class_)
{
	struct Avirtual *_this;
	NEW(Avirtual);
	_this = (void*)__this;
	(void)_this;

	_this->_class=class_;
	_this->_memb=memb_;
	_this->next=0;
	return __this;
}
var Avirtual___V_dispose(var __this)
{
	struct Avirtual *_this;
	_this = (void*)__this;
	(void)_this;

	std__free(__this);
	return 0;
}
var Avirtual__set_next(var __this, var n)
{
	struct Avirtual *_this;
	_this = (void*)__this;
	(void)_this;

	_this->next=n;
	return 0;
}
var Avirtual__get_next(var __this)
{
	struct Avirtual *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->next;
}
var Avirtual__get_class_name(var __this)
{
	struct Avirtual *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->_class;
}
var Avirtual__get_member(var __this)
{
	struct Avirtual *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->_memb;
}
var Avirtual__get_member_name(var __this)
{
	struct Avirtual *_this;
	_this = (void*)__this;
	(void)_this;

	return Amember__get_name_string(_this->_memb);
}
// class bytes
// class file
struct file {
	var _folder;
	var fs_cb;
};
var file__new(var folder, var fscb)
{
	struct file *_this;
	NEW(file);
	_this = (void*)__this;
	(void)_this;

	_this->_folder=string__to_string(folder);
	_this->fs_cb=fscb;
	return __this;
}
var file___V_dispose(var __this)
{
	struct file *_this;
	_this = (void*)__this;
	(void)_this;

	response__clear(_this->fs_cb);
	string__dispose(_this->_folder);
	std__free(__this);
	return 0;
}
var file__mkfolder(var __this)
{
	struct file *_this;
	_this = (void*)__this;
	(void)_this;

	response__clear(_this->fs_cb);
	std__mkfolder(_this->fs_cb);
	return 0;
}
var file__mkdir(var __this, var name)
{
	struct file *_this;
	_this = (void*)__this;
	(void)_this;

	response__clear(_this->fs_cb);
	std__mkdir(_this->_folder,name,_this->fs_cb);
	return 0;
}
var file__read(var __this, var name, var seek, var size_)
{
	struct file *_this;
	_this = (void*)__this;
	(void)_this;

	response__clear(_this->fs_cb);
	std__read(_this->_folder,name,seek,size_,_this->fs_cb);
	return 0;
}
var file__write(var __this, var name, var data, var seek, var size)
{
	struct file *_this;
	_this = (void*)__this;
	(void)_this;

	response__clear(_this->fs_cb);
	std__write(_this->_folder,name,data,seek,size,_this->fs_cb);
	return 0;
}
var file__filesize(var __this, var name)
{
	struct file *_this;
	_this = (void*)__this;
	(void)_this;

	response__clear(_this->fs_cb);
	std__filesize(_this->_folder,name,_this->fs_cb);
	return 0;
}
var file__scandir(var __this, var name)
{
	struct file *_this;
	_this = (void*)__this;
	(void)_this;

	response__clear(_this->fs_cb);
	std__scandir(_this->_folder,name,_this->fs_cb);
	return 0;
}
var file__rmdir(var __this, var name)
{
	struct file *_this;
	_this = (void*)__this;
	(void)_this;

	response__clear(_this->fs_cb);
	std__rmdir(_this->_folder,name,_this->fs_cb);
	return 0;
}
var file__unlink(var __this, var name)
{
	struct file *_this;
	_this = (void*)__this;
	(void)_this;

	response__clear(_this->fs_cb);
	std__unlink(_this->_folder,name,_this->fs_cb);
	return 0;
}
// class response
struct response {
	var status;
	var str;
	var byt;
};
var response__new()
{
	struct response *_this;
	NEW(response);
	_this = (void*)__this;
	(void)_this;

	_this->status=0;
	_this->byt=0;
	_this->str=0;
	return __this;
}
var response___V_dispose(var __this)
{
	struct response *_this;
	_this = (void*)__this;
	(void)_this;

	std__free(__this);
	return 0;
}
var response__clear(var __this)
{
	struct response *_this;
	_this = (void*)__this;
	(void)_this;

	_this->status=0;
	if (_this->byt!=0) {
		bytes__dispose(_this->byt);
		_this->byt=0;
	}
	if (_this->str!=0) {
		string__dispose(_this->str);
		_this->str=0;
	}
	return 0;
}
var response__set_string(var __this, var status_, var data_)
{
	struct response *_this;
	_this = (void*)__this;
	(void)_this;

	_this->status=status_;
	_this->str=data_;
	return 0;
}
var response__set_bytes(var __this, var status_, var data_)
{
	struct response *_this;
	_this = (void*)__this;
	(void)_this;

	_this->status=status_;
	_this->byt=data_;
	return 0;
}
var response__get_status(var __this)
{
	struct response *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->status;
}
var response__get_string(var __this)
{
	struct response *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->str;
}
var response__get_bytes(var __this)
{
	struct response *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->byt;
}
// class Aclass
struct Aclass {
	var tok;
	var next;
	var prep_kind;
	var prep_type;
	var prep_type_id;
	var prep_name;
	var implement;
	var members;
	var member;
	var field_index;
	var statement;
	var stm_stack;
	var expression;
	var cur_expr;
	var expr_id;
};
var Aclass__new(var token)
{
	struct Aclass *_this;
	NEW(Aclass);
	_this = (void*)__this;
	(void)_this;

	_this->tok=token;
	_this->next=0;
	_this->members=buffer__new(256);
	_this->implement=buffer__new(1);
	_this->field_index=-(1);
	_this->statement=0;
	_this->stm_stack=buffer__new(2);
	_this->expression=0;
	return __this;
}
var Aclass___V_dispose(var __this)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	buffer__dispose(_this->members);
	buffer__dispose(_this->implement);
	std__free(__this);
	return 0;
}
var Aclass__error(var __this, var err)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	console__log(err);
	std__exit(-(1));
	return 0;
}
var Aclass__get_implement(var __this)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->implement;
}
var Aclass__add_implement(var __this, var x)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	buffer__push(_this->implement,x);
	return 0;
}
var Aclass__get_members(var __this)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->members;
}
var Aclass__get_nb_fields(var __this)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->field_index+1;
}
var Aclass__set_next(var __this, var n)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	_this->next=n;
	return 0;
}
var Aclass__get_next(var __this)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->next;
}
var Aclass__get_name(var __this)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->tok;
}
var Aclass__pad(var __this, var p)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	while (p>0) {
		p=p-1;
		console__log_str((var)(__string_Aclass2+ 2));
	}
	return 0;
}
var Aclass__prepare_kind(var __this, var kind_)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	_this->prep_kind=kind_;
	_this->prep_type=0;
	_this->prep_type_id=0;
	_this->prep_name=0;
	return 0;
}
var Aclass__prepare_type(var __this, var type_)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	_this->prep_type=type_;
	return 0;
}
var Aclass__prepare_type_identifier(var __this, var id_)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	_this->prep_type=Aclass__Cidentifier;
	_this->prep_type_id=id_;
	return 0;
}
var Aclass__prepare_set_name(var __this, var id_)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	_this->prep_name=id_;
	return 0;
}
var Aclass__valid_member_name(var __this)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	_this->member=Amember__new(_this->prep_kind,_this->prep_type,_this->prep_type_id,_this->prep_name);
	if (_this->prep_kind==(Aclass__Cfield)) {
		_this->field_index=_this->field_index+1;
		Amember__set_index(_this->member,_this->field_index);
	} else if (_this->prep_kind==(Aclass__Cstatic)) {
	} else if (_this->prep_kind==(Aclass__Cconst)) {
	} else {
	}
	buffer__push(_this->members,_this->member);
	return 0;
}
var Aclass__valid_param(var __this)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	Amember__add_param(_this->member,_this->prep_kind,_this->prep_type,_this->prep_type_id,_this->prep_name);
	return 0;
}
var Aclass__valid_var(var __this)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	Amember__add_var(_this->member,_this->prep_kind,_this->prep_type,_this->prep_type_id,_this->prep_name);
	return 0;
}
var Aclass__begin_else(var __this, var type_)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	Astatement__add_else(_this->statement,type_);
	return 0;
}
var Aclass__begin_stm(var __this, var type_, var orig)
{
	var st;
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	buffer__push(_this->stm_stack,_this->statement);
	st=Astatement__new(type_,_this->statement,buffer__length(_this->stm_stack));
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
	return 0;
}
var Aclass__finish_stm(var __this)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	_this->statement=buffer__pop(_this->stm_stack);
	return 0;
}
var Aclass__finish_const(var __this, var initialiser_)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	Aclass__valid_member_name(__this);
	Amember__set_initial_value(_this->member,initialiser_);
	return 0;
}
var Aclass__finish_subroutine(var __this)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	while ((buffer__length(_this->stm_stack))>0) {
		buffer__pop(_this->stm_stack);
	}
	return 0;
}
var Aclass__begin_expr(var __this, var orig)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	_this->expression=Aexpr__new(Aclass__Croot,0,0);
	Aexpr__set_origin(_this->expression,orig);
	_this->cur_expr=_this->expression;
	return 0;
}
var Aclass__finish_expr(var __this)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->expression!=0) {
		Astatement__set_expression(_this->statement,_this->expression);
	}
	_this->expression=0;
	_this->cur_expr=0;
	return 0;
}
var Aclass__expr_op(var __this, var op_, var orig)
{
	var ex;
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	ex=0;
	if (op_==(Aclass__Croot)) {
	} else if (op_==(Aclass__Cassign)) {
		ex=Aexpr__new(op_,30,Aclass__Crl);
	} else if (op_==(Aclass__Cequal)) {
		ex=Aexpr__new(op_,100,Aclass__Clr);
	} else if (op_==(Aclass__Cnotequal)) {
		ex=Aexpr__new(op_,100,Aclass__Crl);
	} else if (op_==(Aclass__Clargerequal)) {
		ex=Aexpr__new(op_,110,Aclass__Clr);
	} else if (op_==(Aclass__Clesserequal)) {
		ex=Aexpr__new(op_,110,Aclass__Clr);
	} else if (op_==(Aclass__Clarger)) {
		ex=Aexpr__new(op_,110,Aclass__Clr);
	} else if (op_==(Aclass__Clesser)) {
		ex=Aexpr__new(op_,110,Aclass__Clr);
	} else if (op_==(Aclass__Clogicaland)) {
		ex=Aexpr__new(op_,60,Aclass__Clr);
	} else if (op_==(Aclass__Clogicalor)) {
		ex=Aexpr__new(op_,50,Aclass__Clr);
	} else if (op_==(Aclass__Cadd)) {
		ex=Aexpr__new(op_,130,Aclass__Clr);
	} else if (op_==(Aclass__Csub)) {
		ex=Aexpr__new(op_,130,Aclass__Clr);
	} else if (op_==(Aclass__Cmult)) {
		ex=Aexpr__new(op_,140,Aclass__Clr);
	} else if (op_==(Aclass__Cdiv)) {
		ex=Aexpr__new(op_,140,Aclass__Clr);
	} else if (op_==(Aclass__Cmodulo)) {
		ex=Aexpr__new(op_,140,Aclass__Clr);
	} else if (op_==(Aclass__Clogicalnot)) {
		ex=Aexpr__new(op_,160,Aclass__Crl);
	} else if (op_==(Aclass__Cunaryplus)) {
		ex=Aexpr__new(op_,160,Aclass__Crl);
	} else if (op_==(Aclass__Cunaryminus)) {
		ex=Aexpr__new(op_,160,Aclass__Crl);
	} else if (op_==(Aclass__Cdot)) {
		ex=Aexpr__new(op_,170,Aclass__Clr);
	} else if (op_==(Aclass__Cconstant)) {
		ex=Aexpr__new(op_,170,Aclass__Clr);
	} else if (op_==(Aclass__Ccall)) {
		ex=Aexpr__new(op_,170,Aclass__Clr);
	} else if (op_==(Aclass__Cindex)) {
		ex=Aexpr__new(op_,170,Aclass__Clr);
	} else if (op_==(Aclass__Ccomma)) {
		ex=Aexpr__new(op_,10,Aclass__Clr);
	} else {
		console__log((var)(__string_Aclass3+ 2));
		std__exit(-(1));
	}
	if (ex!=0) {
		Aexpr__set_origin(ex,orig);
		_this->cur_expr=Aexpr__add(_this->cur_expr,ex);
	}
	return 0;
}
var Aclass__expr_open_par(var __this)
{
	var ex;
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	ex=Aexpr__new(Aclass__Cparenthesis,1000,Aclass__Clr);
	_this->cur_expr=Aexpr__add(_this->cur_expr,ex);
	Aexpr__set_precedence(ex,1);
	return 0;
}
var Aclass__expr_in_par(var __this)
{
	var ex;
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	ex=Aexpr__close(_this->cur_expr,Aclass__Cparenthesis);
	if (ex==0) {
		return 0;
	}
	return 1;
}
var Aclass__expr_close_par(var __this)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	_this->cur_expr=Aexpr__close(_this->cur_expr,Aclass__Cparenthesis);
	if (_this->cur_expr==0) {
		Aclass__error(__this, (var)(__string_Aclass4+ 2));
	} else {
		Aexpr__set_precedence(_this->cur_expr,1000);
	}
	return 0;
}
var Aclass__expr_open_index(var __this, var id_, var orig)
{
	var ex;
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	Aclass__expr_var(__this, id_,orig);
	Aclass__expr_op(__this, Aclass__Cindex,orig);
	ex=Aexpr__new(Aclass__Cexpr,1000,Aclass__Clr);
	_this->cur_expr=Aexpr__add(_this->cur_expr,ex);
	Aexpr__set_precedence(ex,2);
	return 0;
}
var Aclass__expr_close_index(var __this)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	_this->cur_expr=Aexpr__close(_this->cur_expr,Aclass__Cindex);
	if (_this->cur_expr==0) {
		Aclass__error(__this, (var)(__string_Aclass5+ 2));
	} else {
		Aexpr__set_precedence(_this->cur_expr,1000);
	}
	return 0;
}
var Aclass__expr_begin_sub_call(var __this, var class_, var name_, var orig)
{
	var ex;
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	if (class_!=0) {
		Aclass__expr_var(__this, class_,orig);
		Aclass__expr_op(__this, Aclass__Cdot,orig);
		Aclass__expr_var(__this, name_,orig);
		Aclass__expr_op(__this, Aclass__Ccall,orig);
	} else {
		Aclass__expr_var(__this, name_,orig);
		Aclass__expr_op(__this, Aclass__Ccall,orig);
	}
	ex=Aexpr__new(Aclass__Cexpr,1000,Aclass__Clr);
	_this->cur_expr=Aexpr__add(_this->cur_expr,ex);
	Aexpr__set_precedence(ex,2);
	Aexpr__set_origin(ex,orig);
	return 0;
}
var Aclass__expr_next_expr(var __this, var orig)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	Aclass__expr_op(__this, Aclass__Ccomma,orig);
	return 0;
}
var Aclass__expr_finish_sub_call(var __this)
{
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	_this->cur_expr=Aexpr__close(_this->cur_expr,Aclass__Ccall);
	if (_this->cur_expr==0) {
		Aclass__error(__this, (var)(__string_Aclass6+ 2));
	} else {
		Aexpr__set_precedence(_this->cur_expr,1000);
	}
	return 0;
}
var Aclass__expr_term(var __this, var term_, var orig)
{
	var ex;
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	ex=Aexpr__new(term_,1000,Aclass__Clr);
	_this->cur_expr=Aexpr__add(_this->cur_expr,ex);
	Aexpr__set_origin(ex,orig);
	return 0;
}
var Aclass__expr_var(var __this, var name_, var orig)
{
	var ex;
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	ex=Aexpr__new(Aclass__Cvar,900,0);
	_this->cur_expr=Aexpr__add(_this->cur_expr,ex);
	Aexpr__set_value(ex,name_);
	Aexpr__set_origin(ex,orig);
	return 0;
}
var Aclass__expr_int_const(var __this, var value_, var orig)
{
	var ex;
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	ex=Aexpr__new(Aclass__Cint_const,900,0);
	_this->cur_expr=Aexpr__add(_this->cur_expr,ex);
	Aexpr__set_value(ex,value_);
	Aexpr__set_origin(ex,orig);
	return 0;
}
var Aclass__expr_char_const(var __this, var value_, var orig)
{
	var ex;
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	ex=Aexpr__new(Aclass__Cchar_const,900,0);
	_this->cur_expr=Aexpr__add(_this->cur_expr,ex);
	Aexpr__set_value(ex,value_);
	Aexpr__set_origin(ex,orig);
	return 0;
}
var Aclass__expr_str_const(var __this, var value_, var orig)
{
	var ex;
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	ex=Aexpr__new(Aclass__Cstr_const,900,0);
	_this->cur_expr=Aexpr__add(_this->cur_expr,ex);
	Aexpr__set_value(ex,value_);
	Aexpr__set_origin(ex,orig);
	return 0;
}
var Aclass__expr_constant(var __this, var class_name_, var const_name_, var orig)
{
	var ex;
	struct Aclass *_this;
	_this = (void*)__this;
	(void)_this;

	Aclass__expr_var(__this, class_name_,orig);
	Aclass__expr_op(__this, Aclass__Cconstant,orig);
	ex=Aexpr__new(Aclass__Cconst,900,0);
	Aexpr__set_origin(ex,orig);
	_this->cur_expr=Aexpr__add(_this->cur_expr,ex);
	Aexpr__set_value(ex,const_name_);
	return 0;
}
// class Aparser
struct Aparser {
	var _states;
	var lex;
	var lookahead;
	var lookstring;
	var status;
	var debug;
	var _class;
};
var Aparser__new()
{
	struct Aparser *_this;
	NEW(Aparser);
	_this = (void*)__this;
	(void)_this;

	_this->debug=0;
	_this->status=0;
	_this->lex=0;
	_this->_states=buffer__new(8);
	_this->_class=0;
	Aparser__push(__this, Aparser__Croot);
	return __this;
}
var Aparser___V_dispose(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	buffer__dispose(_this->_states);
	std__free(__this);
	return 0;
}
var Aparser__get_data(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->lookstring;
}
var Aparser__get_next(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->_class;
}
var Aparser__release(var __this)
{
	var c;
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	c=_this->_class;
	while (c!=0) {
		_this->_class=Aclass__get_next(c);
		Aclass__dispose(c);
		c=_this->_class;
	}
	_this->_class=0;
	return 0;
}
var Aparser__parse(var __this, var lexer_)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

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
			return 0;
		}
		if ((Atoken__get_type(_this->lookahead))==(Alexer__Cend)) {
			Aparser__eat(__this);
			return 0;
		}
	}
	return 0;
}
var Aparser__error(var __this, var e)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	console__log_str(Atoken__get_file(_this->lookahead));
	console__log_str((var)(__string_Aparser7+ 2));
	console__log_str(Atoken__get_data(_this->lookahead));
	console__log_str((var)(__string_Aparser8+ 2));
	console__log_int(Atoken__get_line(_this->lookahead));
	console__log_str((var)(__string_Aparser9+ 2));
	console__log(e);
	std__exit(-(1));
	_this->status=-(1);
	return 0;
}
var Aparser__push(var __this, var step_)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	buffer__push(_this->_states,step_);
	return 0;
}
var Aparser__pop(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	buffer__pop(_this->_states);
	return 0;
}
var Aparser__root(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->status!=0) {
		return -(1);
	}
	Aparser__push(__this, Aparser__Cclass_dec);
	return 0;
}
var Aparser__class_dec(var __this)
{
	var c;
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Aparser__match_id(__this, (var)(__string_Aparser10+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser11+ 2));
		return 0;
	}
	Aparser__eat(__this);
	if ((Aparser__match_id(__this, 0))==0) {
		Aparser__error(__this, (var)(__string_Aparser12+ 2));
		return 0;
	}
	c=_this->_class;
	_this->_class=Aclass__new(_this->lookahead);
	Aclass__set_next(_this->_class,c);
	Aparser__eat(__this);
	if ((Aparser__match_id(__this, (var)(__string_Aparser13+ 2)))!=0) {
		Aparser__eat(__this);
		if ((Aparser__match_id(__this, 0))==0) {
			Aparser__error(__this, (var)(__string_Aparser14+ 2));
			return 0;
		}
		Aclass__add_implement(_this->_class,_this->lookahead);
		Aparser__eat(__this);
		while ((Aparser__match_op(__this, (var)(__string_Aparser15+ 2)))!=0) {
			Aparser__eat(__this);
			if ((Aparser__match_id(__this, 0))==0) {
				Aparser__error(__this, (var)(__string_Aparser16+ 2));
				return 0;
			}
			Aclass__add_implement(_this->_class,_this->lookahead);
			Aparser__eat(__this);
		}
	}
	if ((Aparser__match_op(__this, (var)(__string_Aparser17+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser18+ 2));
		return 0;
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
	return 0;
}
var Aparser__class_dec1(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	_this->status=0;
	if ((Aparser__match_op(__this, (var)(__string_Aparser19+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser20+ 2));
		return 0;
	}
	Aparser__eat(__this);
	Aparser__pop(__this);
	return 0;
}
var Aparser__class_var_dec(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Aparser__match_id(__this, (var)(__string_Aparser21+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Cfield);
	} else if ((Aparser__match_id(__this, (var)(__string_Aparser22+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Cstatic);
	} else {
		_this->status=-(1);
		return 0;
	}
	Aparser__eat(__this);
	Aparser__type(__this);
	Aparser__var_name(__this);
	while ((Aparser__match_op(__this, (var)(__string_Aparser23+ 2)))!=0) {
		Aclass__valid_member_name(_this->_class);
		Aparser__var_name(__this);
	}
	if ((Aparser__match_op(__this, (var)(__string_Aparser24+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser25+ 2));
		return 0;
	}
	Aclass__valid_member_name(_this->_class);
	Aparser__eat(__this);
	return 0;
}
var Aparser__var_name(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Aparser__match_id(__this, 0))!=0) {
		Aclass__prepare_set_name(_this->_class,_this->lookahead);
		Aparser__eat(__this);
		return 0;
	}
	Aparser__error(__this, (var)(__string_Aparser26+ 2));
	return 0;
}
var Aparser__type(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Aparser__match_id(__this, (var)(__string_Aparser27+ 2)))!=0) {
		Aclass__prepare_type(_this->_class,Aclass__Cint);
	} else if ((Aparser__match_id(__this, (var)(__string_Aparser28+ 2)))!=0) {
		Aclass__prepare_type(_this->_class,Aclass__Cvoid);
	} else if ((Aparser__match_id(__this, 0))!=0) {
		Aclass__prepare_type_identifier(_this->_class,_this->lookahead);
	} else {
		Aparser__error(__this, (var)(__string_Aparser29+ 2));
		return 0;
	}
	Aparser__eat(__this);
	return 0;
}
var Aparser__clas_const_dec(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Aparser__match_id(__this, (var)(__string_Aparser30+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Cconst);
	} else {
		_this->status=-(1);
		return 0;
	}
	Aparser__eat(__this);
	Aparser__type(__this);
	Aparser__var_name(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser31+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser32+ 2));
		return 0;
	}
	Aparser__eat(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser33+ 2)))==0) {
		Aclass__finish_const(_this->_class,_this->lookahead);
	} else {
		Aparser__error(__this, (var)(__string_Aparser34+ 2));
		return 0;
	}
	Aparser__eat(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser35+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser36+ 2));
		return 0;
	}
	Aparser__eat(__this);
	return 0;
}
var Aparser__subroutine_dec(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->status!=0) {
		Aparser__pop(__this);
		return 0;
	}
	if ((Aparser__match_id(__this, (var)(__string_Aparser37+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Cconstructor);
	} else if ((Aparser__match_id(__this, (var)(__string_Aparser38+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Cfunction);
	} else if ((Aparser__match_id(__this, (var)(__string_Aparser39+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Cmethod);
	} else if ((Aparser__match_id(__this, (var)(__string_Aparser40+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Cvirtual);
	} else {
		Aparser__pop(__this);
		_this->status=-(1);
		return 0;
	}
	Aparser__eat(__this);
	if ((Aparser__match_id(__this, (var)(__string_Aparser41+ 2)))!=0) {
		Aclass__prepare_type(_this->_class,Aclass__Cvoid);
		Aparser__eat(__this);
	} else {
		Aparser__type(__this);
	}
	Aparser__var_name(__this);
	Aclass__valid_member_name(_this->_class);
	if ((Aparser__match_op(__this, (var)(__string_Aparser42+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser43+ 2));
		return 0;
	}
	Aparser__eat(__this);
	Aparser__param_list(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser44+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser45+ 2));
		return 0;
	}
	Aparser__eat(__this);
	Aparser__subrout_body(__this);
	return 0;
}
var Aparser__param_list(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Aparser__match_op(__this, (var)(__string_Aparser46+ 2)))!=0) {
		return 0;
	}
	Aparser__direction(__this);
	Aparser__type(__this);
	Aparser__var_name(__this);
	while ((Aparser__match_op(__this, (var)(__string_Aparser47+ 2)))!=0) {
		Aclass__valid_param(_this->_class);
		Aparser__eat(__this);
		Aparser__direction(__this);
		Aparser__type(__this);
		Aparser__var_name(__this);
	}
	Aclass__valid_param(_this->_class);
	return 0;
}
var Aparser__direction(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Aparser__match_id(__this, (var)(__string_Aparser48+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Cin);
		Aparser__eat(__this);
		return 0;
	} else if ((Aparser__match_id(__this, (var)(__string_Aparser49+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Cout);
		Aparser__eat(__this);
		return 0;
	} else if ((Aparser__match_id(__this, (var)(__string_Aparser50+ 2)))!=0) {
		Aclass__prepare_kind(_this->_class,Aclass__Cio);
		Aparser__eat(__this);
		return 0;
	}
	Aparser__error(__this, (var)(__string_Aparser51+ 2));
	return 0;
}
var Aparser__subrout_body(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Aparser__match_op(__this, (var)(__string_Aparser52+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser53+ 2));
		return 0;
	}
	Aparser__eat(__this);
	while (_this->status==0) {
		Aparser__var_dec(__this);
	}
	_this->status=0;
	Aparser__push(__this, Aparser__Csubrout_body1);
	Aparser__push(__this, Aparser__Cstatements);
	return 0;
}
var Aparser__subrout_body1(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser54+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser55+ 2));
		return 0;
	}
	Aparser__eat(__this);
	Aclass__finish_subroutine(_this->_class);
	return 0;
}
var Aparser__var_dec(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Aparser__match_id(__this, (var)(__string_Aparser56+ 2)))==0) {
		_this->status=1;
		return 0;
	}
	Aparser__eat(__this);
	Aclass__prepare_kind(_this->_class,Aclass__Cvar);
	Aparser__type(__this);
	Aparser__var_name(__this);
	while ((Aparser__match_op(__this, (var)(__string_Aparser57+ 2)))!=0) {
		Aclass__valid_var(_this->_class);
		Aparser__eat(__this);
		Aparser__var_name(__this);
	}
	Aclass__valid_var(_this->_class);
	if ((Aparser__match_op(__this, (var)(__string_Aparser58+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser59+ 2));
		return 0;
	}
	Aparser__eat(__this);
	return 0;
}
var Aparser__statements(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->status==0) {
		Aparser__push(__this, Aparser__Cstatement);
		return 0;
	}
	if (_this->status>0) {
		_this->status=0;
	}
	Aparser__pop(__this);
	return 0;
}
var Aparser__statement(var __this)
{
	var r;
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	Aparser__pop(__this);
	r=0;
	if ((Aparser__match_id(__this, (var)(__string_Aparser60+ 2)))!=0) {
		r=1;
		Aclass__begin_stm(_this->_class,Aclass__Cbreak,_this->lookahead);
		Aparser__eat(__this);
		if ((Aparser__match_op(__this, (var)(__string_Aparser61+ 2)))==0) {
			Aparser__error(__this, (var)(__string_Aparser62+ 2));
			return 0;
		}
		Aclass__finish_stm(_this->_class);
		Aparser__eat(__this);
		return 0;
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
	return 0;
}
var Aparser__if_statem(var __this, var type_)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Aparser__match_id(__this, (var)(__string_Aparser63+ 2)))==0) {
		return 0;
	}
	Aclass__begin_stm(_this->_class,type_,_this->lookahead);
	Aparser__eat(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser64+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser65+ 2));
		return 1;
	}
	Aparser__eat(__this);
	Aparser__push(__this, Aparser__Cif_statem1);
	Aparser__push(__this, Aparser__Cexpression);
	Aclass__begin_expr(_this->_class,_this->lookahead);
	return 1;
}
var Aparser__if_statem1(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser66+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser67+ 2));
		return 0;
	}
	Aclass__finish_expr(_this->_class);
	Aparser__eat(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser68+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser69+ 2));
		return 0;
	}
	Aparser__eat(__this);
	Aparser__push(__this, Aparser__Celse_statem);
	Aparser__push(__this, Aparser__Cstatements);
	return 0;
}
var Aparser__else_statem(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser70+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser71+ 2));
		return 0;
	}
	Aparser__eat(__this);
	if ((Aparser__match_id(__this, (var)(__string_Aparser72+ 2)))==0) {
		Aclass__finish_stm(_this->_class);
		return 0;
	}
	Aparser__eat(__this);
	if ((Aparser__match_id(__this, (var)(__string_Aparser73+ 2)))!=0) {
		Aclass__finish_stm(_this->_class);
		Aparser__if_statem(__this, Aclass__Celseif);
		return 0;
	}
	Aclass__begin_else(_this->_class,Aclass__Celse);
	if ((Aparser__match_op(__this, (var)(__string_Aparser74+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser75+ 2));
		return 0;
	}
	Aparser__eat(__this);
	Aparser__push(__this, Aparser__Celse_statem1);
	Aparser__push(__this, Aparser__Cstatements);
	return 0;
}
var Aparser__else_statem1(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser76+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser77+ 2));
		return 0;
	}
	Aclass__finish_stm(_this->_class);
	Aparser__eat(__this);
	return 0;
}
var Aparser__while_statem(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Aparser__match_id(__this, (var)(__string_Aparser78+ 2)))==0) {
		return 0;
	}
	Aclass__begin_stm(_this->_class,Aclass__Cwhile,_this->lookahead);
	Aparser__eat(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser79+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser80+ 2));
		return 1;
	}
	Aparser__eat(__this);
	Aclass__begin_expr(_this->_class,_this->lookahead);
	Aparser__push(__this, Aparser__Cwhile_statem1);
	Aparser__push(__this, Aparser__Cexpression);
	return 1;
}
var Aparser__while_statem1(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser81+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser82+ 2));
		return 0;
	}
	Aclass__finish_expr(_this->_class);
	Aparser__eat(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser83+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser84+ 2));
		return 0;
	}
	Aparser__eat(__this);
	Aparser__push(__this, Aparser__Cwhile_statem2);
	Aparser__push(__this, Aparser__Cstatements);
	return 0;
}
var Aparser__while_statem2(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser85+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser86+ 2));
		return 0;
	}
	Aclass__finish_stm(_this->_class);
	Aparser__eat(__this);
	return 0;
}
var Aparser__return_statem(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Aparser__match_id(__this, (var)(__string_Aparser87+ 2)))==0) {
		return 0;
	}
	Aclass__begin_stm(_this->_class,Aclass__Creturn,_this->lookahead);
	Aparser__eat(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser88+ 2)))!=0) {
		Aclass__finish_stm(_this->_class);
		Aparser__eat(__this);
	} else {
		Aclass__begin_expr(_this->_class,_this->lookahead);
		Aparser__push(__this, Aparser__Creturn_statem1);
		Aparser__push(__this, Aparser__Cexpression);
	}
	return 1;
}
var Aparser__return_statem1(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Aparser__match_op(__this, (var)(__string_Aparser89+ 2)))!=0) {
		Aclass__finish_expr(_this->_class);
		Aclass__finish_stm(_this->_class);
		Aparser__eat(__this);
		Aparser__pop(__this);
		return 0;
	}
	Aparser__error(__this, (var)(__string_Aparser90+ 2));
	return 0;
}
var Aparser__dolet_statem(var __this)
{
	var id;
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Aparser__match_id(__this, 0))==0) {
		return 0;
	}
	id=_this->lookahead;
	Aparser__eat(__this);
	if ((((Aparser__match_op(__this, (var)(__string_Aparser91+ 2)))!=0))||(((Aparser__match_op(__this, (var)(__string_Aparser92+ 2)))!=0))) {
		Aclass__begin_stm(_this->_class,Aclass__Clet,_this->lookahead);
		return Aparser__let_statem(__this, id);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser93+ 2)))==0) {
		Aclass__begin_stm(_this->_class,Aclass__Cdo,_this->lookahead);
		return Aparser__do_statem(__this, id);
	}
	return 0;
}
var Aparser__let_statem(var __this, var id)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Aparser__match_op(__this, (var)(__string_Aparser94+ 2)))!=0) {
		Aclass__expr_var(_this->_class,Atoken__get_data(id),_this->lookahead);
		Aclass__expr_op(_this->_class,Aclass__Cassign,_this->lookahead);
		Aparser__eat(__this);
		Aparser__push(__this, Aparser__Clet_statem1);
		Aparser__push(__this, Aparser__Cexpression);
		return 1;
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser95+ 2)))!=0) {
		Aclass__expr_open_index(_this->_class,Atoken__get_data(id),_this->lookahead);
		Aparser__eat(__this);
		Aparser__push(__this, Aparser__Clet_statem2);
		Aparser__push(__this, Aparser__Cexpression);
		return 1;
	}
	return 0;
}
var Aparser__let_statem1(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser96+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser97+ 2));
		return 0;
	}
	Aclass__finish_expr(_this->_class);
	Aclass__finish_stm(_this->_class);
	Aparser__eat(__this);
	return 0;
}
var Aparser__let_statem2(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser98+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser99+ 2));
		return 0;
	}
	Aclass__expr_close_index(_this->_class);
	Aparser__eat(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser100+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Cassign,_this->lookahead);
		Aparser__eat(__this);
		Aparser__push(__this, Aparser__Clet_statem1);
		Aparser__push(__this, Aparser__Cexpression);
		return 0;
	}
	Aparser__error(__this, (var)(__string_Aparser101+ 2));
	return 0;
}
var Aparser__do_statem(var __this, var id)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	Aparser__push(__this, Aparser__Cdo_statem1);
	return Aparser__subrout_call(__this, id);
}
var Aparser__do_statem1(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser102+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser103+ 2));
		return 0;
	}
	Aclass__finish_expr(_this->_class);
	Aclass__finish_stm(_this->_class);
	Aparser__eat(__this);
	return 0;
}
var Aparser__expression(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	Aparser__pop(__this);
	Aparser__push(__this, Aparser__Cexpression1);
	Aparser__push(__this, Aparser__Cterm);
	return 0;
}
var Aparser__expression1(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Aparser__op(__this))!=0) {
		Aparser__push(__this, Aparser__Cterm);
		return 0;
	} else {
		Aparser__pop(__this);
	}
	return 0;
}
var Aparser__op(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Aparser__match_op(__this, (var)(__string_Aparser104+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Cadd,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser105+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Csub,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser106+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Cmult,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser107+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Cdiv,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser108+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Cmodulo,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser109+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Clogicaland,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser110+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Clogicalor,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser111+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Cequal,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser112+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Cnotequal,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser113+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Clargerequal,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser114+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Clesserequal,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser115+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Clarger,_this->lookahead);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser116+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Clesser,_this->lookahead);
	} else {
		return 0;
	}
	Aparser__eat(__this);
	return 1;
}
var Aparser__term(var __this)
{
	var id;
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	Aparser__pop(__this);
	if ((Aparser__match_id(__this, (var)(__string_Aparser117+ 2)))!=0) {
		Aclass__expr_term(_this->_class,Aclass__Cthis,_this->lookahead);
		Aparser__eat(__this);
	} else if ((Aparser__match_id(__this, (var)(__string_Aparser118+ 2)))!=0) {
		Aclass__expr_term(_this->_class,Aclass__Cnull,_this->lookahead);
		Aparser__eat(__this);
	} else if ((Atoken__get_type(_this->lookahead))==(Alexer__Cidentifier)) {
		id=_this->lookahead;
		Aparser__eat(__this);
		if ((Aparser__match_op(__this, (var)(__string_Aparser119+ 2)))!=0) {
			Aclass__expr_open_index(_this->_class,Atoken__get_data(id),_this->lookahead);
			Aparser__eat(__this);
			Aparser__push(__this, Aparser__Cterm2);
			Aparser__push(__this, Aparser__Cexpression);
		} else if ((Aparser__subrout_call(__this, id))!=0) {
		} else if ((Aparser__match_op(__this, (var)(__string_Aparser120+ 2)))!=0) {
			Aparser__eat(__this);
			if ((Atoken__get_type(_this->lookahead))!=(Alexer__Cidentifier)) {
				Aparser__error(__this, (var)(__string_Aparser121+ 2));
				return 0;
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
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser122+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Cunaryminus,_this->lookahead);
		Aparser__eat(__this);
		Aparser__push(__this, Aparser__Cterm);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser123+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Cunaryplus,_this->lookahead);
		Aparser__eat(__this);
		Aparser__push(__this, Aparser__Cterm);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser124+ 2)))!=0) {
		Aclass__expr_op(_this->_class,Aclass__Clogicalnot,_this->lookahead);
		Aparser__eat(__this);
		Aparser__push(__this, Aparser__Cterm);
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser125+ 2)))!=0) {
		Aclass__expr_open_par(_this->_class);
		Aparser__eat(__this);
		Aparser__push(__this, Aparser__Cterm1);
		Aparser__push(__this, Aparser__Cexpression);
	} else {
		Aparser__error(__this, (var)(__string_Aparser126+ 2));
		return 0;
	}
	return 0;
}
var Aparser__subrout_call(var __this, var id)
{
	var id2;
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Aparser__match_op(__this, (var)(__string_Aparser127+ 2)))!=0) {
		Aparser__sub_call(__this, 0,id);
		return 1;
	} else if ((Aparser__match_op(__this, (var)(__string_Aparser128+ 2)))!=0) {
		id2=id;
		Aparser__eat(__this);
		id=_this->lookahead;
		Aparser__eat(__this);
		Aparser__sub_call(__this, id2,id);
		return 1;
	}
	return 0;
}
var Aparser__term1(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser129+ 2)))!=0) {
		Aclass__expr_close_par(_this->_class);
		Aparser__eat(__this);
		return 0;
	}
	Aparser__error(__this, (var)(__string_Aparser130+ 2));
	return 0;
}
var Aparser__term2(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser131+ 2)))!=0) {
		Aclass__expr_close_index(_this->_class);
		Aparser__eat(__this);
		return 0;
	}
	Aparser__error(__this, (var)(__string_Aparser132+ 2));
	return 0;
}
var Aparser__sub_call(var __this, var class_, var id)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Aparser__match_op(__this, (var)(__string_Aparser133+ 2)))==0) {
		Aparser__error(__this, (var)(__string_Aparser134+ 2));
		return 0;
	}
	Aparser__eat(__this);
	if (class_!=0) {
		Aclass__expr_begin_sub_call(_this->_class,Atoken__get_data(class_),Atoken__get_data(id),_this->lookahead);
	} else {
		Aclass__expr_begin_sub_call(_this->_class,0,Atoken__get_data(id),_this->lookahead);
	}
	Aparser__push(__this, Aparser__Csub_call1);
	if ((Aparser__match_op(__this, (var)(__string_Aparser135+ 2)))==0) {
		Aparser__push(__this, Aparser__Cexpr_list);
		Aparser__push(__this, Aparser__Cexpression);
		return 0;
	}
	Aclass__expr_finish_sub_call(_this->_class);
	return 0;
}
var Aparser__sub_call1(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	Aparser__pop(__this);
	if ((Aparser__match_op(__this, (var)(__string_Aparser136+ 2)))!=0) {
		Aclass__expr_finish_sub_call(_this->_class);
		Aparser__eat(__this);
		return 0;
	}
	Aparser__error(__this, (var)(__string_Aparser137+ 2));
	return 0;
}
var Aparser__expr_list(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	Aparser__pop(__this);
	if (_this->status!=0) {
		_this->status=0;
		return 0;
	}
	if ((Aparser__match_op(__this, (var)(__string_Aparser138+ 2)))!=0) {
		Aparser__eat(__this);
		Aclass__expr_next_expr(_this->_class,_this->lookahead);
		Aparser__push(__this, Aparser__Cexpr_list1);
		Aparser__push(__this, Aparser__Cexpression);
	}
	return 0;
}
var Aparser__expr_list1(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	Aparser__pop(__this);
	if (_this->status!=0) {
		return 0;
	}
	if ((Aparser__match_op(__this, (var)(__string_Aparser139+ 2)))!=0) {
		Aclass__expr_next_expr(_this->_class,_this->lookahead);
		Aparser__eat(__this);
		Aparser__push(__this, Aparser__Cexpr_list1);
		Aparser__push(__this, Aparser__Cexpression);
	}
	return 0;
}
var Aparser__eat(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	Alexer__shift(_this->lex);
	if ((Alexer__empty(_this->lex))!=0) {
		_this->lookstring=0;
		_this->lookahead=0;
		return 0;
	}
	_this->lookahead=Alexer__get_at(_this->lex,0);
	if (_this->lookahead==0) {
		_this->lookstring=0;
		return 0;
	}
	while ((((Atoken__get_type(_this->lookahead))==(Alexer__Cnewline)))||(((Atoken__get_type(_this->lookahead))==(Alexer__Ccomment)))) {
		Alexer__shift(_this->lex);
		if ((Alexer__empty(_this->lex))!=0) {
			_this->lookstring=0;
			_this->lookahead=0;
			return 0;
		}
		_this->lookahead=Alexer__get_at(_this->lex,0);
	}
	_this->lookstring=Atoken__get_data(_this->lookahead);
	return 0;
}
var Aparser__match_id(var __this, var id)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Atoken__get_type(_this->lookahead))!=(Alexer__Cidentifier)) {
		return 0;
	}
	if (id==0) {
		return 1;
	}
	if ((string__compare(_this->lookstring,id))==0) {
		return 1;
	}
	return 0;
}
var Aparser__match_op(var __this, var id)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Atoken__get_type(_this->lookahead))!=(Alexer__Coperator)) {
		return 0;
	}
	if ((string__compare(_this->lookstring,id))==0) {
		return 1;
	}
	return 0;
}
var Aparser__match_newline(var __this)
{
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Atoken__get_type(_this->lookahead))==(Alexer__Cnewline)) {
		return 1;
	}
	return 0;
}
var Aparser__match_str(var __this, var id)
{
	var t;
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	t=Atoken__get_type(_this->lookahead);
	if (((t!=(Alexer__Cstring)))&&((t!=(Alexer__Cquote)))) {
		return 0;
	}
	if (((id==0))||(((string__compare(_this->lookstring,id))==0))) {
		return 1;
	}
	return 0;
}
var Aparser__state_machine(var __this)
{
	var state;
	struct Aparser *_this;
	_this = (void*)__this;
	(void)_this;

	state=buffer__get_last(_this->_states);
	if (_this->debug>0) {
		console__log(_this->lookstring);
		console__log_int(state);
	}
	if (state==(Aparser__Croot)) {
		Aparser__root(__this);
	} else if (state==(Aparser__Cclass_dec)) {
		Aparser__class_dec(__this);
	} else if (state==(Aparser__Cstatement)) {
		Aparser__statement(__this);
	} else if (state==(Aparser__Cstatements)) {
		Aparser__statements(__this);
	} else if (state==(Aparser__Cexpression)) {
		Aparser__expression(__this);
	} else if (state==(Aparser__Cexpression1)) {
		Aparser__expression1(__this);
	} else if (state==(Aparser__Cterm)) {
		Aparser__term(__this);
	} else if (state==(Aparser__Cterm1)) {
		Aparser__term1(__this);
	} else if (state==(Aparser__Cterm2)) {
		Aparser__term2(__this);
	} else if (state==(Aparser__Creturn_statem1)) {
		Aparser__return_statem1(__this);
	} else if (state==(Aparser__Cexpr_list)) {
		Aparser__expr_list(__this);
	} else if (state==(Aparser__Cexpr_list1)) {
		Aparser__expr_list1(__this);
	} else if (state==(Aparser__Csub_call1)) {
		Aparser__sub_call1(__this);
	} else if (state==(Aparser__Clet_statem1)) {
		Aparser__let_statem1(__this);
	} else if (state==(Aparser__Clet_statem2)) {
		Aparser__let_statem2(__this);
	} else if (state==(Aparser__Cdo_statem1)) {
		Aparser__do_statem1(__this);
	} else if (state==(Aparser__Cwhile_statem1)) {
		Aparser__while_statem1(__this);
	} else if (state==(Aparser__Cwhile_statem2)) {
		Aparser__while_statem2(__this);
	} else if (state==(Aparser__Csubrout_body1)) {
		Aparser__subrout_body1(__this);
	} else if (state==(Aparser__Csubroutine_dec)) {
		Aparser__subroutine_dec(__this);
	} else if (state==(Aparser__Cclass_dec1)) {
		Aparser__class_dec1(__this);
	} else if (state==(Aparser__Cif_statem1)) {
		Aparser__if_statem1(__this);
	} else if (state==(Aparser__Celse_statem)) {
		Aparser__else_statem(__this);
	} else if (state==(Aparser__Celse_statem1)) {
		Aparser__else_statem1(__this);
	} else {
		Aparser__error(__this, (var)(__string_Aparser140+ 2));
		Alexer__shift(_this->lex);
		_this->status=-(1);
	}
	return 1;
}
// class main
var main__copyto(var f, var output)
{
	var fd;
	var res;
	var data;
	var n;
	var i;
	var off;

	console__log_str((var)(__string_main141+ 2));
	console__log(f);
	res=response__new();
	fd=file__new((var)(__string_main142+ 2),res);
	file__read(fd,f,0,main__Cblock);
	off=0;
	while ((response__get_status(res))==200) {
		data=response__get_bytes(res);
		n=bytes__get_size(data);
		i=0;
		while (i<n) {
			string__add_char(output,bytes__get_at(data,i));
			i=i+1;
		}
		off=off+(main__Cblock);
		file__read(fd,f,off,main__Cblock);
	}
	file__dispose(fd);
	response__dispose(res);
	return 0;
}
var main__process_file(var f, var lex)
{
	var tmp;
	var fd;
	var res;
	var data;
	var n;
	var i;
	var off;

	console__log_str((var)(__string_main143+ 2));
	console__log(f);
	Alexer__begin(lex,f);
	res=response__new();
	fd=file__new((var)(__string_main144+ 2),res);
	file__read(fd,f,0,main__Cblock);
	off=0;
	tmp=string__new(10000);
	while ((response__get_status(res))==200) {
		data=response__get_bytes(res);
		n=bytes__get_size(data);
		i=0;
		while (i<n) {
			string__add_char(tmp,bytes__get_at(data,i));
			i=i+1;
		}
		Alexer__add(lex,tmp);
		string__set(tmp,(var)(__string_main145+ 2));
		off=off+(main__Cblock);
		file__read(fd,f,off,main__Cblock);
	}
	file__dispose(fd);
	response__dispose(res);
	Alexer__finish(lex);
	return 0;
}
var main__main()
{
	var str;
	var tmp;
	var args;
	var fd;
	var res;
	var data;
	var n;
	var i;
	var end;
	var start;
	var len;
	var lex;
	var par;
	var emi;
	var head;
	var body;
	var to;
	var l;

	console__log(main__Chello);
	args=std__get_args();
	n=std__get_argc();
	if (n!=2) {
		console__log((var)(__string_main146+ 2));
		std__exit(-(1));
	}
	head=string__new(2048);
	body=string__new(2048);
	str=((var*)args)[1];
	to=string__new(20);
	string__add(to,str);
	string__add(to,(var)(__string_main147+ 2));
	res=response__new();
	fd=file__new((var)(__string_main148+ 2),res);
	file__scandir(fd,str);
	tmp=string__new(100);
	lex=Alexer__new();
	par=Aparser__new();
	emi=Aemmiter__new();
	if ((response__get_status(res))==200) {
		data=response__get_string(res);
		len=string__length(data);
		i=0;
		start=0;
		i=string__indexof(data,start,(var)(__string_main149+ 2));
		while (((i>=0))&&((start<len))) {
			string__substr(data,start,i-start,tmp);
			end=i-start;
			if ((string__indexof(tmp,0,(var)(__string_main150+ 2)))==((end-5))) {
				main__process_file(tmp,lex);
				Aparser__parse(par,lex);
				Aemmiter__emmit(emi,par);
				Aparser__release(par);
			} else if ((string__indexof(tmp,0,(var)(__string_main151+ 2)))==((end-2))) {
				main__copyto(tmp,head);
			} else if ((string__indexof(tmp,0,(var)(__string_main152+ 2)))==((end-2))) {
				main__copyto(tmp,body);
			}
			start=i+1;
			i=string__indexof(data,start,(var)(__string_main153+ 2));
			string__set(tmp,(var)(__string_main154+ 2));
		}
	}
	Aemmiter__gen_virtuals(emi);
	file__unlink(fd,to);
	i=0;
	str=head;
	l=string__length(str);
	if (l>0) {
		file__write(fd,to,string__get_buf(str),i,l);
		if ((response__get_status(res))!=200) {
			std__exit(-(1));
		}
	}
	i=i+l;
	str=Aemmiter__get_head(emi);
	l=string__length(str);
	if (l>0) {
		file__write(fd,to,string__get_buf(str),i,l);
	}
	i=i+l;
	str=Aemmiter__get_mid(emi);
	l=string__length(str);
	if (l>0) {
		file__write(fd,to,string__get_buf(str),i,l);
	}
	i=i+l;
	str=body;
	l=string__length(str);
	if (l>0) {
		file__write(fd,to,string__get_buf(str),i,l);
	}
	i=i+l;
	str=Aemmiter__get_data(emi);
	l=string__length(str);
	if (l>0) {
		file__write(fd,to,string__get_buf(str),i,l);
	}
	console__log_str((var)(__string_main155+ 2));
	console__log(to);
	string__dispose(to);
	file__dispose(fd);
	response__dispose(res);
	Alexer__dispose(lex);
	Aparser__dispose(par);
	Aemmiter__dispose(emi);
	return 0;
}
// class Atoken
struct Atoken {
	var type;
	var _data;
	var line;
	var file_;
	var next;
};
var Atoken__new(var type1, var _data1, var line1, var file1)
{
	struct Atoken *_this;
	NEW(Atoken);
	_this = (void*)__this;
	(void)_this;

	_this->type=type1;
	_this->_data=_data1;
	_this->line=line1;
	_this->file_=file1;
	_this->next=0;
	return __this;
}
var Atoken___V_dispose(var __this)
{
	struct Atoken *_this;
	_this = (void*)__this;
	(void)_this;

	string__dispose(_this->_data);
	std__free(__this);
	return 0;
}
var Atoken__get_data(var __this)
{
	struct Atoken *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->_data;
}
var Atoken__get_type(var __this)
{
	struct Atoken *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->type;
}
var Atoken__get_line(var __this)
{
	struct Atoken *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->line;
}
var Atoken__get_file(var __this)
{
	struct Atoken *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->file_;
}
// class Alexer
struct Alexer {
	var _src;
	var _str;
	var _pool;
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
var Alexer__new()
{
	struct Alexer *_this;
	NEW(Alexer);
	_this = (void*)__this;
	(void)_this;

	_this->_str=string__new(1024);
	_this->_token=string__new(256);
	_this->_pool=buffer__new(32);
	_this->_stringh=hash__new(4096);
	_this->_syms=buffer__new(2048);
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
	return __this;
}
var Alexer___V_dispose(var __this)
{
	struct Alexer *_this;
	_this = (void*)__this;
	(void)_this;

	buffer__dispose(_this->_pool);
	string__dispose(_this->_token);
	string__dispose(_this->_str);
	buffer__dispose(_this->_syms);
	hash__dispose(_this->_stringh);
	std__free(__this);
	return 0;
}
var Alexer__begin(var __this, var file_)
{
	struct Alexer *_this;
	_this = (void*)__this;
	(void)_this;

	_this->pos=0;
	_this->line=1;
	_this->_src=Alexer__get_string(__this, file_);
	return 0;
}
var Alexer__get_at(var __this, var x)
{
	struct Alexer *_this;
	_this = (void*)__this;
	(void)_this;

	return buffer__get_at(_this->_pool,x);
}
var Alexer__shift(var __this)
{
	struct Alexer *_this;
	_this = (void*)__this;
	(void)_this;

	buffer__shift(_this->_pool);
	return 0;
}
var Alexer__empty(var __this)
{
	struct Alexer *_this;
	_this = (void*)__this;
	(void)_this;

	return buffer__empty(_this->_pool);
}
var Alexer__set_enable_escape(var __this, var v)
{
	struct Alexer *_this;
	_this = (void*)__this;
	(void)_this;

	_this->enable_escape=v;
	return 0;
}
var Alexer__get_string(var __this, var str_)
{
	var s;
	var i;
	struct Alexer *_this;
	_this = (void*)__this;
	(void)_this;

	i=hash__get(_this->_stringh,str_);
	if (i>0) {
		return buffer__get_at(_this->_syms,i);
	}
	s=string__new((string__length(str_))+2);
	string__add(s,str_);
	hash__add(_this->_stringh,s,buffer__length(_this->_syms));
	buffer__push(_this->_syms,s);
	return s;
}
var Alexer__get_string_id(var __this, var str_)
{
	struct Alexer *_this;
	_this = (void*)__this;
	(void)_this;

	return hash__get(_this->_stringh,str_);
}
var Alexer__add(var __this, var str_)
{
	var ns;
	struct Alexer *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->len<0) {
		return 0;
	}
	if ((string__length(str_))<1) {
		Alexer__finish(__this);
		return 0;
	}
	if (_this->pos<(string__length(_this->_str))) {
		ns=string__new(32);
		string__substr(_this->_str,_this->pos,0,ns);
		string__add(ns,str_);
		string__dispose(_this->_str);
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
	return 0;
}
var Alexer__tokenize(var __this)
{
	var s;
	struct Alexer *_this;
	_this = (void*)__this;
	(void)_this;

	s=Alexer__state(__this);
	while ((s!=0)) {
		if (_this->need_char!=0) {
			return 0;
		}
		s=Alexer__state(__this);
	}
	return 0;
}
var Alexer__is_digit(var __this, var c)
{
	struct Alexer *_this;
	_this = (void*)__this;
	(void)_this;

	if (((c>='0'))&&((c<='9'))) {
		return 1;
	}
	return 0;
}
var Alexer__is_letter(var __this, var c)
{
	struct Alexer *_this;
	_this = (void*)__this;
	(void)_this;

	if (((((c>='a'))&&((c<='z')))||((((c>='A'))&&((c<='Z')))))) {
		return 1;
	}
	return 0;
}
var Alexer__is_space(var __this, var c)
{
	struct Alexer *_this;
	_this = (void*)__this;
	(void)_this;

	if (((((c==' '))||((c=='\t')))||((c=='\n')))||((c=='\r'))) {
		return 1;
	}
	return 0;
}
var Alexer__next(var __this)
{
	struct Alexer *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->pos>=_this->len) {
		_this->need_char=1;
		_this->c='\0';
		return 0;
	}
	_this->need_char=0;
	_this->c=string__get_at(_this->_str,_this->pos);
	_this->pos=_this->pos+1;
	return 1;
}
var Alexer__validate(var __this, var type_)
{
	var t;
	struct Alexer *_this;
	_this = (void*)__this;
	(void)_this;

	if (type_==(Alexer__Cnewline)) {
		_this->line=_this->line+1;
	}
	t=Atoken__new(type_,Alexer__get_string(__this, _this->_token),_this->line,_this->_src);
	buffer__push(_this->_pool,t);
	string__set_at(_this->_token,0,'\0');
	return 0;
}
var Alexer__error(var __this, var msg)
{
	struct Alexer *_this;
	_this = (void*)__this;
	(void)_this;

	console__log_str((var)(__string_Alexer156+ 2));
	console__log_str(_this->_src);
	console__log_str((var)(__string_Alexer157+ 2));
	console__log_int(_this->line);
	console__log_str((var)(__string_Alexer158+ 2));
	console__log_str(_this->_token);
	console__log_str((var)(__string_Alexer159+ 2));
	console__log(msg);
	_this->len=-(1);
	return 0;
}
var Alexer__state(var __this)
{
	var l;
	var a;
	var b;
	var d;
	struct Alexer *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->in_escape!=0) {
		if (_this->enable_escape==0) {
			if (_this->c!='\n') {
				string__add_char(_this->_token,'\\');
				string__add_char(_this->_token,_this->c);
				Alexer__next(__this);
				_this->in_escape=0;
				return 1;
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
		return 1;
	} else if (_this->in_string!=0) {
		if (_this->c=='"') {
			_this->in_string=0;
			Alexer__validate(__this, Alexer__Cstring);
		} else if (_this->c=='\\') {
			_this->in_escape=1;
		} else if (_this->c=='\n') {
			Alexer__error(__this, (var)(__string_Alexer160+ 2));
			return 0;
		} else {
			string__add_char(_this->_token,_this->c);
		}
		Alexer__next(__this);
		return 1;
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
		return 1;
	} else if (_this->in_comment!=0) {
		if (_this->in_comment==(-(1))) {
			if (_this->c=='/') {
				_this->in_comment=1;
				Alexer__next(__this);
				return 1;
			} else if (_this->c=='*') {
				_this->in_comment=0;
				_this->in_com_multi=1;
				Alexer__next(__this);
				return 1;
			}
			_this->in_comment=0;
			string__add_char(_this->_token,'/');
			return 1;
		} else if (_this->in_comment==1) {
			if (_this->c=='#') {
				_this->in_asm=1;
				_this->in_comment=0;
				Alexer__next(__this);
				return 1;
			}
			_this->in_comment=2;
		}
		if (_this->c=='\n') {
			_this->in_comment=0;
			Alexer__validate(__this, Alexer__Ccomment);
			Alexer__validate(__this, Alexer__Cnewline);
		}
		if (_this->c=='\0') {
			return 0;
		}
		Alexer__next(__this);
		return 1;
	} else if (_this->in_com_multi!=0) {
		if (_this->in_com_multi==1) {
			if (_this->c=='#') {
				_this->in_asm_multi=2;
				_this->in_com_multi=0;
				Alexer__next(__this);
				return 1;
			}
			_this->in_com_multi=2;
		} else if (_this->in_com_multi==2) {
			if (_this->c=='*') {
				_this->in_com_multi=3;
				Alexer__next(__this);
				return 1;
			}
		} else if (_this->in_com_multi==3) {
			if (_this->c=='/') {
				_this->in_com_multi=0;
				Alexer__validate(__this, Alexer__Ccomment);
				Alexer__next(__this);
				return 1;
			}
			_this->in_com_multi=2;
		}
		Alexer__next(__this);
		return 1;
	} else if (_this->in_asm!=0) {
		if (_this->c=='\n') {
			Alexer__validate(__this, Alexer__Casm);
			Alexer__validate(__this, Alexer__Cnewline);
			_this->in_asm=0;
			Alexer__next(__this);
			return 1;
		}
		if (_this->c=='\0') {
			return 0;
		}
		string__add_char(_this->_token,_this->c);
		Alexer__next(__this);
		return 1;
	} else if (_this->in_asm_multi!=0) {
		if (_this->in_asm_multi==2) {
			if (_this->c=='*') {
				_this->in_asm_multi=3;
				Alexer__next(__this);
				return 1;
			}
		} else if (_this->in_asm_multi==3) {
			if (_this->c=='/') {
				_this->in_asm_multi=0;
				Alexer__validate(__this, Alexer__Casm);
				Alexer__next(__this);
				return 1;
			}
			_this->in_asm_multi=2;
		}
		string__add_char(_this->_token,_this->c);
		Alexer__next(__this);
		return 1;
	} else if (_this->in_number!=0) {
		if ((Alexer__is_digit(__this, _this->c))!=0) {
			string__add_char(_this->_token,_this->c);
			Alexer__next(__this);
		} else {
			_this->in_number=0;
			Alexer__validate(__this, Alexer__Cnumber);
		}
		return 1;
	} else if (_this->in_identifier!=0) {
		while ((((_this->c=='_'))||(((Alexer__is_letter(__this, _this->c))!=0)))||(((Alexer__is_digit(__this, _this->c))!=0))) {
			string__add_char(_this->_token,_this->c);
			if ((Alexer__next(__this))==0) {
				return 1;
			}
		}
		Alexer__validate(__this, Alexer__Cidentifier);
		_this->in_identifier=0;
		return 1;
	} else if (_this->in_space!=0) {
		while ((Alexer__is_space(__this, _this->c))!=0) {
			if (_this->c=='\n') {
				Alexer__validate(__this, Alexer__Cnewline);
			}
			if ((Alexer__next(__this))==0) {
				return 1;
			}
		}
		_this->in_space=0;
		return 1;
	} else {
		l=string__length(_this->_token);
		if ((Alexer__is_space(__this, _this->c))!=0) {
			if (l!=0) {
				Alexer__validate(__this, Alexer__Coperator);
			}
			_this->in_space=1;
			return 1;
		} else if (l==0) {
			if ((Alexer__is_digit(__this, _this->c))!=0) {
				string__add_char(_this->_token,_this->c);
				Alexer__next(__this);
				_this->in_number=1;
				return 1;
			} else if (((_this->c=='_'))||(((Alexer__is_letter(__this, _this->c))!=0))) {
				string__add_char(_this->_token,_this->c);
				Alexer__next(__this);
				_this->in_identifier=1;
				return 1;
			} else if (_this->c=='\'') {
				Alexer__next(__this);
				_this->in_quote=1;
				return 1;
			} else if (_this->c=='"') {
				Alexer__next(__this);
				_this->in_string=1;
				return 1;
			} else if ((_this->c=='/')) {
				Alexer__next(__this);
				_this->in_comment=-(1);
				return 1;
			}
			string__add_char(_this->_token,_this->c);
			Alexer__next(__this);
			return 1;
		} else if (l==1) {
			a=string__get_at(_this->_token,0);
			if (_this->c=='=') {
				if (((((((((((((a=='+'))||((a=='-')))||((a==':')))||((a=='*')))||((a=='/')))||((a=='%')))||((a=='&')))||((a=='^')))||((a=='|')))||((a=='>')))||((a=='<')))||((a=='~'))) {
					string__add_char(_this->_token,_this->c);
					Alexer__validate(__this, Alexer__Coperator);
					Alexer__next(__this);
					return 1;
				} else if (((a=='='))||((a=='!'))) {
					string__add_char(_this->_token,_this->c);
					Alexer__next(__this);
					return 1;
				}
			} else if (((((a=='+'))&&((_this->c=='+')))||(((((a=='-'))&&((_this->c=='>')))||(((((a==':'))&&((_this->c==':')))||(((((a=='|'))&&((_this->c=='|')))||(((((a=='&'))&&((_this->c=='&')))||(((((a=='.'))&&((_this->c=='$')))||((((a=='-'))&&((_this->c=='-')))))))))))))))) {
				string__add_char(_this->_token,_this->c);
				Alexer__validate(__this, Alexer__Coperator);
				Alexer__next(__this);
				return 1;
			} else if (((((a=='>'))&&((_this->c=='>')))||(((((a=='.'))&&((_this->c=='.')))||((((a=='<'))&&((_this->c=='<')))))))) {
				string__add_char(_this->_token,_this->c);
				Alexer__next(__this);
				return 1;
			}
			Alexer__validate(__this, Alexer__Coperator);
			return 1;
		} else if (l==2) {
			a=string__get_at(_this->_token,0);
			b=string__get_at(_this->_token,1);
			if ((((((a=='!'))&&((b=='=')))&&((_this->c=='=')))||((((((a=='='))&&((b=='=')))&&((_this->c=='=')))||((((((a=='>'))&&((b=='>')))&&((_this->c=='=')))||((((((a=='.'))&&((b=='.')))&&((_this->c=='.')))||(((((a=='<'))&&((b=='<')))&&((_this->c=='=')))))))))))) {
				string__add_char(_this->_token,_this->c);
				Alexer__validate(__this, Alexer__Coperator);
				Alexer__next(__this);
				return 1;
			} else if (((((a=='>'))&&((b=='>')))&&((_this->c=='>')))) {
				string__add_char(_this->_token,_this->c);
				Alexer__next(__this);
				return 1;
			}
			Alexer__validate(__this, Alexer__Coperator);
			return 1;
		} else {
			a=string__get_at(_this->_token,0);
			b=string__get_at(_this->_token,1);
			d=string__get_at(_this->_token,2);
			if (((((a=='>'))&&((b=='>')))&&((d=='>')))&&((_this->c=='='))) {
				string__add_char(_this->_token,_this->c);
				Alexer__validate(__this, Alexer__Coperator);
				Alexer__next(__this);
				return 1;
			}
			Alexer__validate(__this, Alexer__Coperator);
			return 1;
		}
	}
	return 0;
}
var Alexer__finish(var __this)
{
	struct Alexer *_this;
	_this = (void*)__this;
	(void)_this;

	if ((string__length(_this->_token))>0) {
		Alexer__error(__this, (var)(__string_Alexer161+ 2));
	}
	Alexer__validate(__this, Alexer__Cend);
	return 0;
}
// class hash
struct hash {
	var _arr;
	var size;
};
var hash__new(var size_)
{
	var i;
	struct hash *_this;
	NEW(hash);
	_this = (void*)__this;
	(void)_this;

	_this->size=size_;
	_this->_arr=array__new(_this->size);
	i=0;
	while (i<size_) {
		((var*)_this->_arr)[i]=0;
		i=i+1;
	}
	return __this;
}
var hash___V_dispose(var __this)
{
	var i;
	var next;
	var cur;
	struct hash *_this;
	_this = (void*)__this;
	(void)_this;

	i=0;
	while (i<_this->size) {
		cur=((var*)_this->_arr)[i];
		while (cur!=0) {
			next=((var*)cur)[hash__Cnext];
			array__dispose(cur);
			cur=next;
		}
		((var*)_this->_arr)[i]=0;
		i=i+1;
	}
	array__dispose(_this->_arr);
	std__free(__this);
	return 0;
}
var hash__add(var __this, var key, var value)
{
	var h;
	var hh;
	var cur;
	var old;
	var next;
	var prev;
	var ret;
	var cmp;
	struct hash *_this;
	_this = (void*)__this;
	(void)_this;

	h=string__get_hash(key);
	hh=h;
	h=h%_this->size;
	old=((var*)_this->_arr)[h];
	cur=0;
	if (old==0) {
		cur=array__new(4);
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
				cur=array__new(4);
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
			cur=array__new(4);
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
		cur=array__new(4);
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
	return ret;
}
var hash__get(var __this, var key)
{
	var h;
	var hh;
	var next;
	var cmp;
	struct hash *_this;
	_this = (void*)__this;
	(void)_this;

	h=string__get_hash(key);
	hh=h;
	h=h%_this->size;
	next=((var*)_this->_arr)[h];
	while (next!=0) {
		if ((((var*)next)[hash__Chash])==hh) {
			cmp=string__compare(key,((var*)next)[hash__Ckey]);
			if (cmp>0) {
				return 0;
			} else if (cmp==0) {
				return ((var*)next)[hash__Cvalue];
			}
		} else if ((((var*)next)[hash__Chash])>hh) {
			return 0;
		}
		next=((var*)next)[hash__Cnext];
	}
	return 0;
}
// class array
struct array {
	var dummy;
};
var array__new(var size)
{
	var a;

	a=std__alloc(size);
	((var*)a)[-(1)]=array___DcidD;
	return a;
}
var array___V_dispose(var __this)
{
	struct array *_this;
	_this = (void*)__this;
	(void)_this;

	std__free(__this);
	return 0;
}
// class buffer
struct buffer {
	var _arr;
	var size;
	var pos;
};
var buffer__new(var initial_size)
{
	var i;
	struct buffer *_this;
	NEW(buffer);
	_this = (void*)__this;
	(void)_this;

	_this->_arr=array__new(initial_size);
	_this->size=initial_size;
	_this->pos=0;
	i=0;
	while (i<initial_size) {
		((var*)_this->_arr)[i]=0;
		i=i+1;
	}
	return __this;
}
var buffer__dispose_all(var __this)
{
	var i;
	struct buffer *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->_arr==0) {
		buffer__dispose(__this);
		return 0;
	}
	i=0;
	while (i<_this->size) {
		std__delete(((var*)_this->_arr)[i]);
		i=i+1;
	}
	buffer__dispose(__this);
	return 0;
}
var buffer___V_dispose(var __this)
{
	struct buffer *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->_arr!=0) {
		array__dispose(_this->_arr);
		_this->_arr=0;
	}
	std__free(__this);
	return 0;
}
var buffer__length(var __this)
{
	struct buffer *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->pos;
}
var buffer__empty(var __this)
{
	struct buffer *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->pos>0) {
		return 0;
	}
	return 1;
}
var buffer__set_at(var __this, var idx, var elem)
{
	var a;
	var i;
	struct buffer *_this;
	_this = (void*)__this;
	(void)_this;

	if (idx>=_this->size) {
		a=array__new(idx+8);
		i=0;
		while (i<_this->size) {
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
	}
	((var*)_this->_arr)[idx]=elem;
	if (((idx+1))>_this->pos) {
		_this->pos=idx+1;
	}
	return 0;
}
var buffer__get_at(var __this, var idx)
{
	struct buffer *_this;
	_this = (void*)__this;
	(void)_this;

	return ((var*)_this->_arr)[idx];
}
var buffer__push(var __this, var elem)
{
	var p;
	struct buffer *_this;
	_this = (void*)__this;
	(void)_this;

	p=_this->pos+1;
	buffer__set_at(__this, _this->pos,elem);
	_this->pos=p;
	return 0;
}
var buffer__append(var __this, var buf)
{
	var l;
	var j;
	struct buffer *_this;
	_this = (void*)__this;
	(void)_this;

	j=buffer__length(buf);
	l=(buffer__length(__this))+j;
	_this->pos=l;
	while (j>0) {
		l=l-1;
		j=j-1;
		buffer__set_at(__this, l,buffer__get_at(buf,j));
	}
	return 0;
}
var buffer__set_last(var __this, var elem)
{
	struct buffer *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->pos<1) {
		return 0;
	}
	((var*)_this->_arr)[_this->pos-1]=elem;
	return 0;
}
var buffer__get_last(var __this)
{
	struct buffer *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->pos<1) {
		return 0;
	}
	return ((var*)_this->_arr)[_this->pos-1];
}
var buffer__pop(var __this)
{
	var elem;
	struct buffer *_this;
	_this = (void*)__this;
	(void)_this;

	elem=0;
	if (_this->pos>0) {
		_this->pos=_this->pos-1;
		elem=buffer__get_at(__this, _this->pos);
	}
	return elem;
}
var buffer__unshift(var __this, var elem)
{
	var i;
	var p;
	struct buffer *_this;
	_this = (void*)__this;
	(void)_this;

	p=_this->pos+1;
	buffer__set_at(__this, _this->pos,0);
	i=_this->pos;
	while (i>1) {
		i=i-1;
		((var*)_this->_arr)[i]=((var*)_this->_arr)[i-1];
	}
	((var*)_this->_arr)[0]=elem;
	_this->pos=p;
	return 0;
}
var buffer__shift(var __this)
{
	var elem;
	var i;
	var p;
	struct buffer *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->pos<1) {
		return 0;
	}
	p=_this->pos-1;
	elem=buffer__get_at(__this, 0);
	i=0;
	while (i<_this->pos) {
		((var*)_this->_arr)[i]=((var*)_this->_arr)[i+1];
		i=i+1;
	}
	_this->pos=p;
	return elem;
}
// class string
struct string {
	var _str;
	var size;
};
var string__new(var alloc)
{
	struct string *_this;
	NEW(string);
	_this = (void*)__this;
	(void)_this;

	_this->_str=0;
	std__stralloc(__this,alloc+1);
	_this->size=alloc;
	return __this;
}
var string___V_dispose(var __this)
{
	struct string *_this;
	_this = (void*)__this;
	(void)_this;

	std__strfree(__this);
	std__free(__this);
	return 0;
}
var string__get_buf(var __this)
{
	struct string *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->_str;
}
var string__set_buf(var __this, var b)
{
	struct string *_this;
	_this = (void*)__this;
	(void)_this;

	_this->_str=b;
	return 0;
}
var string__get_size(var __this)
{
	struct string *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->size;
}
var string__set_size(var __this, var ns)
{
	var ops;
	var b;
	struct string *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->size>ns) {
		return 0;
	}
	ops=string__new(ns+1);
	std__append(ops,0,__this,0,_this->size);
	b=_this->_str;
	_this->_str=string__get_buf(ops);
	string__set_buf(ops,b);
	string__dispose(ops);
	_this->size=ns;
	return 0;
}
var string__length(var __this)
{
	struct string *_this;
	_this = (void*)__this;
	(void)_this;

	return std__strlen(__this);
}
var string__set_int(var __this, var num)
{
	struct string *_this;
	_this = (void*)__this;
	(void)_this;

	return std__str_set_int(__this,_this->size,num);
}
var string__set(var __this, var src)
{
	var sl;
	struct string *_this;
	_this = (void*)__this;
	(void)_this;

	sl=std__strlen(src);
	if (_this->size<sl) {
		std__strfree(__this);
		std__stralloc(__this,sl+1);
		_this->size=sl;
	}
	std__str_set_at(__this,0,'\0');
	std__append(__this,0,src,0,sl);
	return 0;
}
var string__add_char(var __this, var num)
{
	var sl;
	var tl;
	var ns;
	var i;
	struct string *_this;
	_this = (void*)__this;
	(void)_this;

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
	return 0;
}
var string__add(var __this, var src)
{
	struct string *_this;
	_this = (void*)__this;
	(void)_this;

	string__add_at(__this, std__strlen(__this),src);
	return 0;
}
var string__add_at(var __this, var tl, var src)
{
	var sl;
	var ns;
	struct string *_this;
	_this = (void*)__this;
	(void)_this;

	sl=std__strlen(src);
	ns=(sl+tl)+1;
	if (ns>=_this->size) {
		string__set_size(__this, ns*2);
	}
	std__append(__this,tl,src,0,ns);
	return sl+tl;
}
var string__indexof(var __this, var start_pos, var needle)
{
	struct string *_this;
	_this = (void*)__this;
	(void)_this;

	return std__strindex(__this,start_pos,needle);
}
var string__substr(var __this, var start_pos, var length_, var result)
{
	var len;
	struct string *_this;
	_this = (void*)__this;
	(void)_this;

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
		string__set(result,(var)(__string_string162+ 2));
		return 0;
	}
	string__set_size(result,length_+1);
	std__str_set_at(result,0,'\0');
	std__append(result,0,__this,start_pos,length_);
	return 0;
}
var string__to_string(var __this)
{
	var str;
	struct string *_this;
	_this = (void*)__this;
	(void)_this;

	str=string__new((string__length(__this))+1);
	string__set(str,__this);
	return str;
}
var string__to_int(var __this)
{
	struct string *_this;
	_this = (void*)__this;
	(void)_this;

	return std__str_toint(__this);
}
var string__compare(var __this, var other)
{
	struct string *_this;
	_this = (void*)__this;
	(void)_this;

	return std__strcmp(__this,other);
}
var string__get_hash(var __this)
{
	struct string *_this;
	_this = (void*)__this;
	(void)_this;

	return std__strhash(__this);
}
var string__get_at(var __this, var at)
{
	struct string *_this;
	_this = (void*)__this;
	(void)_this;

	if (((at<_this->size))&&((_this->size>=0))) {
		return std__str_get_at(__this,at);
	}
	return '\0';
}
var string__set_at(var __this, var at, var v)
{
	struct string *_this;
	_this = (void*)__this;
	(void)_this;

	if (((at<_this->size))&&((_this->size>=0))) {
		std__str_set_at(__this,at,v);
	}
	return 0;
}
// class Aexpr
struct Aexpr {
	var op;
	var prec;
	var asso;
	var left;
	var right;
	var parent;
	var value;
	var value2;
	var flags;
	var origin;
	var data;
};
var Aexpr__new(var op_, var precedence_, var associativity_)
{
	struct Aexpr *_this;
	NEW(Aexpr);
	_this = (void*)__this;
	(void)_this;

	_this->op=op_;
	_this->prec=precedence_;
	_this->asso=associativity_;
	_this->parent=0;
	_this->left=0;
	_this->right=0;
	_this->value=0;
	_this->value2=0;
	_this->flags=0;
	_this->origin=0;
	_this->data=0;
	return __this;
}
var Aexpr___V_dispose(var __this)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	std__free(__this);
	return 0;
}
var Aexpr__clear_data(var __this)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->data!=0) {
		buffer__dispose(_this->data);
	}
	_this->data=0;
	return 0;
}
var Aexpr__add_data(var __this, var value)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	if (value==0) {
		return 0;
	}
	if ((string__length(value))<1) {
		return 0;
	}
	if (_this->data==0) {
		_this->data=buffer__new(3);
	}
	buffer__push(_this->data,value);
	return 0;
}
var Aexpr__get_data(var __this)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->data;
}
var Aexpr__merge_data(var __this, var buf)
{
	var l;
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	l=1;
	if (buf!=0) {
		l=buffer__length(buf);
	}
	if (_this->data==0) {
		_this->data=buffer__new(l);
	}
	if (buf==0) {
		return 0;
	}
	buffer__append(_this->data,buf);
	return 0;
}
var Aexpr__data_to_string(var __this, var s)
{
	var l;
	var i;
	var ol;
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->data==0) {
		return s;
	}
	ol=string__length(s);
	l=buffer__length(_this->data);
	i=0;
	while (i<l) {
		ol=string__add_at(s,ol,buffer__get_at(_this->data,i));
		i=i+1;
	}
	return s;
}
var Aexpr__get_origin(var __this)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->origin;
}
var Aexpr__set_origin(var __this, var orig)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	_this->origin=orig;
	return 0;
}
var Aexpr__get_right(var __this)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->right;
}
var Aexpr__set_right(var __this, var r)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	_this->right=r;
	return 0;
}
var Aexpr__get_left(var __this)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->left;
}
var Aexpr__set_left(var __this, var l)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	_this->left=l;
	return 0;
}
var Aexpr__get_parent(var __this)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->parent;
}
var Aexpr__set_parent(var __this, var p)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	_this->parent=p;
	return 0;
}
var Aexpr__get_value2(var __this)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->value2;
}
var Aexpr__set_value2(var __this, var v)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	_this->value2=v;
	return 0;
}
var Aexpr__get_value(var __this)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->data==0) {
		return 0;
	}
	return buffer__get_at(_this->data,0);
}
var Aexpr__set_value(var __this, var v)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->data!=0) {
		buffer__dispose(_this->data);
	}
	_this->data=buffer__new(1);
	buffer__push(_this->data,v);
	return 0;
}
var Aexpr__get_op(var __this)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->op;
}
var Aexpr__get_flags(var __this)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->flags;
}
var Aexpr__set_flags(var __this, var flags_)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	_this->flags=flags_;
	return 0;
}
var Aexpr__set_precedence(var __this, var p)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	_this->prec=p;
	return 0;
}
var Aexpr__get_precedence(var __this)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->prec;
}
var Aexpr__get_associativity(var __this)
{
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->asso;
}
var Aexpr__close(var __this, var op_)
{
	var cur;
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	cur=__this;
	while (cur!=0) {
		if ((Aexpr__get_op(cur))==op_) {
			return cur;
		}
		cur=Aexpr__get_parent(cur);
	}
	return 0;
}
var Aexpr__add(var __this, var ex)
{
	var pre;
	var ass;
	var cur;
	var ri;
	var le;
	var par;
	var child;
	var p;
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

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
	return ex;
}
var Aexpr__dump(var __this, var depth)
{
	var i;
	struct Aexpr *_this;
	_this = (void*)__this;
	(void)_this;

	if (_this->left!=0) {
		Aexpr__dump(_this->left,depth+1);
	}
	i=depth;
	while (i>0) {
		i=i-1;
		console__log_str((var)(__string_Aexpr163+ 2));
	}
	if (_this->value!=0) {
		console__log_str(_this->value);
	}
	console__log_int(_this->op);
	console__log((var)(__string_Aexpr164+ 2));
	if (_this->right!=0) {
		Aexpr__dump(_this->right,depth+1);
	}
	return 0;
}
// class Aemmiter
struct Aemmiter {
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
	var class_id;
	var string_id;
};
var Aemmiter__new()
{
	struct Aemmiter *_this;
	NEW(Aemmiter);
	_this = (void*)__this;
	(void)_this;

	_this->_proc=buffer__new(100);
	_this->_stk=buffer__new(100);
	_this->_expr_stk=buffer__new(100);
	_this->_data=string__new(10000);
	_this->_head=string__new(10000);
	_this->_mid=string__new(10000);
	_this->_str=string__new(10000);
	_this->_virtuals=buffer__new(1000);
	_this->token1=0;
	_this->token2=0;
	_this->class_id=10;
	_this->string_id=0;
	return __this;
}
var Aemmiter___V_dispose(var __this)
{
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	buffer__dispose(_this->_proc);
	buffer__dispose(_this->_stk);
	string__dispose(_this->_data);
	string__dispose(_this->_head);
	string__dispose(_this->_mid);
	string__dispose(_this->_str);
	buffer__dispose(_this->_virtuals);
	buffer__dispose(_this->_expr_stk);
	std__free(__this);
	return 0;
}
var Aemmiter__emmit(var __this, var par)
{
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	_this->clas=Aparser__get_next(par);
	while (_this->clas!=0) {
		Aemmiter__gen_class(__this);
		_this->clas=Aclass__get_next(_this->clas);
	}
	return 1;
}
var Aemmiter__get_head(var __this)
{
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->_head;
}
var Aemmiter__get_data(var __this)
{
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	return _this->_data;
}
var Aemmiter__get_mid(var __this)
{
	var l;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	l=string__length(_this->_mid);
	l=string__add_at(_this->_mid,l,(var)(__string_Aemmiter165+ 2));
	l=string__add_at(_this->_mid,l,_this->_str);
	string__dispose(_this->_str);
	_this->_str=string__new(1);
	l=string__add_at(_this->_mid,l,(var)(__string_Aemmiter166+ 2));
	return _this->_mid;
}
var Aemmiter__add_to_data(var __this, var s)
{
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	_this->_datal=string__add_at(_this->_data,_this->_datal,s);
	return 0;
}
var Aemmiter__gen_class(var __this)
{
	var to;
	var s;
	var mem;
	var i;
	var l;
	var m;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	to=Aclass__get_name(_this->clas);
	_this->class_name=Atoken__get_data(to);
	_this->_datal=string__length(_this->_data);
	Aemmiter__add_to_data(__this, (var)(__string_Aemmiter167+ 2));
	Aemmiter__add_to_data(__this, _this->class_name);
	Aemmiter__add_to_data(__this, (var)(__string_Aemmiter168+ 2));
	s=string__new(4);
	string__set_int(s,Aclass__get_nb_fields(_this->clas));
	_this->_headl=string__length(_this->_head);
	_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter169+ 2));
	_this->_headl=string__add_at(_this->_head,_this->_headl,_this->class_name);
	_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter170+ 2));
	_this->_headl=string__add_at(_this->_head,_this->_headl,s);
	_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter171+ 2));
	_this->class_id=_this->class_id+1;
	string__set_int(s,_this->class_id);
	_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter172+ 2));
	_this->_headl=string__add_at(_this->_head,_this->_headl,_this->class_name);
	_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter173+ 2));
	_this->_headl=string__add_at(_this->_head,_this->_headl,s);
	_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter174+ 2));
	string__dispose(s);
	_this->pass=0;
	while (_this->pass<3) {
		mem=Aclass__get_members(_this->clas);
		l=buffer__length(mem);
		i=0;
		while (i<l) {
			m=buffer__get_at(mem,i);
			Aemmiter__gen_member(__this, m);
			if (_this->pass==2) {
				Amember__dispose_body(m);
			}
			i=i+1;
		}
		_this->pass=_this->pass+1;
	}
	return 0;
}
var Aemmiter__gen_member(var __this, var mb)
{
	var k;
	var str;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	str=string__new(8);
	k=Amember__get_kind(mb);
	if (_this->pass==0) {
		Aemmiter__pass_0(__this, str,mb,k);
		Aemmiter__pass_1(__this, str,mb,k);
		Aemmiter__pass_2(__this, str,mb,k);
	} else if (_this->pass==1) {
		Aemmiter__pass_3(__this, str,mb,k);
	} else if (_this->pass==2) {
		Aemmiter__pass_4(__this, str,mb,k);
	}
	string__dispose(str);
	return 0;
}
var Aemmiter__gen_conditional_call(var __this, var v, var mb)
{
	var param;
	var params;
	var i;
	var l;
	var tok;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	_this->_datal=string__length(_this->_data);
	Aemmiter__add_to_data(__this, (var)(__string_Aemmiter175+ 2));
	Aemmiter__add_to_data(__this, Avirtual__get_class_name(v));
	Aemmiter__add_to_data(__this, (var)(__string_Aemmiter176+ 2));
	params=Amember__get_params(mb);
	Aemmiter__add_to_data(__this, Avirtual__get_class_name(v));
	Aemmiter__add_to_data(__this, (var)(__string_Aemmiter177+ 2));
	Aemmiter__add_to_data(__this, Amember__get_name_string(mb));
	Aemmiter__add_to_data(__this, (var)(__string_Aemmiter178+ 2));
	if (params!=0) {
		l=buffer__length(params);
		i=0;
		while (i<l) {
			param=buffer__get_at(params,i);
			Aemmiter__add_to_data(__this, (var)(__string_Aemmiter179+ 2));
			tok=Amember__get_name(param);
			Aemmiter__add_to_data(__this, Atoken__get_data(tok));
			i=i+1;
		}
	}
	Aemmiter__add_to_data(__this, (var)(__string_Aemmiter180+ 2));
	return 0;
}
var Aemmiter__gen_virtuals(var __this)
{
	var i;
	var v;
	var mb;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	i=buffer__length(_this->_virtuals);
	_this->_datal=string__length(_this->_data);
	while (i>0) {
		i=i-1;
		v=buffer__get_at(_this->_virtuals,i);
		mb=Avirtual__get_member(v);
		Aemmiter__gen_method_decl(__this, _this->_head,(var)(__string_Aemmiter181+ 2),Amember__get_name_string(mb),mb,Aclass__Cvirtual);
		_this->_headl=string__length(_this->_head);
		_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter182+ 2));
		Aemmiter__gen_method_decl(__this, _this->_data,(var)(__string_Aemmiter183+ 2),Amember__get_name_string(mb),mb,Aclass__Cvirtual);
		_this->_datal=string__length(_this->_data);
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter184+ 2));
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter185+ 2));
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter186+ 2));
		while (v!=0) {
			Aemmiter__gen_conditional_call(__this, v,mb);
			v=Avirtual__get_next(v);
		}
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter187+ 2));
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter188+ 2));
	}
	return 0;
}
var Aemmiter__pass_0(var __this, var str, var mb, var k)
{
	var t;
	var ty;
	var i;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	_this->_datal=string__length(_this->_data);
	_this->_headl=string__length(_this->_head);
	if (k==(Aclass__Cconst)) {
		_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter189+ 2));
		_this->_headl=string__add_at(_this->_head,_this->_headl,_this->class_name);
		_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter190+ 2));
		_this->_headl=string__add_at(_this->_head,_this->_headl,Amember__get_name_string(mb));
		_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter191+ 2));
		t=Amember__get_initial_value(mb);
		ty=Atoken__get_type(t);
		if (ty==(Alexer__Cstring)) {
			_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter192+ 2));
			_this->_headl=string__add_at(_this->_head,_this->_headl,_this->class_name);
			_this->_headl=string__add_at(_this->_head,_this->_headl,Amember__get_name_string(mb));
			_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter193+ 2));
			Aemmiter__gen_string(__this, Amember__get_name_string(mb),Atoken__get_data(t));
		} else if (ty==(Alexer__Cquote)) {
			_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter194+ 2));
			_this->_headl=string__add_at(_this->_head,_this->_headl,Atoken__get_data(t));
			_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter195+ 2));
		} else {
			_this->_headl=string__add_at(_this->_head,_this->_headl,Atoken__get_data(t));
		}
		_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter196+ 2));
	}
	if (k==(Aclass__Cfield)) {
		i=Amember__get_index(mb);
		if (i==0) {
			Aemmiter__add_to_data(__this, (var)(__string_Aemmiter197+ 2));
			Aemmiter__add_to_data(__this, _this->class_name);
			Aemmiter__add_to_data(__this, (var)(__string_Aemmiter198+ 2));
		}
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter199+ 2));
		Aemmiter__add_to_data(__this, Amember__get_name_string(mb));
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter200+ 2));
		if (((i+1))==(Aclass__get_nb_fields(_this->clas))) {
			Aemmiter__add_to_data(__this, (var)(__string_Aemmiter201+ 2));
		}
	}
	return 0;
}
var Aemmiter__pass_1(var __this, var str, var mb, var k)
{
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	_this->_datal=string__length(_this->_data);
	if (k==(Aclass__Cstatic)) {
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter202+ 2));
		Aemmiter__add_to_data(__this, _this->class_name);
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter203+ 2));
		Aemmiter__add_to_data(__this, Amember__get_name_string(mb));
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter204+ 2));
	}
	return 0;
}
var Aemmiter__pass_2(var __this, var str, var mb, var k)
{
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	return 0;
}
var Aemmiter__pad(var __this, var depth)
{
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	_this->_datal=string__length(_this->_data);
	while (depth>0) {
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter205+ 2));
		depth=depth-1;
	}
	return 0;
}
var Aemmiter__find_param(var __this, var stri)
{
	var v;
	var i;
	var vars;
	var tok;
	var s;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

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
					return v;
				}
			}
		}
	}
	return 0;
}
var Aemmiter__find_member(var __this, var stri)
{
	var v;
	var i;
	var vars;
	var tok;
	var s;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

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
			if ((s!=0)) {
				if ((string__compare(stri,s))==0) {
					return v;
				}
			}
		}
	}
	return 0;
}
var Aemmiter__find_field(var __this, var stri)
{
	var v;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	v=Aemmiter__find_member(__this, stri);
	if (((v!=0))&&(((Amember__get_kind(v))==(Aclass__Cfield)))) {
		return v;
	}
	return 0;
}
var Aemmiter__find_static(var __this, var stri)
{
	var v;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	v=Aemmiter__find_member(__this, stri);
	if (((v!=0))&&(((Amember__get_kind(v))==(Aclass__Cstatic)))) {
		return v;
	}
	return 0;
}
var Aemmiter__find_meth_virt(var __this, var stri)
{
	var v;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	v=Aemmiter__find_member(__this, stri);
	if (v!=0) {
		if ((((Amember__get_kind(v))==(Aclass__Cmethod)))||(((Amember__get_kind(v))==(Aclass__Cvirtual)))) {
			return v;
		}
	}
	return 0;
}
var Aemmiter__find_local(var __this, var stri)
{
	var v;
	var i;
	var vars;
	var tok;
	var s;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

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
					return v;
				}
			}
		}
	}
	return 0;
}
var Aemmiter__expr_gen_call(var __this, var expr)
{
	var ex1;
	var ex2;
	var tok;
	var stri;
	var v;
	var obj;
	var fld;
	var s;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	ex2=buffer__pop(_this->_expr_stk);
	ex1=buffer__pop(_this->_expr_stk);
	stri=Aexpr__data_to_string(ex1,Aemmiter__new_string(__this, 8));
	obj=Aexpr__get_value2(ex1);
	Aexpr__clear_data(expr);
	if (obj==0) {
		v=Aemmiter__find_meth_virt(__this, stri);
		if ((v!=0)) {
			Aexpr__add_data(expr,_this->class_name);
			Aexpr__add_data(expr,(var)(__string_Aemmiter206+ 2));
			Aexpr__add_data(expr,stri);
			s=Aexpr__get_value(ex2);
			if ((s!=0)&&((string__length(s))>0)) {
				Aexpr__add_data(expr,(var)(__string_Aemmiter207+ 2));
				Aexpr__merge_data(expr,Aexpr__get_data(ex2));
				Aexpr__add_data(expr,(var)(__string_Aemmiter208+ 2));
			} else {
				Aexpr__add_data(expr,(var)(__string_Aemmiter209+ 2));
			}
			buffer__push(_this->_expr_stk,expr);
			return 0;
		}
		Aemmiter__error(__this, Aexpr__get_origin(expr),(var)(__string_Aemmiter210+ 2));
		return 0;
	}
	fld=0;
	v=Aemmiter__find_local(__this, obj);
	if (v==0) {
		v=Aemmiter__find_param(__this, obj);
	}
	if (v==0) {
		v=Aemmiter__find_field(__this, obj);
		if (v!=0) {
			fld=1;
		}
	}
	if (v!=0) {
		tok=Amember__get_type_id(v);
		if (tok==0) {
			console__log(obj);
			console__log(Amember__get_name_string(v));
			Aemmiter__error(__this, Aexpr__get_origin(ex1),(var)(__string_Aemmiter211+ 2));
			return 0;
		}
		Aexpr__add_data(expr,Atoken__get_data(tok));
		Aexpr__add_data(expr,(var)(__string_Aemmiter212+ 2));
		Aexpr__merge_data(expr,Aexpr__get_data(ex1));
		s=Aexpr__get_value(ex2);
		Aexpr__add_data(expr,(var)(__string_Aemmiter213+ 2));
		if (fld!=0) {
			Aexpr__add_data(expr,(var)(__string_Aemmiter214+ 2));
		}
		Aexpr__add_data(expr,Aexpr__get_value2(ex1));
		if ((s!=0)&&((string__length(s))>0)) {
			Aexpr__add_data(expr,(var)(__string_Aemmiter215+ 2));
			Aexpr__merge_data(expr,Aexpr__get_data(ex2));
		}
		Aexpr__add_data(expr,(var)(__string_Aemmiter216+ 2));
		buffer__push(_this->_expr_stk,expr);
		return 0;
	}
	Aexpr__add_data(expr,obj);
	Aexpr__add_data(expr,(var)(__string_Aemmiter217+ 2));
	Aexpr__merge_data(expr,Aexpr__get_data(ex1));
	Aexpr__add_data(expr,(var)(__string_Aemmiter218+ 2));
	Aexpr__merge_data(expr,Aexpr__get_data(ex2));
	Aexpr__add_data(expr,(var)(__string_Aemmiter219+ 2));
	buffer__push(_this->_expr_stk,expr);
	return 0;
}
var Aemmiter__expr_gen_sub_expr(var __this, var expr)
{
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	if ((Aexpr__get_right(expr))==0) {
		Aexpr__clear_data(expr);
		Aexpr__add_data(expr,(var)(__string_Aemmiter220+ 2));
		buffer__push(_this->_expr_stk,expr);
	}
	return 0;
}
var Aemmiter__expr_gen_comma(var __this, var expr)
{
	var ex1;
	var ex2;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	ex2=buffer__pop(_this->_expr_stk);
	ex1=buffer__pop(_this->_expr_stk);
	Aexpr__clear_data(expr);
	Aexpr__merge_data(expr,Aexpr__get_data(ex1));
	Aexpr__add_data(expr,(var)(__string_Aemmiter221+ 2));
	Aexpr__merge_data(expr,Aexpr__get_data(ex2));
	buffer__push(_this->_expr_stk,expr);
	return 0;
}
var Aemmiter__expr_gen_index(var __this, var expr)
{
	var ex1;
	var ex2;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	ex2=buffer__pop(_this->_expr_stk);
	ex1=buffer__pop(_this->_expr_stk);
	Aexpr__clear_data(expr);
	Aexpr__add_data(expr,(var)(__string_Aemmiter222+ 2));
	Aexpr__merge_data(expr,Aexpr__get_data(ex1));
	Aexpr__add_data(expr,(var)(__string_Aemmiter223+ 2));
	Aexpr__merge_data(expr,Aexpr__get_data(ex2));
	Aexpr__add_data(expr,(var)(__string_Aemmiter224+ 2));
	buffer__push(_this->_expr_stk,expr);
	return 0;
}
var Aemmiter__expr_gen_par(var __this, var expr)
{
	var ex1;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	ex1=buffer__pop(_this->_expr_stk);
	Aexpr__clear_data(expr);
	Aexpr__add_data(expr,(var)(__string_Aemmiter225+ 2));
	Aexpr__merge_data(expr,Aexpr__get_data(ex1));
	Aexpr__add_data(expr,(var)(__string_Aemmiter226+ 2));
	buffer__push(_this->_expr_stk,expr);
	return 0;
}
var Aemmiter__expr_gen_constant(var __this, var expr)
{
	var ex1;
	var ex2;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	Aexpr__clear_data(expr);
	ex2=buffer__pop(_this->_expr_stk);
	ex1=buffer__pop(_this->_expr_stk);
	Aexpr__merge_data(expr,Aexpr__get_data(ex1));
	Aexpr__add_data(expr,(var)(__string_Aemmiter227+ 2));
	Aexpr__merge_data(expr,Aexpr__get_data(ex2));
	buffer__push(_this->_expr_stk,expr);
	return 0;
}
var Aemmiter__expr_gen_dot(var __this, var expr)
{
	var ex1;
	var ex2;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	Aexpr__clear_data(expr);
	ex2=buffer__pop(_this->_expr_stk);
	ex1=buffer__pop(_this->_expr_stk);
	Aexpr__set_value2(expr,Aexpr__data_to_string(ex1,Aemmiter__new_string(__this, 8)));
	Aexpr__merge_data(expr,Aexpr__get_data(ex2));
	buffer__push(_this->_expr_stk,expr);
	return 0;
}
var Aemmiter__gen_string(var __this, var s2, var value)
{
	var l;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	l=string__length(_this->_mid);
	l=string__add_at(_this->_mid,l,(var)(__string_Aemmiter228+ 2));
	l=string__add_at(_this->_mid,l,_this->class_name);
	l=string__add_at(_this->_mid,l,s2);
	l=string__add_at(_this->_mid,l,(var)(__string_Aemmiter229+ 2));
	l=string__add_at(_this->_mid,l,(var)(__string_Aemmiter230+ 2));
	l=string__add_at(_this->_mid,l,value);
	l=string__add_at(_this->_mid,l,(var)(__string_Aemmiter231+ 2));
	l=string__add_at(_this->_mid,l,(var)(__string_Aemmiter232+ 2));
	l=string__add_at(_this->_mid,l,(var)(__string_Aemmiter233+ 2));
	l=string__add_at(_this->_mid,l,_this->class_name);
	l=string__add_at(_this->_mid,l,s2);
	l=string__add_at(_this->_mid,l,(var)(__string_Aemmiter234+ 2));
	l=string__add_at(_this->_mid,l,(var)(__string_Aemmiter235+ 2));
	string__add(_this->_str,(var)(__string_Aemmiter236+ 2));
	string__add(_this->_str,_this->class_name);
	string__add(_this->_str,s2);
	string__add(_this->_str,(var)(__string_Aemmiter237+ 2));
	string__add(_this->_str,(var)(__string_Aemmiter238+ 2));
	string__add(_this->_str,_this->class_name);
	string__add(_this->_str,s2);
	string__add(_this->_str,(var)(__string_Aemmiter239+ 2));
	return 0;
}
var Aemmiter__number(var __this, var n)
{
	var s2;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	s2=string__new(8);
	string__set_int(s2,n);
	return s2;
}
var Aemmiter__new_string(var __this, var l)
{
	var s2;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	s2=string__new(l);
	return s2;
}
var Aemmiter__expr_gen_str_const(var __this, var expr)
{
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	_this->string_id=_this->string_id+1;
	Aemmiter__gen_string(__this, Aemmiter__number(__this, _this->string_id),Aexpr__data_to_string(expr,Aemmiter__new_string(__this, 20)));
	Aexpr__clear_data(expr);
	Aexpr__add_data(expr,(var)(__string_Aemmiter240+ 2));
	Aexpr__add_data(expr,_this->class_name);
	Aexpr__add_data(expr,Aemmiter__number(__this, _this->string_id));
	Aexpr__add_data(expr,(var)(__string_Aemmiter241+ 2));
	buffer__push(_this->_expr_stk,expr);
	return 0;
}
var Aemmiter__expr_gen_char_const(var __this, var expr)
{
	var s;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	s=Aexpr__data_to_string(expr,Aemmiter__new_string(__this, 3));
	Aexpr__clear_data(expr);
	Aexpr__add_data(expr,(var)(__string_Aemmiter242+ 2));
	if ((string__length(s))>0) {
		Aexpr__add_data(expr,s);
	} else {
		Aexpr__add_data(expr,(var)(__string_Aemmiter243+ 2));
	}
	Aexpr__add_data(expr,(var)(__string_Aemmiter244+ 2));
	buffer__push(_this->_expr_stk,expr);
	return 0;
}
var Aemmiter__expr_gen0(var __this, var expr, var op)
{
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	Aexpr__clear_data(expr);
	Aexpr__add_data(expr,op);
	buffer__push(_this->_expr_stk,expr);
	return 0;
}
var Aemmiter__expr_gen1(var __this, var expr, var op)
{
	var ex1;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	Aexpr__clear_data(expr);
	ex1=buffer__pop(_this->_expr_stk);
	Aexpr__add_data(expr,op);
	Aexpr__add_data(expr,(var)(__string_Aemmiter245+ 2));
	Aexpr__merge_data(expr,Aexpr__get_data(ex1));
	Aexpr__add_data(expr,(var)(__string_Aemmiter246+ 2));
	buffer__push(_this->_expr_stk,expr);
	return 0;
}
var Aemmiter__expr_gen_assign(var __this, var expr, var op)
{
	var ex1;
	var ex2;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	Aexpr__clear_data(expr);
	ex2=buffer__pop(_this->_expr_stk);
	ex1=buffer__pop(_this->_expr_stk);
	Aexpr__merge_data(expr,Aexpr__get_data(ex1));
	Aexpr__add_data(expr,op);
	Aexpr__merge_data(expr,Aexpr__get_data(ex2));
	buffer__push(_this->_expr_stk,expr);
	return 0;
}
var Aemmiter__expr_gen2(var __this, var expr, var op)
{
	var ex1;
	var ex2;
	var oper;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	Aexpr__clear_data(expr);
	ex2=buffer__pop(_this->_expr_stk);
	ex1=buffer__pop(_this->_expr_stk);
	oper=Aexpr__get_op(ex1);
	if (oper>(Aclass__Croot)) {
		Aexpr__add_data(expr,(var)(__string_Aemmiter247+ 2));
	}
	Aexpr__merge_data(expr,Aexpr__get_data(ex1));
	if (oper>(Aclass__Croot)) {
		Aexpr__add_data(expr,(var)(__string_Aemmiter248+ 2));
	}
	Aexpr__add_data(expr,op);
	oper=Aexpr__get_op(ex2);
	if (oper>(Aclass__Croot)) {
		Aexpr__add_data(expr,(var)(__string_Aemmiter249+ 2));
	}
	Aexpr__merge_data(expr,Aexpr__get_data(ex2));
	if (oper>(Aclass__Croot)) {
		Aexpr__add_data(expr,(var)(__string_Aemmiter250+ 2));
	}
	buffer__push(_this->_expr_stk,expr);
	return 0;
}
var Aemmiter__expr_gen_var(var __this, var expr)
{
	var stri;
	var v;
	var ex;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	stri=Aexpr__data_to_string(expr,Aemmiter__new_string(__this, 8));
	Aexpr__clear_data(expr);
	if (stri==0) {
		buffer__push(_this->_expr_stk,expr);
		return 0;
	}
	v=Aemmiter__find_local(__this, stri);
	if (v!=0) {
		Aexpr__add_data(expr,stri);
		buffer__push(_this->_expr_stk,expr);
		return 0;
	}
	v=Aemmiter__find_param(__this, stri);
	if (v!=0) {
		Aexpr__add_data(expr,stri);
		buffer__push(_this->_expr_stk,expr);
		return 0;
	}
	ex=Aexpr__get_parent(expr);
	v=0;
	if ((Aexpr__get_op(ex))!=(Aclass__Cdot)) {
		v=Aemmiter__find_member(__this, stri);
	}
	if (((v!=0))&&(((Amember__get_kind(v))==(Aclass__Cfield)))) {
		Aexpr__add_data(expr,(var)(__string_Aemmiter251+ 2));
		Aexpr__add_data(expr,stri);
		buffer__push(_this->_expr_stk,expr);
		return 0;
	}
	v=Aemmiter__find_static(__this, stri);
	if (v!=0) {
		Aexpr__add_data(expr,_this->class_name);
		Aexpr__add_data(expr,(var)(__string_Aemmiter252+ 2));
		Aexpr__add_data(expr,stri);
		buffer__push(_this->_expr_stk,expr);
		return 0;
	}
	Aexpr__add_data(expr,stri);
	buffer__push(_this->_expr_stk,expr);
	return 0;
}
var Aemmiter__expr_process(var __this, var expr)
{
	var op;
	var ex;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	op=Aexpr__get_op(expr);
	if (op<(Aclass__Croot)) {
		if (op==(Aclass__Cnull)) {
			Aemmiter__expr_gen0(__this, expr,(var)(__string_Aemmiter253+ 2));
		} else if (op==(Aclass__Cchar_const)) {
			Aemmiter__expr_gen_char_const(__this, expr);
		} else if (op==(Aclass__Cint_const)) {
			buffer__push(_this->_expr_stk,expr);
		} else if (op==(Aclass__Cstr_const)) {
			Aemmiter__expr_gen_str_const(__this, expr);
		} else if (op==(Aclass__Cthis)) {
			Aemmiter__expr_gen0(__this, expr,(var)(__string_Aemmiter254+ 2));
		} else {
			Aemmiter__expr_gen_var(__this, expr);
		}
		return 0;
	}
	if (op==(Aclass__Croot)) {
		if ((buffer__length(_this->_expr_stk))!=1) {
			Aemmiter__error(__this, Aexpr__get_origin(expr),(var)(__string_Aemmiter255+ 2));
			return 0;
		}
		ex=buffer__pop(_this->_expr_stk);
		Aexpr__data_to_string(ex,_this->_data);
		_this->_datal=string__length(_this->_data);
	} else if (op==(Aclass__Cassign)) {
		Aemmiter__expr_gen_assign(__this, expr,(var)(__string_Aemmiter256+ 2));
	} else if (op==(Aclass__Cequal)) {
		Aemmiter__expr_gen2(__this, expr,(var)(__string_Aemmiter257+ 2));
	} else if (op==(Aclass__Cnotequal)) {
		Aemmiter__expr_gen2(__this, expr,(var)(__string_Aemmiter258+ 2));
	} else if (op==(Aclass__Clargerequal)) {
		Aemmiter__expr_gen2(__this, expr,(var)(__string_Aemmiter259+ 2));
	} else if (op==(Aclass__Clesserequal)) {
		Aemmiter__expr_gen2(__this, expr,(var)(__string_Aemmiter260+ 2));
	} else if (op==(Aclass__Clarger)) {
		Aemmiter__expr_gen2(__this, expr,(var)(__string_Aemmiter261+ 2));
	} else if (op==(Aclass__Clesser)) {
		Aemmiter__expr_gen2(__this, expr,(var)(__string_Aemmiter262+ 2));
	} else if (op==(Aclass__Clogicaland)) {
		Aemmiter__expr_gen2(__this, expr,(var)(__string_Aemmiter263+ 2));
	} else if (op==(Aclass__Clogicalor)) {
		Aemmiter__expr_gen2(__this, expr,(var)(__string_Aemmiter264+ 2));
	} else if (op==(Aclass__Cadd)) {
		Aemmiter__expr_gen2(__this, expr,(var)(__string_Aemmiter265+ 2));
	} else if (op==(Aclass__Csub)) {
		Aemmiter__expr_gen2(__this, expr,(var)(__string_Aemmiter266+ 2));
	} else if (op==(Aclass__Cmult)) {
		Aemmiter__expr_gen2(__this, expr,(var)(__string_Aemmiter267+ 2));
	} else if (op==(Aclass__Cdiv)) {
		Aemmiter__expr_gen2(__this, expr,(var)(__string_Aemmiter268+ 2));
	} else if (op==(Aclass__Cmodulo)) {
		Aemmiter__expr_gen2(__this, expr,(var)(__string_Aemmiter269+ 2));
	} else if (op==(Aclass__Clogicalnot)) {
		Aemmiter__expr_gen1(__this, expr,(var)(__string_Aemmiter270+ 2));
	} else if (op==(Aclass__Cparenthesis)) {
		Aemmiter__expr_gen_par(__this, expr);
	} else if (op==(Aclass__Cunaryplus)) {
		Aemmiter__expr_gen1(__this, expr,(var)(__string_Aemmiter271+ 2));
	} else if (op==(Aclass__Cunaryminus)) {
		Aemmiter__expr_gen1(__this, expr,(var)(__string_Aemmiter272+ 2));
	} else if (op==(Aclass__Cdot)) {
		Aemmiter__expr_gen_dot(__this, expr);
	} else if (op==(Aclass__Cconstant)) {
		Aemmiter__expr_gen_constant(__this, expr);
	} else if (op==(Aclass__Ccall)) {
		Aemmiter__expr_gen_call(__this, expr);
	} else if (op==(Aclass__Cindex)) {
		Aemmiter__expr_gen_index(__this, expr);
	} else if (op==(Aclass__Ccomma)) {
		Aemmiter__expr_gen_comma(__this, expr);
	} else if (op==(Aclass__Cexpr)) {
		Aemmiter__expr_gen_sub_expr(__this, expr);
	} else {
		Aemmiter__error(__this, Aexpr__get_origin(expr),(var)(__string_Aemmiter273+ 2));
		return 0;
	}
	return 0;
}
var Aemmiter__expr_gen(var __this, var expr)
{
	var ex;
	var ex1;
	var stack;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	stack=buffer__new(4);
	ex=Aexpr__get_right(expr);
	ex=expr;
	Aexpr__set_flags(ex,0);
	buffer__push(stack,ex);
	while ((buffer__length(stack))>0) {
		ex=buffer__get_last(stack);
		if ((Aexpr__get_flags(ex))!=0) {
			ex=buffer__pop(stack);
			Aemmiter__expr_process(__this, ex);
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
	buffer__dispose(stack);
	return 0;
}
var Aemmiter__is_switch(var __this, var body_, var i, var l)
{
	var stm;
	var ty;
	var ex;
	var r;
	var op;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	return 0;
	stm=buffer__get_at(body_,i);
	ty=Astatement__get_type(stm);
	ex=Astatement__get_expression(stm);
	if (ex==0) {
		return 0;
	}
	ex=Aexpr__get_right(ex);
	op=Aexpr__get_op(ex);
	if (op==(Aclass__Cequal)) {
		r=Aexpr__get_left(ex);
		if ((Aexpr__get_op(r))==(Aclass__Cvar)) {
			console__log_str(Aexpr__get_value(r));
		} else {
			console__log_int(Aexpr__get_op(r));
		}
		console__log((var)(__string_Aemmiter274+ 2));
	} else if (op==(Aclass__Clogicaland)) {
		console__log((var)(__string_Aemmiter275+ 2));
	} else {
		return 0;
	}
	while (i<l) {
		stm=buffer__get_at(body_,i);
		ty=Astatement__get_type(stm);
		if (ty==(Aclass__Celse)) {
			return 1;
		}
		if (ty!=(Aclass__Celseif)) {
			return 1;
		}
		ex=Astatement__get_expression(stm);
		if (ex==0) {
			return 0;
		}
		i=i+1;
	}
	return 0;
}
var Aemmiter__body_gen(var __this, var mb, var k, var vars_, var body_)
{
	var l;
	var i;
	var tok;
	var va;
	var stm;
	var ty;
	var stack;
	var padde;
	var ex;
	var buf;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	_this->cur_memb=mb;
	_this->_datal=string__length(_this->_data);
	Aemmiter__add_to_data(__this, (var)(__string_Aemmiter276+ 2));
	stack=buffer__new(4);
	if (vars_!=0) {
		l=buffer__length(vars_);
	} else {
		l=0;
	}
	i=0;
	while (i<l) {
		va=buffer__get_at(vars_,i);
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter277+ 2));
		tok=Amember__get_name(va);
		Aemmiter__add_to_data(__this, Atoken__get_data(tok));
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter278+ 2));
		i=i+1;
	}
	if (k==(Aclass__Cconstructor)) {
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter279+ 2));
		Aemmiter__add_to_data(__this, _this->class_name);
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter280+ 2));
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter281+ 2));
		Aemmiter__add_to_data(__this, _this->class_name);
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter282+ 2));
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter283+ 2));
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter284+ 2));
	} else if (((k==(Aclass__Cvirtual)))||((k==(Aclass__Cmethod)))) {
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter285+ 2));
		Aemmiter__add_to_data(__this, _this->class_name);
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter286+ 2));
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter287+ 2));
		Aemmiter__add_to_data(__this, (var)(__string_Aemmiter288+ 2));
	}
	l=buffer__length(body_);
	i=0;
	padde=1;
	while (i<l) {
		stm=buffer__get_at(body_,i);
		ty=Astatement__get_type(stm);
		if (((ty!=(Aclass__Celseif)))&&((ty!=(Aclass__Celse)))) {
			Aemmiter__add_to_data(__this, (var)(__string_Aemmiter289+ 2));
			Aemmiter__pad(__this, padde);
		}
		if (((ty==(Aclass__Cif)))||((ty==(Aclass__Celseif)))) {
			Aemmiter__is_switch(__this, body_,i,l);
			if (ty==(Aclass__Celseif)) {
				Aemmiter__add_to_data(__this, (var)(__string_Aemmiter290+ 2));
			} else {
				Aemmiter__add_to_data(__this, (var)(__string_Aemmiter291+ 2));
			}
			ex=Astatement__get_expression(stm);
			if (ex!=0) {
				Aemmiter__expr_gen(__this, ex);
			}
			Aemmiter__add_to_data(__this, (var)(__string_Aemmiter292+ 2));
			buffer__push(stack,l);
			buffer__push(stack,i+1);
			buffer__push(stack,body_);
			buf=Astatement__get_else(stm);
			if (buf!=0) {
				buffer__push(stack,buffer__length(buf));
				buffer__push(stack,0);
				buffer__push(stack,buf);
			}
			padde=padde+1;
			i=-(1);
			l=0;
			body_=Astatement__get_statements(stm);
			if (body_!=0) {
				l=buffer__length(body_);
			}
		} else if (ty==(Aclass__Celse)) {
			Aemmiter__add_to_data(__this, (var)(__string_Aemmiter293+ 2));
			padde=padde+1;
		} else if (ty==(Aclass__Cbreak)) {
			Aemmiter__add_to_data(__this, (var)(__string_Aemmiter294+ 2));
		} else if (ty==(Aclass__Creturn)) {
			ex=Astatement__get_expression(stm);
			if (ex!=0) {
				Aemmiter__add_to_data(__this, (var)(__string_Aemmiter295+ 2));
				Aemmiter__expr_gen(__this, ex);
				Aemmiter__add_to_data(__this, (var)(__string_Aemmiter296+ 2));
			} else {
				Aemmiter__add_to_data(__this, (var)(__string_Aemmiter297+ 2));
			}
		} else if (ty==(Aclass__Cdo)) {
			ex=Astatement__get_expression(stm);
			if (ex!=0) {
				Aemmiter__expr_gen(__this, ex);
			}
			Aemmiter__add_to_data(__this, (var)(__string_Aemmiter298+ 2));
		} else if (ty==(Aclass__Clet)) {
			ex=Astatement__get_expression(stm);
			if (ex!=0) {
				Aemmiter__expr_gen(__this, ex);
			}
			Aemmiter__add_to_data(__this, (var)(__string_Aemmiter299+ 2));
		} else if (ty==(Aclass__Cwhile)) {
			Aemmiter__add_to_data(__this, (var)(__string_Aemmiter300+ 2));
			ex=Astatement__get_expression(stm);
			if (ex!=0) {
				Aemmiter__expr_gen(__this, ex);
			}
			Aemmiter__add_to_data(__this, (var)(__string_Aemmiter301+ 2));
			buffer__push(stack,l);
			buffer__push(stack,i+1);
			buffer__push(stack,body_);
			i=-(1);
			l=0;
			body_=Astatement__get_statements(stm);
			if (body_!=0) {
				l=buffer__length(body_);
			}
			padde=padde+1;
		} else {
			Aemmiter__add_to_data(__this, (var)(__string_Aemmiter302+ 2));
		}
		i=i+1;
		if (i>=l) {
			padde=padde-1;
			Aemmiter__add_to_data(__this, (var)(__string_Aemmiter303+ 2));
			Aemmiter__pad(__this, padde);
			Aemmiter__add_to_data(__this, (var)(__string_Aemmiter304+ 2));
		}
		while (((i>=l))&&(((buffer__length(stack))>0))) {
			body_=buffer__pop(stack);
			i=buffer__pop(stack);
			l=buffer__pop(stack);
			if (i>=l) {
				padde=padde-1;
				Aemmiter__add_to_data(__this, (var)(__string_Aemmiter305+ 2));
				Aemmiter__pad(__this, padde);
				Aemmiter__add_to_data(__this, (var)(__string_Aemmiter306+ 2));
			}
		}
	}
	Aemmiter__add_to_data(__this, (var)(__string_Aemmiter307+ 2));
	buffer__dispose(stack);
	return 0;
}
var Aemmiter__gen_type(var __this, var mb)
{
	var ty;
	var tok;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	_this->_datal=string__length(_this->_data);
	tok=Amember__get_type_id(mb);
	if (tok!=0) {
		Aemmiter__add_to_data(__this, Atoken__get_data(tok));
	} else {
		ty=Amember__get_type(mb);
		if (ty==(Aclass__Cint)) {
			Aemmiter__add_to_data(__this, (var)(__string_Aemmiter308+ 2));
		} else if (ty==(Aclass__Cvoid)) {
			Aemmiter__add_to_data(__this, (var)(__string_Aemmiter309+ 2));
		} else {
			Aemmiter__error(__this, Amember__get_name(mb),(var)(__string_Aemmiter310+ 2));
		}
	}
	return 0;
}
var Aemmiter__add_virtual(var __this, var mb)
{
	var n;
	var v;
	var nv;
	var i;
	var s;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	n=Amember__get_name_string(mb);
	nv=Avirtual__new(mb,_this->class_name);
	i=buffer__length(_this->_virtuals);
	while (i>0) {
		i=i-1;
		v=buffer__get_at(_this->_virtuals,i);
		if (v!=0) {
			s=Avirtual__get_member_name(v);
			if (((s!=0))&&(((string__compare(n,s))==0))) {
				Avirtual__set_next(nv,Avirtual__get_next(v));
				Avirtual__set_next(v,nv);
				return 0;
			}
		}
	}
	buffer__push(_this->_virtuals,nv);
	return 0;
}
var Aemmiter__gen_virtual_caller(var __this, var mb)
{
	var param;
	var params;
	var i;
	var l;
	var tok;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	params=Amember__get_params(mb);
	_this->_headl=string__length(_this->_head);
	_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter311+ 2));
	_this->_headl=string__add_at(_this->_head,_this->_headl,_this->class_name);
	_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter312+ 2));
	_this->_headl=string__add_at(_this->_head,_this->_headl,Amember__get_name_string(mb));
	_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter313+ 2));
	if (params!=0) {
		l=buffer__length(params);
		i=0;
		while (i<l) {
			param=buffer__get_at(params,i);
			_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter314+ 2));
			tok=Amember__get_name(param);
			_this->_headl=string__add_at(_this->_head,_this->_headl,Atoken__get_data(tok));
			i=i+1;
		}
	}
	_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter315+ 2));
	_this->_headl=string__add_at(_this->_head,_this->_headl,Amember__get_name_string(mb));
	_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter316+ 2));
	if (params!=0) {
		l=buffer__length(params);
		i=0;
		while (i<l) {
			param=buffer__get_at(params,i);
			_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter317+ 2));
			tok=Amember__get_name(param);
			_this->_headl=string__add_at(_this->_head,_this->_headl,Atoken__get_data(tok));
			i=i+1;
		}
	}
	_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter318+ 2));
	return 0;
}
var Aemmiter__gen_method_decl(var __this, var dest, var c_name, var name, var mb, var k)
{
	var param;
	var params;
	var i;
	var l;
	var sub;
	var tok;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	string__add(dest,(var)(__string_Aemmiter319+ 2));
	string__add(dest,c_name);
	string__add(dest,(var)(__string_Aemmiter320+ 2));
	string__add(dest,name);
	params=Amember__get_params(mb);
	string__add(dest,(var)(__string_Aemmiter321+ 2));
	sub=1;
	if (((k==(Aclass__Cmethod)))||((k==(Aclass__Cvirtual)))) {
		string__add(dest,(var)(__string_Aemmiter322+ 2));
		sub=2;
	}
	if (params!=0) {
		l=buffer__length(params);
		i=0;
		while (i<l) {
			param=buffer__get_at(params,i);
			if (((i>0))||((sub==2))) {
				string__add(dest,(var)(__string_Aemmiter323+ 2));
			}
			string__add(dest,(var)(__string_Aemmiter324+ 2));
			tok=Amember__get_name(param);
			string__add(dest,Atoken__get_data(tok));
			i=i+1;
		}
	}
	string__add(dest,(var)(__string_Aemmiter325+ 2));
	return 0;
}
var Aemmiter__pass_3(var __this, var str, var mb, var k)
{
	var vars;
	var body;
	var sub;
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	_this->_datal=string__length(_this->_data);
	sub=0;
	if (k==(Aclass__Cconstructor)) {
		sub=1;
	} else if (k==(Aclass__Cfunction)) {
		sub=1;
	} else if (k==(Aclass__Cmethod)) {
		sub=2;
	} else if (k==(Aclass__Cvirtual)) {
		sub=2;
	}
	if (sub!=0) {
		if (k==(Aclass__Cvirtual)) {
			Aemmiter__add_virtual(__this, mb);
			Aemmiter__gen_virtual_caller(__this, mb);
			string__set(str,(var)(__string_Aemmiter326+ 2));
			string__add(str,Amember__get_name_string(mb));
			Aemmiter__gen_method_decl(__this, _this->_head,_this->class_name,str,mb,k);
			_this->_headl=string__length(_this->_head);
			_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter327+ 2));
			Aemmiter__gen_method_decl(__this, _this->_data,_this->class_name,str,mb,k);
			_this->_datal=string__length(_this->_data);
			Aemmiter__add_to_data(__this, (var)(__string_Aemmiter328+ 2));
		} else {
			Aemmiter__gen_method_decl(__this, _this->_head,_this->class_name,Amember__get_name_string(mb),mb,k);
			_this->_headl=string__length(_this->_head);
			_this->_headl=string__add_at(_this->_head,_this->_headl,(var)(__string_Aemmiter329+ 2));
			Aemmiter__gen_method_decl(__this, _this->_data,_this->class_name,Amember__get_name_string(mb),mb,k);
			_this->_datal=string__length(_this->_data);
			Aemmiter__add_to_data(__this, (var)(__string_Aemmiter330+ 2));
		}
		vars=Amember__get_vars(mb);
		body=Amember__get_body(mb);
		if (body!=0) {
			Aemmiter__body_gen(__this, mb,k,vars,body);
		}
	}
	return 0;
}
var Aemmiter__pass_4(var __this, var str, var mb, var k)
{
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	return 0;
}
var Aemmiter__error(var __this, var t, var e)
{
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	if (t!=0) {
		console__log_str(Atoken__get_file(t));
		console__log_str((var)(__string_Aemmiter331+ 2));
		console__log_int(Atoken__get_line(t));
		console__log_str((var)(__string_Aemmiter332+ 2));
		console__log_str(Atoken__get_data(t));
		console__log_str((var)(__string_Aemmiter333+ 2));
	}
	console__log(e);
	Aemmiter__dump(__this);
	std__exit(-(1));
	return 0;
}
var Aemmiter__dump(var __this)
{
	struct Aemmiter *_this;
	_this = (void*)__this;
	(void)_this;

	return 0;
}
var virtual__dispose(var __this)
{
	var cid;
	cid = ((var*)__this)[-1];
	switch (cid) {
	case Amember___DcidD:
		return Amember___V_dispose(__this);
	case Aemmiter___DcidD:
		return Aemmiter___V_dispose(__this);
	case Aexpr___DcidD:
		return Aexpr___V_dispose(__this);
	case string___DcidD:
		return string___V_dispose(__this);
	case buffer___DcidD:
		return buffer___V_dispose(__this);
	case array___DcidD:
		return array___V_dispose(__this);
	case hash___DcidD:
		return hash___V_dispose(__this);
	case Alexer___DcidD:
		return Alexer___V_dispose(__this);
	case Atoken___DcidD:
		return Atoken___V_dispose(__this);
	case Aparser___DcidD:
		return Aparser___V_dispose(__this);
	case Aclass___DcidD:
		return Aclass___V_dispose(__this);
	case response___DcidD:
		return response___V_dispose(__this);
	case file___DcidD:
		return file___V_dispose(__this);
	case Avirtual___DcidD:
		return Avirtual___V_dispose(__this);
	case Astatement___DcidD:
		return Astatement___V_dispose(__this);
	default:
		std__panic();
	}
	return 0;
}
