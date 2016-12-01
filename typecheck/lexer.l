%option yylineno
%pointer
L           [a-zA-Z_]


%{
    #include <cstdlib>
    #include <cstring>
    #include "ast.hpp"
    #include "parser.hpp"

    /* void yyerror(const char *); */
%}



/** The example below is very simple, but it shows almost everything you will
 *  need to do for this first part. The syntax is as follows:
 *
 *  regular_expression      {  c code  }
 *
 * The lexer will try to match each regular expression. When it does it will
 * execute the corresponding C code.
*/

%x COMMENT

%%

"procedure"	{  return T_proc;}
"return"		{ return T_return;}
"var"			{return T_var;}
\;			{return T_semiCol;}
\:			{ return T_col;}
\|			{ return T_pipe;}
\,			{ return T_comma;}

\{			{return T_openCurly;}
\}			{ return T_closeCurly;}
\[			{ return T_openBracket;}
\]			{ return T_closeBracket;}
\(			{ return T_openParen;}
\)			{ return T_closeParen;}

\&\&		{ return T_and;}
\|\|		{ return T_or;}
\!			{ return T_not;}
\=\=			{ return T_isEq;}
\<\=			{ return T_lessOrEq;}
\>\=			{ return T_greatOrEq;}
\<			{ return T_less;}
\>			{ return T_great;}
\!\=			{ return T_notEq;}

"boolean"		{ return T_bool_type;}
"char" 		{ return T_char_type;}
"integer"		{ return T_int_type;}

"intptr"		{ return T_intptr_type;}
"charptr"		{ return T_charptr_type;}

"null"		{ yylval.u_base_int = 0; return T_null;}
\&			{ return T_addr;}
\^			{ return T_deRef;}

"if" 			{ return T_if;}
"else" 		{ return T_else;}
"while" 		{ return T_while;}

"true"		{ yylval.u_base_int = 1; return T_true;}
"false"		{ yylval.u_base_int = 0;return T_false;}

\*			{ return T_times;}
\/			{ return T_divide;}
\+			{ return T_plus;}
\-			{ return T_minus;}
\%			{ return T_mod;}
\=			{ return T_assign;}

"string"		{ return T_string_type;}

0|[1-9][0-9]*        	 	{  yylval.u_base_int = (int)strtol(yytext, 0, 10); return T_num_dec; }	//integer
0[0-7]*					    { yylval.u_base_int = (int)strtol(yytext, 0, 8);return T_num_oct;} //octal
0[xX][0-9|A-F][0-9|A-F]*	{ yylval.u_base_int = (int)strtol(yytext, 0, 16); return T_num_hex;}	//hexidecimal
[0|1][0|1]*b 				{ yylval.u_base_int = (int)strtol(yytext, 0, 2); return T_num_bin;}	//binary
'[[:print:]]'				{ yylval.u_base_int = (int)yytext[1]; return T_char;}

[a-zA-Z][a-zA-Z0-9]*	{ yylval.u_base_charptr = strdup(yytext); return T_identifier;}

[ \t\n  ]        {}      /* skip whitespace */

[\"][^\"]*[\"]          {
                            yytext[strlen(yytext)-1] = 0;
                            yytext++;
                            yylval.u_base_charptr = strdup(yytext);
                            return(T_string);
                        }

"\/\%"	{ 	printf("commentStart ");
			BEGIN(COMMENT);
		}


<COMMENT>"%\/"  { 	printf(" commentFinished ");
					BEGIN(INITIAL);
                }

<COMMENT>[.\n\t ]*		{; }

%%

/**
.       yyerror((char *) "invalid character");
L?\"(\\.|[^\\"])*\" { yylval.u_base_charptr = strdup(yytext); return(T_string); }
You shall not pass!
 *  You should not  have to do or edit anything past this.
 */

int yywrap(void) {
    return 1;
}
