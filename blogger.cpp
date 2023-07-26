#define _CRT_SECURE_NO_WARNINGS




#include "blogger.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

blogger* create_blogger(const char* name, const char* url, const char* descr) {

	blogger* new_blogger = (blogger*)malloc(sizeof(blogger)); // выделение памяти для блогера
	init_blogger(new_blogger); //инициализация
	new_blogger->name = _strdup(name); // копирование имени блогера
	new_blogger->url = _strdup(url);
	new_blogger->description = _strdup(descr); // копирование описания профиля

	return new_blogger; // возвращение указателя на нового блогера

	printf("\nБлоггер создан.\n");
}

void add_photo(blogger* b, photo* p) {

	b->photo_count++; // увеличение количества фото на единицу

	b->photos = (photo**)realloc(b->photos, sizeof(photo*) * b->photo_count);

	b->photos[b->photo_count - 1] = p;
	
	printf("Фото добавлено.\n");
}

void add_video(blogger* b, video* v){

	b->video_count++; // увеличение количества видео на едининицу

	b->videos = (video**)realloc(b->videos, sizeof(video*) * b->video_count);

	b->videos[b->video_count - 1] = v;
	

	printf("Видео добавлено.\n");
}


void free_blogger(blogger* b)
{
	if (!b) return; // если указатель на блогера пустой, то ничего не делать

	if (b->name) {
		free(b->name); // освободить память от имени блогера
	}
	if (b->url) {
		free(b->url);
	}
	if (b->description) {
		free(b->description);
	}
	for (int i = b->photo_count-1; i >= 0; i--) { // для каждого фото в массиве фото
		
		free_photo(b->photos[i]);
	}
	if (b->photos) {
		free(b->photos); // освободить память от массива фото
	}
	for (int i = b->video_count-1; i >= 0; i--) { // для каждого видео в массиве видео
		
		free_video(b->videos[i]);
	}
	if (b->videos) {
		free(b->videos);
	}
	free(b); // освободить память от блогера
	b = nullptr;
}


void print_blogger(blogger* b) {

	if (!b) return; // если указатель на блогера пустой, то ничего не выводить

	printf("\nИмя блогера: %s\n", b->name); // вывести имя блогера
	printf("Количество подписчиков: %d\n", b->followers); // вывести количество подписчиков
	printf("Ссылка: %s\n", b->url);
	printf("Описание %s\n", b->description);

	printf("\nФото:\n"); // вывести заголовок для фото
	if (b->photo_count == 0)
		printf("Фото отсутствуют.\n");
	else
		for (int i = 0; i < b->photo_count; i++) { // для каждого фото в массиве фото
			printf("%d. %s (%s) - %d.%d.%d\n", i + 1, b->photos[i]->name, b->photos[i]->url, b->photos[i]->date.day, b->photos[i]->date.month, b->photos[i]->date.year); // вывести номер, название, ссылку и дату загрузки фото
			printf("Просмотры: %d | Лайки: %d | Дизлайки: %d | Комментарии: %d\n\n", b->photos[i]->views, b->photos[i]->likes, b->photos[i]->dislikes, b->photos[i]->comments_count);
		}


	printf("Видео:\n"); // вывести заголовок для видео
	if (b->video_count == 0)
		printf("Видео отсутствуют.\n");
	else
		for (int i = 0; i < b->video_count; i++) { // для каждого видео в массиве видео
			printf("%d. %s (%s) - %d.%d.%d\n", i + 1, b->videos[i]->name, b->videos[i]->url, b->videos[i]->date.day, b->videos[i]->date.month, b->videos[i]->date.year); // вывести номер, название, ссылку и дату загрузки видео
			printf("Просмотры: %d | Лайки: %d | Дизлайки: %d | Комментарии: %d\n\n", b->videos[i]->views, b->videos[i]->likes, b->videos[i]->dislikes, b->videos[i]->comments_count);

		}
}

void input_blogger(blogger* b)
{

	printf("\nВвод блоггера.\n");

	char name[name_lenght];
	char url[url_lenght];
	char description[description_lenght];

	if (b->url) free(b->name);
	printf("Введите имя блоггера: ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';
	b->name = _strdup(name);
	
	if (b->url) free(b->url);
	printf("Введите ссылку на блоггера: ");
	fgets(url, sizeof(url), stdin);
	url[strlen(url) - 1] = '\0';
	b->url = _strdup(url);

	if (b->description) free(b->description);
	printf("Введите описание блоггера: ");
	fgets(description, sizeof(description), stdin);
	description[strlen(description) - 1] = '\0';
	b->description = _strdup(description);
	
}

void init_blogger(blogger* b) {

	b->name = nullptr;
	b->url = nullptr;
	b->description = nullptr;
	b->photos = nullptr;
	b->videos = nullptr;
	b->followers = 0;
	b->photo_count = 0;
	b->video_count = 0;
}
