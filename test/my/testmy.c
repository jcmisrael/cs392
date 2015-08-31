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
    char str[] = "test";

    if(temp_file != NULL){
        CU_ASSERT(my_str(str) == 5);
        CU_ASSERT(my_str("") == 1);
        CU_ASSERT(my_str(NULL) == 0);
    }
}

void testMY_INT(void){
    int i = 55;

    if(temp_file != NULL){
        CU_ASSERT(my_int(i) == 2);
        CU_ASSERT(my_int(-i) == 3);
    }
}

void testMY_NUM_BASE(void){
    int i = 123;
    char alpha[] = "0123456789";
    char hex[] = "0123456789ABCDEF";

    if(temp_file != NULL){
        CU_ASSERT_STRING_EQUAL(my_num_base(i, alpha), "123");
        CU_ASSERT_STRING_EQUAL(my_num_base(i, hex), "7B");
        CU_ASSERT_STRING_EQUAL(my_num_base(-i, alpha), "-123");
        CU_ASSERT_STRING_EQUAL(my_num_base(i, NULL), "");
    }
}

void testMY_STRLEN(void){
    char str[] = "test";

    if(temp_file != NULL){
        CU_ASSERT(my_strlen(str) == 4);
        CU_ASSERT(my_strlen("") == 0);
        CU_ASSERT(my_strlen(NULL) == 0);
    }
}

void testMY_REVSTR(void){
    char* str = (char*)xmalloc(5 * sizeof(char));
    str = "test";

    if(temp_file != NULL){
        CU_ASSERT(my_revstr(str) == 4);
        CU_ASSERT(my_revstr(NULL) == 0);
    }
}

void testMY_STRPOS(void){
    char str[] = "testing";

    if(temp_file != NULL){
        CU_ASSERT(my_strpos(str, 'g') == 6);
        CU_ASSERT(my_strpos(NULL, 'g') == -1);
        CU_ASSERT(my_strpos(str, 'q') == -1);
        CU_ASSERT(my_strpos(str, 't') == 0);
    }
}

void testMY_STRRPOS(void){
    char str[] = "testing";

    if(temp_file != NULL){
        CU_ASSERT(my_strrpos(str, 'g') == 6);
        CU_ASSERT(my_strrpos(NULL, 'g') == -1);
        CU_ASSERT(my_strrpos(str, 'q') == -1);
        CU_ASSERT(my_strrpos(str, 't') == 3);
    }
}

void testMY_STRDUP(void){
    char* str;

    if(temp_file != NULL){
        str = my_strdup("testing");
        CU_ASSERT_STRING_EQUAL_FATAL(str, "testing");
        free(str);
        str = my_strdup(NULL);
        CU_ASSERT_FATAL(str == NULL);
    }
}

void testMY_STRCMP(void){
    if(temp_file != NULL){
        CU_ASSERT(my_strcmp("testing", "testing") == 0);
        CU_ASSERT(my_strcmp("Testing", "testing") > 0);
        CU_ASSERT(my_strcmp("testing", "Testing") < 0);
        CU_ASSERT(my_strcmp(NULL, NULL) == 0);
        CU_ASSERT(my_strcmp("testing", NULL) > 0);
        CU_ASSERT(my_strcmp(NULL, "testing") < 0);
        CU_ASSERT(my_strcmp("test", "testing") < 0);
        CU_ASSERT(my_strcmp("testing", "test") > 0);
    }
}

void testMY_STRNCMP(void){
    if(temp_file != NULL){
        CU_ASSERT(my_strncmp("testing", "testing", 4) == 0);
        CU_ASSERT(my_strncmp("Testing", "testing", 4) > 0);
        CU_ASSERT(my_strncmp("testing", "Testing", 4) < 0);
        CU_ASSERT(my_strncmp(NULL, NULL, 4) == 0);
        CU_ASSERT(my_strncmp("testing", NULL, 4) > 0);
        CU_ASSERT(my_strncmp(NULL, "testing", 4) < 0);
        CU_ASSERT(my_strncmp("test", "testing", 4) == 0);
        CU_ASSERT(my_strncmp("testing", "test", 4) > 0);
    }
}

