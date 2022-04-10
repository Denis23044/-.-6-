//
// Created by User on 13.03.2022.
//

#ifndef TASK_1_CONTACTDATA_H
#define TASK_1_CONTACTDATA_H

#include <vector>
#include <string>

using namespace std;

class ContactData {
private:
    vector<int> linked;   //вектор с номерами контактов, соединенных с данным
    int contact_num;      //номер контакта
    int plate_num;        //номер слоя платы
    string device_name;   //строковое имя устройства
public:
    ContactData(int contact_num=0, int plate_num=0, const string& name="def");
    void link(ContactData *second); //связывание 2 контактов
    void unlink(ContactData *second); //удаление связи 2 контактов
    void print();
    bool isLinked(ContactData *contactData);
    int getContactNum();
    int getPlateNum();
    string getDeviceName();
};


#endif //TASK_1_CONTACTDATA_H
