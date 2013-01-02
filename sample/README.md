Usage
=====

For running the test:

`export CC=gcc; make clean test`

If no error occurred and you saw something like:

<pre>
DBUG_OPTS=d:t:o:L:i:n:N:P:g
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


everything is good. The output above is the output from the usage of dbug library in the sample app. You can look into the Sample.c on how to use dbug library.
