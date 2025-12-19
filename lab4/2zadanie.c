#include <stdio.h>

int main()
{
 int a;
 scanf("%d", &a);
 int val = 0;
 while (a)
 {
  a &= (a - 1);
  val++;
 }
 printf("%d\n", val);
}