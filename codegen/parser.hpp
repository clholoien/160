/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_comma = 258,
     T_assign = 259,
     T_or = 260,
     T_and = 261,
     T_isEq = 262,
     T_notEq = 263,
     T_less = 264,
     T_lessOrEq = 265,
     T_great = 266,
     T_greatOrEq = 267,
     T_minus = 268,
     T_plus = 269,
     T_mod = 270,
     T_divide = 271,
     T_times = 272,
     T_not = 273,
     T_deRef = 274,
     T_addr = 275,
     T_openCurly = 276,
     T_closeCurly = 277,
     T_openBracket = 278,
     T_closeBracket = 279,
     T_openParen = 280,
     T_closeParen = 281,
     T_true = 282,
     T_false = 283,
     T_string = 284,
     T_char = 285,
     T_num_oct = 286,
     T_num_bin = 287,
     T_num_hex = 288,
     T_num_dec = 289,
     T_null = 290,
     T_if = 291,
     T_else = 292,
     T_while = 293,
     T_bool_type = 294,
     T_char_type = 295,
     T_int_type = 296,
     T_string_type = 297,
     T_intptr_type = 298,
     T_charptr_type = 299,
     T_proc = 300,
     T_return = 301,
     T_var = 302,
     T_identifier = 303,
     T_col = 304,
     T_semiCol = 305,
     T_pipe = 306
   };
#endif
/* Tokens.  */
#define T_comma 258
#define T_assign 259
#define T_or 260
#define T_and 261
#define T_isEq 262
#define T_notEq 263
#define T_less 264
#define T_lessOrEq 265
#define T_great 266
#define T_greatOrEq 267
#define T_minus 268
#define T_plus 269
#define T_mod 270
#define T_divide 271
#define T_times 272
#define T_not 273
#define T_deRef 274
#define T_addr 275
#define T_openCurly 276
#define T_closeCurly 277
#define T_openBracket 278
#define T_closeBracket 279
#define T_openParen 280
#define T_closeParen 281
#define T_true 282
#define T_false 283
#define T_string 284
#define T_char 285
#define T_num_oct 286
#define T_num_bin 287
#define T_num_hex 288
#define T_num_dec 289
#define T_null 290
#define T_if 291
#define T_else 292
#define T_while 293
#define T_bool_type 294
#define T_char_type 295
#define T_int_type 296
#define T_string_type 297
#define T_intptr_type 298
#define T_charptr_type 299
#define T_proc 300
#define T_return 301
#define T_var 302
#define T_identifier 303
#define T_col 304
#define T_semiCol 305
#define T_pipe 306




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

