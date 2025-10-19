struct Table {
    char tableName[255];
    struct Row *head;
};

struct Row {
    struct Column *column;
    struct Row *next_row;
};

struct Column {
    char key[255];
    char *value;

    struct Column *next_column;
};

struct Table createTable(const char *tableName, unsigned int fieldNumber, ...);