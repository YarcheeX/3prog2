#define _CRT_SECURE_NO_WARNINGS

#include "photo.h"
#include <stdlib.h>
#include <string.h>

photo* create_photo(char* name, char* descr, char* url, upload_date date)
{
	photo* pho = (photo*)malloc(sizeof(photo));

	pho->date = date;
	pho->name = _strdup(name);
	pho->description = _strdup(descr);
	pho->url = _strdup(url);

	return pho;
}

void add_comment_photo(photo* p, comment* c) {

	p->comments_count++; // ���������� ���������� ������������ �� �������
	if (p->comments == NULL)  // ���� ������ ������������ ������, �� �������� ������ ��� ������ ��������
	{	
		p->comments = (comment*)malloc(sizeof(comment));
	}
	else  // ����� ������������ ������ ��� ������������ ������� ������������ 
	{
		p->comments = (comment*)realloc(p->comments, sizeof(comment) * p->comments_count);
	}

	p->comments[p->comments_count - 1] = *c;

}

void like_photo(photo* p, int likes){
	p->likes += likes;
}

void dislike_photo(photo* p, int dislikes){
	p->dislikes += dislikes;
}

void view_photo(photo* p, int views) {
	p->views += views;
}

void free_photo(photo* p)
{
	free(p->name);
	free(p->description);
	free(p->url);
	for (int i = 0; i < p->comments_count; i++) {

		free_comment(&p->comments[i]);
	}
	free(p->comments);
}


void input_photo(photo* p)
{

	printf("\n���� ����.\n");

	char name[name_lenght];
	char url[url_lenght];
	char description[description_lenght];
	upload_date date;

	free(p->name);
	printf("������� ��� ����: ");
	fgets(name, sizeof(name), stdin);
	*(strchr(name, '\n')) = 0;
	p->name = _strdup(name);

	free(p->url);
	printf("������� ������ �� ����: ");
	fgets(url, sizeof(url), stdin);
	*(strchr(url, '\n')) = 0;
	p->url = _strdup(url);

	free(p->description);
	printf("������� �������� ����: ");
	fgets(description, sizeof(description), stdin);
	*(strchr(description, '\n')) = 0;
	p->description = _strdup(description);

	input_date(&p->date);

}
