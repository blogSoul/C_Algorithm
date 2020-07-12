#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// heights_len은 배열 heights의 길이입니다.
int* solution(int heights[], size_t heights_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)calloc(heights_len , sizeof(int)), i, j;
    for(i = 0; i < heights_len; i++){
        for(j = i; j >= 0; j--){
            if(heights[j] > heights[i]){
                answer[i] = j + 1;
                break;
            }
        }    
    }
    return answer;
}
