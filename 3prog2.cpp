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
	
	blogger Alex = { name, url, descr, 0, nullptr, 0, nullptr, 0 };
	photo pho;
	input_photo(&pho);
	add_photo(&Alex, &pho);
	comment comm;
	input_comment(&comm);
	add_comment_photo(&pho, &comm);
	
	blogger* Ivan = (blogger*)malloc(sizeof(blogger));
	input_blogger(Ivan);
	video* v;
	v = create_video(_strdup("лайфак"), _strdup("zxcbcgb"), _strdup("рабочий"), {10,2,2010});
	add_comment_video(v, create_comment(_strdup("Шляпа, не работает"), _strdup("Честный пользователь"), { 10, 3, 2010 }));


	print_blogger(&Alex);
	print_blogger(Ivan);

	free_non_dinamic_blogger(&Alex);
	free_blogger(Ivan);

}