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

	printf("\n���� ���� ��������.\n������� ����: ");
	while (scanf_s("%d", day) != 1 || *day < 0 || *day > 31)
	{
		printf("������. ������� ���� (�����): ");
	}
	while (getchar() != '\n');

	printf("������� ����� (������): ");
	while (scanf_s("%d", month) != 1 || *month < 0 || *month > 12)
	{
		printf("������. ������� ����� (������): ");
	}
	while (getchar() != '\n');

	printf("������� ��� (2005-2023, ���������): ");
	while (scanf_s("%d", year) != 1 || *year < 2005 || *year > 2023)
	{
		printf("������. ������� ��� (2005-20023, ���������): ");
	}
	while (getchar() != '\n');

}