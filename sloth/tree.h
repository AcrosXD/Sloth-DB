#include "sloth.h"

typedef struct Node Node;
typedef struct Branch Branch;
typedef struct Leaf Leaf;
typedef union Tree Tree;

void addTree(Database *database, char tableName[64], Schema schema);
