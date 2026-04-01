#include <stdio.h>
#include <string.h>
int main()
{
  char str[0x100];
  FILE *f, *fo;
  f = fopen("input.txt", "r");
  fo = fopen("output.txt", "w");
 
  // Use fgets() instead of gets()
  if (fgets(str, 0x100, f)!= NULL)
  {
    str[strlen(str)-1] = '\0';
    fprintf(fo, "%s, %s, %s %d\n", str, str, str, strlen(str));
  }
  else
  {
    printf("Error reading input");
  }
  fclose(fo);
  return 0;
}