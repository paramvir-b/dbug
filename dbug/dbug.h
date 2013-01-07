/******************************************************************************
 *									      *
 *				   N O T I C E				      *
 *									      *
 *		      Copyright Abandoned, 1987, Fred Fish		      *
 *									      *
 *									      *
 *	This previously copyrighted work has been placed into the  public     *
 *	domain	by  the  author  and  may be freely used for any purpose,     *
 *	private or commercial.						      *
 *									      *
 *	Because of the number of inquiries I was receiving about the  use     *
 *	of this product in commercially developed works I have decided to     *
 *	simply make it public domain to further its unrestricted use.	I     *
 *	specifically  would  be  most happy to see this material become a     *
 *	part of the standard Unix distributions by AT&T and the  Berkeley     *
 *	Computer  Science  Research Group, and a standard part of the GNU     *
 *	system from the Free Software Foundation.			      *
 *									      *
 *	I would appreciate it, as a courtesy, if this notice is  left  in     *
 *	all copies and derivative works.  Thank you.			      *
 *									      *
 *	The author makes no warranty of any kind  with	respect  to  this     *
 *	product  and  explicitly disclaims any implied warranties of mer-     *
 *	chantability or fitness for any particular purpose.		      *
 *									      *
 ******************************************************************************
 */


/*
 *  FILE
 *
 *	dbug.c	 runtime support routines for dbug package
 *
 *  SCCS
 *
 *	@(#)dbug.c	1.28-beta	01/02/13
 *
 *      Code Location: https://github.com/paramvir-b/dbug
 *
 *  DESCRIPTION
 *
 *	These are the runtime support routines for the dbug package.
 *	The dbug package has two main components; the user include
 *	file containing various macro definitions, and the runtime
 *	support routines which are called from the macro expansions.
 *
 *	Externally visible functions in the runtime support module
 *	use the naming convention pattern "_db_xx...xx_", thus
 *	they are unlikely to collide with user defined function names.
 *
 *  AUTHOR(S)
 *
 *	Fred Fish		(base code)
 *	Enhanced Software Technologies, Tempe, AZ
 *	asuvax!mcdphx!estinc!fnf
 *
 *	Binayak Banerjee	(profiling enhancements)
 *	seismo!bpa!sjuvax!bbanerje
 *
 *	Michael Widenius:
 *	DBUG_DUMP	- To dump a pice of memory.
 *	PUSH_FLAG "O"	- To be used insted of "o" if we don't
 *			  want flushing (for slow systems)
 *	PUSH_FLAG "A"	- as 'O', but we will append to the out file instead
 *			  of creating a new one.
 *	Check of malloc on entry/exit (option "S")
 *
 *	Paramvir Bali           Made it compilable on OSX
 *	Paramvir Bali           Fixed C types so that code is more portable
 *	Paramvir Bali           Added check for FALSE macro to make code more portable
 *	Paramvir Bali           Added define for __attribute__ to make code more portable
 */

#ifndef _dbug_h
#define _dbug_h

#include <stdio.h>
#include <sys/types.h>

/* GNU specific features */
#ifdef __GNUC__
#    ifdef HAVE_ANSIDECL_H
#        include <ansidecl.h>
#    endif
/**
 * ATTRIBUTE_UNUSED:
 *
 * Macro used to signal to GCC unused function parameters
 */
#    ifndef ATTRIBUTE_UNUSED
#        define ATTRIBUTE_UNUSED __attribute__((unused))
#    endif
#else
#    define ATTRIBUTE_UNUSED
#endif

