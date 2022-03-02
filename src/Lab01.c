#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAXLINES 10000

char *words[MAXLINES];
int readlines(char *words[], int nlines);
void printlines(char *words[], int nlines);

void strCpy(char *s, char *t);
  
int main(){

  int nlines;
  printf("Enter words. Enter @ to stop and view saved words.\n");
  printf("> ");

  if ((nlines = readlines(words, MAXLINES)) < 0) {
    printf("error: input too big to use.\n");
    return 1;
  }
  List *list = init_history();
  for(int i = 0; i<nlines; i++)
    add_history(list,words[i]);
  printf("Please choose one of your strings.\n");
  print_history(list);
  getchar();
  char *string = get_history(list,getchar()-'0');

  printf("the number of words in your string is: %d\n", count_words(string));
  char *copy = copy_str(string,15);
  printf("this is a copy of your string: ");
  while(*copy != '\0'){
    printf("%c",*copy);
    copy++;
  }
  printf("\n");

  char **t = tokenize(string);
  print_tokens(t);

  printf("Please choose one of your tokens.\n");
  getchar();
  char choice = getchar()-'0';
  for(choice; choice != 1; choice--)
    t++;

  printf("the first char is: %c\n", *word_start(*t));
  printf("the last char is: %c\n", *word_terminator(*t));
}

#define MAXLEN 1000    //max length of any input line.
int getLine(char *, int);

// readlines: read input lines.
int readlines(char *words[], int maxlines){

  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while((len = getLine(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = malloc(len)) == NULL)
      return -1;
    else{
      line[len-1] = '\0'; // delete newline
      strCpy(p, line);
      words[nlines++] = p;
    }
  return nlines;
}

//strcpy: copy t to s.
void strCpy(char *s, char *t){

  while (*s++ = *t++)
    ;
  
}

//printlines: print output lines.
void printlines(char *words[], int nlines){

  int i;

  for (i = 0; i < nlines; i++)
    printf("%d>  %s\n",i, words[i]);
}

// getline: get line into s, return length.
int getLine(char s[], int lim){

  int c, i;

  i = 0;
  while (--lim > 0 && (c=getchar()) != '@' && c != '\n')
    s[i++] = c;
  if (c== '\n'){
    printf("> ");
    s[i++] = c;}
  s[i] = '\0';
  return i;
}
