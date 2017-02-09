#include <stdio.h>

int main() {
  int num = 1;
  int val = 1;
  while (num < 6) {
    num++;
      val *= num;
      printf("%d\n",num);
      printf("%d\n",val);
  }
  return 0;
}
