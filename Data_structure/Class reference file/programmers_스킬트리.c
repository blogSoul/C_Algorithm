#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// skill_trees_len은 배열 skill_trees의 길이입니다.
int solution(const char* skill, const char* skill_trees[], size_t skill_trees_len) {
    int answer = 0; // 가능한 원소수
    int i = 0, check = 1, j, count = 0, k, a;
    char *p = (char*)malloc(strlen(skill) * sizeof(char)), q[20];
    int *p_count = (int*)calloc(strlen(skill), sizeof(int));
    strcpy(p, skill);
    for(i = 0 ; i < skill_trees_len; i++){
        for(j = 0 ; j < strlen(skill_trees[i]); j++){
            for(k = 0; k < strlen(skill); k++){
                if(skill_trees[i][j] == p[k]){
                    p_count[k]++;
                    for(a = 0; a < strlen(skill) - 1; a++){
                        if(p_count[a] < p_count[a+1]){
                            check = 0;
                            break;
                        }
                    }
                    /*
                    for(a = 0; a < strlen(skill); a++){
                        printf("%d", p_count[a]);
                    }
                    printf("\n");
                    */
                }
                if(check == 0)
                    break;
            }
            if(check == 0)
                break;
        }
        if(check == 1)
            answer++;
        else
            check = 1;
        for(a = 0; a < strlen(skill); a++)
            p_count[a] = 0;
    }
    return answer;
}
