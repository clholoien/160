#include <stdio.h>

  int Main();  // inform the compiler that Main is an external function

  int main(int argc, char **argv) {
      printf("Main returned: %d\n", Main());
      return 0;
  }
