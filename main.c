#include <stdlib.h>
#include <string.h>
#include "sloth/sloth.h"

int main(){
    Database *database = newDatabase("My database");
    
    struct Node *nodes = calloc(2, sizeof(struct Node));
    char* keys[3] = {"name", "email", "password"};

    strcpy(nodes[0].nodeName, "users");
    strcpy(nodes[1].nodeName, "cmd");

    createTable(database, "AWS", 2, nodes, keys);

    return 0;
}