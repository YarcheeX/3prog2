#define _CRT_SECURE_NO_WARNINGS

#include "comment.h"
#include <stdlib.h>
#include <string.h>


//���������� ������
void add_answer(comment* c, answer* a) {

	c->answers_count++; // ���������� ���������� ������� �� �������
	
	//������������� ������ ��� ���������� ������
	c->answers = (answer**)realloc(c->answers, sizeof(answer*) * c->answers_count); 
	
	//��������� ��������� �� ����� � ������� ���������� �� ������ �� ����������
	c->answers[c->answers_count - 1] = a;

}


//�������� �����������
comment* create_comment(const char* text, const char* author, upload_date d)
{
	comment* comm = (comment*)malloc(sizeof(comment)); 
	init_comment(comm);
	comm->text = _strdup(text);
	comm->author = _strdup(author);
	comm->date = d;

	return comm;
}


//������� �����������
void free_comment(comment *c) {

	if (!c) return;
	//������� ������ �����������
	if (c->text) {
		free(c->text);
		c->text = nullptr;
	}
	//������� ����� ������
	if (c->author) {
		free(c->author);
		c->author = nullptr;
	}
	//������� �������
	for (int i = c->answers_count - 1; i >=0 ; i--) {

		free_answer(c->answers[i]);
	}
	//������� ������� �������
	if (c->answers) {
		free(c->answers);
		c->answers = nullptr;
	}
	//������� �����������
	free(c);
	c = nullptr;
}

//����� �����������
void print_comment(comment* c)
{
	printf("\n�����: %s | ����: %d.%d.%d\n", c->author, c->date.day, c->date.month, c->date.year);
	printf("�����: %s\n", c->text);
	printf("������:\n");
	for (int i = 0; i < c->answers_count; i++) {
		printf("%d) ", i);
		print_answer(c->answers[i]);
	}
}

//���� �����������
void input_comment(comment* c)
{
	printf("\n���� �����������.\n");

	char text[comment_lengt];
	char author[name_lenght];
	upload_date date;

	if (c->author) free(c->author);
	printf("������� ��� ������ ����������: ");
	fgets(author, sizeof(author), stdin);
	author[strlen(author) - 1] = '\0';
	c->author = _strdup(author);

	if (c->text) free(c->text);
	printf("������� ����� ����������: ");
	fgets(text, sizeof(text), stdin);
	text[strlen(text) - 1] = '\0';
	c->text = _strdup(text);

	input_date(&c->date);

}

//������������� �����������
void init_comment(comment* c)
{
	init_date(&c->date);
	c->text = nullptr;
	c->author = nullptr;
	c->answers = nullptr;
	c->answers_count = 0;
}
