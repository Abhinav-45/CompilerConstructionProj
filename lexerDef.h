/*
 * Group Number: 1
 * Group Members:
 * Member 1 ID: 2026A7PS0001P Name: John Doe
 * Member 2 ID: 2026A7PS0002P Name: Jane Doe
 */

#ifndef LEXERDEF_H
#define LEXERDEF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 50

/* Enumeration of all Token Types as per Language Specifications */
typedef enum {
    TK_ASSIGNOP, TK_COMMENT, TK_FIELDID, TK_ID, TK_NUM, TK_RNUM,
    TK_FUNID, TK_RUID, TK_WITH, TK_PARAMETERS, TK_END, TK_WHILE,
    TK_UNION, TK_ENDUNION, TK_DEFINETYPE, TK_AS, TK_TYPE, TK_MAIN,
    TK_GLOBAL, TK_PARAMETER, TK_LIST, TK_SQL, TK_SQR, TK_INPUT,
    TK_OUTPUT, TK_INT, TK_REAL, TK_COMMA, TK_SEM, TK_COLON, TK_DOT,
    TK_ENDWHILE, TK_OP, TK_CL, TK_IF, TK_THEN, TK_ENDIF, TK_READ,
    TK_WRITE, TK_RETURN, TK_PLUS, TK_MINUS, TK_MUL, TK_DIV, TK_CALL,
    TK_RECORD, TK_ENDRECORD, TK_ELSE, TK_AND, TK_OR, TK_NOT, TK_LT,
    TK_LE, TK_EQ, TK_GT, TK_GE, TK_NE, TK_ERROR, TK_EOF
} TokenType;

extern const char *TokenStr[];

/* Token Information Structure */
typedef struct {
    char lexeme[64]; // Max identifier length is 30, so 64 is safe
    TokenType tokenType;
    int lineNo;
} token_info;

typedef token_info* tokenInfo;

/* Twin Buffer Structure for File I/O */
struct TwinBufferStruct {
    char buf1[BUFFER_SIZE];
    char buf2[BUFFER_SIZE];
    int currentBuff; // 1 for buf1, 2 for buf2
    unsigned int forward;
    unsigned int bytesRead1;
    unsigned int bytesRead2;
    FILE *fp;
    bool eof_reached;
};

// Pointer to TwinBufferStruct
typedef struct TwinBufferStruct* twinBuffer;

#endif
