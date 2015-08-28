#include <stdio.h>
#include <string.h>
#include "my.h"
#include <CUnit/Basic.h>

static FILE* temp_file = NULL;

int init_suite1(void){
    if(NULL == (temp_file = fopen("temp.txt", "w+"))){
        return -1;
    } else {
        return 0;
    }
}

int clean_suite1(void){
    if (0 != fclose(temp_file)){
        return -1;
    } else {
        temp_file = NULL;
        return 0;
    }
}

void testMY_CHAR(void){
    char c = 'c';

    if(temp_file != NULL){
        CU_ASSERT(my_char(c) == 1);
    }
}

void testMY_STR(void){

}


int main(int argc, char** args){
    CU_pSuite pSuite = NULL;

    if(CU_initialize_registry() != CUE_SUCCESS)
        return CU_get_error();

    pSuite = CU_add_suite("Suite1", init_suite1, clean_suite1);
    if(pSuite == NULL){
        CU_cleanup_registry();
        return CU_get_error();
    }

    if((CU_add_test(pSuite, "test of my_char", testMY_CHAR) == NULL)){
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
