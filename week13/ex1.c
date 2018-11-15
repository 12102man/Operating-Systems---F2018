#include <stdio.h>
#include <stdlib.h>


int is_value_in_array(int val, int *arr, int size){
    int i;
    for (i=0; i < size; i++) {
        if (arr[i] == val)
            return 1;
    }
    return 0;
}

int r_less_a(int index, int *r1, int *a1, int size) {
	for (int i=0; i< size; i++) {
		if (a1[i] < r1[i]) {
			return 0;
		}
	}
	return 1;
}


int main() {
	FILE* fp = fopen("input.txt", "r");

	int *e = malloc(sizeof(int)*3);
	int *a = malloc(sizeof(int)*3);
	int *c[5];
	int *r[5];

	for (int i=0; i<5; i++) {
        c[i] = (int *)malloc(3 * sizeof(int)); 
     	r[i] = (int *)malloc(3 * sizeof(int));
    }

	for (int i=0; i<3; i++) {
		int o;
		fscanf(fp, "%d", &o);
		e[i] = o;
	}

	for (int i=0; i<3; i++) {
		int o;
		fscanf(fp, "%d", &o);
		a[i] = o;
	}

	for (int i=0; i<5; i++) {
		for (int j=0; j<3; j++) {
			int o;
			fscanf(fp, "%d", &o);
			c[i][j] = o;
		}
	}

	for (int i=0; i<5; i++) {
		for (int j=0; j<3; j++) {
			int o;
			fscanf(fp, "%d", &o);
			r[i][j] = o;
		}
	}

	int o = 0;
	int *marked_processes = malloc(sizeof(int)*5);
	int cursor = 0;
	while (o < 5) {
		if ((is_value_in_array(o, marked_processes, 5) == 0) && (r_less_a(o, r[o], a, 5) == 0))  {
			for (int i=0; i< 5; i++) {
				a[i] += c[o][i];  
			}
			marked_processes[cursor] = o;
			cursor++;
			o = -1;
		}
		o++;
	}
	for (int i = 0; i<5; i++) {
		if (is_value_in_array(i, marked_processes, cursor) == 0) {
			printf("%d ", i);
		}
	}

}