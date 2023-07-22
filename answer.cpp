#include "answer.h"
#include <stdlib.h>

answer* create_answer(char* text, char* author, upload_date d)
{
	answer* ans = (answer*)malloc(sizeof(answer));
	ans->text = _strdup(text);
	ans->author = _strdup(author);
	ans->date = d;

	return ans;
}

void free_answer(answer* a)
{
	if (!a) return;

	if(a->author) free(a->author);
	if(a->text)free(a->text);

	free(a);
}

void free_non_dynamic_answer(answer* a) {

	if (a->author) free(a->author);
	if (a->text)free(a->text);
}
