#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sloth/sloth.h"

int main(){

    struct Table table = createTable("usersTable", 3, "username", "email", "password");
    printf("DEBUG"); 

    return 0;
}