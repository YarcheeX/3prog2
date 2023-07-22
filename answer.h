#pragma once
#define name_lenght 30
#define description_lenght 100
#define url_lenght 100
#define comment_lengt 300
#include <stdio.h>
#include <string.h>
#include "upload_date.h"

struct answer{

	char* text = nullptr;
	char* author = nullptr;
	upload_date date;
};


answer* create_answer(char* text, char* author, upload_date d);
void free_answer(answer* a);
void free_non_dynamic_answer(answer* a);