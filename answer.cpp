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
	free(a->author);
	free(a->text);
}
