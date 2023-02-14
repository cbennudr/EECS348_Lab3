/*
 * program2.c
 *
 *  Created on: Feb 14, 2023
 *      Author: CBenn
 */

#include <stdio.h>

int main() {

	int score;
	int running = 1;
	int total;
	int count;
	//char SCORINGS[] = {6, 7, 8, 3, 2}; // td, td+fg, td+2pc, fg, safe
	printf("Starting program\n");
	while (running == 1) {
		printf("Enter score (or 0 or 1 to stop): ");
		scanf("%d", &score);

		// td
		if (score > 1){
			for (int i = 0; i < score; i+=6){
				// td+fg
				for (int j = 0; j < score; j += 7) {
					// td+2pc
					for (int k = 0; k < score; k += 8) {
						// fg
						for (int m = 0; m < score; m += 3){
							// safe
							for (int p = 0; p < score; p += 2) {
								total = (i+j+k+m+p);
								//printf("%d\n", total);
								if (total == score) {
									printf("Touchdowns: %d, Touchdowns+fieldgoals: %d, Touchdowns+2pc: %d, Fieldgoals: %d, Safetys: %d\n", i/6, j/7, k/8, m/3, p/2);
									//38
									count++;
								}
							}
						}
					}
				}
			}
			printf("%d possibilities shown\n", count);
		}
		else {
			printf("Invalid score. Program stopping.\n");
			running = 0;
		}



	}
	//printf("%d", score);


	return 0;
}
