#pragma once
#include "upload_date.h"
#include "answer.h"

struct comment {

	struct upload_date date;
	char* text = nullptr;
	char* author = nullptr;
	struct answer* answers = nullptr;
	int answers_count = 0;
};

comment* create_comment(char* text, char* author, upload_date d);
void add_answer(comment* c, answer* a);
void free_comment(comment *c);
void input_comment(comment* c);