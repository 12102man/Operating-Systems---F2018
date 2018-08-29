 #include <stdio.h>
 #include <string.h>
 #define buffer_size 1024

char * reverse(char inp[]) {
	int length = strlen(inp);
	char reverse_string[buffer_size];
	for (int i=length-1; i>=0; i--) {
		reverse_string[length-1-i] = inp[i];
	}
	return reverse_string;
}

int main() {
	char input_string[buffer_size];
	printf("Please, enter the string: ");
	scanf("%s", input_string);

	printf("%s\n", reverse(input_string));
}