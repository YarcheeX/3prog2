#pragma once
#include "upload_date.h"
#include "comment.h"

struct video {

	char* name = nullptr; // �������� �����
	char* description = nullptr;
	char* url = nullptr; // ������ �� �����
	struct upload_date date; // ���� �������� �����
	int views = 0; // ���������� ���������� �����
	int likes = 0; // ���������� ������ �����
	int dislikes = 0; // ���������� ��������� �����
	struct comment* comments = nullptr;
	int comments_count = 0;
};

video* create_video(char* name, char* descr, char* url, upload_date date);
void add_comment_video(video* p, comment* c);
void like_video(video* p, int likes);
void dislike_video(video* p, int likes);
void view_video(video* p, int views);
void free_video(video* v);
void input_video(video* v);