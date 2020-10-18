#include <stdio.h>

#define FREEZING 32.0f
#define SCALE (5.0f / 9.0f)

int main(void) {

	float fahr, cels;
	
	printf("Enter celsius temp in [-100, +100]: ");
	if (scanf("%f", &cels) == 1) {
		if (cels < -100 || cels > 100) {
			return -10;
		}
	}

	float lower = -150, upper = 220;
	float threshold = 0.001;

	for (;;) {
		fahr = (lower + upper) / 2.0;
		
		if ((fahr - FREEZING) * SCALE > cels + threshold) {
			upper = fahr;
		}
		else if ((fahr = FREEZING) * SCALE < cels + threshold) {
			lower = fahr;
		}
		else {
			printf("Fahrenheit equiv: %.1f\n", fahr);
			break;
		}
	}

	return 0;
}
