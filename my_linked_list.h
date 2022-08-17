#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Узел (элемент) связанного списка
typedef struct userL {
    int uid;
    char name[20];
    struct userL *next;
} userL;


userL *head_user = NULL; //Указатель на начало списка (глобальная переменная)


//Добавление элемента в начало связанного списка
void insert_user(int uid, char *name){
    userL *new_user;
    new_user = malloc(sizeof(userL)); //выделяется память под структуру в куче
    strcpy(new_user->name, name); //копируется строка
    new_user->uid = uid;
    new_user->next = head_user; //добавляем в начало, забираем указатель у head
    head_user = new_user; // теперь head указывает на добавленного пользователя
}


//Удаление элемента из списка
void delete_user(int uid){
    userL *cur;
    userL *prev;
    prev = NULL;
    cur = head_user; //Начинаем с начала
    while(cur != NULL){
        if (cur ->uid == uid){
            if (prev == NULL){
                //Если найденный элемент в начале списка
                head_user = cur->next; //Поменяли указатель head
                printf("User %s deleted\n", cur->name);
                free(cur);
                return;
            }
            prev->next = cur->next; // Указатель предыдущего элемента поменяли
            printf("User %s deleted\n", cur->name);
            free(cur);
            return;
        }
        prev = cur; //Сдвиг на следующий
        cur = cur->next;
    }
    printf("User with uid: %d not found\n", uid);
}


//Печать списка
void print_list(){
    if (head_user == NULL){
        printf("List is void \n");
        return;
    }
    userL *cur;
    cur = head_user; // начинаем с головы
    while (cur!=NULL){
        printf("user id: %d, user name: %s \n", cur->uid, cur->name);
        cur = cur->next;
    }
}


//Найти пользователя по id и вернуть указатель на него
userL *find_user(int uid){
    userL *cur = head_user;
    while(cur!= NULL){
        if (cur -> uid == uid){
            return cur;
        }
        cur = cur -> next;
    }
    return NULL;
}


//Вывод информации о пользователе
void get_info(userL *user){
    if (user == NULL){
        printf("User is not found\n");
        return;
    }
    printf("User id: %d, user name: %s\n", user->uid, user->name);
    return;
}


//Вернуть размер связанного списка
int size_of_list(){
    int count = 0;
    userL *cur = head_user;
    while (cur != NULL){
        count++;
        cur = cur -> next;
    }
    return count;
}
