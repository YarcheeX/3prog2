#pragma once

#include "photo.h"
#include "video.h"

struct blogger {

	char* name = nullptr;
	char* url = nullptr;
	char* description = nullptr;
	int followers = 0;
	struct photo* photos = nullptr;
	int photo_count = 0;
	struct video* videos = nullptr;
	int video_count = 0;

};

blogger* create_blogger(char* name, char* url, char* descr);

void add_photo(blogger* b, photo *p);

void add_video(blogger* b, video* v);

void free_blogger(blogger* b);

void free_non_dinamic_blogger(blogger* b);

void print_blogger(blogger* b);

void input_blogger(blogger* b);
