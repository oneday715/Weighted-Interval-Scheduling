#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#ifndef max
#define max(a, b) (((a)>(b)) ? (a) : (b))
#endif
#define number 50001

typedef struct schedule {
    int start, finish, weight, post;
}schedule;
//끝나는 시점 퀵정렬
void finish_quickSort(schedule list[], int left, int right) {
    int pivot;
    int i, j;
    schedule temp;
    if (left < right) {
        i = left + 1;
        j = right;
        pivot = list[left].finish;
        while(i<=j){
            while (list[i].finish <= pivot)
                i++;
            while (list[j].finish > pivot)
                j--;
            if (i < j) SWAP(list[i], list[j], temp);
        };
        SWAP(list[left], list[j], temp);
        finish_quickSort(list, left, j-1);
        finish_quickSort(list, j+1, right);
    }
}
/*p값 찾기, key = list[i].start*/
void findPost(schedule list[], int key, int left, int right, int i) {
    while (left < right) {
        int middle = (right + left) / 2;
        if (list[middle].finish < key) {
            left = middle + 1;
        }
        else right = middle;
    }
    list[i].post = left - 1;
}
int main(void) {
    int i;
    int n;   //영화 개수
    scanf("%d", &n);
    schedule list[number];
    schedule temp;
    list[0].start = 0;
    list[0].finish = 0;
    list[0].weight = 0;
    for (i = 1; i <= n; i++) { //시작, 끝, 출연료 입력
        scanf("%d %d %d", &list[i].start, &list[i].finish, &list[i].weight);
    }

    //퀵 정렬
    finish_quickSort(list, 1, n);

    //finish가 같은 경우 weight가 큰 순서로 정렬
    for (i = 1; i <= n; i++) {
        if (list[i].finish == list[i - 1].finish) {
            if (list[i].weight < list[i - 1].weight) {
                SWAP(list[i], list[i - 1], temp);
            }
        }
    }
    for (i = 1; i <= n; i++) {
        findPost(list, list[i].start, 0, n + 1, i);
    }
    int opt[number];
    for (i = 0; i <= n; i++) {
        opt[i] = 0;
    }
    for (i = 1; i <= n; i++) {
        opt[i] = max(list[i].weight + opt[list[i].post], opt[i - 1]);
    }
    printf("%d\n", opt[n]);
    return 0;
}

