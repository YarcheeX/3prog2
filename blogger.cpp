#define _CRT_SECURE_NO_WARNINGS
#include "blogger.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//создать блоггера
blogger* create_blogger(const char* name, const char* url, const char* descr) {

	blogger* new_blogger = (blogger*)malloc(sizeof(blogger)); // выделение памяти для блогера
	init_blogger(new_blogger); //инициализация
	new_blogger->name = _strdup(name); // копирование имени блогера
	new_blogger->url = _strdup(url);
	new_blogger->description = _strdup(descr); // копирование описания профиля

	return new_blogger; // возвращение указателя на нового блогера

	printf("\nБлоггер создан.\n");
}

//добавить фото
void add_photo(blogger* b, photo* p) {

	b->photo_count++; 

	//перевыделить память при добавлении фото
	b->photos = (photo**)realloc(b->photos, sizeof(photo*) * b->photo_count);

	b->photos[b->photo_count - 1] = p;
	
	printf("Фото добавлено.\n");
}

//добавить видео
void add_video(blogger* b, video* v){

	b->video_count++; 

	//перевыделить память при добавлении видео
	b->videos = (video**)realloc(b->videos, sizeof(video*) * b->video_count);

	b->videos[b->video_count - 1] = v;
	

	printf("Видео добавлено.\n");
}

//освобождение блоггера
void free_blogger(blogger* b)
{
	// если указатель на блоггера пустой, то ничего не делать
	if (!b) return; 
	
	// освободить память от имени блоггера
	if (b->name) {
		free(b->name); 
		b->name = nullptr;
	}
	
	// освободить память от ссылки на блоггера
	if (b->url) {
		free(b->url);
		b->url = nullptr;
	}

	// освободить память от описания канала блоггера
	if (b->description) {
		free(b->description);
		b->description = nullptr;
	}

	// для каждого фото в массиве фото
	for (int i = b->photo_count-1; i >= 0; i--) { 
		
		free_photo(b->photos[i]);
	}

	// освободить массив фото
	if (b->photos) {
		free(b->photos); 
		b->photos = nullptr;
	}

	// для каждого видео в массиве видео
	for (int i = b->video_count-1; i >= 0; i--) { 
		
		free_video(b->videos[i]);
	}

	// освободить массив видео
	if (b->videos) {
		free(b->videos);
		b->videos;
	}

	// освободить память от блогера
	free(b); 
	b = nullptr;
}

//вывод блоггера
void print_blogger(blogger* b) {

	// если указатель на блогера пустой, то ничего не выводить
	if (!b) return; 
	
	printf("\nИмя блогера: %s\n", b->name);
	printf("Количество подписчиков: %d\n", b->followers); 
	printf("Ссылка: %s\n", b->url);
	printf("Описание %s\n", b->description);

	printf("\nФото:\n"); 
	if (b->photo_count == 0)
		printf("Фото отсутствуют.\n");
	else
		for (int i = 0; i < b->photo_count; i++) {
			print_photo(b->photos[i]);
		}


	printf("\nВидео:\n"); 
	if (b->video_count == 0)
		printf("Видео отсутствуют.\n");
	else
		for (int i = 0; i < b->video_count; i++) { 
			print_video(b->videos[i]);
		}
}

//ввод блоггера
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

//инициализация блоггера
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
