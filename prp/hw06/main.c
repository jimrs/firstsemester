#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *cipher = malloc(sizeof(char));
	char *msg = malloc(sizeof(char));

	int move, lowest_move, matching, highest_matching;
	int c_size = 0;
	int m_size = 0;
	int alloc = 1;
	int newlines = 0;

	lowest_move = 500000;
	highest_matching = -500000;

	for (c_size = 0; newlines < 1; c_size++) {
		if (c_size == alloc) {
			alloc++;

			cipher = realloc(cipher, sizeof(char) * alloc);
		}

		cipher[c_size] = getchar();

		if (cipher[c_size] < 'A' || (cipher[c_size] > 'Z' && cipher[c_size] < 'a') || cipher[c_size] > 'z') {
			if (cipher[c_size] == 10);
			else {
				fprintf(stderr, "Error: Chybny vstup!\n");
				free(cipher);
				free(msg);
				return 100;
			}
		}

		if (cipher[c_size] == 10) { // 10 is newline
			newlines++;
			cipher[c_size] = '\0';
		}
	}

	alloc = 1;

	for (m_size = 0; newlines < 2; m_size++) {
		if (m_size == alloc) {
			alloc++;

			msg = realloc(msg, sizeof(char) * alloc);
		}

		msg[m_size] = getchar();

		if (msg[m_size] < 'A' || (msg[m_size] > 'Z' && msg[m_size] < 'a') || msg[m_size] > 'z') {
			if (msg[m_size] == 10);
			else {
				fprintf(stderr, "Error: Chybny vstup!\n");
				free(cipher);
				free(msg);
				return 100;
			}
		}

		if (msg[m_size] == 10) { // 10 is newline
			newlines++;
			msg[m_size] = '\0';
		}
	}

	if (m_size != c_size) {
		fprintf(stderr, "Error: Chybna delka vstupu!\n");
		free(cipher);
		free(msg);
		return 101;
	}


	for (move = 0; move < 58; move++) {
		matching = 0;

		for (int i = 0; i < c_size-1; i++) { //size-1 jelikoz na konci je \0
			int current = cipher[i] + move;

			if (current > 'Z' && current < 'a')
				current = current + 6;

			else if (current > 'z')
				current = current - 58;

			//putchar(current);

			if (current == msg[i])
				matching++;

		}

		//printf(" %d\n", matching);

		if (matching > highest_matching) {
			highest_matching = matching;
			lowest_move = move;
		}
	}


	//printf("-------------------\n");
	//printf("%d\n", lowest_move);
	//printf("%d\n", highest_matching);
	//printf("-------------------\n");


	//printf("%s\n", cipher);

	//char *result = malloc(sizeof(char) * (c_size));

	for (int i = 0; i < c_size-1; i++) {
		int current = cipher[i] + lowest_move;
		
		if (current > 'Z' && current < 'a')
			cipher[i] = current + 6;

		else if (current > 'z')
			cipher[i] = current - 58;
		else
			cipher[i] = current;
	
	}

	printf("%s\n", cipher);

	free(cipher);
	free(msg);
	//free(result);

	return 0;
}
