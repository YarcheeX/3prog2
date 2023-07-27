#define _CRT_SECURE_NO_WARNINGS
#include "blogger.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//������� ��������
blogger* create_blogger(const char* name, const char* url, const char* descr) {

	blogger* new_blogger = (blogger*)malloc(sizeof(blogger)); // ��������� ������ ��� �������
	init_blogger(new_blogger); //�������������
	new_blogger->name = _strdup(name); // ����������� ����� �������
	new_blogger->url = _strdup(url);
	new_blogger->description = _strdup(descr); // ����������� �������� �������

	return new_blogger; // ����������� ��������� �� ������ �������

	printf("\n������� ������.\n");
}

//�������� ����
void add_photo(blogger* b, photo* p) {

	b->photo_count++; 

	//������������ ������ ��� ���������� ����
	b->photos = (photo**)realloc(b->photos, sizeof(photo*) * b->photo_count);

	b->photos[b->photo_count - 1] = p;
	
	printf("���� ���������.\n");
}

//�������� �����
void add_video(blogger* b, video* v){

	b->video_count++; 

	//������������ ������ ��� ���������� �����
	b->videos = (video**)realloc(b->videos, sizeof(video*) * b->video_count);

	b->videos[b->video_count - 1] = v;
	

	printf("����� ���������.\n");
}

//������������ ��������
void free_blogger(blogger* b)
{
	// ���� ��������� �� �������� ������, �� ������ �� ������
	if (!b) return; 
	
	// ���������� ������ �� ����� ��������
	if (b->name) {
		free(b->name); 
		b->name = nullptr;
	}
	
	// ���������� ������ �� ������ �� ��������
	if (b->url) {
		free(b->url);
		b->url = nullptr;
	}

	// ���������� ������ �� �������� ������ ��������
	if (b->description) {
		free(b->description);
		b->description = nullptr;
	}

	// ��� ������� ���� � ������� ����
	for (int i = b->photo_count-1; i >= 0; i--) { 
		
		free_photo(b->photos[i]);
	}

	// ���������� ������ ����
	if (b->photos) {
		free(b->photos); 
		b->photos = nullptr;
	}

	// ��� ������� ����� � ������� �����
	for (int i = b->video_count-1; i >= 0; i--) { 
		
		free_video(b->videos[i]);
	}

	// ���������� ������ �����
	if (b->videos) {
		free(b->videos);
		b->videos;
	}

	// ���������� ������ �� �������
	free(b); 
	b = nullptr;
}

//����� ��������
void print_blogger(blogger* b) {

	// ���� ��������� �� ������� ������, �� ������ �� ��������
	if (!b) return; 
	
	printf("\n��� �������: %s\n", b->name);
	printf("���������� �����������: %d\n", b->followers); 
	printf("������: %s\n", b->url);
	printf("�������� %s\n", b->description);

	printf("\n����:\n"); 
	if (b->photo_count == 0)
		printf("���� �����������.\n");
	else
		for (int i = 0; i < b->photo_count; i++) {
			print_photo(b->photos[i]);
		}


	printf("\n�����:\n"); 
	if (b->video_count == 0)
		printf("����� �����������.\n");
	else
		for (int i = 0; i < b->video_count; i++) { 
			print_video(b->videos[i]);
		}
}

//���� ��������
void input_blogger(blogger* b)
{
	printf("\n���� ��������.\n");

	char name[name_lenght];
	char url[url_lenght];
	char description[description_lenght];

	if (b->url) free(b->name);
	printf("������� ��� ��������: ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';
	b->name = _strdup(name);
	
	if (b->url) free(b->url);
	printf("������� ������ �� ��������: ");
	fgets(url, sizeof(url), stdin);
	url[strlen(url) - 1] = '\0';
	b->url = _strdup(url);

	if (b->description) free(b->description);
	printf("������� �������� ��������: ");
	fgets(description, sizeof(description), stdin);
	description[strlen(description) - 1] = '\0';
	b->description = _strdup(description);
	
}

//������������� ��������
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
