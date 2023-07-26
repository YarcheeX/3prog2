#define _CRT_SECURE_NO_WARNINGS

#include "video.h"
#include <stdlib.h>
#include <string.h>


video* create_video(const char* name, const char* descr, const char* url, upload_date date)
{
	video* vid = (video*)malloc(sizeof(video));
	init_video(vid);
	vid->date = date;
	vid->name = _strdup(name);
	vid->description = _strdup(descr);
	vid->url = _strdup(url);

	return vid;
}

void add_comment_video(video* v, comment* c) {

	v->comments_count++; // увеличение количества комментариев на единицу
	
	v->comments = (comment**)realloc(v->comments, sizeof(comment*) * v->comments_count);

	v->comments[v->comments_count - 1] = c;

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
	
	if (v->name) {
		free(v->name);
		v->name = nullptr;
	}
	if (v->url) {
		free(v->url);
		v->url = nullptr;
	}
	if (v->description) {
		free(v->description);
		v->description = nullptr;
	}
	for (int i = v->comments_count-1; i >= 0; i--) {

		free_comment(v->comments[i]);
	}
	if (v->comments) {
		free(v->comments);
		v->comments = nullptr;
	}
	free(v);
	v = nullptr;
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
	name[strlen(name) - 1] = '\0';
	v->name = _strdup(name);

	if (v->url) free(v->url);
	printf("¬ведите ссылку на видео: ");
	fgets(url, sizeof(url), stdin);
	url[strlen(url) - 1] = '\0';
	v->url = _strdup(url);

	if (v->description) free(v->description);
	printf("¬ведите описание видео: ");
	fgets(description, sizeof(description), stdin);
	description[strlen(description) - 1] = '\0';
	v->description = _strdup(description);

	input_date(&v->date);

}

void init_video(video* v)
{
	v->name = nullptr;
	v->description = nullptr;
	v->url = nullptr;
	v->comments = nullptr;
	init_date(&v->date);
	v->views = 0;
	v->likes = 0;
	v->dislikes = 0;
	v->comments_count = 0;
}


