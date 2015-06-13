dbug
====

Modified version of debug library written by Fred Fish. Add some more features.

DEPENDENCIES
============

* `make` to run the sample code
* c99 compatible compiler like gcc, xlc etc.

UNDER DEVELOPMENT
=================

For time being refer to

http://www.tol.it/doc/MySQL/appendixC.html


Whats New
=========

* Code is more portable as its been tested/fixed on multiple compilers and operating systems 
* If you using C99 standards you can use DBUG_ENTER without passing any arguments (See Sample.c)
* Added support for log levels like info, warn, error etc.

Sample Output
=============

<pre>
DBUG_OPTS=d=trace:t:o:L:i:n:N:P:g
50930:     1: sample:    50:    1: &gt;MAIN
50930:     2: sample:    52:    1: | TRACE: This is a trace message
50930:     3: sample:    53:    1: | DEBUG: This is a debug message
50930:     4: sample:    54:    1: | DEBUG1: This is a debug message
50930:     5: sample:    55:    1: | DEBUG2: This is a debug message
50930:     6: sample:    56:    1: | INFO: This is an info message
50930:     7: sample:    57:    1: | WARN: This is a warn message
50930:     8: sample:    58:    1: | ERROR: This is an error message
50930:     9: sample:    59:    1: | FATAL: This is a fatal message
50930:    10: sample:    23:    2: | &gt;TESTFUNCTION
50930:    11: sample:    25:    2: | | ARGS: arg1=3 arg2=6
50930:    12: sample:     6:    3: | | &gt;TESTFUNCTION_2
50930:    13: sample:     8:    3: | | | ARGS: arg1=7 arg2=9 arg3=100
50930:    14: sample:    10:    3: | | | TRACE: This is a trace message
50930:    15: sample:    11:    3: | | | DEBUG: This is a debug message
50930:    16: sample:    12:    3: | | | DEBUG1: This is a debug message
50930:    17: sample:    13:    3: | | | DEBUG2: This is a debug message
50930:    18: sample:    14:    3: | | | INFO: This is an info message
50930:    19: sample:    15:    3: | | | WARN: This is a warn message
50930:    20: sample:    16:    3: | | | ERROR: This is an error message
50930:    21: sample:    17:    3: | | | FATAL: This is a fatal message
50930:    22: sample:    19:    3: | | &lt;TESTFUNCTION_2
50930:    23: sample:    28:    2: | | TRACE: This is a trace message
50930:    24: sample:    29:    2: | | DEBUG: This is a debug message
50930:    25: sample:    30:    2: | | DEBUG1: This is a debug message
50930:    26: sample:    31:    2: | | DEBUG2: This is a debug message
50930:    27: sample:    32:    2: | | INFO: This is an info message
50930:    28: sample:    33:    2: | | WARN: This is a warn message
50930:    29: sample:    34:    2: | | ERROR: This is an error message
50930:    30: sample:    35:    2: | | FATAL: This is a fatal message
50930:    31: sample:    37:    2: | &lt;TESTFUNCTION
50930:    32: sample:    63:    1: &lt;MAIN

</pre>

Another one:

<pre>
DBUG_OPTS=d=trace:o:L:i:n:N:P:g
 7490:     1: ./sample:    55:    1: main: TRACE: This is a trace message
 7490:     2: ./sample:    56:    1: main: DEBUG: This is a debug message
 7490:     3: ./sample:    57:    1: main: DEBUG2: This is a debug message
 7490:     4: ./sample:    58:    1: main: INFO : This is an info message
 7490:     5: ./sample:    59:    1: main: WARN : This is a warn message
 7490:     6: ./sample:    60:    1: main: ERROR: This is an error message
 7490:     7: ./sample:    61:    1: main: FATAL: This is a fatal message
 7490:     8: ./sample:    29:    2: testFunction: ARGS : arg1=3 arg2=6
 7490:     9: ./sample:    13:    3: testFunction_2: ARGS : arg1=7 arg2=9 arg3=100
 7490:    10: ./sample:    15:    3: testFunction_2: TRACE: This is a trace message
 7490:    11: ./sample:    16:    3: testFunction_2: DEBUG: This is a debug message
 7490:    12: ./sample:    17:    3: testFunction_2: DEBUG1: This is a debug message
 7490:    13: ./sample:    18:    3: testFunction_2: INFO : This is an info message
 7490:    14: ./sample:    19:    3: testFunction_2: WARN : This is a warn message
 7490:    15: ./sample:    20:    3: testFunction_2: ERROR: This is an error message
 7490:    16: ./sample:    21:    3: testFunction_2: FATAL: This is a fatal message
 7490:    17: ./sample:    32:    2: testFunction: TRACE: This is a trace message
 7490:    18: ./sample:    33:    2: testFunction: DEBUG: This is a debug message
 7490:    19: ./sample:    34:    2: testFunction: DEBUG2: This is a debug message
 7490:    20: ./sample:    35:    2: testFunction: INFO : This is an info message
 7490:    21: ./sample:    36:    2: testFunction: WARN : This is a warn message
 7490:    22: ./sample:    37:    2: testFunction: ERROR: This is an error message
 7490:    23: ./sample:    38:    2: testFunction: FATAL: This is a fatal message
</pre>
