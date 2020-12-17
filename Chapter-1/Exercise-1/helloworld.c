#include <stdio.h>

int main() {
	printf("hello, world\n");
}

// int main() is needed because of C89 revision, read:
// https://stackoverflow.com/a/31673379

// - If you forget .h extension -> fatal error: stdio: No such file or directory.
// - If you forget ; at end of statement -> error: expected ‘;’ before ‘}’ token.
// - If you forget the quotes "", the compiler thinks the words are undeclared
// variables.
