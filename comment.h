#pragma once
#include "upload_date.h"
#include "answer.h"

struct comment {

	upload_date date;          //дата комментария
	char* author = nullptr;	   //имя автора комментария
	char* text = nullptr;	   //текст комментария
	answer** answers = nullptr;//массив ответов на комментарий
	int answers_count = 0;	   //кол-во ответов
};

comment* create_comment(const char* text, const char* author, upload_date d);
void add_answer(comment* c, answer* a);
void free_comment(comment *c);
void input_comment(comment* c);
void init_comment(comment* c);