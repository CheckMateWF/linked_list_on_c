#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Node of linked list
typedef struct userL {
    int uid;
    char name[20];
    struct userL *next;
} userL;


userL *head_user = NULL; //Head of linked list (Global var)


//insert element to the beginning
void insert_user(int uid, char *name){
    userL *new_user;
    new_user = malloc(sizeof(userL)); //Allocate memory for a structure on the heap
    strcpy(new_user->name, name); //Copy name
    new_user->uid = uid;
    new_user->next = head_user;
    head_user = new_user; // Update head
}


//Delete element
void delete_user(int uid){
    userL *cur;
    userL *prev;
    prev = NULL;
    cur = head_user; //Start from beginnig
    while(cur != NULL){
        if (cur ->uid == uid){
            if (prev == NULL){
                //if element in beginning
                head_user = cur->next; //update head
                printf("User %s deleted\n", cur->name);
                free(cur);
                return;
            }
            prev->next = cur->next; // Update prev element pointer
            printf("User %s deleted\n", cur->name);
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    printf("User with uid: %d not found\n", uid);
}


//Print linked list
void print_list(){
    if (head_user == NULL){
        printf("List is void \n");
        return;
    }
    userL *cur;
    cur = head_user;
    while (cur!=NULL){
        printf("user id: %d, user name: %s \n", cur->uid, cur->name);
        cur = cur->next;
    }
}


//Find user
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


//Print info about user
void get_info(userL *user){
    if (user == NULL){
        printf("User is not found\n");
        return;
    }
    printf("User id: %d, user name: %s\n", user->uid, user->name);
    return;
}


//Get size of linked list
int size_of_list(){
    int count = 0;
    userL *cur = head_user;
    while (cur != NULL){
        count++;
        cur = cur -> next;
    }
    return count;
}
