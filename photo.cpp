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

	p->comments_count++; // увеличение количества комментариев на единицу
	if (p->comments == NULL)  // если массив комментариев пустой, то выделить пам€ть дл€ одного элемента
	{	
		p->comments = (comment*)malloc(sizeof(comment));
	}
	else  // иначе перевыделить пам€ть дл€ увеличенного массива комментариев 
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
	if (!p) return;
	
	if (p->name) free(p->name);
	if (p->url) free(p->description);
	if (p->description) free(p->url);
	for (int i = 0; i < p->comments_count; i++) {

		free_comment(&p->comments[i]);
	}
	
	if(p->comments) free(p->comments);

	free(p);
}

void free_non_dynamic_photo(photo* p) {

	if (p->name) free(p->name);
	if (p->url) free(p->description);
	if (p->description) free(p->url);
	for (int i = 0; i < p->comments_count; i++) {

		free_comment(&p->comments[i]);
	}

	if (p->comments) free(p->comments);
}


void input_photo(photo* p)
{

	printf("\n¬вод фото.\n");

	char name[name_lenght];
	char url[url_lenght];
	char description[description_lenght];
	upload_date date;

	if (p->name) free(p->name);
	printf("¬ведите им€ фото: ");
	fgets(name, sizeof(name), stdin);
	*(strchr(name, '\n')) = 0;
	p->name = _strdup(name);

	if (p->url) free(p->description);
	printf("¬ведите ссылку на фото: ");
	fgets(url, sizeof(url), stdin);
	*(strchr(url, '\n')) = 0;
	p->url = _strdup(url);

	if (p->description) free(p->url);
	printf("¬ведите описание фото: ");
	fgets(description, sizeof(description), stdin);
	*(strchr(description, '\n')) = 0;
	p->description = _strdup(description);

	input_date(&p->date);
}
