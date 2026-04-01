#include <stdio.h>
#include <string.h>
int main()
{
  char str[0x100];
  int N = 0, i = 0;
  FILE *f, *fo;
  f = fopen("input.txt", "r");
  fo = fopen("output.txt", "w");
  int odd[4] = {2, 4, 6, 8};
  if (f){
    fscanf(f, "%d", &N);
    if (N > 26) return 0;
    for (i = 0; i < N; i++){
      if (i % 2 == 1) str[i] = '0' + odd[(i/2)%4];
      else str[i] = 'A' + i/2;
    }
  }
  str[i] = 0;
  // printf("%s\n", str);
  fprintf(fo, "%s\n", str);
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