#define _CRT_SECURE_NO_WARNINGS

#include "comment.h"
#include <stdlib.h>
#include <string.h>


//добавление ответа
void add_answer(comment* c, answer* a) {

	c->answers_count++; // увеличение количества ответов на единицу
	
	//перевыделение памяти при добавлении ответа
	c->answers = (answer**)realloc(c->answers, sizeof(answer*) * c->answers_count); 
	
	//присвоить указатель на ответ к массиву указателей на ответы на коментарии
	c->answers[c->answers_count - 1] = a;

}


//создание комментария
comment* create_comment(const char* text, const char* author, upload_date d)
{
	comment* comm = (comment*)malloc(sizeof(comment)); 
	init_comment(comm);
	comm->text = _strdup(text);
	comm->author = _strdup(author);
	comm->date = d;

	return comm;
}


//очистка комментария
void free_comment(comment *c) {

	if (!c) return;
	//очистка текста комментария
	if (c->text) {
		free(c->text);
		c->text = nullptr;
	}
	//очистка имени автора
	if (c->author) {
		free(c->author);
		c->author = nullptr;
	}
	//очистка ответов
	for (int i = c->answers_count - 1; i >=0 ; i--) {

		free_answer(c->answers[i]);
	}
	//очистка массива ответов
	if (c->answers) {
		free(c->answers);
		c->answers = nullptr;
	}
	//очистка комментария
	free(c);
	c = nullptr;
}

//вывод комментария
void print_comment(comment* c)
{
	printf("\nАвтор: %s | Дата: %d.%d.%d\n", c->author, c->date.day, c->date.month, c->date.year);
	printf("Текст: %s\n", c->text);
	printf("Ответы:\n");
	for (int i = 0; i < c->answers_count; i++) {
		printf("%d) ", i);
		print_answer(c->answers[i]);
	}
}

//ввод комментария
void input_comment(comment* c)
{
	printf("\nВвод комментария.\n");

	char text[comment_lengt];
	char author[name_lenght];
	upload_date date;

	if (c->author) free(c->author);
	printf("Введите имя автора коментария: ");
	fgets(author, sizeof(author), stdin);
	author[strlen(author) - 1] = '\0';
	c->author = _strdup(author);

	if (c->text) free(c->text);
	printf("Введите текст коментария: ");
	fgets(text, sizeof(text), stdin);
	text[strlen(text) - 1] = '\0';
	c->text = _strdup(text);

	input_date(&c->date);

}

//инициализация комментария
void init_comment(comment* c)
{
	init_date(&c->date);
	c->text = nullptr;
	c->author = nullptr;
	c->answers = nullptr;
	c->answers_count = 0;
}
