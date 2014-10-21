#ifndef NL
#define NL my_char('\n');
#endif

#include "my.h"

int main(int argc, char** argv){
  int i;
  int j;
#ifdef T2
  /* test my_strdup */
  my_str("Testing my_strdup\n");
  my_str(my_strdup("Hello\n")); // Prints: Hello
  if(!my_strdup(NULL))
    my_str("my_strdup(NULL) returned NULL.\n");
  else
    my_str("Dupe of NULL failed.\n");

  /* test my_strcmp */
  my_str("Testing my_strcmp\n");
  my_int(my_strcmp("hello", "bok")); // Prints: 1
  NL
  my_int(my_strcmp("hello", "hell")); // Prints: 1
  NL
  my_int(my_strcmp(NULL, NULL)); // Prints: 0
  NL
  my_int(my_strcmp(NULL, "test")); // Prints: -1
  NL
  my_int(my_strcmp("test", NULL)); // Prints: -1
  NL
  my_int(my_strcmp("a", "b")); // Prints: -1
  NL

  /* test my_strncmp */
    my_str("Testing my_strncmp\n");
  my_int(my_strncmp("hello", "bok", 5)); // Prints: 1
  NL
  my_int(my_strncmp("hello", "bok", 0)); // Prints: 0
  NL
  my_int(my_strncmp(NULL, "bok", 2)); // Prints: -1
  NL
  my_int(my_strncmp("bok", NULL, 4)); // Prints: 1
  NL
  my_int(my_strncmp("hello", "hell", 4)); // Prints: 0
  NL
    my_int(my_strncmp("hello", "hell", 500));
  NL

  /* test my_strconcat */
  my_str("Testing my_strconcat\n");
#if 0
  my_str(my_strconcat("hello", "bok")); // Prints: "hellobok"
  NL
  my_str(my_strconcat("bok", "")); // Prints: "bok"
  NL
  my_str(my_strconcat(NULL, "test")); // Prints: "test"
  NL
  my_str(my_strconcat(NULL, NULL)); // Prints: nothing (literally)
  NL
  my_str(my_strconcat("", NULL)); // Prints: nothing
  NL
#endif
    if (my_strconcat(NULL, NULL) == NULL)
      my_str("Concat null to null ok!\n");
    else
      my_str("Concat NULL to NULL bad!\n");
  char* s3;
  if((s3 = my_strconcat(NULL, "concat NULL and string works\n")) == NULL)
    my_str("Concat NULL and string failed\n");
  else
    my_str(s3);
  char* s2;
  if ((s2 = my_strconcat("concat string and NULL works\n", NULL)) == NULL)
    my_str("concat string and NULL failed\n");
  else
    my_str(s2);
  free(s2);
  s2 = my_strconcat("concat", "really works!\n");
  my_str(s2);

  /* test my_strnconcat */
    my_str("Testing my_strnconcat.c\n");
  my_str(my_strnconcat("hello", "bok", 1)); // Prints: hellob
  NL
  my_str(my_strnconcat("hello", "bok", 0)); // Prints: hello
  NL
  my_str(my_strnconcat("test", "bok", 7)); // Prints: testbok
  NL
  my_str(my_strnconcat(NULL, "bok", 2)); // Prints: bo
  NL
  my_str(my_strnconcat("test", NULL, 2)); // Prints: test
  NL
  my_str(my_strnconcat(NULL, NULL, 2)); // Prints: nothing
  NL

  /* test my_strcat */
    my_str("Testing my_strcat.\n");
  char* s = xmalloc(12 * sizeof(char) + 1);
  char* sc = "hello";
  i = 0;
  for(; sc[i] != '\0'; s[i] = sc[i++]);
  s[i] = '\0';
  my_str(my_strcat(s, NULL)); // Prints: hello
  NL
  my_str(my_strcat(NULL, s)); // Prints: nothing
  NL
  my_str(my_strcat(s, "test")); // Prints: hellotest
  NL

  /* test  my_strcpy */
    my_str("Testing my_strcpy.\n");
  my_str(my_strcpy(s, NULL)); // Prints: hellotest
  NL
  my_str(my_strcpy(NULL, s)); // Prints: nothing
  NL
  my_str(my_strcpy(s, "test")); // Prints: test
  NL

  /* test my_strncpy */
    my_str("Testing my_strncpy.\n");
  my_str(my_strncpy(s, NULL, 5)); // Prints: test
  NL
  my_str(my_strncpy(NULL, s, 5)); // Prints: nothing
  NL
  my_str(my_strncpy(s, s+(7 * sizeof(char)), 3)); // Prints: st
  NL

  for(i = 0; sc[i]; s[i] = sc[i++]);
  s[i] = '\0';
  my_str(s);
  NL

  /* test my_strfind */
    my_str("Testing my_strfind.\n");
  my_str(my_strfind(s, 'l')); // Prints: llo
  NL
  my_str(my_strfind(NULL, 'l')); // Prints: nothing
  NL
  my_str(my_strfind(s, 'x'));
  NL

  /* test my_strrfind */
    my_str("Testing my_strrfind.\n");
  my_str(my_strrfind(s, 'l')); // Prints: lo
  NL
  my_str(my_strrfind(NULL, 'l')); // Prints: nothing
  NL
    my_str(my_strrfind(s, 'x'));
  NL

    /* test my_vect2str */
    my_str("Testing my_vect2str.\n");
  my_str(my_vect2str(&(argv[1])));
  NL
    my_str((my_vect2str(NULL)) ? "BAD: !NULL\n" : "GOOD: NULL\n");
  NL
  
    /* test my_str2vect */
    my_str("Testing my_str2vect.\n");
    char** v1 = my_str2vect("Testing my_str2vect");
  for(i = 0; v1[i]; ++i){
    my_str(v1[i]);
    free(v1[i]);
    my_char(' ');
  }
  my_char('\n');
  free(v1);
  v1 = my_str2vect("test    number\t\t\t\t    2 \t with \t  \t tabs ");
  for(i = 0; v1[i]; ++i){
    my_str(v1[i]);
    free(v1[i]);
    my_char(' ');
  }
  my_char('\n');
  free(v1);
  
  /* Testing my_atoi */
  my_str("Testing my_atoi.\n");
  j = my_atoi("test");
  my_str("Garbage Test: ");
  my_int(j);			/* Should print garbage */
  my_char('\n');
  j = my_atoi(NULL);
  my_str("Null Garbage Test: ");
  my_int(j);			/* Should print garbage */
  my_char('\n');
  j = my_atoi("123");
  my_str((j == 123) ? "GOOD: j == 123\n" : "BAD: j != 123\n");
  my_int(j);
  my_char('\n');
  j = my_atoi("-901");
  my_str((j == -901) ? "GOOD: j == -901\n" : "BAD: j != -901\n");
  my_int(j);
  my_char('\n');
  j = my_atoi("             124\t\t ");
  my_str((j == 124) ? "GOOD: j == 124\n": "BAD: j != 124\n");
  my_int(j);
  my_char('\n');
  

#endif
  return 0;
}
