int stack[] = {};
int slen = sizeof stack / sizeof *stack;
int addval = 0;
int newval;

int currval = 0;

char *code =
"int stack[] = {!};"
"int slen = sizeof stack / sizeof *stack;"
"int addval = 0;"
"int newval;"
""
"int currval = !;"
""
"char *code = !!!;"
"extern void *stdout;"
""
"void printcode() {"
"int i, j;"
"int c;"
"c = 0;"
"for (i = 0; code[i]; ++i) {"
"if (code[i] == '!') {"
"switch (c++) {"
"case 0:"
"for (j = 0; j < slen; ++j)"
"printf(!%d,!, stack[j]);"
"if (addval)"
"printf(!%d!, newval);"
"break;"
"case 1:"
"printf(!%d!, currval);"
"break;"
"case 3:"
"fputs(code, stdout);"
"break;"
"case 5: case 12:"
"putchar('!');"
"break;"
"default:"
"putchar('!');"
"break;"
"}"
"}"
"else "
"putchar(code[i]);"
"}"
"}"
""
"int main() {"
"if (__TIME__[6] == '0') {"
"switch (__TIME__[7]) {"
"case '0':"
"newval = stack[slen - 1] + stack[slen - 2];"
"addval = 1;"
"slen -= 2;"
"break;"
"case '1':"
"newval = stack[slen - 1] - stack[slen - 2];"
"addval = 1;"
"slen -= 2;"
"break;"
"case '2':"
"newval = stack[slen - 1] * stack[slen - 2];"
"addval = 1;"
"slen -= 2;"
"break;"
"case '3':"
"newval = stack[slen - 1] / stack[slen - 2];"
"addval = 1;"
"slen -= 2;"
"break;"
"case '4':"
"newval = currval;"
"addval = 1;"
"currval = 0;"
"break;"
"case '5':"
"slen = 0;"
"break;"
"}"
"}"
"else {"
"currval *= 10;"
"currval += __TIME__[7] - '0';"
"}"
"printcode();"
"}";
extern void *stdout;

void printcode() {
	int i, j;
	int c;
	c = 0;
	for (i = 0; code[i]; ++i) {
		if (code[i] == '!') {
			switch (c++) {
			/* haha c++ */
			case 0:
				for (j = 0; j < slen; ++j)
					printf("%d,", stack[j]);
				if (addval)
					printf("%d", newval);
				break;
			case 1:
				printf("%d", currval);
				break;
			case 3:
				fputs(code, stdout);
				break;
			case 5: case 12:
				putchar('!');
				break;
			default:
				putchar('"');
				break;
			}
		}
		else
			putchar(code[i]);
	}
}

int main() {
	if (__TIME__[6] == '0') {
		switch (__TIME__[7]) {
		case '0':
			newval = stack[slen - 1] + stack[slen - 2];
			addval = 1;
			slen -= 2;
			break;
		case '1':
			newval = stack[slen - 1] - stack[slen - 2];
			addval = 1;
			slen -= 2;
			break;
		case '2':
			newval = stack[slen - 1] * stack[slen - 2];
			addval = 1;
			slen -= 2;
			break;
		case '3':
			newval = stack[slen - 1] / stack[slen - 2];
			addval = 1;
			slen -= 2;
			break;
		case '4':
			newval = currval;
			addval = 1;
			currval = 0;
			break;
		case '5':
			slen = 0;
			break;
		}
	}
	else {
		currval *= 10;
		currval += __TIME__[7] - '0';
	}
	printcode();
}
