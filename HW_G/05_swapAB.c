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
  char w1[1000];

  int len = 0, i = 0, j = 0;

  FILE *f, *fo;
  f = fopen("input.txt", "r");
  fo = fopen("output.txt", "w");
  if (f){
    fscanf(f, " %[^\n]", &w1);
    printf("strlen %d \n", strlen(w1));
    for (i = 0; i < strlen(w1); i++){
      if (w1[i] == 'a') { w1[i] = 'b'; fprintf(fo, "%c", w1[i]); continue; }
      if (w1[i] == 'b') { w1[i] = 'a'; fprintf(fo, "%c", w1[i]); continue; }
      if (w1[i] == 'A') { w1[i] = 'B'; fprintf(fo, "%c", w1[i]); continue; }
      if (w1[i] == 'B') { w1[i] = 'A'; fprintf(fo, "%c", w1[i]); continue; }
      fprintf(fo, "%c", w1[i]);
      
    }
  }
  fclose(fo);
  return 0;
}