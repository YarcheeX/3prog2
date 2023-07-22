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

	v->comments_count++; // увеличение количества комментариев на единицу
	if (!v->comments)  // если массив комментариев пустой, то выделить пам€ть дл€ одного элемента
	{
		v->comments = (comment*)malloc(sizeof(comment));
	}
	else  // иначе перевыделить пам€ть дл€ увеличенного массива комментариев 
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
	if (!v) return;
	
	if (v->name) free(v->name);
	if (v->url) free(v->description);
	if (v->description) free(v->url);
	for (int i = 0; i < v->comments_count; i++) {

		free_comment(&v->comments[i]);
	}
	
	if(v->comments)free(v->comments);

	free(v);
}

void free_non_dynamic_video(video* v) {

	if (v->name) free(v->name);
	if (v->url) free(v->description);
	if (v->description) free(v->url);
	for (int i = 0; i < v->comments_count; i++) {

		free_comment(&v->comments[i]);
	}

	if (v->comments) free(v->comments);
}

void input_video(video* v)
{
	printf("\n¬вод видео.\n");

	char name[name_lenght];
	char url[url_lenght];
	char description[description_lenght];
	upload_date date;

	if (v->name) free(v->name);
	printf("¬ведите название видео: ");
	fgets(name, sizeof(name), stdin);
	*(strchr(name, '\n')) = 0;
	v->name = _strdup(name);

	if (v->url) free(v->url);
	printf("¬ведите ссылку на видео: ");
	fgets(url, sizeof(url), stdin);
	*(strchr(url, '\n')) = 0;
	v->url = _strdup(url);

	if (v->description) free(v->description);
	printf("¬ведите описание видео: ");
	fgets(description, sizeof(description), stdin);
	*(strchr(description, '\n')) = 0;
	v->description = _strdup(description);

	input_date(&v->date);

}


