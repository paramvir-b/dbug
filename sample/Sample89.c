/* UNDER DEVELOPMENT */
#include <stdlib.h>
#include "../dbug/dbug.h"

void testFunction_2(int arg1, int arg2, int arg3) {
    DBUG_ENTER("TESTFUNCTION_2");

    DBUG_PRINT("ARGS", ("arg1=%d arg2=%d arg3=%d", arg1, arg2, arg3));

    DBUG_PRINT("TRACE", ("This is a trace message"));
    DBUG_PRINT("DEBUG", ("This is a debug message"));
    DBUG_PRINT("DEBUG1", ("This is a debug message"));
    DBUG_PRINT("DEBUG2", ("This is a debug message"));
    DBUG_PRINT("INFO", ("This is an info message"));
    DBUG_PRINT("WARN", ("This is a warn message"));
    DBUG_PRINT("ERROR", ("This is an error message"));
    DBUG_PRINT("FATAL", ("This is a fatal message"));

    DBUG_VOID_RETURN;
}

void testFunction(int arg1, int arg2) {
    DBUG_ENTER("TESTFUNCTION");

    DBUG_PRINT("ARGS", ("arg1=%d arg2=%d", arg1, arg2));

    testFunction_2(7, 9, 100);
    DBUG_PRINT("TRACE", ("This is a trace message"));
    DBUG_PRINT("DEBUG", ("This is a debug message"));
    DBUG_PRINT("DEBUG1", ("This is a debug message"));
    DBUG_PRINT("DEBUG2", ("This is a debug message"));
    DBUG_PRINT("INFO", ("This is an info message"));
    DBUG_PRINT("WARN", ("This is a warn message"));
    DBUG_PRINT("ERROR", ("This is an error message"));
    DBUG_PRINT("FATAL", ("This is a fatal message"));

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


    DBUG_PRINT("TRACE", ("This is a trace message"));
    DBUG_PRINT("DEBUG", ("This is a debug message"));
    DBUG_PRINT("DEBUG1", ("This is a debug message"));
    DBUG_PRINT("DEBUG2", ("This is a debug message"));
    DBUG_PRINT("INFO", ("This is an info message"));
    DBUG_PRINT("WARN", ("This is a warn message"));
    DBUG_PRINT("ERROR", ("This is an error message"));
    DBUG_PRINT("FATAL", ("This is a fatal message"));

    testFunction(3, 6);

    DBUG_RETURN(0);
}
