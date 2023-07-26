#pragma once

struct upload_date {

	int day = 0;
	int month = 0;
	int year = 0;
};

upload_date create_date(int day, int month, int year);
void input_date(upload_date* date);
void init_date(upload_date* date);