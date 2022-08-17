#include "my_linked_list.h"


int main()
{
    //������� ���� ���������
    insert_user(1, "alex");
    insert_user(2, "anton");
    insert_user(3, "vlad");
    printf("--------\n");

    //������ ������
    print_list();
    printf("--------\n");

    //����� ������������ �� id
    userL *p = find_user(3);

    //������� ���������� � ������������
    get_info(p);
    printf("--------\n");

    //�������� ������������
    delete_user(3);
    delete_user(5);
    printf("--------\n");

    //������ ������
    print_list();
    printf("--------\n");

    //�������� ��� ���� �������������
    insert_user(4, "dmitry");
    insert_user(5, "ivan");

    //������ ������
    print_list();
    printf("--------\n");

    //���������� ��������� � ������
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
