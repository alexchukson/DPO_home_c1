#include <stdio.h>
#include <string.h>
int is_single(char* w, char s){
  char* result = strchr(w, s);
  if (result != NULL){
    if (strlen(result) == 1) return 1;
    result = strchr(result+1, s);
    if (result == NULL) return 1;
    else return 0;
  }else return 0;
}

int main()
{
  char w1[100];
  char w2[100];
  int len = 0, i = 0, j = 0;
  char sy = 0;
  FILE *f, *fo;
  f = fopen("input.txt", "r");
  fo = fopen("output.txt", "w");
  if (f){
    fscanf(f, "%s %s", &w1, &w2);
    for (i = 0; i < strlen(w1); i++){
      sy = w1[i];
      printf("%c\n", sy);
      if (is_single(w1, sy))
        if (is_single(w2, sy))
          fprintf(fo, "%c ", sy);
      
    }
  }
  fclose(fo);
  return 0;
}