void testMY_STRCONCAT(void){
    char* str = NULL;

    if(temp_file != NULL){
        str = my_strconcat("test", "ing");
        CU_ASSERT_STRING_EQUAL(str, "testing");
        free(str);
        str = my_strconcat("test", NULL);
        CU_ASSERT_STRING_EQUAL(str, "test");
        free(str);
        str = my_strconcat(NULL, "ing");
        CU_ASSERT_STRING_EQUAL(str, "ing");
        free(str);
        str = my_strconcat(NULL, NULL);
        CU_ASSERT(str == NULL);
    }
}

void testMY_STRNCONCAT(void){
    char* str = NULL;

    if(temp_file != NULL){
        str = my_strnconcat("test", "ing", 2);
        CU_ASSERT_STRING_EQUAL(str, "testin");
        free(str);
        str = my_strnconcat("test", NULL, 2);
        CU_ASSERT_STRING_EQUAL(str, "test");
        free(str);
        str = my_strnconcat(NULL, "ing", 2);
        CU_ASSERT_STRING_EQUAL(str, "in");
        free(str);
        str = my_strconcat(NULL, NULL);
        CU_ASSERT(str == NULL);
        str = my_strnconcat("testing", " long", 50);
        CU_ASSERT_STRING_EQUAL(str, "testing long");
        free(str);
        str = my_strnconcat("testing", " negative", -51);
        CU_ASSERT_STRING_EQUAL(str, "testing");
        free(str);
    }
}

void testMY_STRCAT(void){
    char* str = NULL;

    if(temp_file != NULL){
        str = (char*)xmalloc((15 + 1) * sizeof(char));
        str[0] = '\0';
        str = my_strcat(str, "test");
        CU_ASSERT_STRING_EQUAL(str, "test");
        str = my_strcat(str, "ing");
        CU_ASSERT_STRING_EQUAL(str, "testing");
        str = my_strcat(str, NULL);
        CU_ASSERT_STRING_EQUAL(str, "testing");
        free(str);
        str = my_strcat(NULL, "test");
        CU_ASSERT(str == NULL);
    }
}

void testMY_STRCPY(void){
    char* str = NULL;

    if(temp_file != NULL){
        str = (char*)xmalloc((15+1) * sizeof(char));
        str = my_strcpy(str, "testing");
        CU_ASSERT_STRING_EQUAL(str, "testing");
        str = my_strcpy(str, "");
        CU_ASSERT_STRING_EQUAL(str, "");
        str = my_strcpy(str, NULL);
        CU_ASSERT_STRING_EQUAL(str, "");
        free(str);
        str = my_strcpy(NULL, "test");
        CU_ASSERT(str == NULL);
    }
}

void testMY_STRNCPY(void){
    char* str = NULL;

    if(temp_file != NULL){
        str = (char*)xmalloc((15+1) * sizeof(char));
        str = my_strncpy(str, "testing", 8);
        CU_ASSERT_STRING_EQUAL(str, "testing");
        str = my_strncpy(str, "copy", 4);
        CU_ASSERT_STRING_EQUAL(str, "copying");
        str = my_strncpy(str, NULL, 4);
        CU_ASSERT_STRING_EQUAL(str, "copying");
        str = my_strncpy(str, "testing", -6);
        CU_ASSERT_STRING_EQUAL(str, "copying");
        free(str);
        str = my_strncpy(NULL, "testing", 6);
        CU_ASSERT(str == NULL);
    }
}

void testMY_STRFIND(void){
    if(temp_file != NULL){
        char* ch;
        ch = my_strfind("testing", 't');
        CU_ASSERT_STRING_EQUAL(ch, "testing");
        ch = my_strfind("testing", 'q');
        CU_ASSERT(ch == NULL);
        ch = my_strfind(NULL, 'q');
        CU_ASSERT(ch == NULL);
    }
}

void testMY_STRRFIND(void){
    if(temp_file != NULL){
        char* ch;
        ch = my_strrfind("testing", 't');
        CU_ASSERT_STRING_EQUAL(ch, "ting");
        ch = my_strrfind("testing", 'q');
        CU_ASSERT(ch == NULL);
        ch = my_strrfind(NULL, 'g');
        CU_ASSERT(ch == NULL);
    }
}

