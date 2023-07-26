#include "upload_date.h"
#include <stdio.h>

upload_date create_date(int day, int month, int year) {

	struct upload_date date = { day, month, year };
	return date;
}

void input_date(upload_date* date) {

	int* day = &date->day;
	int* month = &date->month;
	int* year = &date->year;

	printf("\n¬вод даты загрузки.\n¬ведите день: ");
	while (scanf_s("%d", day) != 1 || *day < 0 || *day > 31)
	{
		while (getchar() != '\n');
		printf("ќшибка. ¬ведите день (число): ");
	}
	while (getchar() != '\n');

	printf("¬ведите мес€ц (числом): ");
	while (scanf_s("%d", month) != 1 || *month < 0 || *month > 12)
	{
		while (getchar() != '\n');
		printf("ќшибка. ¬ведите мес€ц (числом): ");
	}
	while (getchar() != '\n');

	printf("¬ведите год (2005-2023, полностью): ");
	while (scanf_s("%d", year) != 1 || *year < 2005 || *year > 2023)
	{
		while (getchar() != '\n');
		printf("ќшибка. ¬ведите год (2005-20023, полностью): ");
	}
	while (getchar() != '\n');

}

void init_date(upload_date* d) {

	d->day = 0;
	d->month = 0;
	d->year = 0;
}