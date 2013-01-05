/*
 * This is a sample file to show how to use dbug library
 *
 * Code Location: https://github.com/paramvir-b/dbug
 *
*/
#include <stdlib.h>
#include "../dbug/dbug.h"

void testFunction_2(int arg1, int arg2, int arg3) {
    DBUG_ENTER("TESTFUNCTION_2");

    DBUG_ARGS(("arg1=%d arg2=%d arg3=%d", arg1, arg2, arg3));

    DBUG_TRACE(("This is a trace message"));
    DBUG_DEBUG(("This is a debug message"));
    DBUG_PRINT("DEBUG1", ("This is a debug message"));
    DBUG_INFO(("This is an info message"));
    DBUG_WARN(("This is a warn message"));
    DBUG_ERROR(("This is an error message"));
    DBUG_FATAL(("This is a fatal message"));

    DBUG_VOID_RETURN;
}

void testFunction(int arg1, int arg2) {
    DBUG_ENTER("TESTFUNCTION");

    DBUG_ARGS(("arg1=%d arg2=%d", arg1, arg2));

    testFunction_2(7, 9, 100);
    DBUG_TRACE(("This is a trace message"));
    DBUG_DEBUG(("This is a debug message"));
    DBUG_PRINT("DEBUG2", ("This is a debug message"));
    DBUG_INFO(("This is an info message"));
    DBUG_WARN(("This is a warn message"));
    DBUG_ERROR(("This is an error message"));
    DBUG_FATAL(("This is a fatal message"));

    DBUG_VOID_RETURN;
}

int main(int argc, char** argv) {
    char *dbug_opts = NULL;
    /* In C89 has to be the first line of code after declaration of variable as it declares variables */
    DBUG_ENTER("MAIN");
    DBUG_PROCESS(argv[0]);

    dbug_opts = getenv("DBUG_OPTS");
    if(dbug_opts){
        printf("DBUG_OPTS=%s\n", dbug_opts);
        DBUG_PUSH(dbug_opts);
    }


    DBUG_TRACE(("This is a trace message"));
    DBUG_DEBUG(("This is a debug message"));
    DBUG_PRINT("DEBUG2", ("This is a debug message"));
    DBUG_INFO(("This is an info message"));
    DBUG_WARN(("This is a warn message"));
    DBUG_ERROR(("This is an error message"));
    DBUG_FATAL(("This is a fatal message"));

    testFunction(3, 6);

    DBUG_RETURN(0);
}
