#pragma once

struct upload_date {

	int day = 0;  //день
	int month = 0;//мес€ц
	int year = 0; //год
};

upload_date create_date(int day, int month, int year);
void input_date(upload_date* date);
void init_date(upload_date* date);