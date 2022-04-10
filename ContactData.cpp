//
// Created by User on 13.03.2022.
//

#include <iostream>
#include <algorithm>
#include "ContactData.h"
using namespace std;

ContactData::ContactData(int contact_num, int plate_num, const string& name)
{
    this->contact_num=contact_num;
    this->plate_num=plate_num;
    this->device_name=name;
    this->linked;
}

void ContactData::link(ContactData *second) {
//Проверяю, не нулевые ли указатели
    if(second==nullptr){
        printf("\tfailed link: nullpointer\n");
        return;
    }
    int f=this->contact_num;
    int s=second->contact_num;
//Хочу проверить, не связаны ли контакты и так
    for(int i : this->linked){
        if(i==s){
            printf("failed link: already linked\n");
            return;
        }
    }
//Связываю
//Вот здесь непонятно. Нужно по-хорошему еще проверить, что second связан с first тоже,
//но тогда нужно еще думать о том, как бороться со сломанной системой связок, когда 1 связан с 2, а 2 с 1 - нет,
//поэтому считаю, что все с этим хорошо.
    this->linked.push_back(s);
    second->linked.push_back(f);
}

void ContactData::unlink(ContactData *second) {
//Проверяю, не нулевые ли указатели
    if(second==nullptr){
        printf("\tfailed unlink: nullptr\n");
        return;
    }
    int f=this->contact_num;
    int s=second->contact_num;
    bool b=false;
//Хочу проверить, связаны ли контакты
    int i, j;
    for(i=0; i < (this->linked.size()); i++){ //Хочу в итоге в i сохранить позицию нужного элемента
        printf("i==%d, size==%d, s==%d\n", i, this->linked.size(),s);
        //this->print();
        printf("linked   %d\n", this->linked.at(i));

        if(this->linked[i]==s){
            //printf("i==%d, size==%d\n", i, this->linked.size());
            b=true;
            break;
        }
    }

    if(!b){
        printf("\tfailed unlink: contacts wasn't linked\n");
        return;
    }
//Отвязываю
    for(j=0; j < second->linked.size(); j++){ //Хочу в итоге в j сохранить позицию номера f в векторе second
        if(second->linked.at(i)==f) break;
    }
    this->linked.erase(this->linked.begin()+i);
    second->linked.erase(second->linked.begin()+j);
}
void printing(int i){
    cout << i <<";  ";
}
void ContactData::print() {
    cout << "print" <<"\n";
    cout << "    device_name    " << this->device_name <<"\n";
    cout << "    plate_num    " << this->plate_num <<"\n";
    cout << "    contact_num    " << this->contact_num <<"\n";
    cout << "    linked    {";
    for_each(this->linked.begin(), this->linked.end(), printing);
    cout << "}\n";
    //for(int i=0; i< (this->linked.size()); i++){}
    cout << "printed" <<"\n";
}

bool ContactData::isLinked(ContactData *contactData) {
    int s=contactData->contact_num;
    for (int i: this->linked) if (i == s) { return true; };
    return false;
}

int ContactData::getContactNum() {
    return this->contact_num;
}

int ContactData::getPlateNum() {
    return this->plate_num;
}

string ContactData::getDeviceName() {
    return this->device_name;
}
