/*
 * Group Number: 1
 * Group Members:
 * Member 1 ID: 2026A7PS0001P Name: John Doe
 * Member 2 ID: 2026A7PS0002P Name: Jane Doe
 */

#ifndef LEXER_H
#define LEXER_H

#include "lexerDef.h"

/*
 * This function takes the input from the file pointed to by 'fp'.
 * It populates twin buffer by bringing the fixed sized piece of source code into the memory.
 * It maintains the file pointer after every access.
 */
FILE *getStream(FILE *fp);

/* Helper to initialize the twin buffer structure */
twinBuffer initBaseBuffer(FILE *fp);

/*
 * This function reads the input character stream and uses efficient mechanism to recognize lexemes.
 * It returns all relevant information it collects in this phase encapsulated as tokenInfo.
 */
tokenInfo getNextToken(twinBuffer B);

/*
 * This function takes as input the source code and writes the clean code without comments.
 */
void removeComments(char *testcaseFile, char *cleanFile);

#endif
