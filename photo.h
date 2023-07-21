#pragma once
#include "upload_date.h"
#include "comment.h"

struct photo {

	char* name = nullptr;
	char* description = nullptr;
	char* url = nullptr; // ������ �� ����
	struct upload_date date; // ���� �������� ���� 
	int views; // ���������� ���������� ����
	int likes; // ���������� ������ ����
	int dislikes;
	struct comment* comments = nullptr;
	int comments_count = 0;
};

photo* create_photo(char* name, char* descr, char* url, upload_date date);
void add_comment_photo(photo* p, comment* c);
void like_photo(photo* p, int likes);
void dislike_photo(photo* p, int dislikes);
void view_photo(photo* p, int views);
void free_photo(photo* p);
void input_photo(photo* p);