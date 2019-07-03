#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int* random_num(int digit)
{
	int *answer;
	answer = (int*)malloc(sizeof(int)*digit);
	int i = 0,j;

	srand((unsigned int)getpid());
	
	while(i < digit){
		int dup = 1;
		int tmp = rand() % 10;
		for(j = 0; j < i; j++){
			if(answer[j] == tmp){
				dup = 0;
			}
		}
		if(dup == 1){
			answer[i] = tmp;
			i++;
		}	
	}
	return answer;
}

int hit_blow(int *answer, int *hit, int *blow, char *num, int digit)
{
	int i, j;
	char cp_num[10];
	int atoi_num;
	if(strlen(num) != digit){
		return 1;
	}
	for(i = 0; i < digit; i++){
		for(j = 0; j < digit; j++){
			strncpy(cp_num, num+j, 1);
			atoi_num = atoi(cp_num);
			if(atoi_num < 1 || atoi_num > 10){
				return 1;
			}
			if(*(answer+i) == atoi_num && i == j){
				*hit = *hit + 1;
			}
			if(*(answer+i) == atoi_num && i != j){
				*blow = *blow + 1;
			}
		}
	}
	return 0;
}
	

int main(int argc, char *argv[])
{
	int hit, blow, i;
	int digit = atoi(argv[1]);
	int *answer;
	char input_num[256];

	if(digit < 1 || digit > 10){
		exit(EXIT_FAILURE);
	}

	answer = random_num(digit);

	while(1){
		hit = 0;
		blow = 0;
		printf("%d桁の数値を入力してください: ", digit);
		scanf("%s", input_num);
		if(hit_blow(answer, &hit, &blow, input_num, digit)){
			continue;
		}
		i++;
		printf("%dHit %dBlow\n", hit, blow);
		if(hit == digit){
			break;
		}
	}

	printf("Congratulations!\n%d回で正解しました.\n", i);
	

	return 0;
}
