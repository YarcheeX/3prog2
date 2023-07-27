#define _CRT_SECURE_NO_WARNINGS

#include "photo.h"
#include <stdlib.h>
#include <string.h>


//�������� ����
photo* create_photo(const char* name, const char* descr, const char* url, upload_date date)
{
	photo* pho = (photo*)malloc(sizeof(photo));
	init_photo(pho);
	pho->date = date;
	pho->name = _strdup(name);
	pho->description = _strdup(descr);
	pho->url = _strdup(url);

	return pho;
}

//���������� ����
void add_comment_photo(photo* p, comment* c) {

	p->comments_count++; 

	//������������ ������ ��� ���������� �����������
	p->comments = (comment**)realloc(p->comments, sizeof(comment*) * p->comments_count);

	p->comments[p->comments_count - 1] = c;

}

//�������� ����
void like_photo(photo* p, int likes){
	p->likes += likes;
}

//����������� ����
void dislike_photo(photo* p, int dislikes){
	p->dislikes += dislikes;
}

//���������� ����
void view_photo(photo* p, int views) {
	p->views += views;
}

//���������� ����
void free_photo(photo* p)
{
	if (!p) return;
	
	if (p->name) { 
		free(p->name);
		p->name = nullptr;
	}
	if (p->url) {
		free(p->url);
		p->url = nullptr;
	}
	if (p->description) {
		free(p->description);
		p->description = nullptr;
	}
	for (int i = p->comments_count-1; i >= 0; i--) {

		free_comment(p->comments[i]);
	}

	free(p);
	p = nullptr;
}

void print_photo(photo* p)
{
	printf("��������: %s (%s) | ����: %d.%d.%d\n", p->name, p->url, p->date.day, p->date.month, p->date.year);
	printf("���������: %d | �����: %d | ��������: %d | �����������: %d\n", p->views, p->likes, p->dislikes, p->comments_count);
}

//���� ����
void input_photo(photo* p)
{

	printf("\n���� ����.\n");

	char name[name_lenght];
	char url[url_lenght];
	char description[description_lenght];
	upload_date date;

	if (p->name) free(p->name);
	printf("������� ��� ����: ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';
	p->name = _strdup(name);

	if (p->url) free(p->url);
	printf("������� ������ �� ����: ");
	fgets(url, sizeof(url), stdin);
	url[strlen(url) - 1] = '\0';
	p->url = _strdup(url);

	if (p->description) free(p->description);
	printf("������� �������� ����: ");
	fgets(description, sizeof(description), stdin);
	description[strlen(description) - 1] = '\0';
	p->description = _strdup(description);

	input_date(&p->date);
}

//������������� ����
void init_photo(photo* p)
{
	p->name = nullptr;
	p->description = nullptr;
	p->url = nullptr; 
	p->comments = nullptr;
	init_date(&p->date);  
	p->views = 0; 
	p->likes = 0; 
	p->dislikes = 0;
	p->comments_count = 0;
}
