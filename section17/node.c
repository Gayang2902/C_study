#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

// struct node *add_to_list(struct node *list, int n);

struct node *read_numbers(void);

struct node *search_list(struct node *list, int n);

struct node *delete_from_list(struct node *list, int n);

int main(void)
{
    // 리스트의 첫번째 노드를 가리킴
    struct node *list;

    list = read_numbers();

    return 0;
}

// value = n인 노드를 리스트의 첫번째에 넣어줌
// struct node *add_to_list(struct node *list, int n)
// {
//     struct node *new_node;

//     new_node = malloc(sizeof(struct node));
//     if (new_node == NULL) {
//         printf("Error: malloc failed in add_to_list\n");
//         exit(EXIT_FAILURE);
//     }
//     new_node->value = n;
//     new_node->next = list;
//     return new_node;
// }

// double pointer 를 이용한 구현 (외부 함수인 add_to_list에서 main함수의 list를 변형시킬수 있다.)
// 실제로는 call-by-value이지만, call-by-address와 비슷한 방식을 이용해 (call-by-reference)처럼 작동시킴
void add_to_list(struct node **list, int n) 
{
    struct node *new_node;

    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = *list;
    *list = new_node;
}

// 일련의 n들을 입력받아 노드들을 생성해줌
struct node *read_numbers(void)
{
    struct node *first = NULL;
    int n;

    printf("Enter series of integers (0 to terminate): ");
    for (;;) {
        scanf("%d", &n);
        if (n == 0) { return first; }
        first = add_to_list(first, n);
    }
}

// n이 들어있는 node를 찾고 return, 없다면 null pointer(어차피 마지막 노드의 next는 null이 되도록 read_numbers에서 정의해주고 있다.) 리턴
struct node *search_list(struct node *list, int n)
{
    // ver1
    for (; list != NULL && list->value != n; list = list->next);

    // ver2
    while (list != NULL && list->value != n) { list = list->next; }
    return list;
}

struct node *delete_from_list(struct node *list, int n)
{
    struct node *cur;
    struct node *prev;

    for (cur = list, prev = NULL; 
         cur != NULL && cur->value != n;
         prev = cur, cur = cur->next);

    // n을 갖는 노드가 없을때
    if (cur == NULL) { return list; }
    // n이 첫번째 노드에 있을때
    if (prev == NULL) { list = list->next; } 
    // n을 찾음 (대부분의 상황)
    else { prev->next = cur->next; }
    free(cur);
    return list;
}