#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//���� (�������) ���������� ������
typedef struct userL {
    int uid;
    char name[20];
    struct userL *next;
} userL;


userL *head_user = NULL; //��������� �� ������ ������ (���������� ����������)


//���������� �������� � ������ ���������� ������
void insert_user(int uid, char *name){
    userL *new_user;
    new_user = malloc(sizeof(userL)); //���������� ������ ��� ��������� � ����
    strcpy(new_user->name, name); //���������� ������
    new_user->uid = uid;
    new_user->next = head_user; //��������� � ������, �������� ��������� � head
    head_user = new_user; // ������ head ��������� �� ������������ ������������
}


//�������� �������� �� ������
void delete_user(int uid){
    userL *cur;
    userL *prev;
    prev = NULL;
    cur = head_user; //�������� � ������
    while(cur != NULL){
        if (cur ->uid == uid){
            if (prev == NULL){
                //���� ��������� ������� � ������ ������
                head_user = cur->next; //�������� ��������� head
                printf("User %s deleted\n", cur->name);
                free(cur);
                return;
            }
            prev->next = cur->next; // ��������� ����������� �������� ��������
            printf("User %s deleted\n", cur->name);
            free(cur);
            return;
        }
        prev = cur; //����� �� ���������
        cur = cur->next;
    }
    printf("User with uid: %d not found\n", uid);
}


//������ ������
void print_list(){
    if (head_user == NULL){
        printf("List is void \n");
        return;
    }
    userL *cur;
    cur = head_user; // �������� � ������
    while (cur!=NULL){
        printf("user id: %d, user name: %s \n", cur->uid, cur->name);
        cur = cur->next;
    }
}


//����� ������������ �� id � ������� ��������� �� ����
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


//����� ���������� � ������������
void get_info(userL *user){
    if (user == NULL){
        printf("User is not found\n");
        return;
    }
    printf("User id: %d, user name: %s\n", user->uid, user->name);
    return;
}


//������� ������ ���������� ������
int size_of_list(){
    int count = 0;
    userL *cur = head_user;
    while (cur != NULL){
        count++;
        cur = cur -> next;
    }
    return count;
}
