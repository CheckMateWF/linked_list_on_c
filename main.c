#include "my_linked_list.h"


int main()
{
    //Вставка трех элементов
    insert_user(1, "alex");
    insert_user(2, "anton");
    insert_user(3, "vlad");
    printf("--------\n");

    //Печать списка
    print_list();
    printf("--------\n");

    //Найди пользователя по id
    userL *p = find_user(3);

    //Вывести информацию о пользователе
    get_info(p);
    printf("--------\n");

    //Удаление пользователя
    delete_user(3);
    delete_user(5);
    printf("--------\n");

    //Печать списка
    print_list();
    printf("--------\n");

    //Добавить еще двух пользователей
    insert_user(4, "dmitry");
    insert_user(5, "ivan");

    //Печать списка
    print_list();
    printf("--------\n");

    //Количество элементов в списке
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
