/* libmy
My library for commonly used functions */

#ifndef _MY_H_
#define _MY_H_
#ifndef NULL
#define NULL ((void *) 0)
#endif
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

ssize_t my_char(char);
ssize_t my_str(char *);
ssize_t my_int(int);
char* my_num_base(int, char *);
void my_alpha();
void my_digits();
int my_strlen(char *);
int my_revstr(char *);
int my_strpos(char *, char);
int my_strrpos(char *, char);
char* my_strdup(char* );
int my_strcmp(char*, char*);
int my_strncmp(char*, char*, unsigned int);
char* my_strconcat(char*, char*);
char* my_strnconcat(char*, char*, unsigned int);
char* my_strcat(char*, char*);
char* my_strcpy(char*, char*);
char* my_strncpy(char*, char*, unsigned int);
char* my_strfind(char*, char);
char* my_strrfind(char*, char);
void* xmalloc(int n);
char* my_vect2str(char**);
char** my_str2vect(char*);
void my_freevect(char**);
int my_atoi(char*);
void my_err(char*);

#endif
