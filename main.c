#include "my_linked_list.h"


int main()
{
    //Insert 3 users
    insert_user(1, "alex");
    insert_user(2, "anton");
    insert_user(3, "vlad");
    printf("--------\n");

    //Print linked list
    print_list();
    printf("--------\n");

    //Find user
    userL *p = find_user(3);

    //Get info about user
    get_info(p);
    printf("--------\n");

    //Delete users
    delete_user(3);
    delete_user(5);
    printf("--------\n");

    //Print linked list
    print_list();
    printf("--------\n");

    //Insert 2 users
    insert_user(4, "dmitry");
    insert_user(5, "ivan");

    //Print linked list
    print_list();
    printf("--------\n");

    //Print size of linked list
    printf("There are %d users in users list\n", size_of_list());

    delete_user(1);
    delete_user(2);
    delete_user(4);
    delete_user(5);
    delete_user(6);
    printf("--------\n");
    printf("There are %d users in users list\n", size_of_list());
    print_list();

    return 0;
}
