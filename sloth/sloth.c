#include "sloth.h"
#include "tree.h"

Database *newDatabase(char databaseName[64]){
    Database *database;

    database = malloc(sizeof(Database));

    strcpy_s(database->name, 64, databaseName);
    //database->trees = malloc(sizeof(Tree));

    return database;
}

void createTable(Database *database, char tableName[64], int nodeCount, struct Node *node, char* keys[]){
    Schema schema = {
        .node = node,
        .nodeCount = nodeCount
    };
    strcpy_s(schema.tableName, 64, tableName);
    memcpy(schema.keys, keys, nodeCount);
    addTree(database, tableName, schema);
}