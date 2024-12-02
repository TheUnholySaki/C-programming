#include <stdio.h>

// 2
static int local_variable;

//3
int global_variable;

// 3
static float const perm_storage_variable;


static int my_function(void){
    return 0;
}

// 1
void temp_storage_var(void) {
    int this_is_the_answer;
}

int main() {
    register int a = 0x1;
    return 0;
}
