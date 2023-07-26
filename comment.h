#pragma once
#include "upload_date.h"
#include "answer.h"

struct comment {

	upload_date date;          //���� �����������
	char* author = nullptr;	   //��� ������ �����������
	char* text = nullptr;	   //����� �����������
	answer** answers = nullptr;//������ ������� �� �����������
	int answers_count = 0;	   //���-�� �������
};

comment* create_comment(const char* text, const char* author, upload_date d);
void add_answer(comment* c, answer* a);
void free_comment(comment *c);
void input_comment(comment* c);
void init_comment(comment* c);