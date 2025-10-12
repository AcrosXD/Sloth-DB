 #include "tree.h"
 #include "tools/utils.h"

Leaf *createLeaf(Branch *branch, char key[255], char* value){
    Leaf *leaf = malloc(sizeof(Leaf));

    leaf = calloc(1, sizeof(Leaf));

    strcpy_s(leaf->key, 255, key);
    if(value != NULL){
        memcpy(leaf->value, value, strlen(value) + 1);
    }

    return leaf;
}

Branch *createBranch(int leafCount, char* (keys)[]){
    Branch *dataBranch = malloc(sizeof(Branch));
    dataBranch->leafCount = leafCount;

    Leaf *firstLeaf = malloc(sizeof(Leaf));
    Leaf *curr_leaf = firstLeaf;

    memcpy_s(firstLeaf->key, 255, keys[0], 256);
    for (size_t i = 1; i < leafCount; i++){
        curr_leaf = curr_leaf->left;
        memcpy_s(curr_leaf->key, 256, keys[i], 255);
    }

    dataBranch->leaf = firstLeaf;

    return dataBranch;
}

Node createNode(char nodeName[64], Node *up_node, Node *down_node, Branch *firstBranch){
    Node node;

    //node = malloc(sizeof(Node));

    if (up_node != NULL){
        strcpy(node.path, concat(3, up_node, "/", nodeName));
    } else{
        strcpy(node.path, concat(2, "/", nodeName));
    }

    node.down_node = down_node;
    node.up_node = up_node;

    node.firstBranch = firstBranch;

    return node;
}

Tree *createTree(char tableName[64], Node node){
    Tree *tree = malloc(sizeof(Tree));

    tree->node = node;
    strcpy_s(tree->tableName, 64, tableName);

    return tree;
}

void addTree(Database *database, char tableName[64], Schema schema){
    database->trees = calloc(1, sizeof(Tree));                                  

    Node root = createNode(schema.node->nodeName, NULL, &schema.node[0], schema.node[0].firstBranch);
    
    Node *curr_node = &root;
    for (size_t i = 1; i <= schema.nodeCount; i++){
        Node *next_node = &schema.node[i];

        Branch *firstBranch = createBranch(schema.node[i].firstBranch->leafCount, schema.keys);
        schema.node[i] = createNode(schema.node->nodeName, curr_node, (i + 1 < schema.nodeCount) ? &schema.node[i + 1] : NULL, firstBranch);

        // curr_node->down_node = &schema.node[i];
        // curr_node->down_node->up_node = curr_node;
    }

    database->trees = createTree(tableName, root);
}