#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#define MAXLINE 10000

int space_char(char c){
  return (c == '\t' || c == ' ');
}

int non_space_char(char c){
  return !space_char(c);
}

char *word_start(char *s){
  while(space_char(*s))
    s++;
  return s;
}

char *word_terminator(char *word){
  word = &*word_start(word);
  while(non_space_char(*word) && *word != '\0'){
    word++;
  }
  word--;
  return word;
}

int count_words(char *s){
  int count = 0;
  while(*s != '\0'){
    s = &*word_terminator(s);
    s++;
    s = &*word_start(s);
    count++;
  }
  return count;
}

char *copy_str(char *inStr, short len){
  char *c =  malloc(len);
  char *remember = c;
  while((*c++ = *inStr++) && len !=1){
    len--;
  }
  return remember;
}

char **tokenize(char* str){
  char **t = malloc(count_words(str));
  char **remember = t;
  while (*str != '\0'){
    str = word_start(str);
    *t = str;
    str = word_terminator(str);
    str++;
    t++;
  }
  *t = str;
  return remember;
}

void print_tokens(char **tokens){
  int counter = 1;
  char *navigator;
  printf("These are your TOKENS:\n");

  while(**tokens != '\0'){
    printf("%d> ",counter);
    navigator = *tokens;
    while(*navigator != '\0' && non_space_char(*navigator)){
      printf("%c",*navigator);
      navigator++;
    }
    counter++;
    tokens++;
    printf("\n");
  }
}

void free_tokens(char **tokens){
  free(tokens);
}
  
