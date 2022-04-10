#include <iostream>
#include <cassert>
#include "ContactData.h"

int main() {
    ContactData cd1 = ContactData(1,2, "name");
    ContactData cd2 = ContactData(15,2, "name2");
    ContactData cd3 = ContactData();
    ContactData cd4 = ContactData(7,2, "name4");

    //Проверка значений по умолчанию
    assert(cd3.getContactNum()==0);
    printf("default\n");

    //Проверка связи контактов
    cd1.link(&cd2);
    cd1.link(&cd2);
    cd1.link(&cd3);
    cd2.link(&cd4);
    assert(cd1.isLinked(&cd2));
    assert(cd2.isLinked(&cd1));
    printf("link\n");

    //Если попытаться соединить с пустотой
    cd1.link(NULL);
    printf("link to null\n");

    //Проверка отвязывания
    cd1.unlink(&cd2);
    printf("unlink\n");
    cd1.unlink(&cd2);
    printf("unlink that wasn't linked\n");
    cd1.unlink(NULL);
    printf("unlink to null\n");
    return 0;
}
