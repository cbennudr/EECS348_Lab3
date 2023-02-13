/*
 * program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: CBenn
 */


#include <stdio.h>
#include <math.h>
#include <string.h>
//#define MONTHS 12
const char *months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

void sales_report(double sales[12]){
	printf("\nMonthly Sales Report for 2022:\n");
	//go through lists printing
	printf("Month\tSales\n");
	for (int i = 0; i < 12; i++){
		//char month = *months[i];
		double sale = sales[i];
		printf("%s \t %lf\n", *(months+i), sale);
	}

}

void min_max_avg(double sales[12]){
	double min=0, max=0, avg = 0, total = 0;
	char *minMonth, *maxMonth;
	int count = 0;
	for (int i = 0; i < 12; i++){
		// min
		if (count == 0) {
			min = sales[i];
			minMonth = *(months+i);
			count++;
		}
		if (sales[i] < min){
			min = sales[i];
			minMonth = *(months+i);
		}

		//max
		if (sales[i] > max){
			max = sales[i];
			maxMonth = *(months+i);
		}

		//avg
		total += sales[i];
		//printf("sales: %f --- Total: %f\n", sales[i], total);
	}
	avg = total/12;

	printf("\nSales Summary: \n");
	printf("Min sales: %lf (%s)\n", min, minMonth);
	printf("Max sales: %lf (%s)\n", max, maxMonth);
	//////////////////////INCORRECT AVG
	printf("Avg sales: %lf\n", avg);
}


void six_month_avg(double sales[12]){
	printf("\nSix-Month Moving Avg Report:\n");
	double total, avg;
	int j;
	for (int i = 0; i <= 6; i++){
		total = 0;
		avg = 0;
		j = i;
		while (j < i+6){
			total += sales[j];
			j++;
		}
		//printf("Tot: %f", total);
		avg = total/6;
		printf("%s - %s:   %lf\n", *(months+i), *(months+i+5), avg);
	}

}

void print_sales_des(double sales[12]){
	printf("\nSales Report (Highest to lowest)\n");
	printf("Month \t Sales\n");
	char *sortedMonths[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	//sort
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 12-i-1; j++){
			if (sales[j] > sales[j+1]){
				//get value that will be overwritten
				double tmp = sales[j+1];
				char* tmpMonth = sortedMonths[j+1];
				//overwrite value
				sales[j+1] = sales[j];
				sortedMonths[j+1] = sortedMonths[j];
				//restore overwritten value in proper place
				sales[j] = tmp;
				sortedMonths[j] = tmpMonth;
			}
		}
	}
	for (int i = 11; i >= 0; i--){
			//char *month = *sortedMonths[i];
			// was getting weird value so added if block
			if (sales[i] > 0){
				printf("%s", *(sortedMonths+i));
				printf("\t%lf\n", sales[i]);
			}
	}

}

int main() {

	double sales[12];
	FILE *fp;

	//open file
	fp = fopen("input.txt", "r");
	//ensure worked
	if (fp == NULL) {
		printf("err opening file");
		return 0;
	}
	// if worked make array
	for (int i = 0; i < 12; i++){
		fscanf(fp, "%lf", &sales[i]);
		int tmp = sales[i];
		double dec = round((sales[i] - tmp)*100);
		double res = tmp + (dec*.01);
		sales[i] = res;
	}
	//close file
	fclose(fp);
	// call funcs
	sales_report(sales);
	min_max_avg(sales);
	six_month_avg(sales);
	print_sales_des(sales);


	return 0;
}
