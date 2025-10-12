#include <stdlib.h>
#include <string.h>

typedef struct Schema {
    char tableName[64];

    int nodeCount;
    struct Node *node;

    char* keys[];
} Schema;

typedef struct Database {
    char name[64];
    union Tree *trees;
} Database;

struct Branch {
    struct Branch *nextBranch;
    int leafCount;
    struct Leaf *leaf;
};

struct Leaf {
    char key[255];
    char *value;
    struct Leaf *left;
};

struct Node {
    struct Node *up_node;
    struct Node *down_node;
    struct Branch *firstBranch;
    char path[255];
    char nodeName[64]; 
};

union Tree {
    struct Node node;
    char tableName[64];
};

Database *newDatabase(char databaseName[64]);
void createTable(Database *database, char tableName[64], int nodeCount, struct Node *node, char* keys[]);