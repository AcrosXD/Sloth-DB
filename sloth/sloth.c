#include "sloth.h"
#include "tree.h"

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

struct Column* endInsertInit(struct Column *column, char key[255]){
    struct Column *endColumn = (struct Column*)malloc(sizeof(struct Column));

    endColumn->value = NULL;
    strcpy_s(endColumn->key, 255, key);
    endColumn->next_column = NULL;

    if(column == NULL){
        return endColumn;
    }                                            

    struct Column *temp = column;
    while(temp->next_column != NULL){
        temp = temp->next_column;
    }
    column->next_column = endColumn;

    return column;
}

struct Table createTable(const char *tableName, unsigned int fieldNumber, ...){
    struct Table table;
    strcpy_s(table.tableName, 255, tableName);

    struct Row *rowTableHead = (struct Row*)malloc(sizeof(struct Row));
    rowTableHead->next_row = NULL;

    struct Column *column = NULL;

    int i = fieldNumber;

    va_list args;
    va_start(args, fieldNumber);

    do {
        column = endInsertInit(column, va_arg(args, char*));
        i--;
    } while(i != 0);

    va_end(args);

    rowTableHead->column = column;
    table.head = rowTableHead;

    return table;
}



