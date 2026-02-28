/*
 * Group Number: 1
 * Group Members:
 * Member 1 ID: 2026A7PS0001P Name: John Doe
 * Member 2 ID: 2026A7PS0002P Name: Jane Doe
 */

#include "lexer.h"
#include <time.h>

void printTokens(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Could not open file %s\n", filename);
        return;
    }
    twinBuffer B = initBaseBuffer(fp);
    tokenInfo ti;
    while (1) {
        ti = getNextToken(B);
        if (ti->tokenType == TK_EOF) {
            free(ti);
            break;
        }
        if (ti->tokenType != TK_ERROR) {
            printf("Line no. %d\t Lexeme %s\t\tToken %s\n", ti->lineNo, ti->lexeme, TokenStr[ti->tokenType]);
        }
        free(ti);
    }
    fclose(fp);
    free(B);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./stage1exe testcase.txt parsetreeOutFile.txt\n");
        return 1;
    }
    
    int option;
    while(1) {
        printf("\n0: Exit\n1: Remove Comments\n2: Print Token List\n3: Parse\n4: Time taken\nEnter option: ");
        if (scanf("%d", &option) != 1) break;
        
        switch(option) {
            case 0: return 0;
            case 1:
                removeComments(argv[1], "cleanFile.txt");
                printf("Comments removed. Check cleanFile.txt\n");
                break;
            case 2:
                printTokens(argv[1]);
                break;
            case 3:
                printf("Parser not yet implemented.\n");
                break;
            case 4:
                {
                    clock_t start_time, end_time;
                    double total_CPU_time, total_CPU_time_in_seconds;
                    start_time = clock();
                    printTokens(argv[1]);
                    end_time = clock();
                    total_CPU_time = (double) (end_time - start_time);
                    total_CPU_time_in_seconds = total_CPU_time / CLOCKS_PER_SEC;
                    printf("Total CPU time: %f ticks / %f seconds\n", total_CPU_time, total_CPU_time_in_seconds);
                }
                break;
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}
