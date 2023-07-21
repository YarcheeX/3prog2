#define _CRT_SECURE_NO_WARNINGS

#include "video.h"
#include <stdlib.h>
#include <string.h>


video* create_video(char* name, char* descr, char* url, upload_date date)
{
	video* vid = (video*)malloc(sizeof(video));

	vid->date = date;
	vid->name = _strdup(name);
	vid->description = _strdup(descr);
	vid->url = _strdup(url);

	return vid;
}

void add_comment_video(video* v, comment* c) {

	v->comments_count++; // ���������� ���������� ������������ �� �������
	if (v->comments == NULL)  // ���� ������ ������������ ������, �� �������� ������ ��� ������ ��������
	{
		v->comments = (comment*)malloc(sizeof(comment));
	}
	else  // ����� ������������ ������ ��� ������������ ������� ������������ 
	{
		v->comments = (comment*)realloc(v->comments, sizeof(comment) * v->comments_count);
	}

	v->comments[v->comments_count - 1] = *c;

}


void like_video(video* p, int likes)
{
	p->likes += likes;
}

void dislike_video(video* p, int dislikes)
{
	p->dislikes += dislikes;
}

void view_video(video* p, int views)
{
	p->views += views;
}

void free_video(video* v)
{
	free(v->name);
	free(v->description);
	free(v->url);
	for (int i = 0; i < v->comments_count; i++) {

		free_comment(&v->comments[i]);
	}
	free(v->comments);
}

void input_video(video* v)
{
	printf("\n���� �����.\n");

	char name[name_lenght];
	char url[url_lenght];
	char description[description_lenght];
	upload_date date;

	free(v->name);
	printf("������� ��� ����: ");
	fgets(name, sizeof(name), stdin);
	*(strchr(name, '\n')) = 0;
	v->name = _strdup(name);

	free(v->url);
	printf("������� ������ �� ����: ");
	fgets(url, sizeof(url), stdin);
	*(strchr(url, '\n')) = 0;
	v->url = _strdup(url);

	free(v->description);
	printf("������� �������� ����: ");
	fgets(description, sizeof(description), stdin);
	*(strchr(description, '\n')) = 0;
	v->description = _strdup(description);

	input_date(&v->date);

}


