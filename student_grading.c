#include <stdio.h>

#define MAX_STUDENTS 100
#define SUBJECTS 3

void input_scores(int scores[][SUBJECTS], int n);
void compute_totals_and_averages(int scores[][SUBJECTS], int total[], double avg[], int n);
void compute_ranks(int total[], int rank[], int n);
void print_results(int scores[][SUBJECTS], int total[], double avg[], int rank[], int n);

int main(){
	int n;
	printf("?? ? ??: ");
	scanf("%d", &n);
	if(n <= 0 || n > MAX_STUDENTS){
		printf("?? ?? ??? ??????.\n");
		return 1;
	}
	
	int scores[MAX_STUDENTS][SUBJECTS];
	int total[MAX_STUDENTS];
	double avg[MAX_STUDENTS];
	int rank[MAX_STUDENTS];
	
	input_scores(scores, n);
	compute_totals_and_averages(scores, total, avg, n);
	compute_ranks(total, rank, n);
	print_results(scores, total, avg, rank, n);
	
	return 0;
}

void input_scores(int scores[][SUBJECTS], int n){
	int i, j;
	for (i = 0; i < n; i++){
		printf("?? %d? ?? ?? (3??): ", i + 1);
		for(j = 0; j < SUBJECTS; j++){
			scanf("%d", &scores[i][j]);
		}
	}
}

void compute_totals_and_averages(int scores[][SUBJECTS], int total[], double avg[], int n){
	int  i, j;
	for (i = 0; i < n; i++){
		int sum = 0;
		for (j = 0; j < SUBJECTS; j++){
			sum += scores[i][j];
		}
		total[i] = sum;
		avg[i] = sum / (double)SUBJECTS;
	}
}

void compute_ranks(int total[], int rank[], int n){
	int i, j;
	for (i = 0; i<n; i++){
		rank[i]= 1;
	}
	for (i = 0; i<n; i++){
		for(j=0; j<n; j++){
			if(total[j] > total[i]){
				rank[i]++;
			}
		}
	}
}

void print_results(int scores[][SUBJECTS], int total[], double avg[], int rank[], int n){
	int i,j;
	printf("\n--- ?? ---\n");
	printf("??\t eng\t kor\t math\t tot\t avg\n");
	for (i = 0; i < n; i++){
		printf("%3d\t", i + 1);
		for(j = 0; j < SUBJECTS; j++){
			printf("%3d\t", scores[i][j]);
		}
		printf("%d\t%.2f\t%2d\n", total[i], avg[i]);
	}
}