void testMY_VECT2STR(void){
    char** strvect = NULL;
    char* str = NULL;
    int i;

    if(temp_file != NULL){
        strvect = (char**)xmalloc(4 * sizeof(char*));
        strvect[0] = my_strdup("test");
        strvect[1] = my_strdup("was");
        strvect[2] = my_strdup("successful");
        strvect[3] = NULL;
        str = my_vect2str(strvect);
        CU_ASSERT_STRING_EQUAL(str, "test was successful");
        free(str);
        str = my_vect2str(NULL);
        CU_ASSERT(str == NULL);
        for(i = 0; i < 3; ++i){
            free(strvect[i]);
            strvect[i] = NULL;
        }
        free(strvect);
        strvect = NULL;
        str = NULL;
    }
}

void testMY_STR2VECT(void){
    char* str = NULL;
    char** strVect = NULL;
    int i;

    if(temp_file != NULL){
        str = my_strdup("testing was successful");
        strVect = my_str2vect(str);
        CU_ASSERT_STRING_EQUAL(strVect[0], "testing");
        CU_ASSERT_STRING_EQUAL(strVect[1], "was");
        CU_ASSERT_STRING_EQUAL(strVect[2], "successful");
        CU_ASSERT(strVect[3] == NULL);
        for(i = 0; strVect[i]; ++i){
            free(strVect[i]);
            strVect[i] = NULL;
        }
        free(strVect);
        strVect = NULL;
        strVect = my_str2vect(NULL);
        CU_ASSERT(strVect == NULL);
        free(str);
    }
}

void testMY_ATOI(void){
    char* str = NULL;
    int i;

    if(temp_file != NULL){
        str = my_strdup("55");
        i = my_atoi(str);
        CU_ASSERT(i == 55);
        free(str);
        str = my_strdup("-72");
        i = my_atoi(str);
        CU_ASSERT(i == -72);
        free(str);
    }
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

    if((CU_add_test(pSuite, "test of my_char", testMY_CHAR) == NULL) ||
       (CU_add_test(pSuite, "test of my_str", testMY_STR) == NULL) ||
       (CU_add_test(pSuite, "test of my_int", testMY_INT) == NULL) ||
       (CU_add_test(pSuite, "test of my_num_base", testMY_NUM_BASE) == NULL) ||
       (CU_add_test(pSuite, "test of my_strlen", testMY_STRLEN) == NULL) ||
       (CU_add_test(pSuite, "test of my_revstr", testMY_REVSTR) == NULL) ||
       (CU_add_test(pSuite, "test of my_strpos", testMY_STRPOS) == NULL) ||
       (CU_add_test(pSuite, "test of my_strrpos", testMY_STRRPOS) == NULL) ||
       (CU_add_test(pSuite, "test of my_strdup", testMY_STRDUP) == NULL) ||
       (CU_add_test(pSuite, "test of my_strcmp", testMY_STRCMP) == NULL) ||
       (CU_add_test(pSuite, "test of my_strncmp", testMY_STRNCMP) == NULL) ||
       (CU_add_test(pSuite, "test of my_strconcat", testMY_STRCONCAT) == NULL) ||
       (CU_add_test(pSuite, "test of my_strnconcat", testMY_STRNCONCAT) == NULL) ||
       (CU_add_test(pSuite, "test of my_strcat", testMY_STRCAT) == NULL) ||
       (CU_add_test(pSuite, "test of my_strcpy", testMY_STRCPY) == NULL) ||
       (CU_add_test(pSuite, "test of my_strncpy", testMY_STRNCPY) == NULL) ||
       (CU_add_test(pSuite, "test of my_strfind", testMY_STRFIND) == NULL) ||
       (CU_add_test(pSuite, "test of my_strrfind", testMY_STRRFIND) == NULL) ||
       (CU_add_test(pSuite, "test of my_vect2str", testMY_VECT2STR) == NULL) ||
       (CU_add_test(pSuite, "test of my_str2vect", testMY_STR2VECT) == NULL) ||
       (CU_add_test(pSuite, "test of my_atoi", testMY_ATOI) == NULL)){
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
