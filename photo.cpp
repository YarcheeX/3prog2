#define _CRT_SECURE_NO_WARNINGS

#include "photo.h"
#include <stdlib.h>
#include <string.h>


//создание фото
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

//добавление фото
void add_comment_photo(photo* p, comment* c) {

	p->comments_count++; 

	//перевыделить пам€ть при добавлении комментари€
	p->comments = (comment**)realloc(p->comments, sizeof(comment*) * p->comments_count);

	p->comments[p->comments_count - 1] = c;

}

//лайкнуть фото
void like_photo(photo* p, int likes){
	p->likes += likes;
}

//дизлайкнуть фото
void dislike_photo(photo* p, int dislikes){
	p->dislikes += dislikes;
}

//посмотреть фото
void view_photo(photo* p, int views) {
	p->views += views;
}

//освободить фото
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

//ввод фото
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
	name[strlen(name) - 1] = '\0';
	p->name = _strdup(name);

	if (p->url) free(p->url);
	printf("¬ведите ссылку на фото: ");
	fgets(url, sizeof(url), stdin);
	url[strlen(url) - 1] = '\0';
	p->url = _strdup(url);

	if (p->description) free(p->description);
	printf("¬ведите описание фото: ");
	fgets(description, sizeof(description), stdin);
	description[strlen(description) - 1] = '\0';
	p->description = _strdup(description);

	input_date(&p->date);
}

//инициализаци€ фото
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