#ifdef	__cplusplus
extern "C"
{
#endif

/* Old compatibility names for C types for dbug to make it C99 compatible.  */
#ifdef ulong
    typedef ulong dbug_ulong;
#else
    typedef unsigned long int dbug_ulong;
#endif

#ifdef uint
    typedef uint dbug_uint;
#else
    typedef unsigned int dbug_uint;
#endif

    extern char _dig_vec[];

#if !defined(DBUG_OFF) && !defined(_lint)
    extern int _db_on_, _no_db_;
    extern FILE *_db_fp_;
    extern char *_db_process_;
    extern int _db_keyword_(const char *keyword);
    extern void _db_setjmp_(void);
    extern void _db_longjmp_(void);
    extern void _db_push_(const char *control);
    extern void _db_pop_(void);
    extern void _db_enter_(const char *_func_, const char *_file_,
	dbug_uint _line_, const char **_sfunc_, const char **_sfile_,
	dbug_uint * _slevel_, char ***);
    extern void _db_return_(dbug_uint _line_, const char **_sfunc_,
	const char **_sfile_, dbug_uint * _slevel_);
    extern void _db_pargs_(dbug_uint _line_, const char *keyword);
    extern void _db_doprnt_(const char *format, ...);
    extern void _db_dump_(dbug_uint _line_, const char *keyword,
	const char *memory, dbug_uint length);
    extern void _db_lock_file(void);
    extern void _db_unlock_file(void);

/* Predifined log strings */
#define DBUG_FATAL_STR  "[FATAL]"
#define DBUG_ERROR_STR  "[ERROR]"
#define DBUG_WARN_STR   "[WARN ]"
#define DBUG_INFO_STR   "[info ]"
#define DBUG_ARGS_STR   "[args ]"
#define DBUG_DEBUG_STR  "[debug]"
#define DBUG_TRACE_STR  "[trace]"

/* Predifned log check strings */
#define DBUG_FATAL_CHECK  "fatal"
#define DBUG_ERROR_CHECK  "error"
#define DBUG_WARN_CHECK   "warn"
#define DBUG_INFO_CHECK   "info"
#define DBUG_ARGS_CHECK   "args"
#define DBUG_DEBUG_CHECK  "debug"
#define DBUG_TRACE_CHECK  "trace"
#define DBUG_ALL_CHECK    "*"

#define DBUG_ENTER_EX(a) const char *_db_func_, *_db_file_; dbug_uint _db_level_; \
	char **_db_framep_; \
	_db_enter_ (a,__FILE__,__LINE__,&_db_func_,&_db_file_,&_db_level_, \
		    &_db_framep_)

#if (__STDC_VERSION__ >= 199901L)
#    define DBUG_ENTER(a) DBUG_ENTER_EX(__func__)
#else
#    define DBUG_ENTER(a) DBUG_ENTER_EX(a)
#endif

#define DBUG_LEAVE \
	(_db_return_ (__LINE__, &_db_func_, &_db_file_, &_db_level_))
#define DBUG_RETURN(a1) {DBUG_LEAVE; return(a1);}
#define DBUG_VOID_RETURN {DBUG_LEAVE; return;}
#define DBUG_EXECUTE(keyword,a1) \
	{if (_db_on_) {if (_db_keyword_ (keyword)) { a1 }}}
#define DBUG_PRINT(keyword,arglist) \
	{if (_db_on_) {_db_pargs_(__LINE__,keyword); _db_doprnt_ arglist;}}
/* Predifined print strings for consistency and ease of use*/
#define DBUG_FATAL(arglist) DBUG_PRINT(DBUG_FATAL_STR, arglist) 
#define DBUG_ERROR(arglist) DBUG_PRINT(DBUG_ERROR_STR, arglist) 
#define DBUG_WARN(arglist) DBUG_PRINT(DBUG_WARN_STR, arglist) 
#define DBUG_INFO(arglist) DBUG_PRINT(DBUG_INFO_STR, arglist) 
#define DBUG_DEBUG(arglist) DBUG_PRINT(DBUG_DEBUG_STR, arglist) 
#define DBUG_TRACE(arglist) DBUG_PRINT(DBUG_TRACE_STR, arglist) 
#define DBUG_ARGS(arglist) DBUG_PRINT(DBUG_ARGS_STR, arglist) 
#define DBUG_PUSH(a1) _db_push_ (a1)
#define DBUG_POP() _db_pop_ ()
#define DBUG_PROCESS(a1) (_db_process_ = a1)
#define DBUG_FILE (_db_fp_)
#define DBUG_SETJMP(a1) (_db_setjmp_ (), setjmp (a1))
#define DBUG_LONGJMP(a1,a2) (_db_longjmp_ (), longjmp (a1, a2))
#define DBUG_DUMP(keyword,a1,a2)\
	{if (_db_on_) {_db_dump_(__LINE__,keyword,a1,a2);}}
#define DBUG_IN_USE (_db_fp_ && _db_fp_ != stderr)
#define DEBUGGER_OFF _no_db_=1;_db_on_=0;
#define DEBUGGER_ON  _no_db_=0
#define DBUG_my_pthread_mutex_lock_FILE { _db_lock_file(); }
#define DBUG_my_pthread_mutex_unlock_FILE { _db_unlock_file(); }
#define DBUG_ASSERT(A) assert(A)

/* Define defaults. Override these in your code, if not overridden it will default to below */
#ifndef DBUG_DEFAULT_DEBUG_CTRL_STR
#    define DBUG_DEFAULT_DEBUG_CTRL_STR   DBUG_WARN_CHECK
#endif

#else							   /* No debugger */

#define DBUG_ENTER(a1)
#define DBUG_ENTER_EX(a1)
#define DBUG_RETURN(a1) return(a1)
#define DBUG_VOID_RETURN return
#define DBUG_EXECUTE(keyword,a1) {}
#define DBUG_PRINT(keyword,arglist) {}
#define DBUG_FATAL(arglist)
#define DBUG_ERROR(arglist)
#define DBUG_WARN(arglist)
#define DBUG_INFO(arglist)
#define DBUG_DEBUG(arglist)
#define DBUG_TRACE(arglist)
#define DBUG_ARGS(arglist)
#define DBUG_PUSH(a1) {}
#define DBUG_POP() {}
#define DBUG_PROCESS(a1) {}
#define DBUG_FILE (stderr)
#define DBUG_SETJMP setjmp
#define DBUG_LONGJMP longjmp
#define DBUG_DUMP(keyword,a1,a2) {}
#define DBUG_IN_USE 0
#define DEBUGGER_OFF
#define DEBUGGER_ON
#define DBUG_my_pthread_mutex_lock_FILE
#define DBUG_my_pthread_mutex_unlock_FILE
#define DBUG_ASSERT(A) {}
#endif
#ifdef	__cplusplus
}
#endif
#endif
