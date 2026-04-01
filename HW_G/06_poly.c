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

int is_palindrom(char* str){
  int res = 1, len = 0;
  len = strlen(str);
  for (int i = 0; i < len/2; i++){
    if (str[i] != str[len - i - 1]) res = 0;
  }
  return res;
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
    if (is_palindrom(w1)) fprintf(fo, "YES");
    else fprintf(fo, "NO");
  }
  fclose(fo);
  return 0;
}