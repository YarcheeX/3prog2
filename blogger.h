#pragma once

#include "photo.h"
#include "video.h"

struct blogger {

	char* name = nullptr;        //название блоггера
	char* url = nullptr;		 //ссылка на блоггера
	char* description = nullptr; //описание канала блоггера
	int followers = 0;			 //количество подписчиков
	photo** photos = nullptr;	 //массив фото
	int photo_count = 0;		 //кол-во фото
	video** videos = nullptr;	 //массив видео
	int video_count = 0;		 //кол-во видео

};

blogger* create_blogger(const char* name, const char* url, const char* descr);

void add_photo(blogger* b, photo *p);

void add_video(blogger* b, video* v);

void free_blogger(blogger* b);

void print_blogger(blogger* b);

void input_blogger(blogger* b);

void init_blogger(blogger* b);