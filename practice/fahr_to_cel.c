#include <stdio.h>

/* compact version of fahr_to_celsius, but in reverse order */

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {

   int fahr;

   for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
      printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
   }
}
