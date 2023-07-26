#pragma once
#include "upload_date.h"
#include "comment.h"

struct video {

	char* name = nullptr;               // название видео
	char* description = nullptr;        // описание видео
	char* url = nullptr;                // ссылка на видео
	upload_date date;                   // дата загрузки видео
	int views = 0;                      // количество просмотров видео
	int likes = 0;                      // количество лайков видео
	int dislikes = 0;                   // количество дизлайков видео
	struct comment** comments = nullptr;// массив комментариев
	int comments_count = 0;				// кол-во комментариев
};

video* create_video(const char* name, const char* descr, const char* url, upload_date date);
void add_comment_video(video* p, comment* c);
void like_video(video* p, int likes);
void dislike_video(video* p, int likes);
void view_video(video* p, int views);
void free_video(video* v);
void input_video(video* v);
void init_video(video* v);