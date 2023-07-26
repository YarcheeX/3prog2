#pragma once

#include "photo.h"
#include "video.h"

struct blogger {

	char* name = nullptr;
	char* url = nullptr;
	char* description = nullptr;
	int followers = 0;
	photo** photos = nullptr;
	int photo_count = 0;
	video** videos = nullptr;
	int video_count = 0;

};

blogger* create_blogger(const char* name, const char* url, const char* descr);

void add_photo(blogger* b, photo *p);

void add_video(blogger* b, video* v);

void free_blogger(blogger* b);

void print_blogger(blogger* b);

void input_blogger(blogger* b);

void init_blogger(blogger* b);