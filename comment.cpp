#define _CRT_SECURE_NO_WARNINGS

#include "comment.h"
#include <stdlib.h>
#include <string.h>

void add_answer(comment* c, answer* a) {

	c->answers_count++; // ���������� ���������� ������� �� �������
	if (c->answers == nullptr)  // ���� ������ ������� ������, �� �������� ������ ��� ������ ��������
	{
		c->answers = (answer*)malloc(sizeof(answer));
	}
	else  // ����� ������������ ������ ��� ������������ ������� ������� 
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

	if (!c) return;

	if(c->text) free(c->text);
	if(c->author) free(c->author);
	for (int i = 0; i < c->answers_count; i++) {

		free_answer(&c->answers[i]);
	}
	if(c->answers) free(c->answers);

	free(c);
}

void free_non_dynamic_comment(comment* c) {

	if (c->text) free(c->text);
	if (c->author) free(c->author);
	for (int i = 0; i < c->answers_count; i++) {

		free_answer(&c->answers[i]);
	}
	if (c->answers) free(c->answers);
}

void input_comment(comment* c)
{
	char text[comment_lengt];
	char author[name_lenght];
	upload_date date;

	if (c->text) free(c->author);
	printf("������� ��� ������ ����������: ");
	fgets(author, sizeof(author), stdin);
	*(strchr(author, '\n')) = 0;
	c->author = _strdup(author);

	if (c->author) free(c->text);
	printf("������� ����� ����������: ");
	fgets(text, sizeof(text), stdin);
	*(strchr(text, '\n')) = 0;
	c->text = _strdup(text);

	input_date(&c->date);

	
}
