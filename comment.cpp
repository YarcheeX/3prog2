#define _CRT_SECURE_NO_WARNINGS

#include "comment.h"
#include <stdlib.h>
#include <string.h>

void add_answer(comment* c, answer* a) {

	c->answers_count++; // увеличение количества ответов на единицу
	if (c->answers == nullptr)  // если массив ответов пустой, то выделить пам€ть дл€ одного элемента
	{
		c->answers = (answer*)malloc(sizeof(answer));
	}
	else  // иначе перевыделить пам€ть дл€ увеличенного массива ответов 
	{
		c->answers = (answer*)realloc(c->answers, sizeof(answer) * c->answers_count);
	}
	
	c->answers[c->answers_count - 1] = *a;

}

comment* create_comment(char* text, char* author, upload_date d)
{
	comment* comm = (comment*)malloc(sizeof(comment));

	comm->text = _strdup(text);
	comm->author = _strdup(author);
	comm->date = d;

	return comm;
}

void free_comment(comment *c) {

	free(c->text);
	free(c->author);
	for (int i = 0; i < c->answers_count; i++) {

		free_answer(&c->answers[i]);
	}
	free(c->answers);
}

void input_comment(comment* c)
{
	char text[comment_lengt];
	char author[name_lenght];
	upload_date date;

	free(c->author);
	printf("¬ведите им€ автора коментари€: ");
	fgets(author, sizeof(author), stdin);
	*(strchr(author, '\n')) = 0;
	c->author = _strdup(author);

	free(c->text);
	printf("¬ведите текст коментари€: ");
	fgets(text, sizeof(text), stdin);
	*(strchr(text, '\n')) = 0;
	c->text = _strdup(text);

	input_date(&c->date);

	
}
