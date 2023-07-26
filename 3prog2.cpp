#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#include "blogger.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>


int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color f0");

	char name[] = "Alex";
	char url[] = "qwerty";
	char descr[] = "Развлекательный контент";
	
	blogger Alex = { name, url, descr, 0, nullptr, 0, nullptr, 0 }; //
	photo pho;														//
	input_photo(&pho);												//
	add_photo(&Alex, &pho);											//статические струтуры
	comment comm;													//
	input_comment(&comm);											//
	add_comment_photo(&pho, &comm);									//
	
	blogger* Ivan = (blogger*)malloc(sizeof(blogger));													//
	init_blogger(Ivan);																					//
	input_blogger(Ivan);																				//
	video* v = create_video("лайфак", "рабочий", "zxcvbnm", {10, 2, 2010});								//динамические струткуры
	add_comment_video(v, create_comment("Обман! Не работает", "Честный пользователь", { 10, 3, 2010 }));//
	add_comment_video(v, create_comment("Полная дезинформация", "Еще честнее", { 20, 8, 2020 }));		//
	add_video(Ivan, v);

	print_blogger(&Alex);
	print_blogger(Ivan);

	free(pho.name);			//
	free(pho.description);	//
	free(pho.url);			//
	free(comm.text);		//очистка статических струткур
	free(comm.author);		//
	free(pho.comments);		//
	free(Alex.photos);		//

	free_blogger(Ivan);     //очистка динамических структур


	_CrtDumpMemoryLeaks();

}