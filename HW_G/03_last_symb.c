#include <stdio.h>
#include <string.h>
int main()
{
  char str[1000];
  char ostr[1000];
  char last_symb = '\0';
  int len = 0, i = 0, j = 0;
  FILE *f, *fo;
  f = fopen("input.txt", "r");
  fo = fopen("output.txt", "w");
  if (f){
    fscanf(f, " %[^\\n]", &str);
    len = strlen(str);
    last_symb = str[len-1];
    for (i = 0; i < len-1; i++){
      if (str[i] == last_symb) {
        fprintf(fo, "%d ", i) ;
      }
    }
  }
  // fprintf(fo, "\0\n ")  ;
  // str[i] = 0;

  // printf("%s", ostr);
  // fprintf(fo, "%s\n", ostr) ;
  // Use fgets() instead of gets()
  // if (fgets(str, 0x100, f)!= NULL)
  // {
  //   str[strlen(str)-1] = '\0';
  //   fprintf(fo, "%s, %s, %s %d\n", str, str, str, strlen(str));
  // }
  // else
  // {
  //   printf("Error reading input");
  // }
  // fclose(fo);
  return 0;
}