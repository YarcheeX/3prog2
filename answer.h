#pragma once
#define name_lenght 30
#define description_lenght 100
#define url_lenght 100
#define comment_lengt 300

#include <stdio.h>
#include <string.h>
#include "upload_date.h"

struct answer{

	char* author = nullptr;//название автора
	char* text = nullptr;  //текст 
	upload_date date;	   //дата 
};


answer* create_answer(const char* text, const char* author, upload_date d);
void free_answer(answer* a);
void init_answer(answer* a);