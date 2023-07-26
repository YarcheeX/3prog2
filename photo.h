#pragma once
#include "upload_date.h"
#include "comment.h"

struct photo {

	char* name = nullptr;
	char* description = nullptr;
	char* url = nullptr; // ������ �� ����
	upload_date date; // ���� �������� ���� 
	int views = 0; // ���������� ���������� ����
	int likes = 0; // ���������� ������ ����
	int dislikes = 0;
	int comments_count = 0;
	comment** comments = nullptr;
};

photo* create_photo(const char* name, const char* descr, const char* url, upload_date date);
void add_comment_photo(photo* p, comment* c);
void like_photo(photo* p, int likes);
void dislike_photo(photo* p, int dislikes);
void view_photo(photo* p, int views);
void free_photo(photo* p);
void input_photo(photo* p);
void init_photo(photo* p);