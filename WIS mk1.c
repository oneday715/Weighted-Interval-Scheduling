//#include <stdio.h>
//#include <stdlib.h>
//#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
//#ifndef max
//#define max(a, b) (((a)>(b)) ? (a) : (b))
//#endif
//
//typedef struct schedule{
//    int start, finish, weight, post;
//}schedule;
//
//
///*끝나는 순서로 퀵정렬*/
////pivot을 임의로 설정
////right부터 탐색하도록 변경 요망
//void finish_quickSort(schedule list[], int left, int right){
//    int pivot;
//    int i, j;
//    schedule temp;
//    if(left < right){
//        i = left;
//        j = right + 1;
//        pivot = list[left].finish;
//        do{
//            do i++; while(list[i].finish < pivot);
//            do j--; while(list[j].finish > pivot);
//            if(i<j) SWAP(list[i], list[j], temp);
//        }while(i<j);
//        SWAP(list[left], list[j], temp);
//        finish_quickSort(list, left, j-1);
//        finish_quickSort(list, j+1, right);
//    }
//}
//
//
///*p 값 찾기, key = list[i].start*/
//void findPost(schedule list[], int key, int left, int right, int i){
//    while(left < right){
//        int middle = (right + left)/2;
//        if(list[middle].finish < key){
//            left = middle + 1;
//        }
//        else right = middle;
//    }
//    list[i].post = left - 1;
//}
//
//
//int main(void){
//    int i;
//    int n;   //영화의 개수
//    scanf("%d", &n);
//    schedule list[n+1];
//    schedule temp;
//    list[0].start = 0;
//    list[0].finish = 0;
//    list[0].weight = 0;
//    for(i=1;i<=n;i++){ //a, b, p 입력
//        scanf("%d %d %d", &list[i].start, &list[i].finish, &list[i].weight);
//    }
//        
//    finish_quickSort(list, 1, n);
//
//    
//    //finish가 같은 경우 weight 큰 순서로 정렬 O(n)
//    for(i=1;i<=n;i++){
//        if(list[i].finish == list[i-1].finish){
//            if(list[i].weight < list[i-1].weight){
//                SWAP(list[i], list[i-1], temp);
//            }
//        }
//    }
//    
////    for(i=1;i<=n;i++){
////        printf("%d %d %d\n",list[i].start, list[i].finish, list[i].weight);
////    }
//    
//    for(i=1;i<=n;i++){
//        findPost(list, list[i].start, 0, n+1, i);
//    }
//    
////    for(i=1;i<=n;i++){
////        printf("%d\n", list[i].post);
////    }
//    
//    int opt[n+1];
//    for(i=0;i<=n;i++){
//        opt[i] = 0;
//    }
//    for(i = 1; i<=n; i++){
//        opt[i] = max(list[i].weight + opt[list[i].post], opt[i-1]);
//    }
//    printf("%d\n", opt[n]);
//    return 0;
//}







