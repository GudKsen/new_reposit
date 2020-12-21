#include<lib.h>
int main() {
#define STR 5
#define COL 5
	int arr[STR][COL];
	
	int count = 0;

	for (int i = 0; i < STR; i++) {
		for (int j = 0; j < COL; j++) {
			*(*(arr+i)+j) = rand() % 99;
		}
	}

	int* line_arr = (int*)malloc(STR * COL * sizeof(int));


	for (int i = 0; i < STR; i++) {
		for (int j = 0; j < COL; j++) {
			if (i == j) {
				count++;
			}
		}
	}


	int* res = (int*)malloc(count * sizeof(int));

	for(int i = 0; i < STR; i++) {
		for(int j = 0; j < COL; j++) {
			*(line_arr + i * STR + j) = *(*(arr + i) + j);
		}
	}
	
	main_diagonal(STR, COL, &line_arr, &res);
	
	sort_array(count, res);
	free(res);
	return 0;
}