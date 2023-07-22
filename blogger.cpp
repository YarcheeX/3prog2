#define _CRT_SECURE_NO_WARNINGS




#include "blogger.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

blogger* create_blogger(char* name, char* url, char* descr) {

	blogger* new_blogger = (blogger*)malloc(sizeof(blogger)); // ��������� ������ ��� �������
	new_blogger->name = _strdup(name); // ����������� ����� �������
	new_blogger->url = _strdup(url);
	new_blogger->description = _strdup(descr); // ����������� �������� �������

	return new_blogger; // ����������� ��������� �� ������ �������

	printf("\n������� ������.\n");
}

void add_photo(blogger* b, photo* p) {
	b->photo_count++; // ���������� ���������� ���� �� �������

	if (!b->photos) { // ���� ������ ���� ������, �� �������� ������ ��� ������ ��������
		b->photos = (photo*)malloc(sizeof(photo));
	}
	else { // ����� ������������ ������ ��� ������������ ������� ���� 
		b->photos = (photo*)realloc(b->photos, sizeof(photo) * b->photo_count);
	}

	b->photos[b->photo_count - 1] = *p;
	

	printf("\n���� ���������\n");
}

void add_video(blogger* b, video* v){

	b->video_count++; // ���������� ���������� ����� �� ���������

	if (!b->videos)  // ���� ������ ����� ������, �� �������� ������ ��� ������ ��������
	{	
		b->videos = (video*)malloc(sizeof(video));
	}
	else // ����� ������������ ������ ��� ������������ ������� ����� 
	{
		b->videos = (video*)realloc(b->videos, sizeof(video) * b->video_count);
	}

	b->videos[b->video_count - 1] = *v;
	

	printf("\nVideo has been added\n");
}


void free_blogger(blogger* b)
{
	if (!b) return; // ���� ��������� �� ������� ������, �� ������ �� ������

	if(b->name) free(b->name); // ���������� ������ �� ����� �������
	if (b->url) free(b->url);
	if (b->description) free(b->description);

	for (int i = 0; i < b->photo_count; i++) { // ��� ������� ���� � ������� ����
		
		free_photo(&b->photos[i]);
	}
	if(b->photos)free(b->photos); // ���������� ������ �� ������� ����


	for (int i = 0; i < b->video_count; i++) { // ��� ������� ����� � ������� �����
		
		free_video(&b->videos[i]);
	}
	if(b->videos)free(b->videos); // ���������� ������ �� ������� �����

	free(b); // ���������� ������ �� �������
}

void free_non_dinamic_blogger(blogger* b) {
	
	if (b->name) free(b->name); // ���������� ������ �� ����� �������
	if (b->url) free(b->url);
	if (b->description) free(b->description);

	for (int i = 0; i < b->photo_count; i++) { // ��� ������� ���� � ������� ����

		free_photo(&b->photos[i]);
	}
	if (b->photos)free(b->photos); // ���������� ������ �� ������� ����


	for (int i = 0; i < b->video_count; i++) { // ��� ������� ����� � ������� �����

		free_video(&b->videos[i]);
	}
	if (b->videos)free(b->videos); // ���������� ������ �� ������� �����
}

void print_blogger(blogger* b) {

	if (!b) return; // ���� ��������� �� ������� ������, �� ������ �� ��������

	printf("\n��� �������: %s\n", b->name); // ������� ��� �������
	printf("���������� �����������: %d\n", b->followers); // ������� ���������� �����������
	printf("������: %s\n", b->url);
	printf("�������� %s\n", b->description);

	printf("\n����:\n"); // ������� ��������� ��� ����
	if (b->photo_count == 0)
		printf("���� �����������.\n");
	else
		for (int i = 0; i < b->photo_count; i++) { // ��� ������� ���� � ������� ����
			printf("%d. %s (%s) - %d.%d.%d\n", i + 1, b->photos[i].name, b->photos[i].url, b->photos[i].date.day, b->photos[i].date.month, b->photos[i].date.year); // ������� �����, ��������, ������ � ���� �������� ����
			printf("���������: %d | �����: %d | ��������: %d | �����������: %d\n\n", b->photos[i].views, b->photos[i].likes, b->photos[i].dislikes, b->photos[i].comments_count);
		}
	

	printf("�����:\n"); // ������� ��������� ��� �����
	if (b->video_count == 0)
		printf("����� �����������.\n");
	else 
		for (int i = 0; i < b->video_count; i++) { // ��� ������� ����� � ������� �����
			printf("%d. %s (%s) - %d.%d.%d\n", i + 1, b->videos[i].name, b->videos[i].url, b->videos[i].date.day, b->videos[i].date.month, b->videos[i].date.year); // ������� �����, ��������, ������ � ���� �������� �����
			printf("���������: %d | �����: %d | ��������: %d | �����������: %d\n\n", b->videos[i].views, b->videos[i].likes, b->videos[i].dislikes, b->videos[i].comments_count);

		}
}

void input_blogger(blogger* b)
{

	printf("\n���� ��������.\n");

	char name[name_lenght];
	char url[url_lenght];
	char description[description_lenght];

	if (b->name) free(b->name);
	printf("������� ��� ��������: ");
	fgets(name, sizeof(name), stdin);
	*(strchr(name, '\n')) = 0;
	b->name = _strdup(name);
	
	if (b->url) free(b->url);
	printf("������� ������ �� ��������: ");
	fgets(url, sizeof(url), stdin);
	*(strchr(url, '\n')) = 0;
	b->url = _strdup(url);

	if (b->description) free(b->description);
	printf("������� �������� ��������: ");
	fgets(description, sizeof(description), stdin);
	*(strchr(description, '\n')) = 0;
	b->description = _strdup(description);
	
}
