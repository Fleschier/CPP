#include<stdio.h>
#include<string>


int main() {
	char c[100];
	char res[100];
	printf("please enter a stirng: ");
	scanf("%s", c);
	int index = 0;
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] >= 'A' && c[i] <= 'Z' || c[i] >= 'a' && c[i] <= 'z' || c[i] >= '0' && c[i] <= '9')
			res[index++] = c[i];
	}
	for (int i = 0; i < index; i++) printf("%c", res[i]);
	printf("\n");
	return 0;
}