#include "answer.h"
#include <stdlib.h>

answer* create_answer(const char* text, const char* author, upload_date d)
{
	answer* ans = (answer*)malloc(sizeof(answer));
	init_answer(ans);
	ans->text = _strdup(text);
	ans->author = _strdup(author);
	ans->date = d;

	return ans;
}

void free_answer(answer* a)
{
	if (!a) return;

	if (a->author) {
		free(a->author);
		a->author = nullptr;
	}
	if (a->text) {
		free(a->text);
		a->text = nullptr;
	}
	free(a);
	a = nullptr;
}

void init_answer(answer* a)
{
	a->text = nullptr;
	a->author = nullptr;
	init_date(&a->date);
}

