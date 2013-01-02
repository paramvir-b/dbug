/* UNDER DEVELOPMENT */
#include <stdlib.h>
#include "../dbug/dbug.h"

void testFunction(int arg1, int arg2) {
    DBUG_ENTER("TESTFUNCTION");

    DBUG_PRINT("ARGS", ("arg1=%d arg2=%d", arg1, arg2));

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

    DBUG_PROCESS(argv[0]);

    char *dbug_opts = getenv("DBUG_OPTS");
    if(dbug_opts){
        printf("DBUG_OPTS=%s\n", dbug_opts);
        DBUG_PUSH(dbug_opts);
    }

    DBUG_ENTER("MAIN");

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
